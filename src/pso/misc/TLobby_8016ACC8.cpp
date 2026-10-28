#include "types.h"
#include "pso/misc/TLobby_8016ACC8.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void bswap_6x05_switch_flag__5TOKeyFv(void* p);

void TLobby::finalize_and_send_60() { bswap_6x05_switch_flag__5TOKeyFv(this); send_subcommand((u8 *)this); }
void*TLobby::init_6x05_switch_changed() { init_6x04_packet((u8 *)this); *(unsigned char*)(this) = 5; *(unsigned char*)((char*)this + 0x1) = 3; return this; }
}

void init_6x04_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 4;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}
