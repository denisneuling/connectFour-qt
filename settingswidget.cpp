#include <QDebug>
#include "gamemanager.h"
#include "settingswidget.h"
#include "ui_settingswidget.h"

#include "gameserver.h"

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);
    m_Settings.useAI = false;
    m_Settings.aiBegins = false;
}

SettingsWidget::~SettingsWidget()
{
    delete ui;
}

void SettingsWidget::on_startGameButton_clicked()
{
    m_Settings.width = ui->xSize->value();
    m_Settings.height = ui->ySize->value();
    emit startButtonPressed(m_Settings);
}

void SettingsWidget::on_aiCheckbox_toggled(bool checked)
{
    ui->playerTwoName->setEnabled(!checked);
    ui->playerTwoNameLabel->setEnabled(!checked);
    ui->aiBeginsCheckbox->setEnabled(checked);

    m_Settings.useAI = checked;
}

void SettingsWidget::on_ipAddress_textChanged(const QString &arg1)
{
    m_Settings.ipAddress = arg1;
}

void SettingsWidget::on_aiBeginsCheckbox_toggled(bool checked)
{
    m_Settings.aiBegins = checked;
}

void SettingsWidget::on_playerOneName_textChanged(const QString &arg1)
{
    m_Settings.player1 = arg1;
}

void SettingsWidget::on_playerTwoName_textChanged(const QString &arg1)
{
    m_Settings.player2 = arg1;
}

void SettingsWidget::on_hostServerButton_clicked()
{
    m_Settings.width = ui->xSize->value();
    m_Settings.height = ui->ySize->value();
    emit hostServerButtonPressed(m_Settings);
}

void SettingsWidget::on_connectButton_clicked()
{
    if (m_Settings.ipAddress.length() == 0)
    {
        QMessageBox::information(this, tr("Information"), tr("No IPAddress provided..\n Trying to connect to localhost"));
        m_Settings.ipAddress = "127.0.0.1";
    }

    emit connectButtonPressed(m_Settings);
}

void SettingsWidget::on_highScoreButtonPressed_clicked()
{
    emit highscoreButtonPressed();
}
