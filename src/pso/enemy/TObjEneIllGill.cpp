#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/TObject.h"
#include "pso/TObjControl.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjIllGillKage.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneIllGill.h"
extern "C" void render__15TObjIllGillKageFv();
#include "pso/enemy/TUnk_80494938.h"

#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/TParticleCtrl.h"

struct IllGillEffectRotation { s32 x, y, z; };

extern "C" {
f32 calc_xz_distance_sq(void *, void *, Vec *);
extern const f64 lbl_8047A358[];
extern int enable_v2_features;
s32 apply_actor_gravity(void *, int, f32);
s32 get_current_floor(void);
f64 atan2_float(f32, f32);
f32 newton_sqrtf(f32);
void spawn_directional_particle(void *, void *, s32);
s32 spawn_continuous_particle_with_direction(void *, void *, s32);
s32 angle_difference_abs(s32, s32);
s32 get_player_by_client_id(u16);
s32 minimap_render_dot(void *, int, int, int);
s32 play_persistent_sound(int, void *, void *, int, int);
void *__nw__7TObjectFUl(int);
void TObjIllGillKage__ct(void *, s32, void *);
void subtract_vector(void *, void *);
extern const f64 TObjEneIllGill__data_8047A348;
extern s32 tl_05;
extern const f32 TObjEneIllGill__data_805E02BC;
extern const f32 TObjEneIllGill__data_805E02D8;
s32 obj_setFlags30(void *, int);
s32 play_sound_effect(int, void *, int, int);

s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, s32);
s32 push_matrix_from(void *);
s32 pop_matrices(s32 arg0);
u16 get_entity_id(void *);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
void enemy_turn_toward_dest(void *, s32);
f32 horizontal_distance_squared(void *, void *);

f32 get_collision_body_radius(void *, int);
s32 select_enemy_destination(void *, Vec, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, Vec);
s32 is_split_screen();
extern s32 game_difficulty_selection;
extern s32 local_client_id;
extern IllGillAttackBehavior *illGillAttackBehavior;
extern const f32 lbl_805E02B8;
extern const f32 TObjEneIllGill__data_805E02C0;
extern const f32 lbl_805E02C4;
extern const f32 lbl_805E02C8;
extern const f32 TObjEneIllGill__data_805E02CC;
extern const f32 lbl_805E02D0;
extern const f32 lbl_805E02D4;
s32 init_collision_body_parts(void *, void *, int);

extern s32 TObjEneIllGill_class_name;
extern BmlResource *illGillResource;
extern s32 TObjEneIllGill__boss_registration_id;
extern s32 lbl_805D6FD8;
extern const f32 lbl_805E0308;

}
void move_with_wall_slide(u8 *arg0);

extern "C" {
void *spawn_particle_effect(void *pos, s32 id);
extern const f32 TObjEneIllGill__data_805E02DC;
extern const f32 lbl_805E02E0;
extern const f32 lbl_805E02E4;
s32 project_actor_to_ground(void *, void *, int);
extern Vec lbl_8050BF00;

void submit_cursor_candidate(void *, int);
f32 step_toward_destination__10TObjPlayerFPvPvf(void *, Vec, f32);
extern const f32 lbl_805E02E8;
u16 find_nearest_visible_player(void *, int, f32 *, f32);
s32 check_path_obstructed(void *, void *);
s32 obj_is_hit_receivable(void *);
s32 get_enemy_entity(u16);
extern Vec lbl_8047A328;
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern const f32 lbl_805E02EC;
f32 enemy_move_toward(void *, s32, Vec *, s32, f32, f32);
s32 enemy_pursue_point(void *, s32, Vec *, f32, f32, f32);
extern const f32 lbl_805E02F0;
extern const f32 lbl_805E02F4;
extern const f32 lbl_805E02F8;
f32 fabs_float(f32);
s32 approach_angle_limited(s32, s32, s32);
extern Vec scratch_vec;

int TLobby__sub_8001FE7C(void*, void*);
void free_collision_body_parts(void *);

#pragma push
#pragma opt_common_subs off
void vfunc_6__8TObjBaseFPsl();
void get_name__8TObjBaseFv();
void get_center__8TObjBaseFv();
void *__dt__15TObjIllGillKageFv(void *arg0, s16 arg1);
void apply_object_set_data__8TObjBaseFPv();
void classify_actor_view_detail__8TObjBaseFfff();
extern u8 lbl_8047A1E8[];
extern u8 lbl_8047A1F8[];
extern u8 lbl_8047A210[];
extern u8 lbl_8047A228[];
extern u8 lbl_8047A240[];
extern u8 lbl_8047A258[];
extern u8 lbl_8047A274[];
extern u8 lbl_8047A290[];
extern u8 lbl_8047A2A8[];
extern u8 lbl_8047A2C4[];
extern u8 lbl_8047A2DC[];
extern u8 lbl_8047A2F4[];
void render_shadows__7TObjectFv();
void reset_motion_fields__8TObjBaseFv();
void run_task__15TObjIllGillKageFv();
void update_object_view_visibility__8TObjBaseFff();
extern const char *TObjEneIllGill_model_file_list[2];
extern const char *TObjEneIllGill_motion_name_table[11];
Vec illGillWeaponEffectPosition;
Vec illGillShadowEffectPosition;
Vec illGillChargeEffectPosition1;
Vec illGillChargeEffectPosition2;
u32 lbl_80543A90[4];
__declspec(section ".data") const char *TObjEneIllGill_model_file_list[2] = {
    (const char *)&lbl_8047A1E8, NULL,
};
const char *TObjEneIllGill_motion_name_table[11] = {
    (const char *)&lbl_8047A1F8, (const char *)&lbl_8047A210, (const char *)&lbl_8047A228, (const char *)&lbl_8047A240,
    (const char *)&lbl_8047A258, (const char *)&lbl_8047A274, (const char *)&lbl_8047A290, (const char *)&lbl_8047A2A8,
    (const char *)&lbl_8047A2C4, (const char *)&lbl_8047A2DC, NULL,
};
BmlResourceDescriptor illGillResourceDescriptor = {
    (const char *)lbl_8047A2F4, TObjEneIllGill_model_file_list,
    TObjEneIllGill_motion_name_table, 1, 10
};
TObjMotionAction illGillActions[10] = {
    {1, 0, 0, 0.6f, 1},
    {1, 1, 1, 0.8f, 1},
    {2, 0, 4, 1.0f, 4},
    {2, 0, 5, 1.0f, 4},
    {2, 0, 8, 1.0f, 4},
    {2, 0, 6, 1.0f, 8},
    {3, 5, 9, 1.0f, 0x10},
    {2, 8, 7, 1.0f, 0x20},
    {3, 9, 2, 1.0f, 0x20},
    {2, 0, 3, 1.0f, 0x20},
};
IllGillMovementParameters illGillMovement = {
    400.0f, 0.9f, 0x400, {0x1e0000, 0, 1, 0}
};
CollisionBody illGillCollisionBody = {
    {0.0f, 13.200001f, 0.0f}, 7.2000003f, 0.0f, 0, 0x8003,
    {0.0f, 0.0f, 0.0f}, 0.0f
};
AttackParams *ill_gill_combat_parameter_variants[4] = {0, 0, 0, 0};
void *__vt__15TObjIllGillKage[13] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__15TObjIllGillKageFv, (void *)&run_task__15TObjIllGillKageFv,
    (void *)&render__15TObjIllGillKageFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__8TObjBaseFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv,
};

