#include "pso/enemy/EnemyMovement.h"
#include "pso/system/BmlAccessors.h"
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"

#include "pso/effect/enemy/TEneEffHamon.h"

#include "pso/render/ChunkMaterialState.h"

#include "types.h"

#include "pso/enemy/TUnk_804909C4.h"

#include "pso/render/NinjaUtil.h"

#include "pso/object/base/TObjChara.h"

#include "pso/enemy/darkgunner/TObjEneDarkGunCenter.h"

#include "pso/player/TObjPlayer.h"

#include "pso/enemy/TObjEnemyCustom.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/darkgunner/TObjEneDarkGunner.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/system/SoundEffect.h"

#include "pso/math/MatrixTransforms.h"

#include "pso/math/AngleLookup.h"

#include <stdlib.h>


#include "pso/render/render_util.h"

#include "pso/unk/text_803E2D70.h"

#include "pso/unk/text_803D96A8.h"


#include "pso/map/CsnQuery.h"

#include "pso/system/task/TObject.h"


#include "pso/system/vector.h"

#include "pso/render/TUnk_80490470.h"

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/enemy/lappy/TObjEneLappy.h"

#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/unk/TLobby.h"

#include "pso/ui/hud/TNowLoading.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"

#include "pso/system/TLanguage_801E4874.h"

#include "pso/enemy/saver/SaverLifecycle.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/render/MaterialColorFade.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/enemy/TeneFakeTecThunderEff.h"
#include "pso/object/TObjControl.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/system/MatrixOps.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

// The four ripple offsets spawn_hamon_effects puts around the gunner.
struct HamonOffset {
    f32 x, z;
};

struct HamonOffsets {
    HamonOffset v[4];
};

extern "C" {

struct Raw_800A10A0 { u8 b[12]; };
















}


