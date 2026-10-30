#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/TObjControl.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/NinjaUtil.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneNanoDrago.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/misc/TCameraCtrl.h"

#include "pso/misc/MaterialOpacityFade.h"

extern "C" s32 TObjPlayer__sub_800DC420(void *self, s32 i);
extern "C" f32 TObjPlayer__sub_800DC434(s32 arg0, s32 arg1);
extern "C" f32 lbl_805D525C;
extern "C" f32 lbl_805D5260;
extern "C" f32 lbl_805D5264;
extern "C" f32 lbl_805D5268;
extern "C" s32 lbl_805D526C;
extern "C" s32 lbl_805D5270;
extern "C" s32 push_matrix_from(void *);
extern "C" s32 pop_matrix(void);
extern "C" s32 scale_matrix(int, f32, f32, f32);
extern "C" s32 rotate_matrix_y(int, int);
extern "C" s32 translate_matrix(int, f32, f32, f32);
extern "C" Mtx34 identity_matrix;
extern "C" s32 registered_player_count;
extern "C" void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" s32 lbl_805D5870;
extern "C" f32 atan2_float(f32, f32);
extern "C" void vec3_add_to(void *, void *);
extern "C" s32 matrix_mult_vec(int, Vec *, void *);
extern "C" Vec lbl_8043C8E4;
extern "C" Vec find_open_direction_zero_vec;
extern "C" const f64 lbl_8043C900[];
extern "C" s16 get_entity_id(void *);
extern "C" s32 angle_difference_abs(s32, s32);
extern "C" void subtract_vector(void *, void *);

#include <stddef.h>
typedef char NanoGrow_scale[offsetof(TObjEneNanoDrago, scale.x) == 0x68 ? 1 : -1];
typedef char NanoGrow_target_scale[offsetof(TObjEneNanoDrago, scale.y) == 0x6c ? 1 : -1];
typedef char NanoGrow_m_2c0[offsetof(TObjEneNanoDrago, m_2c0) == 0x2c0 ? 1 : -1];
typedef char NanoGrow_m_2c8[offsetof(TObjEneNanoDrago, m_2c8) == 0x2c8 ? 1 : -1];
typedef char NanoGrow_m_2fc[offsetof(TObjEneNanoDrago, m_2fc) == 0x2fc ? 1 : -1];
typedef char NanoGrow_params[offsetof(TObjEneNanoDrago, movementParameters) == 0x350 ? 1 : -1];
typedef char NanoGrow_next_action[offsetof(TObjEneNanoDrago, next_action) == 0x374 ? 1 : -1];
typedef char NanoGrow_state[offsetof(TObjEneNanoDrago, state) == 0x37c ? 1 : -1];
typedef char NanoGrow_growth_count[offsetof(TObjEneNanoDrago, growth_count) == 0x38c ? 1 : -1];
typedef char NanoGrow_speed[offsetof(TObjEneNanoDrago, speed) == 0x3d8 ? 1 : -1];
typedef char NanoDrago_flags30_offset[offsetof(TObjEneNanoDrago, actorFlags) == 0x30 ? 1 : -1];
typedef char NanoDrago_pos_offset[offsetof(TObjEneNanoDrago, position) == 0x38 ? 1 : -1];
typedef char NanoDrago_angle_offset[offsetof(TObjEneNanoDrago, rotation_y) == 0x60 ? 1 : -1];
typedef char NanoDrago_fb8_offset[offsetof(TObjEneNanoDrago, requested_action) == 0xb8 ? 1 : -1];
typedef char NanoDrago_home_offset[offsetof(TObjEneNanoDrago, m_29c) == 0x29c ? 1 : -1];
typedef char NanoDrago_target_offset[offsetof(TObjEneNanoDrago, target) == 0x2a8 ? 1 : -1];
typedef char NanoDrago_hpmax_offset[offsetof(TObjEneNanoDrago, hpmax) == 0x2b8 ? 1 : -1];
typedef char NanoDrago_hp_offset[offsetof(TObjEneNanoDrago, hp) == 0x32c ? 1 : -1];
typedef char NanoDrago_params_offset[offsetof(TObjEneNanoDrago, movementParameters) == 0x350 ? 1 : -1];
typedef char NanoDrago_state_offset[offsetof(TObjEneNanoDrago, state) == 0x37c ? 1 : -1];
typedef char NanoDrago_flags388_offset[offsetof(TObjEneNanoDrago, m_388) == 0x388 ? 1 : -1];
typedef char NanoDrago_accum_offset[offsetof(TObjEneNanoDrago, circlingAngle) == 0x3d0 ? 1 : -1];
typedef char NanoDrago_t_offset[offsetof(TObjEneNanoDrago, wanderDistance) == 0x3d4 ? 1 : -1];
typedef char NanoDrago_speed_offset[offsetof(TObjEneNanoDrago, speed) == 0x3d8 ? 1 : -1];
typedef char NanoDrago_toggle_offset[offsetof(TObjEneNanoDrago, alternateBeam) == 0x3e0 ? 1 : -1];

extern "C" u16 find_nearest_visible_player(void *, s32, f32);
extern "C" s32 apply_actor_gravity(void *, int, f32);
extern "C" f32 atan2_float(f32 y, f32 x);
extern "C" s32 check_enemy_body_collisions(void *);
extern "C" s32 play_sound_effect(int, void *, int, int);
extern "C" void rotate_vector_by_matrix(int, void *, void *);

extern "C" u32 get_player_by_client_id(s32);
extern "C" s32 play_area_sound_effect__12TBoss3VoloptFv(void *, s32);

void move_with_wall_slide(u8 *arg0);

struct BeamRotation { s32 x, y, z; };

