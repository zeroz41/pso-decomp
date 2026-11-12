#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/trap/TOMine.h"
#include "pso/object/trap/TOMineIcon04.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_80087278.h"

extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();

extern "C" void get_name__6TOMineFv();


extern "C" {
void vfunc_80__12TOMineIcon04Fv(s32 arg0);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void init_collision_body_parts(void *, void *, s32);
extern u8 mine_collision_body_parts[];
extern void *__vt__12TOMineIcon04[];
extern const char *TOMineIcon04__name;
extern s32 game_difficulty_selection;
extern void *lbl_805D5A50;
int vfunc_82__12TOMineIcon04Fv(void* p);
void vfunc_84__12TOMineIcon04Fv(void);
void *__dt__12TOMineIcon04Fv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__dt__6TOMineFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TOMineIcon04::vfunc_84() {  }
void TOMineIcon04::vfunc_82() { spawn_particle_effect((char*)this + 0x2fc, 140); }

extern void *tl_05;

void roll_physical_accuracy__6TOMineFPvlf();
void try_start_action__6TOMineFll();
void apply_knockback_from_attacker__6TOMineFPUcf();
void vfunc_79__6TOMineFv();
void spawn_disp_objects__6TOMineFv(u8 *arg0);
void apply_object_set_data__6TOMineFPv();
void vfunc_85__6TOMineFv();
void vfunc_6__6TOMineFPsl();
void receive_direct_attack__6TOMineFPv19DirectAttackPayloadPvll();
void vfunc_86__6TOMineFv();
void render__6TOMineFv();
void vfunc_29__9TObjCharaFv();
void vfunc_74__9TObjCharaFl();
void recalc_stats__9TObjCharaFv();
void vfunc_28__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_63__9TObjCharaFv();
void vfunc_62__9TObjCharaFv();
void vfunc_61__9TObjCharaFv();
void vfunc_60__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_58__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
void vfunc_43__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void interact__14TObjCollidableFl();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_movement_ailment__9TObjCharaFl();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_shock_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void receive_weapon_special_attack__6TOMineFPvPv();
void select_melee_contact_body__6TOMineFPvf();
void calc_distance_accuracy_penalty__6TOMineFPvPvPvf();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void apply_defense_stat_status__9TObjCharaFPv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFf();
void vfunc_75__9TObjCharaFf();
void get_center__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void is_target_in_attack_range__9TObjCharaFv();
void render_shadows__7TObjectFv();
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void run_task__6TOMineFv();
void vfunc_81__6TOMineFv();
void receive_physical_attack__6TOMineFPvf();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void update_action_hold_status__9TObjCharaFv();
void update_actor_ground_y__9TObjCharaFv();
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();

void *__vt__12TOMineIcon04[87] = {
    0,
    0,
    (void *)__dt__12TOMineIcon04Fv,
    (void *)run_task__6TOMineFv,
    (void *)render__6TOMineFv,
    (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__6TOMineFPsl,
    (void *)apply_object_set_data__6TOMineFPv,
    (void *)reset_motion_fields__9TObjCharaFv,
    (void *)get_center__9TObjCharaFv,
    (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__6TOMineFv,
    (void *)interact__14TObjCollidableFl,
    (void *)add_actor_exp__9TObjCharaFl,
    (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv,
    (void *)update_actor_ground_y__9TObjCharaFv,
    (void *)vfunc_18__9TObjCharaFPUc,
    (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__6TOMineFPvf,
    (void *)calc_distance_accuracy_penalty__6TOMineFPvPvPvf,
    (void *)receive_physical_attack__6TOMineFPvf,
    (void *)receive_direct_attack__6TOMineFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__6TOMineFPvPv,
    (void *)apply_knockback_from_attacker__6TOMineFPUcf,
    (void *)try_start_action__6TOMineFll,
    (void *)roll_physical_accuracy__6TOMineFPvlf,
    (void *)vfunc_28__9TObjCharaFv,
    (void *)vfunc_29__9TObjCharaFv,
    (void *)is_target_in_attack_range__9TObjCharaFv,
    (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv,
    (void *)&has_flag_0x800__9TObjCharaFv,
    (void *)&test_flag_1000__9TObjCharaFv,
    (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv,
    (void *)vfunc_37__9TObjCharaFv,
    (void *)update_flag30_timer__9TObjCharaFv,
    (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv,
    (void *)update_attack_stat_status__9TObjCharaFv,
    (void *)update_defense_stat_status__9TObjCharaFv,
    (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv,
    (void *)apply_paralysis__9TObjCharaFv,
    (void *)apply_slow_status__9TObjCharaFv,
    (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl,
    (void *)apply_shock_status__9TObjCharaFv,
    (void *)clear_harmful_statuses__9TObjCharaFv,
    (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv,
    (void *)cure_poison_ailment__9TObjCharaFv,
    (void *)cure_paralysis__9TObjCharaFv,
    (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf,
    (void *)apply_anti_technique__9TObjCharaFl,
    (void *)vfunc_58__9TObjCharaFv,
    (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv,
    (void *)vfunc_61__9TObjCharaFv,
    (void *)vfunc_62__9TObjCharaFv,
    (void *)vfunc_63__9TObjCharaFv,
    (void *)reset_pose__9TObjCharaFv,
    (void *)get_anim_node_position__9TObjCharaFlP3Vec,
    (void *)vfunc_66__9TObjCharaFv,
    (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl,
    (void *)apply_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_jellen_effect__9TObjCharaFv,
    (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv,
    (void *)recalc_stats__9TObjCharaFv,
    (void *)vfunc_74__9TObjCharaFl,
    (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFf,
    (void *)vfunc_77__9TObjCharaFv,
    (void *)vfunc_78__9TObjCharaFl,
    (void *)vfunc_79__6TOMineFv,
    (void *)vfunc_80__12TOMineIcon04Fv,
    (void *)vfunc_81__6TOMineFv,
    (void *)vfunc_82__12TOMineIcon04Fv,
    (void *)spawn_disp_objects__6TOMineFv,
    (void *)vfunc_84__12TOMineIcon04Fv,
    (void *)vfunc_85__6TOMineFv,
    (void *)vfunc_86__6TOMineFv,
};

void TOMineIcon04::vfunc_80() {
    s32 arg0 = (s32)this;
    u32 area;
    area = get_current_floor_area();
    switch (area) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_sound_effect(0x4C111, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x44110, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_MINE1:
    case AREA_MINE2:
        play_sound_effect(0x4004C10A, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_sound_effect(0x4004C111, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4BC07, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004BC07, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x4BC19, (void *)(arg0 + 0x38), 0, 0);
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004BC19, (void *)(arg0 + 0x38), 0, 0);
    default:
        return;
    }
}

void *TOMineIcon04::create() {
    return new TOMineIcon04((TObject *)tl_05, this);
}

void *__dt__12TOMineIcon04Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__12TOMineIcon04;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__6TOMineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
TOMineIcon04::TOMineIcon04(TObject *parent, void *set_data) : TOMine(parent) {
    m_name = TOMineIcon04__name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)get_bml_model(lbl_805D5A50, 7);
    texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 7);
    m_374 = get_bml_model(lbl_805D5A50, 3);
    m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 3);
    mode = 0;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    }
    if (set_params[1] < 0) {
        set_params[1] = 0;
    } else if (set_params[1] > 5) {
        set_params[1] = 5;
    }
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    attack.power = (f32)set_params[0] * (2.0f * (f32)game_difficulty_selection + 1.0f);
    if (game_difficulty_selection == 3) {
        attack.power *= 2.0f;
    }
    attack.kind = set_params[1];
    pad_34C = 0.5f * scale.x + 60.0f;
    m_350 = 0.5f * scale.y + 120.0f;
    update_state();
    m_35c = 0xFFFF;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, mine_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}
#pragma pop

}
