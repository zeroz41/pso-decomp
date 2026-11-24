#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/effect/GroundContactSound.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2F28.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/math/AngleUnits.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_EffCurse3.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_Bomb.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_802D1C84.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/technique/TTecKafun.h"
#include "pso/player/TPlyDispData.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/base/TObjBase.h"
#pragma defer_codegen on



// inferred: the per-phase colour the constructor gives its two TAttackTraceStrip effects.
static const u32 mericarol_phase_effect_colors[3] = { 0xFFFD42E3, 0xFF39374B, 0xFFDEFB46 };

static const char mericarol_body_model_name[] = "bm9_s_meri_body.nj";
static const char mericarol_attack_motion_name[] = "atack_bm9_s_meri_body.njm";
static const char mericarol_damage_motion_name[] = "damage_bm9_s_meri_body.njm";
static const char mericarol_dead_motion_name[] = "dead_bm9_s_meri_body.njm";
static const char mericarol_fire_motion_name[] = "fire_bm9_s_meri_body.njm";
static const char mericarol_laugh_motion_name[] = "laugh_bm9_s_meri_body.njm";
static const char mericarol_wait_motion_name[] = "wait_bm9_s_meri_body.njm";
static const char mericarol_wait2_motion_name[] = "wait2_bm9_s_meri_body.njm";
static const char mericarol_wake_motion_name[] = "wake_bm9_s_meri_body.njm";
static const char mericarol_archive_name[] = "bm_ene_bm9_s_mericarol.bml";
static const char mericarol_low_detail_body_model_name[] = "lo_bm9_s_meri_body.nj";
static const char mericarol_low_detail_archive_name[] = "bm_ene_bm9_s_mericarol_low.bml";
static const char TObjEneBm9Mericarol__class_name_string[] = "TObjEneBm9Mericarol";

TObjEneBm9MericarolMovementParameters mericarol_movement_params = {
    { 225.0f, 0.0f, 0x200 }, { 0, 0, 0, 0 },
};

