#include <vector>

#include "gameresults.h"
#include "ui_gameresults.h"

#include "game.h"
#include "gamedatabase.h"

GameResults::GameResults(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameResults)
{
    ui->setupUi(this);
}

GameResults::~GameResults()
{
    delete ui;
}

void GameResults::on_backButton_clicked()
{
    this->setVisible(false);
}

void GameResults::showEvent(QShowEvent *)
{
    std::vector<std::string> list = GameDatabase::getInstance().getGames();
    ui->results->clear();
    for (auto it = list.begin();it != list.end(); ++it)
        ui->results->addItem(QString::fromStdString(*it));
}
