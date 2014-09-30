#include <QMessageBox>
#include "gameclient.h"

GameClient::GameClient(QString ipAddress, QObject *parent) :
    NetworkAdapter(parent), m_IpAddress(ipAddress)
{
    m_IsServer = false;
    m_pSocket = new QTcpSocket(this);


    m_pMessageBox = new QMessageBox(NULL);
    m_pMessageBox->setAttribute(Qt::WA_DeleteOnClose);
    m_pMessageBox->setStandardButtons(QMessageBox::Ok);
    m_pMessageBox->setWindowTitle(tr("Connection Refused"));
    m_pMessageBox->setText(tr("The connection was refused by the server!"));
    m_pMessageBox->setModal(false);

    connect(m_pSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(readReady()));
    connect(m_pSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}


void GameClient::connected()
{
    qDebug() << "connected";
    m_IsConnected = true;
}

void GameClient::disconnected()
{
    qDebug() << "disconnected";
    m_IsConnected = false;
    // create new socket after disconnecting. old one is invalid
    delete m_pSocket;
    m_pSocket = new QTcpSocket(this);

}

void GameClient::readReady()
{
    QString data = QString::fromUtf8(m_pSocket->readAll());
    if (data == "ac")
    {
        emit connectionEstablished();
    }
    else if (data == "nac")
    {
        m_pMessageBox->open(this, SLOT(refusedConnection()));
    }
    else
        emit dataReceived(data);
}

void GameClient::refusedConnection()
{

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
