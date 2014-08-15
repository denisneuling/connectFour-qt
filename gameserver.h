#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "networkadapter.h"

//! Class that handles server client connection
class GameServer : public NetworkAdapter
{
    Q_OBJECT
public:
    explicit GameServer(QObject *parent = 0);

public slots:
    //! called when a new client connects
    void newConnection();
    //! called when new data is available from the client
    void readReady();
private:
    QTcpServer* m_pServer;

    // NetworkAdapter interface
public:
    void init();
    void send(QString data);

};

#endif // GAMESERVER_H