CollisionBody mericarol_collision_bodies[2] = {
    { { 0.0f, 0.0f, 0.0f }, 25.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 50.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

__declspec(section ".data") const char *mericarol_model_names[2] = {
    mericarol_body_model_name, NULL,
};

const char *mericarol_motion_names[9] = {
    mericarol_attack_motion_name, mericarol_damage_motion_name, mericarol_dead_motion_name, mericarol_fire_motion_name,
    mericarol_laugh_motion_name, mericarol_wait_motion_name, mericarol_wait2_motion_name, mericarol_wake_motion_name,
    NULL,
};

BmlResourceDescriptor mericarol_bml_descriptor = {
    mericarol_archive_name, mericarol_model_names, mericarol_motion_names, 1, 8,
};

__declspec(section ".data") const char *mericarol_low_model_names[2] = {
    mericarol_low_detail_body_model_name, NULL,
};

const char *mericarol_low_motion_names[9] = {
    mericarol_attack_motion_name, mericarol_damage_motion_name, mericarol_dead_motion_name, mericarol_fire_motion_name,
    mericarol_laugh_motion_name, mericarol_wait_motion_name, mericarol_wait2_motion_name, mericarol_wake_motion_name,
    NULL,
};

BmlResourceDescriptor mericarol_low_bml_descriptor = {
    mericarol_low_detail_archive_name, mericarol_low_model_names, mericarol_low_motion_names, 1, 8,
};

TObjMotionAction mericarol_motion_actions[9] = {
    { 3, 0, 3, 0.6f, 0 },
    { 1, 0, 5, 1.0f, 0 },
    { 1, 0, 6, 0.5f, 0 },
    { 1, 0, 5, 0.5f, 0 },
    { 2, 3, 7, 0.7f, 0 },
    { 3, 0, 1, 0.8f, 0 },
    { 3, 0, 2, 0.5f, 0 },
    { 1, 0, 4, 0.6f, 0 },
    { 1, 0, 0, 0.7f, 0 },
};

static const NpcAnimationBinding mericarol_animation_binding = { NULL, mericarol_motion_actions, 3, 1, 9 };
static const Vec lbl_80472490 = { 2.0f, 1.0f, 2.0f };
static const Vec lbl_8047249C = { 2.0f, 1.0f, 2.0f };
static const Vec player_sub_802ce68c_zero_vec = { 0.0f, 0.0f, 0.0f };

player_stats *bm9_mericarol_phase_hp_table[3];
AttackParams *bm9_mericarol_phase_attack_table[3];
ActorParamBlock *bm9_mericarol_phase_resist_table[3];
TObjEneBm9MericarolParams *mericarol_phase_param_table[3];
f32 lbl_80540B88[4];
const char *TObjEneBm9Mericarol__class_name = TObjEneBm9Mericarol__class_name_string;
SampledMotionPoints *mericarol_trail0_points;
SampledMotionPoints *mericarol_trail1_points;
BmlResource *mericarol_bml;
s32 mericarol_node_counter;
u32 lbl_805D6870;
u32 lbl_805D6874;
u32 lbl_805D6878;
#pragma push
#pragma opt_common_subs off
#pragma pop
void TObjEneBm9Mericarol::load_resources() {
    s32 i;

    if (is_split_screen() != 0) {
        mericarol_bml = load_enemy_bml_resource(&mericarol_low_bml_descriptor);
    } else {
        mericarol_bml = load_enemy_bml_resource(&mericarol_bml_descriptor);
    }
    mericarol_node_counter = 0;
    lbl_805D6870 = 0;
    lbl_80540B88[0] = 0.0f;
    lbl_80540B88[1] = 0.0f;
    lbl_80540B88[2] = 0.0f;
    lbl_805D6874 = 0;
    lbl_805D6878 = 0;
    fn_802D1CC8();
    TObjPlayer::init_alt_model();
    for (i = 0; i < 3; i++) {
        bm9_mericarol_phase_hp_table[i] = TLobby::register_boss(mericarol_phase_hp_ids[i]);
        bm9_mericarol_phase_attack_table[i] = TLobby::dispatch_shared_handler_b(mericarol_phase_attack_ids[i]);
        bm9_mericarol_phase_resist_table[i] = TLobby::register_object(mericarol_phase_resist_ids[i]);
        mericarol_phase_param_table[i] = (TObjEneBm9MericarolParams *)TLobby::dispatch_shared_handler_a(mericarol_phase_param_ids[i]);
    }
    mericarol_trail0_points = new SampledMotionPoints(2, 0.0f, 20.0f, 0.7f);
    mericarol_trail1_points = new SampledMotionPoints(2, 0.0f, 20.0f, 0.7f);
    set_motion_packed_rotation();
    mericarol_trail0_points->sample_two_nodes(mericarol_bml->models[0].model, (NJS_MOTION *)mericarol_bml->motions[mericarol_motion_actions[8].motion].motion, 0x20, 0x21);
    mericarol_trail1_points->sample_two_nodes(mericarol_bml->models[0].model, (NJS_MOTION *)mericarol_bml->motions[mericarol_motion_actions[8].motion].motion, 0x2A, 0x2B);
    clear_motion_packed_rotation();
    {
        NpcAnimationBinding params = mericarol_animation_binding;
        params.motions = mericarol_bml->motions;
        TObjNpcEnemy::register_animated_chunk(0x42, mericarol_bml->models[0].model, mericarol_bml->models[0].texlist, &params,
            mericarol_collision_bodies[0].radius, 0.0f);
    }
}

void *TObjEneBm9Mericarol::create(void *set_data) {
    return new TObjEneBm9Mericarol(tl_04, set_data);
}

void TObjEneBm9Mericarol::free_shared_instances() {
    if (mericarol_trail1_points != NULL) {
        delete mericarol_trail1_points;
        mericarol_trail1_points = NULL;
    }
    if (mericarol_trail0_points != NULL) {
        delete mericarol_trail0_points;
        mericarol_trail0_points = NULL;
    }
    fn_802D1C84();
    if (mericarol_bml != NULL) {
        delete mericarol_bml;
        mericarol_bml = NULL;
    }
}

TObjEneBm9Mericarol::TObjEneBm9Mericarol(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    s32 ph;
    s32 i;

    m_name = TObjEneBm9Mericarol__class_name;
    invoke_initialization_hook(set_data);
    init_size_tier_and_offsets();
    flags = 0;
    if (random_ratio() <= 0.002f) {
        flags |= 0x400;
    }
    init_position_vectors();
    model = (void *)mericarol_bml->models[0].model;
    texlist = mericarol_bml->models[0].texlist;
    init_model(mericarol_collision_bodies, 1);
    set_action_table(mericarol_motion_actions);
    set_motion_list(mericarol_bml->motions);
    requested_action = 2;
    set_animation(requested_action);
    set_requested_action(requested_action);
    ph = get_phase();
    reset_hp(bm9_mericarol_phase_hp_table[ph], bm9_mericarol_phase_attack_table[ph], bm9_mericarol_phase_resist_table[ph]);
    trails[0] = TAttackTraceStrip::create(0xA0303030, mericarol_phase_effect_colors[ph]);
    trails[1] = TAttackTraceStrip::create(0xA0303030, mericarol_phase_effect_colors[ph]);
    add_flags_2e4(0x12);
    movementParameters = &mericarol_movement_params;
    switch (get_phase()) {
    case 0:
        initialize_enemy_state(0x38);
        break;
    case 1:
        initialize_enemy_state(0x39);
        break;
    case 2:
        initialize_enemy_state(0x3A);
        break;
    }
    wall_reach = 5.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    draw_offset_y = 0.0f;
    m_44c = 0;
    retarget_counter = 0;
    hit_cooldown = 0;
    blink_level = 0;
    appear_fade.reset_obstruction_fade();
    attack_body = new TObjCollidable(0);
    init_collision_body_parts(attack_body, &mericarol_collision_bodies[1], 1);
    attack_history = new AreaAttackHistory(8);
    state_step = 0;
    state_timer = 0;
    rush_delay = 0;
    m_49c = 0;
    target_angle = 0;
    slide_speed = 0.0f;
    charge_effect = 0;
    sync_center_position();
    update_body_colliders();
    transform_part_positions();
    mode = 0;
    dispatch_action(mode, 4);
    enable_motion_blend();
    for (i = 0; i < 4; i++) {
        camera_fades[i].activate_and_dispatch();
    }
}

TObjEneBm9Mericarol::~TObjEneBm9Mericarol() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (trails[i] != NULL) {
            trails[i]->queue_destruction();
            trails[i] = NULL;
        }
    }
    if (attack_history != NULL) {
        delete attack_history;
        attack_history = NULL;
    }
    if (attack_body != NULL) {
        free_collision_body_parts(attack_body);
        delete attack_body;
        attack_body = NULL;
    }
    if (charge_effect != NULL) {
        charge_effect->queue_destruction();
        charge_effect = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneBm9Mericarol::run_task() {
    s16 state;
    s32 current;
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    current = flags;
    if (current & 0x10) {
        if (current_target == 0) {
            flags = current & ~0x10;
        }
    } else if (current_target != 0) {
        flags = current | 0x10;
    }
    if (update_status_effects() != 4) {
        update_action_state();
    } else {
        state = mode;
        if (state == 0 || state == 1) {
            appear_fade.reset_color();
            transition_enemy_state(2);
        }
    }
    sync_center_position();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneBm9Mericarol::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        state_hidden(reason);
        return;
    case 1:
        state_fade_in(reason);
        return;
    case 2:
        state_wait(reason);
        return;
    case 3:
        state_chase_target(reason);
        return;
    case 4:
        state_shoot(reason);
        return;
    case 5:
        state_attack(reason);
        return;
    case 6:
        state_rush(reason);
        return;
    case 10:
        state_damaged(reason);
        return;
    case 11:
        state_die(reason);
        return;
    case 7:
        state_curse(reason);
        return;
    case 8:
        state_laugh(reason);
        return;
    case 9:
        state_cast_technique(reason);
        return;
    case 12:
        state_destroy(reason);
    default:
        return;
    }
}

void TObjEneBm9Mericarol::refresh_target() {  }

void TObjEneBm9Mericarol::run_death_reaction() {
    s16 state = mode;
    if (state != 0xB && state != 0xC) {
        transition_enemy_state(0xB);
    }
}

void TObjEneBm9Mericarol::run_hit_reaction() {
    if ((s16) this->mode != 0xA) {
        if (this->flags & 0x20) {
            clear_attack_receipts();
            return;
        }
        transition_enemy_state(0xA);
    }
}

void TObjEneBm9Mericarol::run_miss_reaction() {  }

void TObjEneBm9Mericarol::sync_center_position() {
    VecCopy(&body_center, &position);
    body_center.y += 20.0f;
    VecCopy(&center, &body_center);
}

void TObjEneBm9Mericarol::update_body_colliders() {
    bodies->offset.y = body_center.y - position.y;
}

void TObjEneBm9Mericarol::set_child_flags() {  }

void TObjEneBm9Mericarol::clear_child_flags() {  }

s32 TObjEneBm9Mericarol::check_hit_flag() {
    if (this->flags & 2) {
        transition_enemy_state(8);
        return 1;
    }
    return 0;
}

TObjPlayer *TObjEneBm9Mericarol::find_nearby_target() {
    TObjPlayer *best = NULL;
    s32 n = TLobby::get_game_mode();
    TObjPlayer *pl;
    s32 i;
    for (i = 0; i < n; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (((TObjEneDD *)pl)->is_valid_target() != 0 && pl->obj_isState2_324() == 0) {
            best = pl;
            break;
        }
    }
    if (((TObjEneDD *)best)->is_valid_target() != 0 && horizontal_distance_squared(&position, &best->position) < 10000.0f) {
        return best;
    }
    return NULL;
}

void TObjEneBm9Mericarol::init_size_tier_and_offsets() {
    f32 roll;
    s32 tier;
    phase = variant;
    tier = phase;
    if (tier < 0 || tier > 2) {
        roll = random_ratio();
        if (roll > 0.9f) {
            phase = 2;
        } else if (roll > 0.8f) {
            phase = 1;
        } else {
            phase = 0;
        }
    }
    rush_chance = 0.5f + parameters[0];
    rush_speed = 3.0f + parameters[1];
    if (rush_speed < 1.0f) {
        rush_speed = 1.0f;
    }
    technique_chance = 0.1f + parameters[2];
}

s32 TObjEneBm9Mericarol::get_phase() { return phase; }

void TObjEneBm9Mericarol::play_move_sound() {
    play_persistent_sound((s32)(remap_sound_for_area(0x3A810)), this, &position, 0, 0);
}

void TObjEneBm9Mericarol::state_hidden(s32 reason) {
    switch (reason) {
    case 4:
        set_intangible();
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}

void TObjEneBm9Mericarol::state_fade_in(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 2;
        set_intangible();
        clear_child_flags();
        flags |= 0x28;
        flags &= ~0x10;
        set_field_378(2);
        this->enemy_clear_target();
        appear_fade.start_fade_in();
        play_area_sound_effect(&position);
        return;
    case 3:
        if (appear_fade.advance_toward_max() != 0) {
            transition_enemy_state(2);
        }
    case 1:
        return;
    case 0:
        advance_animation();
        update_ground_contact();
        update_body_colliders();
        return;
    case 5:
        flags &= ~0x28;
        break;
    }
}

void TObjEneBm9Mericarol::state_wait(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 2;
        clear_intangible();
        clear_child_flags();
        flags &= ~0x28;
        set_field_378(2);
        this->enemy_clear_target();
        return;
    case 3:
        if (check_hit_flag() == 0 && update_linked_position(250.0f) != 0) {
            transition_enemy_state(3);
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation();
        update_ground_contact();
        update_body_colliders();
        break;
    }
}

void TObjEneBm9Mericarol::state_chase_target(s32 reason) {
    f32 distance;
    u16 target;
    switch (reason) {
    case 4:
        if (mode == 2) {
            requested_action = 4;
            play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
        } else {
            requested_action = 3;
        }
        clear_intangible();
        set_child_flags();
        flags &= ~0x28;
        set_field_378(3);
        state_timer = 0;
        target_angle = 0;
        break;
    case 3:
        if (check_hit_flag() != 0) {
            break;
        }
        distance = destination_distance;
        if (distance > 300.0f || current_target == 0) {
            transition_enemy_state(2);
            break;
        }
        if (distance < 50.0f) {
            if (angle_difference_abs(rotation_y, target_angle) < 0x4000) {
                if (random_ratio() <= technique_chance) {
                    transition_enemy_state(9);
                    break;
                }
                transition_enemy_state(5);
            }
        } else if (state_timer > mericarol_phase_param_table[get_phase()]->shot_delay) {
            transition_enemy_state(4);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        target = 0xFFFF;
        if (tick_period_counter((saddr)this, &retarget_counter, 0x14) != 0) {
            if (destination_distance > 30.0f) {
                if (is_confused() != 0) {
                    target = enemy_nearest_visible_enemy(this, destination_distance - 30.0f);
                }
                if (target == 0xFFFF) {
                    target = enemy_find_nearest_player_in_range(this, (f32)(destination_distance - 30.0f));
                }
                if (target != 0xFFFF) {
                    enemy_set_target_id(this, target);
                }
            }
        } else if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            break;
        }
        enemy_copy_target_destination();
        update_velocity();
        state_timer++;
        target_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
        rotation_y = approach_angle_limited(rotation_y, target_angle, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        update_ground_contact();
        update_body_colliders();
        play_move_sound();
        break;
    }
}

void TObjEneBm9Mericarol::state_shoot(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 0;
        clear_intangible();
        set_child_flags();
        flags &= ~8;
        flags |= 0x20;
        set_field_378(3);
        charge_effect = 0;
        break;
    case 3:
        if (check_hit_flag() == 0 && get_flag_b4() != 0) {
            transition_enemy_state(3);
        }
        break;
    case 1:
        break;
    case 0:
        advance_animation();
        if (is_passing_frame(10.0f) != 0) {
            get_node_position(&shot_origin, 0x43);
            new TObjEneBm9Mericarol_Bomb(this, &shot_origin, &current_target->position,
                mericarol_phase_param_table[get_phase()]->bomb_power, mericarol_phase_param_table[get_phase()]->bomb_speed,
                random_ratio() <= (f32)mericarol_phase_param_table[get_phase()]->final_blast_percent / 100.0f);
            play_sound_effect(remap_sound_for_area(0x3A307), &shot_origin, 0, 0);
        }
        enemy_copy_target_destination();
        update_velocity();
        target_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
        rotation_y = approach_angle_limited(rotation_y, target_angle, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        update_ground_contact();
        update_body_colliders();
        play_move_sound();
        break;
    case 5:
        if (charge_effect != 0) {
            charge_effect->queue_destruction();
            charge_effect = 0;
        }
        break;
    }
}

void TObjEneBm9Mericarol::state_attack(s32 reason) {
    Vec trail0[2];
    Vec trail1[2];
    s32 i;
    Vec *points1;
    Vec *points0;
    TObjChara *p;
    switch (reason) {
    case 4:
        requested_action = 8;
        clear_intangible();
        set_child_flags();
        flags &= ~8;
        flags |= 0x20;
        set_field_378(3);
        state_step = 0;
        state_timer = 0;
        break;
    case 3:
        if (state_step == 2) {
            transition_enemy_state(3);
        }
        break;
    case 1:
        break;
    case 0:
        advance_animation();
        enemy_validate_retained_target(this);
        switch (state_step) {
        case 2:
            break;
        case 0:
            if (is_passing_frame(frame_count - 1.0f - play_speed) != 0) {
                state_step = 1;
                flags &= ~0x20;
                requested_action = 3;
                state_timer = 0;
                play_speed = 0.0f;
            } else {
                if (is_passing_frame(8.0f) != 0) {
                    VecCopy(&attack_body->position, &position);
                    TObjPlayer::init_all_slots();
                    attack_body->check_object_collisions();
                    if (attack_body->bodies->flags & 0x80000) {
                        for (i = 0; i < 0x10; i++) {
                            p = (TObjChara *)TObjPlayer::get_battle_param(i);
                            if (p == NULL) {
                                break;
                            }
                            if (obj_is_hit_receivable(p) != 0 && p->select_melee_contact_body(this, 1.0f) != 0) {
                                p->apply_knockback_from_attacker((u8 *)this, 1.0f);
                                p->receive_physical_attack(this, 1.0f);
                            }
                        }
                    }
                } else if (is_passing_frame(7.0f) != 0) {
                    play_sound_effect(remap_sound_for_area(0x3A40D), &position, 0, 0);
                }
                points0 = mericarol_trail0_points->lookup(frame);
                points1 = mericarol_trail1_points->lookup(frame);
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&position.x);
                rotate_matrix_y(0, rotation_y);
                matrix_mult_vec_array(NULL, (const Vec *)points0, (Vec *)trail0, 2);
                matrix_mult_vec_array(NULL, (const Vec *)points1, (Vec *)trail1, 2);
                pop_matrix();
                if (trails[0] != NULL) {
                    trails[0]->add_segment(&trail0[0], &trail0[1]);
                }
                if (trails[1] != NULL) {
                    trails[1]->add_segment(&trail1[0], &trail1[1]);
                }
            }
            break;
        case 1:
            state_timer++;
            if (state_timer >= mericarol_phase_param_table[get_phase()]->attack_recovery) {
                state_step = 2;
            }
            break;
        }
        enemy_copy_target_destination();
        update_velocity();
        target_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
        rotation_y = approach_angle_limited(rotation_y, target_angle, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        update_ground_contact();
        update_body_colliders();
        play_move_sound();
        break;
    case 5:
        flags &= ~2;
        break;
    }
}

void TObjEneBm9Mericarol::state_rush(s32 reason) {
    s32 hit_wall;
    switch (reason) {
    case 4:
        sync_center_position();
        if (this->enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 100.0f) != NULL) {
            requested_action = 3;
            state_step = 3;
            return;
        }
        requested_action = 2;
        set_field_378(3);
        flags &= ~0x28;
        state_step = 0;
        state_timer = 0;
        rush_delay = 0xA;
        slide_speed = rush_speed;
        rush_distance = 0.0f;
        fill_value_array(attack_history);
        set_active();
        return;
    case 3:
        if (state_step == 3) {
            transition_enemy_state(3);
        }
        return;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            sync_center_position();
            if (this->enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 100.0f) != NULL) {
                requested_action = 3;
                state_step = 3;
                play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
                return;
            }
            rush_delay = rush_delay - 1;
            if (rush_delay <= 0) {
                requested_action = 1;
                state_step = 1;
                flags |= 0x20;
                bodies->flags |= 0x700;
                play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
            }
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
            }
            target_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
            rotation_y = approach_angle_limited(rotation_y, target_angle, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
            check_collisions();
            return;
        case 1:
            play_step_effect();
            hit_wall = 0;
            sync_center_position();
            if (this->enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 30.0f * rush_speed) != NULL) {
                hit_wall = 1;
            }
            move_clamped_on_ground(destination_direction.x, destination_direction.z, rush_speed);
            if (has_move_failures(1) != 0) {
                hit_wall = 1;
            }
            update_enemy_collision_flags();
            if (bodies->flags & 0x200000) {
                hit_wall = 1;
            }
            check_attack_hits();
            rush_distance = rush_distance + rush_speed;
            if (rush_distance >= 200.0f) {
                hit_wall = 1;
            }
            if (hit_wall != 0) {
                state_step = 2;
                state_timer = 0;
                flags &= ~0x20;
                set_field_378(3);
                return;
            }
            break;
        case 2:
            state_timer = state_timer + 1;
            slide_speed *= 0.9f;
            if (state_timer >= 0xA) {
                requested_action = 3;
                state_step = 3;
            }
            check_collisions();
            move_clamped_on_ground(destination_direction.x, destination_direction.z, slide_speed);
            return;
        }
        break;
    case 5:
        flags &= ~0x20;
        bodies->flags &= ~0x700;
        clear_field_388();
        break;
    }
}

