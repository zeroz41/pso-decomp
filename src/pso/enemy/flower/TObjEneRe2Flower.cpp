#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/enemy/epsilon/TObjEneEpsilon_800B92AC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/render/render_util.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/math/AngleUnits.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecMegid.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/flower/TObjEneRe2Flower_Bomb.h"
#include "pso/object/base/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/flower/TObjEneRe2Flower_800C4B78.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/task/TMainTask.h"

// Flower literals the split parts share (TObjEneRe2Flower_800C20D0.cpp, text_800C2CE0.cpp define them).
extern const f32 lbl_805D9FD8;
extern const f32 lbl_805D9FDC;
extern const f32 lbl_805D9FAC;
extern const f32 lbl_805D9FC0;
extern const f32 lbl_805D9FC4;
extern const f32 lbl_805D9FD4;

#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/system/SoundEffect.h"
extern const f32 re2_flower_acquire_range;

extern const f32 re2_flower_lose_target_distance;
extern const f32 re2_flower_attack_distance;
extern const f32 re2_flower_track_timeout;
extern const f32 re2_flower_retarget_margin;



// FlowerRe2Data.cpp
extern const NpcAnimationBinding re2_flower_animation_binding;
extern const char re2_flower_model_name_re2_b_flower_root_nj[];
extern const char re2_flower_motion_name_attack_re2_b_root_njm[];
extern const char re2_flower_motion_name_damege_re2_b_root_njm[];
extern const char re2_flower_motion_name_die_re2_b_root_njm[];
extern const char re2_flower_motion_name_laugh_re2_b_root_njm[];
extern const char re2_flower_motion_name_waitc_re2_b_root_njm[];
extern const char re2_flower_motion_name_waito_re2_b_root_njm[];
extern const char re2_flower_motion_name_wake_re2_b_root_njm[];
extern const char re2_flower_bml_name_bm_ene_re2_flower_bml[];

extern const f32 lbl_805D9FBC; // 5.0
extern const f32 re2_flower_player_range_sq;
extern const f32 re2_flower_body_center_height;
extern const f32 re2_flower_rare_chance; // 0.002
// Stat block ids by variant (0 normal, 1 rare, 2 the tower's): reset_hp's base, attack and
// resistance blocks, and the param block.
extern const s32 re2_flower_base_stat_ids[3];

extern const s32 re2_flower_attack_stat_ids[3];
extern const s32 re2_flower_resist_stat_ids[3];
extern const s32 re2_flower_param_ids[3];
extern const char TObjEneRe2Flower__class_name_string[];
const char *re2_flower_class_name = TObjEneRe2Flower__class_name_string;
// The variant's movement block (TLobby::dispatch_shared_handler_a of re2_flower_param_ids), set by the constructor.
void *re2_flower_movement_params;
BmlResource *re2_flower_bml_resource;
// State of the chunk node callback TObjPlayer::update_effect_sequence: the node counter, the head yaw
// applied at node 1 and the two points transformed at node 14.
s32 re2_flower_node_index;
s32 re2_flower_node_yaw;
f32 *re2_flower_node_points;
struct FlowerSetupData {
    f32 value00;
    u32 unknown04;
    u32 flags;
    u32 unknown0c[4];
};

LAYOUT_ASSERT(FlowerSetupData_size, sizeof(FlowerSetupData) == 0x1C);

FlowerSetupData TObjEneRe2Flower__setup_data = { 225.0f, 0, 0x200, { 0, 0, 0, 0 } };
// The two collision part lists the constructor chooses between: the common
// kinds, then the one is_tower_variant() selects.
CollisionBody re2_flower_collision_bodies[2] = {
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f }
};

CollisionBody re2_flower_tower_collision_bodies[2] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f }
};

