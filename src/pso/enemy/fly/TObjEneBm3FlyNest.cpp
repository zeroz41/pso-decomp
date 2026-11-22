#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest_CarryFly.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/fly/TObjEneBm3Fly.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/camera/TCameraCtrl.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

extern "C" {

struct Ent_800B23A0 { s32 a; u32 count; };

struct Pair_800B23A0 { s32 k; Ent_800B23A0 *e; };

void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
void TBoss8Dragon__sub_800BB7D4(void *self, int id);
s32 set_field_e4__10TObjPlayerFll(void *, int, f32);
void spawn_dead_spot_scale15(s32 point, s32 delay);
void free_collision_body_parts(void *);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
s32 play_sound_effect(s32, void *, int, int);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
s32 vec3_add_to(void *, void *);
s32 post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);

Bm3FlyMovementParameters bm3_fly_nest_params = { 225.0f, 0.0f, 0x600, { 0, 0, 0, 0 } };
CollisionBody bm3_flynest_collider_params[1] = {
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003},
};
const char *bm_ene_bm3_fly_model_names[3] = { "bm3_fly_body.nj", "bm3_s_nest.nj", NULL };
const char *bm_ene_bm3_fly_motion_names[16] = { "atack_bm3_fly_body.njm", "damage_bm3_fly_body.njm", "dam_bm3_s_nest.njm", "dead_bm3_fly_body.njm", "dead_bm3_s_nest.njm", "down_bm3_s_nest.njm", "dwndam_bm3_s_nest.njm", "dwnexit_bm3_s_nest.njm", "dwnwait_bm3_s_nest.njm", "exit_bm3_s_nest.njm", "fly_bm3_fly_body.njm", "land_bm3_s_nest.njm", "move_bm3_fly_body.njm", "trance_bm3_s_nest.njm", "wait_bm3_s_nest.njm", NULL };
BmlResourceDescriptor bm3_fly_nest_resource_desc = { "bm_ene_bm3_fly.bml", bm_ene_bm3_fly_model_names, bm_ene_bm3_fly_motion_names, 2, 15 };
TObjMotionAction bm3_flynest_hit_action_table[10] = {
    { 1, 0, 0xE, 0.3f, 0x0 },
    { 3, 0, 0x9, 0.7f, 0x0 },
    { 3, 0, 0x2, 1.0f, 0x0 },
    { 3, 0, 0x5, 0.5f, 0x0 },
    { 1, 0, 0x8, 0.3f, 0x0 },
    { 3, 0, 0x7, 0.7f, 0x0 },
    { 3, 0, 0x6, 1.0f, 0x0 },
    { 3, 0, 0x4, 0.3f, 0x0 },
    { 1, 0, 0xD, 0.3f, 0x0 },
    { 3, 0, 0xB, 0.2f, 0x0 },
};
static const s32 bm3_fly_nest_attachment_sample_table[8] = { 2, 4, 9, 11, 16, 18, 24, 26 };
const char *bm3_fly_nest_class_name = "TObjEneBm3FlyNest";
const char *TObjEneBm3FlyNest_CarryFly__name = "TObjEneBm3FlyNest_CarryFly";
typedef struct Ctl_800B47C4 {
    f32 *pv;
    s32 *pc;
    s32 d;
    s32 e;
    s32 f;
} Ctl_800B47C4;
Vec TObjEneBm3FlyNest__attachment_sample_origin;
f32 fly_nest_vertex_table[6];
__declspec(section ".data") s32 lbl_80500B24[2];
Ctl_800B47C4 lbl_80500B2C;
extern saddr debug_chunk_object;
u8 *lbl_805D50F8;
u8 *lbl_805D50FC;
u8 *lbl_805D5100;
void *lbl_805D5104;
BmlResource *lbl_805D5108;
s32 lbl_805D510C;
Vec *TObjEneBm3FlyNest_attachment_point_ptr;
Vec *lbl_805D5114;
s32 bm3_fly_nest_attachment_index;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern s32 model_render_flags;
}

#pragma defer_codegen on

