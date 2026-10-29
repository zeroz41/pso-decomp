#include "pso/enemy/TObjEnemy.h"
#include "types.h"
#include "pso/player/TObjEneRe2Flower_Bomb.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneRe2Flower.h"
#include "pso/map/FloorArea.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();

#include "pso/player/TUnk_804928CC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss8Dragon.h"

#include "pso/misc/TLobby.h"

struct VBase_14_2f517b { char pad[0x14]; };

struct VObj_14_2f517b : VBase_14_2f517b {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
};

struct Stack_800C44C4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};
struct RecoveredGlobal_800C44C4_lbl_8043BB90 {
    s32 value;
    u8 remaining[0xC];
};
typedef char RecoveredGlobal_800C44C4_lbl_8043BB90_size[sizeof(RecoveredGlobal_800C44C4_lbl_8043BB90) == 0x10 ? 1 : -1];
struct RecoveredGlobal_800C44C4_lbl_8043BBE0 {
    s32 value;
    u8 remaining[0x10];
};
typedef char RecoveredGlobal_800C44C4_lbl_8043BBE0_size[sizeof(RecoveredGlobal_800C44C4_lbl_8043BBE0) == 0x14 ? 1 : -1];
struct RecoveredGlobal_800C44C4_lbl_8043BBF4 {
    s32 value;
    u8 remaining[0x14];
};
typedef char RecoveredGlobal_800C44C4_lbl_8043BBF4_size[sizeof(RecoveredGlobal_800C44C4_lbl_8043BBF4) == 0x18 ? 1 : -1];