s32 TObjEneBm9Mericarol::check_attack_hits() {
    s32 ret;
    s32 i;
    TObjChara *p;
    ret = 0;
    TObjPlayer::init_all_slots();
    check_object_collisions();
    if (bodies->flags & 0x80000) {
        ret = 1;
        for (i = 0; i < 16; i++) {
            p = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (p == NULL) {
                break;
            }
            if (obj_is_hit_receivable(p) != 0 && attack_target_history_add(attack_history, p) != 0) {
                DirectAttackPayload t;
                t.kind = 0;
                t.power = mericarol_phase_param_table[get_phase()]->attack_power;
                DirectAttackPayload payload = t;
                if (p->receive_direct_attack(this, payload, 0, -1, -1) > 0.0f) {
                    p->set_actor_flags(0x600);
                }
            }
        }
    }
    return ret;
}

void TObjEneBm9Mericarol::state_curse(s32 reason) {
    s32 count;
    TObjPlayer *target;
    switch (reason) {
    case 4:
        requested_action = 2;
        clear_intangible();
        set_invulnerable();
        clear_child_flags();
        flags &= ~8;
        flags |= 0x20;
        state_step = 0;
        state_timer = 0;
        return;
    case 3:
        if (state_step >= 0x1E) {
            transition_enemy_state(3);
        }
        return;
    case 0:
        advance_animation();
        count = state_step;
        if (count == 6) {
            target = find_nearby_target();
            if (target != NULL) {
                new TObjEneBm9Mericarol_EffCurse3(this, target);
                current_target = target;
                state_timer = 1;
                play_sound_effect(remap_sound_for_area(0x3A808), &position, 0, 0);
            }
        } else if (count == 0x19 && state_timer != 0 && current_target->is_alive() != 0) {
            ((TObjPlayer *)current_target)->set_tp(0);
        }
        state_step++;
        update_ground_contact();
        update_body_colliders();
        play_move_sound();
        return;
    case 5:
        actorFlags &= ~0x4000000;
        flags &= ~2;
        break;
    }
}