void TObjEneIllGill::update_charge_attack() {
    TObjEneIllGill *o = this;
    if (o->targetId < 0x1000) {
        s32 p = get_player_by_client_id(o->targetId);
        if (p != 0 && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            o->target = (u8 *)p;
        } else {
            o->target = NULL;
        }
    } else {
        o->targetId = 0xFFFF;
        o->target = NULL;
    }
    o->obj_clearFlags30(0x40000);
    if (o->target == NULL) {
        o->targetId = 0xFFFF;
        o->obj_clearFlags30(0x4202000);
        o->actionTimer = 0;
        return;
    }
    switch (o->phase) {
    default:
        o->phase = 0;
    case 0:
        o->obj_clearFlags30(0x4000000);
        o->clear_player_status_flag(0, 0x80);
        {
            o->play_speed = lbl_805E02B8 * o->action_table[o->requested_action].speed;
        }
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity(o, 0, TObjEneIllGill__data_805E02BC);
        if (o->target != NULL) {
            Vec v = *((Vec *)&((TObjChara *)o->target)->m_2fc);
            s32 d;
            subtract_vector(&v, (Vec *)&o->m_2fc);
            d = o->turn_toward_direction((s32)(lbl_805E02B8 * (f32)((IllGillMovementParameters *)o->movementParameters)->turn), &v);
            if (d < ((AttackParams *)(o->m_318))->get_attack_angle()) {
                s32 ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(v.x, v.z));
                o->chargeDistance = TObjEneIllGill__data_805E02C0 + (newton_sqrtf(TObjPlayer::calc_distance_to_client((s32)o, o->targetId, (u32)0)) + get_collision_body_radius(o, 0));
                if (o->chargeDistance < lbl_805E02C4) {
                    o->chargeDistance = lbl_805E02C4;
                }
                v.z = TObjEneIllGill__data_805E02BC;
                v.x = TObjEneIllGill__data_805E02BC;
                v.z = o->chargeDistance;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, (Vec *)&o->m_2fc);
                if (select_enemy_destination(o, v, 1) != 0 || select_enemy_destination(o, *((Vec *)&((TObjChara *)o->target)->m_2fc), 1) != 0) {
                    o->phase = 1;
                    o->requested_action = 8;
                    obj_setFlags30(o, 0x4000000);
                    o->set_indexed_flags(0, 0x80);
                    copy_position_if_valid__10TObjPlayerFii(o, (*((Vec *)&o->m_2fc)));
                    o->actionTimer = 10;
                    play_sound_effect(0x4003A34E, &o->position, 0, 0);
                } else {
                    if (o->targetId == 0xFFFF) {
                        o->target = NULL;
                    } else {
                        o->phase = 4;
                        o->requested_action = 9;
                        o->actionTimer = illGillAttackBehavior->recoveryFrames;
                    }
                    o->clear_charge_hits();
                }
            }
        }
        break;
    case 1: {
        obj_setFlags30(o, 0x4000000);
        o->set_indexed_flags(0, 0x80);
        {
            Vec v = *((Vec *)&((TObjChara *)o->target)->m_2fc);
            s32 d;
            subtract_vector(&v, (Vec *)&o->m_2fc);
            d = o->turn_toward_direction((s32)(lbl_805E02B8 * (f32)((IllGillMovementParameters *)o->movementParameters)->turn), &v);
            if (d < ((AttackParams *)(o->m_318))->get_attack_angle()) {
                s32 ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(v.x, v.z));
                o->chargeDistance = TObjEneIllGill__data_805E02C0 + (newton_sqrtf(TObjPlayer::calc_distance_to_client((s32)o, o->targetId, (u32)0)) + get_collision_body_radius(o, 0));
                if (o->chargeDistance < lbl_805E02C4) {
                    o->chargeDistance = lbl_805E02C4;
                }
                v.z = TObjEneIllGill__data_805E02BC;
                v.x = TObjEneIllGill__data_805E02BC;
                v.z = o->chargeDistance;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, (Vec *)&o->m_2fc);
                if (select_enemy_destination(o, v, 1) == 0 && select_enemy_destination(o, *((Vec *)&((TObjChara *)o->target)->m_2fc), 1) == 0) {
                    if (o->targetId == 0xFFFF) {
                        o->target = NULL;
                    } else {
                        o->phase = 4;
                        o->requested_action = 9;
                        o->actionTimer = illGillAttackBehavior->recoveryFrames;
                    }
                    o->clear_charge_hits();
                }
            }
        }
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity(o, 0, TObjEneIllGill__data_805E02BC);
        o->actionTimer--;
        if (o->actionTimer < 0) {
            o->phase = 2;
            o->requested_action = 9;
            o->obj_clearFlags30(0x4000000);
            o->clear_player_status_flag(0, 0x80);
            if (o->primaryEffect == 0) {
                o->primaryEffect = create_particle_emitter(&o->chargeEffectPosition1, 0x222);
            }
            if (o->secondaryEffect == 0) {
                o->secondaryEffect = create_particle_emitter(&o->chargeEffectPosition2, 0x222);
            }
        }
        break;
    }
    case 2: {
        TObjChara **hit;
        TObjChara *p;
        s32 i;
        o->obj_clearFlags30(0x4000000);
        o->clear_player_status_flag(0, 0x80);
        {
            o->play_speed = o->action_table[o->requested_action].speed;
        }
        ((TObjMotion *)o)->advance_animation();
        for (i = 0; i < 4; i++) {

            hit = &o->chargeHits[i];
            if (*hit == NULL) {
                p = (TObjChara *)TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                if (get_entity_id(p) >= 0x1000) {
                    break;
                }
                if (o->find_actor_body_contact((u8 *)p, (f32)lbl_805E02C8) != 0 &&
                    p->select_melee_contact_body(o, TObjEneIllGill__data_805E02CC) != 0) {
                    f32 dmg = p->receive_physical_attack(o, TObjEneIllGill__data_805E02CC);
                    obj_setFlags30(p, 0x400);
                    p->apply_knockback_from_attacker((u8 *)o, lbl_805E02B8 * dmg);
                    *hit = p;
                    if (is_split_screen() == 0 && local_client_id == get_entity_id(p)) {
                        TCameraCtrl::set_shake_preset(1);
                    }
                }
            }
        }
        if (o->target != NULL) {
            IllGillMovementParameters *prm = ((IllGillMovementParameters *)o->movementParameters);
            f32 spd = lbl_805E02D0 * prm->speed;
            f32 d2;
            f32 t;
            s32 c;
            if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                spd *= lbl_805E02B8;
            }
            enemy_turn_toward_dest(o, (s32)(lbl_805E02D0 * (f32)prm->turn));
            enemy_set_heading_velocity(spd, (TObjEnemy *)(o), o->rotation_y);
            move_with_wall_slide((u8 *)o);
            d2 = horizontal_distance_squared((Vec *)&o->m_29c, (Vec *)&o->m_2fc);
            t = spd + o->bodies->radius;
            if (d2 < t * t || ((IllGillMovementParameters *)o->movementParameters)->range * ((IllGillMovementParameters *)o->movementParameters)->range < d2 || lbl_805E02D4 < (f32)(c = o->chargeFrames)) {
                if (o->targetId == 0xFFFF) {
                    o->target = NULL;
                } else {
                    o->phase = 4;
                    o->requested_action = 9;
                    o->actionTimer = illGillAttackBehavior->recoveryFrames;
                    o->free_resources();
                }
                o->clear_charge_hits();
                o->chargeFrames = 0;
            } else {
                o->chargeFrames = c + 1;
            }
        }
        play_persistent_sound(0x4003A34F, o, &o->position, 0, 0);
        if (o->primaryEffect != 0 && ((TObject *)(o->primaryEffect))->all_parents_unqueued_for_destruction() != 0) {
            ((TParticleCtrl *)o->primaryEffect)->set_position(&o->chargeEffectPosition1);
        }
        if (o->secondaryEffect != 0 && ((TObject *)(o->primaryEffect))->all_parents_unqueued_for_destruction() != 0) {
            ((TParticleCtrl *)o->secondaryEffect)->set_position(&o->chargeEffectPosition2);
        }
        break;
    }
    case 4:
        o->obj_clearFlags30(0x4000000);
        o->clear_player_status_flag(0, 0x80);
        {
            o->play_speed = lbl_805E02B8 * o->action_table[o->requested_action].speed;
        }
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity(o, 0, TObjEneIllGill__data_805E02BC);
        o->actionTimer--;
        if (o->actionTimer < 0) {
            o->obj_clearFlags30(0x200000);
            o->actionTimer = 0;
            o->targetId = 0xFFFF;
            o->target = NULL;
        }
        break;
    }
    o->refresh_collision_body_centers();
    minimap_render_dot(&o->position, -0x5DB4, 1, 0);
}
#pragma pop

