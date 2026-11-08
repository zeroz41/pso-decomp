#include "pso/network/TProtocol.h"
#include "pso/ui/chat/TChatMessage_801DF918.h"
#include "pso/player/TPlySmth.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/system/byteswap.h"
#include <stddef.h>
#include "pso/network/protocol/protocol.h"

typedef char RegistConnectHeaderOffset[(offsetof(TSendPsoRegistConnect, header) == 0) ? 1 : -1];
typedef char RegistConnectPacketSize[(sizeof(TSendPsoRegistConnect) == 0x28) ? 1 : -1];

void bswap_cmd_9c_send_pso_regist(void* p) { ((packet_header *)p)->bswap(); bswap_ply_smth_pair((char*)p + 0x4); bswap_32((u32 *)((char*)p + 0xc)); }
void* construct_cmd_9c_send_pso_regist(void* p) { __ct__8TPlySmthFv((char*)p + 0x4); return p; }

void TSendPsoRegistConnect::bswap() {
    header.bswap();
}

template<> void TRecvExit<true>::bswap() {
    header.bswap();
}
