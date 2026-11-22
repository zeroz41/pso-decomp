#include "pso/object/base/CollisionActorLookup.h"
#include "pso/enemy/EnemyTargeting.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/AreaSound.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/technique/TTecZarua.h"
#include "pso/unk/text_800DC420.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include <dolphin/mtx.h>
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueBarrier.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/enemy/TUnk_804E14E8.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TObject.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/TObjControl.h"

s32 get_gigue_int_parameter(TObjEneMe1GiGue *, s32);
f32 get_gigue_float_parameter(TObjEneMe1GiGue *, s32);
saddr ene_me1_gigue_boss_id;
saddr lbl_805D682C;
saddr lbl_805D6830;
GiGueParameters *TObjEneMe1GiGue__param_table;
BmlResource *TObjEneMe1GiGue__data_805D6838;
TUnk_8048FA00 *TObjEneMe1GiGue__barrier_obj;
f32 lbl_805D6840;
f32 lbl_805D6844;
f32 lbl_805D6848;
f32 lbl_805D684C;
s32 lbl_805D6850;
s32 lbl_805D6854;
void move_with_wall_slide(u8 *arg0);
int initialize_enemy_photon_effect(void *p);

extern "C" {
f32 atan2_float(f32 y, f32 x);
s16 get_entity_id(void *);
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
extern "C" {
s32 calc_velocity_toward_destination(void *, Vec, Vec, f32);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
}
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 create__9TTecJelinFllll(void *, void *, void *, s32);
s32 check_path_obstructed(void *, Vec *);
s32 enemy_turn_half_toward_dest(void *);
s32 is_split_screen();
saddr find_active_entity_by_id(int);
s32 minimap_render_dot(void *, int, int, int);
void TObjEneMe1GiGue__sub_802CE4E8(void);
void TObjEneMe1GiGue__sub_802CE4EC();
void TObjEneMe1GiGueBarrier__sub_80325CC0(void);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
s32 obj_setFlags30(void *, int);

}

// What movementParameters points at: EnemyMoveParams and four more words.
struct GiGueMoveParams {
    EnemyMoveParams move;
    s32 unk_c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
};

const char *TObjEneMe1GiGue__model_filename_table[4] = {
    "gi_gue_all.nj", "gi_gue_missile.nj", "gi_gue_barrier.nj", NULL,
};

const char *me1_gi_gue_motion_filename_table[10] = {
    "damage_gi_gue_all.njm", "fire_gi_gue_all.njm", "missile_gi_gue_all.njm", "move_gi_gue_all.njm",
    "wait_gi_gue_all.njm", "rot_gi_gue_missile.njm", "exp_exp_barrier.njm", "on_on_barrier.njm",
    "redu_redu_barrier.njm", NULL,
};

BmlResourceDescriptor lbl_804E1200 = {
    "bm_ene_gi_gue.bml", TObjEneMe1GiGue__model_filename_table, me1_gi_gue_motion_filename_table, 3, 9,
};

const char *lbl_804E1210[4] = {
    "lo_gi_gue_all.nj", "gi_gue_missile.nj", "gi_gue_barrier.nj", NULL,
};

const char *gi_gue_njm_name_table[10] = {
    "damage_gi_gue_all.njm", "fire_gi_gue_all.njm", "missile_gi_gue_all.njm", "move_gi_gue_all.njm",
    "wait_gi_gue_all.njm", "rot_gi_gue_missile.njm", "exp_exp_barrier.njm", "on_on_barrier.njm",
    "redu_redu_barrier.njm", NULL,
};

BmlResourceDescriptor lbl_804E1248 = {
    "bm_ene_gi_gue_low.bml", lbl_804E1210, gi_gue_njm_name_table, 3, 9,
};

TObjMotionAction gigue_enemy_param_table[9] = {
    {2, 0, 4, 0.7f, 0},
    {1, 1, 3, 0.7f, 1},
    {2, 0, 2, 0.6f, 4},
    {2, 7, 1, 0.6f, 4},
    {2, 0, 0, 0.5f, 8},
    {2, 7, 0, 0.5f, 8},
    {2, 7, 3, 0.7f, 1},
    {1, 7, 3, 0.7f, 1},
    {2, 0, 3, 0.7f, 1},
};

GiGueMoveParams lbl_804E12E8 = {
    {150.0f, 0.46296296f, 0x300}, 0x1E0000, 0, 1, 0,
};

