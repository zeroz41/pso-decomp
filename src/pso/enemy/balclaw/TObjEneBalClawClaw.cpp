#include "types.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjControl.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/NinjaUtil.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"


extern "C" {
void obj_clearFlags30__8TObjBaseFUl(void *, u32);
int update_if_active__15TObjEnemyCustomFl(void *, int);
void move_along_ground_avoiding_walls__15TObjEnemyCustomF3Vecff(void *, Vec, void *, f32, f32);
void select_enemy_destination(void *, Vec *, s32);
void enemy_turn_half_toward_dest(void *);
u8 *get_enemy_entity(u16 arg0);
s32 post_translate_matrix(void *);
s32 draw_chunk_object(s32);
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 push_matrix();
extern s32 model_render_flags;
void queue_destruction__7TObjectFv(void *);
void TObjPlayer__sub_800A04F0(void *);
void TObjEneBalClawClaw__sub_80091134(TObjEneBalClawClaw *claw);
s32 check_path_obstructed(void *, void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjEneBalClawClaw__sub_80091200(TObjEneBalClawClaw *claw);
TObjChara *find_active_entity_by_id(u16);
void TObjEneBalClawClaw__sub_80090ECC(TObjEneBalClawClaw *claw);
s32 play_area_se_with_particle__12TBoss3VoloptFv(void *, s32);
s32 TObjPlayer__sub_800A0554(void *);
s32 init_collision_body_parts(void *, void *, int);
void *find_entity_by_id(u16 id);
s32 submit_cursor_candidate(void *, int, int, f32, f32);
s32 minimap_render_dot(void *, int, int, int);
void free_collision_body_parts(void *);

TObjMotionAction balclaw_claw_model_node_desc[7] = {
    {1, 0, 0xF, 1.0f, 0},
    {1, 0, 0xF, 1.0f, 1},
    {2, 0, 0xA, 0.8f, 4},
    {2, 0, 0xB, 0.7f, 8},
    {3, 0, 0xC, 0.5f, 0x10},
    {1, 0, 0xD, 0.7f, 1},
    {1, 0, 0xE, 0.7f, 1},
};
BalClawMovement lbl_8048F100 = {{150.0f, 0.5555555f, 0x400}, 0x1E0000, 0, 1, 0};
CollisionBody TObjEneBalClawClaw__collision_body_template = {{0.0f, 18.0f, 0.0f}, 5.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};

extern void *tl_04;
}

extern u8 *lbl_805D4F28;
extern u8 *lbl_805D4F2C;
extern u8 *lbl_805D4F30;

const char *balclaw_claw_class_name = "TObjEneBalClawClaw";

TObjEneBalClawClaw::TObjEneBalClawClaw(TObject *parent, void *set_data) : TObjEneBalClaw(parent) {
    apply_set_data(set_data);
    TObjEneBalClawClaw__ct(this);
    if (*(s16 *)((s8 *)set_data + 0xA) != 0) {
        sub_800C7860();
    }
}

// Spawned by the body (TObjEneBalClawClaw::create): takes the body's room, group, home and wobble state.
TObjEneBalClawClaw::TObjEneBalClawClaw(TObject *parent, TObjEneBalClaw *body, s32 id, s32 index, Vec *pos,
                                       s32 rot_y, s32)
    : TObjEneBalClaw(parent) {
    entity_id = id;
    set_index = index;
    room = body->room;
    set_group = body->set_group;
    VecCopy(&position, pos);
    VecCopy(&home_position, &body->home_position);
    rotation_z = 0;
    rotation_x = 0;
    rotation_y = rot_y;
    TObjEneBalClawClaw__ct(this);
    set_entry = NULL;
    m_3b8 = body->m_3b8;
    m_3bc = body->m_3bc;
    m_3b4 = body->m_3b4;
    sub_80090798();
}

void TObjEneBalClawClaw__ct(TObjEneBalClawClaw *claw) {
    claw->m_name = balclaw_claw_class_name;
    claw->motion_list = lbl_805D4F20->motions;
    claw->action_table = balclaw_claw_model_node_desc;
    claw->set_field_d8((s32)claw->action_table);
    init_collision_body_parts(claw, &TObjEneBalClawClaw__collision_body_template, 1);
    claw->variant = 0;
    claw->movementParameters = &lbl_8048F100;
    claw->bind_enemy_combat_stats(lbl_805D4F28, lbl_805D4F2C, lbl_805D4F30);
    claw->sub_80090824();
    claw->requested_action = 0;
    claw->set_animation(claw->requested_action);
    claw->set_field_b8(claw->requested_action);
    claw->hp = claw->hpmax;
    claw->tp = claw->tpmax;
    claw->referenceHp = claw->hp;
    claw->set_param(0x26);
    VecCopy((Vec *)&claw->m_2fc, &claw->position);
    claw->m_300 += 5.0f;
    ((TBoss3Volopt *)claw)->reset_photon_effect();
    claw->sub_80090418(2);
    claw->m_3b8 = 0;
    claw->m_3bc = 0.0f;
    claw->m_3ac = 15.0f;
    claw->m_3b0 = 40.0f;
    claw->m_3b4 = claw->m_3ac;
    claw->clear_attack_flag();
    VecCopy((Vec *)&claw->m_290, (const Vec *)VecCopy((Vec *)&claw->m_29c, &claw->position));
    claw->clear_lobby_object_state();
}

TObjEneBalClawClaw::~TObjEneBalClawClaw() {
    free_collision_body_parts(this);
}

void *TObjEneBalClawClaw::create() {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneBalClawClaw(control, this);
}

void *TObjEneBalClawClaw::create(void *arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneBalClawClaw(control, this, (s32)arg1, (s32)arg2, (Vec *)arg3, (s32)arg4, (s32)arg5);
}

void TObjEneBalClawClaw::run_task() {
    f32 lift;
    f32 center_y;
    u32 flags;
    CollisionBody *body;
    TObjBase *parent;
    TObjEneBalClaw__sub_8008D68C();
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_80090824();
        sub_800914A4();
        return;
    }
    flags = m_388;
    if (flags & 0x20000000) {
        update_if_active(0xA);
    } else if (flags & 0x10000000) {
        update_if_active(9);
    } else {
        update_attack_distance_state();
    }
    if (mode != (s32)next_action) {
        if ((s32)state != -1) {
            state = -1;
            update_state();
        }
        mode = next_action;
        state = 0;
    }
    target = (u8 *)find_active_entity_by_id(targetId);
    release_destroyed_target();
    update_state();
    flags = m_388;
    if (!(flags & 0x10000000)) {
        if (flags & 0x20000000) {
            m_3bc = (0.2f + m_3bc < 10.0f) ? 0.2f + m_3bc : 10.0f;
        } else {
            update_wobble();
        }
        update_claw_angle();
        VecCopy((Vec *)&m_2fc, &position);
        center_y = m_300;
        m_300 = center_y + (m_3b4 + m_3bc);
        lift = m_3b4;
        body = bodies;
        body->offset.y = lift + m_3bc;
        submit_cursor_candidate(this, -1, (int)body, lift, center_y);
        minimap_render_dot((u8 *)&position, -0x5DB4, 1, 0);
        return;
    }
    parent = (TObjBase *)find_entity_by_id(m_3c6);
    if (parent != NULL) {
        VecCopy(&position, &parent->position);
    }
}

