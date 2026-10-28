#include "types.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProShield.h"
#include "pso/quest/TQuestListVM.h"

extern "C" {

s32 TObjPlayer::decrement_clamp(s32 *arg0, s32 arg1) {
    *arg0 -= arg1;
    if ((s32) *arg0 < 0) {
        *arg0 = 0;
        return 0;
    }
    return 1;
}

#pragma fp_contract on
extern const f32 lbl_805DC334;

void TObjPlayer::copy_offset_position(void *quest_list_vm) {
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)(((TObjPlayer *)quest_list_vm)->get_stats()) + 0x10);
    *(f32 *)((s8 *)this + 0) = (f32) ((TQuestListVM *)quest_list_vm)->m_38;
    *(f32 *)((s8 *)this + 4) = (f32) ((lbl_805DC334 * temp_f2) + *(f32 *)((s8 *)quest_list_vm + 0x3C));
    *(f32 *)((s8 *)this + 8) = (f32) ((TQuestListVM *)quest_list_vm)->m_40;
}

void TObjPlayer::calc_pos_delta(void *arg1, void *arg2) {
    *(s16 *)((s8 *)arg2 + 0) = (s16) (*(s16 *)((s8 *)arg1 + 0) - *(s16 *)((s8 *)this + 0));
    *(s16 *)((s8 *)arg2 + 2) = (s16) (*(s16 *)((s8 *)arg1 + 2) - *(s16 *)((s8 *)this + 2));
    *(s16 *)((s8 *)arg2 + 4) = (s16) (*(s16 *)((s8 *)arg1 + 4) - *(s16 *)&this->m_flags);
    *(s16 *)((s8 *)arg2 + 6) = (s16) (*(s16 *)((s8 *)arg1 + 6) - *(s16 *)&this->m_id);
    *(s16 *)((s8 *)arg2 + 8) = (s16) (*(s16 *)((s8 *)arg1 + 8) - *(s16 *)((s8 *)this + 8));
    *(s16 *)((s8 *)arg2 + 0xA) = (s16) (*(s16 *)((s8 *)arg1 + 0xA) - *(s16 *)((s8 *)this + 0xA));
    *(s16 *)((s8 *)arg2 + 0x16) = (s16) (*(s16 *)((s8 *)arg1 + 0x16) - *(s16 *)((s8 *)this + 0x16));
    *(s16 *)((s8 *)arg2 + 0x18) = (s16) (*(s16 *)((s8 *)arg1 + 0x18) - *(s16 *)((s8 *)this + 0x18));
}

void set_params__10TObjPlayerFPvPvPviPv(void *arg0, void *arg1, void *arg2, s32 arg3, void *arg4);

s16 obj_getS16_2BA(u8 *p);

void TObjPlayer::init_shield_params(s32 arg1) {
    ((void (*)()) set_params__10TObjPlayerFPvPvPviPv)();
    *(s16 *)((s8 *)this + 0x16) = ((TItemProShield *)arg1)->get_field_2b8();
    *(s16 *)((s8 *)this + 0x18) = obj_getS16_2BA((u8 *)arg1);
}

}

struct RecoveredGlobal_801C5F54_TObjPlayer__data_8050E920 {
    s32 value;
    u8 remaining[0xEC];
};

struct Vec_801C5F84 { f32 x, y, z; };
struct Arrival_801C5F84 {
    s32 active;
    s32 yaw;
    Vec_801C5F84 pos;
};

struct Pair_801C5FCC { f32 a; f32 b; };

struct Obj_801C5FCC { s32 n; Pair_801C5FCC e[16]; };

extern "C" {
extern Arrival_801C5F84 TObjPlayer__arrival_override_table[12];
void set_arrival_override_coords(u16 arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2);
void set_arrival_override_pos(u16 idx, s32 yaw, void *pos);
extern const f32 lbl_805DC32C;
void clear_movement_history(Obj_801C5FCC *p);
s16 TObjPlayer__sub_800194E8(s32, s16);
s16 get_attack_params_atp_max(void *p);

extern const f32 lbl_805DC330;

void set_params__10TObjPlayerFPvPvPviPv(void *arg0, void *arg1, void *arg2, s32 arg3, void *arg4) {
    s16 temp_r4;

    *(s16 *)((s8 *)arg0 + 0) = (s16) (*(s16 *)((s8 *)arg2 + 0) + get_attack_params_atp_max((void *)arg3));
    temp_r4 = *(s16 *)((s8 *)arg2 + 8);
    *(s16 *)((s8 *)arg0 + 2) = (s16) (temp_r4 + *(s32 *)((s8 *)arg4 + 0x1C));
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg2 + 2);
    *(s16 *)((s8 *)arg0 + 6) = (s16) (lbl_805DC330 * (f32) (*(s16 *)((s8 *)arg2 + 0xA) + TObjPlayer__sub_800194E8(arg3, temp_r4)));
    *(s16 *)((s8 *)arg0 + 8) = (s16) (*(s16 *)((s8 *)arg2 + 4) + *(s16 *)((s8 *)arg4 + 0));
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg2 + 0xC);
    *(s16 *)((s8 *)arg0 + 0xC) = (s16) *(s16 *)((s8 *)arg4 + 2);
    *(s16 *)((s8 *)arg0 + 0xE) = (s16) *(s16 *)((s8 *)arg4 + 4);
    *(s16 *)((s8 *)arg0 + 0x10) = (s16) *(s16 *)((s8 *)arg4 + 6);
    *(s16 *)((s8 *)arg0 + 0x12) = (s16) *(s16 *)((s8 *)arg4 + 8);
    *(s16 *)((s8 *)arg0 + 0x14) = (s16) *(s16 *)((s8 *)arg4 + 0xA);
}
#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_801C5F54_TObjPlayer__data_8050E920_size[sizeof(RecoveredGlobal_801C5F54_TObjPlayer__data_8050E920) == 0xF0 ? 1 : -1];
void set_arrival_override_coords(u16 arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2) {
    s32 temp_r5;
    u8 *temp_r3;
    temp_r5 = arg0 * 0x14;
    *(s32 *)((s8 *)((u8 *)TObjPlayer__arrival_override_table + temp_r5) + 0) = 1;
    temp_r3 = (u8 *)TObjPlayer__arrival_override_table + temp_r5;
    *(s32 *)((s8 *)temp_r3 + 4) = arg1;
    *(f32 *)((s8 *)temp_r3 + 8) = farg0;
    *(f32 *)((s8 *)temp_r3 + 0xC) = farg1;
    *(f32 *)((s8 *)temp_r3 + 0x10) = farg2;
}
#pragma pop

void set_arrival_override_pos(u16 idx, s32 yaw, void *pos) {
    TObjPlayer__arrival_override_table[idx].active = 1;
    TObjPlayer__arrival_override_table[idx].yaw = yaw;
    VecCopy((Vec *)&TObjPlayer__arrival_override_table[idx].pos, (const Vec *)pos);
}
void clear_movement_history(Obj_801C5FCC *p) {
    s32 i;
    Pair_801C5FCC *e;
    p->n = 0;
    e = p->e;
    for (i = 0; i < 16; i++) {
        e->b = lbl_805DC32C;
        e->a = lbl_805DC32C;
        e++;
    }
}

}