CollisionBody lbl_804E1304[2] = {
    {{0.0f, 15.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8001, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 15.0f, 0.0f}, 12.0f, 0.0f, 0, 0xA000002, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TObjEneMe1GiGue__name = "TObjEneMe1GiGue";

void TObjEneMe1GiGue::load_params_from_table(s32 i) {
    model = (void *)TObjEneMe1GiGue__data_805D6838->models[i].model;
    texlist = (saddr)TObjEneMe1GiGue__data_805D6838->models[i].m_c;
}

void TObjEneMe1GiGue::sub_802CDAE8() {  }

f32 get_gigue_float_parameter(TObjEneMe1GiGue *self, s32 i) {
    return TObjEneMe1GiGue__param_table->floats[i];
}

s32 get_gigue_int_parameter(TObjEneMe1GiGue *self, s32 i) {
    return TObjEneMe1GiGue__param_table->ints[i];
}

extern "C" {

void TObjEneMe1GiGue::run_miss_reaction() {  }

void TObjEneMe1GiGue::run_move_action() {  }

void TObjEneMe1GiGue::run_attack_action() {  }

void TObjEneMe1GiGue::run_idle_action() {  }

TObjEneMe1GiGue::TObjEneMe1GiGue(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    m_name = TObjEneMe1GiGue__name;
    apply_set_data(set_data);
    VecCopy((Vec *)&m_290, VecCopy((Vec *)&m_29c, &position));
    motion_list = TObjEneMe1GiGue__data_805D6838->motions;
    variant = 0;
    add_flags_2e4(0x11);
    state36C = *(s16 *)((s8 *)set_data + 0x3E);
    load_params_from_table(variant);
    action_table = gigue_enemy_param_table;
    set_field_d8((saddr)action_table);
    init_collision_body_parts(this, lbl_804E1304, 2);
    bodies[1].flags &= ~1;
    movementParameters = &lbl_804E12E8;
    bind_enemy_combat_stats((u8 *)ene_me1_gigue_boss_id, (u8 *)lbl_805D682C, (u8 *)lbl_805D6830);
    update_direction();
    load_params();
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    initialize_enemy_photon_effect(this);
    m_38c = 0;
    scale.x = 1.0f;
    m_3e4 = ((EnemyMoveParams *)movementParameters)->min_distance * scale.x;
    VecCopy(&home_position, &position);
    VecCopy(&m_390, &position);
    m_440 = 0.5f + parameters[3];
    m_444 = 0.5f + parameters[4];
    m_43c = 150.0f + parameters[2];
    if (m_43c < 0.0f) {
        m_43c = 0.0f;
    }
    if ((s32)parameters[0] >= 1) {
        m_388 |= 0x40000;
        if (parameters[1] < 1.0f) {
            parameters[1] = 50.0f;
        }
        set_flags_30();
    }
    m_3f4 = 0;
    m_3f8 = 0;
    set_param(0x37);
    m_3e8 = 0.0f;
    m_448 = 0;
    if (m_388 & 0x40000) {
        init_move();
    } else {
        sub_800C7860();
    }
    project_actor_to_ground(this, &position, 0);
    m_3ec = 0.0f;
    m_418.activate_and_dispatch();
    obj_setFlags30(this, 0x01000000);
    VecCopy(&prev_position, &position);
    clear_lobby_object_state();
}

TObjEneMe1GiGue::~TObjEneMe1GiGue() {
    free_collision_body_parts(this);
}

void TObjEneMe1GiGue::load_resources() {
    void *o;

    if (is_split_screen() != 0) {
        o = new BmlResource(1, &lbl_804E1248, 0, 0, NULL);
        TObjEneMe1GiGue__data_805D6838 = (BmlResource *)o;
    } else {
        o = new BmlResource(1, &lbl_804E1200, 0, 0, NULL);
        TObjEneMe1GiGue__data_805D6838 = (BmlResource *)o;
    }
    ene_me1_gigue_boss_id = (saddr)TLobby::register_boss(0x1A);
    lbl_805D682C = (saddr)TLobby::dispatch_shared_handler_b(0x1A);
    lbl_805D6830 = (saddr)TLobby::register_object(0x1A);
    TObjEneMe1GiGue__param_table = (GiGueParameters *)TLobby::dispatch_shared_handler_a(0x1A);
    o = new TUnk_8048FA00((saddr)TObjEneMe1GiGue__data_805D6838->models->model);
    TObjEneMe1GiGue__barrier_obj = (TUnk_8048FA00 *)o;
    TObjEneMe1GiGue__sub_802CE4EC();
    TObjEneMe1GiGueBarrier::init_global();
    {
    NpcAnimationBinding binding = { reinterpret_cast<BmlMotionEntry *>(TObjEneMe1GiGue__data_805D6838->motions), reinterpret_cast<TObjMotionAction *>(gigue_enemy_param_table), 0, 1, 9 };
    NpcModelRegistry::register_animated_chunk(0x41, reinterpret_cast<void *>(TObjEneMe1GiGue__data_805D6838->models->model), reinterpret_cast<void *>(TObjEneMe1GiGue__data_805D6838->models->m_c), &binding, lbl_804E1304[0].radius, 15.0f);
    }
}

void TObjEneMe1GiGue::delete_barrier() {
    TObjEneMe1GiGueBarrier__sub_80325CC0();
    TObjEneMe1GiGue__sub_802CE4E8();
    if (TObjEneMe1GiGue__barrier_obj != NULL) {
        delete TObjEneMe1GiGue__barrier_obj;
        TObjEneMe1GiGue__barrier_obj = NULL;
    }
    if (TObjEneMe1GiGue__data_805D6838 != NULL) {
        delete TObjEneMe1GiGue__data_805D6838;
        TObjEneMe1GiGue__data_805D6838 = NULL;
    }
}

void *TObjEneMe1GiGue::create(void *set_data) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneMe1GiGue(parent, set_data);
}

void TObjEneMe1GiGue::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        load_params();
        sub_802CD054();
        return;
    }
    target = (u8 *)find_active_entity_by_id(targetId);
    release_destroyed_target();
    sub_802CB6D4();
    if (mode != (s32)next_action) {
        if ((s32)state != -1) {
            state = -1;
            dispatch_state();
        }
        mode = next_action;
        state = 0;
    }
    dispatch_state();
    if ((s32)state == -1) {
        state = -1;
        dispatch_state();
        mode = next_action;
        state = 0;
    }
    VecCopy(&body_center, &position);
    body_center.y += 15.0f + m_3ec;
    bodies[0].offset.y = 25.0f + m_3ec;
    if (!(m_388 & 0x40000)) {
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
    }
    if (m_3f4 > 0) {
        m_3f4--;
    }
    bodies[0].flags &= ~6;
    if (m_3ec > 5.0f) {
        bodies[0].flags |= 4;
    } else {
        bodies[0].flags |= 2;
    }
    m_418.update();
    if (xz_distance_squared(&position, &prev_position) > 2500.0f) {
        VecCopy(&position, &prev_position);
    }
    VecCopy(&prev_position, &position);
}