extern "C" {
u8 *load_enemy_bml_resource_named(s32 *, s32 *);
s32 load_enemy_bml_resource(u8 *arg0);
s32 TObjPlayer__sub_800F0928();
extern RecoveredGlobal_800C44C4_lbl_8043BB90 lbl_8043BB90;
extern RecoveredGlobal_800C44C4_lbl_8043BBE0 lbl_8043BBE0;
extern RecoveredGlobal_800C44C4_lbl_8043BBF4 lbl_8043BBF4;
extern s32 lbl_805D5178;
extern s32 lbl_805D517C;
extern s32 lbl_805D5180;
extern const f32 lbl_805D9FAC;
extern const f32 lbl_805D9FBC;
void TObjPlayer__sub_800C44C4(void);
void run_task__16TObjEneRe2FlowerFv(u8 *arg0);
void TObjEneDD__sub_800C2628(u8 *arg0, s32 arg1);
void fn_800C2A88(void *self, s32 msg);
void fn_800C2AC4(u8 *arg0, int arg1);
s32 TObjEneRe2Flower__sub_800C2E64(void *, void *);
void fn_800C3088(u8 *arg0, int arg1);
void fn_800C32DC(u8 *owner, s32 arg1);
void handle_flower_state_change(TObjEneDD *arg0, s32 arg1);
void dispatch_action__16TObjEneRe2FlowerFiUii(s32 arg0, u32 arg1, s32 arg2);
s32 obj_is_hit_receivable(void *);
f32 fabs_float(f32);
s32 is_area_attack_target_eligible(s32, s32);
s32 attack_target_history_add(s32, s32);
extern const f32 lbl_805DA000;
void vfunc_61__16TObjEneRe2FlowerFv(void);
void vfunc_28__16TObjEneRe2FlowerFv(void);
void *destroy__16TObjEneRe2FlowerFPvs(void *arg0, s16 arg1);
void vfunc_63__16TObjEneRe2FlowerFv(void *arg0);
void vfunc_62__16TObjEneRe2FlowerFv(void *arg0);
void TLobby__sub_8001FE7C(void*, int);
void free_collision_body_parts(void *);
void *TObjEneRe2Flower__ct(void *, void *, void *);
void TObjPlayer__sub_800C4D44(void);
void __dl__7TObjectFPv(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
s32 begin_state_242__16TObjEneRe2FlowerFv(void);
void queue_destruction__7TObjectFv(void *);

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_105__16TObjEneRe2FlowerFv();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFPl();
extern "C" void vfunc_84__9TObjEneDDFv();
extern "C" void vfunc_85__9TObjEneDDFv();
extern "C" void vfunc_86__9TObjEneDDFv();
extern "C" void vfunc_89__9TObjEneDDFv();
extern "C" void vfunc_90__9TObjEneDDFv();
extern "C" void vfunc_91__9TObjEneDDFv();
extern "C" void vfunc_92__9TObjEneDDFv();
extern "C" void vfunc_93__9TObjEneDDFv();
extern "C" void vfunc_94__9TObjEneDDFv();
extern "C" void vfunc_95__9TObjEneDDFv();
extern "C" void vfunc_96__9TObjEneDDFv();
extern "C" void vfunc_97__9TObjEneDDFv();
extern "C" void vfunc_98__9TObjEneDDFv();
extern "C" void vfunc_99__9TObjEneDDFv();
extern "C" void vfunc_100__9TObjEneDDFv();
extern "C" void vfunc_101__9TObjEneDDFPUc();
extern "C" void vfunc_102__9TObjEneDDFv();
extern "C" int vfunc_104__12TObjEneDD_STFf(void *p);
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void vfunc_88__16TObjEneRe2FlowerFv();
extern "C" void vfunc_61__16TObjEneRe2FlowerFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void vfunc_59__9TObjCharaFv();
extern "C" void vfunc_58__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_106__16TObjEneRe2FlowerFv();
extern "C" void TObjPlayer__sub_800C220C();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_confusion_status__9TObjCharaFv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();
extern "C" void apply_movement_ailment__9TObjCharaFl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_paralysis__9TObjCharaFv();
extern "C" void apply_poison_status__9TObjCharaFv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" char lbl_8043BAAC[];
extern "C" char lbl_8043BAC4[];
extern "C" char lbl_8043BADC[];
extern "C" char lbl_8043BAF4[];
extern "C" char lbl_8043BB08[];
extern "C" char lbl_8043BB20[];
extern "C" char lbl_8043BB38[];
extern "C" char lbl_8043BB50[];
extern "C" char lbl_8043BB64[];
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_movement_status__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();

struct FlowerCollisionPartInit {
    f32 position[3];
    f32 radius;
    u32 unknown10[2];
    u32 flags;
    u32 unknown1c[4];
};
struct FlowerSetupData {
    f32 value00;
    u32 unknown04;
    u32 flags;
    u32 unknown0c[4];
    FlowerCollisionPartInit normalParts[2];
    FlowerCollisionPartInit rareParts[2];
};
typedef char FlowerCollisionPartInit_size[sizeof(FlowerCollisionPartInit) == 0x2C ? 1 : -1];
typedef char FlowerSetupData_size[sizeof(FlowerSetupData) == 0xCC ? 1 : -1];
FlowerSetupData TObjEneRe2Flower__setup_data = {
    225.0f, 0, 0x200, {0, 0, 0, 0},
    {{{0.0f, 0.0f, 0.0f}, 5.0f, {0, 0}, 0x8003, {0, 0, 0, 0}},
     {{0.0f, 0.0f, 0.0f}, 5.0f, {0, 0}, 0x8003, {0, 0, 0, 0}}},
    {{{0.0f, 0.0f, 0.0f}, 10.0f, {0, 0}, 0x8003, {0, 0, 0, 0}},
     {{0.0f, 0.0f, 0.0f}, 20.0f, {0, 0}, 0x8003, {0, 0, 0, 0}}}
};
__declspec(section ".data") const char *bm_ene_re2_flower_model_names[2] = {
    lbl_8043BAAC, NULL
};
const char *bm_ene_re2_flower_motion_names[8] = {
    lbl_8043BAC4, lbl_8043BADC, lbl_8043BAF4, lbl_8043BB08,
    lbl_8043BB20, lbl_8043BB38, lbl_8043BB50, NULL
};
BmlResourceDescriptor TObjEneRe2Flower__resource_descriptor = {
    lbl_8043BB64, bm_ene_re2_flower_model_names,
    bm_ene_re2_flower_motion_names, 1, 7
};
TObjMotionAction TObjEneRe2Flower__animation_descriptors[8] = {
    {3, 0, 0, 0.6f, 0}, {1, 0, 4, 0.3f, 0},
    {1, 0, 5, 0.5f, 0}, {2, 2, 6, 0.6f, 0},
    {3, 0, 1, 0.5f, 0}, {3, 0, 2, 0.5f, 0},
    {1, 0, 3, 0.6f, 0}, {1, 0, 0, 2.0f, 0}
};
void *__vt__16TObjEneRe2Flower[107] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__16TObjEneRe2FlowerFPvs, (void *)&run_task__16TObjEneRe2FlowerFv,
    (void *)&TObjPlayer__sub_800C220C, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__16TObjEneRe2FlowerFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__16TObjEneRe2FlowerFv, (void *)&vfunc_62__16TObjEneRe2FlowerFv, (void *)&vfunc_63__16TObjEneRe2FlowerFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_action__16TObjEneRe2FlowerFiUii,
    (void *)&vfunc_88__16TObjEneRe2FlowerFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__12TObjEneDD_STFf, (void *)&vfunc_105__16TObjEneRe2FlowerFv, (void *)&vfunc_106__16TObjEneRe2FlowerFv,
};

void TObjEneRe2Flower::vfunc_61() {  }
void TObjEneRe2Flower::vfunc_62() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if (temp_r0 != 9) {
        if (temp_r0 == 8) {
            begin_state_242__16TObjEneRe2FlowerFv();
            clear_attack_receipts();
            return;
        }
        transition_enemy_state(9);
    }
}
void TObjEneRe2Flower::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0xA) && (temp_r0 != 0xB)) {
        transition_enemy_state(0xA);
    }
}
void TObjEneRe2Flower::vfunc_28() {  }

