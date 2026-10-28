#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/TObject.h"
#include "pso/item/TObjContainerAbeEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/item/TObjContainerItem.h"
#include "pso/system/vector.h"
#include "pso/item/TObjContainerBase.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/unk/text_80156BBC.h"
#include "pso/misc/TLazerFenceSw.h"
#include "pso/unk/text_8018A150.h"
#include "pso/misc/TUnk_804AF8D8.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/unk/text_8018A3E0.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TMotorcycle.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/object/TObjSeabedSuisoBrakable.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804B6C24FPvlf();

struct ForestBoxCollisionBody {
    f32 center[3];
    f32 radius;
    f32 height;
    u32 unknown_14;
    u32 flags;
    u32 unknown_1c[4];
};

struct ForestBoxBreakParam {
    f32 f0[3];
    f32 offset[3];
    f32 scale[3];
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 count;
    s32 f34;
    f32 f38;
    f32 f3c;
    s32 f40;
    s32 texture;
    s32 f48;
};

typedef char ForestBoxCollisionBody_size[sizeof(ForestBoxCollisionBody) == 0x2C ? 1 : -1];
typedef char ForestBoxBreakParam_size[sizeof(ForestBoxBreakParam) == 0x4C ? 1 : -1];

extern "C" {
extern const char lbl_80444B90[];
extern const char lbl_80444BAC[];
extern const char lbl_80444BC0[];
extern const char lbl_80444BDC[];
extern const char lbl_80444BF8[];
extern const char lbl_80444C10[];
extern const char lbl_80444C28[];
extern const char lbl_80444C3C[];
extern const char lbl_80444C54[];
extern const char lbl_80444C6C[];
extern const char lbl_80444C8C[];
extern const char lbl_80444CA4[];
extern const char lbl_80444CC4[];
extern const char lbl_80444CDC[];
extern const char lbl_80444D00[];
extern const char lbl_80444D24[];
extern const char lbl_80444D40[];
extern const char lbl_80444F58[];
extern const char lbl_80444F6C[];
extern const char lbl_80444F80[];
extern const char *fe_obj_hako01_hahen02_motion_names[];
extern const char *fe_obj_con_hahen1_motion_names[];
extern const char *bm_obj_seabed_con_motion_names[];
extern const char *bm_obj_seabed_con_rare_motion_names[];
extern const f32 lbl_805DBD0C;
extern const f32 lbl_805DBCF4;
extern BmlResource *lbl_805D5B78;
extern s32 lbl_805D5B7C;
extern ForestBoxBreakParam *lbl_805D5B80;
extern ForestBoxBreakParam *lbl_805D5B84;
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 get_container_param(s32 index);
}

static const char *fe_obj_hako01_hahen02_model_names[4] = {
    lbl_80444B90, lbl_80444BAC, lbl_80444BC0, NULL,
};

static BmlResourceDescriptor fe_obj_hako01_hahen02_resource_descriptor = {
    lbl_80444BDC, fe_obj_hako01_hahen02_model_names, fe_obj_hako01_hahen02_motion_names, 3, 0,
};

static const char *fe_obj_con_hahen1_model_names[5] = {
    lbl_80444BF8, lbl_80444C10, lbl_80444C28, lbl_80444C3C, NULL,
};

static BmlResourceDescriptor fe_obj_con_hahen1_resource_descriptor = {
    lbl_80444C54, fe_obj_con_hahen1_model_names, fe_obj_con_hahen1_motion_names, 4, 0,
};

static const char *bm_obj_seabed_con_model_names[4] = {
    lbl_80444C6C, lbl_80444C8C, lbl_80444CA4, NULL,
};

static BmlResourceDescriptor bm_obj_seabed_con_resource_descriptor = {
    lbl_80444CC4, bm_obj_seabed_con_model_names, bm_obj_seabed_con_motion_names, 3, 0,
};

