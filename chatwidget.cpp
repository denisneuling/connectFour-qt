#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "tcpgamemanager.h"

ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget),
    m_pGameManager(NULL)
{
    ui->setupUi(this);
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

void ChatWidget::init(TCPGameManager* tcpGameManager)
{
    m_pGameManager = tcpGameManager;
    qDebug() << "init chat";
    connect(m_pGameManager, SIGNAL(chatMessageReceived(QString)),this, SLOT(chatMessageReceived(QString)));
}

void ChatWidget::on_sendButton_clicked()
{
    if (m_pGameManager == NULL)
        return;

    QString text = ui->chatTextField->text();
    if (!text.isEmpty())
    {
        m_pGameManager->sendMessage(Helper::chatMessage() + text);
        text = tr("You: ") + text;

        ui->chatLog->addItem(text);
        ui->chatTextField->setText("");
    }
}

void ChatWidget::chatMessageReceived(QString msg)
{
    ui->chatLog->addItem(tr("Opponent: ") + msg);
}
