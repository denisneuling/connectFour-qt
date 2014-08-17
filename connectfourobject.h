#ifndef CONNECTFOUROBJECT_H
#define CONNECTFOUROBJECT_H

/*!
 * \class ConnectFourObject
 * \brief base class for every connect four related class
 * \details base class for every connect four related class
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
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