static const char *bm_obj_seabed_con_rare_model_names[4] = {
    lbl_80444CDC, lbl_80444D00, lbl_80444D24, NULL,
};

static BmlResourceDescriptor bm_obj_seabed_con_rare_resource_descriptor = {
    lbl_80444D40, bm_obj_seabed_con_rare_model_names, bm_obj_seabed_con_rare_motion_names, 3, 0,
};

ForestBoxCollisionBody forest_box_collision_body_parts = {
    { 0.0f, 6.0f, 0.0f }, 9.0f, 9.0f, 0, 0x38003, { 0, 0, 0, 0 },
};

static ForestBoxBreakParam forest_box_break_params[4] = {
    { { 0.5f, 0.03f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, 0x800, 0x100, 0x800, 7, 0x32, 0.0f, 1.0f, 0, 0, 0x16 },
    { { 0.5f, 0.03f, 0.19f }, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, 0x400, 0x100, 0x400, 5, 0x32, 0.0f, 1.0f, 0, 0, 0x16 },
    { { 0.5f, 0.03f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, 0x800, 0x100, 0x800, 7, 0x32, 0.0f, 0.5f, 0, 0, 0x16 },
    { { 0.5f, 0.03f, 0.19f }, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, 0x400, 0x100, 0x400, 5, 0x32, 0.0f, 0.5f, 0, 0, 0x16 },
};


struct RecoveredGlobal_80189BE0___vt__17TObjContainerItem {
    s32 value;
    u8 remaining[0x148];
};

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
extern s32 __vt__17TObjContainerItem[];
extern s32 TObjContainerItem__name;
u8 *TObjContainerItem__ct(u8 *arg0, s32 arg1, s32 arg2);
s32 play_sound_effect(int, void *, int, int);
void *__dt__21TObjContainerAbeEnemyFv(void *arg0, s16 arg1);
void run_task__13TUnk_804B6C24Fv();
void render__13TUnk_804B6C24Fv();
void render_shadows__7TObjectFv();
void vfunc_6__21TObjContainerAbeEnemyFPsl();
void apply_object_set_data__13TUnk_804B9870FPv();
void reset_motion_fields__13TUnk_804806E8Fv();
void vfunc_9__13TUnk_804806E8Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void get_name__13TUnk_804B9870Fv();
void vfunc_13__13TUnk_804AF8A0Fl();
void add_actor_exp__13TUnk_804806E8Fl();
void consume_timer_field__13TUnk_804806E8Fl();
void get_actor_level_index__13TUnk_804806E8Fv();
void update_actor_ground_y__13TUnk_804806E8Fv();
void vfunc_18__13TUnk_804806E8FPUc();
void is_actor_cadence_frame__13TUnk_804806E8Fl();
void is_within_range__10TObjPlayerFl();
void calc_distance_accuracy_penalty__13TUnk_804B6C24FPvPvPvf();
void receive_physical_attack__21TObjContainerAbeEnemyFPvf();
void receive_direct_attack__13TUnk_804B6C24FPv19DirectAttackPayloadPvll();
void receive_weapon_special_attack__13TUnk_804B6C24FPvPv();
void apply_knockback_from_attacker__13TUnk_804B6C24FPUc();
void try_start_action__13TUnk_804B6C24Fll();
void vfunc_28__13TUnk_804806E8Fv();
void vfunc_29__13TUnk_804806E8Fv();
void is_target_in_attack_range__13TUnk_804806E8Fv();
void update_poison_status__13TUnk_804806E8Fv();
void update_action_hold_status__13TUnk_804806E8Fv();
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
void update_flag30_timer__13TUnk_804806E8Fv();
void update_movement_status__13TUnk_804806E8Fv();
void update_shock_clock__13TUnk_804806E8Fv();
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
void vfunc_43__13TUnk_804806E8Fv();
void apply_poison_status__13TUnk_804806E8Fv();
void apply_paralysis__13TUnk_804806E8Fv();
void apply_slow_status__13TUnk_804806E8Fv();
void apply_confusion_status__13TUnk_804806E8Fv();
void apply_movement_ailment__13TUnk_804806E8Fl();
void apply_shock_status__13TUnk_804806E8Fv();
void clear_harmful_statuses__13TUnk_804806E8Fv();
void apply_attack_stat_status__13TUnk_804806E8FPv();
void cure_poison_ailment__13TUnk_804806E8Fv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
void cure_paralysis__13TUnk_804806E8Fv();
void clear_all_status_effects__13TUnk_804806E8Fv();
void apply_action_hold_status__13TUnk_804806E8Ff();
void apply_anti_technique__13TUnk_804806E8Fl();
void vfunc_58__13TUnk_804806E8Fv();
void vfunc_59__13TUnk_804806E8Fv();
void vfunc_60__13TUnk_804806E8Fv();
void vfunc_61__13TUnk_804806E8Fv();
void vfunc_62__13TUnk_804806E8Fv();
void vfunc_63__13TUnk_804806E8Fv();
void reset_pose__13TUnk_804806E8Fv();
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
void vfunc_66__13TUnk_804806E8Fv();
void vfunc_67__13TUnk_804806E8Ff();
void get_pos__13TUnk_804806E8Fl();
void apply_switch_attack__13TUnk_804806E8Fv();
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
void vfunc_73__13TUnk_804806E8Fv();
void vfunc_74__13TUnk_804806E8Fl();
void vfunc_75__13TUnk_804806E8Ff();
void vfunc_76__13TUnk_804806E8Fv();
void vfunc_77__13TUnk_804806E8Fv();
void vfunc_78__13TUnk_804806E8Fl();
void TObjContainerAbeEnemy__vt77();
void vfunc_80__21TObjContainerAbeEnemyFv();
void vfunc_81__21TObjContainerAbeEnemyFv();
void debug_print_item_box_info__21TObjContainerAbeEnemyFv();
void *__vt__21TObjContainerAbeEnemy[83] = {
    0,
    0,
    (void *)__dt__21TObjContainerAbeEnemyFv,
    (void *)run_task__13TUnk_804B6C24Fv,
    (void *)render__13TUnk_804B6C24Fv,
    (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__21TObjContainerAbeEnemyFPsl,
    (void *)apply_object_set_data__13TUnk_804B9870FPv,
    (void *)reset_motion_fields__13TUnk_804806E8Fv,
    (void *)vfunc_9__13TUnk_804806E8Fv,
    (void *)update_object_view_visibility__13TUnk_804B9870Fff,
    (void *)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)get_name__13TUnk_804B9870Fv,
    (void *)vfunc_13__13TUnk_804AF8A0Fl,
    (void *)add_actor_exp__13TUnk_804806E8Fl,
    (void *)consume_timer_field__13TUnk_804806E8Fl,
    (void *)get_actor_level_index__13TUnk_804806E8Fv,
    (void *)update_actor_ground_y__13TUnk_804806E8Fv,
    (void *)vfunc_18__13TUnk_804806E8FPUc,
    (void *)is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)is_within_range__10TObjPlayerFl,
    (void *)calc_distance_accuracy_penalty__13TUnk_804B6C24FPvPvPvf,
    (void *)receive_physical_attack__21TObjContainerAbeEnemyFPvf,
    (void *)receive_direct_attack__13TUnk_804B6C24FPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__13TUnk_804B6C24FPvPv,
    (void *)apply_knockback_from_attacker__13TUnk_804B6C24FPUc,
    (void *)try_start_action__13TUnk_804B6C24Fll,
    (void *)&roll_physical_accuracy__13TUnk_804B6C24FPvlf,
    (void *)vfunc_28__13TUnk_804806E8Fv,
    (void *)vfunc_29__13TUnk_804806E8Fv,
    (void *)is_target_in_attack_range__13TUnk_804806E8Fv,
    (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv,
    (void *)&has_flag_0x800__13TUnk_804806E8Fv,
    (void *)&test_flag_1000__13TUnk_804806E8Fv,
    (void *)update_poison_status__13TUnk_804806E8Fv,
    (void *)update_action_hold_status__13TUnk_804806E8Fv,
    (void *)vfunc_37__13TUnk_804806E8Fv,
    (void *)update_flag30_timer__13TUnk_804806E8Fv,
    (void *)update_movement_status__13TUnk_804806E8Fv,
    (void *)update_shock_clock__13TUnk_804806E8Fv,
    (void *)update_attack_stat_status__13TUnk_804806E8Fv,
    (void *)update_defense_stat_status__13TUnk_804806E8Fv,
    (void *)vfunc_43__13TUnk_804806E8Fv,
    (void *)apply_poison_status__13TUnk_804806E8Fv,
    (void *)apply_paralysis__13TUnk_804806E8Fv,
    (void *)apply_slow_status__13TUnk_804806E8Fv,
    (void *)apply_confusion_status__13TUnk_804806E8Fv,
    (void *)apply_movement_ailment__13TUnk_804806E8Fl,
    (void *)apply_shock_status__13TUnk_804806E8Fv,
    (void *)clear_harmful_statuses__13TUnk_804806E8Fv,
    (void *)apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)apply_defense_stat_status__13TUnk_804806E8FPv,
    (void *)cure_poison_ailment__13TUnk_804806E8Fv,
    (void *)cure_paralysis__13TUnk_804806E8Fv,
    (void *)clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)apply_action_hold_status__13TUnk_804806E8Ff,
    (void *)apply_anti_technique__13TUnk_804806E8Fl,
    (void *)vfunc_58__13TUnk_804806E8Fv,
    (void *)vfunc_59__13TUnk_804806E8Fv,
    (void *)vfunc_60__13TUnk_804806E8Fv,
    (void *)vfunc_61__13TUnk_804806E8Fv,
    (void *)vfunc_62__13TUnk_804806E8Fv,
    (void *)vfunc_63__13TUnk_804806E8Fv,
    (void *)reset_pose__13TUnk_804806E8Fv,
    (void *)get_anim_node_position__13TUnk_804806E8FlP3Vec,
    (void *)vfunc_66__13TUnk_804806E8Fv,
    (void *)vfunc_67__13TUnk_804806E8Ff,
    (void *)get_pos__13TUnk_804806E8Fl,
    (void *)apply_switch_attack__13TUnk_804806E8Fv,
    (void *)enemy_spawn_jellen_effect__13TUnk_804806E8Fv,
    (void *)trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)enemy_spawn_zalure_effect__13TUnk_804806E8Fv,
    (void *)vfunc_73__13TUnk_804806E8Fv,
    (void *)vfunc_74__13TUnk_804806E8Fl,
    (void *)vfunc_75__13TUnk_804806E8Ff,
    (void *)vfunc_76__13TUnk_804806E8Fv,
    (void *)vfunc_77__13TUnk_804806E8Fv,
    (void *)vfunc_78__13TUnk_804806E8Fl,
    (void *)TObjContainerAbeEnemy__vt77,
    (void *)vfunc_80__21TObjContainerAbeEnemyFv,
    (void *)vfunc_81__21TObjContainerAbeEnemyFv,
    (void *)debug_print_item_box_info__21TObjContainerAbeEnemyFv,
};
void *__dt__17TObjContainerItemFv(void *arg0, s16 arg1);
s32 request_box_item_drop__13TUnk_804806E8FPvs(s32, void *, s32, void *);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjContainerItem::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