extern "C" void *spawn_directional_particle(void *pos, void *dir, s32 id);
extern "C" void TObjPlayer__sub_800DCD04(void *, void *, int, void *, s32, int);
extern "C" void *find_entity_by_id(u16 id);
extern "C" u32 __nw__7TObjectFUl(u32);
extern "C" void enemy_turn_toward_dest(void *, s32);
extern "C" f32 sin_table_lookup(s32);
extern "C" f32 cos_table_lookup(s32);
extern "C" s32 enemy_turn_half_toward_dest(void *);
extern "C" void *spawn_particle_effect(void *pos, s32 id);
extern "C" s32 construct_beam_effect__10TObjPlayerFPvPvPviPv(u32, void *, void *, u8, void *);
extern "C" s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
extern "C" s32 check_path_obstructed(void *, Vec *);
extern "C" void calc_velocity_toward_destination(void *, Vec, Vec, f32);
extern "C" s32 TObjPlayer__sub_800DC478(u8 *arg0, s32 arg1, f32 farg0);
extern "C" void project_actor_to_ground(void *, void *, s32);
extern "C" void TObjPlayer__sub_800D92BC(s32 point, s32 delay);
extern "C" s32 refresh_lobby_state__10TObjPlayerFv();

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline f32 max_float(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}

inline f32 xz_length_squared(Vec *v) { return v->x * v->x + v->z * v->z; }

#pragma pop

#include "pso/misc/TLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3VoloptMonitor.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" s32 is_split_screen();
extern "C" s32 restore_scene_lighting();
extern "C" s32 select_actor_lighting(void *);
extern "C" s32 push_matrix();
extern "C" s32 pop_matrix();
extern "C" s32 draw_chunk_object(int);
extern "C" s32 saved_model_render_flags;
extern "C" s32 model_render_flags;
struct NanoDragoAnimationBinding {
    BmlMotionEntry *motions;
    u32 unknown04;
    u32 unknown08;
    u32 unknown0C;
};

extern "C" void obj_setFlags30(void *, u32);
extern "C" s32 dispatch_shared_handler_a__6TLobbyFl(int);
extern "C" s32 register_object__6TLobbyFl(int);
extern "C" s32 dispatch_shared_handler_b__6TLobbyFl(int);
extern "C" s32 register_boss__6TLobbyFl(int);
extern "C" void TLobby__sub_8001FE7C(void*, int);
extern "C" u8 * load_resource_from_descriptor(void *, s32, s32 *, s32, s32, s32);
extern "C" s32 find_active_entity_by_id(int);

extern "C" void TObjPlayer__sub_800DC444(void);

int initialize_enemy_photon_effect(void *p);

extern "C" s32 free_collision_body_parts(void *);
extern "C" void init_collision_body_parts(void *, void *, s32);
extern "C" s32 submit_cursor_candidate(void *, int);
extern "C" s32 minimap_render_dot(void *, int, int, int);

extern "C" NanoDragoAnimationBinding nano_drago_anim_binding;
extern "C" const char *nano_drago_name;
extern "C" s32 lbl_805D5248;
extern "C" s32 lbl_805D524C;
extern "C" s32 lbl_805D5250;
extern "C" s32 lbl_805D5254;
extern "C" BmlResource *nano_drago_entry_params_resource;
extern "C" void *tl_04;

extern "C" u8 lbl_8043C760[];

extern "C" u8 lbl_8043C774[];

extern "C" u8 lbl_8043C78C[];

extern "C" u8 lbl_8043C7A8[];

extern "C" u8 lbl_8043C7C4[];

extern "C" u8 lbl_8043C7E0[];

extern "C" u8 lbl_8043C7FC[];

extern "C" u8 lbl_8043C814[];

extern "C" u8 lbl_8043C82C[];

extern "C" u8 lbl_8043C844[];

extern "C" u8 lbl_8043C860[];

extern "C" u8 lbl_8043C878[];

extern "C" u8 lbl_8043C890[];

extern "C" u8 lbl_8043C8A8[];

extern "C" const char *bm_ene_nanodrago_model_names[2];
extern "C" const char *bm_ene_nanodrago_motion_names[13];
__declspec(section ".data") const char *bm_ene_nanodrago_model_names[2] = {
    (const char *)lbl_8043C760, NULL,
};
const char *bm_ene_nanodrago_motion_names[13] = {
    (const char *)lbl_8043C774, (const char *)lbl_8043C78C, (const char *)lbl_8043C7A8, (const char *)lbl_8043C7C4,
    (const char *)lbl_8043C7E0, (const char *)lbl_8043C7FC, (const char *)lbl_8043C814, (const char *)lbl_8043C82C,
    (const char *)lbl_8043C844, (const char *)lbl_8043C860, (const char *)lbl_8043C878, (const char *)lbl_8043C890,
    NULL,
};
BmlResourceDescriptor bm_ene_nanodrago_resource_descriptor = {
    (const char *)lbl_8043C8A8, bm_ene_nanodrago_model_names, bm_ene_nanodrago_motion_names, 1, 12
};
TObjMotionAction nanodrago_action_table[12] = {
    {2, 0, 10, 0.8f, 0},
    {1, 1, 11, 0.8f, 1},
    {2, 0, 0, 0.7f, 4},
    {2, 0, 2, 0.8f, 8},
    {3, 4, 3, 0.5f, 0x10},
    {2, 0, 6, 0.8f, 1},
    {2, 7, 9, 0.9f, 1},
    {1, 7, 5, 1.4f, 1},
    {2, 0, 7, 1.4f, 1},
    {2, 7, 8, 0.7f, 4},
    {2, 7, 1, 0.8f, 8},
    {3, 11, 4, 0.5f, 0x10},
};
NanoDragoMovementParams nano_drago_movement = {
    150.0f, 0.46296296f, 0x300, {0x1E0000, 0, 1, 0}
};
CollisionBody nano_drago_bodies[2] = {
    {{0.0f, 15.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8001, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 15.0f, 0.0f}, 12.0f, 0.0f, 0, 0xA000002, {0.0f, 0.0f, 0.0f}, 0.0f},
};

