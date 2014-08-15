#include "networkadapter.h"

NetworkAdapter::NetworkAdapter(QObject *parent) :
    QObject(parent)
{
}


bool NetworkAdapter::IsServer()
{
    return m_IsServer;
}
