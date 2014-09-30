#ifndef NETWORKADAPTER_H
#define NETWORKADAPTER_H

#include <QObject>
#include <QTcpSocket>


//! base class for a network connection (server and client)
class NetworkAdapter : public QObject
{
    Q_OBJECT
public:
    explicit NetworkAdapter(QObject *parent = 0);
    virtual void init() = 0;
    virtual void send(QString data) = 0;

    bool isConnected();

    bool IsServer();
signals:
    //! triggered after a new connection has been established either by server or client
    void connectionEstablished();
    //! triggered after new data is available on the socket
    void dataReceived(const QString& data);

protected:
    bool m_IsServer, m_IsConnected;
    QTcpSocket* m_pSocket;
};

#endif // NETWORKADAPTER_H