// Deferred code generation emits these methods in address order.
void TObjEneNanoDrago::vfunc_61() {  }
void TObjEneNanoDrago::vfunc_59() {  }
void TObjEneNanoDrago::vfunc_60() {  }
void TObjEneNanoDrago::vfunc_58() {  }
TObjEneNanoDrago::TObjEneNanoDrago(TObject *parent, void *setData) : TObjEnemyCustom(parent) {
    u8 *arg2 = (u8 *)setData;
    s32 i;
    m_name = nano_drago_name;
    apply_set_data(arg2);
    VecCopy((Vec *)(&m_290), (const Vec *)(VecCopy((Vec *)(&m_29c), (const Vec *)(&position))));
    motion_list = nano_drago_entry_params_resource->motions;
    variant = 0;
    add_flags_2e4(2);
    state36C = *(s16 *)((s8 *)arg2 + 0x3E);
    load_entry_params_nanodrago(variant);
    action_table = nanodrago_action_table;
    set_field_d8((s32)(action_table));
    init_collision_body_parts(this, nano_drago_bodies, 2);
    bodies[1].flags &= ~1;
    movementParameters = &nano_drago_movement;
    bind_enemy_combat_stats((u8 *)lbl_805D5248, (u8 *)lbl_805D524C, (u8 *)lbl_805D5250);
    update_attack_parameters();
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    initialize_enemy_photon_effect(this);
    growth_count = 0;
    scale.x = 0.6f;
    speed = ((NanoDragoMovementParams *)movementParameters)->baseSpeed * scale.x;
    VecCopy((Vec *)(&home_position), (const Vec *)(&position));
    VecCopy((Vec *)(&moveDestination), (const Vec *)(&position));
    if ((s32)parameters[0] == 1) {
        m_388 |= 0x40000;
        if (parameters[1] < 1.0f) {
            parameters[1] = 50.0f;
        }
        set_flags_30();
    }
    cameraShakeCooldown = 0;
    alternateBeam = 0;
    set_param(0xF);
    sinkingOffset = 0.0f;
    if (*(s16 *)((s8 *)arg2 + 0xA) != 0 && !(m_388 & 0x40000)) {
        sub_800C7860();
    }
    flightHeight = 0.0f;
    for (i = 0; i < 4; i++) {
        cameraFades[i].activate_and_dispatch();
    }
    obj_setFlags30(this, 0x1000000);
    VecCopy((Vec *)(&prev_position), (const Vec *)(&position));
    clear_lobby_object_state();
}
TObjEneNanoDrago::~TObjEneNanoDrago() {
    free_collision_body_parts(this);
}
void TObjEneNanoDrago::load_resources() {
    NanoDragoAnimationBinding binding;

    u8 *storage;
    BmlModelEntry *modelEntries;
    u8 *resource;

    storage = (u8 *)((int)::operator new(0x440));
    resource = storage;
    if (resource != NULL) {
        resource = (u8 *)(load_resource_from_descriptor(storage, 1, (s32 *)&bm_ene_nanodrago_resource_descriptor, 0, 0, 0));
    }
    nano_drago_entry_params_resource = (BmlResource *)resource;
    lbl_805D5248 = register_boss__6TLobbyFl(0x1A);
    lbl_805D524C = dispatch_shared_handler_b__6TLobbyFl(0x1A);
    lbl_805D5250 = register_object__6TLobbyFl(0x1A);
    lbl_805D5254 = dispatch_shared_handler_a__6TLobbyFl(0x1A);
    binding = nano_drago_anim_binding;
    binding.motions = nano_drago_entry_params_resource->motions;
    modelEntries = nano_drago_entry_params_resource->models;
    TLobby::spawn_npc_enemy((s16)(0x22), modelEntries[0].model, modelEntries[0].m_c, (s32)&binding, (f32)((f32) (15.0f)), (f32)((f32) (0.0f)));
}
void TObjEneNanoDrago::free_resources() {
    if ((u32) nano_drago_entry_params_resource != 0U) {
        TLobby__sub_8001FE7C((void*)nano_drago_entry_params_resource, 1);
        nano_drago_entry_params_resource = NULL;
    }
}
void *TObjEneNanoDrago::create(void *arg0) {
    void *o;
    void *o2;
    o = new TObjControl((TObject *)tl_04);
    o2 = new TObjEneNanoDrago((TObject *)o, arg0);
    return o2;
}
void TObjEneNanoDrago::run_task() {
    s32 cooldown;

    if (TObjPlayer::check_demo_mode() == 1) {
        update_attack_parameters();
        run_demo_task();
        return;
    }
    target = (u8 *)find_active_entity_by_id((int) (targetId));
    release_destroyed_target();
    update_proximity_state();
    if ((s16) mode != (s32) next_action) {
        if ((s32) state != -1) {
            state = -1;
            dispatch_action_state();
        }
        mode = (s16) next_action;
        state = 0;
    }
    dispatch_action_state();
    if ((s32) state == -1) {
        state = -1;
        dispatch_action_state();
        mode = (s16) next_action;
        state = 0;
    }
    VecCopy((Vec *)(&m_2fc), (const Vec *)(&position));
    m_300 = (f32) (m_300 + (15.0f + flightHeight));
    bodies[0].offset.y = (f32) (15.0f + flightHeight);
    if (!(m_388 & 0x40000)) {
        submit_cursor_candidate(((u8 *)this), -1);
        minimap_render_dot((u8 *)&position, -0x5DB4, 1, 0);
    }
    cooldown = cameraShakeCooldown;
    if (cooldown > 0) {
        cameraShakeCooldown = (cooldown - 1);
    }
    bodies[0].flags &= ~6;
    if (flightHeight > 5.0f) {
        bodies[0].flags |= 4;
    } else {
        bodies[0].flags |= 2;
    }
    if (xz_distance_squared(&position, &prev_position) > 2500.0f) {
        VecCopy((Vec *)(&position), (const Vec *)(&prev_position));
    }
    VecCopy((Vec *)(&prev_position), (const Vec *)(&position));
}
void TObjEneNanoDrago::dispatch_action_state() {
  s16 action;
  action = mode;
  {
    switch (action)
    {
      case 0:
        update_idle_state();
        return;
      case 1:
        update_circling_state();
        return;
      case 2:
        TObjPlayer__sub_800DC444();
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
      case 9:
        update_multi_beam_state();
        return;
      case 10:
        update_single_beam_state();
        return;
      case 11:
        update_flight_state();
        return;
      case 12:
        update_growth_state();
        return;
      case 7:
        update_fade_in_state();
        break;
    }
  }
}

