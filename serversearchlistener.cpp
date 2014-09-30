#include "serversearchlistener.h"

#include "helper.h"

#include <QNetworkInterface>

ServerSearchListener::ServerSearchListener(QObject *parent) :
    QObject(parent)
{
    m_pUdpSocket = std::make_shared<QUdpSocket>(this);
    m_pUdpSocket->bind(Helper::serverSearchPort(), QUdpSocket::ShareAddress);

    connect(m_pUdpSocket.get(), SIGNAL(readyRead()), this, SLOT(processServerSearchRequest()));
}


void ServerSearchListener::processServerSearchRequest()
{
    while(m_pUdpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_pUdpSocket->pendingDatagramSize());

        QHostAddress senderip;
        m_pUdpSocket->readDatagram(datagram.data(), datagram.size(), &senderip);

        QString data = datagram.data();

        if (data.startsWith(Helper::serverSearchRequest()))
        {
            QNetworkInterface interface;
            QList<QHostAddress> list = interface.allAddresses();
            QString ipaddress = "";
            if (list.length() > 0)
                ipaddress = list[0].toString();

            qDebug() << "serversearch request: " + senderip.toString();
            QString ret = Helper::serverSearchResult() + ipaddress;
            QByteArray datagram = ret.toUtf8();
            m_pUdpSocket->writeDatagram(datagram, senderip, Helper::serverSearchPort() + 1);
        }
    }
}
