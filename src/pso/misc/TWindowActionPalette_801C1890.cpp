#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TQuestListVM_8007EAF8.h"
#include "pso/misc/TWindowActionPalette_801C1890.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TWindowActionPalette.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TItemList.h"
#include "pso/enemy/TObjEneBm5Wolf.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/misc/TMainCursor.h"
#include "pso/item/TItem.h"

struct O_801C1C68 { u8 pad[4]; u8 a[0x10]; u8 b[0x10]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct C_801C1BA8 { u32 w[5]; };

struct S_801C1BA8 { u8 a; u8 b; u8 c; u8 d; s32 e; C_801C1BA8 f; };

extern "C" {
s32 read_be16_field2__10TObjPlayerFv();
int set__8FlagWordFUl(void*, int);
int clear__8FlagWordFUl(void*, int);
int TWindowActionPalette__sub_801C1C20(void* p);
int test_flags_any(void*, int);
void reset_settings_to_default__6TLobbyFv(void *);
void *TWindowActionPalette__sub_801C1C68(O_801C1C68 *self, s32 i);
u8 get_item_group__5TItemFv(void *p);
u8 get_item_type__5TItemFv(void *p);
S_801C1BA8 *fn_801C1BA8(S_801C1BA8 *arg0, S_801C1BA8 *arg1);
}

void init_6x21_inter_level_warp_packet(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x21;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::send_warp_packet() { bswap_warp_packet(); TLobby__send_and_handle_60((u8 *)this); }

void TObjPlayer__sub_801C18E0(void* p) { ((TObjPlayer *)p)->byteswap_set_position_cmd(); TLobby__send_and_handle_60((u8 *)p); }

void TObjPlayer::byteswap_set_position_cmd() {
    s32 arg0 = (s32)this;
    read_be16_field2__10TObjPlayerFv();
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

void fn_801C19D8(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }

void fn_801C19E0(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

void fn_801C19E8(void* p) { *(s32*)((char*)p + 0x0) = 0; }

void fn_801C19F4(void* p) { *(s32*)((char*)p + 0x0) = 1; }

void* TObjPlayer__sub_801C1A00(void* p) { TObjPlayer__sub_801C1A30(p); return p; }

void TObjPlayer__sub_801C1A30(void* p) { *(s32*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0x4) = 0; }

void *TObjPlayer::reset_lobby_settings() {
    reset_settings_to_default__6TLobbyFv(this);
    return this;
}

u8 is_item_equipped(TObjPlayer *player) {
  unsigned int var_r31;
  var_r31 = 0;
  if ((((TItem *)player)->test_item_flags(4) != 0U) && (((TItem *)player)->test_item_flags(8) != 0U))
  {
    var_r31 = 1;
  }
  return var_r31;
}

void TObjPlayer__sub_801C1AC8(void *self) {
    is_item_stackable(get_item_type__5TItemFv(self), get_item_group__5TItemFv(self));
}

void TObjPlayer__sub_801C1B0C(void) {  }

int TObjPlayer::set_flags_bit2() { return set__8FlagWordFUl((char*)this + 0x1c, 2); }

int TObjPlayer::set_flags_bit1() { return set__8FlagWordFUl((char*)this + 0x1c, 1); }

int TObjPlayer::clear_flag_1_at_1c() { return clear__8FlagWordFUl((char*)this + 0x1c, 1); }

s32 fn_801C1B88(void* p) { return *(s32*)((char*)p + 0x0); }

f32 get_lock_target_distance_sq(void* p) { return *(f32*)((char*)p + 0x8); }

u16 get_lock_target_id(void* p) { return *(u16*)((char*)p + 0x4); }

s32 fn_801C1BA0(void* p) { return *(s32*)((char*)p + 0x24); }

S_801C1BA8 *fn_801C1BA8(S_801C1BA8 *arg0, S_801C1BA8 *arg1) {
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
    arg0->d = arg1->d;
    arg0->e = arg1->e;
    arg0->f = arg1->f;
    return arg0;
}

int TWindowActionPalette::handle_input_forward() { return TWindowActionPalette__sub_801C1C20(this); }

int TWindowActionPalette__sub_801C1C20(void* p) { return *(u32*)((char*)p + 0x0) == 0; }

void TWindowActionPalette::is_channel_active_at(s32 arg0, s32 i, s32 arg2) {
    s32 *p = (s32 *)((s32)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    ((TMainCursor *)(p + arg2))->is_channel_active();
}

void *TWindowActionPalette__sub_801C1C68(O_801C1C68 *self, s32 i) {
    if (i == 0) {
        return self->a;
    }
    return self->b;
}

void is_action_channel_active(s32 *arg0, s32 arg1) {
    TWindowActionPalette::is_channel_active_at((s32) arg0, *arg0, arg1);
}

void TWindowActionPalette::set_palette_entry(s32 arg0, s32 i, s32 arg2, s32 arg3, s32 arg4) {
    s32 *p = (s32 *)((s32)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    s32 temp_r31 = (s32)(p + arg2);
    ((TWindowActionPalette *)temp_r31)->set_mode((u8)arg3);
    ((TWindowActionPalette *)temp_r31)->set_slot((u8)arg4);
}

void TWindowActionPalette::set_slot_by_index(s32 arg0, s32 i, s32 arg2, s32 arg3) {
    s32 *p = (s32 *)((s32)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    ((TWindowActionPalette *)(p + arg2))->set_slot((u8)arg3);
}

void TWindowActionPalette::set_slot_mode(s32 arg0, s32 i, s32 arg2, s32 arg3) {
    s32 *p = (s32 *)((s32)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
    ((TWindowActionPalette *)(p + arg2))->set_mode((u8)arg3);
}

u8 *TWindowActionPalette__sub_801C1D7C(s32 arg0, s32 i, s32 arg2) {
  s32 var_r31;
  u8 *var_r3;
  s32 new_var;
  var_r31 = arg2;
  new_var = ((s32)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
  var_r3 = (u8 *) (new_var + (var_r31 * 4));
  var_r3 = (u8 *) ((void *) ((TMainCursor *)var_r3)->get_enabled());
  return var_r3;
}

void TWindowActionPalette::get_entry_by_index(s32 *arg0, s32 arg1) {
    TWindowActionPalette__sub_801C1D7C((s32)((s32) arg0), (s32)(*arg0), arg1);
}

u8 *TWindowActionPalette::get_slot_type(s32 arg0, s32 i, s32 arg2) {
  s32 new_var;
  u8 *var_r3;
  new_var = ((s32)TWindowActionPalette__sub_801C1C68((O_801C1C68 *)(arg0), i));
  var_r3 = (u8 *) (new_var + (arg2 * 4));
  var_r3 = (u8 *) ((void *) ((TMainCursor *)var_r3)->get_type());
  return var_r3;
}

void TWindowActionPalette::get_slot_type_for_index(s32 *arg0, s32 arg1) {
    TWindowActionPalette::get_slot_type((s32)((s32) arg0), (s32)(*arg0), arg1);
}

void* fn_801C1E44(void* p) { return p; }

void* fn_801C1E48(void* p) { return (char*)p + 0x24; }

int test_photon_blast_modifier(void* p) { return TWindowActionPalette__sub_801C1C20((char*)p + 0x24); }

void fn_801C1E74(void* p) { fn_801C1E98((void*)((char*)p + 0x24)); }

void fn_801C1E98(void* p) { *(s32*)((char*)p + 0x0) = 0; }

void fn_801C1EA4(void* p) { fn_801C1E98(p); }

void fn_801C1EC4(void* p) { fn_801C1EE8((void*)((char*)p + 0x24)); }

void fn_801C1EE8(void* p) { *(s32*)((char*)p + 0x0) = 1; }

void fn_801C1EF4(void* p) { fn_801C1EE8(p); }

void set_photon_blast_kind(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }

void fn_801C1F1C(void* p) { fn_801C1F40((s32 *)((char*)p + 0x4c)); }

void fn_801C1F40(s32 *arg0) {
    *arg0 -= 1;
}

int TObjPlayer__sub_801C1F50(void* p) { return test_flags_any((char*)p + 0x40, 2); }

void TObjPlayer__sub_801C1F78(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }

s32 TObjPlayer::free_owned_buffer_a(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

s32 TObjPlayer::free_owned_buffer_b(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
