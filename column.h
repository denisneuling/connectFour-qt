#ifndef BOARDCOLUMN_H
#define BOARDCOLUMN_H

#include "coin.h"

/*!
 * \brief column for the game board
 * \details column placed at the the game board
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class BoardColumn
{
public:
    BoardColumn(int rows);
    bool isFull();
    int getCurrentAmountOfCoins();
    bool addCoin(Coin coin);
    Coin getCoin(int index);
private:
    int m_Rows, m_CurrentAmountOfCoins;

    Coin* m_pCoin;
};

#endif // BOARDCOLUMN_H
