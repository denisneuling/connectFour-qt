#include <QDir>
#include "game.h"
#include "gamedatabase.h"
#include "helper.h"

GameDatabase::GameDatabase(QObject *parent) :
    QObject(parent)
{
    m_DB = QSqlDatabase::addDatabase("QSQLITE");
    m_DB.setDatabaseName( QDir::currentPath() + "/games.db3");
    if(m_DB.open())
    {
        QSqlQuery query(m_DB);
        bool result =
            query.exec("CREATE TABLE games(Id int, result int, winner_name varchar(255), winner_clr int, loser_name varchar(255));");
        if (result)
        {
            qDebug() << "created new db";
        }
        else
        {
            qDebug() << "creating table error -> maybe table/db already exists";
        }
    }
}

GameDatabase::~GameDatabase()
{
    m_DB.close();
}

void GameDatabase::addGame(Game game)
{
    if(m_DB.open())
    {
        QSqlQuery query(m_DB);
        query.prepare("INSERT INTO games(result, winner_name, winner_clr, loser_name) "
                      "VALUES (:result, :winner_name, :winner_clr, :loser_name)");
        query.bindValue(":result", (int) game.result);
        query.bindValue(":winner_name", game.winner.getName());
        query.bindValue(":winner_clr", (int)game.winner.getCoin());
        query.bindValue(":loser_name", game.loser.getName());

        query.exec();

    }
    else
    {
        qDebug() << "ERROR: game db not open";
    }
}

//! Return played games
//! \brief GameDatabase::getGames returns all played games that are stored in the sql database
//! \return the list of games stored in the sql database
//!
std::vector<std::string> GameDatabase::getGames()
{
    std::vector<std::string> list;

    if (m_DB.open())
    {
        QSqlQuery query(m_DB);
        query.exec("SELECT * from games");
        while(query.next())
        {
            Result result = (Result)query.value(1).toInt();
            QString winner_name = query.value(2).toString();
            Coin winner_coin = (Coin) query.value(3).toInt();
            QString loser_name = query.value(4).toString();
            list.push_back(
                Game(result, Player(winner_name, winner_coin), Player(loser_name, winner_coin == RED ? YELLOW : RED)).toString().toStdString());
        }
    }
    else
    {
        qDebug() << "ERROR: game db not open";
    }
    return list;
}

GameDatabase &GameDatabase::getInstance()
{
    static GameDatabase instance;
    return instance;
}