void TObjEneBalClawClaw::update_state() {
    switch (mode) {
    case 0:
        sub_80090D3C();
        return;
    case 1:
        update_chase(this);
        return;
    case 2:
        TObjEneBalClawClaw__sub_80090ECC(this);
        return;
    case 4:
        TObjEneBalClawClaw__sub_80091200(this);
        return;
    case 5:
        TObjEneBalClawClaw__sub_80091134(this);
        return;
    case 7:
        action(this);
        return;
    case 9:
        update_drop(this);
        return;
    case 10:
        update_follow_parent(this);
        return;
    case 11:
        run_active_state();
        return;
    case 8:
        update_move_to_target(this);
        return;
    case 12:
        update_chase_state();
        break;
    }
}

void TObjEneBalClawClaw::update_attack_distance_state() {
    f32 dist;
    s32 next;
    s32 prev;
    u8 *chased;

    if (is_actor_cadence_frame(0x1E) != 0) {
        find_target_in_range(250.0f);
    }
    switch (mode) {
    case 8:
    case 0:
        if (is_actor_cadence_frame(0x1E) != 0) {
            if (target != NULL) {
                update_if_active(1);
                m_38c = 2;
                return;
            }
            if (xz_distance_squared(&position, &home_position) > 100.0f) {
                update_if_active(8);
                return;
            }
            reset_active_state(this);
        }
        return;
    case 1:
        chased = target;
        if (chased != NULL) {
            dist = xz_distance_squared(&((TObjChara *)chased)->position, &position);
            prev = m_38c;
            switch (prev) {
            case 0:
                if (dist > 1600.0f) {
                    m_38c = 1;
                }
                break;
            case 1:
                if (dist < 400.0f) {
                    clear_attack_flag();
                    m_38c = 0;
                } else if (dist > 10000.0f) {
                    m_38c = 2;
                }
                break;
            case 2:
                if (dist < 6400.0f) {
                    set_attack_distance_flag();
                    m_38c = 1;
                }
                break;
            }
            next = m_38c;
            if (prev != next) {
                switch (next) {
                case 0:
                    update_if_active(2);
                    return;
                case 1:
                    clear_attack_flag();
                    return;
                case 2:
                    set_attack_distance_flag();
                    return;
                }
            }
        } else {
            update_if_active(8);
        }
        break;
    }
}