void TObjEneBm9Mericarol::state_damaged(s32 reason) {
    s16 max;
    s16 cur;
    switch (reason) {
    case 4:
        requested_action = 5;
        clear_intangible();
        clear_child_flags();
        flags &= ~0x28;
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        play_sound_effect(remap_sound_for_area(0x3AA0C), &position, 0, 0);
        return;
    case 3:
        if (get_flag_b4() != 0) {
            max = hpmax;
            cur = hp;
            if (cur <= max / 2 && cur >= max / 5 && random_ratio() <= rush_chance) {
                transition_enemy_state(6);
                return;
            }
            if (random_ratio() < 0.05f) {
                transition_enemy_state(7);
                return;
            }
            transition_enemy_state(next_mode);
        }
        return;
    case 0:
        advance_animation();
        update_ground_contact();
        update_body_colliders();
        play_move_sound();
        return;
    case 5:
        actorFlags &= ~0x200;
        flags &= ~2;
        clear_attack_receipts();
        break;
    }
}

void TObjEneBm9Mericarol::state_die(s32 reason) {
    f32 x;
    Vec pos;
    switch (reason) {
    case 4:
        requested_action = 6;
        clear_intangible();
        clear_child_flags();
        flags &= ~0x28;
        refresh_and_send_entity_flags();
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        state_step = 0;
        slide_speed = 0.0f;
        play_sound_effect(remap_sound_for_area(0x3AA0B), &position, 0, 0);
        return;
    case 3:
        if (state_step == 2) {
            transition_enemy_state(0xC);
        }
    case 5:
        return;
    case 0:
        switch (state_step) {
        case 0:
            advance_animation();
            if (get_flag_b4() != 0) {
                state_step = 1;
                x = 10.0f * sin_table_lookup(rotation_y);
                pos.y = 0.0f;
                pos.x = x;
                pos.z = 10.0f * cos_table_lookup(rotation_y);
                vec3_add_to(&pos, &position);
                TObjPlayer::spawn_dead_spot_here(&pos, 0x32);
                spawn_ground_effect(&pos, 0x46);
            }
            update_ground_contact();
            return;
        case 1:
            position.y -= 0.1f;
            slide_speed += 0.1f;
            if (slide_speed > 30.0f) {
                state_step = 2;
            }
            break;
        }
        break;
    }
}