void TObjEneIllGill::update_shadow_attack() {
    u8 *arg0_ = (u8 *)this;
    u8 *pl;
    s32 a;
    u8 *enemy = (u8 *)arg0_;
    if (this->targetId < 0x1000U) {
        pl = (u8 *)get_player_by_client_id(this->targetId);
        if (pl != NULL && ((TObjPlayer *)pl)->get_floor() == get_current_floor()) {
            this->target = pl;
        } else {
            this->target = NULL;
        }
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    ((TObjBase *)enemy)->obj_clearFlags30(0x04040000);
    ((TObjMotion *)enemy)->advance_animation();
    switch (this->phase) {
    case 0:
        if (this->target == NULL) {
            this->actorFlags &= ~0x00200000;
            this->actionTimer = 0;
        } else {
            Vec v;
            VecCopy(&v, (const Vec *)((u8 *)&((TObjChara *)target)->m_2fc));
            subtract_vector(&v, &m_2fc);
            a = ((TObjEnemy *)enemy)->turn_toward_direction(((IllGillMovementParameters *)movementParameters)->turn, &v);
            apply_actor_gravity(enemy, 0, TObjEneIllGill__data_805E02BC);
            if (a < ((AttackParams *)(ill_gill_combat_parameter_variants[2]))->get_attack_angle()) {
                this->phase = 1;
                this->requested_action = 4;
                this->actionTimer = 0;
            }
        }
        break;
    case 1:
        if (((TObjMotion *)enemy)->is_passing_frame((f32)TObjEneIllGill__data_805E02D8) != 0) {
            this->phase = 2;
            this->requested_action = 4;
            this->actionTimer = 0;
            {
                Vec d = *(Vec *)((u8 *)&((TObjChara *)target)->m_2fc);
                IllGillEffectRotation ang;
                subtract_vector(&d, &shadowEffectPosition);
                ang.x = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(d.z, newton_sqrtf(d.x * d.x + d.y * d.y)));
                ang.y = 0;
                ang.z = -(s32)(TObjEneIllGill__data_8047A348 * atan2_float(d.x, d.y));
                if (this->primaryEffect == 0U) {
                    this->primaryEffect = (TParticleCtrl *)spawn_continuous_particle_with_direction(&shadowEffectPosition, &ang, 0x224);
                }
                spawn_directional_particle(&shadowEffectPosition, &ang, 0x223);
            }
        }
        break;
    case 2:
        play_persistent_sound(0x4003A356, enemy, &position, 0, 0);
        apply_actor_gravity(enemy, 0, TObjEneIllGill__data_805E02BC);
        if (this->target != NULL) {
            Vec w;
            VecCopy(&w, (const Vec *)((u8 *)&((TObjChara *)target)->m_2fc));
            subtract_vector(&w, &m_2fc);
            a = angle_difference_abs(this->rotation_y, (s32)(TObjEneIllGill__data_8047A348 * atan2_float(w.x, w.z)));
            if (a < ((AttackParams *)(ill_gill_combat_parameter_variants[2]))->get_attack_angle()) {
                VecCopy(&w, (const Vec *)((u8 *)&((TObjChara *)target)->position));
                subtract_vector(&w, &shadowEffectPosition);
                atan2_float(w.z, newton_sqrtf(w.x * w.x + w.y * w.y));
                atan2_float(w.x, w.y);
                if (this->action_flags != 4 && ((TObjCollidable *)target)->obj_testFlags30(0x04000000) == 0) {
                    void *m = __nw__7TObjectFUl(0x9C);
                    if (m != NULL) {
                        TObjIllGillKage__ct(m, tl_05, this->target);
                    }
                }
            } else {
                this->action_flags &= ~4;
            }
        } else {
            this->action_flags &= ~4;
        }
        if (this->action_flags != 4) {
            this->phase = 4;
            this->requested_action = 0;
            this->actionTimer = 10;
        }
        break;
    case 4:
        apply_actor_gravity(enemy, 0, TObjEneIllGill__data_805E02BC);
        this->actionTimer = this->actionTimer - 1;
        if (this->actionTimer < 0) {
            this->actorFlags &= ~0x00200000;
            this->actionTimer = 0;
            this->free_resources();
        }
        break;
    }
    ((TObjPlayer *)enemy)->update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}
extern u8 lbl_804FF5E8[];
extern s32 illGillModelNodeIndex;
void TObjEneIllGill::capture_effect_positions() {
    Vec *v;
    switch (illGillModelNodeIndex) {
    case 50:
        v = &illGillWeaponEffectPosition;
        v->x = TObjEneIllGill__data_805E02BC;
        v->y = TObjEneIllGill__data_805E02BC;
        v->z = TObjEneIllGill__data_805E02BC;
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    case 44:
        v = &illGillShadowEffectPosition;
        v->x = TObjEneIllGill__data_805E02BC;
        v->y = TObjEneIllGill__data_805E02BC;
        v->z = TObjEneIllGill__data_805E02BC;
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    case 40:
        v = &illGillChargeEffectPosition1;
        v->x = TObjEneIllGill__data_805E02BC;
        v->y = TObjEneIllGill__data_805E02BC;
        v->z = TObjEneIllGill__data_805E02BC;
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    case 27:
        v = &illGillChargeEffectPosition2;
        v->x = TObjEneIllGill__data_805E02BC;
        v->y = TObjEneIllGill__data_805E02BC;
        v->z = TObjEneIllGill__data_805E02BC;
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    }
    illGillModelNodeIndex++;
}