extern void *tl_05;

void *TObjContainerItem::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerItem__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *__dt__17TObjContainerItemFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjContainerItem;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80189BE0___vt__17TObjContainerItem_size[sizeof(RecoveredGlobal_80189BE0___vt__17TObjContainerItem) == 0x14C ? 1 : -1];
u8 *TObjContainerItem__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_container_base((arg0), (arg1), (arg2));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80189BE0___vt__17TObjContainerItem *)&__vt__17TObjContainerItem).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerItem__name;
    *(s32 *)((s8 *)arg0 + 0x34) = get_container_param(1);
    ((TObjContainerItem *)arg0)->mode = 0;
    ((TObjContainerItem *)arg0)->actorFlags = (s32) (((TObjContainerItem *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, &forest_box_collision_body_parts, 1);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + forest_box_collision_body_parts.center[1]);
    return arg0;
}

void TUnk_804B6C24::spawn_item(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    request_box_item_drop__13TUnk_804806E8FPvs(arg1, (u8 *)&this->position, this->m_360, arg0);
}
}
void play_container_break_sound(s32 arg0);
void play_container_break_sound(s32 arg0) {
    u32 global_state;
    global_state = TOKeyMachine01::get_global_state();
    switch (global_state) {
    case 1:
    case 2:
        play_sound_effect(0x4BC10, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 3:
    case 4:
    case 5:
        play_sound_effect(0x43C0F, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 6:
    case 7:
        play_sound_effect(0x4004BC09, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 8:
    case 9:
    case 10:
        play_sound_effect(0x4004BC10, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 16:
    case 17:
        play_sound_effect(0x4004BC05, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 19:
    case 20:
        play_sound_effect(0x4BC05, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 21:
    case 22:
        play_sound_effect(0x4004BC05, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        play_sound_effect(0x4BC16, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 28:
    case 29:
        play_sound_effect(0x4004BC16, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 34:
        play_sound_effect(0x4004BC16, (void *)(arg0 + 0x38), 0, 0);
        return;
    case 35:
        play_sound_effect(0x4004BC16, (void *)(arg0 + 0x38), 0, 0);
    default:
        return;
    }
}

struct Item_80189E3C { u8 pad[0x30]; s32 data[3]; };

struct Obj_80189E3C {
    u8 pad[0x68];
    f32 x68;
    u8 pad6c[0x84 - 0x6C];
    s32 data[3];
    u8 pad90[0x360 - 0x90];
    s32 x360;
};

extern "C" {
void TItem__sub_80101DB8(Item_80189E3C *);
void debug_printf_at(s32 id, const char *fmt, ...);
extern const char lbl_80444F00[];
extern const char lbl_80444F10[];
extern const char lbl_80444F20[];
void TUnk_804B6C24::debug_print_item_box_info() {
    Obj_80189E3C *self = (Obj_80189E3C *)this;
    Item_80189E3C item;
    if (this->scale > lbl_805DBCF4) {
        this->m_360 = 1;
    } else {
        this->m_360 = 0;
    }
    if (this->m_360 != 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x13001C, lbl_80444F00);
    } else {
        TObjNpcEnemy::set_global_count(0xFF00FF);
        debug_printf_at(0x13001C, lbl_80444F10);
        debug_printf_at(0x130020, lbl_80444F20);
        item.data[0] = self->data[0];
        item.data[1] = self->data[1];
        item.data[2] = self->data[2];
        TItem__sub_80101DB8(&item);
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

}

struct Base_8018A0B4 { char pad[0x18]; };
struct VObj_8018A0B4 : Base_8018A0B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20(s32, f32);
};

struct SubBase_80189F24 { u8 pad[0x14]; };

struct Sub_80189F24 : SubBase_80189F24 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    u8 pad[0x24 - 0x18];
};

struct VBase_80189F24 { u8 pad[0x18]; };

struct Obj_80189F24 : VBase_80189F24 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    u8 pad1c[0x38 - 0x1C];
    f32 pos[3];
    u8 pad44[0x334 - 0x44];
    f32 x334;
    f32 x338;
    u8 pad33c[0x340 - 0x33C];
    Sub_80189F24 sub;
    s32 x364;
};

extern "C" {
s32 step_laser_fence_fade(void *);
s32 fn_80156BBC(void *, void *);
extern const f32 lbl_805DBCF0;

void TUnk_804B6C24::render() {
    Obj_80189F24 *self = (Obj_80189F24 *)this;
    if (self->m8(self->x334, self->x338) != 1) {
        return;
    }
    self->x364 = 1;
    if (fn_80156BBC(&self->sub, self->pos) != 1) {
        return;
    }
    if (fn_80156C38((f32 *)&self->sub) == 1) {
        self->sub.m6();
        self->m79();
        self->sub.m7();
    } else {
        self->m79();
    }
}

void TUnk_804B6C24::run_task() {
    u8 *arg0 = (u8 *)this;
    step_laser_fence_fade(arg0 + 0x340);
    this->vfunc_80();
    this->m_364 = 0;
}

f32 TUnk_804B6C24::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    if (((u16) this->m_1c >= 0x1000U) && ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) && (((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&sp8, 0);
        ((TUnk_804AF8A0 *)arg0)->send_object_state_update(&sp8);
    }
    return lbl_805DBCF4;
}

f32 TUnk_804B6C24::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
    s32 temp_r4;
    struct VObj_8018A0B4 *o = (struct VObj_8018A0B4 *)this;

    temp_r4 = payload.kind;
    if ((temp_r4 == 0) || ((temp_r4 - 1) <= 3U) || (temp_r4 == 0x13)) {
        o->m20(0, lbl_805DBCF0);
    }
    return lbl_805DBCF4;
}
s32 TObjPlayer::is_within_range(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    return xyz_distance_squared((Vec *)(arg1 + 0x38), (Vec *)&this->position) < *(f32 *)((s8 *)arg0 + 0x33C);
}

}

struct RecoveredGlobal_8018A150_lbl_804B6C24 { s32 value; u8 remaining[0x148]; };

extern "C" {
u8 * __ct__13TUnk_804806E8FP7TObject(void *);
extern RecoveredGlobal_8018A150_lbl_804B6C24 lbl_804B6C24;
extern s32 lbl_805D32E8;
extern const f32 lbl_805DBD00;
extern const f32 lbl_805DBD04;
extern const f32 lbl_805DBD08;
#pragma push
#pragma fp_contract on
u8 *init_container_base(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__13TUnk_804806E8FP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804B6C24.value;
    ((TUnk_804AF8D8 *)(arg0 + 0x340))->init_vtable_804AF8D8();
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D32E8;
    ((TUnk_804B6C24 *)(arg0))->apply_object_set_data((void *)arg2);
    *(f32 *)((s8 *)arg0 + 0x334) = (f32) lbl_805DBD00;
    ((TUnk_804B6C24 *)arg0)->m_338 = (f32) lbl_805DBD04;
    *(f32 *)((s8 *)arg0 + 0x33C) = (f32) lbl_805DBD00;
    if (((TUnk_804B6C24 *)arg0)->scale > lbl_805DBCF4) {
        ((TUnk_804B6C24 *)arg0)->m_360 = 1;
    } else {
        ((TUnk_804B6C24 *)arg0)->m_360 = 0;
    }
    ((TUnk_804AF8D8 *)(arg0 + 0x340))->sub_80156CEC();
    TLazerFenceSw__sub_8018A554((arg0 + 0x340), lbl_805DBD08);
    ((TUnk_804B6C24 *)arg0)->m_364 = 0;
    return arg0;
}
#pragma pop

}

extern "C" {

extern BmlResource *container_breakup_model_archive;
void TLobby::dispatch_fish_event(void* a0) { get_bml_model(container_breakup_model_archive, (s32)a0); }

void *alloc__23TAdSinglePlyChrSelectGCFv(s32);
extern u8 seabed_rare_console_texture_filename[];
extern u8 lbl_80444F48[];
extern u32 lbl_805D5B8C;
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);

void TLobby::free_chr_select_slot() {
    if ((u32) lbl_805D5B8C != 0U) {
        release_texture_list((void*)lbl_805D5B8C);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D5B8C);
        lbl_805D5B8C = 0U;
    }
    if ((u32) container_breakup_model_archive != 0U) {
        TLobby__sub_8001FE7C(container_breakup_model_archive, 1);
        container_breakup_model_archive = NULL;
    }
}
void TLobby::load_console_resources() {
    void *p;
    container_breakup_model_archive = 0;
    switch (TOKeyMachine01::get_global_state()) {
    case 28:
    case 29:
    case 31:
        p = alloc__23TAdSinglePlyChrSelectGCFv(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &bm_obj_seabed_con_rare_resource_descriptor, 0, 0, 0);
        }
        container_breakup_model_archive = (BmlResource *)p;
        lbl_805D5B8C = (u32)load_gvm_texture_file((s32)seabed_rare_console_texture_filename);
        break;
    case 30:
    default:
        p = alloc__23TAdSinglePlyChrSelectGCFv(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &fe_obj_con_hahen1_resource_descriptor, 0, 0, 0);
        }
        container_breakup_model_archive = (BmlResource *)p;
        lbl_805D5B8C = (u32)load_gvm_texture_file((s32)lbl_80444F48);
        break;
    }
}

s32 get_container_param(s32 index) { return get_bml_model(lbl_805D5B78, index); }

void TLobby::free_char_select_resources() {
    if ((u32) lbl_805D5B7C != 0U) {
        release_texture_list((void*)lbl_805D5B7C);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D5B7C);
        lbl_805D5B7C = 0U;
    }
    if ((u32) lbl_805D5B78 != 0U) {
        TLobby__sub_8001FE7C(lbl_805D5B78, 1);
        lbl_805D5B78 = NULL;
    }
}

}

void load_forest_box_resources(void) {
    void *bundle;
    u32 *node;
    lbl_805D5B78 = NULL;
    lbl_805D5B7C = 0;
    switch (TOKeyMachine01::get_global_state()) {
    case 28:
    case 29:
    case 31:
        bundle = (void *)((TAdSinglePlyChrSelectGC *)0x440)->alloc();
        if (bundle != NULL) {
            bundle = load_resource_from_descriptor(bundle, 5, &bm_obj_seabed_con_resource_descriptor, 0, 0, 0);
        }
        lbl_805D5B78 = (BmlResource *)bundle;
        lbl_805D5B7C = (s32)load_gvm_texture_file((s32)lbl_80444F58);
        lbl_805D5B80 = &forest_box_break_params[2];
        lbl_805D5B84 = &forest_box_break_params[3];
        node = (u32 *)find_object_node((NJS_OBJECT *)(get_bml_model(lbl_805D5B78, 1)), 2);
        if (node != NULL) {
            *node |= 0x100000;
        }
        break;
    default:
        bundle = (void *)((TAdSinglePlyChrSelectGC *)0x440)->alloc();
        if (bundle != NULL) {
            bundle = load_resource_from_descriptor(bundle, 5, &fe_obj_hako01_hahen02_resource_descriptor, 0, 0, 0);
        }
        lbl_805D5B78 = (BmlResource *)bundle;
        lbl_805D5B7C = TLobby::is_online_ready() != 0 ? (s32)load_gvm_texture_file((s32)lbl_80444F6C) : (s32)load_gvm_texture_file((s32)lbl_80444F80);
        lbl_805D5B80 = &forest_box_break_params[0];
        lbl_805D5B84 = &forest_box_break_params[1];
        break;
    }
    TMotorcycle::add_entry(1, get_container_param(1), lbl_805D5B7C, lbl_805DBD0C, lbl_805DBCF4);
}
