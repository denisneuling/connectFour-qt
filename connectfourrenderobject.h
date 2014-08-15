#ifndef CONNECTFOURRENDEROBJECT_H
#define CONNECTFOURRENDEROBJECT_H

#include <QDebug>
#include "connectfourobject.h"
#include "renderobject.h"

//! base class for each renderable connect four object
class ConnectFourRenderObject : public ConnectFourObject, public RenderObject
{
public:
    ConnectFourRenderObject(int width, int height, float cellSize) :
        ConnectFourObject(width, height), m_CellSize(cellSize)
    {
        m_CoinRadius = (m_CellSize / 2) * 0.85f;
    }

    virtual void resize(int width, int height)
    {
        if (width > height)
            m_Scale = height / (float)(m_Rows * m_CellSize + m_CellSize);
        else
            m_Scale = width / (float)(m_Rows * m_CellSize + m_CellSize);
    }


protected:

   float m_CellSize, m_CoinRadius, m_Scale;
};

#endif // CONNECTFOURRENDEROBJECT_H