#pragma push
#pragma fp_contract on
void TObjEneNanoDrago::render() {
    Vec shadowScale;
    f32 shadowRadius;
    f32 modelScale;
    s32 cameraIndex;
    RenderFadeState *fade;
    s32 viewDetail;
    s32 rendered;
    cameraIndex = 0;
    if (is_split_screen() != 0) {
        cameraIndex = TCameraCtrl::get_camera_mode();
    }
    if (!(actorFlags & 0x02000000) && (viewDetail = classify_actor_view_detail(150.0f, 400.0f, 20.0f), viewDetail != 0) && ((TObjPlayer::check_demo_mode() == 1) || !(m_388 & 0x40000))) {
        saved_model_render_flags = model_render_flags;
        fade = &cameraFades[cameraIndex];
        fade->update();
        if (fade->updateFromCamera((const f32*)(&m_2fc)) != 0) {
            fade->set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                model_render_flags = saved_model_render_flags;
                return;
            }
        }
        TObjFish::set_global_param((int) (texlist));
        select_actor_lighting(this);
        TObjPlayer::toggle_particle_effect();
        rendered = 1;
        push_matrix();
        translate_matrix(0, (f32) (position.x), (f32) (flightHeight + (position.y + sinkingOffset)), (f32) (position.z));
        rotate_matrix_y(0, (int) (rotation_y));
        modelScale = scale.x;
        scale_matrix(0, modelScale, modelScale, modelScale);
        model_render_flags &= 0xFFFFFBFF;
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object((int) (model));
        } else if (m_388 & 4) {
            if (appearFade.has_visible_opacity() != 0) {
                appearFade.set_flags_and_apply_damage_color();
                if (viewDetail == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                appearFade.clear_flag_and_notify();
            } else {
                rendered = 0;
            }
        } else if (viewDetail == 1) {
            draw();
        } else {
            draw_motion_model();
        }
        pop_matrix();
        restore_scene_lighting();
        TParticleCtrl::end_effect_render();
        if (!(actorFlags & 0x800) && (rendered != 0)) {
            shadowRadius = -(0.01f * flightHeight - 1.0f) * (5.0f * scale.x);
            shadowScale.z = shadowRadius;
            shadowScale.y = shadowRadius;
            shadowScale.x = shadowRadius;
            render_with_position_override((u8 *)&shadowScale, 0);
        }
        fade->clear_flag_and_notify();
        model_render_flags = saved_model_render_flags;
    }
}
#pragma pop
void TObjEneNanoDrago::run_demo_task() {
  }
