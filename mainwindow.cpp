#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpgamemanager.h"
#include "aigamemanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pGameManager(NULL)
{
    ui->setupUi(this);

    m_pLayout = new QHBoxLayout;
    m_pSettingsWidget = new SettingsWidget;
    m_pGameResults = new GameResults;
    m_pLayout->addWidget(m_pSettingsWidget);
    m_pLayout->addWidget(m_pGameResults);
    QWidget* widget = new QWidget();
    widget->setLayout(m_pLayout);
    setCentralWidget(widget);
    setWindowTitle(tr("Connect Four"));
    setMouseTracking(true);
    m_pGameResults->setVisible(false);
    connect(m_pSettingsWidget, SIGNAL(startButtonPressed(Settings)), this, SLOT(settingsWidgetStartButtonPressed(Settings)));
    connect(m_pSettingsWidget, SIGNAL(hostServerButtonPressed(Settings)), this, SLOT(settingsWidgetHostButtonPressed(Settings)));
    connect(m_pSettingsWidget,SIGNAL(connectButtonPressed(Settings)),this, SLOT(settingsWidgetHostButtonPressed(Settings)));
    connect(m_pSettingsWidget, SIGNAL(highscoreButtonPressed()), this, SLOT(settingsWidgetResultsButtonPressed()));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(onSaveAction()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(onLoadAction()));

    setFocusPolicy(Qt::StrongFocus);
    setFocus(Qt::ActiveWindowFocusReason);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(640, 480);
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
    onStartGame(settings);
}

void MainWindow::settingsWidgetResultsButtonPressed()
{
    m_pGameResults->setVisible(true);
    if (m_pGameManager != NULL)
        m_pGameManager->setVisible(false);
}

void MainWindow::onStartGame(Settings settings)
{
    connect(m_pGameManager, SIGNAL(gameStarted()), this, SLOT(gameStarted()));

    m_pLayout->addWidget(m_pGameManager);
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
    QString filename = QFileDialog::getOpenFileName(this, "Select your Savegame", QDir::currentPath(), "Savegame (*.savegame)");
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

// screw u opengl -> need a resize to get the proper scaling
// resize with the same size is not working..
void MainWindow::triggerResizeEvent()
{
    resize(sizeHint().width() + 1, sizeHint().height());
    resize(sizeHint());
}
