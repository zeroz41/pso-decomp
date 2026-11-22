#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/AreaSound.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/balclaw/TObjEneBalClawBody.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/TObjControl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/text_800870BC.h"

static const char balclaw_body_class_name_text[] = "TObjEneBalClawBody";

// The body's actions (TObjMotion::action_table, installed by the ctor).
TObjMotionAction balclaw_body_actions[12] = {
    {1, 0, 9, 0.8f, 0},
    {1, 1, 9, 0.8f, 1},
    {2, 0, 6, 0.5f, 4},
    {2, 0, 7, 0.6f, 8},
    {3, 4, 8, 0.5f, 0x10},
    {1, 5, 5, 0.8f, 0},
    {1, 5, 5, 0.8f, 1},
    {2, 5, 0, 0.6f, 4},
    {2, 5, 2, 0.7f, 8},
    {3, 5, 3, 0.6f, 0x10},
    {2, 5, 4, 0.5f, 1},
    {2, 5, 1, 0.6f, 1},
};

// Movement rows; TObjPlayer__sub_8008E934 points TObjEnemy::movementParameters at one.
BalClawMovement player_attack_param_table[2] = {
    {{150.0f, 0.5555555f, 0x400}, 30, 0, 0, 1, 0},
    {{150.0f, 0.5555555f, 0x400}, 30, 0, 0, 1, 0},
};

// The body's one collision sphere (init_collision_body_parts in the ctor).
CollisionBody balclaw_body_collision = {{0.0f, 18.0f, 0.0f}, 5.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};

u8 *lbl_805007A8[2];
u8 *lbl_805007B0[2];
u8 *lbl_805007B8[2];
u8 *lbl_805007C0[2];
const char *balclaw_body_class_name = balclaw_body_class_name_text;

extern void *tl_04;


extern "C" {
extern s32 lbl_805D5870;
extern u8 identity_matrix[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
s32 TObjPlayer__sub_800A04F0(void *);
s32 TObjPlayer__sub_800A0554(void *);
s32 check_path_obstructed(void *, void *);
TObjChara *find_active_entity_by_id(u16);
s32 fn_80090464(void *, int);
s32 minimap_render_dot(void *, int, int, int);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
s32 post_translate_matrix(void *);
void queue_destruction__7TObjectFv(void *arg0);
s32 rotate_matrix_x(s32, s32);
s32 select_enemy_destination(void *, Vec, s32);
void send_6x2F_change_player_hp(s32 arg0, s32 arg1, s32 arg2);
s32 submit_cursor_candidate(void *, int, int, f32, f32);
int update_if_active__15TObjEnemyCustomFl(void*, int);
void vec3_add_to(Vec *, Vec *);
}

// Picks this part's model and texture list (index into the Bal Claw BML models).
void TObjEneBalClawClaw::sub_80090418(s32 i) {
    model = (void *)lbl_805D4F20->models[i].model;
    texlist = (saddr)lbl_805D4F20->models[i].m_c;
}

TObjEneBalClawBody::TObjEneBalClawBody(TObject *parent, void *set_data) : TObjEneBalClaw(parent) {
    s32 i;
    m_name = balclaw_body_class_name;
    apply_set_data(set_data);
    VecCopy((Vec *)(&m_290), (const Vec *)(VecCopy((Vec *)(&m_29c), (const Vec *)(&position))));
    motion_list = lbl_805D4F20->motions;
    action_table = balclaw_body_actions;
    set_field_d8((saddr)action_table);
    init_collision_body_parts(this, &balclaw_body_collision, 1);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    initialize_enemy_photon_effect(this);
    m_3b8 = 0;
    m_3bc = 0.0f;
    clear_attack_flag();
    if (*(s16 *)((s8 *)set_data + 0xA) != 0) {
        sub_800C7860();
    }
    m_3ac = 25.0f;
    m_3b0 = 40.0f;
    m_3b4 = m_3ac;
    m_3d8 = 4;
    for (i = 0; i < 4; i++) {
        child_ids[i] = 0xFFFF;
    }
    this->set_form(1);
    bind_enemy_combat_stats(lbl_805007A8[0], lbl_805007B0[0], lbl_805007B8[0]);
    effects[0] = NULL;
    effects[1] = NULL;
    effects[2] = NULL;
    effects[3] = NULL;
    clear_lobby_object_state();
}

TObjEneBalClawBody::~TObjEneBalClawBody() {
    s32 i;
    TObject *child;
    free_collision_body_parts(this);
    if (effects[0] != NULL) {
        effects[0]->queue_destruction();
    }
    if (effects[1] != NULL) {
        effects[1]->queue_destruction();
    }
    if (effects[2] != NULL) {
        effects[2]->queue_destruction();
    }
    if (effects[3] != NULL) {
        effects[3]->queue_destruction();
    }
    if (get_flag_0x388_b24() != 0) {
        for (i = 0; i < m_3d8; i++) {
            child = find_entity_by_id(child_ids[i]);
            if (child != NULL) {
                child->queue_destruction();
            }
        }
    }
}

void *TObjEneBalClawBody::create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneBalClawBody(control, set_data);
}

