#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/map/CsnQuery.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/system/GinjaTextureMatrices.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

// Matrix-stack, vector and animation helpers and unowned globals without a usable header:
// text_803D96A8.h/text_803D853C.h/MatrixTransforms.h/TObjMotion.h includers declare these with
// conflicting private prototypes, the globals have no owning unit yet, and the
// MSL headers are not on this unit's include path (rand).
extern "C" {
int rand(void);
// TNpcPlayer_800D87A8.h declares it without the id its definition passes through.
TObjBase *find_active_entity_by_id(u16 id);
s32 push_matrix(void);
void post_translate_matrix(const f32 *offset);
void matrix_mult_vec(s32 matrix, const Vec *src, Vec *dst);
void vec3_add_to(Vec *dst, const Vec *add);
f32 vec3_dot(const Vec *a, const Vec *b);
void vec3_cross(const Vec *a, const Vec *b, Vec *out);
extern Mtx34 identity_matrix;
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
extern s32 registered_player_count;
extern s32 lbl_805D5870;
}

// The whole unit is built with deferred inlining, so the compiler emits the
// functions in reverse order: the last function here sits first in the DOL.

// The actor update() hits, with slot 25 as it is called here: the base declares
// apply_knockback_from_attacker(u8 *) without the strength.
struct TObjEnemyCustomVictim : public TObjCollidable {
    virtual s32 add_actor_exp(s32 exp);
    virtual s32 consume_timer_field(s32 frames);
    virtual s32 get_actor_level_index();
    virtual u8 *update_actor_ground_y();
    virtual u8 *vfunc_18(u8 *);
    virtual s32 is_actor_cadence_frame(s32 frame);
    virtual s32 select_melee_contact_body(TObject *attacker, f32 range);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, f32);
    virtual f32 receive_physical_attack(TObject *attacker, f32 scale);
    virtual f32 receive_direct_attack(void *, void *, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void apply_knockback_from_attacker(TObject *attacker, f32 strength);
};

static const char *TObjEnemyCustom_name = "TObjEnemyCustom";

static NJS_OBJECT **visible_node_cursor;
static s32 visible_node_count;

static void collect_visible_subtree(NJS_OBJECT *node);

TObjEnemyCustom::TObjEnemyCustom(TObject *parent) : TObjEnemy(parent) {
    m_name = TObjEnemyCustom_name;
    next_action = 0;
    m_378 = 0;
    state = 0;
    m_380 = 0;
    resetTimer = 15;
    timer = resetTimer;
    m_388 = 0;
}

TObjEnemyCustom::~TObjEnemyCustom() {
}

void TObjEnemyCustom::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
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
    update_prev_position();
    VecCopy(&center, body_center());
}

void TObjEnemyCustom::dispatch_state() {
    switch (mode) {
    case 0:
        update_state();
        return;
    case 1:
        update_wander_state();
        return;
    case 2:
        update();
        return;
    case 3:
        update_state_machine();
        return;
    case 4:
        update_knockback_state();
        return;
    case 5:
        update_dying_state();
        return;
    case 6:
        break;
    }
}

void TObjEnemyCustom::vfunc_28() {
}

void TObjEnemyCustom::vfunc_58() { ((TObjEneMe1GiGue *)this)->update_if_active(0); }

void TObjEnemyCustom::update_state() {
    switch (state) {
    case 0:
        this->requested_action = 0;
        state = 1;
    case 1:
        advance_animation();
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        break;
    case -1:
        actorFlags &= ~0x40000;
        break;
    }
}

void TObjEnemyCustom::vfunc_59() { ((TObjEneMe1GiGue *)this)->update_if_active(1); }

void TObjEnemyCustom::update_wander_state() {
    switch (state) {
    case -1:
        break;
    case 0:
        this->requested_action = 1;
        state = 1;
    case 1:
        advance_animation();
        if (target != NULL) {
            Vec dest = *((TObjChara *)target)->body_center();
            EnemyMoveParams *params = (EnemyMoveParams *)movementParameters;
            f32 distance = update_enemy_wander_move(this, &dest, 1, params, params->min_distance);
            params = (EnemyMoveParams *)movementParameters;
            if (params->max_distance < distance || distance < params->min_distance) {
                target = NULL;
            }
            turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, velocity());
        }
        apply_actor_gravity(this, NULL, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        return;
    }
}

void TObjEnemyCustom::vfunc_60() { ((TObjEneMe1GiGue *)this)->update_if_active(2); }

