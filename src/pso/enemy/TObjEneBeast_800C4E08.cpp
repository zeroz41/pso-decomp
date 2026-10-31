#include "pso/player/PlayerAttackParams.h"
#include "types.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneRe2Flower_EffCurse3.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjEneRe2Flower_Bomb.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"

#define BEAST_HUNTER_NEAR_EXIT_DISTANCE_SQ 10000.0f
#define BEAST_HUNTER_NEAR_ENTER_DISTANCE_SQ 2500.0f
#define BEAST_OTHER_NEAR_EXIT_DISTANCE_SQ 22500.0f
#define BEAST_OTHER_NEAR_ENTER_DISTANCE_SQ 10000.0f
#define BEAST_DEATH_EFFECT_FRAME 16.0f
#define BEAST_DEATH_SLIDE_FRAME_COUNT 30.0f
#define BEAST_ATTACK_HIT_FRAME 7.0f
#define BEAST_ATTACK_KNOCKBACK 3.0f
#define BEAST_HOME_CHASE_FRAME_COUNT 60.0f
#define BEAST_ANGLE_UNITS_PER_RADIAN 10430.38043493439
#define BEAST_DEATH_SLIDE_FRAME_SCALE 0.5f
#define BEAST_HORIZONTAL_SPEED_DAMPING 0.5f
#define BEAST_ATTACK_CHOICE_THRESHOLD 0.5f
#define BEAST_TARGET_HOLD_BASE_FRAMES 150.0f
#define BEAST_DESTINATION_TIMEOUT_FRAMES 150.0f
#define BEAST_GROUP_APPROACH_DISTANCE_SQ 22500.0f
#define BEAST_ANIMATION_START_FRAME 0.0f
#define BEAST_GROUND_HEIGHT_OFFSET 0.0f
#define BEAST_TARGET_HOLD_BASE_SCALE 1.0f
#define BEAST_ATTACK_SCALE 1.0f
#define BEAST_FRAME_INCREMENT 1.0f
#define BEAST_ZERO_SPEED 0.0f
#define BEAST_MIN_WANDER_RANGE 0.0f
#define BEAST_CORPSE_RETIRE_START 0.0f
#define BEAST_CORPSE_RETIRE_STEP 0.1f
#define BEAST_CORPSE_RETIRE_THRESHOLD (-20.0f)
#define BEAST_DEFAULT_MOVEMENT_RATE 0.8f
#define BEAST_NEAR_TARGET_MOVEMENT_RATE 0.4f
#define BEAST_ZERO_VECTOR_COMPONENT 0.0f

struct Sub350_800C57F0 { char pad[8]; void *p8; };
struct Ctl_800C5B10 { u8 pad[8]; void *field_8; };

