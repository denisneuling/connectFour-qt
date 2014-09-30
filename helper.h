#ifndef HELPER_H
#define HELPER_H

#include <QGLWidget>
#include "coin.h"
#include "game.h"
#include <math.h>

#define PI 3.141592653

/*!
 * \class Helper
 * \brief Helper class for Connect Four
 * \details Helper class for Connect Four
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
class Helper
{
public:
    static inline QString serverSearchResult()
    {
        return "serversearchresult:";
    }

    static inline QString serverSearchRequest()
    {
        return "serversearchrequest";
    }

    static inline uint serverSearchPort()
    {
        return 454545;
    }

    static inline QString boardUpdate()
    {
        return "board,";
    }

    static inline QString chatMessage()
    {
        return "chat_msg";
    }

    static inline void DrawCircle(float radius)
    {
        int steps = 360;
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f);
        for (float angle = 0.0f; angle < 2 * PI * (1+ 1.0f / steps); angle += 2*PI / steps )
            glVertex2f(cosf(angle) * radius, sinf(angle) * radius);
        glEnd();
    }

    static inline void DrawTriangle(float size)
    {
        glBegin(GL_TRIANGLES);
        glVertex2f(-size, -size);
        glVertex2f(size, -size);
        glVertex2f(0.0f, size);
        glEnd();
    }

    static inline void DrawSquare(float size)
    {
        glBegin(GL_QUADS);
        glVertex2f(-size, -size);
        glVertex2f(-size, size);
        glVertex2f(size, size);
        glVertex2f(size, -size);
        glEnd();
    }

    static inline QColor GetCoinColor(Coin coin)
    {
        switch(coin)
        {
            case RED:
                return QColor(255, 0, 0);
            case YELLOW:
                return QColor(255, 255, 0);
            default:
                return QColor(0, 0, 0);
        }
    }

    static inline QString CoinToString(Coin coin)
    {
        switch(coin)
        {
            case RED:
                return "RED";
            case YELLOW:
                return "YELLOW";
            default:
                return "";
        }
    }

    static inline QString ResultToString(Result game)
    {
        switch(game)
        {
            case WIN_RED:
            case WIN_YELLOW:
                return QWidget::tr("WIN");
            case DRAW:
                return QWidget::tr("DRAW");
            default:
                return "";
        }
    }
};

#endif // HELPER_H