void TObjEneBm9Mericarol::state_destroy(s32 reason) {
    switch (reason) {
    case 0:
        return;
    case 3:
        queue_destruction();
        return;
    }
}

void TObjEneBm9Mericarol::state_laugh(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 7;
        clear_intangible();
        clear_child_flags();
        flags &= ~0x28;
        set_field_378(3);
        state_step = 0;
        play_sound_effect(remap_sound_for_area(0x3AD0F), &position, 0, 0);
        return;
    case 3:
        if (is_passing_frame(frame_count - 1.0f) != 0) {
            transition_enemy_state(3);
        }
        update_ground_contact();
        update_body_colliders();
        return;
    case 0:
        advance_animation();
        state_step = state_step + 1;
        play_move_sound();
        return;
    case 5:
        flags &= ~2;
    case 1:
        return;
    }
}

void TObjEneBm9Mericarol::state_cast_technique(s32 reason) {
    Vec pos;
    switch (reason) {
    case 4:
        requested_action = 2;
        set_field_378(3);
        flags &= ~8;
        flags |= 0x20;
        state_step = 0;
        state_timer = mericarol_phase_param_table[get_phase()]->technique_delay;
        break;
    case 3:
        switch (state_step) {
        case 3:
            transition_enemy_state(3);
            break;
        case 2:
            transition_enemy_state(8);
            break;
        }
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            state_timer--;
            if (state_timer <= 0) {
                f32 lim = mericarol_phase_param_table[get_phase()]->laugh_chance;
                if (random_ratio() <= lim) {
                    state_step = 2;
                } else {
                    requested_action = 0;
                    state_step = 1;
                }
            }
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
            }
            check_collisions();
            if (state_timer % 14 == 0) {
                play_sound_effect(remap_sound_for_area(0x3A809), &position, 0, 0);
            }
            break;
        case 1:
            if (is_passing_frame(10.0f) != 0) {
                VecCopy(&pos, &position);
                pos.y += 20.0f;
                TTecKafun::create((saddr)this, (saddr)&pos, 5, 0x20B, 0x20C,
                    mericarol_phase_param_table[get_phase()]->technique_value, get_clamped_level(),
                    mericarol_phase_param_table[get_phase()]->technique_radius);
                play_sound_effect(remap_sound_for_area(0x3A80A), &position, 0, 0);
            }
            if (get_flag_b4() != 0) {
                state_step = 3;
            }
            break;
        }
        break;
    case 5:
        break;
    }
}

