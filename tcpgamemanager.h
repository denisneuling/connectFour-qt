#ifndef TCPGAMEMANAGER_H
#define TCPGAMEMANAGER_H

#include "gamemanager.h"
#include "networkadapter.h"

/*!
 * \class TCPGameManager
 * \brief Gamemanager that handles Network game related tasks
 * \details Gamemanager that handles Network game related tasks
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class TCPGameManager : public GameManager
{
    Q_OBJECT
public:
    explicit TCPGameManager(QWidget* parent);

    void startGame(Settings settings);
private:
    NetworkAdapter* m_pNetworkAdapter;

public slots:
    void clientConnected();
    void connectionEstablished();
    void receivedData(const QString& data);
protected:
    void mousePressEvent(QMouseEvent *event);

    bool m_NetworkInitialized;
    bool m_ServerTurn;
    bool m_SentButNotReceived;
};

#endif // TCPGAMEMANAGER_H
