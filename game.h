#ifndef GAME_H
#define GAME_H

#include <QString>
#include "player.h"

/*!
 * \brief result enum
 * \details result enum
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
typedef enum Result
{
    NOT_FINISHED = 0,   /**< enum value NOT_FINISHED. */  
    WIN_RED,            /**< enum value WIN_RED. */  
    WIN_YELLOW,         /**< enum value WIN_YELLOW. */  
    DRAW,               /**< enum value DRAW. */  
} Result;

/*!
 * \brief data holder for game results
 * \details data holder for game results
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
typedef struct Game
{
    Game(Result result):result(result){}
    Game(Result result, Player winner, Player loser) : result(result), winner(winner), loser(loser) {}

    Result result;
    Player winner;
    Player loser;

    QString toString()
    {
        QString winText = "";
        switch (result)
        {
            case WIN_RED:
            case WIN_YELLOW:
                winText = "The winner is: " + winner.getName() + " against " + loser.getName();
                break;
            case DRAW:
                winText = "Draw: " + winner.getName() + " vs. " + loser.getName();
                break;
        }
        return winText;
    }

} Game;

#endif // GAME_H
