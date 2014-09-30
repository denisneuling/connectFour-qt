#ifndef GAME_H
#define GAME_H

#include <QObject>
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
    Game(Result result, Player winner, Player loser, double duration = 0.0) : result(result), winner(winner), loser(loser), duration(duration) {}

    Result result;
    Player winner;
    Player loser;

    double duration;

    QString toString()
    {
        QString winText = "";
        switch (result)
        {
            case WIN_RED:
            case WIN_YELLOW:
                winText = QObject::tr("The winner is: ") + winner.getName() + QObject::tr(" against ") + loser.getName();
                break;
            case DRAW:
                winText = QObject::tr("Draw: ") + winner.getName() + " vs. " + loser.getName();
                break;
            case NOT_FINISHED:
            default:
                break;
        }
        winText += QObject::tr(" The game took: ") + duration + QObject::tr(" seconds");
        return winText.toUtf8();
    }

} Game;

#endif // GAME_H