void TObjEneMe1GiGue::dispatch_state() {
    switch (mode) {
    case 0:
        sub_802CCF2C();
        return;
    case 1:
        sub_802CCBAC();
        return;
    case 2:
        sub_802CDAE8();
        return;
    case 3:
        update_state_machine();
        return;
    case 4:
        update_hit_reaction();
        return;
    case 5:
        break_apart();
        return;
    case 9:
        sub_802CC614();
        return;
    case 10:
        sub_802CC900();
        return;
    case 11:
        sub_802CC45C();
        return;
    case 12:
        action();
        return;
    case 13:
        update_rush_attack();
        return;
    case 7:
        init();
        return;
    case 14:
        sub_802CB378();
        break;
    }
}

void TObjEneMe1GiGue::render() {
    s32 vis;
    s32 ok;

    if (actorFlags & 0x2000000) {
        return;
    }
    if (get_current_floor_area() == AREA_TOWER) {
        vis = classify_actor_view_detail(600.0f, 600.0f, 20.0f);
    } else {
        vis = classify_actor_view_detail(150.0f, 400.0f, 20.0f);
    }
    if (vis == 0) {
        return;
    }
    if (TObjPlayer::check_demo_mode() != 1 && (m_388 & 0x40000)) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    if (m_418.updateFromCamera(&body_center.x) != 0) {
        ((MaterialColorFade *)&m_418)->set_flags_and_apply_damage_color();
        if (defer_render() != 0) {
            model_render_flags = saved_model_render_flags;
            return;
        }
    }
    TObjFish::set_global_param(texlist);
    select_actor_lighting((saddr)this);
    TObjPlayer::toggle_particle_effect();
    ok = 1;
    push_matrix();
    translate_matrix(0, position.x, m_3ec + (position.y + m_3e8), position.z);
    rotate_matrix_y(NULL, rotation_y);
    model_render_flags &= ~0x400;
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(model);
    } else if (m_388 & 4) {
        if (((MaterialColorFade *)&m_3fc)->has_visible_opacity() != 0) {
            ((MaterialColorFade *)&m_3fc)->set_flags_and_apply_damage_color();
            if (vis == 1) {
                set_motion_packed_rotation();
                draw();
                clear_motion_packed_rotation();
            } else {
                set_motion_packed_rotation();
                draw_motion_model();
                clear_motion_packed_rotation();
            }
            ((MaterialColorFade *)&m_3fc)->clear_flag_and_notify();
        } else {
            ok = 0;
        }
    } else {
        if (vis == 1) {
            set_motion_packed_rotation();
            draw();
            clear_motion_packed_rotation();
        } else {
            set_motion_packed_rotation();
            draw_motion_model();
            clear_motion_packed_rotation();
        }
    }
    pop_matrix();
    restore_scene_lighting();
    TParticleCtrl::end_effect_render();
    if (!(actorFlags & 0x800) && ok != 0) {
        Vec v;
        v.x = v.y = v.z = (1.0f - 0.01f * m_3ec) * (5.0f * scale.x);
        draw_ground_shadow(&v, 0);
    }
    ((MaterialColorFade *)&m_418)->clear_flag_and_notify();
    model_render_flags = saved_model_render_flags;
}

void TObjEneMe1GiGue::sub_802CD054() {  }

void TObjEneMe1GiGue::sub_802CCF2C() {
    if (m_388 & 0x40000) {
        return;
    }
    switch (state) {
    case -1:
        break;
    case 0:
        requested_action = 1;
        state = 1;
        m_384 = 150;
        sub_8004292C();
    case 1:
        advance_animation();
        move_around_center(&home_position, parameters[1]);
        m_384 -= 1;
        if (m_384 <= 0) {
            requested_action = 0;
            state = 2;
            m_384 = 90;
        }
        check_object_collisions();
        check_enemy_body_collisions(this);
        update_enemy_collision_flags();
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case 2:
        advance_animation();
        check_object_collisions();
        check_enemy_body_collisions(this);
        update_enemy_collision_flags();
        m_384 -= 1;
        if (m_384 <= 0) {
            state = 0;
        }
        break;
    }
}

void TObjEneMe1GiGue::run_hit_reaction() {
    switch (mode) {
    case 10:
    case 11:
    case 13:
        referenceHp = hp;
        actorFlags &= ~0x200;
        return;
    }
    set_state(4);
    m_380 = m_378;
    m_378 = 4;
    m_388 |= 0x10000 | 1;
}

void TObjEneMe1GiGue::run_death_reaction() {
    set_state(5);
    m_380 = m_378;
    m_378 = 5;
    m_388 |= 1;
}

