#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include "settings.h"

namespace Ui {
class SettingsWidget;
}

/*!
 * \class SettingsWidget
 * \brief widget for settings
 * \details widget for settings
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();

signals:
    void startButtonPressed(Settings settings);
    void hostServerButtonPressed(Settings settings);
    void connectButtonPressed(Settings settings);
    void highscoreButtonPressed();
    void showChatWidget();
    void onFindServerButton();

private slots:
    void on_startGameButton_clicked();

    void on_aiCheckbox_toggled(bool checked);

    void on_ipAddress_textChanged(const QString &arg1);

    void on_aiBeginsCheckbox_toggled(bool checked);

    void on_playerOneName_textChanged(const QString &arg1);

    void on_playerTwoName_textChanged(const QString &arg1);

    void on_hostServerButton_clicked();

    void on_connectButton_clicked();

    void on_highScoreButtonPressed_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_showChatButton_clicked();

    void on_aiStrengthComboBox_currentIndexChanged(int index);

    void on_findServerButton_clicked();

private:
    Ui::SettingsWidget *ui;
    Settings m_Settings;
};

#endif // SETTINGSWIDGET_H
