#ifndef MINMAX_H
#define MINMAX_H

#include <vector>
#include <cfloat>

#include "game.h"
#include "gameboard.h"
#include "gamemanager.h"


#define MAX_DEPTH 4

/*!
 * \class MinMax
 * \brief Negamax algorithm
 * \details Negamax algorithm
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 *
 * \link http://en.wikipedia.org/wiki/Negamax
 */
class MinMax
{
public:
    //! calculares the ai's nex move
    int calculateMove(GameBoard& board, GameManager& manager)
    {
        std::vector<int> moves = board.getAvailableMoves();
        float alpha = FLT_MIN;
        int columnToPlay = -1;

        for (auto it = moves.begin(); it != moves.end(); ++it)
        {
            float eval = scoreMove(board, manager,(*it));
            if (eval > alpha)
            {
                alpha = eval;
                columnToPlay = (*it);
            }
        }
        return columnToPlay;
    }
private:
    //! evaluates the current move
    float scoreMove(GameBoard& board, GameManager& manager, int column, int depth = 0)
    {
        Result result = board.checkGameConditions();
        Coin coin = manager.getCurrentActivePlayer().getCoin();

        if (result != NOT_FINISHED)
        {
            if (result == DRAW)
                return 0.0f;
            return ((result == WIN_RED && coin == RED) || (result == WIN_YELLOW && coin == YELLOW)) ? 1.0f : -1.0f;
        }

        float alpha = FLT_MIN;

        board.addCoin(column, coin);
        manager.switchPlayer();
        std::vector<int> moves = board.getAvailableMoves();

        for (auto it = moves.begin(); it != moves.end(); ++it)
        {
            float val = scoreMove(board, manager,(*it), depth + 1);
            alpha = std::max(alpha, -val);
            if(depth == MAX_DEPTH)
                return alpha;
        }
        board.removeCoin(column);
        manager.switchPlayer();
        return alpha;

    }
};

#endif // MINMAX_H
