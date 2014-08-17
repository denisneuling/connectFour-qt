#ifndef GAMECOINRENDERER_H
#define GAMECOINRENDERER_H

#include <vector>
#include <memory>

#include "animation.h"
#include "boardcolumn.h"
#include "connectfourrenderobject.h"
#include "helper.h"
#include "renderobject.h"

/*!
 * \class GameCoinRenderer
 * \brief Class that is responsible for rendering the coins added to the board
 * \details Class that is responsible for rendering the coins added to the board
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class GameCoinRenderer : public ConnectFourRenderObject
{
public:

    GameCoinRenderer(int width, int height, float cellSize);

    /*!
     * renders the board
     */
    virtual void draw();

    /*!
     * adds coins to the board
     */
    void updateGameCoins(int column, Coin coin);

    /*!
     * updates the whole board
     */
    void setGameBoard(std::vector<std::shared_ptr<BoardColumn> > board);
private:

    void updateAnimations();

    std::vector<Animation> m_CurrentAnimations;

    std::vector<std::shared_ptr<BoardColumn> > m_GameBoard;
};

#endif // GAMECOINRENDERER_H