extern "C" {
s32 check_path_obstructed(void *, void *);
f32 get_collision_body_radius(void *, s32);
s32 pop_matrix();
f32 fabs_float(f32);
f64 atan2_float(f32, f32);
s32 link_chain_nodes__10TObjPlayerFPvPvPv(void *, void *, void *);
f32 horizontal_distance_squared(void *, void *);
s32 approach_angle_limited(int, int, int);
s32 project_actor_to_ground(void *, void *, int);
s32 minimap_render_dot(void *, int, int, int);
s32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 subtract_vector(void *, void *);
s32 push_matrix_from(void *);
s32 pop_matrices(int);
extern Vec scratch_vec;
extern Vec lbl_8050BF00;
extern u8 identity_matrix[];

s32 apply_actor_gravity(void *, int, f32);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 obj_testFlags30__14TObjCollidableFUl(void *, int);
void *spawn_particle_effect(void *pos, s32 id);
int unlink_enemy_group_relations__13TUnk_80493450Fv(void*);
int send_entity_set_flags__9TObjEnemyFv(void*);
s32 obj_setFlags30(void *, s32);
s32 update_movement_status__9TObjCharaFv(void *);
s32 submit_cursor_candidate(void *, int);
s32 update_action_hold_status__9TObjCharaFv(void *);
u16 get_entity_id(void *);
int queue_destruction__7TObjectFv(void*);
f32 random_ratio__9TObjCharaFv(s32 arg0);
s32 enemy_move_toward(void *, s32, void *, int, f32);
s32 test_elt_flag__13TUnk_80493450Fll(void *, int, int);
s32 enemy_turn_toward_dest(void *, s32);
s32 get_current_floor(void);
u8 *get_enemy_entity(u16 arg0);
TObjPlayer *get_player_by_client_id(s32 i);
f32 enemy_backstep_from_point(void *, void *, f32);
s32 angle_difference_abs(s32, s32);
void TUnk_80493450::sub_800C4E08() {
    if (obj_testFlags30__14TObjCollidableFUl(this, 0x100000) != 0) {
        this->unk_394 = this->unk_39C;
        this->play_speed = this->unk_3A4;
        return;
    }
    this->unk_394 = this->m_398;
    this->play_speed = this->m_3a0;
}

s32 TUnk_80493450::update_target_near_flag() {
    f32 temp_f31;
    u8 *temp_r0;
    u8 *temp_r31;
    temp_r0 = this->target;
    if (temp_r0 == NULL) {
        obj_clearFlags30(0x100000);
        return;
    }
    if ((get_entity_id(temp_r0) < 0x1000U) && (this->is_actor_cadence_frame(0x1E) != 0)) {
        temp_r31 = this->target;
        temp_f31 = horizontal_distance_squared(temp_r31 + 0x38, (void *) ((u8 *)this + 0x38));
        switch (((TObjPlayer *)temp_r31)->class_flags & CLASS_FLAG_TYPE_MASK) {
        case CLASS_FLAG_HUNTER:
            if (obj_testFlags30__14TObjCollidableFUl(this, 0x100000) != 0) {
                if (BEAST_HUNTER_NEAR_EXIT_DISTANCE_SQ < temp_f31) {
                    obj_clearFlags30(0x100000);
                }
            } else if (temp_f31 < BEAST_HUNTER_NEAR_ENTER_DISTANCE_SQ) {
                obj_setFlags30(this, 0x100000);
            }
            break;
        default:
            if (obj_testFlags30__14TObjCollidableFUl(this, 0x100000) != 0) {
                if (BEAST_OTHER_NEAR_EXIT_DISTANCE_SQ < temp_f31) {
                    obj_clearFlags30(0x100000);
                }
            } else if (temp_f31 < BEAST_OTHER_NEAR_ENTER_DISTANCE_SQ) {
                obj_setFlags30(this, 0x100000);
            }
            break;
        }
    } else {
        obj_setFlags30(this, 0x100000);
    }
}

int TUnk_80493450::beast_retire_corpse() { return queue_destruction__7TObjectFv(this); }
void TUnk_80493450::beast_update_dead() {
    u8 *arg0 = (u8 *)this;
    advance_animation();
    if (((TObjMotion *)arg0)->is_passing_frame(BEAST_ANIMATION_START_FRAME) != 0) {
        this->vfunc_98();
    }
    if (((TObjMotion *)arg0)->is_passing_frame(BEAST_DEATH_EFFECT_FRAME) != 0) {
        spawn_particle_effect(((u8 *)&this->position), 0xF3);
        this->vfunc_94();
    }
    if (this->frame < (BEAST_DEATH_SLIDE_FRAME_SCALE * (BEAST_DEATH_SLIDE_FRAME_COUNT * this->play_speed))) {
        move_with_wall_slide((arg0));
        x_speed *= BEAST_HORIZONTAL_SPEED_DAMPING;
        m_310 *= BEAST_HORIZONTAL_SPEED_DAMPING;
    } else if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x800000) == 0) {
        apply_actor_gravity(arg0, 0, BEAST_GROUND_HEIGHT_OFFSET);
    }
    this->unk_380 -= this->m_384;
    if (this->unk_380 <= this->unk_388) {
        this->beast_retire_corpse();
    }
}
void TUnk_80493450::vfunc_63() { if (this->mode != 8) { this->mode = 8; this->requested_action = 8; unlink_enemy_group_relations__13TUnk_80493450Fv(this); clear_player_status_flag((s32)((void*)0), (u32)((void*)1)); ((TObjPlayer *)this)->refresh_lobby_state(); send_entity_set_flags__9TObjEnemyFv(this); } }
void TUnk_80493450::beast_update_hurt() {
    u8 *arg0 = (u8 *)this;
    Vec v;

    advance_animation();
    VecCopy(&v, (const Vec *)&m_2fc);
    scratch_vec.x = scratch_vec.y = BEAST_ZERO_VECTOR_COMPONENT;
    scratch_vec.z = get_collision_body_radius(this, 0);
    ((void (*)(void *, void *))push_matrix_from)(identity_matrix, &scratch_vec);
    rotate_matrix_y(0, -rotation_y);
    rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
    pop_matrix();
    vec3_add_to(&v, &scratch_vec);
    v.x += x_speed;
    v.z += m_310;
    if (check_path_obstructed(this, &v) == 0) {
        move_with_wall_slide(arg0);
        x_speed *= BEAST_HORIZONTAL_SPEED_DAMPING;
        m_310 *= BEAST_HORIZONTAL_SPEED_DAMPING;
    } else {
        x_speed = m_310 = BEAST_ZERO_SPEED;
    }
    ((TObjPlayer *)this)->update_collisions();
    if (is_passing_frame(BEAST_ANIMATION_START_FRAME) != 0) {
        this->vfunc_97();
    }
    if (action_flags != 8) {
        obj_clearFlags30(0x600);
        clear_player_status_flag((s32)((void *)0), (u32)((void *)0x04000000));
        if ((s32)subtype == 0) {
            if ((f32)hp < (f32)hpmax * parameters[0]) {
                obj_clearFlags30(0x1000);
                m_374 = (s16)(BEAST_TARGET_HOLD_BASE_FRAMES * (BEAST_TARGET_HOLD_BASE_SCALE + parameters[0]));
            }
        }
        referenceHp = hp;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}
void TUnk_80493450::vfunc_62() {
    if ((s16) this->mode != 7) {
        this->mode = 7;
        this->requested_action = 6;
    }
    obj_clearFlags30(0x240000);
}
void TUnk_80493450::vfunc_89() {  }
void TUnk_80493450::vfunc_61() { obj_clearFlags30(256); }

void TUnk_80493450::beast_update_attack() {
    if (targetId < 0x1000) {
        TObjPlayer *player = get_player_by_client_id(targetId);
        if (player != NULL && player->get_floor() == get_current_floor()) {
            target = (u8 *)player;
        } else {
            target = NULL;
        }
    } else if (targetId < 0x4000) {
        target = get_enemy_entity(targetId);
    } else {
        target = NULL;
    }
    advance_animation();
    switch (phase) {
    case 0:
        phase = 1;
    case 1:
        if (is_passing_frame(BEAST_ATTACK_HIT_FRAME) != 0) {
            if (target != NULL && ((TObjChara *)target)->select_melee_contact_body(this, BEAST_ATTACK_SCALE) != 0) {
                ((TObjChara *)target)->receive_physical_attack(this, BEAST_ATTACK_SCALE);
                ((TObjChara *)target)->apply_knockback_from_attacker((u8 *)this, BEAST_ATTACK_KNOCKBACK);
            }
            vfunc_96();
        }
        vfunc_93();
        if (action_flags != 4) {
            phase = 2;
            requested_action = 0;
            timer = 0xF;
        }
        break;
    case 2:
        timer--;
        if (timer < 0) {
            obj_clearFlags30(0x200000);
            timer = 0;
            vfunc_100();
        }
        break;
    }
    apply_actor_gravity(this, 0, BEAST_GROUND_HEIGHT_OFFSET);
    enemy_turn_toward_dest(this, ((s32 *)movementParameters)[2]);
    ((TObjPlayer *)this)->update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TUnk_80493450::vfunc_60() {
    switch (this->mode) {
    case 0:
        break;
    case 1:
        this->phase = 0;
        if (this->children == NULL) {
            this->mode = 3;
            this->requested_action = 7;
        } else {
            this->mode = 2;
            this->requested_action = 10;
        }
        obj_clearFlags30(0x04040000);
        clear_player_status_flag((s32)((void *)0), (u32)((void *)0x0A000000));
        break;
    case 2:
        break;
    default:
        this->mode = 5;
        this->phase = 1;
        if (BEAST_ATTACK_CHOICE_THRESHOLD < random_ratio__9TObjCharaFv((s32)this)) {
            this->requested_action = 3;
        } else {
            this->requested_action = 4;
        }
        obj_setFlags30(this, 0x200000);
        obj_clearFlags30(0x04040000);
        clear_player_status_flag((s32)((void *)0), (u32)((void *)0x0A000000));
        break;
    }
}

s32 TUnk_80493450::update_movement_status() {
    u8 *arg0 = (u8 *)this;
  if (update_movement_status__9TObjCharaFv((void *) arg0) != 0)
  {
    if ((this->mode) != 0)
    {
      if (((!arg0) && (!arg0)) && (!arg0))
      {
      }
    }
    else
    {
      this->m_390 = 0;
      this->mode = 1;
      this->phase = 0;
      this->requested_action = 0;
      ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
      ((TObjCollidable *)arg0)->clear_player_status_flag((s32)((void*)(0)), (u32)((void*)(0x0A000000)));
    }
    return 1;
  }
  return 0;
}

s32 TUnk_80493450::update_action_hold_status() {
    u8 *arg0 = (u8 *)this;
  if (update_action_hold_status__9TObjCharaFv((void *) arg0) != 0)
  {
    if ((this->mode) != 0)
    {
      if (((!arg0) && (!arg0)) && (!arg0))
      {
      }
    }
    else
    {
      this->m_390 = 0;
      this->mode = 1;
      this->phase = 0;
      this->requested_action = 0;
      ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
      ((TObjCollidable *)arg0)->clear_player_status_flag((s32)((void*)(0)), (u32)((void*)(0x0A000000)));
    }
    return 1;
  }
  return 0;
}

void TUnk_80493450::beast_update_group_chase() {
    f32 d;
    f32 r;
    advance_animation();
    switch (phase) {
    case 0:
        phase = 1;
        vfunc_99();
        break;
    }
    if (target != NULL) {
        Vec v = *(Vec *)&((TObjChara *)target)->m_2fc;
        d = enemy_backstep_from_point(this, &v, m_398);
        turn_toward_direction((s32)((Sub350_800C57F0 *)movementParameters)->p8, (Vec *)&x_speed);
        r = m_398 + bodies->radius;
        if (d < r * r) {
            mode = 3;
            phase = 0;
            obj_clearFlags30(0x1000);
            m_374 = 0;
        }
    }
    ((TObjPlayer *)this)->update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TUnk_80493450::beast_update_approach() {
    u8 *arg0 = (u8 *)this;
    Vec sp14;
    f32 r;
    switch (this->phase) {
    case 0:
        apply_actor_gravity(arg0, 0, BEAST_GROUND_HEIGHT_OFFSET);
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjMotion *)arg0)->is_passing_frame(BEAST_ANIMATION_START_FRAME) != 0) {
            this->vfunc_95();
        }
        if (this->action_flags != 0x20U) {
            this->phase = 1;
            this->requested_action = 2;
        }
        break;
    default:
        if (this->target != NULL) {
            if (test_elt_flag__13TUnk_80493450Fll(arg0, 0, 0x300000) != 0) {
                if (this->m_38c++ < BEAST_HOME_CHASE_FRAME_COUNT) {
                    VecCopy(&sp14, &this->home_position);
                } else {
                    VecCopy(&sp14, (const Vec *)&((TObjChara *)this->target)->m_2fc);
                }
            } else {
                this->m_38c = 0U;
                VecCopy(&sp14, (const Vec *)&((TObjChara *)this->target)->m_2fc);
            }
            update_target_near_flag();
            sub_800C4E08();
            ((TObjMotion *)arg0)->advance_animation();
            {
                Vec sp8 = sp14;
                enemy_move_toward(arg0, *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8), &sp8, 0, this->unk_394);
            }
            if (this->targetId == 0xFFFF) {
                if (horizontal_distance_squared((u8 *)&this->m_29c, (u8 *)&this->position) < (r = this->unk_394 + this->bodies->radius) * r ||
                    BEAST_DESTINATION_TIMEOUT_FRAMES < (f32) (*(s32 *)&this->m_2ac)++) {
                    this->target = NULL;
                    this->m_2ac = 0;
                }
            }
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    ((TObjBase *)arg0)->obj_clearFlags30(0x200000);
}

void TUnk_80493450::update_turn_toward_target() {
    TUnk_80493450 *arg0 = this;
    s32 ang;
    advance_animation();
    switch (arg0->phase) {
    case 0:
        if (arg0->is_passing_frame(BEAST_ANIMATION_START_FRAME) != 0) {
            arg0->vfunc_95();
        }
        if (arg0->action_flags != 0x20) {
            arg0->phase = 1;
            arg0->requested_action = 2;
        }
        break;
    case 1:
        if (arg0->target != NULL && arg0->is_actor_cadence_frame(0x1E) != 0) {
            Vec d;
            VecCopy(&d, (const Vec *)&((TObjChara *)arg0->target)->m_2fc);
            subtract_vector(&d, &arg0->m_2fc);
            ang = arg0->turn_toward_direction((s32)((Ctl_800C5B10 *)arg0->movementParameters)->field_8, &d);
            if (d.x * d.x + d.z * d.z < BEAST_GROUP_APPROACH_DISTANCE_SQ || arg0->children == 0) {
                arg0->mode = 3;
                arg0->phase = 1;
                arg0->requested_action = 2;
            } else if (ang <= ((AttackParams *)(arg0->m_318))->get_attack_angle()) {
                arg0->phase = 2;
                arg0->requested_action = 0;
            }
        }
        break;
    case 2:
        if (arg0->target != NULL && arg0->is_actor_cadence_frame(0x1E) != 0) {
            Vec d;
            VecCopy(&d, (const Vec *)&((TObjChara *)arg0->target)->m_2fc);
            subtract_vector(&d, &arg0->m_2fc);
            ang = angle_difference_abs(arg0->rotation_y, (s32)(BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(d.x, d.z)));
            if (d.x * d.x + d.z * d.z < BEAST_GROUP_APPROACH_DISTANCE_SQ || arg0->children == 0) {
                arg0->mode = 3;
                arg0->phase = 1;
                arg0->requested_action = 2;
            } else if (((AttackParams *)(arg0->m_318))->get_attack_angle() < ang) {
                arg0->phase = 1;
                arg0->requested_action = 2;
            }
        }
        break;
    }
    apply_actor_gravity(arg0, 0, BEAST_GROUND_HEIGHT_OFFSET);
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot(&arg0->position, -0x5DB4, 1, 0);
}

void TUnk_80493450::vfunc_59() {
    u8 *arg0 = (u8 *)this;
    if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x1000) != 0) {
        this->mode = 4;
    }
    switch (this->mode) {
    case 1:
        this->phase = 0;
        if ((u32) this->children == 0U) {
            this->mode = 3;
            this->requested_action = 7;
        } else {
            this->mode = 2;
            this->requested_action = 0xA;
        }
        ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag((s32)((void*)(0)), (u32)((void*)(0x0A000000U)));
        break;
    case 2:
    case 3:
        break;
    case 4:
        this->requested_action = 5;
        break;
    default:
        this->mode = 3;
        this->phase = 1;
        this->requested_action = 2;
        ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag((s32)((void*)(0)), (u32)((void*)(0x0A000000U)));
        break;
    }
}

