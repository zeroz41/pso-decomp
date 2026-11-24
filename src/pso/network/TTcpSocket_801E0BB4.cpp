#include "pso/network/TTcpSocket.h"

TTcpSocket::TTcpSocket(TObject *parent) : TSocket(parent) {
    m_name = TTcpSocket_name;
}