__declspec(section ".data") const char *bm_ene_re2_flower_model_names[2] = {
    re2_flower_model_name_re2_b_flower_root_nj, NULL
};
const char *bm_ene_re2_flower_motion_names[8] = {
    re2_flower_motion_name_attack_re2_b_root_njm, re2_flower_motion_name_damege_re2_b_root_njm, re2_flower_motion_name_die_re2_b_root_njm, re2_flower_motion_name_laugh_re2_b_root_njm,
    re2_flower_motion_name_waitc_re2_b_root_njm, re2_flower_motion_name_waito_re2_b_root_njm, re2_flower_motion_name_wake_re2_b_root_njm, NULL
};

BmlResourceDescriptor TObjEneRe2Flower__resource_descriptor = {
    re2_flower_bml_name_bm_ene_re2_flower_bml, bm_ene_re2_flower_model_names,
    bm_ene_re2_flower_motion_names, 1, 7
};

TObjMotionAction TObjEneRe2Flower__animation_descriptors[8] = {
    {3, 0, 0, 0.6f, 0}, {1, 0, 4, 0.3f, 0},
    {1, 0, 5, 0.5f, 0}, {2, 2, 6, 0.6f, 0},
    {3, 0, 1, 0.5f, 0}, {3, 0, 2, 0.5f, 0},
    {1, 0, 3, 0.6f, 0}, {1, 0, 0, 2.0f, 0}
};


// The file is compiled -inline off,deferred, which emits the functions in the
// reverse of the order they are written in.
void load_re2_flower_resources(void) {
    NpcAnimationBinding binding;
    BmlModelEntry *models;

    if (get_current_floor_area() == AREA_TOWER) {
        re2_flower_bml_resource = load_enemy_bml_resource_named(&TObjEneRe2Flower__resource_descriptor, "bm_ene_dkflower.bml");
    } else if (TObjEneDD::check_v2_mode() != 0) {
        re2_flower_bml_resource = load_enemy_bml_resource_named(&TObjEneRe2Flower__resource_descriptor, "bm_ene_re2_flower_a.bml");
    } else {
        re2_flower_bml_resource = load_enemy_bml_resource(&TObjEneRe2Flower__resource_descriptor);
    }
    re2_flower_node_index = 0;
    re2_flower_node_yaw = 0;
    re2_flower_node_points = 0;
    TObjPlayer::create_render_texture();
    TObjPlayer::init_alt_model();
    __memcpy(&binding, &re2_flower_animation_binding, sizeof(binding));
    binding.motions = re2_flower_bml_resource->motions;
    models = re2_flower_bml_resource->models;
    TObjNpcEnemy::register_animated_chunk(0x37, models->model, models->texlist, &binding, lbl_805D9FBC, lbl_805D9FAC);
}

void *TObjEneRe2Flower::create(void *setData) {
    return new TObjEneRe2Flower(tl_04, setData);
}

void TObjEneRe2Flower::destroy_instance() {
    TObjPlayer__sub_800C4D44();
    if (re2_flower_bml_resource != NULL) {
        delete re2_flower_bml_resource;
        re2_flower_bml_resource = NULL;
    }
}

