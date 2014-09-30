#include "networkadapter.h"

NetworkAdapter::NetworkAdapter(QObject *parent) :
    QObject(parent), m_IsServer(false), m_IsConnected(false), m_pSocket(NULL)
{
}

bool NetworkAdapter::isConnected()
{
    return m_IsConnected;
}


bool NetworkAdapter::IsServer()
{
    return m_IsServer;
}
