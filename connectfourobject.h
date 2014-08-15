#ifndef CONNECTFOUROBJECT_H
#define CONNECTFOUROBJECT_H

//! base class for every connect four related class
class ConnectFourObject
{
public:
    ConnectFourObject(int width, int height) : m_Rows(height) , m_Columns(width)
    {

    }

protected:
    int m_Rows, m_Columns;
};

#endif // CONNECTFOUROBJECT_H
