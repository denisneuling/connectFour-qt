#include "boardcolumn.h"

BoardColumn::BoardColumn(int rows) :
    m_Rows(rows)
{
    m_CurrentAmountOfCoins = 0;
    m_pCoins = new Coin[m_Rows];
}

bool BoardColumn::isFull()
{
    return m_CurrentAmountOfCoins >= m_Rows;
}

int BoardColumn::getCurrentAmountOfCoins()
{
    return m_CurrentAmountOfCoins;
}

bool BoardColumn::addCoin(Coin coin)
{
    if (isFull())
        return false;
    m_pCoin[m_CurrentAmountOfCoins++] = coin;
    return true;
}

Coin BoardColumn::getCoin(int index)
{
    if (index > m_Rows)
        throw 'out of range';
    return m_pCoin[index];
}