void TObjEneMe1GiGue::sub_802CCBAC() {
    actorFlags &= ~0x01000000;
    switch (state) {
    case 0:
        m_388 &= ~0x00040000;
        sub_8004292C();
        requested_action = 1;
        m_3dc = 0;
        if (target != NULL) {
            VecCopy((Vec *)&m_29c, &((TObjChara *)target)->body_center);
        }
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        if (target != NULL) {
            Vec d = ((TObjBase *)target)->position;
            subtract_vector(&d, &position);
            if (d.x * d.x + d.z * d.z <= m_438 * m_438 &&
                angle_difference_abs(-(s32)(10430.38043493439 * atan2_float(d.z, d.x)) + 0x4000, rotation_y) < m_434 / 2) {
                s32 next;
                m_3f8++;
                if (m_3f8 > 2) {
                    m_3f8 = 0;
                    next = 13;
                } else {
                    m_448 = 0;
                    next = 9;
                }
                update_if_active(next);
                break;
            }
        }
        rotation_y += ((EnemyMoveParams *)movementParameters)->turn_speed / 2;
        enemy_set_heading_velocity(m_3e4, this, rotation_y);
        move_with_wall_slide((u8 *)this);
        m_3dc += ((EnemyMoveParams *)movementParameters)->turn_speed / 2;
        if (m_3dc > 0x10000) {
            m_3e0 = 0.0f;
            state = 2;
        }
        break;
    case -1:
        break;
    case 2:
        enemy_wander_home(m_3e4, 100.0f, 50.0f, ((EnemyMoveParams *)movementParameters)->turn_speed);
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        m_3e0 += m_3e4;
        if (m_3e0 > 100.0f) {
            if (find_target_in_range(((EnemyMoveParams *)movementParameters)->max_distance) != 0) {
                m_3dc = 0;
                state = 1;
            } else {
                update_if_active(0);
            }
        }
        check_object_collisions();
        check_enemy_body_collisions(this);
        update_enemy_collision_flags();
        break;
    }
}

void TObjEneMe1GiGue::sub_802CC900() {
    TParticleCtrl *particle;

    switch (state) {
    case 0:
        sub_8004292C();
        m_384 = m_450;
        if (m_384 <= 40) {
            m_384 = 40;
        }
        if (!(actorFlags & 0x01000000)) {
            requested_action = 2;
            goto start;
        }
        update_if_active(13);
        m_388 &= ~0x40000;
        break;
    start:
        state = 1;
        advance_animation();
        m_388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        if (target == NULL) {
            state = 4;
            break;
        }
        switch (state) {
        case 1:
            if (frame >= 5.0f) {
                sub_802CB03C();
                state = 2;
            }
            break;
        case 2:
            play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(this, 0x3A81D)), (saddr)this, (uaddr)&position, (s32)(0), (s32)(0));
            if (frame >= 20.0f) {
                sub_802CB03C();
                if ((particle = spawn_particle_effect(&m_39c, 0x203)) != NULL) {
                    GiGueShotAngles dir = {0x4000, 0, 0};
                    particle->set_direction(&dir);
                }
                TObjEneMe1GiGueMissile::create((saddr)this, (saddr)&m_39c, (saddr)&((TObjChara *)target)->body_center, lbl_805D6840, (f32)lbl_805D6850);
                play_sound_effect(TObjEneMe1GiGue::remap_sound_id(this, 0x3A31E), &position, 0, 0);
                state = 3;
            }
            break;
        }
        VecCopy((Vec *)&m_29c, &((TObjChara *)target)->body_center);
        enemy_turn_half_toward_dest(this);
        advance_animation();
        if (!(actorFlags & 0x01000000)) {
            apply_actor_gravity(this, 0, 0.0f);
        }
        ((TObjPlayer *)this)->update_collisions();
        if (--m_384 <= 0) {
            state = 4;
        }
        break;
    case 4:
        if (actorFlags & 0x01000000) {
            m_378 = 0;
            update_if_active(13);
        } else if (!(m_388 & 0x80000) && random_ratio() <= m_440) {
            update_if_active(12);
        } else {
            update_if_active(0);
        }
        break;
    case -1:
        break;
    }
}

void TObjEneMe1GiGue::sub_802CC614() {
    s32 n;
    s32 count;

    switch (state) {
    case -1:
        break;
    case 0:
        sub_8004292C();
        count = 0;
        if (!(actorFlags & 0x01000000)) {
            count = sub_802CB10C();
        }
        if (count > 0) {
            requested_action = 3;
            m_384 = m_450;
            if (m_384 <= 20) {
                m_384 = 20;
            }
            state = 1;
        } else if (actorFlags & 0x01000000) {
            update_if_active(13);
        } else if (!(m_388 & 0x80000) && random_ratio() <= m_440) {
            update_if_active(12);
        } else {
            update_if_active(0);
        }
        m_388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (state) {
        case 1:
            if (frame >= 5.0f) {
                sub_802CB03C();
                state = 2;
            }
            break;
        case 2:
            play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(this, 0x3A820)), (saddr)this, (uaddr)&position, (s32)(0), (s32)(0));
            if (frame >= 10.0f) {
                sub_802CB03C();
                n = m_3c0;
                sub_802CB824((s32)((f32)n * random_ratio()) % n);
                state = 3;
            }
            break;
        }
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        m_384--;
        if (m_384 <= 0) {
            m_448++;
            if (m_448 >= 3) {
                m_384 = 45;
                requested_action = 1;
                state = 4;
            } else {
                state = 0;
                frame = 0.0f;
            }
        }
        break;
    case 4:
        enemy_wander_home(m_3e4, 100.0f, 100.0f, ((EnemyMoveParams *)movementParameters)->turn_speed);
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        m_384--;
        if (m_384 <= 0) {
            if (!(m_388 & 0x80000) && random_ratio() <= m_440) {
                update_if_active(12);
            } else {
                update_if_active(0);
            }
        }
        break;
    }
}