void dispatch_action__16TObjEneRe2FlowerFiUii(s32 arg0, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        ((TObjEneRe2Flower *)arg0)->dispatch_action(arg2);
        return;
    case 1:
        ((TObjEneDD *)arg0)->handle_state(arg2);
        return;
    case 2:
        handle_flower_state_change((TObjEneDD *)((void *)arg0), (arg2));
        return;
    case 3:
        ((TObjEneDD *)arg0)->state_chase_target(arg2);
        return;
    case 4:
        fn_800C32DC((u8 *)arg0, (arg2));
        return;
    case 5:
        fn_800C3088((u8 *)arg0, (arg2));
        return;
    case 9:
        ((TObjEneDD *)arg0)->state_damaged(arg2);
        return;
    case 10:
        fn_800C2AC4((u8 *)arg0, (arg2));
        return;
    case 6:
        TObjEneRe2Flower__sub_800C2E64((void *)arg0, (void *)arg2);
        return;
    case 7:
        ((TObjEneRe2Flower *)arg0)->handle_event(arg2);
        return;
    case 8:
        TObjEneDD__sub_800C2628((u8 *)arg0, (arg2));
        return;
    case 11:
        fn_800C2A88((void *)arg0, (arg2));
    default:
        return;
    }
}

void TObjEneRe2Flower::run_task() {
    s16 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_105();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    } else {
        temp_r3 = this->mode;
        if ((temp_r3 == 0) || (temp_r3 == 1)) {
            ((VObj_14_2f517b *)(((u8 *)this) + (1012)))->m2();
            transition_enemy_state(2);
        }
    }
    this->sub_800C3DC4();
    ((TObjEnemy *)((u8 *)this))->submit_default_cursor_candidate();
    this->vfunc_100();
}

