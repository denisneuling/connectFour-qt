#include "tcpgamemanager.h"
#include "gameserver.h"
#include "gameclient.h"

TCPGameManager::TCPGameManager(QWidget *parent) :
    GameManager(parent), m_NetworkInitialized(false), m_ServerTurn(true)
{

}

void TCPGameManager::startGame(Settings settings)
{
    m_Settings = settings;

    if (m_Settings.ipAddress.length() > 0)
    {
        m_pNetworkAdapter = new GameClient(m_Settings.ipAddress, this);
        m_SentButNotReceived = true;
     }
    else
    {
        m_pNetworkAdapter = new GameServer(this);
        m_SentButNotReceived = false;
    }
    connect(m_pNetworkAdapter, SIGNAL(dataReceived(const QString&)), this, SLOT(receivedData(const QString&)));
    connect(m_pNetworkAdapter, SIGNAL(connectionEstablished()), this, SLOT(clientConnected()));
    m_pNetworkAdapter->init();
}

void TCPGameManager::clientConnected()
{

    connect(m_pRenderer, SIGNAL(mousePressed(QMouseEvent*)), this, SLOT(mousePressEvent(QMouseEvent*)));
    connect(m_pUpdateTimer, SIGNAL(timeout()), this, SLOT(update()));

    if(m_pNetworkAdapter->IsServer()) //==server
    {
        qDebug() << "server initialized";
        m_pRenderer->initialize(m_Settings.width, m_Settings.height);
        m_pGameBoard = new GameBoard(m_Settings.height, m_Settings.width);
        m_pUpdateTimer->start(DELTA_TIME);
        m_pGameOverScreen->setVisible(false);
        m_pRenderer->setVisible(true);
        m_Finished = false;
        m_pRenderer->getGameBoardRenderer()->setCurrentActivePlayer(getCurrentActivePlayer().getCoin());
        emit gameStarted();
    }
    else
    {
        qDebug() << "sending init request";
        m_pNetworkAdapter->send("init");
    }
}

void TCPGameManager::connectionEstablished()
{
    qDebug() << "in tcp game";
}

void TCPGameManager::receivedData(const QString &data)
{
    if (m_pNetworkAdapter->IsServer() && !m_NetworkInitialized)
    {
        if (data == "init")
        {
            qDebug() << "received init request";
            m_pNetworkAdapter->send(QString("%1,%2").arg(m_Settings.width).arg(m_Settings.height));
            m_NetworkInitialized = true;
        }
    }
    if(!m_pNetworkAdapter->IsServer() && !m_NetworkInitialized)
    {
        qDebug() << "initalizing client";
        int width, height;
        QStringList list = data.split(",");
        width = list[0].toInt();
        height = list[1].toInt();
        m_pRenderer->initialize(width, height);
        m_pGameBoard = new GameBoard(height, width);
        m_pUpdateTimer->start(DELTA_TIME);
        m_pGameOverScreen->setVisible(false);
        m_pRenderer->setVisible(true);
        m_Finished = false;
        m_pRenderer->getGameBoardRenderer()->setCurrentActivePlayer(getCurrentActivePlayer().getCoin());
        m_NetworkInitialized = true;

        emit gameStarted();
    }
    if (m_NetworkInitialized)
    {
        if (data.startsWith(Helper::boardUpdate()))
        {
            QString newdata = data.split(",")[1];
            m_pGameBoard->deserialize(newdata);
            m_pRenderer->getGameCoinRenderer()->setGameBoard(m_pGameBoard->getCurrentBoard());
            Game game = m_pGameBoard->checkGameConditions();
            if (game.result != NOT_FINISHED)
                finishGame(game);
            m_SentButNotReceived = false;
        }
    }

}

// quite the same as in normal gamemanager but with more stuff
void TCPGameManager::mousePressEvent(QMouseEvent *event)
{

    if (!m_SentButNotReceived)
    {
        if (m_pGameBoard->addCoin(m_CurrentColumn, getCurrentActivePlayer().getCoin()) && !m_Finished )
        {
            m_pNetworkAdapter->send(Helper::boardUpdate() + m_pGameBoard->serialize());

            Result result = m_pGameBoard->checkGameConditions();
            if (result != NOT_FINISHED)
            {
                Game game(result, getCurrentActivePlayer(), getCurrentInactivePlayer());
                finishGame(game);
            }
            else
            {
                m_pRenderer->getGameBoardRenderer()->setCurrentActivePlayer(getCurrentActivePlayer().getCoin());
            }

            m_pRenderer->getGameCoinRenderer()->setGameBoard(m_pGameBoard->getCurrentBoard());
        }
        m_SentButNotReceived = true;
    }
}
