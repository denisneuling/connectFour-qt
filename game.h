#ifndef GAME_H
#define GAME_H

#include <QString>
#include "player.h"


typedef enum Result
{
    NOT_FINISHED = 0,
    WIN_RED,
    WIN_YELLOW,
    DRAW,
} Result;

//! data holder for game results
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