void TObjEneMe1GiGue::sub_802CC45C() {
    s32 count;
    switch (state) {
    case -1:
        break;
    case 0:
        sub_8004292C();
        count = 0;
        if (!(actorFlags & 0x01000000)) {
            count = sub_802CB10C();
        }
        if (count > 0) {
            state = 1;
            requested_action = 3;
        } else if (actorFlags & 0x01000000) {
            update_if_active(13);
        } else {
            update_if_active(0);
        }
        m_388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (state) {
        case 1:
            if (frame >= 5.0f) {
                sub_802CB03C();
                spawn_particle_effect(&m_3a8, 0x204);
                state = 2;
            }
            break;
        case 2:
            play_sound_effect(TObjEneMe1GiGue::remap_sound_id(this, 0x3A344), &position, 0, 0);
            if (frame >= 10.0f) {
                sub_802CB03C();
                state = 3;
                TTecZarua::create_instance((saddr)this, &body_center, &body_center, get_gigue_int_parameter(this, 2));
                create__9TTecJelinFllll(this, &body_center, &body_center, get_gigue_int_parameter(this, 2));
            }
            break;
        }
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        if (requested_action != 3) {
            update_if_active(13);
        }
        break;
    }
}

void TObjEneMe1GiGue::action() {
    switch (state) {
    case 0:
        sub_8004292C();
        m_388 &= ~0x40000;
        requested_action = 1;
        state = 1;
        return;
    case 1:
        TObjEneMe1GiGueBarrier::create(this, this);
        state = 2;
        m_384 = 45;
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        return;
    case 2:
        enemy_wander_home(m_3e4, 100.0f, 100.0f, ((EnemyMoveParams *)movementParameters)->turn_speed);
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        m_384 = m_384 - 1;
        if (m_384 <= 0) {
            update_if_active(0);
        }
    case -1:
        return;
    }
}

void TObjEneMe1GiGue::update_rush_attack() {
    switch (this->state) {
    case 0:
        this->actorFlags |= 0x800000;
        this->actorFlags &= ~0x1000000;
        this->requested_action = this->state = 1;
        this->m_3ec = 0.0f;
        this->m_454 = 60;
        this->sub_8004292C();
        break;
    case 1:
        this->actorFlags &= ~0x1000000;
        this->enemy_wander_home(this->m_3e4, 100.0f, 50.0f, ((EnemyMoveParams *)this->movementParameters)->turn_speed);
        this->advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        this->m_454--;
        if (this->m_454 <= 0) {
            this->state = 2;
            play_sound_effect(TObjEneMe1GiGue::remap_sound_id(this, 0x3A818), &this->position, 0, 0);
            this->actorFlags |= 0x1000000;
            this->actorFlags &= ~0x800000;
            this->find_target_in_range(((EnemyMoveParams *)this->movementParameters)->max_distance);
            if (this->target != NULL) {
                Vec d;
                VecCopy(&d, &this->position);
                subtract_vector(&d, &((TObjBase *)this->target)->position);
                find_open_direction(&d);
                calc_velocity_toward_destination(this, this->position, this->m_390, this->m_3e4);
            } else {
                VecCopy(&this->m_390, &this->home_position);
                calc_velocity_toward_destination(this, this->position, this->m_390, this->m_3e4);
            }
        }
        this->check_object_collisions();
        check_enemy_body_collisions(this);
        this->update_enemy_collision_flags();
        break;
    case 2: {
        s32 rising;
        this->actorFlags &= ~0x800000;
        this->advance_animation();
        calc_velocity_toward_destination(this, this->position, this->m_390, get_gigue_float_parameter(this, 0));
        rising = 1;
        if (this->requested_action == 6 && this->frame < 22.0f) {
            rising = 0;
        }
        if (rising) {
            this->m_3ec += 2.2f;
        }
        ((TObjPlayer *)this)->update_collisions();
        if (TObjPlayer__sub_800DC478((u8 *)this, 1, 22.0f) != 0 && this->check_vector_bit(&this->position) != 0) {
            spawn_particle_effect(&this->position, 0xF0);
        }
        if (this->m_3ec >= 50.0f) {
            this->state = 3;
        }
        play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(this, 0x3A819)), (saddr)this, (uaddr)&this->position, (s32)(0), (s32)(0));
        break;
    }
    case 3:
        this->advance_animation();
        calc_velocity_toward_destination(this, this->position, this->m_390, get_gigue_float_parameter(this, 0));
        this->y_speed = 0.0f;
        VecCopy(&this->prev_position, &this->position);
        vec3_add_to(&this->position, (Vec *)&this->x_speed);
        if (csnVector(&this->prev_position, &this->position, 0x88E0) != 0) {
            VecCopy(&this->position, &this->prev_position);
            this->state = 4;
            this->x_speed = this->m_310 = 0.0f;
        } else {
            if (xz_distance_squared(&this->position, &this->m_390) <= (10.0f + this->m_3e4) * (10.0f + this->m_3e4)) {
                this->state = 4;
                this->x_speed = this->m_310 = 0.0f;
            }
        }
        if (this->is_passing_frame(10.0f) != 0 && this->check_vector_bit(&this->position) != 0) {
            spawn_particle_effect(&this->position, 0xF0);
        }
        this->refresh_collision_body_centers();
        if (this->m_3ec > 15.0f) {
            this->turn_toward_direction(((EnemyMoveParams *)this->movementParameters)->turn_speed * 2, (Vec *)&this->x_speed);
        }
        play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(this, 0x3A819)), (saddr)this, (uaddr)&this->position, (s32)(0), (s32)(0));
        project_actor_to_ground(this, &this->position, 0);
        break;
    case 4:
        this->actorFlags &= ~0x800000;
        this->bodies[1].flags |= 1;
        this->advance_animation();
        this->m_3ec += -2.3f;
        if (this->m_3ec <= 0.0f) {
            this->m_3ec = 0.0f;
            this->actorFlags |= 0x800000;
            this->actorFlags &= ~0x1000000;
            this->y_speed = 0.0f;
            if (this->requested_action != 8) {
                if (!(this->m_388 & 0x80000) && this->random_ratio() <= this->m_440) {
                    this->update_if_active(12);
                } else {
                    this->update_if_active(0);
                }
            }
        } else if (this->requested_action == 7) {
            if (this->m_3ec <= 2.3f * (40.0f + 1.0f / this->blend_speed)) {
                this->requested_action = 8;
            }
        } else {
            s32 frame = (s32)this->frame;
            if ((frame == 0x14 || frame == 0x28) && this->check_vector_bit(&this->position) != 0) {
                spawn_particle_effect(&this->position, 0xF0);
            }
        }
        play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(this, 0x3A819)), (saddr)this, (uaddr)&this->position, (s32)(0), (s32)(0));
        this->check_object_collisions();
        check_enemy_body_collisions(this);
        this->update_enemy_collision_flags();
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case -1:
        if ((s32)this->next_action != 4 && (s32)this->next_action != 5) {
            this->m_3ec = 0.0f;
        }
        this->bodies[1].flags &= ~1;
        this->m_388 &= ~0x40000;
        this->m_3f8 = 0;
        break;
    }
}