extern "C" {
player_stats *TObjEneDarkGunner__base_params_by_variant[1];

AttackParams *TObjEneDarkGunner__attack_params_by_variant[1];

ActorParamBlock *TObjEneDarkGunner__resistance_params_by_variant[1];




const char *bm_ene_darkgunner_model_names[5] = {
    "re5_b_cly_cy_line.nj", "re5_b_gunner_body.nj", "re5_b_rcly_cy_line.nj", "shockwave.nj",
    NULL,
};

const char *bm_ene_darkgunner_motion_names[15] = {
    "attack_re5_b_body.njm", "await_re5_b_body.njm", "damage2_re5_b_body.njm", "damage_re5_b_body.njm",
    "die_re5_b_body.njm", "drop_re5_b_body.njm", "duckdame_re5_b_body.njm", "duckdie_re5_b_body.njm",
    "duckroop_re5_b_body.njm", "duckwake_re5_b_body.njm", "duck_re5_b_body.njm", "move_re5_b_body.njm",
    "pullback_re5_b_body.njm", "wait_re5_b_body.njm", NULL,
};

BmlResourceDescriptor bm_ene_darkgunner_resource_descriptor = {
    "bm_ene_darkgunner.bml",
    bm_ene_darkgunner_model_names, bm_ene_darkgunner_motion_names, 4, 14,
};

// By action: 0 wait, 1 move, 2 drop, 3 attack, 4 await, 5 damage, 6 damage2, 7 die,
// 8 duck, 9 duckdame, 10 duckdie, 11 duckroop, 12 duckwake, 13 pullback.
TObjMotionAction dark_gunner_action_table[14] = {
    {1, 0, 13, 1.0f, 0},
    {2, 0, 11, 0.8f, 1},
    {2, 0, 5, 0.6f, 1},
    {2, 4, 0, 0.8f, 4},
    {1, 4, 1, 1.0f, 4},
    {2, 0, 3, 0.7f, 8},
    {2, 0, 2, 0.7f, 8},
    {3, 7, 4, 0.7f, 0x10},
    {2, 11, 10, 0.7f, 0},
    {2, 12, 6, 0.6f, 8},
    {3, 10, 7, 0.5f, 0x10},
    {1, 11, 8, 0.7f, 0},
    {2, 0, 9, 0.6f, 0},
    {2, 0, 12, 0.7f, 4},
};

const char *TObjEneDarkGunner__class_name = "TObjEneDarkGunner";

const NpcAnimationBinding dark_gunner_attack_binding_desc = { NULL, dark_gunner_action_table, 0, 1, 14 };

const NJS_ARGB dark_gunner_pulse_color = {0.0f, 0.0f, 0.0f, 0.0f};

const Vec dark_gunner_shadow_scale = {1.5f, 1.5f, 1.5f};

const HamonOffsets hamon_effect_offset_table = {{{-7.0f, -7.0f}, {-7.0f, 7.0f}, {7.0f, -7.0f}, {7.0f, 7.0f}}};

const Vec dark_gunner_shadow_origin = {0.0f, 0.0f, 0.0f};

void *dark_gunner_movement_params[14] = {
    (void *)0x42a00000, (void *)0x3e8e38e3, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0, (void *)0x42a00000,
    (void *)0x3e8e38e3, (void *)0x400, (void *)0x1e0000, (void *)0x0,
    (void *)0x1, (void *)0x0,
};

CollisionBody dark_gunner_collision_bodies[1] = {
    {{0.0f, 3.5f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

__declspec(section ".data") NJS_ARGB dark_gunner_constant_material = {0.0f, 0.0f, 0.0f, 0.0f};

Vec dark_gunner_child_local_offsets[4] = {
    {0.0f, 10.0f, 2.0f}, {0.0f, 10.0f, -2.0f}, {2.0f, 10.0f, 0.0f}, {-2.0f, 10.0f, 0.0f},
};

TObjEneDarkGunnerBehaviorParams *TObjEneDarkGunner__behavior_params;

extern NJS_TEXLIST *TObjEneDarkGunner__effect_resource;

extern NJS_TEXLIST *TObjEneDarkGunner__cly_line_texlist;

extern NJS_TEXLIST *TObjEneDarkGunner__rcly_line_texlist;

extern NJS_OBJECT *TObjEneDarkGunner__shadow_chunk_object;

}

extern "C" {



extern s32 TObjEneDarkGunner__polygon_update_tick;

extern s16 *TObjEneDarkGunner__body_child_polygons;

extern s16 *TObjEneDarkGunner__cly_line_polygons;

}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern "C" {
inline f32 fmax_800A2390(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}

inline f32 fmin_800A28A4(f32 a, f32 b) {
    if (a < b) {
        return a;
    }
    return b;
}

inline f32 fmax_800A28A4(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}
}

#pragma pop
f32 dark_gunner_shot_speed;

extern "C" void load_darkgunner_effect_resources();

BmlResource *TObjEneDarkGunner::bml_resource; // bm_ene_darkgunner.bml

extern "C" {

NJS_TEXLIST *TObjEneDarkGunner__effect_resource;

NJS_TEXLIST *TObjEneDarkGunner__cly_line_texlist;

NJS_TEXLIST *TObjEneDarkGunner__rcly_line_texlist;

NJS_OBJECT *TObjEneDarkGunner__shadow_chunk_object;

s32 TObjEneDarkGunner__polygon_update_tick;

s16 *TObjEneDarkGunner__body_child_polygons;

s16 *TObjEneDarkGunner__cly_line_polygons;

void TeneFakeTecThunderEff::set_cancel_flag() { active = 1; }

void TeneFakeTecThunderEff::clear_counter() { active = 0; }

void TObjEneDarkGunner::set_fields_24_34_from_global(void *index) {
    this->model = get_bml_model(TObjEneDarkGunner::bml_resource, (s32)(saddr)index);
    this->texlist = get_bml_texlist(TObjEneDarkGunner::bml_resource, (s32)(saddr)index);
}

int TObjEneDarkGunner::is_death_gunner() { return (behavior_flags >> 26) & 0x1; }

s32 TObjEneDarkGunner::get_int_parameter(s32 index) {
    return TObjEneDarkGunner__behavior_params->int_params[index];
}

f32 TObjEneDarkGunner::get_float_parameter(s32 index) {
    return TObjEneDarkGunner__behavior_params->float_params[index];
}

void TObjEneDarkGunner::run_move_action() {  }

void TObjEneDarkGunner::run_idle_action() {  }

void TObjEneDarkGunner::refresh_target() {  }
}

extern "C" {
TObjEneDarkGunner::TObjEneDarkGunner(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    s32 i;

    m_name = TObjEneDarkGunner__class_name;
    apply_set_data(set_data);
    initialize_enemy_photon_effect(this);
    variant = 0;
    set_param(0x22);
    add_flags_2e4(8);
    state36C = *(s16 *)((u8 *)set_data + 0x3E);
    resetTimer = 0xF;
    timer = resetTimer;
    VecCopy(&prev_position, &position);
    VecCopy(&home_position, &position);
    VecCopy(&move_origin, &position);
    VecCopy(&move_destination, &position);
    set_fields_24_34_from_global((void *)1);
    motion_list = TObjEneDarkGunner::bml_resource->motions;
    action_table = dark_gunner_action_table;
    set_action_table(action_table);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, dark_gunner_collision_bodies, 1);
    movementParameters = dark_gunner_movement_params;
    bind_enemy_combat_stats(TObjEneDarkGunner__base_params_by_variant[variant], TObjEneDarkGunner__attack_params_by_variant[variant], TObjEneDarkGunner__resistance_params_by_variant[variant]);
    load_params();
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    behavior_flags = 0x550000;
    set_actor_flags(0x04040000);
    rotation_z = 0x8000;
    render_y_offset = 0.0f;
    hover_speed = 0.0f;
    hover_height = 0.0f;
    trail_emitter = NULL;
    glow_emitter = NULL;
    bodies->flags |= 4;
    bodies->flags &= ~2;
    pad_39e = 0;
    for (i = 0; i < 4; i++) {
        children[i] = NULL;
    }
    {
        NpcAnimationBinding atk = dark_gunner_attack_binding_desc;
        atk.motions = TObjEneDarkGunner::bml_resource->motions;
        TObjNpcEnemy::register_animated_chunk(0x19, TObjEneDarkGunner::bml_resource->models[1].model, TObjEneDarkGunner::bml_resource->models[1].texlist, &atk, 10.0f, 0.0f);
    }
}
}

extern "C" {
TObjEneDarkGunner::~TObjEneDarkGunner() {
    s32 i;
    free_collision_body_parts(this);
    for (i = 0; i < 4; i++) {
        if (children[i] != NULL) {
            children[i]->queue_destruction();
        }
    }
    if (trail_emitter != NULL) {
        ((TObject *)trail_emitter)->queue_destruction();
    }
    if (glow_emitter != NULL) {
        ((TObject *)glow_emitter)->queue_destruction();
    }
}

void load_darkgunner_effect_resources() {
    s32 i;
    BmlResource *res = new BmlResource(1, &bm_ene_darkgunner_resource_descriptor, 0, 0, NULL);
    TObjEneDarkGunner::bml_resource = res;
    TObjEneDarkGunner__shadow_chunk_object = get_bml_model(TObjEneDarkGunner::bml_resource, 0);
    TObjEneDarkGunner__cly_line_texlist = get_bml_texlist(TObjEneDarkGunner::bml_resource, 0);
    TObjEneDarkGunner__rcly_line_texlist = get_bml_texlist(TObjEneDarkGunner::bml_resource, 2);
    TObjEneDarkGunner__body_child_polygons = ((NJS_CNK_MODEL *)get_bml_model(TObjEneDarkGunner::bml_resource, 1)->child->model)->polygon_list;
    TObjEneDarkGunner__cly_line_polygons = ((NJS_CNK_MODEL *)get_bml_model(TObjEneDarkGunner::bml_resource, 0)->model)->polygon_list;
    init_fake_tec_texlist();
    TEneEffHamon::init_fish_effects();
    TObjEneDarkGunner__effect_resource = load_gvm_texture_file("re5_b_gunner_body_pika.gvm");
    for (i = 0; i < 1; i++) {
        TObjEneDarkGunner__base_params_by_variant[i] = TLobby::register_boss(30 + i);
        TObjEneDarkGunner__attack_params_by_variant[i] = TLobby::dispatch_shared_handler_b(30 + i);
        TObjEneDarkGunner__resistance_params_by_variant[i] = TLobby::register_object(30 + i);
    }
    TObjEneDarkGunner__behavior_params = (TObjEneDarkGunnerBehaviorParams *)TLobby::dispatch_shared_handler_a(30);
}

void TObjEneDarkGunner::cleanup_effects() {
    if (TObjEneDarkGunner::bml_resource != NULL) {
        delete TObjEneDarkGunner::bml_resource;
        TObjEneDarkGunner::bml_resource = NULL;
    }
    if (TObjEneDarkGunner__effect_resource != NULL) {
        TObjPlayer::free_if_valid((s32)TObjEneDarkGunner__effect_resource);
        TObjEneDarkGunner__effect_resource = NULL;
    }
    TObjPlayer::reset_effect_count();
    TEneEffHamon::free_fish_effects();
}

void *TObjEneDarkGunner::create(void *set_data) {
    return new TObjEneDarkGunner(tl_04, set_data);
}
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern "C" {
void TObjEneDarkGunner::run_task() {
    if (TObjEneDarkGunner__polygon_update_tick != actor_frame_tick) {
        TObjEneDarkGunner__polygon_update_tick = actor_frame_tick;
        TObjPlayer__sub_8023DEE0(TObjEneDarkGunner__body_child_polygons, 8, 0, 1);
        TObjPlayer__sub_8023DEE0(TObjEneDarkGunner__cly_line_polygons, 8, 0, 0);
    }
    if (TObjPlayer::check_demo_mode() == 1) {
        load_params();
        run_demo_task();
        return;
    }
    update_flag30_timer();
    if (has_flag_0x800() != 0) {
        run_death_reaction();
    } else if (test_flag30_512() != 0) {
        run_hit_reaction();
    } else if (test_actor_flags(0x100) != 0) {
        run_miss_reaction();
    }
    update_attack_stat_status();
    update_defense_stat_status();
    if ((behavior_flags & 0x400000) && test_actor_flags(0x22) == 0) {
        s32 phase = material_phase;
        material_phase = phase + 0x800;
        bodies->unk_28 = get_int_parameter(2);
    } else {
        bodies->unk_28 = 0.0f;
    }
    if ((behavior_flags & 0x800000) && test_actor_flags(0x22) == 0) {
        if (glow_emitter == NULL) {
            glow_emitter = create_particle_emitter(&body_center, 0xDB);
        } else {
            glow_emitter->set_position(&body_center);
        }
    } else if (glow_emitter != NULL) {
        ((TObject *)glow_emitter)->queue_destruction();
        glow_emitter = NULL;
    }
    if ((behavior_flags & 0x200000) && test_actor_flags(0x22) == 0) {
        if (trail_emitter == NULL) {
            if (is_death_gunner() != 0) {
                trail_emitter = create_particle_emitter(&shadow_pos, 0xD9);
            } else {
                trail_emitter = create_particle_emitter(&shadow_pos, 0xD4);
            }
        } else {
            trail_emitter->set_position(&shadow_pos);
        }
    } else if (trail_emitter != NULL) {
        ((TObject *)trail_emitter)->queue_destruction();
        trail_emitter = NULL;
    }
    if (update_action_hold_status() != 0 || update_shock_clock() != 0 || update_movement_status() != 0) {
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
        return;
    }
    if (mode != next_action) {
        if ((s32)state != -1) {
            state = -1;
            update_state();
        }
        mode = next_action;
        state = 0;
    }
    update_state();
    update_prev_position();
    body_center.y += render_y_offset;
    VecCopy(&center, &shadow_pos);
    if (behavior_flags & 0x80000) {
        render_y_offset = fmin_800A28A4(0.5f + render_y_offset, 10.0f);
    } else {
        render_y_offset = fmax_800A28A4(render_y_offset - 0.5f, 0.0f);
    }
    update_hover();
    bodies->offset.y = 4.0f + render_y_offset;
    if ((actor_frame_tick & 3) == 0 && (behavior_flags & 0x400000) && test_actor_flags(0x22) == 0 &&
        classify_actor_view_detail(150.0f, 400.0f, 15.0f) != 0) {
        Vec p = position;
        p.y += render_y_offset;
        spawn_particle_effect(&p, 0xD6);
    }
}

void TObjEneDarkGunner::return_home_or_wait() {
    s32 next_mode;
    if (xz_distance_squared(&position, &home_position) > 100.0f) {
        next_mode = 8;
    } else {
        next_mode = 0;
    }
    update_if_active(next_mode);
}
}

#pragma pop
extern "C" {
void TObjEneDarkGunner::update_wait() {
    switch (state) {
    case 0:
        if (behavior_flags & 0x10000) {
            actorFlags |= 0x04040000;
            rotation_z = 0x8000;
            state = 1;
        } else {
            requested_action = 0;
            state = 2;
        }
        behavior_flags |= 0x400000;
        advance_animation();
        break;
    case 1:
        break;
    case -1:
        break;
    }
}

void TObjEneDarkGunner::start_move() {
    if (!(actorFlags & 0x800)) {
        update_if_active(1);
        behavior_flags |= 0x20000;
    }
}
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern "C" {
void TObjEneDarkGunner::update_move() {
    clear_actor_flags(0x40000);
    switch ((s32)state) {
    case 0:
        behavior_flags &= ~0x00200000;
        behavior_flags |= 0x400000;
        if (behavior_flags & 0x10000) {
            behavior_flags &= ~0x30000;
            velocity.z = 0.0f;
            velocity.y = 0.0f;
            velocity.x = 0.0f;
            state = 1;
        } else {
            actorFlags &= 0xFBFBFFFF;
            state = 3;
        }
        break;
    case 1:
        apply_actor_gravity(this, NULL, 0.0f);
        rotation_z -= 0x1000;
        if (rotation_z < 0) {
            rotation_z = 0;
        }
        if (actorFlags & 0x800000) {
            rotation_z = 0;
            requested_action = 2;
            state = 2;
            actorFlags &= 0xFBFBFFFF;
            bodies->flags &= ~4;
            bodies->flags |= 2;
            spawn_hamon_effects(0xF, 0, 2.2f);
            spawn_hamon_effects(0xF, 3, 2.0f);
            spawn_hamon_effects(0xF, 6, 1.8f);
        }
        break;
    case 2:
        apply_actor_gravity(this, NULL, 0.0f);
        if (requested_action == 0) {
            state = 3;
        }
        break;
    case 3:
        rotation_z = 0;
        bodies->flags &= ~4;
        bodies->flags |= 2;
        advance_animation();
        if (behavior_flags & 0x20000) {
            behavior_flags &= ~0x20000;
            behavior_flags |= 0x80000;
            if (behavior_flags & 0x40000) {
                behavior_flags &= ~0x40000;
                state = 4;
            } else {
                spin_count = 0;
                state = 6;
            }
        } else {
            behavior_flags &= ~0x80000;
        }
        break;
    case 6:
        rotation_y += 0x555;
        spin_count++;
        if (spin_count >= 4) {
            state = 4;
        }
        break;
    case 4:
        move_heading = rotation_y;
        move_speed = get_float_parameter(0);
        move_distance = 0.0f;
        turn_delay = 0;
        pad_39e = 0;
        requested_action = 1;
        state = 5;
        rotation_z = 0;
        bodies->flags &= ~4;
        bodies->flags |= 2;
    case 5:
        advance_animation();
        enemy_set_heading_velocity(move_speed, this, move_heading);
        step_along_ground();
        move_distance += move_speed;
        move_speed = fmax_800A2390(-0.2f + move_speed, 0.5f);
        if (move_distance >= get_float_parameter(1)) {
            behavior_flags &= ~0x80000;
            state = 3;
        }
        play_persistent_sound(0x4003AD28, this, &position, 0, 0);
        if (turn_delay > 0) {
            turn_delay--;
            if (bodies->flags & 0x300000) {
                move_heading += 0x4000;
                turn_delay = 5;
            }
        }
        if (!(actor_frame_tick & 2)) {
            spawn_hamon_effects(0xF, 0, 1.5f);
        }
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case -1:
        break;
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}
}

#pragma pop
#pragma push
#pragma opt_loop_invariants off
extern "C" {
void TObjEneDarkGunner::update_attack() {
    switch ((s32)state) {
    case 0:
        actorFlags |= 0x200000;
        behavior_flags &= 0xFFB7FFFF;
        attack_count = 0;
        requested_action = 3;
        play_sound_effect(0x4003B52F, &position, 0, 0);
        play_sound_effect(0x4003AD29, &position, 0, 0);
        state = 1;
        break;
    case 1:
        if (frame >= 5.0f) {
            hover_speed = 1.6088889f;
        }
        if (requested_action != 4) break;
        behavior_flags |= 0x200000;
        attack_timer = get_int_parameter(0);
        state = 2;
        play_sound_effect(0x4003B52A, &position, 0, 0);
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                children[i] = new TeneFakeTecThunderEff(this, &shadow_pos, &child_offsets[i], 2);
            }
        }
        break;
    case 2:
        hover_speed = 1.6088889f;
        if (--attack_timer > 0) break;
        attack_timer = 4;
        behavior_flags &= ~0x200000;
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                TeneFakeTecThunderEff *q = children[i];
                if (q != NULL) {
                    q->queue_destruction();
                    children[i] = NULL;
                }
            }
        }
        state = 3;
        if (is_death_gunner() != 0) {
            spawn_particle_effect(&shadow_pos, 0xD8);
        } else {
            spawn_particle_effect(&shadow_pos, 0xD2);
        }
        break;
    case 3:
        hover_speed = 1.6088889f;
        if (--attack_timer > 0) break;
        attack_count++;
        attack_timer = 15;
        state = 4;
        find_target_in_range(200.0f);
        if (targetId == 0xFFFF) break;
        new TUnk_804909C4((u8 *)this, (saddr)&shadow_pos, (saddr)&((TObjChara *)target)->body_center);
        play_sound_effect(0x40039E2B, &position, 0, 0);
        break;
    case 4:
        hover_speed = 1.6088889f;
        if (--attack_timer > 0) break;
        state = 5;
        requested_action = 13;
        hover_speed = 0.0f;
        break;
    case 5:
        if (requested_action != 0) break;
        if (attack_count < 2) {
            state = 1;
            requested_action = 3;
            break;
        }
        update_if_active(1);
        break;
    case -1:
        behavior_flags &= ~0x200000;
        actorFlags &= ~0x200000;
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                TeneFakeTecThunderEff *q = children[i];
                if (q != NULL) {
                    q->queue_destruction();
                    children[i] = NULL;
                }
            }
        }
        break;
    }
    clear_actor_flags(0x40000);
    advance_animation();
    apply_actor_gravity(this, NULL, 0.0f);
    update_collisions();
    minimap_render_dot(&position, -23988, 1, 0);
    submit_cursor_candidate(this, -1);
}
}

