#ifndef SERVERSEARCHLISTENER_H
#define SERVERSEARCHLISTENER_H

#include <memory>
#include <QObject>
#include <QUdpSocket>

/*!
 * \class ServerSearchListener
 * \brief The ServerSearchListener handles incoming serversearch requests
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
class ServerSearchListener : public QObject
{
    Q_OBJECT
public:
    explicit ServerSearchListener(QObject *parent = 0);

protected slots:

    /*!
     * \brief processServerSearchRequest
     * called when new data is available on the socket
     * handles response on the request with sending the first network adapters ip address
     */
    void processServerSearchRequest();

private:
    std::shared_ptr<QUdpSocket> m_pUdpSocket;

};

#endif // SERVERSEARCHLISTENER_H
