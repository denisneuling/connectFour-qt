#include <QShowEvent>

#include "serversearch.h"
#include "ui_serversearch.h"

#include "helper.h"

ServerSearch::ServerSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerSearch)
{
    ui->setupUi(this);

}

ServerSearch::~ServerSearch()
{
    delete ui;
}

void ServerSearch::on_refreshButton_clicked()
{
    ui->listWidget->clear();

    QByteArray datagram(Helper::serverSearchRequest().toUtf8(), Helper::serverSearchRequest().length());
    m_pUdpSocket->writeDatagram(datagram, QHostAddress::Broadcast, Helper::serverSearchPort());
}

void ServerSearch::showEvent(QShowEvent *event)
{
    if (event->type() == QEvent::Show)
    {
        m_pUdpSocket = std::make_shared<QUdpSocket>(this);
        m_pResultSocket = std::make_shared<QUdpSocket>(this);

        m_pResultSocket->bind(QHostAddress::Any, Helper::serverSearchPort() + 1);
        connect(m_pResultSocket.get(), SIGNAL(readyRead()), this, SLOT(readReady()));
    }
}

void ServerSearch::readReady()
{
    while(m_pResultSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_pResultSocket->pendingDatagramSize());

        m_pResultSocket->readDatagram(datagram.data(), datagram.size());

        QString data = datagram.data();

        if (data.startsWith(Helper::serverSearchResult()))
        {
            qDebug() << data;
            data = data.remove(0, Helper::serverSearchResult().length());
            ui->listWidget->addItem(data);
        }
    }
}