void TObjEneBalClawBody::run_task() {
    f32 lift;
    f32 center_y;
    CollisionBody *body;

    TObjEneBalClaw__sub_8008D68C();
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_8008DC90();
        sub_8008FC0C();
        return;
    }
    if ((m_388 & 0x02000000) && get_flag_0x388_b24() == 0) {
        update_if_active(2);
    } else {
        sub_8008FC10();
    }
    if (mode != (s32)next_action) {
        if ((s32)state != -1) {
            state = -1;
            sub_8008FF50();
        }
        mode = next_action;
        state = 0;
    }
    sub_8008FF50();
    update_wobble();
    update_claw_angle();
    VecCopy(&body_center, &position);
    center_y = body_center.y;
    body_center.y = center_y + (m_3b4 + m_3bc);
    lift = m_3b4;
    body = bodies;
    body->offset.y = lift + m_3bc;
    submit_cursor_candidate(this, -1, (saddr)body, lift, center_y);
    minimap_render_dot((u8 *)&position, -0x5DB4, 1, 0);
}

void TObjEneBalClawBody::sub_8008FF50() {
    switch (mode) {
    case 0:
        update_dragon_boss_state();
        return;
    case 1:
        this->sub_8008FAD0();
        return;
    case 2:
        this->sub_8008F1DC();
        return;
    case 9:
        this->sub_8008EDE8();
        return;
    case 4:
        this->sub_8008F910();
        return;
    case 5:
        this->run_death_sequence();
        return;
    case 7:
        this->sub_8008EC3C();
        return;
    case 10:
        this->sub_8008E310();
        return;
    case 11:
        this->sub_8008E254();
        return;
    case 12:
        this->update_move_to_target();
        return;
    case 8:
        this->sub_8008DD14();
        break;
    }
}

void TObjEneBalClawBody::sub_8008FC10() {
    f32 d;
    s32 old;
    if (mode != 0 && mode != 8) {
        m_3d4++;
    }
    if (get_flag_0x388_b24() != 0) {
        switch (mode) {
        case 0:
        case 1:
            if (m_3d4 > 0x708 || m_3da >= 2) {
                update_if_active(0xB);
                return;
            }
            break;
        }
        if (is_actor_cadence_frame(0x1E) != 0) {
            find_target_in_range(250.0f);
        }
        switch (mode) {
        case 0:
        case 8:
            if (target != NULL) {
                update_if_active(1);
                m_38c = 2;
            } else {
                sub_800C73F4();
            }
            break;
        case 1:
            if (target != NULL) {
                d = xz_distance_squared(&((TObjChara *)target)->position, &position);
                old = m_38c;
                switch (old) {
                case 0:
                    if (d > 3600.0f) {
                        m_38c = 1;
                    }
                    break;
                case 1:
                    if (d < 1600.0f) {
                        m_38c = 0;
                    } else if (d > 14400.0f) {
                        m_38c = 2;
                    }
                    break;
                case 2:
                    if (d < 10000.0f) {
                        m_38c = 1;
                    }
                    break;
                }
                if (old != m_38c) {
                    switch (m_38c) {
                    case 0:
                        update_if_active(9);
                        break;
                    case 1:
                        clear_attack_flag();
                        break;
                    case 2:
                        set_attack_distance_flag();
                        break;
                    }
                }
            } else {
                update_if_active(8);
            }
            break;
        }
    } else {
        if (is_actor_cadence_frame(0x1E) != 0 && mode != 2) {
            find_target_in_range(250.0f);
        }
        switch (mode) {
        case 0:
            if (is_actor_cadence_frame(0x1E) != 0 && target == NULL) {
                update_if_active(0xA);
                return;
            }
            break;
        case 1:
        case 12:
            if (m_3d4 > 0x708) {
                update_if_active(0xA);
                return;
            }
            break;
        }
        switch (mode) {
        case 0:
        case 8:
            if (target != NULL) {
                update_if_active(0xC);
            } else {
                sub_800C73F4();
            }
            break;
        case 1:
            if (target == NULL) {
                update_if_active(8);
            }
            break;
        }
    }
}

void TObjEneBalClawBody::sub_8008FC0C() {
}