s32 TObjEneBm9Mericarol::get_clamped_level() {
    player_stats *p = stat_block;
    s32 v = 0;
    if (p != 0) {
        v = p->level;
        if (v < 0) {
            return 0;
        }
        if (game_difficulty_selection == 3) {
            if (v > 0x1D) {
                v = 0x1D;
            }
            return v;
        }
        if (v > 0xE) {
            v = 0xE;
        }
    }
    return v;
}

void TObjEneBm9Mericarol::notify_bomb_hit() {
    flags |= 2;
}

void TObjEneBm9Mericarol::run_demo_task() {  }

void TObjEneBm9Mericarol::update_particle_effect(NJS_OBJECT *) {
    switch (mericarol_node_counter) {
    case 0x21:
    case 0x2B:
    case 0x64:
        TParticleCtrl::begin_effect_render();
        break;
    default:
        TParticleCtrl::end_effect_render();
        break;
    }
    mericarol_node_counter += 1;
}

void TObjEneBm9Mericarol::render() {
    s32 vis;
    RenderFadeState *fade;
    s16 saved;
    s32 detail;
    s32 cam;
    GinjaTextureState *s0;
    GinjaTextureState *s1;
    GinjaTextureState *s2;
    s16 *plist;
    if (TObjPlayer::check_demo_mode() != 0) {
        draw_color_variant();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    fade = &camera_fades[cam];
    fade->update();
    vis = fade->updateFromCamera(&body_center.x);
    if (this->mode == 0xC) {
        return;
    }
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (get_current_floor_area() == AREA_TOWER) {
            detail = classify_actor_view_detail(600.0f, 600.0f, 20.0f);
        } else {
            detail = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 20.0f);
        }
    } else if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail == 0) {
        return;
    }
    if (this->mode != 0xB) {
        Vec v = lbl_80472490;
        draw_ground_shadow(&v, 0);
    }
    update_secondary_light();
    switch (get_phase()) {
    case 1:
        s0 = static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture;
        s1 = static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture;
        s2 = static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture;
        static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[3].texture;
        static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[4].texture;
        static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[5].texture;
        break;
    case 2:
        s0 = static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture;
        s1 = static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture;
        s2 = static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture;
        static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[6].texture;
        static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[7].texture;
        static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[8].texture;
        break;
    }
    saved_model_render_flags = model_render_flags;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    set_alpha_ref_override(0);
    TObjEneDD::clear_global_flag_400();
    translate_matrix(0, 0.0f, draw_offset_y, 0.0f);
    mericarol_node_counter = 0;
    TObjPlayer::toggle_particle_effect();
    if (!(flags & 0x10)) {
        plist = ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->sibling->sibling->model)->polygon_list;
        saved = plist[5];
        plist[5] = (u8)plist[5];
        set_chunk_model_node_callback(TObjEneBm9Mericarol::update_particle_effect);
    }
    if (flags & 8) {
        if (appear_fade.has_visible_opacity() != 0) {
            appear_fade.set_flags_and_apply_damage_color();
            if (defer_render() == 0) {
                draw();
            }
            appear_fade.clear_flag_and_notify();
        }
    } else if (vis != 0) {
        fade->set_flags_and_apply_damage_color();
        if (defer_render() == 0) {
            if (detail == 1) {
                draw();
            } else {
                draw_motion_model();
            }
        }
        fade->clear_flag_and_notify();
    } else if (detail == 1) {
        draw();
    } else {
        draw_motion_model();
    }
    if (!(flags & 0x10)) {
        set_chunk_model_node_callback(NULL);
        ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->sibling->model)->polygon_list[5] = saved;
    }
    TParticleCtrl::end_effect_render();
    restore_alpha_ref();
    pop_matrix();
    model_render_flags = saved_model_render_flags;
    update_primary_light();
    if (get_phase() != 0) {
        static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture = s0;
        static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture = s1;
        static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture = s2;
    }
}