void TObjEnemyCustom::update() {
    switch (state) {
    case 0:
        this->requested_action = 2;
        actorFlags |= 0x200000;
        state = 1;
    case 1:
        enemy_turn_toward_dest(this, ((EnemyMoveParams *)movementParameters)->turn_speed);
        advance_animation();
        if (is_passing_frame(10.0f) != 0) {
            if (((TObjEnemyCustomVictim *)target)->select_melee_contact_body(this, 1.0f) != 0) {
                ((TObjEnemyCustomVictim *)target)->receive_physical_attack(this, 1.0f);
                ((TObjEnemyCustomVictim *)target)->apply_knockback_from_attacker(this, 3.0f);
            }
        }
        ((TObjPlayer *)this)->update_collisions();
        if (this->action_flags != 4) {
            state = -1;
        }
        return;
    case -1:
        next_action = 1;
        actorFlags &= ~0x200000;
        break;
    }
}

void TObjEnemyCustom::vfunc_61() {
}

void TObjEnemyCustom::update_state_machine() {
    s16 remaining;
    switch ((s32)state) {
    case 0:
        this->requested_action = 0;
        actorFlags &= ~0x600000;
        state = 1;
    case 1:
        advance_animation();
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        ((TObjPlayer *)this)->update_collisions();
        remaining = timer;
        timer = remaining - 1;
        if (remaining < 0) {
            state = -1;
        }
        break;
    case -1:
        actorFlags &= ~0x100;
        timer = resetTimer;
        referenceHp = hp;
        next_action = 1;
        break;
    }
}

void TObjEnemyCustom::vfunc_62() {
    ((TObjEneMe1GiGue *)this)->set_state(4);
    m_388 |= 1;
}

void TObjEnemyCustom::update_knockback_state() {
    switch (state) {
    case 0:
        actorFlags &= ~0x200000;
        this->requested_action = 3;
        state = 1;
    case 1:
        advance_animation();
        move_with_wall_slide((u8 *)this);
        velocity()->x *= 0.5f;
        m_310 *= 0.5f;
        apply_actor_gravity(this, NULL, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        if (this->action_flags != 8) {
            state = -1;
        }
        break;
    case -1:
        actorFlags &= ~0x200;
        m_388 &= ~1;
        referenceHp = hp;
        next_action = 1;
        break;
    }
}

void TObjEnemyCustom::vfunc_63() {
    ((TObjEneMe1GiGue *)this)->set_state(5);
    m_388 |= 1;
}

void TObjEnemyCustom::sub_800C7860() {
    ((TObjEneMe1GiGue *)this)->set_state(7);
    m_388 |= 1;
}

void TObjEnemyCustom::update_dying_state() {
    switch ((s32)state) {
    case -1:
        break;
    case 0:
        this->requested_action = 4;
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        if (this->frame < 0.5f * (30.0f * this->play_speed)) {
            move_with_wall_slide((u8 *)this);
            velocity()->x *= 0.5f;
            m_310 *= 0.5f;
        }
        break;
    default:
        break;
    }
}

void TObjEnemyCustom::render() {
    if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        model_render_flags &= ~0x400;
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(model);
        } else {
            draw();
        }
        if (!(actorFlags & 0x800)) {
            model_render_flags |= 0x400;
        }
        pop_matrix();
    }
}

void TObjEnemyCustom::run_demo_task() {
}

