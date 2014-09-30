#ifndef TCPGAMEMANAGER_H
#define TCPGAMEMANAGER_H

#include <memory>

#include "gamemanager.h"
#include "networkadapter.h"
#include "serversearchlistener.h"

/*!
 * \class TCPGameManager
 * \brief Gamemanager that handles Network game related tasks
 * \details Gamemanager that handles Network game related tasks
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
class TCPGameManager : public GameManager
{
    Q_OBJECT
public:
    explicit TCPGameManager(QWidget* parent);

    void startGame(Settings settings);
    void sendMessage(QString string);
private:
    NetworkAdapter* m_pNetworkAdapter;
signals:
    //! emitted when a new chat message has been received
    void chatMessageReceived(QString message);

public slots:
    void clientConnected();
    void connectionEstablished();
    void receivedData(const QString& data);
protected:
    void mousePressEvent(QMouseEvent *event);

    bool m_NetworkInitialized;
    bool m_ServerTurn;
    bool m_SentButNotReceived;

    std::shared_ptr<ServerSearchListener> m_pServerSearchListener;
};

#endif // TCPGAMEMANAGER_H
