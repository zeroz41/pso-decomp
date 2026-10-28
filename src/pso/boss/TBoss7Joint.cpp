#include "types.h"
#include "pso/boss/Boss7DeRolLeCBehavior.h"
#include "pso/boss/TBoss1DragonColli.h"
#include "pso/enemy/TObjEneDD_800BB804.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss7DeRolLeC.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss7Joint.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802EEC60___vt__11TBoss7Joint {
    s32 value;
    u8 remaining[0x1A0];
};

struct J_802EEB88 { u8 pad[0x38C]; u8 sub; };

extern "C" {
s32 add_radar_scaled_marker(void *, int, int, int, f32);
extern const f32 lbl_805DEBB8;
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
extern s32 __vt__11TBoss7Joint[];
extern s32 lbl_805D3FC0;
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
extern s32 lbl_80473FB8[];
extern s32 boss7_joint_params[];
extern const f32 lbl_805DEBBC;
struct VOff_802EE9A4_arg0_802EE9A4 { char pad_0[0x2FC]; char f_2FC[1]; };

s32 apply_damage_and_set_effect__8TObjFishFl(int, int, int);
void __dl__7TObjectFPv(void *);
u32 is_part_active__11TBoss7JointFv(void *, int);

void TBoss7Joint::store_position() {
    struct VOff_802EE9A4_arg0_802EE9A4 *self = (struct VOff_802EE9A4_arg0_802EE9A4 *)this;
    VecCopy((Vec *)self->f_2FC, (const Vec *)((char *)this + 56));
    VecCopy((Vec *)((char *)this + 116), (const Vec *)self->f_2FC);
}

extern const f32 lbl_805DEBB0;
extern const f32 lbl_805DEBB4;

void TBoss7Joint::vfunc_62() {
    s16 temp_r4;
    s32 temp_r31;

    temp_r4 = this->hp;
    temp_r31 = this->hpmax - temp_r4;
    if (is_part_active__11TBoss7JointFv(this, temp_r4) != 0U) {
        TObjFish__sub_802EC468((s32)(((u8 *)this) + 0x38), lbl_805DEBB0, lbl_805DEBB4);
        apply_damage_and_set_effect__8TObjFishFl((int) (*(s32 *)((s8 *)((u8 *)this) + 0x10)), temp_r31, this->m_2d4);
    } else {
        *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) - temp_r31);
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x3C4) <= 0) {
            *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = 0;
            init_boss_stats();
        }
    }
    this->hp = (s16) this->hpmax;
    ((TBoss7DeRolLeC *)(*(s32 *)((s8 *)((u8 *)this) + 0x10)))->set_flag_800();
    clear_attack_receipts();
}

void TBoss7Joint::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 0) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)((int) (*(s32 *)((s8 *)arg0 + 0x3C0))));
        this->vfunc_83();
        store_position();
        this->vfunc_88();
        if (*(s32 *)((s8 *)this->m_a4 + 0x18) & 1) {
            ((TBoss8Dragon *)arg0)->set_player_state_default();
            add_radar_scaled_marker((u8 *)&this->position, -0x5DB4, 1, 1, lbl_805DEBB8);
        }
    }
}

void *__dt__11TBoss7JointFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TBoss7Joint;
        ((TUnk_804AF8A0 *)arg0)->clear_obj_links();
        __dt__9TObjEneDDFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_802EEC60___vt__11TBoss7Joint_size[sizeof(RecoveredGlobal_802EEC60___vt__11TBoss7Joint) == 0x1A4 ? 1 : -1];

#pragma opt_common_subs off
s32 TBoss7Joint::init_params() {
    init_position_vectors();
    fn_8002B630(&((J_802EEB88 *)this)->sub, (u8 *)lbl_80473FB8);
    initialize_linked_object_reference(&((J_802EEB88 *)this)->sub);
    transform_part_positions();
    reset_hp__9TObjEneDDFv(this, register_boss__6TLobbyFl(0x10), dispatch_shared_handler_b__6TLobbyFl(0xF), register_object__6TLobbyFl(0x10));
    *(s16 *)((s8 *)this + 0x32C) = 0x4E20;
    *(s16 *)((s8 *)this + 0x2B8) = 0x4E20;
    check_state_flag_2();
    *(s32 **)((s8 *)this + 0x350) = boss7_joint_params;
    *(s16 *)((s8 *)this + 0x33E) = *(s16 *)((s8 *)this + 0x2B8);
    *(f32 *)((s8 *)this + 0x37C) = lbl_805DEBBC;
    this->vfunc_96();
    *(s32 *)((s8 *)this + 0x3BC) = 0;
    return *(s32 *)((s8 *)this + 0x3C4) = TBoss7Joint_get_shell_max_hp();
}

u8 *TBoss7Joint__ct(u8 *boss7_joint, u8 *arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5) {
    TObjEneDD__ct(boss7_joint);
    *(s32 **)((s8 *)boss7_joint + 0x18) = &(*(RecoveredGlobal_802EEC60___vt__11TBoss7Joint *)&__vt__11TBoss7Joint).value;
    *(s32 *)((s8 *)boss7_joint + 0) = (s32) lbl_805D3FC0;
    ((TObjEneDD *)boss7_joint)->init_common_from(arg1);
    ((TBoss7Joint *)boss7_joint)->entity_id = arg2;
    *(s16 *)((s8 *)boss7_joint + 0x2C) = arg3;
    *(s32 *)((s8 *)boss7_joint + 0x3C0) = arg4;
    *(s32 *)((s8 *)boss7_joint + 0x3B8) = arg5;
    initialize_enemy_state__9TObjEneDDFv(boss7_joint, 0x49);
    ((TBoss7Joint *)boss7_joint)->init_params();
    return boss7_joint;
}

void TBoss7Joint__vt85(void) {  }
void TBoss7Joint::vfunc_28() {  }

void TBoss7Joint::vfunc_63() { this->actorFlags &= 0xfffff7ff; }

void TBoss7Joint::vfunc_61() {  }
void TBoss7Joint::apply_poison_status() {  }
void TBoss7Joint::apply_paralysis() {  }
void TBoss7Joint::apply_slow_status() {  }
void TBoss7Joint::apply_confusion_status() {  }
void TBoss7Joint::apply_movement_ailment(s32) {  }
void TBoss7Joint::apply_shock_status() {  }
void TBoss7Joint::clear_harmful_statuses() {  }

}
