#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer_801BF918.h"
#include "pso/player/TObjPlayer_801BFBCC.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801BFBEC_lbl_804C3E38 {
    s32 value;
    u8 remaining[0x8];
};

struct O_801BFC90 { u16 a; u16 b; s32 c; };

extern RecoveredGlobal_801BFBEC_lbl_804C3E38 lbl_804C3E38;
extern "C" {
void TObjPlayer__sub_801BFC90(O_801BFC90 *p);
extern const f32 lbl_805DC2DC;
void reset_stat_scale_and_ring__10TObjPlayerFi(s32 arg0);

extern const f32 TObjPlayer__data_805DC278;

void TObjPlayer::reset_scale_vector() {
    *(f32 *)((s8 *)this + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 8) = (f32) TObjPlayer__data_805DC278;
    *(s32 *)((s8 *)this + 4) = 0;
    *(s32 *)((s8 *)this + 0) = 0;
}

typedef char RecoveredGlobal_801BFBEC_lbl_804C3E38_size[sizeof(RecoveredGlobal_801BFBEC_lbl_804C3E38) == 0xC ? 1 : -1];
u8 *TObjPlayer::construct_hurt_timer() {
    u8 *arg0 = (u8 *)this;
    *(s32 **)((s8 *)arg0 + 4) = &lbl_804C3E38.value;
    ((TObjPlayer *)arg0)->reset_type();
    return arg0;
}

void*TObjPlayer::reset_and_clear() { __ct__8FlagWordFv(this); reset_counter_field4(); return this; }
void*TObjPlayer::wrap_update() { TObjPlayer__sub_801BFC90((O_801BFC90 *)(this)); return this; }

void TObjPlayer__sub_801BFC90(O_801BFC90 *p) {
    p->c = 0;
    p->a = 0xFFFF;
    p->b = 0;
}

void*TObjPlayer::set_vec4_const_wrapper() { set_vec4_const(); return this; }
void*TObjPlayer::init_members() { zero_vec3(this); return this; }
void*TObjPlayer::init_wrapper() { TObjPlayer__sub_801BFD3C(this); return this; }
void TObjPlayer__sub_801BFD3C(void* p) { *(s16*)((char*)p + 0x0) = 0; *(s16*)((char*)p + 0x2) = 0; *(s32*)((char*)p + 0x4) = 0; *(s16*)((char*)p + 0x8) = 0; }
void*TObjPlayer::init_sub() { __ct__8FlagWordFv(((char*)this + 0xc)); reset_stat_scale_and_ring__10TObjPlayerFi((s32)this); return this; }
void*TObjPlayer::init_subobjects() { __ct__8FlagWordFv(((char*)this + 0x4)); ((TObjPlayer *)((char*)this + 0x18))->init_pair(); init_player_scale_state(this); return this; }
}
int init_player_scale_state(TObjPlayer *player) {
    *(u16 *)player = 0xFFFF;
    ((FlagWord *)((u8 *)player + 4))->reset();
    player->set_speed(lbl_805DC2DC);
}
