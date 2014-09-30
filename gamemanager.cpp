#include <memory>
#include <QFileDialog>
#include <QWidget>
#include <QtNetwork>
#include <QDateTime>
#include "gameaudiomanager.h"
#include "gamemanager.h"
#include "helper.h"
#include "gameclient.h"
#include "gamedatabase.h"

GameManager::GameManager(QWidget *parent) :
    QWidget(parent), m_Settings(), m_CurrentPlayer(Player()), m_Player1(Player()), m_Player2(Player()), m_CurrentIsPlayer1(true)
{
    m_pMainLayout = new QHBoxLayout(this);
    m_pRenderer = new GameRenderer(this);
    m_pGameOverScreen = new GameOverScreen(this);
    m_pUpdateTimer = new QTimer(this);
    m_pMainLayout->addWidget(m_pRenderer);
    m_pMainLayout->addWidget(m_pGameOverScreen);
    m_pGameOverScreen->setVisible(false);

    GameAudioManager::getInstance().addAudio("drop", std::make_shared<QSound>(":sounds/coin_drop.wav"));
    GameAudioManager::getInstance().addAudio("win_red", std::make_shared<QSound>(":sounds/win_red.wav"));
    GameAudioManager::getInstance().addAudio("win_yellow", std::make_shared<QSound>(":sounds/win_yellow.wav"));

    GameAudioManager::getInstance().addAudio("on_connect", std::make_shared<QSound>(":sounds/on_connect.wav"));
    GameAudioManager::getInstance().addAudio("illegal_move", std::make_shared<QSound>(":sounds/illegal_move.wav"));
    setLayout(m_pMainLayout);

    m_Finished = false;
}

GameManager::~GameManager()
{
    qDeleteAll(children());
}

void GameManager::update()
{
    m_CurrentColumn = m_pRenderer->getGameBoardRenderer()->calculateAndSetColumnFromMousePoint(mapFromGlobal(QCursor::pos()));
    m_pRenderer->updateGL();
}

void GameManager::startGame(Settings settings)
{
    m_Settings = settings;

    m_pGameBoard = std::make_shared<GameBoard>(settings.height, settings.width);
    m_pRenderer->initialize(settings.width, settings.height, settings.design);
    m_Finished = false;

    connect(m_pRenderer, SIGNAL(mousePressed(QMouseEvent*)), this, SLOT(mousePressEvent(QMouseEvent*)));
    connect(m_pUpdateTimer, SIGNAL(timeout()), this, SLOT(update()));
    m_pUpdateTimer->start(DELTA_TIME);
    m_pRenderer->setVisible(true);
    m_pGameOverScreen->setVisible(false);

    setStartingPlayer(settings);

    time(&m_StartTime);

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
            GameAudioManager::getInstance().playAudio("win_red");
        case WIN_YELLOW:
            winText =  Helper::ResultToString(game.result) + "\n" + tr("The winner is:\n") + game.winner.getName();
            break;
        case DRAW:
            GameAudioManager::getInstance().playAudio("win_yellow");
            winText = Helper::ResultToString(game.result) + "\n" + game.winner.getName() + " vs. " + game.loser.getName();
            break;
        case NOT_FINISHED:
        default:
            break;
    }
    time_t endTime = 0;
    time(&endTime);
    double elapsed = 0.0;
    elapsed = difftime(endTime, m_StartTime);
    winText += "\n" + tr("The Game took:") + "\n" + QString::number(elapsed) + " " + tr(" seconds");
    qDebug() << winText;
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
        GameAudioManager::getInstance().playAudio("drop");
        checkAndHandleWin(m_CurrentColumn);
    }
    else
    {
        GameAudioManager::getInstance().playAudio("illegal_move");
    }
    m_pRenderer->updateGL();
    event->accept();
}

void GameManager::saveGame()
{
    QDateTime dateTime = QDateTime::currentDateTime();

    QString filename = QFileDialog::getSaveFileName(this, tr("Create Savegame"), QDir::currentPath() + "/" + dateTime.toString("yyMMddhms"), "Savegame (*.savegame)");
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