void TUnk_80493450::beast_idle_update() {
    u8 *arg0 = (u8 *)this;
    f32 r;
    f32 dist;
    f32 range;
    s32 diff;
    s32 angle;
    s32 angle2;
    u8 *other;

    ((TUnk_80493450 *)arg0)->update_target_near_flag();
    ((TUnk_80493450 *)arg0)->sub_800C4E08();
    ((TObjMotion *)arg0)->advance_animation();
    if (this->phase != 1) {
        this->phase = 1;
        ((TUnk_80493450 *)arg0)->link_into_group_chain();
        *(s32 *)&this->m_378 = ((TObjPlayer *)arg0)->is_action_available();
    }
    *(s32 *)&this->m_37c = ((TUnk_80493450 *)arg0)->countChildren();
    other = *(u8 * *)&this->next;
    if (other != NULL) {
        diff = *(s32 *)((s8 *)other + 0x37C) - *(s32 *)&this->m_37c;
        if (diff > 1) {
            link_chain_nodes__10TObjPlayerFPvPvPv(arg0, other, arg0);
            *(s32 *)&this->m_37c = *(s32 *)&this->m_37c + 1;
            *(s32 *)((s8 *)other + 0x37C) = *(s32 *)((s8 *)other + 0x37C) - 1;
        } else if (diff < -1) {
            link_chain_nodes__10TObjPlayerFPvPvPv(arg0, arg0, other);
            *(s32 *)&this->m_37c = *(s32 *)&this->m_37c - 1;
            *(s32 *)((s8 *)other + 0x37C) = *(s32 *)((s8 *)other + 0x37C) + 1;
        }
    }
    dist = horizontal_distance_squared((u8 *)&this->position, (u8 *)&this->home_position);
    range = *(f32 *)((s8 *)arg0 + 0x358) + (*(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4) + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC));
    if (range * range < dist) {
        VecCopy((Vec *)&this->m_29c, &this->home_position);
        VecCopy((Vec *)&this->m_290, (const Vec *)&this->m_2fc);
        VecCopy(&this->prev_position, &this->position);
        VecCopy(&scratch_vec, &this->home_position);
        subtract_vector(&scratch_vec, (u8 *)&this->position);
        angle = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(scratch_vec.x, scratch_vec.z);
        lbl_8050BF00.x = lbl_8050BF00.y = BEAST_ZERO_VECTOR_COMPONENT;
        lbl_8050BF00.z = this->unk_394;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, (u8 *)&this->position);
        if (project_actor_to_ground(arg0, &lbl_8050BF00, 0) == 1) {
            this->requested_action = 2;
            VecCopy(&this->position, &lbl_8050BF00);
            this->rotation_y = approach_angle_limited(this->rotation_y, angle, *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8));
            goto end;
        }
        r = fabs_float(scratch_vec.z);
        if (fabs_float(scratch_vec.x) < r) {
            angle = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(scratch_vec.x, BEAST_ZERO_VECTOR_COMPONENT);
        } else {
            angle = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(BEAST_ZERO_VECTOR_COMPONENT, scratch_vec.z);
        }
        lbl_8050BF00.x = lbl_8050BF00.y = BEAST_ZERO_VECTOR_COMPONENT;
        lbl_8050BF00.z = this->unk_394;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, (u8 *)&this->position);
        if (project_actor_to_ground(arg0, &lbl_8050BF00, 0) == 1) {
            this->requested_action = 2;
            VecCopy(&this->position, &lbl_8050BF00);
            this->rotation_y = approach_angle_limited(this->rotation_y, angle, *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8));
            goto end;
        }
        r = fabs_float(scratch_vec.z);
        if (fabs_float(scratch_vec.x) < r) {
            angle2 = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(BEAST_ZERO_VECTOR_COMPONENT, scratch_vec.z);
        } else {
            angle2 = BEAST_ANGLE_UNITS_PER_RADIAN * atan2_float(scratch_vec.x, BEAST_ZERO_VECTOR_COMPONENT);
        }
        lbl_8050BF00.x = lbl_8050BF00.y = BEAST_ZERO_VECTOR_COMPONENT;
        lbl_8050BF00.z = this->unk_394;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle2);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, (u8 *)&this->position);
        if (project_actor_to_ground(arg0, &lbl_8050BF00, 0) == 1) {
            this->requested_action = 2;
            VecCopy(&this->position, &lbl_8050BF00);
            this->rotation_y = approach_angle_limited(this->rotation_y, angle2, *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8));
        } else {
            this->requested_action = 2;
        }
    } else if (*(s32 *)&this->m_37c == 0 && BEAST_MIN_WANDER_RANGE < *(f32 *)((s8 *)arg0 + 0x358)) {
        this->requested_action = 2;
        ((TObjEnemy *)(arg0))->enemy_wander_home(*(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4), *(f32 *)((s8 *)arg0 + 0x358), *(f32 *)((s8 *)arg0 + 0x358), *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8));
    } else {
        this->request_stand_action();
    }
