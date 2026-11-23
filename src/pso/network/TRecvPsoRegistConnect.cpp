#include "types.h"
#include "pso/network/TProtocol.h"

void TRecvPsoRegistConnect::bswap() {
    header.bswap();
    bswap_32(&server_key);
    bswap_32(&client_key);
}