void TObjEneBm3FlyNest::init_vertex_table() {
    f32 *v = fly_nest_vertex_table;
    v[3] = v[2] = v[1] = v[0] = 0.0f;
    v[5] = v[4] = 6.0f;
    lbl_80500B24[0] = -1;
    lbl_80500B24[1] = -1;
    lbl_80500B2C.pv = fly_nest_vertex_table;
    lbl_80500B2C.pc = lbl_80500B24;
    lbl_80500B2C.d = 0;
    lbl_80500B2C.e = 2;
}

TObjEneBm3FlyNest_CarryFly::TObjEneBm3FlyNest_CarryFly(TObject *parent, Vec *origin, Vec *target, Vec *unused, s32 *arrived, s32 index) : TObject(parent) {
    Vec v;
    m_name = TObjEneBm3FlyNest_CarryFly__name;
    this->origin = origin;
    this->target = target;
    this->arrived = arrived;
    this->index = index;
    VecCopy(&v, this->origin);
    subtract_vector(&v, this->target);
    normalize_vector_safe(&v);
    angle = (s32) (10430.38043493439 * atan2_float(v.x, v.z));
    offset.x = 6.0f * v.x;
    offset.y = 6.0f;
    offset.z = 6.0f * v.z;
    motion = lbl_805D5108->motions[10].motion;
    frame = (f32) (this->index * 2);
    unk_3C = 1.0f;
    unk_44 = 0;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    distance = 0.0f;
    height = 0.0f;
    arc = 0.0f;
    state = 0;
}


TObjEneBm3FlyNest_CarryFly::~TObjEneBm3FlyNest_CarryFly() {}