void TObjEneMe1GiGue::update_hit_reaction() {
    s16 action;
    s16 ref_hp;
    saddr entity;
    s32 retaliate;
    switch (state) {
    case 0:
        action = 4;
        actorFlags &= ~0x200000;
        if (actorFlags & 0x01000000) {
            action = 5;
        }
        requested_action = action;
        spawn_particle_effect(&body_center, 0xF2);
        state = 1;
    case 1:
        advance_animation();
        if (!(actorFlags & 0x01000000)) {
            Vec v = body_center;
            v.x += x_speed;
            v.z += m_310;
            if (check_path_obstructed(this, &v) == 0) {
                move_with_wall_slide((u8 *)this);
            } else {
                x_speed = m_310 = 0.0f;
            }
            x_speed *= 0.5f;
            m_310 *= 0.5f;
        }
        apply_actor_gravity(this, 0, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        if (action_flags != 8) {
            state = -1;
        }
        break;
    case -1:
        retaliate = 0;
        actorFlags &= ~0x200;
        m_388 &= ~1;
        m_378 = 1;
        ref_hp = referenceHp;
        if (ref_hp - hp > ref_hp / 4 && !(actorFlags & 2)) {
            entity = (saddr)find_entity_by_id(attacker_id);
            if (entity != 0) {
                retaliate = 1;
                if ((actorFlags & 0x01000000) && xz_distance_squared(&position, &((TObjBase *)entity)->position) > 400.0f) {
                    retaliate = 0;
                }
            }
        }
        if (retaliate == 1) {
            targetId = attacker_id;
            next_action = 9;
        } else if (actorFlags & 0x01000000) {
            update_if_active(13);
            m_378 = m_380;
        } else {
            update_if_active(0);
        }
        referenceHp = hp;
        break;
    }
}

void TObjEneMe1GiGue::break_apart() {
    Vec pos;
    VecCopy(&pos, &position);
    pos.y += 40.0f + m_3ec;
    TBoss3Volopt::create_breakup_mdl((saddr)TObjEneMe1GiGue__barrier_obj, 0, texlist, (saddr)&pos, rotation_y);
    ((TObjPlayer *)this)->refresh_lobby_state();
    send_entity_set_flags();
    spawn_particle_effect(&pos, 0x205);
    spawn_particle_effect(&pos, 0x206);
    play_sound_effect(remap_sound_id(this, 0x3AF1C), &pos, 0, 0);
    queue_destruction();
}

void TObjEneMe1GiGue::move_around_center(void *center, f32 radius) {
    if (xz_distance_squared(&this->position, &this->m_390) < 400.0f) {
        s32 angle = (s32)(182.04445f * (360.0f * this->random_ratio()));
        f32 d = 0.4f * (radius * (1.0f + this->random_ratio()));
        this->m_390.x = d * cos_table_lookup(angle) + ((Vec *)center)->x;
        this->m_390.z = d * sin_table_lookup(angle) + ((Vec *)center)->z;
    }
    VecCopy((Vec *)&this->m_29c, &this->m_390);
    enemy_turn_toward_dest(((EnemyMoveParams *)this->movementParameters)->turn_speed);
    enemy_set_heading_velocity(this->m_3e4, this, this->rotation_y);
    move_with_wall_slide((u8 *)this);
}

void TObjEneMe1GiGue::sub_802CB824(s32 index) {
    if (find_entity_by_id(m_3c4[index]) != 0) {
        GiGueShotAngles angles;
        angles.x = 0;
        angles.y = rotation_y + ((index & 1) ? -0x2000 : 0x2000);
        angles.z = 0;
        new TUnk_804E14E8(&m_3a8, m_3c4[index], &angles, index * 3,
                          random_ratio() <= get_gigue_float_parameter(this, 5),
                          entity_id);
    }
}

void TObjEneMe1GiGue::sub_802CB6D4() {
    switch (mode) {
    case 0:
        if (is_actor_cadence_frame(30) != 0) {
            if (find_nearest_visible_player(this, NULL, ((EnemyMoveParams *)movementParameters)->max_distance) != 0xFFFF) {
                find_target_in_range(((EnemyMoveParams *)movementParameters)->max_distance);
                if (m_388 & 0x40000) {
                    init_move();
                } else {
                    update_if_active(1);
                }
            }
        }
        break;
    case 1:
        if (find_nearest_visible_player(this, NULL, 50.0f) != 0xFFFF) {
            if (random_ratio() <= m_444) {
                update_if_active(11);
            } else {
                update_if_active(13);
                m_378 = 1;
            }
        } else if (find_nearest_visible_player(this, NULL, 50.0f + ((EnemyMoveParams *)movementParameters)->max_distance) == 0xFFFF) {
            update_if_active(0);
        }
        break;
    case 13:
        break;
    }
}

void TObjEneMe1GiGue::init_move() {
    VecCopy(&prev_position, &position);
    actorFlags |= 0x01000000;
    update_if_active(14);
    m_378 = 1;
    refresh_collision_body_centers();
}

void TObjEneMe1GiGue::apply_hit_shake(TObjChara *player) {
    if (player == get_player_by_client_id(0) && m_3f4 <= 0) {
        m_3f4 = 30;
        TCameraCtrl::set_shake_preset(1);
    }
}

s32 TObjEneMe1GiGue::remap_sound_id(void *obj, s32 id) {
    s32 area = get_current_floor_area();
    if (id == 0x3A344) return area == AREA_TOWER ? 0x40039E14 : id;
    if (id == 0x3A345) return area == AREA_TOWER ? 0x40039415 : id;
    return ((TObjEnemy *)obj)->remap_sound_for_area(id);
}

}

