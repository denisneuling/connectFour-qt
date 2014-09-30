#ifndef CONNECTFOURRENDEROBJECT_H
#define CONNECTFOURRENDEROBJECT_H

#include <QDebug>
#include "connectfourobject.h"
#include "helper.h"
#include "renderobject.h"
#include "settings.h"

/*!
 * \class ConnectFourRenderObject
 * \brief base class for each renderable connect four object
 * \details base class for each renderable connect four object
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
class ConnectFourRenderObject : public ConnectFourObject, public RenderObject
{
public:
    ConnectFourRenderObject(int width, int height, float cellSize, Design design) :
        ConnectFourObject(width, height), m_CellSize(cellSize), m_Design(design),
        m_Scale(1.0f)
    {
    }

    virtual void resize(int width, int height)
    {
        if (width > height)
            m_Scale = height / (float)(m_Rows * m_CellSize + m_CellSize);
        else
            m_Scale = width / (float)(m_Rows * m_CellSize + m_CellSize);
    }


protected:

    void drawPrimitive()
    {
        switch(m_Design)
        {
        case Round:
            Helper::DrawCircle(getCoinRadius());
            break;
        case Squared:
            Helper::DrawSquare(getCoinRadius());
            break;
        case Triangle:
            Helper::DrawTriangle(getCoinRadius());
            break;
        }
    }

    inline float getCoinRadius()
    {
        return  (m_CellSize / 2) * 0.85f;
    }

    float m_CellSize;
    Design m_Design;

    float m_Scale;
};

#endif // CONNECTFOURRENDEROBJECT_H
