#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer_801BFED4.h"
#include "pso/unk/text_80072004.h"
#include "pso/misc/TUnk_804DDD28.h"
#include "pso/boss/TBoss7Crawfish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_8 { u8 bytes[0x8]; };

extern "C" {
extern const f32 TObjPlayer__data_805DC278;
s32 TFontSmallLobby__sub_801C0228();
int get_valid_child__6TLobbyFv(void*);

void TObjPlayer__sub_801BFED4(void* p) { *(s32*)((char*)p + 0x4) = -1; }
s32 TObjPlayer::setup_state() {
    s32 arg0 = (s32)this;
    __ct__8FlagWordFv(this);
    setup_state_helper();
    return arg0;
}
void TObjPlayer::setup_state_helper() { ((FlagWord *)this)->reset(); }

extern s32 lbl_804C3E50[];

u8 *TObjPlayer::init_subobject() {
    u8 *arg0 = (u8 *)this;
    *(s32 * *)&this->m_prev = lbl_804C3E50;
    init_gc_tag((s32)(arg0 + 4));
    *(s32 *)((s8 *)arg0 + 0) = 0;
    return arg0;
}

void TObjPlayer__sub_801BFF80(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(f32 *)((s8 *)arg0 + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 8) = (f32) TObjPlayer__data_805DC278;
}

s32 TObjPlayer__sub_801BFFA0(void* p) { return *(s32*)((char*)p + 0x0); }

u8 *TObjPlayer::copy_hold_params(u8 *arg1) {
    TFontSmallLobby__sub_801C0228();
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(ByteBlock_8 *)((s32) ((u8 *)this) + 8) = *(const ByteBlock_8 *)((s32) arg1 + 8);
    *(f32 *)((s8 *)((u8 *)this) + 0x10) = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    return ((u8 *)this);
}

s16 TBoss7Crawfish::get_floor() { return this->requested_action; }
int TUnk_804DDD28::vfunc_77(s32) { return 0; }
int TUnk_804DDD28::vfunc_10() { return 0; }
int TUnk_804DDD28::vfunc_5(s32) { return 0; }
int TObjPlayer::sub_802a7290_fwd() { return get_valid_child__6TLobbyFv(this); }
int TObjPlayer::is_handle_valid() { return TLobby::validate_handle((s32 *)this); }

}
