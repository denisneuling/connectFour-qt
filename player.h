#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "coin.h"

/*!
 * \class Player
 * \brief player data holder
 * \details class representing a player
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class Player
{
public:
    Player() : m_Name(""), m_Color(RED)
    {

    }

    Player(QString name, Coin color, bool isAiPlayer = false) : m_Name(name), m_Color(color), m_AiPlayer(isAiPlayer)
    {

    }


    Coin getCoin()
    {
        return m_Color;
    }

    QString getName()
    {
        return m_Name;
    }

    bool isAiPlayer()
    {
        return m_AiPlayer;
    }

private:
    QString m_Name;
    Coin m_Color;
    bool m_AiPlayer;
};

#endif // PLAYER_H