void TObjEneIllGill::update_death_fall() {
    u8 *arg0 = (u8 *)this;
  s32 temp_r0_2;
  obj_setFlags30((void *) arg0, 0x04040000);
  ((TObjMotion *)arg0)->advance_animation();
  switch (this->phase)
  {
    default:
      this->phase = 0;
    case 0:
      apply_actor_gravity(arg0, 0, TObjEneIllGill__data_805E02BC);
      if (((TObjMotion *)arg0)->is_passing_frame((f32)((f32) TObjEneIllGill__data_805E02D8)) != 0)
    {
      play_sound_effect(0x4003A351, (u8 *)&this->position, 0, 0);
      this->phase = 2;
    }
      return;
    return;
    case 2:
      this->m_300 = (f32) ((this->m_300) + TObjEneIllGill__data_805E02DC);
      move_with_wall_slide(arg0);
      x_speed = (f32) ((x_speed) * lbl_805E02E0);
      this->m_310 = (f32) ((this->m_310) * lbl_805E02E0);
      if (((TObjMotion *)arg0)->is_passing_frame((f32)((f32) TObjEneIllGill__data_805E02C0)) != 0)
    {
      this->phase = 3;
      spawn_particle_effect(&position, 0xF0);
      return;
    }
      break;
    case 3:
      if (((TObjMotion *)arg0)->is_passing_frame((f32)((f32) lbl_805E02E4)) != 0)
    {
      play_sound_effect(0x4003A358, (u8 *)&this->position, 0, 0);
      TObjPlayer::apply_effect_variant_b((s32)(&position), 0xA);
      fn_800D911C(&position);
      this->phase = 4;
      this->deathTimer = 0xA;
      return;
    }
      break;
    case 4:
      temp_r0_2 = (this->deathTimer) - 1;
      this->deathTimer = temp_r0_2;
      if (temp_r0_2 < 0)
    {
      queue_destruction();
    }
      break;
  }
}

void TObjEneIllGill::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r5;
    if ((s16) this->mode != 8) {
        this->mode = 8;
        this->phase = 0;
        this->requested_action = 6;
        temp_r5 = (u8 *)this->bodies;
        bodies->flags = (s32) (bodies->flags & 0xFFFF7FFE);
        this->free_resources();
        spawn_particle_effect(&m_2fc, 0xF2);
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        ((TObjEnemy *)arg0)->send_entity_set_flags();
    }
}