#pragma push
#pragma fp_contract on
void TObjEneBm3FlyNest_CarryFly::run_task() {
    f32 lim;
    f32 v;
    f32 spd;

    lim = (motion->frameCount - 1);
    frame += 0.8f;
    if (frame > lim) {
        frame -= lim;
    }
    switch (state) {
    case 0:
        if (*arrived == index) {
            Vec tmp;
            state = 1;
            VecCopy(&tmp, &offset);
            vec3_add_to(&tmp, origin);
            VecCopy(&velocity, &tmp);
            subtract_vector(&velocity, target);
            velocity.y -= 5.0f;
            VecCopy(&offset, &velocity);
            distance = normalize_vector_xz(&velocity);
            if (distance <= 0.01f) {
                queue_destruction();
                break;
            }
            arc = (-120.0f) / (distance * distance);
            height = 30.0f;
        }
        play_persistent_sound(((TObjEneBm3FlyNest *)m_up)->copy_target_state(0x4003A828), (saddr)this, (uaddr)origin, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    case 1:
        offset.y += 1.0f;
        if (offset.y > 0.0f) {
            state = 2;
            velocity.y = 0.5f * distance;
        }
        play_persistent_sound(((TObjEneBm3FlyNest *)m_up)->copy_target_state(0x4003A828), (saddr)this, (uaddr)origin, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    case 2:
        spd = distance;
        v = velocity.y;
        v = v - 0.05f * spd;
        if (v < 0.5f * -spd) {
            spawn_particle_effect(target, 0xC8);
            ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(((TObjEneBm3FlyNest *)m_up)->copy_target_state(0x4003AB27), target, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
            queue_destruction();
            break;
        }
        offset.y = arc * (v * v) + height;
        velocity.y = v;
        v += 0.5f * distance;
        offset.x = velocity.x * v;
        offset.z = velocity.z * v;
        play_persistent_sound(((TObjEneBm3FlyNest *)m_up)->copy_target_state(0x4003A828), (saddr)this, (uaddr)target, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    }
}
#pragma pop

void TObjEneBm3FlyNest_CarryFly::render() {
    TObjFish::set_global_param((saddr)lbl_805D5108->models[0].m_c);
    push_matrix();
    if (state == 0) {
        post_translate_matrix(origin);
    } else {
        post_translate_matrix(target);
    }
    post_translate_matrix(&offset);
    rotate_matrix_y(0, angle);
    set_motion_packed_rotation();
    draw_model_motion((void *)lbl_805D5108->models[0].model, motion, frame);
    clear_motion_packed_rotation();
    pop_matrix();
}

void TObjEneBm3FlyNest::load_resources() {
    BmlModelEntry *models;
    TObjEneBm3FlyNest__attachment_sample_origin.x = 0.0f;
    TObjEneBm3FlyNest__attachment_sample_origin.y = 0.0f;
    TObjEneBm3FlyNest__attachment_sample_origin.z = 0.0f;
    lbl_805D510C = 0;
    TObjEneBm3FlyNest_attachment_point_ptr = NULL;
    lbl_805D5114 = NULL;
    bm3_fly_nest_attachment_index = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        lbl_805D5108 = load_enemy_bml_resource_named(&bm3_fly_nest_resource_desc, "bm_ene_bm3_fly_a.bml");
    } else {
        lbl_805D5108 = load_enemy_bml_resource(&bm3_fly_nest_resource_desc);
    }
    lbl_805D50F8 = (u8 *)TLobby::register_boss(1);
    lbl_805D50FC = (u8 *)TLobby::dispatch_shared_handler_b(1);
    lbl_805D5100 = (u8 *)TLobby::register_object(1);
    lbl_805D5104 = TLobby::dispatch_shared_handler_a(1);
    TObjEneBm3Fly::load_resources();
    TObjEneBm3FlyNest::init_vertex_table();
    {
        NpcAnimationBinding anim = { NULL, reinterpret_cast<TObjMotionAction *>(bm3_flynest_hit_action_table), 0, 8, 10 };
        anim.motions = reinterpret_cast<BmlMotionEntry *>(lbl_805D5108->motions);
        models = lbl_805D5108->models;
        NpcModelRegistry::register_animated_chunk(8, reinterpret_cast<void *>(models[1].model), reinterpret_cast<void *>(models[0].m_c), &anim, bm3_flynest_collider_params[0].radius, 0.0f);
    }
}

void *TObjEneBm3FlyNest::create(void *set_data) {
    return new TObjEneBm3FlyNest((TObject *)tl_04, (Bm3FlyNestSetData *)set_data);
}

void TObjEneBm3FlyNest::free_fly() {
    TObjEneBm3Fly::release_shared_data();
    if (lbl_805D5108 != NULL) {
        delete lbl_805D5108;
        lbl_805D5108 = NULL;
    }
}

BmlResource *TObjEneBm3FlyNest::sub_800B4158() { return lbl_805D5108; }

#pragma push
#pragma opt_loop_invariants off
TObjEneBm3FlyNest::TObjEneBm3FlyNest(TObject *parent, Bm3FlyNestSetData *set_data) : TObjEneDD(parent) {
    s32 i;

    m_name = bm3_fly_nest_class_name;
    invoke_initialization_hook(set_data);
    init_position_vectors();
    model = (void *)lbl_805D5108->models[1].model;
    texlist = (saddr)lbl_805D5108->models[0].m_c;
    init_model(bm3_flynest_collider_params, 1);
    body_center.y = 20.0f + position.y;
    update_body_colliders();
    set_field_d8((saddr)bm3_flynest_hit_action_table);
    set_field_dc((saddr)lbl_805D5108->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp(lbl_805D50F8, lbl_805D50FC, lbl_805D5100);
    set_state_flag_1();
    movementParameters = &bm3_fly_nest_params;
    initialize_enemy_state(4);
    wall_reach = 10.0f;
    init_params();
    if (total_num > set_data->unknown_02) {
        total_num = set_data->unknown_02;
    }
    for (i = 0; i < 4; i++) {
        unk_398[i] = 0;
    }
    unk_3a8 = 0;
    unk_3ac = 0;
    child_count = 0;
    spawned_count = 0;
    next_child_id = entity_id + 1;
    for (i = 0; i < 6; i++) {
        child_ids[i] = 0xFFFF;
    }
    for (i = 0; i < 2; i++) {
        VecCopy(&unk_3c8[i], &position);
    }
    unk_3c8[1].y += 25.0f;
    for (i = 0; i < 8; i++) {
        VecCopy(&unk_3e0[i], &position);
    }
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    unk_4b0 = 0.0f;
    unk_4b4 = 0;
    unk_4b8 = 0;
    unk_4bc = 0;
    unk_4c0 = 0;
    unk_4c4 = 0;
    unk_4c8 = 0;
    unk_4cc = 0;
    unk_4d0 = 0;
    unk_4d4 = 0;
    unk_4d8 = 0.0f;
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneBm3FlyNest::~TObjEneBm3FlyNest() {
    free_collision_body_parts(this);
}

#pragma push
#pragma fp_contract on
void TObjEneBm3FlyNest::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        init();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
    } else if (this->mode == 0) {
        transition_enemy_state(1);
    }
    this->update_body_colliders();
    this->copy_pos();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
}
#pragma pop

void TObjEneBm3FlyNest::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 1:
        state_initial_emit(reason);
        return;
    case 0:
        handle_appear(reason);
        return;
    case 2:
        state_wait(reason);
        return;
    case 3:
        handle_event(reason);
        return;
    case 4:
        sub_800B318C(reason);
        return;
    case 5:
        update_state(reason);
        return;
    case 6:
        state_spawn(reason);
        return;
    case 7:
        handle_motion_event(reason);
        return;
    case 8:
        state_dying(reason);
        return;
    case 9:
        handle_state(reason);
    default:
        return;
    }
}

void TObjEneBm3FlyNest::refresh_target() {  }

void TObjEneBm3FlyNest::run_death_reaction() {
    s16 m;

    m = mode;
    if ((m != 9) && (m != 8) && (m != 4)) {
        if (unk_3a8 == 0) {
            transition_enemy_state(4);
            return;
        }
        transition_enemy_state(8);
    }
}

void TObjEneBm3FlyNest::run_hit_reaction() {
    s16 m;

    if ((mode == 3) && (TObjEneDD::check_v2_mode() != 0)) {
        clear_attack_receipts();
        return;
    }
    m = mode;
    if (m == 4) {
        clear_attack_receipts();
        return;
    }
    if (m != 7) {
        transition_enemy_state(7);
    }
}

void TObjEneBm3FlyNest::run_miss_reaction() {  }

void TObjEneBm3FlyNest::copy_pos() { VecCopy(&center, &body_center); }

void TObjEneBm3FlyNest::update_body_colliders() { set_part_local_pos(&body_center, 0); }

void TObjEneBm3FlyNest::update_replenish() {
    s32 room_left;
    s32 total_left;
    s32 n;
    switch (unk_4b4) {
    case 0:
        if ((child_count <= start_num / 2) || (unk_3a8 != 0)) {
            unk_4b4 = 1;
            unk_4bc = 0;
        }
        return;
    case 1:
        if (unk_4c0 > 0) {
            unk_4bc = unk_4bc + 1;
            if (unk_4bc > unk_4c4) {
                unk_4bc = 0;
                n = unk_4c0;
                room_left = 6 - child_count;
                if (room_left < n) {
                    n = room_left;
                }
                total_left = total_num - spawned_count;
                if (total_left < n) {
                    n = total_left;
                }
                unk_4b8 = n;
                return;
            }
        }
        break;
    }
}

s32 TObjEneBm3FlyNest::sub_800B3AC8() {
    return unk_4b8 > 0;
}

void TObjEneBm3FlyNest::spawn_child() {
    Vec velocity = {0.0f, 3.0f, 0.0f};
    Vec pos;
    saddr n;
    if (child_count <= 6) {
        n = (set_index + 1) + spawned_count;
        VecCopy(&pos, sub_800B2A54());
        if (((TObjEneBm3Fly *)this)->create(next_child_id, n, &pos, &velocity) != 0) {
            child_ids[child_count++] = next_child_id;
            next_child_id++;
            spawned_count++;
            spawn_particle_effect(&unk_3c8[1], 0xC8);
            play_sound_effect(remap_sound_for_area(0x4003AB27), &position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
        }
    }
}

void TObjEneBm3FlyNest::init_params() {
    s32 n;
    s32 total;

    state = 2;
    start_num = (s32)parameters[1];
    n = start_num;
    if (n < 0) {
        start_num = 0;
    } else if (n > 6) {
        start_num = 6;
    }
    total_num = (s32)parameters[2];
    total = total_num;
    if (total < 0) {
        total_num = 0;
        return;
    }
    if (total > 0x1E) {
        total_num = 0x1E;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm3FlyNest::handle_appear(s32 reason) {
    s32 *cnt = &unk_4cc;
    s32 i;

    switch (reason) {
    case 4:
        requested_action = 8;
        set_intangible();
        set_field_378(2);
        unk_4b0 = 100.0f;
        unk_4c8 = 0;
        unk_4d0 = 0;
        unk_4d4 = 0;
        break;
    case 3:
        if (unk_4d0 == 2 && get_flag_b4() != 0) {
            transition_enemy_state(1);
        }
        break;
    case 0:
        advance_animation();
        switch (unk_4d0) {
        case 0:
            unk_4c8 += 1;
            if (unk_4c8 == 1) {
                *cnt = 0;
                for (i = 0; i < 6; i++) {
                    new TObjEneBm3FlyNest_CarryFly(this, &unk_3e0[i], &unk_3c8[1], &position, cnt, i + 1);
                }
            }
            unk_4b0 = unk_4b0 - ((0.3f * (1.0f + sin_table_lookup(unk_4d4))) + 0.2f);
            unk_4d4 += 0x700;
            if (unk_4b0 < 18.0f && requested_action != 9) {
                requested_action = 9;
            }
            if (unk_4b0 < -5.0f) {
                unk_4b0 = -5.0f;
                unk_4d0 = 1;
                unk_4c8 = 0;
                spawn_particle_effect(&position, 0xF0);
                play_sound_effect(remap_sound_for_area(0x4003B72A), &position, 0, 0);
            }
            break;
        case 1:
            unk_4c8 += 1;
            if (unk_4c8 > 3) {
                unk_4c8 = 0;
                *cnt += 1;
                if (*cnt >= 6) {
                    unk_4d0 = 2;
                }
            }
            break;
        }
        update_ground_contact();
        break;
    case 5:
        *cnt = 6;
        break;
    }
}
#pragma pop

void TObjEneBm3FlyNest::state_initial_emit(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 0;
        set_intangible();
        set_field_378(2);
        unk_4b0 = -5.0f;
        unk_4c8 = 0;
        unk_4cc = 0;
        unk_4d0 = 0;
        break;
    case 3:
        advance_animation();
        if (unk_4d0 == 3) {
            switch (state) {
            case 2:
                transition_enemy_state(state);
                break;
            case 5:
                transition_enemy_state(state);
                break;
            case 9:
                requested_action = 7;
                advance_animation();
                frame = 2.0f;
                advance_animation();
                frame = frame_count - 1.0f;
                actorFlags |= 0x800;
                unk_3a8 = 1;
                transition_enemy_state(state);
                break;
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        unk_4c8 += 1;
        switch (unk_4d0) {
        case 0:
            if (unk_4c8 > 0x3C) {
                unk_4d0 = 2;
                requested_action = 1;
            }
            break;
        case 1:
            if (is_passing_frame(15.0f) != 0) {
                unk_4d0 = 2;
            }
            break;
        case 2:
            if (get_flag_b4() != 0) {
                requested_action = 0;
            }
            if ((unk_4c8 % 10) == 0) {
                if (unk_4cc < start_num) {
                    spawn_child();
                    unk_4cc += 1;
                } else {
                    unk_4d0 = 3;
                }
            }
            break;
        }
        break;
    }
}

void TObjEneBm3FlyNest::state_wait(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 0;
        clear_intangible();
        set_field_378(2);
        unk_4b0 = -5.0f;
        unk_4c0 = 1;
        unk_4c4 = 0x96;
        return;
    case 3:
        if (sub_800B3AC8() != 0) {
            transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        update_replenish();
        update_ground_contact();
        break;
    }
}

void TObjEneBm3FlyNest::handle_event(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        set_field_378(2);
        unk_4b0 = -5.0f;
        return;
    case 3:
        if (motion_flags & 0x10) {
            transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (is_passing_frame(15.0f) != 0) {
            spawn_child();
            unk_4b8 = unk_4b8 - 1;
        }
        update_ground_contact();
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TObjEneBm3FlyNest::sub_800B318C(s32 reason) {
    Vec pos;
    s32 angle;
    switch (reason) {
    case 4:
        set_invulnerable();
        requested_action = 3;
        clear_intangible();
        set_field_378(5);
        unk_4b0 = -5.0f;
        break;
    case 3:
        if (motion_flags & 0x10) {
            transition_enemy_state(5);
            break;
        }
        break;
    case 0:
        advance_animation();
        if ((is_passing_frame(10.0f) != 0) || (is_passing_frame(28.0f) != 0)) {
            play_sound_effect(remap_sound_for_area(0x4003B72A), &position, 0, 0);
        }
        if (is_passing_frame(9.0f) != 0) {
            spawn_particle_effect(&position, 0xF0);
        } else if (is_passing_frame(27.0f) != 0) {
            angle = rotation_y - 0x4000;
            VecCopy(&pos, &position);
            pos.x += 16.0f * sin_table_lookup(angle);
            pos.z += 16.0f * cos_table_lookup(angle);
            spawn_particle_effect(&pos, 0xF0);
        }
        unk_4b0 += 0.1f;
        if (unk_4b0 > 0.0f) {
            unk_4b0 = 0.0f;
        }
        update_ground_contact();
        break;
    case 5:
        clear_invulnerable();
        break;
    }
}
#pragma pop

void TObjEneBm3FlyNest::update_state(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 4;
        clear_intangible();
        set_field_378(5);
        unk_4b0 = 0.0f;
        if (unk_3a8 == 0) {
            unk_3a8 = 1;
            unk_4c0 = 2;
            unk_4c4 = 0x78;
        }
        break;
    case 5:
        break;
    case 3:
        if (sub_800B3AC8() != 0) {
            transition_enemy_state(6);
            return;
        }
        break;
    case 0:
        advance_animation();
        update_replenish();
        update_ground_contact();
        break;
    }
}

void TObjEneBm3FlyNest::state_spawn(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 5;
        clear_intangible();
        set_field_378(5);
        unk_4b0 = 0.0f;
        return;
    case 3:
        if (motion_flags & 0x10) {
            transition_enemy_state(5);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        if (is_passing_frame(15.0f) != 0) {
            spawn_child();
            unk_4b8 = unk_4b8 - 1;
        }
        advance_animation();
        update_ground_contact();
        break;
    }
}

void TObjEneBm3FlyNest::handle_motion_event(s32 reason) {
    switch (reason) {
    case 4:
        clear_intangible();
        ((TBoss8Dragon *)this)->noop();
        TBoss8Dragon__sub_800BB7D4(this, 0xF1);
        play_sound_effect(remap_sound_for_area(0x4003A829), &position, 0, 0);
        if (unk_3a8 != 0) {
            requested_action = 6;
            unk_4b0 = 0.0f;
            return;
        }
        requested_action = 2;
        unk_4b0 = -5.0f;
        return;
    case 3:
        if (get_flag_b4() != 0) {
            if (unk_3a8 != 0) {
                transition_enemy_state(5);
                return;
            }
            if (hp <= hpmax / 2) {
                transition_enemy_state(4);
                return;
            }
            transition_enemy_state(next_mode);
            return;
        }
        break;
    case 0:
        advance_animation();
        update_ground_contact();
        return;
    case 5:
        clear_attack_receipts();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm3FlyNest::state_dying(s32 reason) {
    Vec v;
    Vec p;
    f32 r;
    s32 a;
    switch (reason) {
    case 4:
        requested_action = 7;
        clear_intangible();
        unk_4b0 = 0.0f;
        ((TObjPlayer *)this)->refresh_lobby_state();
        unk_4c8 = 4;
        unk_4cc = 0x14;
        unk_4d0 = 0;
        unk_4d8 = 0.0f;
        break;
    case 3:
        if (unk_4d8 >= 20.0f) {
            transition_enemy_state(9);
        }
        break;
    case 5:
        break;
    case 0:
        switch (unk_4d0) {
        case 0:
            advance_animation();
            if (get_flag_b4() != 0) {
                unk_4d0 = 1;
                v.x = -10.0f;
                v.y = 0.0f;
                v.z = -8.0f;
                rotate_xz_pair_by_angle(&v.x, &v.z, rotation_y);
                vec3_add_to(&v, &position);
                spawn_dead_spot_scale15((saddr)&v, 0x32);
                set_field_e4__10TObjPlayerFll(&v, 0x46, 10.0f);
            }
            if (frame < 25.0f) {
                unk_4c8 += 1;
                if (unk_4c8 >= 4) {
                    r = rand_range(5.0f, 10.0f);
                    a = get_random_scaled();
                    VecCopy(&p, &body_center);
                    p.x = r * sin_table_lookup(a) + p.x;
                    p.y += 5.0f;
                    p.z = r * cos_table_lookup(a) + p.z;
                    spawn_particle_effect(&p, 0xF1);
                    unk_4c8 = 0;
                }
                unk_4cc += 1;
                if (unk_4cc >= 0x14) {
                    play_sound_effect(remap_sound_for_area(0x4003AD2B), &position, 0, 0);
                    unk_4cc = 0;
                }
            }
            update_ground_contact();
            break;
        case 1:
            unk_4d8 += 0.1f;
            position.y -= 0.1f;
            break;
        }
        break;
    }
}
#pragma pop

void TObjEneBm3FlyNest::handle_state(s32 reason) {
    switch (reason) {
    case 4:
        set_intangible();
        return;
    case 3:
        if (child_count == 0) {
            send_entity_set_flags();
            queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}

s32 TObjEneBm3FlyNest::has_free_attack_slot(u16 id) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < child_count; i++) {
        u8 *p = (u8 *)find_entity_by_id(child_ids[i]);
        if (p != 0 && id == ((TObjEneBm3Fly *)p)->get_active_id()) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode()) {
        return n < 4;
    }
    return n < 2;
}

void TObjEneBm3FlyNest::remove_child(u8 *child) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(child_ids[i]) == reinterpret_cast<TObjCollidable *>(child)) {
            child_count--;
            child_ids[i] = child_ids[child_count];
            child_ids[child_count] = 0xFFFF;
            return;
        }
    }
}

Vec *TObjEneBm3FlyNest::sub_800B2A54() { return &unk_3c8[1]; }

s32 TObjEneBm3FlyNest::copy_target_state(s32 sound_id) { return remap_sound_for_area(sound_id); }

void TObjEneBm3FlyNest::init() { init_params(); }

void TObjEneBm3FlyNest::capture_attachment(NJS_OBJECT *_w0) {
    switch (lbl_805D510C) {
    case 36: case 45:
        forward_transform_to_view(&TObjEneBm3FlyNest__attachment_sample_origin, TObjEneBm3FlyNest_attachment_point_ptr++);
        break;
    }
    ++lbl_805D510C;
}

void TObjEneBm3FlyNest::handle_attachment_sample(NJS_OBJECT *arg0) {
    Vec *pos;
    if (lbl_805D510C == bm3_fly_nest_attachment_sample_table[bm3_fly_nest_attachment_index]) {
        pos = lbl_805D5114;
        bm3_fly_nest_attachment_index += 1;
        lbl_805D5114 = pos + 1;
        forward_transform_to_view(&TObjEneBm3FlyNest__attachment_sample_origin, pos);
    }
    TObjEneBm3FlyNest::capture_attachment(arg0);
}

void TObjEneBm3FlyNest::render() {
    RenderFadeState *cm;
    s32 cam;
    s32 res;
    s32 visible;
    f32 t;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_with_state_debug();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    unk_3ac = 0;
    if (mode != 9) {
        if (TObjEneDD::is_main_phase_15() != 0) {
            res = classify_actor_view_detail(25.0f + lbl_805D9E88, 50.0f + lbl_805D9E84, 120.0f);
        } else if (update_object_view_visibility(500.0f, 120.0f) != 0) {
            res = 1;
        } else {
            res = 0;
        }
        if (res != 0) {
            visible = 1;
            unk_3ac = 1;
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            cm = &fades[cam];
            cm->update();
            if (cm->updateFromCamera(&body_center.x) != 0) {
                cm->set_flags_and_apply_damage_color();
                if (defer_render() != 0) {
                    visible = 0;
                }
            }
            if (mode != 9) {
                Vec v = {5.0f, 1.0f, 5.0f};
                if (mode == 0) {
                    t = 10.0f / (unk_4b0 - 2.0f);
                    if (t < 1.0f && t > 0.0f) {
                        v.x = v.z = 5.0f * t;
                    }
                }
                draw_ground_shadow(&v, 1);
            }
            if (visible != 0) {
                update_secondary_light();
                TObjFish::set_global_param(texlist);
                push_matrix();
                lbl_805D510C = 0;
                TObjEneBm3FlyNest_attachment_point_ptr = &unk_3c8[0];
                post_translate_matrix(&position);
                ((s32 (*)(int, f32, f32, f32))translate_matrix)(0, 0.0f, unk_4b0, 0.0f);
                if (mode == 0) {
                    bm3_fly_nest_attachment_index = 0;
                    lbl_805D5114 = unk_3e0;
                    set_chunk_model_node_callback(TObjEneBm3FlyNest::handle_attachment_sample);
                } else {
                    set_chunk_model_node_callback(TObjEneBm3FlyNest::capture_attachment);
                }
                ((s32 (*)(int, int))rotate_matrix_y)(0, rotation_y);
                TObjEneDD::clear_global_flag_400();
                TObjPlayer::toggle_particle_effect();
                if (res == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                TParticleCtrl::end_effect_render();
                set_chunk_model_node_callback(NULL);
                pop_matrix();
            }
            update_primary_light();
            if (cm->updateFromCamera(&body_center.x) != 0) {
                cm->clear_flag_and_notify();
            }
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        }
    }
    VecCopy(&body_center, &unk_3c8[0]);
}

#pragma pool_data off
void TObjEneBm3FlyNest::render_with_state_debug() {
    u8 *self = (u8 *)this;
    f32 var_f31;
    Ent_800B23A0 *var_r30;
    if (((TObjEneDD *)self)->get_target_info() != 0) {
        switch (this->state) {
        default:
        case 2:
            debug_printf_at(pack_debug_text_position(0, 0), "STATE : NORMAL");
            break;
        case 9:
            debug_printf_at(pack_debug_text_position(0, 0), "STATE : DEAD");
            break;
        case 5:
            debug_printf_at(pack_debug_text_position(0, 0), "STATE : FALLEN");
            break;
        }
        debug_printf_at(pack_debug_text_position(0, 1), "START NUM : %2d", this->start_num);
        debug_printf_at(pack_debug_text_position(0, 2), "TOTAL NUM : %2d", this->total_num);
    }
    switch (this->state) {
    default:
    case 2:
        var_f31 = 0.0f;
        var_r30 = (*(Pair_800B23A0 * *)&this->motion_list)[*(s32 *)((s8 *)(*(u8 * *)&this->action_table) + 4)].e;
        break;
    case 9:
        var_r30 = (*(Pair_800B23A0 * *)&this->motion_list)[*(s32 *)((s8 *)(*(u8 * *)&this->action_table) + 0x74)].e;
        var_f31 = var_r30->count - 1;
        break;
    case 5:
        var_r30 = (*(Pair_800B23A0 * *)&this->motion_list)[*(s32 *)((s8 *)(*(u8 * *)&this->action_table) + 0x34)].e;
        var_f31 = var_r30->count - 1;
        break;
    }
    if (this->update_object_view_visibility(500.0f, 120.0f) != 0) {
        Vec v = {5.0f, 1.0f, 5.0f};
        ((TObjEneDD *)(self))->draw_ground_shadow(&v, 1);
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        ((void (*)(void *))post_translate_matrix)(self + 0x38);
        translate_matrix(0, 0.0f, -5.0f, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        set_motion_packed_rotation();
        draw_model_motion(this->model, var_r30, var_f31);
        clear_motion_packed_rotation();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    push_matrix();
    ((void (*)(void *))post_translate_matrix)(self + 0x38);
    rotate_matrix_y(0, this->rotation_y);
    translate_matrix(0, *(f32 *)((s8 *)self + 0x35C), *(f32 *)((s8 *)self + 0x360), *(f32 *)((s8 *)self + 0x364));
    draw_chunk_object((void *)debug_chunk_object);
    pop_matrix();
}
#pragma pool_data reset
