#ifndef GAMEBOARDRENDERER_H
#define GAMEBOARDRENDERER_H

#include <QGLWidget>
#include <QtOpenGL/QtOpenGL>
#include <QDebug>

#include "connectfourrenderobject.h"
#include "gameboard.h"
#include "helper.h"

/*!
 * \class GameBoardRenderer
 * \brief Class that is responsible for rendering the gameboard
 * \details renders the game board grid
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class GameBoardRenderer : public ConnectFourRenderObject
{
public:
    GameBoardRenderer(int width, int height, float cellSize, Design design);
    virtual ~GameBoardRenderer() { }

    void init();

    void draw();

    int calculateAndSetColumnFromMousePoint(QPoint point);

    void setCurrentActivePlayer(Coin player);

private:
    void generateBoardDisplayList();

    int m_CurrentColumn;
    GLuint m_BoardDisplayList;
    Coin m_Player;
};

#endif // GAMEBOARDRENDERER_H
