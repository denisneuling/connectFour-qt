#include "gameserver.h"

GameServer::GameServer(QObject *parent) :
    NetworkAdapter(parent)
{
    m_IsServer = true;

}


void GameServer::newConnection()
{
    m_pSocket = m_pServer->nextPendingConnection();
    connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(readReady()));
    m_pServer->pauseAccepting();
    emit connectionEstablished();
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