end:
    if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x800000) == 0) {
        apply_actor_gravity(arg0, 0, BEAST_GROUND_HEIGHT_OFFSET);
    }
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    ((TObjBase *)arg0)->obj_clearFlags30(0x04240000);
    ((TObjCollidable *)arg0)->clear_player_status_flag((s32)((void *)0), (u32)((void *)0x0A000000));
}

void TUnk_80493450::vfunc_58() {
    switch (this->mode) {
    case 1:
        if ((s32) this->m_390 != 0) {
            this->mode = 0;
            this->phase = 0;
        }
        break;
    case 0:
        switch ((s16) this->phase) {
        case 2:
            if ((s32) this->m_390 != 0) {
                this->phase = 0;
            }
            break;
        }
        break;
    default:
        if ((s32) this->m_390 != 0) {
            this->mode = 0;
        } else {
            this->mode = 1;
        }
        this->phase = 0;
        ((TUnk_80493450 *)this)->request_stand_action();
        obj_setFlags30(this, 0x04040000);
        set_indexed_flags(0, 0x0A000000);
        break;
    }
}

u16 find_nearest_visible_player(void *, int, f32);
u32 csnVector(void *, void *, s32);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern const Vec lbl_8043BC68;
}
u16 get_enemy_target_id(void *p);
extern "C" {

void TUnk_80493450::vfunc_28() {
    TUnk_80493450 *self = this;
    u16 best;
    TObjPlayer *player;
    u16 id;
    f32 best_dist;
    f32 dist;

    if (self->m_390 == 1) {
        self->targetId = 0xFFFF;
        obj_setFlags30(self, 0x04040000);
    } else if (self->obj_testFlags30(0x1000) != 0) {
        if (--self->m_374 < 0) {
            self->targetId = 0xFFFF;
            self->m_374 = 0;
            obj_setFlags30(self, 0x1000);
        } else {
            self->targetId = find_nearest_visible_player(self, 0, *(f32 *)self->movementParameters);
        }
    } else if (self->obj_testFlags30(0x10) != 0) {
        if (self->is_actor_cadence_frame(0x1E) != 0) {
            s32 i = 0;
            best = 0xFFFF;
            Vec d = lbl_8043BC68;
            best_dist = *(f32 *)self->movementParameters * *(f32 *)self->movementParameters;
            for (; i < registered_player_count + lbl_805D5870; i++) {
                player = TObjPlayer::get_player_data(i);
                if (player == NULL) {
                    break;
                }
                id = get_entity_id(player);
                if (id < 0x4000 && id != self->entity_id && player->obj_testFlags30(0x03000800) == 0) {
                    VecCopy(&d, (Vec *)&player->m_2fc);
                    subtract_vector(&d, &self->m_2fc);
                    dist = d.x * d.x + d.z * d.z;
                    if (dist < best_dist && check_path_obstructed(self, &player->m_2fc) != 1 &&
                        csnVector(&self->m_2fc, &player->m_2fc, -1) == 0) {
                        best = id;
                        best_dist = dist;
                    }
                }
            }
            self->targetId = best;
        }
    } else if (self->m_378 != 0) {
        self->targetId = get_enemy_target_id(self->groupRoot());
    } else if (self->is_actor_cadence_frame(0x1E) != 0) {
        self->targetId = find_nearest_visible_player(self, 0, *(f32 *)self->movementParameters);
    }
    if (self->targetId < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(self->targetId);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            self->target = (u8 *)p;
        } else {
            self->target = NULL;
        }
    } else if (self->targetId < 0x4000) {
        self->target = get_enemy_entity(self->targetId);
    } else {
        self->target = NULL;
    }
}

