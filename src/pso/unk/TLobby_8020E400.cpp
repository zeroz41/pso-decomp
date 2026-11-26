#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/unk/TLobby_8020E400.h"
#include "pso/system/byteswap.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"

void TLobby::bswap_player_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }
void TLobby::send_player_update() { bswap_player_fields(); send_subcommand((u8 *)this); }

struct SendPlayerUpdateItem { u8 pad[0x80]; s32 v; };

struct SendPlayerUpdateObject { u8 pad[0x1c]; s32 max; s32 count; SendPlayerUpdateItem **ptrs; s32 *vals; };

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

s32 TLobby::get_lobby_group(s32 level) {
    if ((level >= 1) && (level <= 0xA)) {
        return 0;
    }
    if ((level >= 0xB) && (level <= 0x19)) {
        return 1;
    }
    if ((level >= 0x1A) && (level <= 0x2A)) {
        return 2;
    }
    if ((level >= 0x2B) && (level <= 0x3C)) {
        return 3;
    }
    if ((level >= 0x3D) && (level <= 0x64)) {
        return 4;
    }
    if (level >= 0x65) {
        return 4;
    }
    return -1;
}

s32 get_shop_unit_count(s32 level) {
    if ((level >= 1) && (level <= 0xA)) {
        return 0;
    }
    if ((level >= 0xB) && (level <= 0x19)) {
        return 3;
    }
    if ((level >= 0x1A) && (level <= 0x2A)) {
        return 5;
    }
    if ((level >= 0x2B) && (level <= 0x3C)) {
        return 6;
    }
    if ((level >= 0x3D) && (level <= 0x64)) {
        return 6;
    }
    if (level >= 0x65) {
        return 6;
    }
    return -1;
}

s32 TLobby::get_shield_shop_tier_for_level(s32 level) {
    if ((level >= 1) && (level <= 0xA)) {
        return 4;
    }
    if ((level >= 0xB) && (level <= 0x19)) {
        return 5;
    }
    if ((level >= 0x1A) && (level <= 0x2A)) {
        return 6;
    }
    if ((level >= 0x2B) && (level <= 0x3C)) {
        return 7;
    }
    if ((level >= 0x3D) && (level <= 0x64)) {
        return 7;
    }
    if (level >= 0x65) {
        return 7;
    }
    return -1;
}

s32 TLobby::get_armor_shop_tier_for_level(s32 level) {
    if ((level >= 1) && (level <= 0xA)) {
        return 4;
    }
    if ((level >= 0xB) && (level <= 0x19)) {
        return 6;
    }
    if ((level >= 0x1A) && (level <= 0x2A)) {
        return 7;
    }
    if ((level >= 0x2B) && (level <= 0x3C)) {
        return 8;
    }
    if ((level >= 0x3D) && (level <= 0x64)) {
        return 8;
    }
    if (level >= 0x65) {
        return 8;
    }
    return -1;
}
