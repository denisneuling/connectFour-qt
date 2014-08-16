#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <memory>
#include <QObject>

#include <QDebug>
#include "coin.h"
#include "game.h"
#include "helper.h"
#include "boardcolumn.h"
#include "connectfourobject.h"
#include "player.h"

/*!
 * \brief game board class representing game board
 * \details game board splitted up into columns and rows handling coins
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class GameBoard : public QObject, public ConnectFourObject
{
    Q_OBJECT
public:
    explicit GameBoard(int rows, int columns, QObject* parent = 0);

    GameBoard(const GameBoard& other);

    ~GameBoard();

    //! add coin to the game board at the specific column
    /*!
     \param column the column where the coin should be added
     \param the coin to add
    */
    bool addCoin(int column, Coin coin);

    void removeCoin(int column);

    //! check if the game is over
    Result checkGameConditions();

    //! returns list of available columns
    std::vector<int> getAvailableMoves();

    std::vector<std::shared_ptr<BoardColumn> > getCurrentBoard();

    QString serialize();

    void deserialize(QString board);
protected:

    bool checkDrawConditions();

    Coin checkWinConditions();

    Coin getCoin(int column, int row);

    bool isCoinValidAt(int column, int row);

    std::vector<std::shared_ptr<BoardColumn> > m_pGameBoard;
};

#endif // GAMEBOARD_H
