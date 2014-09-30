#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include "tcpgamemanager.h"
namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = 0);
    ~ChatWidget();
    void init(TCPGameManager* tcpGameManager);
private slots:
    void on_sendButton_clicked();
    void chatMessageReceived(QString msg);
private:
    Ui::ChatWidget *ui;

    TCPGameManager* m_pGameManager;
};

#endif // CHATWIDGET_H