void TObjEneNanoDrago::update_idle_state() {
    if ((m_388) & 0x40000) {
        return;
    }
    switch ((state)) {
    case -1:
        break;
    case 0:
        requested_action = 1;
        (state) = 1;
        m_384 = 0x96;
        sub_8004292C();
    case 1:
        advance_animation();
        wander_around(&home_position, parameters[1]);
        if (is_passing_frame((f32)(4.0f)) != 0 || is_passing_frame((f32)(20.0f)) != 0) {
            play_sound_effect(0x4003AD23, (u8 *)(&position), 0, 0);
        }
        m_384 = m_384 - 1;
        if (m_384 <= 0) {
            requested_action = 0;
            (state) = 2;
            m_384 = 0x5A;
        }
        check_object_collisions();
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case 2:
        advance_animation();
        check_object_collisions();
        m_384 = m_384 - 1;
        if (m_384 <= 0) {
            (state) = 0;
        }
        break;
    }
}
void TObjEneNanoDrago::vfunc_62() {
    ((TObjEneMe1GiGue *)this)->set_state(4);
    m_380 = (s32) m_378;
    m_378 = 4;
    m_388 = (s32) (m_388 | 0x10000 | 1);
}
void TObjEneNanoDrago::vfunc_63() {
    ((TObjEneMe1GiGue *)((u8 *)this))->set_state(5);
    m_380 = (s32) m_378;
    m_378 = 5;
    m_388 = (s32) (m_388 | 1);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TObjEneNanoDrago::update_circling_state() {
    (actorFlags) &= ~0x01000000;
    switch (state) {
    case -1:
        break;
    case 0:
        (m_388) &= ~0x00040000;
        sub_8004292C();
        requested_action = 1;
        circlingAngle = 0;
        if (target != NULL) {
            VecCopy((Vec *)((Vec *)&m_29c), (const Vec *)(target + 0x2FC));
        }
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(((u8 *)this), 0, 0.0f);
        if (is_passing_frame((f32)(4.0f)) != 0 || is_passing_frame((f32)(20.0f)) != 0) {
            play_sound_effect(0x4003AD23, (Vec *)&position, 0, 0);
        }
        if (target != NULL) {
            Vec d = *(Vec *)(target + 0x38);
            subtract_vector(&d, (Vec *)&position);
            if (xz_length_squared(&d) <= 160000.0f &&
                angle_difference_abs(-(s32)(lbl_8043C900[0] * atan2_float(d.z, d.x)) + 0x4000, rotation_y) < 0xAAA) {
                s32 next;
                if (hp <= hpmax / 4) {
                    next = 10;
                } else {
                    s32 n = 9;
                    if (alternateBeam != 0) {
                        n = 10;
                    }
                    next = n;
                    alternateBeam ^= 1;
                }
                ((TObjEneMe1GiGue *)this)->update_if_active(next);
                break;
            }
        }
        rotation_y += ((NanoDragoMovementParams *)movementParameters)->turnSpeed / 2;
        enemy_set_heading_velocity(speed, this, rotation_y);
        move_with_wall_slide(((u8 *)this));
        circlingAngle += ((NanoDragoMovementParams *)movementParameters)->turnSpeed / 2;
        if (circlingAngle > 0x10000) {
            wanderDistance = 0.0f;
            state = 2;
        }
        check_object_collisions();
        check_enemy_body_collisions(((u8 *)this));
        break;
    case 2:
        enemy_wander_home(speed, 100.0f, 50.0f, ((NanoDragoMovementParams *)movementParameters)->turnSpeed);
        advance_animation();
        apply_actor_gravity(((u8 *)this), 0, 0.0f);
        if (is_passing_frame((f32)(4.0f)) != 0 || is_passing_frame((f32)(20.0f)) != 0) {
            play_sound_effect(0x4003AD23, (Vec *)&position, 0, 0);
        }
        wanderDistance += speed;
        if (wanderDistance > 100.0f) {
            if (select_nearest_target(((NanoDragoMovementParams *)movementParameters)->detectionRadius) != 0) {
                circlingAngle = 0;
                state = 1;
            } else {
                ((TObjEneMe1GiGue *)this)->update_if_active(0);
            }
        }
        check_object_collisions();
        check_enemy_body_collisions(((u8 *)this));
        break;
    }
}
#pragma pop
void TObjEneNanoDrago::update_single_beam_state() {
    s32 remainingFrames;
    s32 phase;
    phase = state;
    switch (phase) {
    case -1:
        break;
    case 0:
        sub_8004292C();
        m_384 = 0x5A;
        if (!(actorFlags & 0x01000000)) {
            requested_action = 2;
        } else {
            requested_action = 9;
        }
        state = 1;
        advance_animation();
        m_388 = (s32) (m_388 & 0xFFFBFFFF);
        break;
    case 3:
    case 2:
    case 1:
        if ((u32) target == 0U) {
            state = 4;
            return;
        }
        switch (phase) {
        case 1:
            if (frame >= 5.0f) {
                capture_beam_origins();
                spawn_particle_effect((&beamOrigins[0]), 0xF7);
                state = 2;
            }
            break;
        case 2:
            play_persistent_sound(0x4003AD1E, (s32)((u8 *)this), (u32)(&position), 0, 0);
            if (frame >= 20.0f) {
                capture_beam_origins();
                u32 obj = __nw__7TObjectFUl(0x100);
                if (obj != 0U) {
                    construct_beam_effect__10TObjPlayerFPvPvPviPv(obj, &beamOrigins[0], (void *) (target + 0x2FC), (u8) !(actorFlags & 0x01000000), ((u8 *)this));
                }
                spawn_beam_particle(0);
                play_sound_effect(0x4003A527, &position, 0, 0);
                state = 3;
            }
            break;
        }
        VecCopy((Vec *)(&m_29c), (const Vec *)(target + 0x2FC));
        enemy_turn_half_toward_dest(((u8 *)this));
        advance_animation();
        if (!(actorFlags & 0x01000000)) {
            apply_actor_gravity(((u8 *)this), 0, (f32) (0.0f));
        }
        ((TObjPlayer *)((u8 *)this))->update_collisions();
        remainingFrames = m_384 - 1;
        m_384 = remainingFrames;
        if (remainingFrames <= 0) {
            state = 4;
        }
        break;
    case 4:
        if (actorFlags & 0x01000000) {
            m_378 = 0;
            ((TObjEneMe1GiGue *)this)->update_if_active(0xB);
            return;
        }
        ((TObjEneMe1GiGue *)this)->update_if_active(0);
        break;
    }
}
void TObjEneNanoDrago::update_multi_beam_state() {
    s32 r;
    s32 i;
    switch (state) {
    case 0:
        sub_8004292C();
        r = 0;
        if (!(actorFlags & 0x01000000)) {
            r = collect_beam_targets();
        }
        if (r > 0) {
            requested_action = 2;
            m_384 = 0x5A;
            state = 1;
        } else if (actorFlags & 0x01000000) {
            ((TObjEneMe1GiGue *)this)->update_if_active(0xB);
        } else {
            ((TObjEneMe1GiGue *)this)->update_if_active(0);
        }
        m_388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (state) {
        case 1:
            if (frame >= 5.0f) {
                capture_beam_origins();
                spawn_particle_effect(&beamOrigins[0], 0xF7);
                spawn_particle_effect(&beamOrigins[1], 0xF7);
                state = 2;
            }
            break;
        case 2:
            play_persistent_sound(0x4003AD1E, (s32)((u8 *)this), (u32)&position, 0, 0);
            if (frame >= 20.0f) {
                capture_beam_origins();
                for (i = 0; i < beamTargetCount; i++) {
                    spawn_targeted_beam(i);
                }
                state = 3;
            }
            break;
        }
        advance_animation();
        apply_actor_gravity(((u8 *)this), 0, 0.0f);
        ((TObjPlayer *)((u8 *)this))->update_collisions();
        m_384--;
        if (m_384 <= 0) {
            m_384 = 0x2D;
            requested_action = 1;
            state = 4;
        }
        break;
    case 4:
        enemy_wander_home(speed, 100.0f, 100.0f, ((NanoDragoMovementParams *)movementParameters)->turnSpeed);
        advance_animation();
        apply_actor_gravity(((u8 *)this), 0, 0.0f);
        ((TObjPlayer *)((u8 *)this))->update_collisions();
        if (is_passing_frame((f32)(4.0f)) != 0 || is_passing_frame((f32)(20.0f)) != 0) {
            play_sound_effect(0x4003AD23, &position, 0, 0);
        }
        if (find_nearest_visible_player(this, 0, 50.0f) != 0xFFFF) {
            ((TObjEneMe1GiGue *)this)->update_if_active(0xB);
        } else {
            m_384--;
            if (m_384 <= 0) {
                ((TObjEneMe1GiGue *)this)->update_if_active(0);
            }
        }
        break;
    case -1:
        break;
    }
}
void TObjEneNanoDrago::update_flight_state() {
    Vec v;
    actorFlags &= ~0x800000;
    switch (state) {
    case 0:
        state = 1;
        if (actorFlags & 0x01000000) {
            if (m_388 & 0x40000) {
                VecCopy((Vec *)(&moveDestination), (const Vec *)(&home_position));
                calc_velocity_toward_destination(((u8 *)this), position, moveDestination, speed);
                m_388 &= ~0x40000;
                sub_8004292C();
                flightHeight = 50.0f;
            } else {
                find_target_in_range(((NanoDragoMovementParams *)movementParameters)->detectionRadius);
                calc_velocity_toward_destination(((u8 *)this), position, moveDestination, speed);
            }
            requested_action = 7;
        } else {
            actorFlags |= 0x01000000;
            requested_action = 6;
            flightHeight = 0.0f;
            find_target_in_range(((NanoDragoMovementParams *)movementParameters)->detectionRadius);
            if (target != 0) {
                VecCopy((Vec *)&v, (const Vec *)(&position));
                subtract_vector(&v, target + 0x38);
                find_open_direction(&v);
                calc_velocity_toward_destination(((u8 *)this), position, moveDestination, speed);
            } else {
                VecCopy((Vec *)(&moveDestination), (const Vec *)(&home_position));
                calc_velocity_toward_destination(((u8 *)this), position, moveDestination, speed);
            }
        }
        break;
    case 1:
        advance_animation();
        calc_velocity_toward_destination(((u8 *)this), position, moveDestination, TObjPlayer__sub_800DC434((s32)((u8 *)this), 0));
        if (flightHeight < 50.0f) {
            s32 ok = 1;
            if (requested_action == 6 && frame < 22.0f) {
                ok = 0;
            }
            if (ok != 0) {
                flightHeight += 2.2f;
            }
            ((TObjPlayer *)((u8 *)this))->update_collisions();
            if (TObjPlayer__sub_800DC478(((u8 *)this), 6, 22.0f) != 0) {
                spawn_particle_effect(&position, 0xF0);
                play_sound_effect(0x4003AD20, &position, 0, 0);
            }
        } else {
            y_speed = 0.0f;
            VecCopy((Vec *)(&prev_position), (const Vec *)(&position));
            vec3_add_to(&position, &x_speed);
            if (xz_distance_squared((Vec *)(&position), (Vec *)(&moveDestination)) <= (10.0f + speed) * (10.0f + speed)) {
                state = 2;
                m_310 = 0.0f;
                x_speed = 0.0f;
            }
            if (is_passing_frame((f32)(10.0f)) != 0) {
                spawn_particle_effect(&position, 0xF0);
                play_sound_effect(0x4003AD20, &position, 0, 0);
            }
            refresh_collision_body_centers();
        }
        if (flightHeight > 15.0f) {
            turn_toward_direction(((NanoDragoMovementParams *)movementParameters)->turnSpeed * 2, (Vec *)((u8 *)&x_speed));
        }
        project_actor_to_ground(((u8 *)this), &position, 0);
        break;
    case 2:
        bodies[1].flags |= 1;
        advance_animation();
        flightHeight += -2.3f;
        if (flightHeight <= 0.0f) {
            flightHeight = 0.0f;
            actorFlags |= 0x800000;
            actorFlags &= ~0x01000000;
            y_speed = 0.0f;
            if (requested_action != 8) {
                ((TObjEneMe1GiGue *)this)->update_if_active(0);
            }
        } else if (requested_action == 7) {
            if (flightHeight <= 2.3f * (40.0f + 1.0f / blend_speed)) {
                requested_action = 8;
            }
        } else {
            s32 t = (s32)frame;
            if (t == 20 || t == 40) {
                spawn_particle_effect(&position, 0xF0);
            }
        }
        if (TObjPlayer__sub_800DC478(((u8 *)this), 8, 42.0f) != 0) {
            play_sound_effect(0x4003AD23, &position, 0, 0);
        }
        check_object_collisions();
        apply_actor_gravity(((u8 *)this), 0, 0.0f);
        break;
    case -1:
        if ((s32)next_action != 4 && (s32)next_action != 5) {
            flightHeight = 0.0f;
        }
        bodies[1].flags &= ~1;
        m_388 &= ~0x40000;
        break;
    }
}
void TObjEneNanoDrago::update_growth_state() {
    f32 t;
    f32 v;

    switch (state) {
    case 0:
        if (!((actorFlags) & 0x01000000) && growth_count < 4) {
            growth_count++;
            requested_action = 5;
            state = 1;
            scale.y = 0.1f + scale.x;
            spawn_particle_effect(&m_2fc, 0xFA);
            speed = ((NanoDragoMovementParams *)movementParameters)->baseSpeed * scale.x;
            play_sound_effect(0x4003A824, (Vec *)&position, 0, 0);
            m_2c8 += 8;
            m_2c0 += 8;
        } else {
            scale.y = scale.x;
            state = -1;
        }
    case 1:
        advance_animation();
        apply_actor_gravity(((u8 *)this), 0, 0.0f);
        ((TObjPlayer *)((u8 *)this))->update_collisions();
        t = scale.y;
        v = 0.0016000001f + scale.x;
        scale.x = (v < t) ? v : t;
        if (requested_action != 5) {
            (state) = -1;
        }
        break;
    case -1:
        scale.x = scale.y;
        (m_388) &= 0xFFFDFFFE;
        (next_action) = 1;
        break;
    }
}
void TObjEneNanoDrago::update_knockback_state() {
    s16 previousHp;
    s16 animation;
    u32 entity;
    s32 retaliate;
    switch (state) {
    case 0:
        animation = 3;
        actorFlags = (s32) (actorFlags & 0xFFDFFFFF);
        if (actorFlags & 0x01000000) {
            animation = 0xA;
        }
        requested_action = animation;
        spawn_particle_effect((&m_2fc), 0xF2);
        play_sound_effect(0x40039E22, &position, 0, 0);
        state = 1;
    case 1:
        advance_animation();
        if (!(actorFlags & 0x01000000)) {
            Vec v = *(Vec *)((s8 *)&m_2fc);
            v.x += x_speed;
            v.z += m_310;
            if (check_path_obstructed(((u8 *)this), &v) == 0) {
                move_with_wall_slide(((u8 *)this));
            } else {
                x_speed = m_310 = 0.0f;
            }
            x_speed *= 0.5f;
            m_310 *= 0.5f;
        }
        apply_actor_gravity(((u8 *)this), 0, 0.0f);
        ((TObjPlayer *)((u8 *)this))->update_collisions();
        if ((u32) action_flags != 8U) {
            state = -1;
        }
        break;
    case -1:
        retaliate = 0;
        actorFlags = (s32) (actorFlags & 0xFFFFFDFF);
        m_388 = (s32) (m_388 & 0xFFFFFFFE);
        m_378 = 1;
        previousHp = referenceHp;
        if (((s32) (previousHp - hp) > (s32) (previousHp / 4)) && !(actorFlags & 2)) {
            entity = (u32)find_entity_by_id(m_2d4);
            if (entity != 0) {
                retaliate = 1;
                if ((actorFlags & 0x01000000) && (xz_distance_squared((Vec *)(&position), (Vec *)((u8 *)entity + 0x38)) > 400.0f)) {
                    retaliate = 0;
                }
            }
        }
        if (retaliate == 1) {
            targetId = (u16) m_2d4;
            next_action = 0xA;
        } else if (actorFlags & 0x01000000) {
            ((TObjEneMe1GiGue *)this)->update_if_active(0xB);
            m_378 = (s32) m_380;
        } else {
            ((TObjEneMe1GiGue *)this)->update_if_active(0);
        }
        referenceHp = (s16) hp;
        break;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TObjEneNanoDrago::update_dying_state() {
    switch (state) {
    case 0:
        refresh_lobby_state__10TObjPlayerFv();
        send_entity_set_flags();
        timer = 0x1E;
        play_sound_effect(0x4003A825, &position, 0, 0);
        if (actorFlags & 0x01000000) {
            descentSpeed = (f32) (0.015384615f * -flightHeight);
            requested_action = 0xB;
            state = 2;
            return;
        }
        requested_action = 4;
        state = 1;
        return;
    case 1:
        advance_animation();
        apply_actor_gravity(((u8 *)this), 0, (f32) (0.0f));
        if (frame >= 30.0f) {
            spawn_particle_effect((&position), 0xF0);
            state = 3;
            return;
        }
        break;
    case 2:
        advance_animation();
        apply_actor_gravity(((u8 *)this), 0, (f32) (0.0f));
        {
        f32 lim = 0.0f;
        flightHeight = max_float(flightHeight + descentSpeed, lim);
        }
        if (frame >= 30.0f) {
            spawn_particle_effect((&position), 0xF0);
            play_sound_effect(0x40039E22, &position, 0, 0);
            state = 3;
            return;
        }
        break;
    case 3:
        timer = (s16) (timer - 1);
        if (timer <= 0) {
            ((TObjPlayer *)(&position))->spawn_ground_effect(0x1E);
            TObjPlayer__sub_800D92BC((s32)(&position), 0xF);
            state = 4;
            return;
        }
        break;
    case 4:
        sinkingOffset = (f32) (sinkingOffset - 0.3f);
        if (sinkingOffset < (-15.0f)) {
            queue_destruction();
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneNanoDrago::wander_around(Vec *center, f32 radius) {
    TObjEneNanoDrago *actor = this;
    s32 ang;
    f32 r;
    if (xz_distance_squared((Vec *)&actor->position, (Vec *)&actor->moveDestination) < 400.0f) {
        ang = (s32)(182.04445f * (360.0f * random_ratio()));
        r = 0.4f * (radius * (1.0f + random_ratio()));
        actor->moveDestination.x = r * cos_table_lookup(ang) + center->x;
        actor->moveDestination.z = r * sin_table_lookup(ang) + center->z;
    }
    VecCopy((Vec *)&actor->m_29c, (const Vec *)&actor->moveDestination);
    enemy_turn_toward_dest(actor, ((NanoDragoMovementParams *)actor->movementParameters)->turnSpeed);
    enemy_set_heading_velocity(actor->speed, actor, actor->rotation_y);
    move_with_wall_slide((u8 *)actor);
}
#pragma pop
void TObjEneNanoDrago::spawn_beam_particle(s32 i) {
    BeamRotation v;
    v.x = rotation_y + 0x4000;
    v.y = 0;
    v.z = 0x4000;
    spawn_directional_particle(&beamOrigins[i], &v, 0xfd);
}
void TObjEneNanoDrago::spawn_targeted_beam(s32 targetIndex) {
    BeamRotation rotation;
    s32 originIndex;
    s32 spreadAngle;
    void *beam;
    if (find_entity_by_id(beamTargetIds[targetIndex]) != 0) {
        originIndex = targetIndex & 1;
        rotation.x = 0;
        spreadAngle = 0x2000;
        if (originIndex != 0) {
            spreadAngle = -0x2000;
        }
        rotation.y = rotation_y + spreadAngle;
        rotation.z = 0;
        beam = (void *)__nw__7TObjectFUl(0x104);
        if (beam != 0) {
            TObjPlayer__sub_800DCD04(beam, &beamOrigins[originIndex], beamTargetIds[targetIndex], &rotation, targetIndex * 3, entity_id);
        }
    }
}
void TObjEneNanoDrago::request_growth() {
    if (!(m_388 & 0x20000)) {
        ((TObjEneMe1GiGue *)this)->update_if_active(0xC);
        m_388 = (s32) (m_388 | 0x20000 | 1);
    }
}
void TObjEneNanoDrago::update_proximity_state() {
    switch (mode) {
    case 0:
        if (is_actor_cadence_frame(0x1E) != 0) {
            if (find_nearest_visible_player(((TObjEneNanoDrago *)this), 0, ((NanoDragoMovementParams *)movementParameters)->detectionRadius) != 0xFFFF) {
                select_nearest_target(((NanoDragoMovementParams *)movementParameters)->detectionRadius);
                if (m_388 & 0x40000) {
                    begin_hidden_flight();
                } else {
                    ((TObjEneMe1GiGue *)this)->update_if_active(1);
                }
            }
        }
        break;
    case 11:
        break;
    case 1:
        if (find_nearest_visible_player(((TObjEneNanoDrago *)this), 0, 50.0f) != 0xFFFF) {
            ((TObjEneMe1GiGue *)this)->update_if_active(0xB);
            m_378 = 1;
        } else if (find_nearest_visible_player(((TObjEneNanoDrago *)this), 0, 50.0f + ((NanoDragoMovementParams *)movementParameters)->detectionRadius) == 0xFFFF) {
            ((TObjEneMe1GiGue *)this)->update_if_active(0);
        }
        break;
    }
}
void TObjEneNanoDrago::begin_hidden_flight() {
    Vec v;
    v.y = 0.0f;
    v.x = 0.0f;
    v.z = (-150.0f);
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, rotation_y);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    vec3_add_to(&position, &v);
    VecCopy((Vec *)&prev_position, (const Vec *)&position);
    actorFlags |= 0x01000000;
    ((TObjEneMe1GiGue *)this)->update_if_active(0xB);
    m_378 = 1;
    refresh_collision_body_centers();
}
void TObjEneNanoDrago::trigger_hit_camera_shake(u32 victim) {
    if ((victim == get_player_by_client_id(0)) && ((s32) cameraShakeCooldown <= 0)) {
        cameraShakeCooldown = 0x1E;
        TCameraCtrl::set_shake_preset(1);
    }
}
void TObjEneNanoDrago::update_fade_in_state() {
    s32 flags;
    s32 stateFlags;

    switch (state) {
    case 0:
        m_388 = (s32) (m_388 | 4);
        flags = actorFlags | 0x04000000;
        actorFlags = flags;
        requested_action = 0;
        play_area_sound_effect__12TBoss3VoloptFv((u8 *)(&m_2fc), flags);
        appearFade.start_fade_in();
        state = 1;
    case 1:
        advance_animation();
        if (appearFade.advance_toward_max() == 1) {
            state = -1;
        }
        ((TObjPlayer *)this)->update_collisions();
        return;
    case -1:
        stateFlags = m_388;
        m_388 = (s32) (stateFlags & ~5);
        actorFlags = (s32) (actorFlags & 0xFBFFFFFF);
        ((TObjEneMe1GiGue *)this)->update_if_active(0);
        break;
    }
}
void TObjEneNanoDrago::add_target_in_front_arc(TObjChara *candidate) {
  f32 dx;
  int heading;
  if ((((beamTargetCount < 12) && (candidate != 0)) && (candidate != this)) && (!(candidate->actorFlags & 0x6000800)))
  {
    Vec v = candidate->position;
    subtract_vector(&v, &position);
    if (!(((v.x * v.x) + (v.z * v.z)) > 160000.0f))
    {
      dx = v.x;
      heading = (-((s32) (lbl_8043C900[0] * atan2_float(v.z, dx)))) + 0x4000;
      if (angle_difference_abs(heading, rotation_y) <= 0xAAA)
      {
        s16 id = get_entity_id(candidate);
        u16 *ids = beamTargetIds;
        ids[beamTargetCount++] = id;
      }
    }
  }
}
s32 TObjEneNanoDrago::collect_beam_targets() {
    s32 i;
    TObjPlayer *candidate;
    beamTargetCount = 0;
    for (i = 0; i < registered_player_count + lbl_805D5870; i++) {
        candidate = TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((u32)candidate) != 0) {
            add_target_in_front_arc(candidate);
        }
    }
    return beamTargetCount;
}
void TObjEneNanoDrago::capture_beam_origins() {
    f32 modelScale;
    push_matrix_from(&identity_matrix);
    translate_matrix(0, (f32) (position.x), (f32) (flightHeight + (position.y + sinkingOffset)), position.z);
    rotate_matrix_y(0, rotation_y);
    modelScale = scale.x;
    scale_matrix(0, modelScale, modelScale, modelScale);
    calc_joint_matrices(frame);
    pop_matrix();
    get_anim_node_position(0x55, &beamOrigins[0]);
    get_anim_node_position(0x54, &beamOrigins[1]);
}
void TObjEneNanoDrago::update_attack_parameters() {
    s32 arg0 = (s32)this;
    lbl_805D525C = TObjPlayer__sub_800DC434((arg0), 1);
    lbl_805D5260 = TObjPlayer__sub_800DC434((arg0), 2);
    lbl_805D5264 = TObjPlayer__sub_800DC434((arg0), 3);
    lbl_805D5268 = TObjPlayer__sub_800DC434((arg0), 4);
    lbl_805D526C = TObjPlayer__sub_800DC420((void *)arg0, 0);
    lbl_805D5270 = TObjPlayer__sub_800DC420((void *)arg0, 1);
}

#pragma push
#pragma opt_common_subs off
void TObjEneNanoDrago::find_open_direction(Vec *direction) {
    s32 ang;
    s32 best;
    s32 i;
    f32 bias;
    f32 bestv;
    f32 d;
    CsnHit *h;
    ang = (s32)(lbl_8043C900[0] * atan2_float(direction->x, direction->z));
    bestv = 0.0f;
    best = ang;
    push_matrix_from(&identity_matrix);
    {
        Vec v = lbl_8043C8E4;
        rotate_matrix_y(0, ang);
        i = 0;
        bias = 20.0f;
        for (; i < 3; i++) {
            matrix_mult_vec(0, &v, &moveDestination);
            vec3_add_to(&moveDestination, &m_2fc);
            h = csnVector((Vec *)&m_2fc, &moveDestination, -1);
            if (h == NULL) {
                pop_matrix();
                return;
            }
            d = vec_xz_distance((Vec *)(&position), &h->contact->point) - bias;
            if (bestv < d) {
                bestv = d;
                best = ang;
            }
            rotate_matrix_y(0, 0x5555);
            ang += 0x5555;
        }
    }
    pop_matrix();
    push_matrix_from(&identity_matrix);
    {
        Vec v2 = find_open_direction_zero_vec;
        v2.x = bestv;
        rotate_matrix_y(0, best);
        matrix_mult_vec(0, &v2, &moveDestination);
        vec3_add_to(&moveDestination, &m_2fc);
        pop_matrix();
    }
}
#pragma pop
s32 TObjEneNanoDrago::update_action_hold_status() {
    s32 arg0 = (s32)this;
    if (TObjChara::update_action_hold_status() != 0) {
        ((TObjEneNanoDrago *)arg0)->sub_800D9BBC();
        return 1;
    }
    return 0;
}
