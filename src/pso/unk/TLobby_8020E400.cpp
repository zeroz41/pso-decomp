#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/unk/TLobby_8020E400.h"
#include "pso/system/byteswap.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"

void TLobby::bswap_player_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }
void TLobby::send_player_update() { bswap_player_fields(); send_subcommand((u8 *)this); }



extern "C" {
void append_wave_member(SendPlayerUpdateObject *o, SendPlayerUpdateItem *item);
}
void build_6x76_set_entity_set_flags(void* p) { *(u8*)((char*)p + 0x0) = 118; *(u8*)((char*)p + 0x1) = 2; }

void append_wave_member(SendPlayerUpdateObject *o, SendPlayerUpdateItem *item) {
    if (o->count < o->max) {
        o->ptrs[o->count] = item;
        o->vals[o->count++] = item->v;
    }
}
