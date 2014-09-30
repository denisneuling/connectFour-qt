#include <vector>
#include <string>

#include <QDebug>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpgamemanager.h"
#include "aigamemanager.h"
#include "gamedatabase.h"
#include "serversearch.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pGameManager(NULL)
{
    ui->setupUi(this);

    m_pLayout = new QHBoxLayout;
    m_pSettingsWidget = new SettingsWidget(this);
    m_pGameResults = new GameResults(this);
    m_pChatWidget = new ChatWidget(this);
    m_pServerSearchWidget = new ServerSearch(this);
    m_pGameOverScreen = NULL;
    m_pLayout->addWidget(m_pSettingsWidget);
    m_pLayout->addWidget(m_pGameResults);
    m_pLayout->addWidget(m_pServerSearchWidget);
    m_pServerSearchWidget->setVisible(false);
    m_pGameResults->setVisible(false);
    m_pChatWidget->setVisible(false);
    QWidget* widget = new QWidget();
    widget->setLayout(m_pLayout);
    setCentralWidget(widget);
    setWindowTitle(tr("Connect Four"));
    setMouseTracking(true);
    connect(m_pSettingsWidget, SIGNAL(startButtonPressed(Settings)), this, SLOT(settingsWidgetStartButtonPressed(Settings)));
    connect(m_pSettingsWidget, SIGNAL(hostServerButtonPressed(Settings)), this, SLOT(settingsWidgetHostButtonPressed(Settings)));
    connect(m_pSettingsWidget,SIGNAL(connectButtonPressed(Settings)),this, SLOT(settingsWidgetHostButtonPressed(Settings)));
    connect(m_pSettingsWidget, SIGNAL(highscoreButtonPressed()), this, SLOT(settingsWidgetResultsButtonPressed()));
    connect(m_pSettingsWidget, SIGNAL(showChatWidget()), this, SLOT(toggleChatWidget()));
    connect(m_pSettingsWidget, SIGNAL(onFindServerButton()), this, SLOT(settingsWidgetFindServerButtonPressed()));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(onSaveAction()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(onLoadAction()));
    connect(ui->actionFullscreen, SIGNAL(triggered()), this, SLOT(onFullscreenAction()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(onExitAction()));
    connect(ui->actionPrint, SIGNAL(triggered()), this, SLOT(onPrintAction()));

    setFocusPolicy(Qt::StrongFocus);
    setFocus(Qt::ActiveWindowFocusReason);
}

MainWindow::~MainWindow()
{
    delete ui;

    if (m_pGameManager != NULL)
        delete m_pGameManager;
    if (m_pGameOverScreen != NULL)
        delete m_pGameOverScreen;
    if (m_pChatWidget != NULL)
        delete m_pChatWidget;
    if (m_pGameResults != NULL)
        delete m_pGameResults;
    if (m_pLayout != NULL)
        delete m_pLayout;
    if (m_pServerSearchWidget != NULL)
        delete m_pServerSearchWidget;
    if (m_pSettingsWidget != NULL)
        delete m_pSettingsWidget;
}

QSize MainWindow::sizeHint() const
{
    return QSize(800, 600);
}


void MainWindow::settingsWidgetStartButtonPressed(Settings settings)
{
    if (m_pGameManager != NULL)
        delete m_pGameManager;
    if (settings.useAI)
        m_pGameManager = new AIGameManager(this);
    else
        m_pGameManager = new GameManager(this);

    onStartGame(settings);
}

void MainWindow::settingsWidgetHostButtonPressed(Settings settings)
{
    if (m_pGameManager != NULL)
        delete m_pGameManager;
    m_pGameManager = new TCPGameManager(this);
    m_pChatWidget->init((TCPGameManager*)m_pGameManager);
//    m_pChatWidget->setVisible(true);
    if (settings.ipAddress.isEmpty())
        setWindowTitle(windowTitle() + " - Server");

    m_pServerSearchWidget->setVisible(false);
    onStartGame(settings);

}

void MainWindow::settingsWidgetResultsButtonPressed()
{

    m_pGameResults->setVisible(true);
    if (m_pGameManager != NULL)
        m_pGameManager->setVisible(false);
}

void MainWindow::settingsWidgetFindServerButtonPressed()
{
    m_pServerSearchWidget->setVisible(true);
}

void MainWindow::toggleChatWidget()
{
    if (m_pChatWidget->isVisible())
    {
        m_pChatWidget->setVisible(false);
        resize(width() - m_pChatWidget->width(), height());
    }
    else
    {
        m_pChatWidget->setVisible(true);
        resize(width() + m_pChatWidget->width(), height());
    }
}

void MainWindow::onStartGame(Settings settings)
{
    connect(m_pGameManager, SIGNAL(gameStarted()), this, SLOT(gameStarted()));

    m_pLayout->addWidget(m_pGameManager);
    m_pLayout->addWidget(m_pChatWidget);

    m_pGameManager->setVisible(true);
    m_pGameManager->startGame(settings);
    m_pGameResults->setVisible(false);
}

void MainWindow::gameStarted()
{
    // need to trigger resize event when game is properly started need a signal for multiplayer where initialization happens later
    triggerResizeEvent();
}

void MainWindow::onSaveAction()
{
    if (m_pGameManager != NULL)
        m_pGameManager->saveGame();
    else
        QMessageBox::information(this, tr("Information"), tr("No Game available to save!"));

}

void MainWindow::onLoadAction()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select your Savegame"), QDir::currentPath(), "Savegame (*.savegame)");
    QFile file(filename);
    Settings settings;
    Coin player;
    QString gameBoard;
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QString content;
        content = QString::fromUtf8(file.readLine());

        settings.width = content[0].digitValue();
        settings.height = content[2].digitValue();

        content = QString::fromUtf8(file.readLine());
        player = (Coin)content[2].digitValue();

        gameBoard = QString::fromUtf8(file.readAll());

        if (m_pGameManager != NULL)
            delete m_pGameManager;
        m_pGameManager = new GameManager(this);
        onStartGame(settings);
        m_pGameManager->setStartingPlayer(settings, player);
        m_pGameManager->loadGame(gameBoard);
    }
    else
        QMessageBox::information(this, tr("ERROR"), tr("Invalid savegame data!"));
}

void MainWindow::onFullscreenAction()
{
    isFullScreen() ? showNormal() : showFullScreen();
}

void MainWindow::onExitAction()
{
    exit(0);
}

void MainWindow::onPrintAction()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *printDialog = new QPrintDialog(&printer);
    QTextDocument *document = new QTextDocument();

    printDialog->setWindowTitle(tr("Print Document"));

    if (printDialog->exec() == QDialog::Accepted)
    {
        QString text = "<table border=1>";

        text.append("<tr>");
        text.append("<th>Game</th>");
        text.append("</tr>");

        std::vector<std::string> games = GameDatabase::getInstance().getGames();
        for (unsigned i = 0; i < games.size(); ++i)
        {
            text.append("<tr>");

            text.append("<td>");
            text.append( QString::fromStdString(games[i]));
            text.append("</td>");

            text.append("</tr>");
        }

        text.append("</table>");

        document->setHtml(text);
        document->print(&printer);
    }
}

//! function to trick opengl
/*! screw u opengl -> need a resize to get the proper scaling
 resize with the same size is not working.. */
void MainWindow::triggerResizeEvent()
{
    resize(width() + 2, height());
//    resize(width() - 2, height());
}
