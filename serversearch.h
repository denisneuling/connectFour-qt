#ifndef SERVERSEARCH_H
#define SERVERSEARCH_H

#include <memory>

#include <QWidget>
#include <QUdpSocket>



namespace Ui {
class ServerSearch;
}

/*!
 * \brief The ServerSearch class handles requesting and rendering of a server list in the local network
 */
class ServerSearch : public QWidget
{
    Q_OBJECT

public:
    explicit ServerSearch(QWidget *parent = 0);
    ~ServerSearch();

protected:
    //! called when the Widget is shown
    void showEvent(QShowEvent *event);
protected slots:

    //! called on response to the serversearch request
    void readReady();
private slots:
    //! sends a serversearch request
    void on_refreshButton_clicked();

private:
    std::shared_ptr<QUdpSocket> m_pUdpSocket;
    std::shared_ptr<QUdpSocket> m_pResultSocket;
    Ui::ServerSearch *ui;
};

#endif // SERVERSEARCH_H