void TObjEnemyCustom::render_anim_model_at_pos() {
    push_matrix_from(identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    calc_joint_matrices(frame);
    pop_matrix();
}

void TObjEnemyCustom::get_anim_node_position(s32 node, Vec *out) {
    Vec origin = {0.0f, 0.0f, 0.0f};
    push_matrix_from(&anim_model_matrix_array[node]);
    matrix_mult_vec(0, &origin, out);
    pop_matrix();
}

s32 collect_visible_nodes(NJS_OBJECT *root, NJS_OBJECT **out) {
    NJS_OBJECT *sibling;
    if (root == NULL) {
        return 0;
    }
    if (out == NULL) {
        return 0;
    }
    sibling = root->sibling;
    root->sibling = NULL;
    visible_node_cursor = out;
    visible_node_count = 0;
    collect_visible_subtree(root);
    root->sibling = sibling;
    *visible_node_cursor = NULL;
    return visible_node_count;
}

static void collect_visible_subtree(NJS_OBJECT *node) {
    do {
        if (!(node->evalflags & NJD_EVAL_HIDE) && node->model != NULL) {
            *visible_node_cursor++ = node;
            visible_node_count++;
        }
        if (node->child != NULL) {
            collect_visible_subtree(node->child);
        }
        node = node->sibling;
    } while (node != NULL);
}

void hide_model_nodes(NJS_OBJECT **nodes) {
    while (*nodes != NULL) {
        NJS_OBJECT *node = *nodes++;
        node->evalflags |= NJD_EVAL_HIDE;
    }
}

void show_model_nodes(NJS_OBJECT **nodes) {
    while (*nodes != NULL) {
        NJS_OBJECT *node = *nodes++;
        node->evalflags &= ~NJD_EVAL_HIDE;
    }
}

s32 TObjEnemyCustom::turn_toward_point(Vec *point, s32 max_step, s32 angle_offset) {
    Vec delta = *point;
    subtract_vector(&delta, &position);
    angle_offset += (s32)(10430.38043493439 * atan2_float(delta.x, delta.z));
    rotation_y = approach_angle_limited(rotation_y, angle_offset, max_step);
    return angle_difference_abs(rotation_y, angle_offset);
}

void TObjEnemyCustom::sub_800C73F4() {
    if (xz_distance_squared(&position, &home_position) > 100.0f) {
        ((TObjEneMe1GiGue *)this)->update_if_active(8);
        return;
    }
    vfunc_58();
}

void TObjEnemyCustom::move_along_ground_avoiding_walls(Vec dest, f32 speed, f32 probe) {
    Vec probe_end;
    CsnHit *hit;
    s32 angle;
    s32 i;
    calc_velocity_toward_destination(this, *&position, dest, speed);
    VecCopy(&prev_position, &position);
    VecCopy(&probe_end, body_center());
    Vec step = *velocity();
    Vec up;
    Vec cross;
    Vec dir;
    Vec next;
    vec_set_length(&step, speed + probe);
    vec3_add_to(&probe_end, &step);
    hit = csnVector(body_center(), &probe_end, -1);
    if (hit != NULL) {
        vec3_dot(velocity(), &hit->contact->normal);
        angle = (s32)(10430.38043493439 * TObjPlayer::get_scale_factor());
        up.x = up.z = 0.0f;
        up.y = 1.0f;
        vec3_cross(velocity(), &hit->contact->normal, &cross);
        if (0.0f > vec3_dot(&up, &cross)) {
            angle = 0x10000 - angle;
        }
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, velocity(), velocity());
        pop_matrices(1);
    }
    if (3.0517578e-05f * (f32)rand() < 0.5f) {
        angle = -1;
    } else {
        angle = 1;
    }
    for (i = 0; i < 15; i++) {
        if (i == 0) {
            VecCopy(&dir, velocity());
        } else {
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, angle * (i * 0x1000));
            rotate_vector_by_matrix(0, velocity(), &dir);
            pop_matrices(1);
        }
        VecCopy(&next, &position);
        vec3_add_to(&next, &dir);
        if (project_actor_to_ground(this, &next, 0) == 1) {
            VecCopy(&position, &next);
            VecCopy(velocity(), &position);
            subtract_vector(velocity(), &prev_position);
            return;
        }
    }
}

BOOL TObjEnemyCustom::find_target_in_range(f32 radius) {
    if (obj_testFlags30(0x10) != 0) {
        return select_nearest_target(radius);
    }
    targetId = find_nearest_visible_player(this, NULL, radius);
    target = (u8 *)get_player_by_client_id(targetId);
    return has_target();
}

BOOL TObjEnemyCustom::select_nearest_target(f32 radius) {
    u16 player;
    u16 enemy;
    f32 player_distance;
    player = find_nearest_visible_player(this, NULL, radius);
    enemy = find_nearest_enemy(NULL, radius);
    if (player == 0xFFFF) {
        targetId = 0xFFFF;
    } else if (enemy == 0xFFFF) {
        targetId = player;
    } else {
        player_distance = xz_distance_squared(&position, (Vec *)&find_entity_by_id(player)->position);
        targetId = player_distance < xz_distance_squared(&position, (Vec *)&find_entity_by_id(enemy)->position)
                       ? player
                       : enemy;
    }
    target = (u8 *)find_active_entity_by_id(targetId);
    if (target != NULL) {
        return TRUE;
    }
    return FALSE;
}

u16 TObjEnemyCustom::find_nearest_enemy(Vec *out, f32 radius) {
    Vec offset;
    u16 best;
    s32 i;
    TObjChara *entity;
    f32 best_distance;
    f32 distance;
    u16 id;
    best_distance = radius * radius;
    best = 0xFFFF;
    for (i = registered_player_count; i < registered_player_count + lbl_805D5870; i++) {
        entity = (TObjChara *)TObjPlayer::get_player_data(i);
        if (entity == NULL) {
            break;
        }
        id = get_entity_id(entity);
        if (id == entity_id) {
            continue;
        }
        if (id < 0x1000 || id >= 0x4000) {
            continue;
        }
        if (entity->actorFlags & 0x2000800) {
            continue;
        }
        distance = calc_xz_distance_sq(this, entity, &offset);
        if (distance < best_distance) {
            best = get_entity_id(entity);
            best_distance = distance;
            if (out != NULL) {
                VecCopy(out, &offset);
            }
        }
    }
    return best;
}

