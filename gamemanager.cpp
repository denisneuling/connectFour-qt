#include <QFileDialog>
#include <QWidget>
#include <QtNetwork>
#include <QDateTime>
#include "gamemanager.h"
#include "helper.h"
#include "gameclient.h"
#include "gamedatabase.h"

GameManager::GameManager(QWidget *parent) :
    QWidget(parent)
{
    m_pMainLayout = new QHBoxLayout(this);
    m_pRenderer = new GameRenderer(this);
    m_pGameOverScreen = new GameOverScreen(this);
    m_pUpdateTimer = new QTimer(this);
    m_pMainLayout->addWidget(m_pRenderer);
    m_pMainLayout->addWidget(m_pGameOverScreen);
    m_pGameOverScreen->setVisible(false);

    setLayout(m_pMainLayout);

    m_Finished = false;
}

GameManager::~GameManager()
{
    delete m_pMainLayout;
    delete m_pRenderer;
    delete m_pGameOverScreen;
    delete m_pUpdateTimer;
    delete m_pGameBoard;
}

void GameManager::update()
{
    m_CurrentColumn = m_pRenderer->getGameBoardRenderer()->calculateAndSetColumnFromMousePoint(mapFromGlobal(QCursor::pos()));
    m_pRenderer->updateGL();
}

void GameManager::startGame(Settings settings)
{
    m_Settings = settings;

    connect(m_pRenderer, SIGNAL(mousePressed(QMouseEvent*)), this, SLOT(mousePressEvent(QMouseEvent*)));
    connect(m_pUpdateTimer, SIGNAL(timeout()), this, SLOT(update()));
    m_pRenderer->initialize(settings.width, settings.height);
    m_pGameBoard = new GameBoard(settings.height, settings.width);
    m_pUpdateTimer->start(DELTA_TIME);
    m_pGameOverScreen->setVisible(false);
    m_pRenderer->setVisible(true);
    m_Finished = false;

    setStartingPlayer(settings);

    emit gameStarted();
}

void GameManager::setStartingPlayer(Settings settings, Coin player)
{
    m_CurrentPlayer = m_Player1 = Player(settings.player1, player);
    m_Player2 = Player(settings.player2, player == RED ? YELLOW : RED);
    m_pRenderer->getGameBoardRenderer()->setCurrentActivePlayer(getCurrentActivePlayer().getCoin());
}

void GameManager::gameEnd()
{
    m_pGameOverScreen->setVisible(true);
    m_pRenderer->setVisible(false);
}

void GameManager::finishGame(Game game)
{
    QString winText = "";
    switch (game.result)
    {
        case WIN_RED:
        case WIN_YELLOW:
            winText =  Helper::ResultToString(game.result) + "\n" + "The winner is:\n" + game.winner.getName();
            break;
        case DRAW:
            winText = Helper::ResultToString(game.result) + "\n" + game.winner.getName() + " vs. " + game.loser.getName();
    }

    m_pGameOverScreen->setWinner(winText);
    QTimer::singleShot(1000, this, SLOT(gameEnd()));
    m_Finished = true;
    GameDatabase::getInstance().addGame(game);
}

// only usable for standard and ai game
void GameManager::checkAndHandleWin(int column)
{
    Result result = m_pGameBoard->checkGameConditions();

    if (result == NOT_FINISHED)
    {
        m_pRenderer->getGameCoinRenderer()->updateGameCoins(
                    column, getCurrentActivePlayer().getCoin());
        switchPlayer();
    }
    else
    {
        Game game(result, getCurrentActivePlayer(), getCurrentInactivePlayer());
        finishGame(game);
    }
    m_pRenderer->getGameBoardRenderer()->setCurrentActivePlayer(getCurrentActivePlayer().getCoin());
}

void GameManager::mousePressEvent(QMouseEvent *event)
{
    if (m_pGameBoard->addCoin(m_CurrentColumn, getCurrentActivePlayer().getCoin()) && !m_Finished)
    {
        checkAndHandleWin(m_CurrentColumn);
    }
    m_pRenderer->updateGL();
}

void GameManager::saveGame()
{
    QDateTime dateTime = QDateTime::currentDateTime();

    QString filename = QFileDialog::getSaveFileName(this, "Create Savegame", QDir::currentPath() + "/" + dateTime.toString("yyMMddhms"), "Savegame (*.savegame)");
    qDebug() << filename;
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        file.write(QString("%1,%2\n").arg(m_Settings.width).arg(m_Settings.height).toUtf8());
        file.write(QString("p,%1\n").arg(getCurrentActivePlayer().getCoin()).toUtf8());
        file.write(m_pGameBoard->serialize().toUtf8());
    }
}

void GameManager::loadGame(QString gameBoard)
{
    qDebug() << gameBoard;
    m_pGameBoard->deserialize(gameBoard);
    m_pRenderer->getGameCoinRenderer()->setGameBoard(m_pGameBoard->getCurrentBoard());
}

void GameManager::switchPlayer()
{
    m_CurrentPlayer = m_CurrentIsPlayer1 ? m_Player2 : m_Player1;
    m_CurrentIsPlayer1 = !m_CurrentIsPlayer1;
}

Player GameManager::getCurrentActivePlayer()
{
    return m_CurrentPlayer;
}

Player GameManager::getCurrentInactivePlayer()
{
    return m_CurrentIsPlayer1 ? m_Player2 : m_Player1;
}
