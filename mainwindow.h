#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include "gamemanager.h"
#include "settingswidget.h"
#include "gameresults.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSize size();
    QSize sizeHint() const;

private slots:
    void settingsWidgetStartButtonPressed(Settings settings);
    void settingsWidgetHostButtonPressed(Settings settings);
    void settingsWidgetResultsButtonPressed();

    // triggered after game is started, important for networkgames
    void gameStarted();

    void onSaveAction();
    void onLoadAction();
private:
    void triggerResizeEvent();

    QHBoxLayout* m_pLayout;
    GameManager* m_pGameManager;
    SettingsWidget* m_pSettingsWidget;
    GameOverScreen* m_pGameOverScreen;
    GameResults* m_pGameResults;

    Ui::MainWindow *ui;
    void onStartGame(Settings settings);
};


#endif // MAINWINDOW_H