void TObjEneBalClawClaw::sub_800914A4() {
}

void TObjEneBalClawClaw::update_chase(void *p) {
    TObjEneBalClawClaw *claw = (TObjEneBalClawClaw *)p;
    switch (claw->state) {
    case 0:
        claw->find_target_in_range(250.0f);
        if (claw->targetId != 0xFFFF) {
            claw->actorFlags &= 0xFBFFFEFF;
            claw->sub_8004292C();
            claw->state = claw->requested_action = 1;
        } else {
            reset_active_state(claw);
        }
        claw->target = (u8 *)find_active_entity_by_id(claw->targetId);
        if (claw->target != NULL) {
            VecCopy((Vec *)&claw->m_29c, (const Vec *)&((TObjChara *)claw->target)->m_2fc);
        }
        break;
    case 1: {
        if (claw->target == NULL) {
            reset_active_state(claw);
            break;
        }
        play_persistent_sound(0x4003B235, (s32)claw, (u32)&claw->position, 0, 0);
        Vec target_pos = *(Vec *)&((TObjChara *)claw->target)->m_2fc;
        update_enemy_wander_move(claw, &target_pos, 1, (EnemyMoveParams *)claw->movementParameters,
                                 ((EnemyMoveParams *)claw->movementParameters)->min_distance);
        claw->turn_toward_direction(((EnemyMoveParams *)claw->movementParameters)->turn_speed, (Vec *)&claw->x_speed);
        claw->advance_animation();
        apply_actor_gravity(claw, NULL, 0.0f);
        ((TObjPlayer *)claw)->update_collisions();
        break;
    }
    case -1:
        break;
    }
}

void TObjEneBalClawClaw__sub_80091200(TObjEneBalClawClaw *claw) {
    switch (claw->state) {
    case 0:
        claw->actorFlags &= ~0x200000;
        claw->requested_action = 3;
        claw->state = 1;
    case 1: {
        claw->advance_animation();
        Vec next = *(Vec *)&claw->m_2fc;
        next.x += claw->x_speed;
        next.z += claw->m_310;
        if (check_path_obstructed(claw, &next) == 0) {
            move_with_wall_slide((u8 *)claw);
        } else {
            claw->x_speed = claw->m_310 = 0.0f;
        }
        claw->x_speed *= 0.9f;
        claw->m_310 *= 0.9f;
        apply_actor_gravity(claw, NULL, 0.0f);
        ((TObjPlayer *)claw)->update_collisions();
        play_persistent_sound(0x4003B235, (s32)claw, (u32)&claw->position, 0, 0);
        if (claw->action_flags != 8) {
            claw->actorFlags &= ~0x200;
            claw->m_388 &= ~1;
            claw->referenceHp = claw->hp;
            TObjEneBalClawClaw::reset_active_state(claw);
        }
        break;
    }
    case -1:
        break;
    }
}