#pragma defer_codegen on
TUnk_80493450::TUnk_80493450(TObject *parent) : TObjEnemy(parent) {
    mode = 0;
    phase = 0;
    m_374 = 0;
    m_376 = 0;
    m_378 = 0;
    m_37c = 0;
    unk_380 = BEAST_CORPSE_RETIRE_START;
    m_384 = BEAST_CORPSE_RETIRE_STEP;
    unk_388 = BEAST_CORPSE_RETIRE_THRESHOLD;
    m_38c = 0;
    m_390 = 0;
    m_398 = BEAST_DEFAULT_MOVEMENT_RATE;
    unk_39C = BEAST_NEAR_TARGET_MOVEMENT_RATE;
    unk_394 = BEAST_DEFAULT_MOVEMENT_RATE;
    m_3a0 = BEAST_DEFAULT_MOVEMENT_RATE;
    unk_3A4 = BEAST_NEAR_TARGET_MOVEMENT_RATE;
}
TUnk_80493450::~TUnk_80493450() {}

void TUnk_80493450::run_task() {
    u8 *arg0 = (u8 *)this;
  s16 temp_r0;
  if (TObjPlayer::check_demo_mode() == 1)
  {
    (this->vfunc_101());
    return;
  }
  temp_r0 = this->mode;
  {
    switch (temp_r0)
    {
      case 0:
        (this->vfunc_83());
        break;
      case 1:
        (this->beast_idle_update());
        break;
      case 2:
        (this->update_turn_toward_target());
        break;
      case 3:
        (this->beast_update_approach());
        break;
      case 4:
        (this->beast_update_group_chase());
        break;
      case 5:
        (this->beast_update_attack());
        break;
      case 6:
        (this->vfunc_89());
        break;
      case 7:
        (this->beast_update_hurt());
        break;
      case 8:
        (this->beast_update_dead());
        break;
      case 9:
        (this->beast_retire_corpse());
        break;
    }
  }
  ((TObjEnemy *)arg0)->update_prev_position();
  ((TBoss3VoloptHiraisin *)arg0)->copy_position();
  submit_cursor_candidate((void *) arg0, -1);
  this->m_2b4 += BEAST_FRAME_INCREMENT;
}

}