void *destroy__16TObjEneRe2FlowerFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = __vt__16TObjEneRe2Flower;
        if (*(void **)((s8 *)arg0 + 0x428) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x428)); *(s32 *)((s8 *)arg0 + 0x428) = 0; }
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x3F4, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern u32 lbl_805D5174;

void TObjEneRe2Flower::destroy_instance() {
    TObjPlayer__sub_800C4D44();
    if ((u32) lbl_805D5174 != 0U) {
        TLobby__sub_8001FE7C((void*)lbl_805D5174, 1);
        lbl_805D5174 = 0U;
    }
}

extern void *tl_04;

void *TObjEneRe2Flower::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x42C);
    if (o != NULL) {
        o = TObjEneRe2Flower__ct(o, tl_04, arg0);
    }
    return o;
}

void TObjPlayer__sub_800C44C4(void) {
    Stack_800C44C4 stack;

    u8 *temp_r5;

    if (get_current_floor_area() == AREA_TOWER) {
        lbl_805D5174 = (u32) load_enemy_bml_resource_named((s32 *)&TObjEneRe2Flower__resource_descriptor, &lbl_8043BBE0.value);
    } else if (TObjEneDD::check_v2_mode() != 0) {
        lbl_805D5174 = (u32) load_enemy_bml_resource_named((s32 *)&TObjEneRe2Flower__resource_descriptor, &lbl_8043BBF4.value);
    } else {
        lbl_805D5174 = (u32) load_enemy_bml_resource((u8 *)((s32 *)&TObjEneRe2Flower__resource_descriptor));
    }
    lbl_805D5178 = 0;
    lbl_805D517C = 0;
    lbl_805D5180 = 0;
    TObjPlayer::create_render_texture();
    TObjPlayer__sub_800F0928();
    stack.sp8 = *(s32 *)((s8 *)&lbl_8043BB90.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8043BB90.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8043BB90.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&lbl_8043BB90.value + 0xC);
    stack.sp8 = *(s32 *)((s8 *)lbl_805D5174 + 0x430);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)lbl_805D5174 + 0x42C));
    TLobby::spawn_npc_enemy((s16)(0x37), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 8))), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 0xC))), (s32)((void *)&stack.sp8), (f32)lbl_805D9FBC, (f32)lbl_805D9FAC);
}
s32 TObjEneRe2Flower_Bomb::area_attack_deliver_direct(void *recoil, s32 arg2, void *object, f32 range) {
    s32 result;
    s32 flags;
    s32 p;
    s32 i;
    s32 ok;
    result = 0;
    flags = 0;
    if (this->m_ac == 0) {
        return 0;
    }
    TObjPlayer::init_all_slots();
    if (*(s32 *)((s8 *)((u8 *)recoil) + 4) & 1) {
        this->update_body_contact_flag(range);
        flags |= 0x80000;
    }
    if (*(s32 *)((s8 *)((u8 *)recoil) + 4) & 2) {
        this->mark_enemy_body_contacts();
        flags |= 0x100000;
    }
    if (*(s32 *)((s8 *)(this->bodies) + 0x18) & flags) {
        for (i = 0; i < 0x10; i++) {
            p = TObjPlayer::get_battle_param(i);
            if (p == 0) {
                break;
            }
            if (obj_is_hit_receivable((void *)p) != 0 && (u32)p != this->m_ac &&
                is_area_attack_target_eligible((s32)this, *(s32 *)((s8 *)p + 0x30)) != 0 &&
                !(fabs_float(*(f32 *)&(this->m_b8) - *(f32 *)((s8 *)p + 0x300)) > lbl_805DA000)) {
                ok = 1;
                if (object != 0 && attack_target_history_add((s32)object, p) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->area_attack_receive_direct((void *)p, (f32 *)((u8 *)recoil), (void *)arg2);
                    result = 1;
                }
            }
        }
    }
    return result;
}

}