void TObjEneBalClawClaw__sub_80091134(TObjEneBalClawClaw *claw) {
    switch (claw->state) {
    case 0:
        ((TObjPlayer *)claw)->refresh_lobby_state();
        claw->requested_action = 4;
        TObjPlayer__sub_800A04F0(&claw->fade);
        fn_800D911C((Vec *)&claw->m_2fc);
        play_sound_effect(0x4003AD37, &claw->position, 0, 0);
        claw->state = 1;
    case 1:
        claw->advance_animation();
        if (claw->fade.decay_value_toward_floor() == 1) {
            TObjPlayer::apply_effect_variant_a((s32)&claw->position, 0);
            claw->send_entity_set_flags();
            queue_destruction__7TObjectFv(claw);
        }
        break;
    case -1:
        return;
    }
}

void TObjEneBalClawClaw__sub_80090ECC(TObjEneBalClawClaw *claw) {
    switch (claw->state) {
    case -1:
        break;
    case 0:
        if (claw->target == NULL) {
            TObjEneBalClawClaw::reset_active_state(claw);
            return;
        }
        claw->clear_attack_flag();
        claw->m_388 &= ~8;
        claw->state = claw->requested_action = 1;
        break;
    case 1: {
        if (claw->target == NULL) {
            TObjEneBalClawClaw::reset_active_state(claw);
            return;
        }
        Vec target_pos = *(Vec *)&((TObjChara *)claw->target)->m_2fc;
        ((s32 (*)(void *, void *, int, f32))update_enemy_wander_move)(claw, &target_pos, 1, 0.7f);
        claw->turn_toward_direction(((EnemyMoveParams *)claw->movementParameters)->turn_speed, (Vec *)&claw->x_speed);
        if (claw->m_3c0 <= ((AttackParams *)claw->m_318)->get_attack_range() * ((AttackParams *)claw->m_318)->get_attack_range()) {
            claw->state = claw->requested_action = 2;
        }
        break;
    }
    case 2: {
        if (claw->target == NULL) {
            TObjEneBalClawClaw::reset_active_state(claw);
            return;
        }
        Vec target_pos = *(Vec *)&((TObjChara *)claw->target)->m_2fc;
        ((s32 (*)(void *, void *, int, f32))update_enemy_wander_move)(claw, &target_pos, 1, 0.7f);
        claw->turn_toward_direction(((EnemyMoveParams *)claw->movementParameters)->turn_speed, (Vec *)&claw->x_speed);
        if (claw->is_passing_frame(8.0f) != 0) {
            play_sound_effect(0x4003B032, &claw->position, 0, 0);
            if (((TObjChara *)claw->target)->select_melee_contact_body(claw, 1.0f) != 0) {
                ((TObjChara *)claw->target)->apply_knockback_from_attacker((u8 *)claw, 3.0f);
                ((TObjChara *)claw->target)->receive_physical_attack(claw, 1.0f);
                claw->m_388 |= 8;
            }
        }
        if (claw->action_flags != 4) {
            claw->timer = 0x5A;
            claw->update_if_active(0xC);
        }
        break;
    }
    case 3:
        claw->timer = claw->timer - 1;
        if (claw->timer <= 0) {
            TObjEneBalClawClaw::reset_active_state(claw);
        }
        break;
    }
    claw->advance_animation();
    apply_actor_gravity(claw, NULL, 0.0f);
    ((TObjPlayer *)claw)->update_collisions();
}