void TObjEneBalClawBody::sub_8008FAD0() {
    TObjEneBalClawBody *body = this;
    s16 v;
    switch (body->state) {
    case 0:
        body->actorFlags &= 0xFBFFFEFF;
        body->sub_8004292C();
        v = 6;
        if (body->m_388 & 0x01000000) {
            v = 1;
        }
        body->requested_action = v;
        body->state = 1;
        if (body->target != NULL) {
            VecCopy((Vec *)&body->m_29c, &((TObjChara *)body->target)->body_center);
        }
        break;
    case 1:
        if (body->target == NULL) {
            body->reset_enemy_state();
            break;
        }
        play_persistent_sound(0x4003B235, (saddr)body, (uaddr)&body->position, 0, 0);
        body->y_speed = 0.0f;
        {
            Vec pos = ((TObjChara *)body->target)->body_center;
            ((s32 (*)(void *, Vec *, int, f32))update_enemy_wander_move)(body, &pos, 1, ((EnemyMoveParams *)body->movementParameters)->min_distance);
        }
        body->turn_toward_direction(((EnemyMoveParams *)body->movementParameters)->turn_speed, (Vec *)&body->x_speed);
        body->advance_animation();
        apply_actor_gravity(body, NULL, 0.0f);
        ((TObjPlayer *)body)->update_collisions();
        break;
    case -1:
        break;
    }
}

void TObjEneBalClawBody::sub_8008F910() {
    TObjEneBalClawBody *body = this;
    s32 next_mode;
    s32 percent;
    switch (body->state) {
    case -1:
        break;
    case 0:
        body->actorFlags &= ~0x200000;
        body->requested_action = body->get_flag_0x388_b24() != 0 ? 3 : 8;
        body->state = 1;
    case 1: {
        body->advance_animation();
        body->y_speed = 0.0f;
        Vec v = body->body_center;
        v.x += body->x_speed;
        v.z += body->m_310;
        if (check_path_obstructed(body, &v) == 0) {
            move_with_wall_slide((u8 *)body);
        } else {
            body->x_speed = body->m_310 = 0.0f;
        }
        body->x_speed *= 0.9f;
        body->m_310 *= 0.9f;
        apply_actor_gravity(body, NULL, 0.0f);
        ((TObjPlayer *)body)->update_collisions();
        if (body->action_flags != 8U) {
            next_mode = 0;
            body->referenceHp = body->hp;
            body->actorFlags &= ~0x200;
            body->m_388 &= ~1;
            if (body->get_flag_0x388_b24() == 0) {
                percent = fn_80090464(body, 0);
                if (percent <= 0) {
                    percent = 0xA;
                }
                if (body->hp <= (body->hpmax * percent) / 100) {
                    if (!(body->m_388 & 0x02000000)) {
                        body->targetId = body->attacker_id;
                        body->m_388 |= 0x02000000;
                    }
                    next_mode = 2;
                }
            }
            body->update_if_active(next_mode);
        }
        break;
    }
    }
}

void TObjEneBalClawBody::run_death_sequence() {
    TObjEneBalClawBody *body = this;
    s32 i;
    TObjEnemy *claw;
    switch (body->state) {
    case 0:
        reinterpret_cast<TObjPlayer *>(this)->refresh_lobby_state();
        body->m_388 &= ~0x20000;
        if (body->get_flag_0x388_b24() != 0) {
            body->requested_action = 4;
            body->state = 1;
            for (i = 0; i < body->m_3d8; i++) {
                claw = (TObjEnemy *)find_entity_by_id(body->child_ids[i]);
                if (claw != NULL) {
                    claw->send_entity_set_flags();
                    queue_destruction__7TObjectFv(claw);
                }
            }
        } else {
            body->requested_action = 9;
            body->y_speed = body->m_3b4 / 11.666666f;
            body->state = 2;
        }
        play_sound_effect(0x4003AD37, (u8 *)&body->position, 0, 0);
        break;
    case 1:
        body->advance_animation();
        if (body->frame >= 20.0f) {
            body->state = 3;
        }
        break;
    case 2:
        body->advance_animation();
        if (body->frame >= 10.0f) {
            body->m_3b4 -= body->y_speed;
            if (body->m_3b4 <= 0.0f) {
                body->m_3b4 = 0.0f;
                body->state = 3;
            }
        }
        break;
    case 3:
        TObjPlayer__sub_800A04F0(&body->fade);
        fn_800D911C(&body->body_center);
        body->m_388 |= 4;
        body->state = 4;
    case 4:
        body->advance_animation();
        if ((&body->fade)->decay_value_toward_floor() == 1) {
            TObjPlayer::apply_effect_variant_a((saddr)&body->position, 0);
            body->send_entity_set_flags();
            queue_destruction__7TObjectFv(body);
        }
        break;
    }
}