void TObjEneMe1GiGue::sub_802CB378() {
    f32 height;
    s32 whole_frame;
    switch (state) {
    case 0:
        VecCopy(&m_390, &home_position);
        calc_velocity_toward_destination(this, position, m_390, m_3e4);
        m_388 &= ~0x40000;
        sub_8004292C();
        m_3ec = m_43c;
        requested_action = 7;
        state = 1;
    case 1:
        advance_animation();
        bodies[1].flags |= 1;
        m_3ec += -2.3f;
        height = m_3ec;
        if (height <= 0.0f) {
            m_3ec = 0.0f;
            actorFlags |= 0x800000;
            actorFlags &= ~0x1000000;
            y_speed = 0.0f;
            if (requested_action != 8) {
                state = -1;
                play_sound_effect(TObjEneMe1GiGue::remap_sound_id(this, 0x3A345), &position, 0, 0);
            }
        } else if (requested_action == 7) {
            if (height <= 2.3f * (40.0f + 1.0f / blend_speed)) {
                requested_action = 8;
            }
        } else {
            whole_frame = (s32)frame;
            if ((whole_frame == 0x14 || whole_frame == 0x28) && check_vector_bit(&position) != 0) {
                spawn_particle_effect(&position, 0xF0);
            }
        }
        play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(this, 0x3A819)), (saddr)this, (uaddr)&position, (s32)(0), (s32)(0));
        ((TObjPlayer *)this)->update_collisions();
        break;
    case -1:
        update_if_active(1);
        break;
    }
    apply_actor_gravity(this, 0, 0.0f);
}

void TObjEneMe1GiGue::init() {
    u32 flags;

    switch (state) {
    case 0:
        m_388 |= 4;
        flags = actorFlags | 0x04000000;
        actorFlags = flags;
        requested_action = 0;
        play_area_sound_effect(&body_center);
        m_3fc.start_fade_in();
        state = 1;
    case 1:
        advance_animation();
        if (((TUnk_80494938 *)&m_3fc)->advance_toward_max() == 1) {
            state = -1;
            play_sound_effect(TObjEneMe1GiGue::remap_sound_id(this, 0x3A345), &position, 0, 0);
        }
        ((TObjPlayer *)this)->update_collisions();
        return;
    case -1:
        flags = m_388;
        m_388 = flags & ~5;
        actorFlags &= ~0x04000000;
        update_if_active(0);
        return;
    }
}

