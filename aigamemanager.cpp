#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>

#include "aigamemanager.h"
#include "minmax.h"
AIGameManager::AIGameManager(QWidget *parent) :
    GameManager(parent)
{
    std::srand(std::time(0));
}

void AIGameManager::startGame(Settings settings)
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

    time(&m_StartTime);
    setStartingPlayer(settings);

    emit gameStarted();
}

void AIGameManager::setStartingPlayer(Settings settings)
{
    m_CurrentPlayer = m_Player1 = Player(settings.player1, RED, settings.aiBegins);
    m_Player2 = Player(settings.player2, YELLOW, !settings.aiBegins);
    if (settings.aiBegins)
        QTimer::singleShot(500, this, SLOT(makeAiTurn()));
    m_pAI = std::make_shared<MinMax>(settings.aiStrength);
}

void AIGameManager::mousePressEvent(QMouseEvent *event)
{
    if (!getCurrentActivePlayer().isAiPlayer())
    {
        GameManager::mousePressEvent(event);
        QTimer::singleShot(500, this, SLOT(makeAiTurn()));
    }
}

void AIGameManager::makeAiTurn()
{

    int next = m_pAI->calculateMove(*m_pGameBoard, *this);
    if (m_pGameBoard->addCoin(next, m_CurrentPlayer.getCoin()))
    {
        checkAndHandleWin(next);
    }
}


