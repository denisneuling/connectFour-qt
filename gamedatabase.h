#ifndef GAMEDATABASE_H
#define GAMEDATABASE_H

#include <vector>

#include <QList>
#include <QObject>
#include <QtSql>

#include "game.h"
#include "player.h"

/*!
 * \class GameDatabase
 * \brief singleton class that manages the game result database
 * \details singleton class that manages the game result database
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class GameDatabase : public QObject
{
    Q_OBJECT
public:
    ~GameDatabase();

    //! Adds a game to the database
    /*!
     * \param the game to add
     */
    void addGame(Game game);

    QStringList getGames();

    static GameDatabase& getInstance();
signals:

public slots:

private:
    explicit GameDatabase(QObject *parent = 0);
    GameDatabase(GameDatabase const&);
    void operator=(GameDatabase const&);
    QSqlDatabase m_DB;
};

#endif // GAMEDATABASE_H