extern "C" {

void TObjEneMe1GiGue::add_target_in_cone(TObjChara *target) {
    int angle;
    if (this->m_3c0 < 12 && target != NULL && (void *)target != (void *)this && !(target->actorFlags & 0x06000800)) {
        Vec v = target->position;
        subtract_vector(&v, &this->position);
        if (!(v.x * v.x + v.z * v.z > this->m_438 * this->m_438)) {
            angle = -(s32)(10430.38043493439 * atan2_float(v.z, v.x)) + 0x4000;
            if (angle_difference_abs(angle, this->rotation_y) <= this->m_434 / 2) {
                this->m_3c4[this->m_3c0++] = get_entity_id(target);
            }
        }
    }
}

s32 TObjEneMe1GiGue::sub_802CB10C() {
    s32 i;
    m_3c0 = 0;
    for (i = 0; i < registered_player_count; i++) {
        TObjChara *player = (TObjChara *)TObjPlayer::get_player_data(i);
        add_target_in_cone(player);
    }
    return m_3c0;
}

void TObjEneMe1GiGue::sub_802CB03C() {
    push_matrix_from(&identity_matrix);
    translate_matrix(0, position.x, m_3ec + (position.y + m_3e8), position.z);
    rotate_matrix_y(0, rotation_y);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    get_anim_node_position(0, &m_3b4);
    get_anim_node_position(0x2A, &m_39c);
    get_anim_node_position(0x16, &m_3a8);
}

void TObjEneMe1GiGue::update_direction() {
    m_438 = ((AttackParams *)m_318)->get_attack_range();
    m_434 = ((AttackParams *)m_318)->get_attack_angle();
}

void TObjEneMe1GiGue::load_params() {
    lbl_805D6840 = get_gigue_float_parameter(this, 1);
    lbl_805D6844 = get_gigue_float_parameter(this, 2);
    lbl_805D6848 = get_gigue_float_parameter(this, 3);
    lbl_805D684C = get_gigue_float_parameter(this, 4);
    lbl_805D6850 = get_gigue_int_parameter(this, 0);
    lbl_805D6854 = get_gigue_int_parameter(this, 1);
    m_44c = (s32)(30.0f * (f32)get_gigue_int_parameter(this, 3));
    m_450 = get_gigue_int_parameter(this, 4);
}

#pragma pool_data off
void TObjEneMe1GiGue::find_open_direction(Vec *dir) {
    f32 best;
    s32 ang;
    s32 best_ang;
    s32 i;
    CsnHit *hit;
    f32 d;
    ang = (s32)(10430.38043493439 * atan2_float(dir->x, dir->z));
    best = 0.0f;
    best_ang = ang;
    push_matrix_from(&identity_matrix);
    Vec v = {200.0f, 0.0f, 0.0f};
    rotate_matrix_y(0, ang);
    for (i = 0; i < 3; i++) {
        matrix_mult_vec(0, &v, &m_390);
        vec3_add_to(&m_390, &body_center);
        hit = csnVector(&body_center, &m_390, -1);
        if (hit == NULL) {
            pop_matrix();
            return;
        }
        d = vec_xz_distance(&position, &hit->contact->point) - 20.0f;
        if (best < d) {
            best = d;
            best_ang = ang;
        }
        rotate_matrix_y(0, 0x5555);
        ang += 0x5555;
    }
    pop_matrix();
    push_matrix_from(&identity_matrix);
    Vec w = {0.0f, 0.0f, 0.0f};
    w.x = best;
    rotate_matrix_y(0, best_ang);
    matrix_mult_vec(0, &w, &m_390);
    vec3_add_to(&m_390, &body_center);
    pop_matrix();
}
#pragma pool_data reset

s32 TObjEneMe1GiGue::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        sub_802CACD8();
        return 1;
    }
    return 0;
}

void TObjEneMe1GiGue::sub_802CACD8() {
    s32 flags = m_388;
    if (flags & 0x40000) {
        m_388 = flags & ~0x40000;
        VecCopy(&position, &home_position);
        project_actor_to_ground(this, &position, 0);
        return;
    }
    if ((s32)next_action == 7) {
        m_388 = flags & ~1;
        update_if_active(0);
    }
}

s32 TObjEneMe1GiGue::check_vector_bit(Vec *pos) {
    CsnHit *hit = csnVectorUnder(pos, (CsnGroup **)&m_120, 5);
    if (hit == NULL) {
        return 0;
    }
    return (u32)__cntlzw(hit->hit_mask & 4) >> 5;
}

BmlResource *TObjEneMe1GiGue::sub_802CAC80() { return TObjEneMe1GiGue__data_805D6838; }

}

Vec *TObjEneMe1GiGue::update_and_get_pos() {
    sub_802CB03C();
    return &m_3b4;
}

s32 TObjEneMe1GiGue::sub_802CAC48() { return rotation_y; }

s32 TObjEneMe1GiGue::get_field_44c() { return m_44c; }

s32 TObjEneMe1GiGue::is_active_state() {
    s32 r = 0;
    s16 v = mode;
    if (v == 9) goto yes;
    if (v == 10) goto yes;
    if (v == 11) goto yes;
    if (v == 4) goto yes;
    if (v != 5) goto done;
yes:
    r = 1;
done:
    return (u8)r;
}

void TObjEneMe1GiGue::sub_802CABF4() { m_388 |= 0x80000; }

void TObjEneMe1GiGue::clear_flag388_bit80000() { m_388 &= ~0x80000; }

extern "C" {

f32 TObjEneMe1GiGue::receive_physical_attack(void *attacker, f32 power) {
    f32 damage = 0.0f;
    if (m_388 & 0x80000) {
        show_miss_popup(&body_center.x);
        set_state(10);
    } else {
        damage = TObjChara::receive_physical_attack(attacker, power);
    }
    return damage;
}

f32 TObjEneMe1GiGue::receive_direct_attack(void *attacker, DirectAttackPayload hit, void *source, s32, s32) {
    f32 damage = 0.0f;
    if (m_388 & 0x80000) {
        show_miss_popup(&body_center.x);
        set_state(10);
    } else {
        damage = TObjChara::receive_direct_attack(attacker, hit, source, -1, -1);
    }
    return damage;
}

f32 TObjEneMe1GiGue::receive_weapon_special_attack(void *attacker, void *weapon) {
    f32 damage = 0.0f;
    if (m_388 & 0x80000) {
        show_miss_popup(&body_center.x);
        set_state(10);
    } else {
        damage = TObjChara::receive_weapon_special_attack(attacker, weapon);
    }
    return damage;
}

}
