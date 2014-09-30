#include <QMessageBox>

#include "gameserver.h"
#include "gameaudiomanager.h"

GameServer::GameServer(QObject *parent) :
    NetworkAdapter(parent)
{
    m_IsServer = true;

    m_pMessageBox = new QMessageBox(NULL);
    m_pMessageBox->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    m_pMessageBox->setWindowTitle(tr("Incoming Connection"));
    m_pMessageBox->setText(tr("Do you want to accept the connection?"));
    m_pMessageBox->setModal(false);


}

GameServer::~GameServer()
{
    if (m_pSocket != NULL)
        delete m_pSocket;

    delete m_pMessageBox;

    delete m_pServer;
}

void GameServer::newConnection()
{
    m_pSocket = m_pServer->nextPendingConnection();
    m_pMessageBox->open(this, SLOT(acceptingConnection(QAbstractButton*)));
    m_pMessageBox->setFocus();
    GameAudioManager::getInstance().playAudio("on_connect");
    connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(readReady()));
}

void GameServer::acceptingConnection(QAbstractButton* button)
{
    QMessageBox::StandardButton btn = m_pMessageBox->standardButton(button);
    if (btn == QMessageBox::Yes)
    {
        m_pServer->pauseAccepting();
        send("ac");
        m_IsConnected = true;
        emit connectionEstablished();
    }
    else
    {
        send("nac");
        m_pSocket->close();
        m_pServer->resumeAccepting();
        m_IsConnected = false;
    }
}

void GameServer::init()
{
    m_pServer = new QTcpServer(this);

    connect(m_pServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!m_pServer->listen(QHostAddress::Any, 50000))
    {
        qDebug() << "server not started";
    }
    else
    {
        qDebug() << "server started";
    }
}

void GameServer::send(QString data)
{
    m_pSocket->write(data.toUtf8());
}

void GameServer::readReady()
{
    QByteArray data = m_pSocket->readAll();
    emit dataReceived(QString::fromUtf8(data));
}
