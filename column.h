#ifndef BOARDCOLUMN_H
#define BOARDCOLUMN_H

#include "coin.h"

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
