#include "pso/player/TPlyInventory.h"
#include "pso/item/InventoryEntryCopy.h"
#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/player/PhotonBlastGauge.h"
#include "pso/system/byteswap.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemList.h"
#include "pso/enemy/wolf/TObjEneBm5Wolf.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/item/TItem.h"

#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

struct O_801C1C68 { u8 pad[4]; u8 a[0x10]; u8 b[0x10]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct C_801C1BA8 { u32 w[5]; };

struct S_801C1BA8 { u8 a; u8 b; u8 c; u8 d; s32 e; C_801C1BA8 f; };

extern "C" {
int TWindowActionPalette__sub_801C1C20(void* p);
void *TWindowActionPalette__sub_801C1C68(O_801C1C68 *self, s32 i);
}

void init_6x21_inter_level_warp_packet(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x21;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::send_warp_packet() { bswap_warp_packet(); send_subcommand((u8 *)this); }

void TObjPlayer__sub_801C18E0(void* p) { ((TObjPlayer *)p)->byteswap_set_position_cmd(); send_subcommand((u8 *)p); }

void TObjPlayer::byteswap_set_position_cmd() {
    saddr arg0 = (saddr)this;
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)(arg0 + 4));
    bswap_16((u16 *)(arg0 + 6));
    bswap_16((u16 *)(arg0 + 8));
    bswap_16((u16 *)(arg0 + 0xA));
    bswap_32((u32 *)(arg0 + 0xC));
    bswap_32((u32 *)(arg0 + 0x10));
    bswap_32((u32 *)(arg0 + 0x14));
}

void TObjPlayer::init_set_position_packet() {
    u8 *arg0 = (u8 *)this;
    this->m_flags = 0;
    this->m_id = 0;
    *(s16 *)((s8 *)arg0 + 8) = -1;
    *(s16 *)((s8 *)arg0 + 0xA) = -1;
    *(s8 *)((s8 *)arg0 + 0) = 0x3F;
    *(s8 *)((s8 *)arg0 + 1) = 6;
}

f32 fn_801C19A4(void* p) { return *(f32*)((char*)p + 0xc); }

s32 TWindowDuelResult__sub_801C19AC(f32 *arg0) {
    return (s32) *arg0;
}

void TObjPlayer__sub_801C19C8(void* p, f32 v) { *(f32*)((char*)p + 0x0) = v; }

s32 TLobby__sub_801C19D0(void* p) { return *(s32*)((char*)p + 0x4); }

void set_player_team_id(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }

