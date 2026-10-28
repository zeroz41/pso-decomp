#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TLobby_8020E400.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

void TLobby::bswap_player_fields() { ((TObjPlayer *)this)->read_be16_field2(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }
void TLobby::send_player_update() { bswap_player_fields(); send_subcommand((u8 *)this); }

struct Item_8020E484 { u8 pad[0x80]; s32 v; };

struct Obj_8020E484 { u8 pad[0x1c]; s32 max; s32 count; Item_8020E484 **ptrs; s32 *vals; };

extern "C" {
void append_wave_member(Obj_8020E484 *o, Item_8020E484 *item);
}
void build_6x76_set_entity_set_flags(void* p) { *(u8*)((char*)p + 0x0) = 118; *(u8*)((char*)p + 0x1) = 2; }

void append_wave_member(Obj_8020E484 *o, Item_8020E484 *item) {
    if (o->count < o->max) {
        o->ptrs[o->count] = item;
        o->vals[o->count++] = item->v;
    }
}

s32 TLobby::get_lobby_group(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 0;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 1;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 2;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x3C)) {
        return 3;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x64)) {
        return 4;
    }
    if (arg0 >= 0x65) {
        return 4;
    }
    return -1;
}

s32 get_shop_unit_count(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 0;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 3;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 5;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x3C)) {
        return 6;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x64)) {
        return 6;
    }
    if (arg0 >= 0x65) {
        return 6;
    }
    return -1;
}

s32 TLobby::get_shield_shop_tier_for_level(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 4;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 5;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 6;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x3C)) {
        return 7;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x64)) {
        return 7;
    }
    if (arg0 >= 0x65) {
        return 7;
    }
    return -1;
}

s32 TLobby::get_armor_shop_tier_for_level(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 4;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 6;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 7;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x3C)) {
        return 8;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x64)) {
        return 8;
    }
    if (arg0 >= 0x65) {
        return 8;
    }
    return -1;
}
