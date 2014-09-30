#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include "chatwidget.h"
#include "gamemanager.h"
#include "settingswidget.h"
#include "serversearch.h"
#include "gameresults.h"

namespace Ui {
class MainWindow;
}

/*!
 * \class MainWindow
 * \brief main window class
 * \details application's main window
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSize size();
    QSize sizeHint() const;

private slots:
    void settingsWidgetFindServerButtonPressed();
    void settingsWidgetStartButtonPressed(Settings settings);
    void settingsWidgetHostButtonPressed(Settings settings);
    void settingsWidgetResultsButtonPressed();
    void toggleChatWidget();

    /*!
     * triggered after game is started, important for networkgames
     */
    void gameStarted();

    void onSaveAction();
    void onLoadAction();
    void onFullscreenAction();
    void onExitAction();
    void onPrintAction();
private:
    void triggerResizeEvent();

    Ui::MainWindow *ui;

    QHBoxLayout* m_pLayout;
    GameManager* m_pGameManager;
    SettingsWidget* m_pSettingsWidget;
    GameOverScreen* m_pGameOverScreen;
    GameResults* m_pGameResults;
    ChatWidget* m_pChatWidget;
    ServerSearch* m_pServerSearchWidget;

    void onStartGame(Settings settings);
};


#endif // MAINWINDOW_H