void TObjEnemyCustom::target_nearest_player(f32 radius) {
    s32 count;
    u16 best;
    s32 i;
    f32 best_distance;
    f32 distance;
    TObjEnemyCustom *entity;
    best_distance = radius * radius;
    best = 0xFFFF;
    if (obj_testFlags30(0x10) != 0) {
        count = registered_player_count + lbl_805D5870;
    } else {
        count = registered_player_count;
    }
    for (i = 0; i < count; i++) {
        entity = (TObjEnemyCustom *)TObjPlayer::get_player_data(i);
        if (entity != this && entity != NULL && target != (u8 *)entity) {
            distance = xz_distance_squared(entity->body_center(), body_center());
            if (distance < best_distance) {
                best_distance = distance;
                best = i;
            }
        }
    }
    targetId = best;
    target = (u8 *)find_active_entity_by_id(targetId);
}

u16 TObjEnemyCustom::pick_random_nearby_player(f32 radius) {
    u16 candidates[32];
    s32 found;
    s32 count;
    s32 i;
    f32 radius_sq;
    TObjEnemyCustom *entity;
    radius_sq = radius * radius;
    found = 0;
    if (obj_testFlags30(0x10) != 0) {
        count = registered_player_count + lbl_805D5870;
    } else {
        count = registered_player_count;
    }
    for (i = 0; i < count; i++) {
        entity = (TObjEnemyCustom *)TObjPlayer::get_player_data(i);
        if (entity == this) {
            continue;
        }
        if (entity == NULL) {
            break;
        }
        if (xz_distance_squared(entity->body_center(), body_center()) < radius_sq) {
            candidates[found++] = i;
            if (found >= 32) {
                break;
            }
        }
    }
    if (found == 0) {
        return 0xFFFF;
    }
    return candidates[(s32)((f32)found * random_ratio())];
}

void TObjEnemyCustom::vfunc_79(s32 *state) {
    s16 saved_mode = mode;
    TObjEnemy::vfunc_79(state);
    mode = saved_mode;
}

extern "C" u8 is_local_client_floor_leader(void) {
    TObjPlayer *player;
    s32 id;
    s32 i;
    if (get_main_phase() == 15) {
        player = get_player_by_client_id(TLobby__designated_client_id);
        if (player != NULL) {
            if (player->get_floor() == get_current_floor()) {
                return local_client_id == TLobby__designated_client_id;
            }
        }
        for (i = 0; i < 4; i++) {
            id = (TLobby__designated_client_id + i + 1) % 4;
            player = get_player_by_client_id(id);
            if (player != NULL) {
                if (player->get_floor() == get_current_floor()) {
                    break;
                }
            }
        }
        return local_client_id == id;
    }
    return 1;
}

void TObjEnemyCustom::pick_open_direction(f32 *dir, f32 reach, f32 radius) {
    Vec eye;
    f32 heading;
    f32 best;
    s32 angle;
    s32 best_angle;
    s32 i;
    CsnHit *hit;
    f32 clearance;
    heading = atan2_float(dir[0], dir[2]);
    best = 10.0f;
    angle = (s32)(10430.38043493439 * heading);
    best_angle = angle;
    VecCopy(&eye, &position);
    eye.y += 5.0f;
    push_matrix_from(identity_matrix);
    {
        Vec probe = {reach + radius, 0.0f, 0.0f};
        rotate_matrix_y(0, angle);
        for (i = 0; i < 3; i++) {
            matrix_mult_vec(0, &probe, destination());
            vec3_add_to(destination(), &eye);
            hit = csnVector(&eye, destination(), -1);
            if (hit == NULL) {
                pop_matrix();
                return;
            }
            clearance = vec_xz_distance(&position, &hit->contact->point) - radius;
            if (best < clearance) {
                best = clearance;
                best_angle = angle;
            }
            rotate_matrix_y(0, 0x5555);
            angle += 0x5555;
        }
    }
    pop_matrix();
    push_matrix_from(identity_matrix);
    {
        Vec offset = {best, 0.0f, 0.0f};
        rotate_matrix_y(0, best_angle);
        matrix_mult_vec(0, &offset, destination());
    }
    vec3_add_to(destination(), &eye);
    pop_matrix();
}

void TObjEnemyCustom::release_destroyed_target() {
    if (target != NULL && (((TObjBase *)target)->actorFlags & 0x800)) {
        target = NULL;
        targetId = 0xFFFF;
    }
}
