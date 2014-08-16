#ifndef BOARDCOLUMN_H
#define BOARDCOLUMN_H

#include <QDebug>
#include "coin.h"

/*!
 * \class BoardColumn
 * \brief column for the game board
 * \details column placed at the the game board
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class BoardColumn
{
public:
    BoardColumn(int rows) :
        m_Rows(rows)
    {
        m_CurrentAmountOfCoins = 0;
        m_pCoins = new Coin[m_Rows];
    }

    ~BoardColumn()
    {
        delete [] m_pCoins;
    }

    bool isFull()
    {
        return m_CurrentAmountOfCoins >= m_Rows;
    }

    int getCurrentAmountOfCoins()
    {
        return m_CurrentAmountOfCoins;
    }

    //! adds an coin to the boardcolumn
    bool addCoin(Coin coin)
    {
        if (isFull())
            return false;
        m_pCoins[m_CurrentAmountOfCoins++] = coin;
        return true;
    }

    //! returns the coin at the specific index
    /*!
     \param index the index of the coin
     */
    Coin getCoin(int index)
    {
        if (index > m_Rows)
            throw "out of range";
        return m_pCoins[index];
    }

    //! removes the last added coin
    void removeLastCoin()
    {
        m_CurrentAmountOfCoins--;
    }

    //! clears the boardcolumn
    void clear()
    {
        m_CurrentAmountOfCoins = 0;
    }

private:
    int m_Rows, m_CurrentAmountOfCoins;

    Coin* m_pCoins;
};

#endif // BOARDCOLUMN_H