TObjEneRe2Flower::TObjEneRe2Flower(TObject *parent, void *setData) : TObjEneDD_ST(parent) {
    s32 variant;

    m_name = re2_flower_class_name;
    invoke_initialization_hook(setData);
    sub_800C3BA8();
    flags = 0;
    if (get_current_floor_area() == AREA_TOWER) {
        flags |= 0x800;
    } else if (random_ratio() <= re2_flower_rare_chance) {
        flags |= 0x400;
    }
    init_position_vectors();
    model = (void *)re2_flower_bml_resource->models->model;
    texlist = re2_flower_bml_resource->models->texlist;
    if (is_tower_variant()) {
        init_model(re2_flower_tower_collision_bodies, 2);
    } else {
        init_model(re2_flower_collision_bodies, 2);
    }
    set_action_table(TObjEneRe2Flower__animation_descriptors);
    set_motion_list(re2_flower_bml_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_requested_action(requested_action);
    enable_motion_blend();
    if (is_tower_variant()) {
        variant = 2;
    } else if (is_rare_variant()) {
        variant = 1;
    } else {
        variant = 0;
    }
    reset_hp(TLobby::register_boss(re2_flower_base_stat_ids[variant]),
             TLobby::dispatch_shared_handler_b(re2_flower_attack_stat_ids[variant]),
             TLobby::register_object(re2_flower_resist_stat_ids[variant]));
    re2_flower_movement_params = TLobby::dispatch_shared_handler_a(re2_flower_param_ids[variant]);
    if (is_tower_variant()) {
        set_state_8();
    } else {
        set_state_flag_2();
    }
    movementParameters = &TObjEneRe2Flower__setup_data;
    if (is_tower_variant()) {
        initialize_enemy_state(83);
    } else if (is_rare_variant()) {
        initialize_enemy_state(14);
    } else {
        initialize_enemy_state(13);
    }
    wall_reach = lbl_805D9FBC;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    base_yaw = rotation_y;
    draw_offset_y = lbl_805D9FAC;
    pad_3cc = 0;
    retarget_counter = 0;
    hit_cooldown = 0;
    blink_level = 0;
    for (s32 i = 0; i < 2; i++) {
        VecCopy(&node_points[i], &position);
        node_points[i].y += lbl_805D9FD8;
    }
    appear_fade.reset_obstruction_fade();
    state_step = 0;
    state_timer = 0;
    swing_count = 0;
    pad_41c = 0;
    target_angle = 0;
    sink_depth = lbl_805D9FAC;
    charge_effect = NULL;
    sync_center_offset();
    update_body_colliders();
    transform_part_positions();
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneRe2Flower::~TObjEneRe2Flower() {
    if (charge_effect != NULL) {
        charge_effect->queue_destruction();
        charge_effect = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneRe2Flower::run_task() {
    s16 mode;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
    } else {
        mode = this->mode;
        if ((mode == 0) || (mode == 1)) {
            appear_fade.reset_color();
            transition_enemy_state(2);
        }
    }
    this->sync_center_offset();
    submit_default_cursor_candidate();
    this->render_minimap_dot();
}

void TObjEneRe2Flower::dispatch_action(u32 state, s32 reason) {
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
    case 9:
        state_damaged(reason);
        return;
    case 10:
        state_die(reason);
        return;
    case 6:
        state_curse(reason);
        return;
    case 7:
        state_laugh(reason);
        return;
    case 8:
        state_self_destruct(reason);
        return;
    case 11:
        state_destroy(reason);
    default:
        return;
    }
}

void TObjEneRe2Flower::refresh_target() {  }

void TObjEneRe2Flower::run_death_reaction() {
    s16 mode;

    mode = this->mode;
    if ((mode != 0xA) && (mode != 0xB)) {
        transition_enemy_state(0xA);
    }
}

void TObjEneRe2Flower::run_hit_reaction() {
    s16 mode;

    mode = this->mode;
    if (mode != 9) {
        if (mode == 8) {
            start_hit_cooldown();
            clear_attack_receipts();
            return;
        }
        transition_enemy_state(9);
    }
}

void TObjEneRe2Flower::run_miss_reaction() {  }

void TObjEneRe2Flower::sync_center_offset() {
    VecCopy(&this->body_center, &this->position);
    this->body_center.y = this->body_center.y + re2_flower_body_center_height;
    VecCopy(&this->center, &this->body_center);
}

void TObjEneRe2Flower::update_body_colliders() {
    bodies[1].offset.y = body_center.y - position.y;
    set_part_local_pos(node_points, 0);
}

void TObjEneRe2Flower::set_child_flags() {
    if (is_tower_variant() != 0) {
        bodies[0].flags |= 1;
        return;
    }
    bodies[1].flags |= 1;
}

void TObjEneRe2Flower::clear_child_flags() {
    if (is_tower_variant() != 0) {
        bodies[0].flags &= ~1;
        return;
    }
    bodies[1].flags &= ~1;
}

s32 TObjEneRe2Flower::check_hit_flag() {
    if (flags & 2) {
        transition_enemy_state(7);
        return 1;
    }
    return 0;
}

void TObjEneRe2Flower::start_hit_cooldown() {
    if (hit_cooldown == 0) {
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        hit_cooldown = 20;
    }
}

TObjPlayer *TObjEneRe2Flower::find_target_in_range() {
    s32 n;
    TObjPlayer *result;
    TObjPlayer *p;
    s32 i;
    result = NULL;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (((TObjEneDD *)p)->is_valid_target() != 0 && p->obj_isState2_324() == 0) {
            result = p;
            break;
        }
    }
    if (((TObjEneDD *)result)->is_valid_target() != 0 && horizontal_distance_squared(&position, &result->position) < re2_flower_player_range_sq) {
        return result;
    }
    return NULL;
}

void TObjEneRe2Flower::sub_800C3BA8() {  }

s32 TObjEneRe2Flower::is_rare_variant() {
    u32 variant = flags;
    if (variant & 0x800) {
        return 0;
    }
    return (variant & 0x400) != 0;
}

int TObjEneRe2Flower::is_tower_variant() { return (flags >> 11) & 0x1; }

s32 TObjEneRe2Flower::remap_sound_for_variant(s32 sound_id) {
    if (is_tower_variant() != 0) {
        switch (sound_id) {
        case 0x4003A10E:
            return 0x4003A339;
        case 0x4003A50F:
            return 0x4003A53A;
        case 0x4003AD10:
            return 0x4003A33B;
        case 0x4003A311:
            return 0x4003A63C;
        case 0x4003A812:
            return 0x4003A83D;
        case 0x4003AB13:
            return 0x4003A83E;
        case 0x4003A814:
            return 0x4003A13F;
        case 0x4003A315:
            return 0x4003A341;
        case 0x4003B216:
            return 0x40039942;
        }
    }
    return remap_sound_for_area(sound_id);
}

void TObjEneRe2Flower::noop() {}

void TObjEneRe2Flower::state_hidden(s32 reason) {
    switch (reason) {
    case 4:
        this->set_intangible();
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}

void TObjEneRe2Flower::state_fade_in(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 1;
        set_intangible();
        clear_child_flags();
        flags |= 8;
        set_field_378(2);
        enemy_clear_target();
        appear_fade.start_fade_in();
        if (is_tower_variant() != 0) {
            play_area_se_with_particle(&position);
            return;
        }
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
        flags &= ~8;
        break;
    }
}

void TObjEneRe2Flower::state_wait(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        clear_child_flags();
        flags &= ~8;
        set_field_378(2);
        enemy_clear_target();
        return;
    case 3:
        if (check_hit_flag() == 0 && update_linked_position(re2_flower_acquire_range) != 0) {
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

void TObjEneRe2Flower::state_chase_target(s32 reason) {
    f32 d;
    s32 t;
    u16 idx;

    switch (reason) {
    case 5:
        break;
    case 4:
        if (mode == 2) {
            requested_action = 3;
        } else {
            requested_action = 2;
        }
        clear_intangible();
        set_child_flags();
        flags &= ~8;
        set_field_378(3);
        state_timer = 0;
        target_angle = 0;
        if (is_tower_variant() != 0) {
            play_sound_effect(0x4003A840, &position, 0, 0);
        }
        break;
    case 3:
        if (check_hit_flag() == 0) {
            d = destination_distance;
            if (d > re2_flower_lose_target_distance || current_target == NULL) {
                transition_enemy_state(2);
            } else if (d < re2_flower_attack_distance) {
                t = angle_difference_abs(rotation_y, target_angle);
                if (t < attack_params->get_attack_angle()) {
                    transition_enemy_state(5);
                }
            } else if ((f32)state_timer > re2_flower_track_timeout) {
                transition_enemy_state(4);
            }
        }
        break;
    case 0:
        advance_animation();
        idx = 0xFFFF;
        if (tick_period_counter((saddr)this, &retarget_counter, 0x14) != 0) {
            if (destination_distance > re2_flower_retarget_margin) {
                if (is_confused() != 0) {
                    idx = enemy_nearest_visible_enemy(this, destination_distance - re2_flower_retarget_margin);
                }
                if (idx == 0xFFFF) {
                    idx = enemy_find_nearest_player_in_range(this, destination_distance - re2_flower_retarget_margin);
                }
                if (idx != 0xFFFF) {
                    enemy_set_target_id(this, idx);
                }
            }
        } else if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            break;
        }
        enemy_copy_target_destination();
        update_velocity();
        state_timer++;
        target_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
        rotation_y = approach_angle_limited(rotation_y, target_angle, ((EnemyMoveParams *)movementParameters)->turn_speed);
        rotation_y = (s16)rotation_y;
        update_ground_contact();
        update_body_colliders();
        noop();
        break;
    }
}

void TObjEneRe2Flower::state_shoot(s32 reason) {
    Vec pos;
    switch (reason) {
    case 4:
        requested_action = 0;
        clear_intangible();
        set_child_flags();
        flags &= ~8;
        set_field_378(3);
        charge_effect = NULL;
        break;
    case 3:
        if (check_hit_flag() == 0 && get_flag_b4() != 0) {
            transition_enemy_state(3);
            break;
        }
    case 1:
        break;
    case 0:
        advance_animation();
        if (charge_effect == NULL) {
            charge_effect = create_particle_emitter(&node_points[1], 0xD1);
            if (charge_effect != NULL) {
                charge_effect->enable();
            }
        }
        if (charge_effect != NULL) {
            if (frame < lbl_805D9FD8) {
                charge_effect->set_position(&node_points[1]);
            } else {
                charge_effect->enable();
            }
        }
        if (is_passing_frame(lbl_805D9FDC) != 0) {
            VecCopy(&pos, &node_points[0]);
            pos.y = lbl_805D9FDC + position.y;
            if (is_tower_variant() != 0 || TObjEneDD::check_v2_mode() != 0) {
                TTecMegid::create_ex((saddr)this, (saddr)&pos, rotation_y, TObjEneDD::clamp_frame_index(*(s32 *)((s8 *)re2_flower_movement_params + 0x18)));
            } else {
                TObjEneRe2Flower_Bomb *bomb = static_cast<TObjEneRe2Flower_Bomb *>(
                    TObject::operator new(sizeof(TObjEneRe2Flower_Bomb)));
                if (bomb != NULL) {
                    TObjPlayer__sub_800C4A5C(bomb, this, &pos, rotation_y);
                }
            }
            play_sound_effect(remap_sound_for_variant(0x4003A10E), &node_points[0], 0, 0);
        }
        update_ground_contact();
        update_body_colliders();
        noop();
        break;
    case 5:
        if (charge_effect != NULL) {
            charge_effect->queue_destruction();
            charge_effect = NULL;
        }
        break;
    }
}

void TObjEneRe2Flower::state_attack(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 7;
        clear_intangible();
        set_child_flags();
        flags &= ~8;
        set_field_378(3);
        state_step = 0;
        state_timer = 0;
        swing_count = 0;
        return;
    case 3:
        if (state_step >= 0x14) {
            transition_enemy_state(3);
        }
    case 1:
        return;
    case 0:
        advance_animation();
        enemy_validate_retained_target(this);
        switch (state_timer) {
        case 0:
            if (is_passing_frame((frame_count - lbl_805D9FC0) - play_speed) != 0) {
                swing_count++;
                if ((f32)swing_count >= lbl_805D9FD4) {
                    state_timer = 1;
                    play_speed = lbl_805D9FAC;
                }
            } else if (is_passing_frame(lbl_805D9FC4) != 0) {
                if (enemy_check_target_valid() != 0) {
                    if (current_target->select_melee_contact_body(this, lbl_805D9FC0) != 0) {
                        current_target->receive_physical_attack(this, lbl_805D9FC0);
                        current_target->apply_knockback_from_attacker((u8 *)this, lbl_805D9FD4);
                    }
                }
                play_sound_effect(remap_sound_for_variant(0x4003A814), &position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
            break;
        case 1:
            state_step++;
            break;
        }
        update_ground_contact();
        update_body_colliders();
        noop();
        return;
    case 5:
        flags &= ~2;
        break;
    }
}