#pragma pop
extern "C" {
void TObjEneDarkGunner::run_hit_reaction() {
    s16 cur_mode;
    TObjEneDarkGunCenter *center;
    cur_mode = this->mode;
    if (cur_mode != 4) {
        if ((cur_mode == 2) && (is_death_gunner() != 0) &&
            (center = (TObjEneDarkGunCenter *)get_enemy_entity(center_id)) != NULL) {
            center->hide_gunners();
            return;
        }
        this->set_state(4);
    }
}

void TObjEneDarkGunner::update_damage() {
    f32 limit;
    f32 speed;
    switch ((s32)state) {
    case 0:
        actorFlags = actorFlags & 0xFFDFFFFF;
        if (behavior_flags & 0x800000) {
            requested_action = 9;
        } else {
            requested_action = 5;
        }
        speed = vector_length(&velocity);
        limit = get_float_parameter(2);
        if (speed > limit) {
            velocity.x = (velocity.x * limit) / speed;
            velocity.z = (velocity.z * limit) / speed;
        }
        if (behavior_flags & 0x400000) {
            spawn_particle_effect(&body_center, 0xD7);
        }
        pad_39e = 0;
        state = 1;
    case 1:
        velocity.x *= 0.95;
        velocity.z *= 0.95;
        advance_animation();
        {
        Vec v = body_center;
        v.x = v.x + velocity.x;
        v.z = v.z + velocity.z;
        if (check_path_obstructed(this, &v) == 0) {
            move_with_wall_slide(this);
        } else {
            velocity.z = 0.0f;
            velocity.x = 0.0f;
        }
        }
        apply_actor_gravity(this, NULL, 0.0f);
        update_collisions();
        if (action_flags != 8U) {
            clear_actor_flags(0x40300);
            behavior_flags = behavior_flags & 0xFF7FFFFE;
            referenceHp = hp;
            start_move();
        }
        break;
    case -1:
        behavior_flags = behavior_flags & 0xFFFFFFFE;
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

void TObjEneDarkGunner::update_dying() {
    behavior_flags &= 0xFF07FFFF;
    switch ((s32)state) {
    case 0:
        requested_action = 7;
        refresh_lobby_state();
        send_entity_set_flags();
        render_control.start_fade_out();
        fn_800D911C(&body_center);
        behavior_flags |= 4;
        play_sound_effect(0x4003AD37, &position, 0, 0);
        state = 1;
        break;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        if (render_control.decay_value_toward_floor() == 1) {
            TObjPlayer::apply_effect_variant_a(&position, 0);
            queue_destruction();
        }
        break;
    case -1:
        break;
    }
}

void TObjEneDarkGunner::render() {
    s32 view;
    s32 drawn;
    s32 visible;
    BOOL cancel;
    s32 i;

    if (test_actor_flags(0x02000000) == 0) {
        view = classify_actor_view_detail(150.0f, 400.0f, 15.0f);
        if (view != 0) {
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            drawn = 1;
            push_matrix();
            saved_model_render_flags = model_render_flags;
            model_render_flags &= ~0x10;
            translate_matrix(0, position.x, position.y + render_y_offset, position.z);
            rotate_matrix_z(0, rotation_z);
            rotate_matrix_y(0, rotation_y);
            if (behavior_flags & 0x400000) {
                f32 s;
                model_render_flags |= 0x820;
                set_chunk_material_override_pair(0xFF00, 0x800);
                s = -0.25f * fabs_float(sin_table_lookup(material_phase));
                NJS_ARGB color = dark_gunner_pulse_color;
                color.r = s;
                color.g = s;
                color.b = s;
                set_constant_material(&color);
                TObjFish::set_global_param(TObjEneDarkGunner__effect_resource);
            } else {
                TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
            }
            if (behavior_flags & 4) {
                if (render_control.has_visible_opacity() != 0) {
                    render_control.set_flags_and_apply_damage_color();
                    visible = 1;
                    if (defer_render() != 0) {
                        visible = 0;
                    }
                    if (visible != 0) {
                        if (view == 1) {
                            draw();
                        } else {
                            draw_motion_model();
                        }
                    }
                    render_control.clear_flag_and_notify();
                } else {
                    drawn = 0;
                }
            } else if (view == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            if (behavior_flags & 0x400000) {
                set_constant_material(&dark_gunner_constant_material);
                set_chunk_material_override_pair(0xFF00, 0);
            }
            model_render_flags = saved_model_render_flags;
            pop_matrix();
            render_shadow();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            cancel = view == 1 && (behavior_flags & 0x200000) && test_actor_flags(0x22) == 0;
            for (i = 0; i < 4; i++) {
                if (children[i] != NULL) {
                    if (cancel) {
                        children[i]->set_cancel_flag();
                    } else {
                        children[i]->clear_counter();
                    }
                }
            }
            if (test_actor_flags(0x800) == 0 && drawn != 0 && test_actor_flags(0x800000) != 0) {
                Vec offset = dark_gunner_shadow_scale;
                draw_ground_shadow(&offset, 0);
            }
        }
    }
}

void TObjEneDarkGunner::run_demo_task() {  }

void TObjEneDarkGunner::render_shadow() {
    if (test_actor_flags(0x800) == 0) {
        if (is_death_gunner() == 0) {
            TObjFish::set_global_param(TObjEneDarkGunner__cly_line_texlist);
        } else {
            TObjFish::set_global_param(TObjEneDarkGunner__rcly_line_texlist);
        }
        push_matrix();
        post_translate_matrix(&shadow_pos.x);
        draw_chunk_object(TObjEneDarkGunner__shadow_chunk_object);
        pop_matrix();
    }
}
}

#pragma push
#pragma opt_loop_invariants off
extern "C" {
void TObjEneDarkGunner::spawn_hamon_effects(s32 type, s32 variant, f32 scale) {
    Vec p;
    HamonOffsets ofs = hamon_effect_offset_table;
    s32 i;
    p.y = 0.01f + (position.y + render_y_offset);
    for (i = 0; i < 4; i++) {
        p.x = position.x + ofs.v[i].x;
        p.z = position.z + ofs.v[i].z;
        new TEneEffHamon(&p, type, variant, scale);
    }
}
}

#pragma pop
extern "C" {
int TObjEneDarkGunner::is_on_ground() { return (actorFlags >> 23) & 0x1; }

void TObjEneDarkGunner::run_miss_reaction() {
    u8 *self = (u8 *)this;
    ((TObjBase *)self)->clear_actor_flags((s32)(0x100U));
    spawn_particle_effect(&body_center, 0xD7);
    play_sound_effect(0x4003B22D, &position, 0, 0);
}

void TObjEneDarkGunner::update_state_machine() {
    s16 left;
    switch ((s32)state) {
    case 0:
        behavior_flags = behavior_flags | 1;
        clear_actor_flags(0x100);
        timer = resetTimer;
        requested_action = 0;
        actorFlags = actorFlags & 0xFF9FFFFF;
        state = 1;
    case 1:
        advance_animation();
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        update_collisions();
        left = timer;
        timer = left - 1;
        if (left < 0) {
            referenceHp = hp;
            behavior_flags = behavior_flags & 0xFFFFFFFE;
            start_move();
        }
        break;
    case -1:
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneDarkGunner::update_hover() {
    f32 lo;
    s32 i;
    hover_speed += (-0.10888889f);
    hover_height += hover_speed;
    hover_height = (hover_height < 0.0f) ? 0.0f : ((hover_height < 9.0f) ? hover_height : 9.0f);
    push_matrix_from(identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_z(0, rotation_z);
    rotate_matrix_y(0, rotation_y);
    Vec t = dark_gunner_shadow_origin;
    lo = 5.0f + hover_height;
    t.y = lo + render_y_offset;
    matrix_mult_vec(0, &t, &shadow_pos);
    if (mode == 2) {
        for (i = 0; i < 4; i++) {
            matrix_mult_vec(0, &dark_gunner_child_local_offsets[i], &child_offsets[i]);
        }
    }
    pop_matrix();
}

void TObjEneDarkGunner::update_state() {
    switch (mode) {
    case 0:
        update_wait();
        return;
    case 1:
        update_move();
        return;
    case 2:
        update_attack();
        return;
    case 4:
        update_damage();
        return;
    case 3:
        update_state_machine();
        return;
    case 5:
        update_dying();
        return;
    case 6:
        update_hide_sequence();
        return;
    case 8:
        update_return_home();
        break;
    }
}

void TObjEneDarkGunner::start_hide() {
    if (!(actorFlags & 0x800) && !(behavior_flags & 0x800000)) {
        update_if_active(6);
    }
}

void TObjEneDarkGunner::update_hide_sequence() {
    s32 left;

    switch ((s32)state) {
    case 0:
        clear_actor_flags(0x240300);
        behavior_flags |= 0x800000;
        behavior_flags &= ~0x480000;
        this->requested_action = 8;
        hide_timer = get_int_parameter(1);
        state = 1;
    case 1:
        advance_animation();
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity(this, (s32 *)(0), 0.0f);
        }
        update_collisions();
        left = hide_timer - 1;
        hide_timer = (s16) left;
        if ((s16) left <= 0) {
            start_move();
        }
        break;
    case -1:
        behavior_flags &= 0xFF7FFFFF;
        break;
    }
    minimap_render_dot(&this->position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

void TObjEneDarkGunner::update_return_home() {
    switch ((s32)state) {
    case -1:
        break;
    case 0:
        behavior_flags &= ~0x200000;
        behavior_flags |= 0x480000;
        requested_action = 0;
        state = 1;
    case 1: {
        advance_animation();
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, (s32 *)(0), 0.0f);
        }
        calc_velocity_toward_destination(this, position, home_position, get_float_parameter(0));
        move_with_wall_slide(this);
        if (xz_distance_squared(&position, &home_position) <= 100.0f) {
            behavior_flags &= ~0x80000;
            return_home_or_wait();
        }
        break;
    }
    }
}

void TObjEneDarkGunner::load_params() {
    dark_gunner_shot_speed = get_float_parameter(3);
}
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {
void TObjEneDarkGunner::step_along_ground() {
    Vec pos;
    Raw_800A10A0 vel;
    Vec dir;
    Vec v;
    s32 ang;
    s32 sign;
    s32 b;
    s32 a;
    s32 i;
    CsnHit *hit;
    CsnContact *q;

    VecCopy(&prev_position, &position);
    VecCopy(&pos, &body_center);
    vel = *(Raw_800A10A0 *)&velocity;
    vec_set_length((Vec *)&vel, 10.0f + get_float_parameter(0));
    vec3_add_to(&pos, (Vec *)&vel);
    hit = csnVector(&body_center, &pos, -1);
    if (hit != NULL) {
        a = 10430.38043493439 * atan2_float(velocity.x, velocity.z);
        q = hit->contact;
        b = 10430.38043493439 * atan2_float(q->normal.x, q->normal.z);
        move_heading = b - (0x8000 - angle_diff_s16(a, b));
    }
    if ((1.0f / 32768.0f) * (f32)rand() < 0.5f) {
        sign = -1;
    } else {
        sign = 1;
    }
    for (i = 0, ang = 0; i < 15; i++, ang += 0x1000) {
        if (i == 0) {
            VecCopy(&dir, &velocity);
        } else {
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, sign * ang);
            rotate_vector_by_matrix(0, &velocity, &dir);
            pop_matrix();
        }
        VecCopy(&v, &position);
        vec3_add_to(&v, &dir);
        if (project_actor_to_ground(this, &v, 0) == 1) {
            VecCopy(&position, &v);
            VecCopy(&velocity, &position);
            subtract_vector(&velocity, &prev_position);
            return;
        }
    }
}
}

#pragma pop
extern "C" {
s32 TObjEneDarkGunner::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        clear_state7_flag();
        return 1;
    }
    return 0;
}

s32 TObjEneDarkGunner::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        clear_state7_flag();
        return 1;
    }
    return 0;
}

void TObjEneDarkGunner::clear_state7_flag() {  }

void TObjEneDarkGunner::become_death_gunner() {
    behavior_flags |= 0x04000000;
    set_param(0x23);
}

void TObjEneDarkGunner::become_dark_gunner() {
    behavior_flags &= ~0x04000000;
    set_param(0x22);
}
}