void fn_801C19E0(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

void fn_801C19E8(void* p) { *(s32*)((char*)p + 0x0) = 0; }

void set_player_pk_mode_flag(void* p) { *(s32*)((char*)p + 0x0) = 1; }

void* TObjPlayer__sub_801C1A00(void* p) { TObjPlayer__sub_801C1A30(p); return p; }

void TObjPlayer__sub_801C1A30(void* p) { *(s32*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0x4) = 0; }

void *TObjPlayer::reset_lobby_settings() {
    ((TLobby *)this)->reset_settings_to_default();
    return this;
}

s32 is_item_equipped(TItem *item) {
    u8 equipped = 0;
    if (item->test_item_flags(4) != 0U && item->test_item_flags(8) != 0U) {
        equipped = 1;
    }
    return equipped;
}

void TObjPlayer__sub_801C1AC8(void *self) {
    is_item_stackable(((TItem *)self)->get_item_type(), ((TItem *)self)->get_item_group());
}

void TObjPlayer__sub_801C1B0C(void) {  }

void TObjPlayer::set_flags_bit2() { ((FlagWord *)((char*)this + 0x1c))->set(2); }

void TObjPlayer::set_flags_bit1() { ((FlagWord *)((char*)this + 0x1c))->set(1); }

void TObjPlayer::clear_flag_1_at_1c() { ((FlagWord *)((char*)this + 0x1c))->clear(1); }

s32 fn_801C1B88(void* p) { return *(s32*)((char*)p + 0x0); }

f32 get_lock_target_distance_sq(void* p) { return *(f32*)((char*)p + 0x8); }

u16 get_lock_target_id(void* p) { return *(u16*)((char*)p + 0x4); }

s32 fn_801C1BA0(void* p) { return *(s32*)((char*)p + 0x24); }

TPlyInventoryItem *fn_801C1BA8(TPlyInventoryItem *destination, const TPlyInventoryItem *source) {
    S_801C1BA8 *dst = (S_801C1BA8 *)destination;
    const S_801C1BA8 *src = (const S_801C1BA8 *)source;
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    return destination;
}

int TWindowActionPalette::handle_input_forward() { return TWindowActionPalette__sub_801C1C20(this); }

int TWindowActionPalette__sub_801C1C20(void* p) { return *(u32*)((char*)p + 0x0) == 0; }

s32 TWindowActionPalette::is_channel_active_at(saddr arg0, s32 i, s32 arg2) {
    s32 *p = (s32 *)((saddr)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    return ((TMainCursor *)(p + arg2))->is_channel_active();
}

void *TWindowActionPalette__sub_801C1C68(O_801C1C68 *self, s32 i) {
    if (i == 0) {
        return self->a;
    }
    return self->b;
}

s32 is_action_channel_active(s32 *arg0, s32 arg1) {
    return TWindowActionPalette::is_channel_active_at((saddr) arg0, *arg0, arg1);
}

void TWindowActionPalette::set_palette_entry(saddr arg0, s32 i, s32 arg2, s32 arg3, s32 arg4) {
    s32 *p = (s32 *)((saddr)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    ActionPaletteTag *tag = reinterpret_cast<ActionPaletteTag *>(p + arg2);
    set_action_palette_tag_mode(tag, static_cast<u8>(arg3));
    set_action_palette_tag_slot(tag, static_cast<u8>(arg4));
}

void TWindowActionPalette::set_slot_by_index(saddr arg0, s32 i, s32 arg2, s32 arg3) {
    s32 *p = (s32 *)((saddr)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    set_action_palette_tag_slot(reinterpret_cast<ActionPaletteTag *>(p + arg2), static_cast<u8>(arg3));
}

void TWindowActionPalette::set_slot_mode(saddr arg0, s32 i, s32 arg2, s32 arg3) {
    s32 *p = (s32 *)((saddr)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    set_action_palette_tag_mode(reinterpret_cast<ActionPaletteTag *>(p + arg2), static_cast<u8>(arg3));
}

u16 TWindowActionPalette__sub_801C1D7C(saddr arg0, s32 i, s32 arg2) {
    s32 *p = (s32 *)((saddr)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    return get_action_palette_tag_slot(reinterpret_cast<const ActionPaletteTag *>(p + arg2));
}

void TWindowActionPalette::get_entry_by_index(s32 *arg0, s32 arg1) {
    TWindowActionPalette__sub_801C1D7C((s32)((saddr) arg0), (s32)(*arg0), arg1);
}

u16 TWindowActionPalette::get_slot_type(void *effect, s32 i, s32 id) {
  saddr new_var;
  new_var = ((saddr)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(effect), i));
  return get_action_palette_tag_mode(reinterpret_cast<const ActionPaletteTag *>(new_var + id * 4));
}

u16 TWindowActionPalette::get_slot_type_for_index(s32 *effect, s32 id) {
    return TWindowActionPalette::get_slot_type(effect, (s32)(*effect), id);
}

void* ref_primary_action_palette(void* p) { return p; }

void* ref_secondary_action_palette(void* p) { return (char*)p + 0x24; }

int test_photon_blast_modifier(void* p) { return TWindowActionPalette__sub_801C1C20((char*)p + 0x24); }

void clear_secondary_action_palette_bank(void* p) { fn_801C1E98((void*)((char*)p + 0x24)); }

void fn_801C1E98(void* p) { *(s32*)((char*)p + 0x0) = 0; }

void clear_primary_action_palette_bank(void* p) { fn_801C1E98(p); }

void set_secondary_action_palette_bank(void* p) { fn_801C1EE8((void*)((char*)p + 0x24)); }

void fn_801C1EE8(void* p) { *(s32*)((char*)p + 0x0) = 1; }

void set_primary_action_palette_bank(void* p) { fn_801C1EE8(p); }

void set_photon_blast_kind(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }

void fn_801C1F1C(void* p) { fn_801C1F40((s32 *)((char*)p + 0x4c)); }

void fn_801C1F40(s32 *arg0) {
    *arg0 -= 1;
}

int PhotonBlastGauge::has_ready_flag() { return test_flags_any(&flags.bits, 2); }

void TObjPlayer__sub_801C1F78(void* p, u16 v) { *(s16*)((char*)p + 0x0) = v; }

PhotonBlastGauge::~PhotonBlastGauge() {}

s32 TObjPlayer::free_owned_buffer_b(saddr arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