void TObjEneBalClawBody::sub_8008F1DC() {
    TObjEneBalClawBody *body = this;
    switch (body->state) {
    case 0:
        if (body->get_flag_0x388_b24() != 0) {
            body->reset_enemy_state();
            return;
        }
        if (body->attacker_id < 0x1000) {
            body->targetId = body->attacker_id;
            body->target = (u8 *)find_active_entity_by_id(body->targetId);
            if (body->target != NULL && (((TObjChara *)body->target)->actorFlags & 0x04000800)) {
                body->targetId = 0xFFFF;
                body->target = NULL;
            }
        } else {
            body->find_target_in_range(250.0f);
        }
        if (body->targetId != 0xFFFF) {
            body->m_388 &= ~0x20000;
            body->requested_action = 6;
            body->state = 1;
        } else {
            body->run_idle_action();
        }
        break;
    case 1:
        if (body->target == NULL) {
            body->reset_enemy_state();
        } else {
            body->y_speed = 0.0f;
            calc_velocity_toward_destination(body, body->body_center, ((TObjChara *)body->target)->body_center, 0.7f);
            {
                Vec n1 = body->body_center;
                n1.x += body->x_speed;
                n1.z += body->m_310;
                if (check_path_obstructed(body, &n1) == 0) {
                    move_with_wall_slide((u8 *)body);
                }
            }
            body->turn_toward_direction(((EnemyMoveParams *)body->movementParameters)->turn_speed, (Vec *)&body->x_speed);
            body->m_3c0 = xz_distance_squared(&body->body_center, &((TObjChara *)body->target)->body_center);
            if (body->m_3c0 <= ((AttackParams *)body->m_318)->get_attack_range() * ((AttackParams *)body->m_318)->get_attack_range()) {
                body->requested_action = 7;
                body->state = 2;
                body->effects[2] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&body->body_center, body->m_3f8, 0x12B, 2);
                body->effects[2]->enable();
                body->effects[3] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&body->body_center, body->m_3f8, 0x12C, 2);
                body->effects[3]->enable();
            }
        }
        break;
    case 2:
        push_matrix_from(identity_matrix);
        post_translate_matrix(&body->body_center);
        rotate_matrix_y(0, body->rotation_y);
        body->calc_joint_matrices(body->frame);
        pop_matrix();
        body->get_anim_node_position(8, &body->m_3ec);
        body->m_3f8[0] = 0;
        body->m_3f8[1] = body->rotation_y + 0x4000;
        body->m_3f8[2] = -0x4000;
        if (body->frame >= 9.0f && body->frame < 17.0f) {
            body->effects[2]->set_position(&body->m_3ec);
            body->effects[2]->set_direction(body->m_3f8);
        } else {
            body->effects[2]->enable();
        }
        if (body->frame >= 12.0f && body->frame < 17.0f) {
            body->effects[3]->set_position(&body->m_3ec);
            body->effects[3]->set_direction(body->m_3f8);
        } else {
            body->effects[3]->enable();
        }
        body->y_speed = 0.0f;
        calc_velocity_toward_destination(body, body->body_center, ((TObjChara *)body->target)->body_center, 0.7f);
        {
            Vec n2 = body->body_center;
            n2.x += body->x_speed;
            n2.z += body->m_310;
            if (check_path_obstructed(body, &n2) == 0) {
                move_with_wall_slide((u8 *)body);
            }
        }
        body->turn_toward_direction(((EnemyMoveParams *)body->movementParameters)->turn_speed, (Vec *)&body->x_speed);
        if (body->is_passing_frame(10.0f) != 0) {
            play_sound_effect(0x4003B034, &body->position, 0, 0);
            if (((TObjChara *)body->target)->select_melee_contact_body(body, 1.0f) != 0) {
                ((TObjChara *)body->target)->receive_physical_attack(body, 1.0f);
                ((TObjChara *)body->target)->apply_knockback_from_attacker((u8 *)body, 3.0f);
                if (!(((TObjChara *)body->target)->actorFlags & 0x800) && ((TObjChara *)(body->target))->get_actor_hp() > 0) {
                    send_6x2F_change_player_hp(body->entity_id, body->targetId, 1);
                }
            }
        }
        if (body->action_flags != 4) {
            obj_setFlags30(body, 0x800);
        }
        break;
    case -1:
        if (body->effects[2] != NULL) {
            queue_destruction__7TObjectFv(body->effects[2]);
            body->effects[2] = NULL;
        }
        if (body->effects[3] != NULL) {
            queue_destruction__7TObjectFv(body->effects[3]);
            body->effects[3] = NULL;
        }
        body->m_388 |= 0x20000;
        break;
    }
    body->advance_animation();
    apply_actor_gravity(body, NULL, 0.0f);
    ((TObjPlayer *)body)->check_object_collisions();
    check_enemy_body_collisions(body);
}

