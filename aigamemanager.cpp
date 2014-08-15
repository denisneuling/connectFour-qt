#include <vector>
#include <cstdlib>
#include <ctime>

#include "aigamemanager.h"
#include "minmax.h"
AIGameManager::AIGameManager(QWidget *parent) :
    GameManager(parent)
{
    std::srand(std::time(0));
}


void AIGameManager::setStartingPlayer(Settings settings)
{
    m_CurrentPlayer = m_Player1 = Player(settings.player1, RED, settings.aiBegins);
    m_Player2 = Player(settings.player2, YELLOW, !settings.aiBegins);
    if (settings.aiBegins)
        QTimer::singleShot(500, this, SLOT(makeAiTurn()));
}

void AIGameManager::mousePressEvent(QMouseEvent *event)
{
    if (!getCurrentActivePlayer().isAiPlayer())
    {
        GameManager::mousePressEvent(event);
        QTimer::singleShot(500, this, SLOT(makeAiTurn()));
    }
}

// minmax not working properly
void AIGameManager::makeAiTurn()
{
    std::vector<int> availableTurns = m_pGameBoard->getAvailableMoves();

    int current = availableTurns[rand() % availableTurns.size()];
    qDebug() << "random: " << current;

    MinMax mm;
    int next = mm.calculateMove(*m_pGameBoard, *this);
    qDebug() << "minmax: " << next;

    if (m_pGameBoard->addCoin(current, m_CurrentPlayer.getCoin()))
    {
        checkAndHandleWin(current);
    }
}


