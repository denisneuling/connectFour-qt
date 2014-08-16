#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "networkadapter.h"

/*!
 * \class GameClient
 * \brief Class that is responsible for opening a tcp socket connection to the host
 * \details Class handles a tcp socket connection to the host
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
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