void TObjEneBm9Mericarol::draw_color_variant() {
    GinjaTextureState *s0;
    GinjaTextureState *s1;
    GinjaTextureState *s2;
    if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        Vec v = lbl_8047249C;
        draw_ground_shadow(&v, 0);
        switch (variant) {
        case 1:
            s0 = static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture;
            s1 = static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture;
            s2 = static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture;
            static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[3].texture;
            static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[4].texture;
            static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[5].texture;
            break;
        case 2:
            s0 = static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture;
            s1 = static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture;
            s2 = static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture;
            static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[6].texture;
            static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[7].texture;
            static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture = static_cast<NJS_TEXLIST *>(texlist)->textures[8].texture;
            break;
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        set_alpha_ref_override(0);
        draw_chunk_object(model);
        restore_alpha_ref();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        if (variant == 1 || variant == 2) {
            static_cast<NJS_TEXLIST *>(texlist)->textures[0].texture = s0;
            static_cast<NJS_TEXLIST *>(texlist)->textures[1].texture = s1;
            static_cast<NJS_TEXLIST *>(texlist)->textures[2].texture = s2;
        }
    }
}

void TObjEneBm9Mericarol::get_node_position(Vec *out, s32 node) {
    set_motion_packed_rotation();
    push_matrix_from(&identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[node]);
    Vec v = player_sub_802ce68c_zero_vec;
    matrix_mult_vec(0, &v, out);
    pop_matrix();
    clear_motion_packed_rotation();
}