void TObjEneBalClawClaw::action(void *p) {
    TObjEneBalClawClaw *claw = (TObjEneBalClawClaw *)p;
    s32 flags;
    s32 cleared;
    s32 old;

    switch (claw->state) {
    case 0:
        claw->m_388 |= 4;
        flags = claw->actorFlags | 0x04000000;
        claw->actorFlags = flags;
        claw->requested_action = 0;
        play_area_se_with_particle__12TBoss3VoloptFv(&claw->position, flags);
        TObjPlayer__sub_800A0554(&claw->fade);
        claw->state = 1;
    case 1:
        claw->advance_animation();
        apply_actor_gravity(claw, NULL, 0.0f);
        if (claw->fade.advance_toward_max() == 1) {
            old = claw->m_388;
            cleared = old & ~5;
            claw->m_388 = cleared;
            claw->state = -1;
            ((s32 (*)(void *, s32, s32))reset_active_state)(claw, cleared, old);
        }
        return;
    case -1:
        claw->m_388 &= ~5;
        claw->actorFlags &= 0xFBFFFFFF;
        break;
    }
}

void TObjEneBalClawClaw::sub_80090D3C() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        requested_action = 0;
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        return;
    case -1:
        actorFlags &= 0xFFFBFFFF;
        return;
    }
}

