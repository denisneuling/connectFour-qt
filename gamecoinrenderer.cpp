#include "gamecoinrenderer.h"

GameCoinRenderer::GameCoinRenderer(int width, int height, float cellSize) :
    ConnectFourRenderObject(width, height, cellSize)
{
    for (int i = 0; i < m_Columns; ++i)
        m_GameBoard.push_back(std::make_shared<BoardColumn>(m_Rows));
}

void GameCoinRenderer::draw()
{
    updateAnimations();
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
            Helper::DrawCircle(m_CoinRadius);
            glPopMatrix();
        }
    }

    for (auto it = m_CurrentAnimations.begin(); it != m_CurrentAnimations.end(); ++it)
    {
        glPushMatrix();
        glTranslatef((*it).positionX * m_CellSize + (m_CellSize / 2), (*it).currentY, 0);
        QColor color = Helper::GetCoinColor((*it).player);
        glColor3f(color.red(), color.green(), color.blue());
        Helper::DrawCircle(m_CoinRadius);
        glPopMatrix();
    }
    glPopMatrix();
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
        (*it).currentY += ACCELERATION;

        if ((*it).currentY + ACCELERATION < (*it).endY && (*it).active)
        {
            // add coin for further rendering after animation is finished
            (*it).active = false;
            m_GameBoard[(*it).positionX]->addCoin((*it).player);
        }
    }

    m_CurrentAnimations.erase(
                std::remove_if(m_CurrentAnimations.begin(), m_CurrentAnimations.end(),
                               [](Animation a){ return !a.active; }), m_CurrentAnimations.end());
}
