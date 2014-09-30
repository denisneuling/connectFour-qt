#include "gamecoinrenderer.h"

GameCoinRenderer::GameCoinRenderer(int width, int height, float cellSize, Design design) :
    ConnectFourRenderObject(width, height, cellSize, design)
{
    for (int i = 0; i < m_Columns; ++i)
        m_GameBoard.push_back(std::make_shared<BoardColumn>(m_Rows));
}

void GameCoinRenderer::draw()
{
    updateAnimations();
#ifndef HAVE_GLES
    glPushMatrix();
    glScalef(m_Scale, m_Scale, 1.0f);
    for (unsigned i = 0; i < m_GameBoard.size(); ++i)
    {
        for (int j = 0; j < m_GameBoard[i]->getCurrentAmountOfCoins(); ++j)
        {
            glPushMatrix();
            glTranslatef(i * m_CellSize + m_CellSize / 2, m_CellSize / 2 + j * m_CellSize, 0);
            QColor color = Helper::GetCoinColor(m_GameBoard[i]->getCoin(j));
            glColor3f(color.red(), color.green(), color.blue());
            drawPrimitive();
            glPopMatrix();
        }
    }

    for (auto it = m_CurrentAnimations.begin(); it != m_CurrentAnimations.end(); ++it)
    {
        glPushMatrix();
        glTranslatef((*it).positionX * m_CellSize + (m_CellSize / 2), (*it).currentY, 0);
        QColor color = Helper::GetCoinColor((*it).player);
        glColor3f(color.red(), color.green(), color.blue());
        drawPrimitive();
        glPopMatrix();
    }
    glPopMatrix();
#endif
}

void GameCoinRenderer::updateGameCoins(int column, Coin coin)
{
    // start animation
    Animation animation;
    animation.positionX = column;
    animation.currentY = animation.startY = m_CellSize * m_Rows;
    animation.endY = m_GameBoard[column]->getCurrentAmountOfCoins() * m_CellSize + (m_CellSize / 2);
    animation.player = coin;
    animation.active = true;
    animation.bounceUp = animation.didBounce = false;
    animation.currentBounceDistance = 0;
    animation.maxBounceDistance = (animation.startY - animation.endY) / m_Rows;
    m_CurrentAnimations.push_back(animation);
}

void GameCoinRenderer::setGameBoard(std::vector<std::shared_ptr<BoardColumn> > board)
{
    m_GameBoard = board;
}

void GameCoinRenderer::updateAnimations()
{
    for (auto it = m_CurrentAnimations.begin(); it != m_CurrentAnimations.end(); ++it)
    {

        (*it).time += TIME_STEP;
        if (!(*it).bounceUp)
        {
            (*it).currentY += ACCELERATION;
        }
        else
        {
            (*it).currentY -= ACCELERATION;
            (*it).currentBounceDistance -= ACCELERATION;

            if ((*it).currentBounceDistance >= (*it).maxBounceDistance)
            {
                (*it).bounceUp = false;
                (*it).didBounce = true;
            }
        }

        if ((*it).currentY + ACCELERATION < (*it).endY)
        {
            // add coin for further rendering after animation is finished
            if (!(*it).didBounce)
                (*it).bounceUp = true;
            else
            {
                (*it).active = false;
                m_GameBoard[(*it).positionX]->addCoin((*it).player);
            }
        }
    }

    m_CurrentAnimations.erase(
                std::remove_if(m_CurrentAnimations.begin(), m_CurrentAnimations.end(),
                               [](Animation a){ return !a.active; }), m_CurrentAnimations.end());
}