void TObjEneIllGill::update_damage_recovery() {
    u8 *arg0 = (u8 *)this;
    ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
    ((TObjMotion *)arg0)->advance_animation();
    this->m_310 = TObjEneIllGill__data_805E02BC;
    this->x_speed = TObjEneIllGill__data_805E02BC;
    apply_actor_gravity(arg0, 0, TObjEneIllGill__data_805E02BC);
    ((TObjPlayer *)arg0)->update_collisions();
    if (((TObjMotion *)arg0)->is_passing_frame((f32)TObjEneIllGill__data_805E02C0) != 0) {
        play_sound_effect(0x4003A350, &position, 0, 0);
    }
    if (this->action_flags != 8) {
        this->actorFlags &= ~0x600;
        this->bodies->flags &= ~0x04000000;
        if ((f32)this->hp < lbl_805E02E8 * (f32)this->hpmax) {
            this->actorFlags |= 0x2000;
            this->target = 0;
            this->targetId = 0xFFFF;
            VecCopy((Vec *)(((u8 *)&this->m_290)), (const Vec *)(&m_2fc));
            VecCopy((Vec *)(&m_29c), (const Vec *)(&m_2fc));
            this->chargeDistance = TObjEneIllGill__data_805E02BC;
        }
        this->referenceHp = this->hp;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::vfunc_62() {
    s16 temp_r0;
    void *temp_r3;

    temp_r0 = this->requested_action;
    if ((temp_r0 == 2) || (temp_r0 == 3)) {
        this->referenceHp = (s16) this->hp;
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
        this->m_2dc = 0;
        temp_r3 = this->bodies;
        bodies->flags = (s32) (bodies->flags & 0xFBFFFFFF);
        return;
    }
    if ((s16) this->mode != 7) {
        this->mode = 7;
        this->requested_action = 5;
        this->free_resources();
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
}

void TObjEneIllGill::sub_803669B0() {
    u8 *player = (u8 *)this;
    s32 temp_r3;
    ((TObjBase *)player)->obj_clearFlags30((int)(0x04040000U));
    ((TObjMotion *)player)->advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(player, 0, (f32) ((*(f32 *)&TObjEneIllGill__data_805E02BC)));
    }
    ((TObjPlayer *)player)->update_collisions();
    temp_r3 = this->actionTimer;
    this->actionTimer = (temp_r3 - 1);
    if (temp_r3 < 0) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        this->actionTimer = (s32) this->resetTimer;
        this->referenceHp = (s16) this->hp;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::vfunc_61() { obj_clearFlags30(256); }
void TObjEneIllGill::free_resources() {
    if (this->primaryEffect != 0U) {
        TParticleCtrl::release((void *)this->primaryEffect);
        this->primaryEffect = NULL;
    }
    if (this->secondaryEffect != 0U) {
        TParticleCtrl::release((void *)this->secondaryEffect);
        this->secondaryEffect = NULL;
    }
    if (this->tertiaryEffect != 0U) {
        TParticleCtrl::release((void *)this->tertiaryEffect);
        this->tertiaryEffect = NULL;
    }
}

extern const f32 lbl_805E02FC;

void TObjEneIllGill::update_weapon_attack() {
    u8 *actor = (u8 *)this;
    f32 temp_f1_2;
    f32 temp_f31;
    s32 temp_r30_2;
    u16 temp_r3;
    TParticleCtrl *temp_r3_10;
    TParticleCtrl *temp_r3_11;
    TParticleCtrl *temp_r3_12;
    u8 *player;
    u8 *temp_r3_3;
    u8 *temp_r6;
    temp_r3 = this->targetId;
    if (temp_r3 < 0x1000U) {
        player = (u8 *)get_player_by_client_id(temp_r3);
        if ((player != NULL) && (((TObjPlayer *)player)->get_floor() == get_current_floor())) {
            this->target = player;
        } else {
            this->target = NULL;
        }
    } else if (temp_r3 < 0x4000U) {
        this->target = (u8 *)get_enemy_entity(temp_r3);
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    ((TObjBase *)actor)->obj_clearFlags30(0x04040000);
    {
        play_speed = illGillAttackBehavior->animationSpeed * action_table[requested_action].speed;
    }
    ((TObjMotion *)actor)->advance_animation();
    switch (this->phase) {
    default:
        this->phase = 0;
    case 0:
        temp_r6 = (u8 *)(this->target);
        if (temp_r6 == NULL) {
            this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
            this->actionTimer = 0;
        } else {
            Vec v = *(Vec *)((u8 *)&((TObjChara *)temp_r6)->m_2fc);
            subtract_vector(&v, &m_2fc);
            temp_r30_2 = ((TObjEnemy *)actor)->turn_toward_direction((((IllGillMovementParameters *)movementParameters)->turn), &v);
            apply_actor_gravity(actor, 0, TObjEneIllGill__data_805E02BC);
            if (temp_r30_2 < ((AttackParams *)(this->m_318))->get_attack_angle()) {
                this->phase = 2;
                temp_f1_2 = this->parameters[1];
                if (TObjEneIllGill__data_805E02BC == temp_f1_2) {
                    if (random_ratio() > lbl_805E02EC) {
                        if (random_ratio() > lbl_805E02E0) {
                            this->weaponSpecial = 1;
                        } else {
                            this->weaponSpecial = 2;
                        }
                    } else {
                        this->weaponSpecial = 3;
                    }
                } else {
                    this->weaponSpecial = (s32) temp_f1_2;
                }
                switch (this->weaponSpecial) {
                case 1:
                    this->requested_action = 2;
                    if (this->primaryEffect == 0U) {
                        this->primaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1E);
                    }
                    if (this->secondaryEffect == 0U) {
                        this->secondaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1F);
                    }
                    this->hitFrame = 0x1E;
                    this->tertiaryEffect = NULL;
                    play_sound_effect(0x4003A352, &position, 0, 0);
                    break;
                case 2:
                    this->requested_action = 2;
                    if (this->primaryEffect == 0U) {
                        this->primaryEffect = create_particle_emitter((&weaponEffectPosition), 0xA1);
                    }
                    if (this->secondaryEffect == 0U) {
                        this->secondaryEffect = create_particle_emitter((&weaponEffectPosition), 0x188);
                    }
                    this->hitFrame = 0x1E;
                    this->tertiaryEffect = NULL;
                    play_sound_effect(0x4003A352, &position, 0, 0);
                    break;
                case 3:
                default:
                    this->requested_action = 3;
                    if (this->primaryEffect == 0U) {
                        this->primaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1C4);
                    }
                    if (this->secondaryEffect == 0U) {
                        this->secondaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1C5);
                    }
                    if (this->tertiaryEffect == 0U) {
                        this->tertiaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1C8);
                    }
                    this->hitFrame = 0x23;
                    play_sound_effect(0x4003A352, &position, 0, 0);
                    break;
                }
            }
        }
        break;
    case 2:
        apply_actor_gravity(actor, 0, TObjEneIllGill__data_805E02BC);
        if (((TObjMotion *)actor)->is_passing_frame(TObjEneIllGill__data_805E02DC) != 0) {
            play_sound_effect(0x4003A353, &position, 0, 0);
        }
        if (((TObjMotion *)actor)->is_passing_frame((f32)((f32) this->hitFrame)) != 0) {
            this->hitFrame = 0;
            temp_r3_3 = (u8 *)(this->target);
            if ((temp_r3_3 != NULL) && (((TObjChara *)(temp_r3_3))->select_melee_contact_body(actor, TObjEneIllGill__data_805E02CC) != 0)) {
                switch (this->weaponSpecial) {
                case 1:
                    ((TObjPlayer *)actor)->set_model_id(7);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) illGillAttackBehavior->specialParameter));
                    ((TObjChara *)((u8 *)(this->target)))->receive_weapon_special_attack(actor, 0);
                    play_sound_effect(0x40039E54, &position, 0, 0);
                    break;
                case 2:
                    ((TObjPlayer *)actor)->set_model_id(0xA);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) illGillAttackBehavior->specialParameter));
                    ((TObjChara *)((u8 *)(this->target)))->receive_weapon_special_attack(actor, 0);
                    play_sound_effect(0x40039E54, &position, 0, 0);
                    break;
                case 3:
                    ((TObjPlayer *)actor)->set_model_id(0xB);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) illGillAttackBehavior->thirdSpecialParameter));
                    if (((TObjChara *)((u8 *)(this->target)))->receive_weapon_special_attack(actor, 0) <= TObjEneIllGill__data_805E02BC) {
                        ((TObjChara *)((u8 *)(this->target)))->receive_physical_attack(actor, TObjEneIllGill__data_805E02CC);
                    }
                    play_sound_effect(0x40039E55, &position, 0, 0);
                    break;
                default:
                    temp_f31 = ((TObjChara *)((u8 *)(this->target)))->receive_physical_attack(actor, TObjEneIllGill__data_805E02CC);
                    play_sound_effect(0x40039E54, &position, 0, 0);
                    ((TObjChara *)((u8 *)(this->target)))->apply_knockback_from_attacker(actor, temp_f31);
                    break;
                }
            }
        }
        temp_r3_10 = this->primaryEffect;
        if ((temp_r3_10 != 0U) && (((TObject *)temp_r3_10)->all_parents_unqueued_for_destruction() != 0)) {
            ((TParticleCtrl *)this->primaryEffect)->set_position(&weaponEffectPosition);
        }
        temp_r3_11 = this->secondaryEffect;
        if ((temp_r3_11 != 0U) && (((TObject *)temp_r3_11)->all_parents_unqueued_for_destruction() != 0)) {
            ((TParticleCtrl *)this->secondaryEffect)->set_position(&weaponEffectPosition);
        }
        temp_r3_12 = this->tertiaryEffect;
        if ((temp_r3_12 != 0U) && (((TObject *)temp_r3_12)->all_parents_unqueued_for_destruction() != 0)) {
            ((TParticleCtrl *)this->tertiaryEffect)->set_position(&weaponEffectPosition);
        }
        if ((u32) this->action_flags != 4U) {
            this->phase = 3;
            this->requested_action = 0;
            this->actionTimer = 0x1E;
            this->free_resources();
        }
        break;
    case 3:
        apply_actor_gravity(actor, 0, TObjEneIllGill__data_805E02BC);
        this->actionTimer = (s32) (this->actionTimer - 1);
        if ((s32) this->actionTimer < 0) {
            this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
            this->actionTimer = 0;
        }
        break;
    }
    ((TObjPlayer *)actor)->update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::vfunc_60() {
    TObjEneIllGill *o = this;
    switch (o->attackType) {
    default:
        o->attackType = 0;
    case 0:
    case 1:
        o->mode = 3;
        o->phase = 0;
        o->requested_action = 1;
        break;
    case 2:
        o->mode = 5;
        o->phase = 0;
        o->requested_action = 1;
        break;
    case 3:
        o->mode = 4;
        o->phase = 0;
        o->requested_action = 7;
        o->chargeDistance = TObjEneIllGill__data_805E02BC;
        o->clear_charge_hits();
        break;
    }
    o->actorFlags |= 0x200000;
    o->actorFlags &= ~0x40000;
}