void TObjEneBalClawBody::sub_8008EDE8() {
    TObjEneBalClawBody *body = this;
    switch (body->state) {
    case 0:
        if (body->get_flag_0x388_b24() == 0) {
            body->reset_enemy_state();
            return;
        }
        body->find_target_in_range(250.0f);
        if (body->targetId != 0xFFFF) {
            body->requested_action = 1;
            body->state = 1;
            if (select_enemy_destination(body, body->body_center, 1) != 0) {
                ((void (*)(void *, Vec))copy_position_if_valid__10TObjPlayerFii)(body, body->body_center);
            }
        } else {
            body->reset_enemy_state();
        }
        break;
    case 1:
        if (body->target == NULL) {
            body->reset_enemy_state();
        } else {
            body->y_speed = 0.0f;
            calc_velocity_toward_destination(body, body->body_center, ((TObjChara *)body->target)->body_center, 0.7f);
            {
                Vec n1 = body->body_center;
                n1.x += body->x_speed;
                n1.z += body->m_310;
                if (check_path_obstructed(body, &n1) == 0) {
                    move_with_wall_slide((u8 *)body);
                }
            }
            body->turn_toward_direction(((EnemyMoveParams *)body->movementParameters)->turn_speed, (Vec *)&body->x_speed);
            body->m_3c0 = xz_distance_squared(&body->body_center, &((TObjChara *)body->target)->body_center);
            if (body->m_3c0 <= ((AttackParams *)body->m_318)->get_attack_range() * ((AttackParams *)body->m_318)->get_attack_range()) {
                body->requested_action = 2;
                body->state = 2;
                play_sound_effect(0x4003B033, &body->position, 0, 0);
            }
        }
        break;
    case 2:
        if (body->target == NULL) {
            body->reset_enemy_state();
        } else {
            body->y_speed = 0.0f;
            calc_velocity_toward_destination(body, body->body_center, ((TObjChara *)body->target)->body_center, 0.7f);
            move_with_wall_slide((u8 *)body);
            {
                Vec n2 = body->body_center;
                n2.x += body->x_speed;
                n2.z += body->m_310;
                if (check_path_obstructed(body, &n2) == 0) {
                    move_with_wall_slide((u8 *)body);
                }
            }
            if (body->is_passing_frame(10.0f) != 0) {
                if (((TObjChara *)body->target)->select_melee_contact_body(body, 1.0f) != 0) {
                    if (body->random_ratio() <= 0.1f) {
                        DirectAttackPayload q = {0xF, 0.0f};
                        ((TObjChara *)body->target)->receive_direct_attack(body, q, 0, -1, -1);
                    }
                    ((TObjChara *)body->target)->receive_physical_attack(body, 1.0f);
                    ((TObjChara *)body->target)->apply_knockback_from_attacker((u8 *)body, 3.0f);
                }
                body->m_3da++;
            }
            if (body->action_flags != 4) {
                body->reset_enemy_state();
            }
        }
        break;
    case -1:
        break;
    }
    body->advance_animation();
    apply_actor_gravity(body, NULL, 0.0f);
    ((TObjPlayer *)body)->update_collisions();
}

void TObjPlayer::set_visibility_flags_by_count(void *arg0, s32 arg1) {
    s32 i;
    s32 j;
    NJS_OBJECT *e;
    for (i = 0; i < arg1; i++) {
        for (j = 0; (e = balclaw_arm_part_models[i][j]) != NULL; j++) {
            e->evalflags &= ~NJD_EVAL_HIDE;
        }
    }
    for (; i < 4; i++) {
        for (j = 0; (e = balclaw_arm_part_models[i][j]) != NULL; j++) {
            e->evalflags |= NJD_EVAL_HIDE;
        }
    }
}

void TObjEneBalClawBody::sub_8008EC3C() {
    TObjEneBalClawBody *body = this;
    s32 cleared;
    s32 flags;
    switch (body->state) {
    case 0:
        body->m_388 |= 4;
        body->actorFlags |= 0x04000000;
        body->requested_action = (body->m_388 & 0x01000000) ? 0 : 5;
        play_area_se_with_particle(&body->position);
        TObjPlayer__sub_800A0554(&body->fade);
        body->state = 1;
    case 1:
        body->advance_animation();
        apply_actor_gravity(body, NULL, 0.0f);
        if ((&body->fade)->advance_toward_max() == 1) {
            flags = body->m_388;
            cleared = flags & ~5;
            body->m_388 = cleared;
            body->state = -1;
            body->reset_enemy_state();
        }
        return;
    case -1:
        body->m_388 &= ~5;
        body->actorFlags &= 0xFBFFFFFF;
        break;
    }
}

