#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "networkadapter.h"

//! Class that handles the  client network object
class GameClient : public NetworkAdapter
{
    Q_OBJECT
public:
    explicit GameClient(QString ipAddress, QObject *parent = 0);


public slots:
    //! called when connected to the server
    void connected();

    //! called when new data is available from the client
    void readReady();
private:
    QTcpSocket* m_pSocket;
    QString m_IpAddress;
    // NetworkAdapter interface
public:
    void init();
    void send(QString data);
};

#endif // GAMECLIENT_H
