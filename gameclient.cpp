#include "gameclient.h"

GameClient::GameClient(QString ipAddress, QObject *parent) :
    NetworkAdapter(parent), m_IpAddress(ipAddress)
{
    m_IsServer = false;
    m_pSocket = new QTcpSocket(this);

    connect(m_pSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(readReady()));
}


void GameClient::connected()
{
    emit connectionEstablished();
}

void GameClient::readReady()
{
    QByteArray data = m_pSocket->readAll();
    emit dataReceived(QString::fromUtf8(data));
}

void GameClient::init()
{

    m_pSocket->connectToHost(m_IpAddress, 50000);
    if (!m_pSocket->waitForConnected())
    {
        qDebug() << "error" << m_pSocket->errorString();
        m_pSocket->close();
    }
    else
    {
    }
}

void GameClient::send(QString data)
{
    m_pSocket->write(data.toUtf8());
}