void TObjEneBalClawBody::update_dragon_boss_state() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        requested_action = (m_388 & 0x01000000) ? 0 : 5;
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        return;
    case -1:
        actorFlags &= ~0x40000;
        return;
    }
}

#pragma push
#pragma opt_propagation off
void TObjEneBalClawBody::set_form(s32 form) {
    Vec a;
    Vec b;
    s32 angA;
    s32 angB;
    s32 i;
    s32 id;
    saddr id2;
    s32 n;
    s32 k;
    u8 *ent;
    s32 j;
    if (form == 1) {
        this->m_388 |= 0x01000000;
        this->set_param(0x28);
        this->requested_action = 0;
        ((TObjEneBalClawClaw *)this)->sub_80090418(1);
        this->m_3da = 0;
        this->clear_all_status_effects();
    } else {
        this->m_388 &= ~0x01000000;
        this->set_param(0x27);
        this->requested_action = 5;
        ((TObjEneBalClawClaw *)this)->sub_80090418(0);
        this->clear_all_status_effects();
        if (!(this->m_388 & 0x40000)) {
            this->hp = this->hp / (this->m_3d8 + 1);
            if (this->hp <= 0) {
                this->hp = 1;
            }
            this->referenceHp = this->hp;
            if (this->set_entry != NULL) {
                this->m_388 |= 0x40000;
                for (i = 0; i < 4; i++) {
                    id = this->entity_id + i;
                    id2 = this->set_index + i;
                    id++;
                    id2++;
                    this->calc_slot_offset_position(i, &a, &angA);
                    TObjEneBalClawClaw::create_from_body(this, id, id2, &a, angA, this->hp);
                }
            }
        } else {
            n = 0;
            for (k = 0; k < this->m_3d8; k++) {
                ent = get_enemy_entity(this->child_ids[k]);
                if (ent != NULL) {
                    this->calc_slot_offset_position(k, &b, &angB);
                    TObjEneBalClawClaw__sub_80090A10((TObjEneBalClawClaw *)ent, &b, angB, this->hp);
                    n++;
                }
            }
            if (n > 0) {
                this->hp = this->hp / (n + 1);
                for (j = 0; j < this->m_3d8; j++) {
                    if ((ent = get_enemy_entity(this->child_ids[j])) != NULL) {
                        ((TObjPlayer *)ent)->set_hp_clamped(this->hp);
                    }
                }
            }
        }
        this->m_3d8 = 0;
    }
    this->set_field_b8(this->requested_action);
    this->movementParameters = &player_attack_param_table[form];
    this->sub_8008DC90();
    this->variant = form;
    this->m_3d4 = 0;
}
#pragma pop