void TObjEneBalClawClaw::render() {
    s32 shadow;
    s32 detail;
    s32 visible;

    if (!(actorFlags & 0x02000000)) {
        detail = classify_actor_view_detail(120.0f, 400.0f, 10.0f);
        if (detail != 0) {
            shadow = 1;
            TObjFish::set_global_param(texlist);
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                post_translate_matrix(&position);
                rotate_matrix_x(0, rotation_x);
                rotate_matrix_y(0, rotation_y);
                draw_chunk_object((s32)model);
            } else {
                translate_matrix(0, 0.0f, m_3b4 + m_3bc, 0.0f);
                post_translate_matrix(&position);
                rotate_matrix_x(0, rotation_x);
                rotate_matrix_y(0, rotation_y);
                if (m_388 & 4) {
                    if (fade.has_visible_opacity() != 0) {
                        fade.set_flags_and_apply_damage_color();
                        visible = 1;
                        if (defer_render() != 0) {
                            visible = 0;
                        }
                        if (visible != 0) {
                            if (detail == 1) {
                                draw();
                            } else {
                                draw_motion_model();
                            }
                        }
                        fade.clear_flag_and_notify();
                    } else {
                        shadow = 0;
                    }
                } else if (detail == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            render_scaled(shadow);
        }
    }
}

void TObjEneBalClawClaw::update_follow_parent(void *p) {
    TObjEneBalClawClaw *claw = (TObjEneBalClawClaw *)p;
    TObjBase *parent = (TObjBase *)get_enemy_entity(claw->m_3c6);
    if (parent == NULL || (parent->actorFlags & 0x800)) {
        claw->clear_flag();
        return;
    }
    switch (claw->state) {
    case -1:
        break;
    case 0:
        claw->requested_action = 1;
        claw->clear_attack_flag();
        claw->state = 1;
    case 1: {
        Vec dest = parent->position;
        select_enemy_destination(claw, &dest, 1);
        Vec goal = parent->position;
        claw->m_3c0 = update_enemy_wander_move(claw, &goal, 1, (EnemyMoveParams *)claw->movementParameters,
                                               ((EnemyMoveParams *)claw->movementParameters)->min_distance);
        enemy_turn_half_toward_dest(claw);
        claw->advance_animation();
        apply_actor_gravity(claw, NULL, 0.0f);
        ((TObjPlayer *)claw)->check_object_collisions();
        break;
    }
    }
}

void TObjEneBalClawClaw__sub_80090A10(TObjEneBalClawClaw *claw, Vec *pos, s32 rot_y, s16 hp) {
    VecCopy(&claw->position, pos);
    claw->rotation_y = rot_y;
    claw->referenceHp = hp;
    claw->hp = hp;
    claw->sub_80090798();
    claw->clear_all_status_effects();
}

s32 TObjEneBalClawClaw::check_active() {
    if (actorFlags & 0xA00) {
        return 0;
    }
    return (u32)__cntlzw(m_388 & 0x10000000) >> 5;
}

void TObjEneBalClawClaw::enter_hit_state(s16 body_id) {
    m_3c6 = body_id;
    targetId = body_id;
    m_388 |= 0x20000000;
    actorFlags &= 0xFFFBFFFF;
    m_3c0 = 100000.0f;
    update_if_active(0xA);
    clear_all_status_effects();
}

void TObjEneBalClawClaw::clear_flag() {
    m_388 &= 0xDFFFFFFF;
    reset_active_state(this);
}

void TObjEneBalClawClaw::update_move_to_target(void *p) {
    TObjEneBalClawClaw *claw = (TObjEneBalClawClaw *)p;
    switch (claw->state) {
    case -1:
        break;
    case 0:
        claw->actorFlags &= ~0x100;
        claw->requested_action = 1;
        VecCopy((Vec *)&claw->m_29c, &claw->home_position);
        claw->state = 1;
    case 1:
        claw->y_speed = 0.0f;
        VecCopy((Vec *)&claw->m_290, (const Vec *)&claw->m_2fc);
        calc_velocity_toward_destination(claw, *(Vec *)&claw->m_290, *(Vec *)&claw->m_29c,
                                         ((EnemyMoveParams *)claw->movementParameters)->min_distance);
        claw->turn_toward_direction(((EnemyMoveParams *)claw->movementParameters)->turn_speed, (Vec *)&claw->x_speed);
        move_with_wall_slide((u8 *)claw);
        claw->advance_animation();
        apply_actor_gravity(claw, NULL, 0.0f);
        break;
    }
}

int TObjEneBalClawClaw::reset_active_state(void *claw) {
    return update_if_active__15TObjEnemyCustomFl(claw, 0);
}

void TObjEneBalClawClaw::vfunc_58() {
}

void TObjEneBalClawClaw::sub_80090824() {
}

void TObjEneBalClawClaw::set_claw_flags() {
    obj_setFlags30(this, 0x04040000);
    m_388 &= 0xDFFFFFFF;
    m_388 |= 0x10000000;
}

void TObjEneBalClawClaw::sub_80090798() {
    m_388 &= 0xEFFFFFFF;
    obj_clearFlags30__8TObjBaseFUl(this, 0x06040000);
    next_action = 0xB;
}

void TObjEneBalClawClaw::update_drop(void *p) {
    TObjEneBalClawClaw *claw = (TObjEneBalClawClaw *)p;
    switch (claw->state) {
    case -1:
        break;
    case 0:
        claw->requested_action = 0;
        claw->fade.reset_color();
        claw->m_388 |= 4;
        claw->state = 1;
    case 1:
        claw->advance_animation();
        apply_actor_gravity(claw, NULL, 0.0f);
        if (claw->fade.decay_value_toward_floor() == 1) {
            claw->m_388 &= ~4;
            obj_setFlags30(claw, 0x02000000);
            claw->state = 2;
        }
        break;
    case 2:
        break;
    }
}

void TObjEneBalClawClaw::run_active_state() {
    switch (state) {
    case 0:
        fade.reset_obstruction_fade();
        m_388 |= 5;
        state = 1;
    case 1:
        if (fade.advance_toward_max() == 1) {
            m_388 &= ~5;
            reset_active_state(this);
        }
        return;
    case -1:
        m_388 &= ~4;
        break;
    }
}

void TObjEneBalClawClaw::update_chase_state() {
    switch (state) {
    case -1:
        break;
    case 0:
        actorFlags &= ~0x100;
        requested_action = 1;
        state = 1;
        m_3c8 = 0x78;
        break;
    case 1:
        if (target == NULL || --m_3c8 <= 0) {
            update_if_active(0);
            break;
        }
        y_speed = 0.0f;
        move_along_ground_avoiding_walls__15TObjEnemyCustomF3Vecff(this, *(Vec *)&((TObjChara *)target)->m_2fc, bodies,
                                                                   -0.6f, bodies->radius);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, (Vec *)&x_speed);
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        break;
    }
}

void spawn_lobby_npc_enemy(void) {
    BalClawSpawnParams binding = {lbl_805D4F20->motions, balclaw_claw_model_node_desc, 1, 7, 0};
    BmlModelEntry *models;
    models = lbl_805D4F20->models;
    TLobby::spawn_npc_enemy(0x14, models[2].model, (NJS_TEXLIST *)models[2].m_c, &binding,
                            TObjEneBalClawClaw__collision_body_template.radius, 15.0f);
}