void TObjEneBm9Mericarol::play_step_effect() {
    Vec origin;
    VecCopy(&origin, &position);
    origin.y += 15.0f;

    CsnHit *hit = csnVectorUnder(&origin, ground_candidates.groups, 0x15);
    if (hit != NULL) {
        u32 surface_mask = hit->hit_mask & 4;
        if (surface_mask != 0) {
            play_ground_step_sound(this, &position);
        } else {
            play_persistent_sound(remap_sound_for_area(0x3B211), this, &position, 0, 0);
        }
        if (is_passing_frame(5.0f) != 0 || is_passing_frame(15.0f) != 0 ||
            is_passing_frame(25.0f) != 0) {
            if (surface_mask != 0) {
                TParticleCtrl *spray = (TParticleCtrl *)spawn_particle_effect(&hit->contact[2].point, 0x49);
                if (spray != NULL) {
                    attach_particle_model(spray, TParticleCtrl::get_particle_model(2),
                                          TParticleCtrl::get_instance(), 0, 1, 1.0f);
                    spray->set_scale(5.0f, 1.0f);
                }
                TParticleCtrl *ripple = (TParticleCtrl *)spawn_particle_effect(&hit->contact[2].point, 0xA4);
                if (ripple != NULL) {
                    ripple->set_scale(5.0f, 1.5f);
                }
            } else {
                TParticleCtrl *dust = (TParticleCtrl *)spawn_particle_effect(&position, 0xF3);
                if (dust != NULL) {
                    dust->set_scale(5.0f, 2.0f);
                }
            }
        }
    }
}
