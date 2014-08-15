#include "gameboardrenderer.h"

GameBoardRenderer::GameBoardRenderer(int width, int height, float cellSize) :
    ConnectFourRenderObject(width, height, cellSize)
{
}

void GameBoardRenderer::init()
{
    generateBoardDisplayList();
}

void GameBoardRenderer::draw()
{
    glPushMatrix();
    glScalef(m_Scale, m_Scale, 1.0f);
    //            glStencilFunc(GL_ALWAYS, 0x1, 0x1);
    glCallList(m_BoardDisplayList);

    glPushMatrix();
    glTranslatef(m_CurrentColumn * m_CellSize + m_CellSize / 2, m_CellSize / 2 + m_Rows * m_CellSize, 0);
    QColor color = Helper::GetCoinColor(m_Player);
    glColor3f(color.red(), color.green(), color.blue());
    Helper::DrawCircle(m_CoinRadius);
    glPopMatrix();
    glPopMatrix();
}

int GameBoardRenderer::calculateAndSetColumnFromMousePoint(QPoint point)
{
    int column;
    int x = point.x();
    if (x < 0)
        x = 0;
    int width = m_Columns * m_CellSize * m_Scale;
    column = ((float)x / width) * m_Columns;
    column = (column > m_Columns - 1) ? m_Columns - 1 : column;
    column = (column < 0) ? 0 : column;
    m_CurrentColumn = column;
    return column;
}

void GameBoardRenderer::setCurrentActivePlayer(Coin player)
{
    m_Player = player;
}

void GameBoardRenderer::generateBoardDisplayList()
{
    m_BoardDisplayList = glGenLists(1);
    glNewList(m_BoardDisplayList, GL_COMPILE_AND_EXECUTE);
    glPushMatrix();
    glStencilFunc(GL_NEVER, 0x1, 0x1);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
    glPushMatrix();
    glTranslatef(m_CellSize / 2, m_CellSize / 2, 0.0f);
    for (int i = 0; i < m_Columns; i++)
    {
        glPushMatrix();
        for (int j = 0; j < m_Rows; j++)
        {
            Helper::DrawCircle(m_CoinRadius);
            glTranslatef(0.0f, m_CellSize, 0.0f);
        }
        glPopMatrix();
        glTranslatef(m_CellSize, 0.0f, 0.0f);
    }
    glPopMatrix();

    glStencilFunc(GL_NOTEQUAL, 0x1, 0x1);
    glStencilOp (GL_KEEP, GL_KEEP, GL_KEEP);
    glColor3f(250, 218, 94);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, m_Rows * m_CellSize);
    glVertex2f(m_Columns * m_CellSize, m_Rows * m_CellSize);
    glVertex2f(m_Columns * m_CellSize, 0);
    glEnd();

    glStencilFunc(GL_ALWAYS, 0x1, 0x1);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for (int i = 1; i < m_Columns; i++)
    {
        glVertex2f(i * m_CellSize, 0);
        glVertex2f(i * m_CellSize, m_Rows * m_CellSize);
    }
    for (int i = 1; i < m_Rows; i++)
    {
        glVertex2f(0, i * m_CellSize);
        glVertex2f(m_Columns * m_CellSize, i * m_CellSize);
    }
    glEnd();
    glPopMatrix();
    glEndList();
}