s32 TObjEneIllGill::is_target_in_attack_range() {
    Vec v;
    f32 dist;
    s32 ang;
    f32 rad;
    u16 id;
    u8 *pl;

    if (this->target != NULL && this->m_318 != 0 && !(((TObjChara *)this->target)->actorFlags & 0x02000800)) {
        if (obj_testFlags30(0x2000) != 0) {
            this->attackType = 3;
            bind_enemy_combat_stats((u8 *)0, (u8 *)(ill_gill_combat_parameter_variants[this->attackType]), (u8 *)0);
            return 1;
        }
        dist = calc_xz_distance_sq(this, this->target, &v);
        ang = angle_difference_abs(this->rotation_y, (s32)(TObjEneIllGill__data_8047A348 * atan2_float(v.x, v.z)));
        pl = this->target;
        if (((TObjChara *)pl)->bodies != NULL) {
            rad = ((TObjChara *)pl)->bodies->radius - lbl_8047A358[0];
        } else {
            rad = TObjEneIllGill__data_805E02D8;
        }
        id = get_entity_id(pl);
        if (id < 0x1000) {
            s32 i;
            pl = this->target;
            if (((TLobby *)pl)->check_player_flag1() == 1 || (enable_v2_features == 1 && ((TObjCollidable *)pl)->obj_testFlags30(0x20) != 0)) {
                this->m_318 = (u32)ill_gill_combat_parameter_variants[0];
                if (dist <= (rad + ((AttackParams *)(this->m_318))->get_attack_range()) * (rad + ((AttackParams *)(this->m_318))->get_attack_range()) &&
                    ang <= ((AttackParams *)(this->m_318))->get_attack_angle()) {
                    this->attackType = 0;
                    bind_enemy_combat_stats((u8 *)0, (u8 *)(ill_gill_combat_parameter_variants[this->attackType]), (u8 *)0);
                    return 1;
                }
                return 0;
            }
            for (i = 0; i < 4; i++) {
                f32 r2;
                s32 m;
                this->m_318 = (u32)ill_gill_combat_parameter_variants[i];
                r2 = (rad + ((AttackParams *)(this->m_318))->get_attack_range()) * (rad + ((AttackParams *)(this->m_318))->get_attack_range());
                m = ((AttackParams *)(this->m_318))->get_attack_angle();
                if (dist <= r2 && ang <= m) {
                    this->attackType = i;
                    bind_enemy_combat_stats((u8 *)0, (u8 *)(ill_gill_combat_parameter_variants[this->attackType]), (u8 *)0);
                    return 1;
                }
            }
        } else if (id < 0x4000) {
            this->m_318 = (u32)ill_gill_combat_parameter_variants[0];
            if (dist <= (rad + ((AttackParams *)(this->m_318))->get_attack_range()) * (rad + ((AttackParams *)(this->m_318))->get_attack_range()) &&
                ang <= ((AttackParams *)(this->m_318))->get_attack_angle()) {
                this->attackType = 0;
                bind_enemy_combat_stats((u8 *)0, (u8 *)(ill_gill_combat_parameter_variants[this->attackType]), (u8 *)0);
                return 1;
            }
        }
    }
    return 0;
}

void TObjEneIllGill::update_chase_target() {
    u8 *arg0 = (u8 *)this;
    f32 r;
    s32 id;
    f32 d;
    s32 a;
    f32 t;
    ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
    r = ((IllGillMovementParameters *)movementParameters)->speed;
    id = ((IllGillMovementParameters *)movementParameters)->turn;
    ((TObjMotion *)arg0)->advance_animation();
    if (this->target != NULL) {
        switch (this->phase) {
        default:
        case 1:
            this->phase = 0;
        case 0: {
            Vec dir;
            t = this->m_300 + TObjEneIllGill__data_805E02DC;
            this->m_300 = t;
            {
                Vec tgt = *(Vec *)((u8 *)&((TObjChara *)target)->m_2fc);
                d = enemy_move_toward(arg0, id, &tgt, 0, lbl_805E02F0 * r, t);
            }
            VecCopy(&dir, (const Vec *)((u8 *)&((TObjChara *)target)->m_2fc));
            subtract_vector(&dir, &m_2fc);
            a = angle_difference_abs(this->rotation_y,
                                     (s32)(TObjEneIllGill__data_8047A348 * atan2_float(dir.x, dir.z)));
            if (a < ((AttackParams *)(this->m_318))->get_attack_angle()) {
                this->phase = 2;
            }
            break;
        }
        case 2: {
            t = this->m_300;
            this->m_300 = t + TObjEneIllGill__data_805E02DC;
            {
                Vec tgt = *(Vec *)((u8 *)&((TObjChara *)target)->m_2fc);
                enemy_pursue_point(arg0, id, &tgt, r, lbl_805E02F4, t);
            }
            d = horizontal_distance_squared(&m_29c, &m_2fc);
            t = r + this->bodies->radius;
            if (d < t * t) {
                if (this->targetId == 0xFFFF) {
                    this->target = NULL;
                } else {
                    this->phase = 0;
                }
            }
            break;
        }
        }
        t = ((IllGillMovementParameters *)movementParameters)->range;
        if (t * t < d) {
            this->target = NULL;
        }
        if (((TObjMotion *)arg0)->is_passing_frame((f32)TObjEneIllGill__data_805E02BC) != 0) {
            play_sound_effect(0x4003A34D, &position, 0, 0);
        }
        if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805E02F8) != 0) {
            play_sound_effect(0x4003A34D, &position, 0, 0);
        }
    }
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::vfunc_59() {
    TObjEneIllGill *enemy = this;
    s16 temp_r0;
    temp_r0 = enemy->mode;
    if ((temp_r0 >= 3) || (temp_r0 < 1)) {
        enemy->requested_action = 1;
        enemy->mode = 2;
        enemy->phase = 0;
        enemy->obj_clearFlags30((int)(0x04040000U));
        enemy->free_resources();
    }
}

void TObjEneIllGill::update_forward_movement() {
    u8 *player = (u8 *)this;
    Vec v;
    f32 d;
    f32 a;
    f32 b;
    IllGillMovementParameters *movement;
    this->requested_action = 0;
    ((TObjMotion *)player)->advance_animation();
    obj_setFlags30(player, 0x04040000);
    v.y = TObjEneIllGill__data_805E02BC;
    v.x = TObjEneIllGill__data_805E02BC;
    v.z = TObjEneIllGill__data_805E02CC;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrices(1);
    vec3_add_to(&v, &home_position);
    this->m_300 += TObjEneIllGill__data_805E02DC;
    d = step_toward_destination__10TObjPlayerFPvPvf(player, v, lbl_805E02B8 * ((IllGillMovementParameters *)movementParameters)->speed);
    movement = (IllGillMovementParameters *)movementParameters;
    a = movement->range * movement->range;
    b = movement->speed * movement->speed;
    if (a < d || d < b) {
        this->target = 0;
    }
    apply_actor_gravity(player, 0, TObjEneIllGill__data_805E02BC);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::update_idle() {
    u8 *arg0 = (u8 *)this;
    IllGillMovementParameters *movement;

    ((TObjMotion *)arg0)->advance_animation();
    switch (this->phase) {
    case 0:
        obj_setFlags30(arg0, 0x04040000);
        ((TUnk_80494938 *)(&this->fade))->start_fade_in();
        ((TBoss3Volopt *)(&position))->play_area_se_with_particle();
        this->phase = 1;
        break;
    case 1:
        obj_setFlags30(arg0, 0x04040000);
        if (fade.advance_toward_max() == 1) {
            this->phase = 2;
            this->requested_action = 1;
            this->fadingIn = 0;
        }
        break;
    case 2:
        ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        this->requested_action = 1;
        if (horizontal_distance_squared((u8 *)&this->position, (u8 *)&this->home_position) > lbl_805E02C8) {
            move_toward_dest_with_detour();
        } else {
            this->m_300 = (f32) (this->m_300 + TObjEneIllGill__data_805E02DC);
            movement = (IllGillMovementParameters *)movementParameters;
            ((TObjEnemy *)arg0)->enemy_wander_home((f32) (lbl_805E02E8 * movement->speed), lbl_805E02C4, lbl_805E02FC, movement->turn);
        }
        ((TObjCollidable *)arg0)->refresh_collision_body_centers();
        break;
    default:
        this->requested_action = 0;
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity(arg0, 0, TObjEneIllGill__data_805E02BC);
        }
        break;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    ((TObjBase *)arg0)->obj_clearFlags30(0x200000);
}

extern void *tl_04;

void TObjEneIllGill::move_toward_dest_with_detour() {
    TObjEneIllGill *o = this;
    s32 ang;
    VecCopy((Vec *)(Vec *)&o->m_29c, (const Vec *)&o->home_position);
    VecCopy((Vec *)&(*(Vec *)&o->m_290), (const Vec *)(Vec *)&o->m_2fc);
    VecCopy((Vec *)&o->prev_position, (const Vec *)&o->position);
    VecCopy((Vec *)&scratch_vec, (const Vec *)&o->home_position);
    subtract_vector(&scratch_vec, &o->position);
    ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(scratch_vec.x, scratch_vec.z));
    if (o->project_step_to_ground(ang) == 1) {
        o->requested_action = 1;
        VecCopy((Vec *)&o->position, (const Vec *)&lbl_8050BF00);
        o->rotation_y = approach_angle_limited(o->rotation_y, ang, ((IllGillMovementParameters *)o->movementParameters)->turn);
    } else {
        if (fabs_float(scratch_vec.x) < fabs_float(scratch_vec.z)) {
            ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(scratch_vec.x, TObjEneIllGill__data_805E02BC));
        } else {
            ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(TObjEneIllGill__data_805E02BC, scratch_vec.z));
        }
        if (o->project_step_to_ground(ang) == 1) {
            o->requested_action = 1;
            VecCopy((Vec *)&o->position, (const Vec *)&lbl_8050BF00);
            o->rotation_y = approach_angle_limited(o->rotation_y, ang, ((IllGillMovementParameters *)o->movementParameters)->turn);
        } else {
            if (fabs_float(scratch_vec.x) < fabs_float(scratch_vec.z)) {
                ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(TObjEneIllGill__data_805E02BC, scratch_vec.z));
            } else {
                ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(scratch_vec.x, TObjEneIllGill__data_805E02BC));
            }
            if (o->project_step_to_ground(ang) == 1) {
                o->requested_action = 1;
                VecCopy((Vec *)&o->position, (const Vec *)&lbl_8050BF00);
                o->rotation_y = approach_angle_limited(o->rotation_y, ang, ((IllGillMovementParameters *)o->movementParameters)->turn);
            } else {
                o->requested_action = 0;
            }
        }
    }
    enemy_turn_toward_dest(o, ((IllGillMovementParameters *)o->movementParameters)->turn);
    enemy_set_heading_velocity(((IllGillMovementParameters *)o->movementParameters)->speed, (TObjEnemy *)(o), o->rotation_y);
    (*((Vec *)&o->m_2fc)).y += TObjEneIllGill__data_805E02DC;
    move_with_wall_slide((u8 *)o);
}