void TObjEneBalClawBody::render() {
    s32 shadow;
    s32 detail;
    s32 visible;

    if (!(actorFlags & 0x02000000)) {
        saved_model_render_flags = model_render_flags;
        detail = classify_actor_view_detail(150.0f, 400.0f, 30.0f);
        if (detail != 0) {
            shadow = 1;
            TObjFish::set_global_param(texlist);
            select_actor_lighting((saddr)this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                TObjPlayer::set_visibility_flags_by_count(this, 4);
                post_translate_matrix((u8 *)&position);
                rotate_matrix_x(0, rotation_x);
                rotate_matrix_y(0, rotation_y);
                draw_chunk_object(model);
            } else {
                TObjPlayer::set_visibility_flags_by_count(this, m_3d8);
                translate_matrix(0, 0.0f, m_3b4 + m_3bc, 0.0f);
                post_translate_matrix((u8 *)&position);
                rotate_matrix_x(0, rotation_x);
                rotate_matrix_y(0, rotation_y);
                if (m_388 & 4) {
                    if ((&fade)->has_visible_opacity() != 0) {
                        (&fade)->set_flags_and_apply_damage_color();
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
                        (&fade)->clear_flag_and_notify();
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
            model_render_flags = saved_model_render_flags;
            render_scaled(shadow);
        }
    }
}

void TObjEneBalClawBody::run_attack_action() {
    update_if_active(get_flag_0x388_b24() ? 9 : 2);
}

void TObjEneBalClawBody::sub_8008E310() {
    TObjEneBalClawBody *body = this;
    s32 all;
    s32 cnt;
    TObjEneBalClawClaw *claw;
    f32 lim;
    switch (body->state) {
    case 0:
        if (body->get_flag_0x388_b24() != 0) {
            body->reset_enemy_state();
            return;
        }
        body->m_3d4 = 0;
        if (body->sub_8008E098() == 0) {
            body->reset_enemy_state();
            return;
        }
        body->m_388 |= 1;
        body->m_388 &= ~0x04020000;
        body->m_384 = 0x258;
        body->state = 1;
        body->requested_action = 5;
        body->effects[0] = create_particle_emitter(&body->body_center, 0x128);
        break;
    case 1:
        body->effects[0]->set_position(&body->body_center);
        body->advance_animation();
        apply_actor_gravity(body, NULL, 0.0f);
        all = 1;
        cnt = 0;
        lim = 225.0f;
        for (s32 i = 0; i < body->m_3d8; i++) {
            claw = (TObjEneBalClawClaw *)find_entity_by_id(body->child_ids[i]);
            if (claw != NULL) {
                cnt++;
                if (claw->m_3c0 > lim) {
                    all = 0;
                }
            } else {
                body->child_ids[i] = 0xFFFF;
            }
        }
        if (--body->m_384 <= 0 || cnt == 0) {
            body->m_388 &= ~1;
            body->reset_enemy_state();
            return;
        }
        if (all == 1) {
            for (s32 i = 0; i < body->m_3d8; i++) {
                TObjEneBalClawClaw *claw2 = (TObjEneBalClawClaw *)find_entity_by_id(body->child_ids[i]);
                if (claw2 != NULL) {
                    claw2->set_claw_flags();
                    body->hp += ((TObjChara *)claw2)->get_actor_hp();
                }
            }
            body->effects[1] = create_particle_emitter(&body->body_center, 0x12A);
            body->effects[1]->enable();
            body->requested_action = 0xB;
            body->m_388 |= 0x04000000;
            body->state = 2;
        }
        break;
    case 2:
        body->effects[0]->set_position(&body->body_center);
        body->advance_animation();
        apply_actor_gravity(body, NULL, 0.0f);
        if (body->frame < 9.0f) {
            body->effects[1]->enable();
        } else {
            body->effects[1]->clear_active_flag();
            body->effects[1]->set_position(&body->body_center);
        }
        if (body->requested_action != 0xB) {
            queue_destruction__7TObjectFv(body->effects[0]);
            body->effects[0] = NULL;
            spawn_particle_effect(&body->body_center, 0x129);
            body->set_form(1);
            body->advance_animation();
            body->m_388 &= ~0x04000000;
            body->timer = 0x1E;
            body->state = 3;
            play_sound_effect(0x4003AD30, &body->position, 0, 0);
        }
        break;
    case 3:
        body->effects[1]->set_position(&body->body_center);
        body->advance_animation();
        apply_actor_gravity(body, NULL, 0.0f);
        if (--body->timer <= 0) {
            body->m_388 &= ~1;
            body->reset_enemy_state();
        }
        break;
    case -1:
        if (body->m_388 & 0x04000000) {
            body->set_form(1);
            body->advance_animation();
        }
        if (body->get_flag_0x388_b24() == 0) {
            for (s32 i = 0; i < body->m_3d8; i++) {
                claw = (TObjEneBalClawClaw *)find_entity_by_id(body->child_ids[i]);
                if (claw != NULL) {
                    claw->clear_flag();
                }
            }
        }
        body->m_388 |= 0x20000;
        if (body->effects[0] != NULL) {
            queue_destruction__7TObjectFv(body->effects[0]);
            body->effects[0] = NULL;
        }
        if (body->effects[1] != NULL) {
            queue_destruction__7TObjectFv(body->effects[1]);
            body->effects[1] = NULL;
        }
        break;
    }
}

void TObjEneBalClawBody::sub_8008E254() {
    TObjEneBalClawBody *body = this;
    switch (body->state) {
    case -1:
        break;
    case 0:
        if (body->get_flag_0x388_b24() == 0) {
            body->reset_enemy_state();
            return;
        }
        body->m_3d4 = 0;
        body->set_form(0);
        body->timer = 0x1E;
        body->state = 1;
        return;
    case 1:
        body->advance_animation();
        apply_actor_gravity(body, NULL, 0.0f);
        body->timer--;
        if (body->timer <= 0) {
            body->reset_enemy_state();
        }
        return;
    }
}

void TObjEneBalClawBody::calc_slot_offset_position(s32 slot, Vec *out, s32 *angle_out) {
    TObjEneBalClawBody *self = this;
    s32 angle;
    push_matrix();
    angle = (s32)(182.04445f * (f32)(slot * 0x5A + 0x2D));
    *angle_out = self->rotation_y + angle;
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 13.0f;
    set_matrix_identity(0);
    rotate_matrix_y(0, angle);
    matrix_mult_vec(0, out, out);
    vec3_add_to(out, &self->position);
    pop_matrix();
}

s32 TObjEneBalClawBody::sub_8008E098() {
    TObjEneBalClawBody *self = this;
    s32 i;
    TObjEneBalClawClaw *p;
    s32 j;
    self->m_3d8 = 0;
    for (i = registered_player_count; i < registered_player_count + lbl_805D5870; i++) {
        p = (TObjEneBalClawClaw *)TObjPlayer::get_player_data(i);
        if (p != NULL && ((TWindowLockOn *)p)->get_target_id() == 0x26 &&
            self->room == p->room && p->check_active() != 0) {
            self->child_ids[self->m_3d8++] = get_entity_id(p);
            if (self->m_3d8 >= 4) {
                break;
            }
        }
    }
    for (j = 0; j < self->m_3d8; j++) {
        TObjEneBalClawClaw *claw = static_cast<TObjEneBalClawClaw *>(find_entity_by_id(self->child_ids[j]));
        claw->enter_hit_state(self->entity_id);
    }
    return self->m_3d8;
}

void TObjEneBalClawBody::update_move_to_target() {
    TObjEneBalClawBody *self = this;
    switch (self->state) {
    case -1:
        break;
    case 0: {
        self->actorFlags &= ~0x100;
        self->requested_action = self->get_flag_0x388_b24() != 0 ? 1 : 6;
        Vec d = self->body_center;
        subtract_vector(&d, &((TObjChara *)self->target)->body_center);
        self->pick_open_direction((f32 *)&d, 60.0f, 30.0f);
        self->state = 1;
        break;
    }
    case 1: {
        if (self->target == NULL) {
            reset_enemy_state();
            break;
        }
        if (this->is_actor_cadence_frame(0x5A) != 0) {
            Vec d2 = self->body_center;
            subtract_vector(&d2, &((TObjChara *)self->target)->body_center);
            self->pick_open_direction((f32 *)&d2, 60.0f, 30.0f);
        }
        VecCopy((Vec *)&self->m_290, &self->body_center);
        calc_velocity_toward_destination(self, *(Vec *)&self->m_290, *(Vec *)&self->m_29c, ((EnemyMoveParams *)self->movementParameters)->min_distance);
        self->turn_toward_direction(((EnemyMoveParams *)self->movementParameters)->turn_speed, (Vec *)&self->x_speed);
        Vec v = self->body_center;
        v.x += self->x_speed;
        v.z += self->m_310;
        if (check_path_obstructed(self, &v) == 0) {
            move_with_wall_slide((u8 *)self);
        }
        self->advance_animation();
        apply_actor_gravity(self, NULL, 0.0f);
        ((TObjPlayer *)self)->update_collisions();
        break;
    }
    }
}

void TObjEneBalClawBody::sub_8008DD14() {
    TObjEneBalClawBody *self = this;
    s16 mode;
    switch (self->state) {
    case 0:
        self->actorFlags &= 0xFFFBFEFF;
        mode = 6;
        if (self->m_388 & 0x01000000) {
            mode = 1;
        }
        self->requested_action = mode;
        self->state = 1;
        VecCopy((Vec *)&self->m_29c, (const Vec *)&self->home_position);
        break;
    case 1: {
        self->y_speed = 0.0f;
        VecCopy((Vec *)&self->m_290, &self->body_center);
        calc_velocity_toward_destination(self, *(Vec *)&self->m_290, *(Vec *)&self->m_29c, ((EnemyMoveParams *)self->movementParameters)->min_distance);
        self->turn_toward_direction(((EnemyMoveParams *)self->movementParameters)->turn_speed, (Vec *)&self->x_speed);
        Vec v = self->body_center;
        v.x += self->x_speed;
        v.z += self->m_310;
        if (check_path_obstructed(self, &v) == 0) {
            move_with_wall_slide((u8 *)self);
        }
        if (xz_distance_squared(&self->position, &self->home_position) < 100.0f) {
            self->reset_enemy_state();
        }
        self->advance_animation();
        apply_actor_gravity(self, NULL, 0.0f);
        break;
    }
    case -1:
        break;
    }
}

int TObjEneBalClawBody::reset_enemy_state() {
    return update_if_active__15TObjEnemyCustomFl(this, 0);
}

void TObjEneBalClawBody::run_idle_action() {
    if (xz_distance_squared(&position, &home_position) > 100.0f) {
        update_if_active(8);
        return;
    }
    update_if_active(0);
}

void TObjEneBalClawBody::sub_8008DC90() {
}

void TObjEneBalClawClaw::spawn_child_enemy() {
    NpcAnimationBinding params = { reinterpret_cast<BmlMotionEntry *>(lbl_805D4F20->motions), reinterpret_cast<TObjMotionAction *>(balclaw_body_actions), 0, 1, 12 };
    NpcModelRegistry::register_animated_chunk(0x13, reinterpret_cast<void *>(lbl_805D4F20->models[1].model), reinterpret_cast<void *>(lbl_805D4F20->models[1].m_c), &params,
                            balclaw_body_collision.radius, 15.0f);
}