void TObjEneIllGill::clear_charge_hits() {
    for (s32 i = 0; i < 4; i++) {
        chargeHits[i] = NULL;
    }
}

s32 TObjEneIllGill::project_step_to_ground(s32 angle) {
    lbl_8050BF00.y = TObjEneIllGill__data_805E02BC;
    lbl_8050BF00.x = TObjEneIllGill__data_805E02BC;
    lbl_8050BF00.z = ((IllGillMovementParameters *)movementParameters)->speed;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, angle);
    rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
    pop_matrices(1);
    vec3_add_to(&lbl_8050BF00, &position);
    return project_actor_to_ground(this, &lbl_8050BF00, 0);
}

void TObjEneIllGill::vfunc_58() {
    switch (mode) {
    case 0:
        switch (phase) {
        case 0:
        case 1:
            break;
        default:
            phase = 2;
            if ((s32)fadingIn != 0) {
                phase = 0;
            }
            break;
        }
        break;
    default:
        mode = 0;
        if ((s32)fadingIn != 0) {
            phase = 0;
        } else {
            phase = 2;
        }
        requested_action = 1;
        free_resources();
        break;
    }
}

s32 TObjEneIllGill::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        switch (mode) {
        default: break;
        case 0:
            fadingIn = 0;
            phase = 0;
            requested_action = 1;
            obj_clearFlags30(0x04040000);
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneIllGill::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        switch (mode) {
        default: break;
        case 0:
            fadingIn = 0;
            phase = 0;
            requested_action = 1;
            obj_clearFlags30(0x04040000);
            break;
        }
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_loop_invariants off
void TObjEneIllGill::vfunc_28() {
    u16 best;
    s32 i;
    u8 *pl;
    u16 id;
    f32 bestDist;
    f32 d;
    u16 t;
    s32 ent;
    if (is_actor_cadence_frame(0x1E) != 0) {
        if (fadingIn != 0) {
            targetId = 0xFFFF;
            target = 0;
            return;
        }
        if (obj_testFlags30(0x10) != 0) {
            i = 0;
            best = 0xFFFF;
            Vec v = lbl_8047A328;
            bestDist = ((IllGillMovementParameters *)movementParameters)->range * ((IllGillMovementParameters *)movementParameters)->range;
            for (; i < registered_player_count + lbl_805D5870; i++) {
                pl = (u8 *)TObjPlayer::get_player_data(i);
                if (pl == NULL) break;
                if (obj_is_hit_receivable(pl) == 0) continue;
                id = get_entity_id(pl);
                if (id >= 0x4000) continue;
                if (id == entity_id) continue;
                if (((TObjChara *)pl)->actorFlags & 0x02000800) continue;
                VecCopy(&v, (const Vec *)(pl + offsetof(TObjChara, m_2fc)));
                subtract_vector(&v, &m_2fc);
                d = v.x * v.x + v.z * v.z;
                if (d < bestDist && check_path_obstructed(this, pl + offsetof(TObjChara, m_2fc)) == 0) {
                    best = id;
                    bestDist = d;
                }
            }
            targetId = best;
        } else {
            targetId = find_nearest_visible_player(this, 0, (f32 *)((IllGillMovementParameters *)movementParameters), ((IllGillMovementParameters *)movementParameters)->range);
        }
        t = targetId;
        if (t < 0x1000) {
            ent = get_player_by_client_id(t);
            if (ent != 0) {
                if (((TObjPlayer *)ent)->get_floor() == get_current_floor()) {
                    target = (u8 *)ent;
                    obj_clearFlags30(0x04040000);
                    return;
                }
            }
            target = 0;
            obj_setFlags30(this, 0x04040000);
            return;
        }
        if (t < 0x4000) {
            target = (u8 *)get_enemy_entity(t);
            obj_clearFlags30(0x04040000);
        }
    }
}
#pragma pop

void select_actor_lighting(s32 obj);

void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805E0300;
extern const f32 lbl_805E0304;
void TObjEneIllGill::render() {
    u8 *arg0 = (u8 *)this;

    if (((s32 (*)(void *))is_split_screen)(arg0) != 0) {
        TCameraCtrl::get_camera_mode();
    }
    this->viewDetail = classify_actor_view_detail(lbl_805E0300, lbl_805E0304, lbl_805E02F4);
    if (this->viewDetail != 0) {
        select_actor_lighting((s32)arg0);
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, this->scale.x, this->scale.y, this->scale.z);
        illGillModelNodeIndex = 0;
        set_chunk_model_node_callback((s32)((void *)TObjEneIllGill::capture_effect_positions));
        if (this->fadingIn != 0 && TObjPlayer::check_demo_mode() == 0) {
            if (fade.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                fade.set_flags_and_apply_damage_color();
                ((TObjMotion *)arg0)->draw();
                fade.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else if (this->viewDetail == 1) {
            ((TObjMotion *)arg0)->draw();
        } else {
            ((TObjEnemy *)arg0)->draw_motion_model();
        }
        set_chunk_model_node_callback((s32)NULL);
        VecCopy(&weaponEffectPosition, (const Vec *)&illGillWeaponEffectPosition);
        VecCopy(&shadowEffectPosition, (const Vec *)&illGillShadowEffectPosition);
        VecCopy(&chargeEffectPosition1, (const Vec *)&illGillChargeEffectPosition1);
        VecCopy(&chargeEffectPosition2, (const Vec *)&illGillChargeEffectPosition2);
        pop_matrix();
    }
}
void TObjEneIllGill::run_task() {
    TObjEneIllGill *o = this;
    switch (o->mode) {
    case 0:
        update_idle();
        break;
    case 1:
        update_forward_movement();
        break;
    case 2:
        update_chase_target();
        break;
    case 3:
        update_weapon_attack();
        break;
    case 4:
        update_charge_attack();
        break;
    case 5:
        update_shadow_attack();
        break;
    case 6:
        sub_803669B0();
        break;
    case 7:
        update_damage_recovery();
        break;
    case 8:
        update_death_fall();
        break;
    case 9:
        break;
    }
    if (o->target != NULL && (((TObjChara *)o->target)->actorFlags & 0x02000800)) {
        o->actionTimer = 0;
        o->actorFlags &= ~0x200000;
        o->target = NULL;
    }
    o->update_prev_position();
    ((TBoss3VoloptHiraisin *)o)->copy_position();
    submit_cursor_candidate(o, -1);
    o->m_2b4 += TObjEneIllGill__data_805E02CC;
}

void *TObjEneIllGill::create(void *setData) {
    TObjControl *parent = new TObjControl((TObject *)tl_04);
    return new TObjEneIllGill(parent, setData);
}

TObjEneIllGill::~TObjEneIllGill() {
    free_resources();
    free_collision_body_parts(this);
}

TObjEneIllGill::TObjEneIllGill(TObject *parent, void *setData) : TObjEnemy(parent) {
    u8 *self = (u8 *)this;
    m_name = (const char *)TObjEneIllGill_class_name;
    this->set_param(0x52);
    this->apply_set_data(setData);
    this->clear_lobby_object_state();
    ((TObjPlayer *)self)->init_position_vectors();
    apply_actor_gravity(self, 0, TObjEneIllGill__data_805E02BC);
    model = (void *)illGillResource->models->model;
    texlist = illGillResource->models->m_c;
    motion_list = illGillResource->motions;
    action_table = illGillActions;
    this->set_field_d8((s32)action_table);
    requested_action = 0;
    this->set_animation(requested_action);
    this->set_field_b8(requested_action);
    this->sub_8002AE64();
    scale.x = lbl_805E0308;
    scale.y = lbl_805E0308;
    scale.z = lbl_805E0308;
    this->add_flags_2e4(8);
    init_collision_body_parts(self, &illGillCollisionBody, 1);
    this->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    register_object_by_id();
    movementParameters = &illGillMovement;
    attackType = 0;
    this->bind_enemy_combat_stats((u8 *)TObjEneIllGill__boss_registration_id, (u8 *)ill_gill_combat_parameter_variants[attackType], (u8 *)lbl_805D6FD8);
    deathTimer = 0;
    mode = 0;
    phase = 0;
    weaponSpecial = 0;
    hitFrame = 0;
    weaponEffectPosition.z = TObjEneIllGill__data_805E02BC;
    weaponEffectPosition.y = TObjEneIllGill__data_805E02BC;
    weaponEffectPosition.x = TObjEneIllGill__data_805E02BC;
    shadowEffectPosition.z = TObjEneIllGill__data_805E02BC;
    shadowEffectPosition.y = TObjEneIllGill__data_805E02BC;
    shadowEffectPosition.x = TObjEneIllGill__data_805E02BC;
    chargeEffectPosition1.z = TObjEneIllGill__data_805E02BC;
    chargeEffectPosition1.y = TObjEneIllGill__data_805E02BC;
    chargeEffectPosition1.x = TObjEneIllGill__data_805E02BC;
    chargeEffectPosition2.z = TObjEneIllGill__data_805E02BC;
    chargeEffectPosition2.y = TObjEneIllGill__data_805E02BC;
    chargeEffectPosition2.x = TObjEneIllGill__data_805E02BC;
    tertiaryEffect = 0;
    secondaryEffect = 0;
    primaryEffect = 0;
    chargeDistance = TObjEneIllGill__data_805E02BC;
    chargeFrames = 0;
    viewDetail = 0;
    fade.reset_obstruction_fade();
    fadingIn = 1;
    this->clear_charge_hits();
    if (TObjEneIllGill__data_805E02BC != parameters[0]) {
        actorFlags |= 0x2000;
        target = 0;
        targetId = 0xFFFF;
        VecCopy((Vec *)&m_290, (const Vec *)&m_2fc);
        VecCopy((Vec *)&m_29c, (const Vec *)&m_2fc);
        chargeDistance = TObjEneIllGill__data_805E02BC;
    }
}

void TObjEneIllGill::free_effect() {
    TLobby__sub_8001FE7C(illGillResource, (void *)1);
    illGillResource = NULL;
}

struct IllGillSharedMotionSetup {
    BmlMotionEntry *motions;
    s32 unknown[3];
};
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern IllGillSharedMotionSetup lbl_8047A318;
void TObjEneIllGill::load_shared_resources() {
    void *p;
    BmlResource *resource;
    Vec *q;

    p = (void *)::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 1, &illGillResourceDescriptor, 0, 0, 0);
    }
    illGillResource = (BmlResource *)p;
    TObjEneIllGill__boss_registration_id = register_boss__6TLobbyFl(0x26);
    ill_gill_combat_parameter_variants[0] = (AttackParams *)dispatch_shared_handler_b__6TLobbyFl(0x26);
    ill_gill_combat_parameter_variants[1] = (AttackParams *)dispatch_shared_handler_b__6TLobbyFl(0x27);
    ill_gill_combat_parameter_variants[2] = (AttackParams *)dispatch_shared_handler_b__6TLobbyFl(0x28);
    ill_gill_combat_parameter_variants[3] = (AttackParams *)dispatch_shared_handler_b__6TLobbyFl(0x29);
    lbl_805D6FD8 = register_object__6TLobbyFl(0x26);
    illGillAttackBehavior = (IllGillAttackBehavior *)TLobby::dispatch_shared_handler_a(0x26);
    illGillModelNodeIndex = 0;
    q = &illGillWeaponEffectPosition;
    q->x = q->y = q->z = TObjEneIllGill__data_805E02BC;
    q = &illGillShadowEffectPosition;
    q->x = q->y = q->z = TObjEneIllGill__data_805E02BC;
    q = &illGillChargeEffectPosition1;
    q->x = q->y = q->z = TObjEneIllGill__data_805E02BC;
    q = &illGillChargeEffectPosition2;
    q->x = q->y = q->z = TObjEneIllGill__data_805E02BC;
    {
        IllGillSharedMotionSetup pos = lbl_8047A318;
        resource = illGillResource;
        pos.motions = resource->motions;
        TLobby::spawn_npc_enemy((s16)0x43, (s32)(resource->models->model), (s32)(resource->models->m_c), (s32)&pos, illGillCollisionBody.radius, (f32)TObjEneIllGill__data_805E02BC);
    }
}

}
