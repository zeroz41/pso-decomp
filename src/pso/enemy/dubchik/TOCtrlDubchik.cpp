#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/dubchik/TOCtrlDubchik.h"
#include "pso/enemy/dubchik/TObjEneDubchik.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/TextureState.h"
#include "pso/render/render_util.h"
#include "pso/render/BlobShadow.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/PlayerCommands.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TObject.h"


#include "pso/object/base/ActorCollision.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaModel.h"

static const char *bm_fs_obj_zombie_con_model_names[2] = { "fs_obj_zombie_con.gj", NULL };
static const char *bm_fs_obj_zombie_con_motion_names[1] = { NULL };
static BmlResourceDescriptor bm_fs_obj_zombie_con_resource_descriptor = {
    "bm_fs_obj_zombie_con.bml", bm_fs_obj_zombie_con_model_names, bm_fs_obj_zombie_con_motion_names, 1, 0,
};
static CollisionBody ctrl_dubchik_collision_body = { { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8005, { 0.0f, 0.0f, 0.0f }, 0.0f };
static const char *ctrl_dubchik_name = "TOCtrlDubchik";

// The switch's loaded BML resource (load_shared_resource loads it).
BmlResource *ctrl_dubchik_shared_resource;

void TOCtrlDubchik::apply_knockback_from_attacker(TObjBase *, f32) {  }

s32 TOCtrlDubchik::roll_physical_accuracy(TObjChara *attacker, s32 collider, f32 accuracy) {
    if (mode != 0) {
        return TObjChara::roll_physical_accuracy(attacker, collider, accuracy);
    }
    return 0;
}

s32 TOCtrlDubchik::try_start_action(TObjChara *attacker, s32 collider, f32 accuracy) {
    if (mode != 0) {
        return TObjChara::try_start_action(attacker, collider, accuracy);
    }
    return 0;
}

f32 TOCtrlDubchik::receive_direct_attack(TObjBase *attacker, DirectAttackPayload payload, CollisionBody *hit, s32, s32) {
    if (mode != 0) {
        return TObjChara::receive_direct_attack(attacker, payload, hit, -1, -1);
    }
    return 0.0f;
}

s32 TOCtrlDubchik::select_melee_contact_body(TObjChara *source, f32 factor) {
    if (mode != 0) {
        return TObjChara::select_melee_contact_body(source, factor);
    }
    return 0;
}

TOCtrlDubchik::TOCtrlDubchik(TObject *parent, void *set_data) : TObjEnemy(parent) {
    m_name = ctrl_dubchik_name;
    apply_set_data(set_data);
    init_position_vectors();
    model = ctrl_dubchik_shared_resource->models[0].model;
    texlist = ctrl_dubchik_shared_resource->models[0].texlist;
    init_collision_body_parts(this, &ctrl_dubchik_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    set_indexed_flags(0, 0x08000000);
    mode = 0;
    hp = 0x12C;
    hpmax = 0x12C;
    view_range = 400.0f;
    model_radius = ((GinjaModelBounds *)model->model)->radius;
    hover_height = 60.0f;
    bob_phase = 0;
    part_spread = 0.0f;
    effect_scale = 0.0f;
    spin_angle = 0;
    VecCopy(&shadow_pos, &home_position);
    visible = 1;
}

TOCtrlDubchik::~TOCtrlDubchik() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOCtrlDubchik::load_shared_resource() {
    ctrl_dubchik_shared_resource = new BmlResource(1, &bm_fs_obj_zombie_con_resource_descriptor, 0, 0, NULL);
}

void TOCtrlDubchik::destroy_instance() {
    if (ctrl_dubchik_shared_resource != NULL) {
        delete ctrl_dubchik_shared_resource;
        ctrl_dubchik_shared_resource = NULL;
    }
}

void *TOCtrlDubchik::create(void *set_data) {
    return new TOCtrlDubchik(tl_05, set_data);
}

void TOCtrlDubchik::render() {
    NJS_OBJECT *node;
    s32 rot_x;
    s32 rot_z;
    f32 shadow_scale;
    f32 scale[3];

    visible = update_object_view_visibility(view_range, model_radius);
    if (visible == 1) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(texlist));
        node = model;
        post_translate_matrix(node->pos);
        draw_ginja_model(node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1] + part_spread, node->pos[2]);
        draw_ginja_model(node->model);
        pop_matrix();
        push_matrix();
        node = node->sibling;
        translate_matrix(0, node->pos[0], node->pos[1] - part_spread, node->pos[2]);
        draw_ginja_model(node->model);
        pop_matrix();
        push_matrix();
        node = node->sibling;
        post_translate_matrix(node->pos);
        rotate_matrix_y(NULL, spin_angle);
        draw_ginja_model(node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        post_translate_matrix(node->pos);
        scale_matrix(NULL, effect_scale, 1.0f, effect_scale);
        draw_ginja_model(node->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
    }
    push_matrix();
    direction_to_rotation_xz((u8 *)&ground_normal, &rot_x, &rot_z);
    translate_matrix(0, shadow_pos.x, 0.3f + shadow_pos.y, shadow_pos.z);
    rotate_matrix_z(NULL, rot_z);
    rotate_matrix_x(NULL, rot_x);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, -0x4000);
    shadow_scale = 1.0f - 0.025f * (hover_height - 20.0f);
    scale[2] = 1.0f;
    scale[1] = shadow_scale;
    scale[0] = shadow_scale;
    scale_current_matrix(scale);
    draw_blob_shadow(0);
    pop_matrix();
}

void TOCtrlDubchik::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    if (test_actor_flags(0x800) != 0) {
        mode = 6;
    } else if (update_movement_status() != 0) {
        refresh_collision_body_centers();
        submit_cursor_candidate(this, -1);
        return;
    }
    switch (mode) {
    case 0:
        update_waiting();
        break;
    case 1:
        update_bobbing();
        break;
    case 2:
        update_effect_grow();
        break;
    case 3:
        update_spin();
        break;
    case 4:
        decay_timer_and_finish();
        break;
    case 5:
        decay_timer_and_clear_flag();
        break;
    case 6:
        complete_and_destroy();
        break;
    }
    VecCopy(&body_center, &position);
    refresh_collision_body_centers();
    submit_cursor_candidate(this, -1);
}

void TOCtrlDubchik::update_waiting() {
    s32 i;
    TObjEnemy *p;
    bob_phase += 2184.0f;
    hover_height = 60.0f + sin_table_lookup(bob_phase);
    apply_actor_gravity(this, (s32 *)&shadow_pos, hover_height);
    for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
        p = (TObjEnemy *)TObjPlayer::get_player_data(i);
        if (p != NULL && p != this && p->test_actor_flags(0x800) != 0 &&
            reinterpret_cast<TObject *>(p)->check_value_equals(dubchik_class_name) != 0 &&
            p->variant == 0 && room == p->room) {
            mode = 1;
        }
    }
}

void TOCtrlDubchik::update_bobbing() {
    bob_phase += 2184.0f;
    hover_height = 20.0f + sin_table_lookup(bob_phase);
    apply_actor_gravity(this, (s32 *)&shadow_pos, hover_height);
    part_spread += 0.1f;
    if (1.0f < part_spread) {
        part_spread = 1.0f;
        mode = 2;
    }
}

void TOCtrlDubchik::update_effect_grow() {
    bob_phase += 2184.0f;
    hover_height = 20.0f + sin_table_lookup(bob_phase);
    apply_actor_gravity(this, (s32 *)&shadow_pos, hover_height);
    effect_scale += 0.1f;
    if (1.0f < effect_scale) {
        effect_scale = 1.0f;
        mode = 3;
        clear_player_status_flag(0, 0x08000004);
        set_indexed_flags(0, 2);
    }
}

void TOCtrlDubchik::update_spin() {

    bob_phase += 2184.0f;
    hover_height = 20.0f + sin_table_lookup(bob_phase);
    apply_actor_gravity(this, (s32 *)&shadow_pos, hover_height);
    spin_angle += 0x147;
}

void TOCtrlDubchik::decay_timer_and_finish() {
    effect_scale -= 0.1f;
    if (effect_scale < 0.0f) {
        effect_scale = 0.0f;
        mode = 5;
    }
}

void TOCtrlDubchik::decay_timer_and_clear_flag() {
    part_spread -= 0.1f;
    if (part_spread < 0.0f) {
        part_spread = 0.0f;
        mode = 0;
        set_indexed_flags(0, 0x08000000);
    }
}

void TOCtrlDubchik::complete_and_destroy() {
    EnemyStateRecord state;
    if (exchange_object_state(&state, 1) != 0) {
        state.flags = 1;
        send_6x0A_enemy_state(&state);
        exchange_object_state(&state, 0);
        apply_enemy_state(&state.flags);
        kill_room_dubchiks();
        set_flag8();
        queue_destruction();
    }
}

void TOCtrlDubchik::kill_room_dubchiks() {
    s32 area;
    s32 i;
    TObjEnemy *p;
    spawn_particle_effect(&position, 0x45);
    spawn_particle_effect(&position, 0x46);
    area = get_current_floor_area();
    if (area >= 0x17 || area < 0x13) {
        play_sound_effect(0x4003AD16, &position, 0, 0);
    }
    for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
        p = (TObjEnemy *)TObjPlayer::get_player_data(i);
        if (p != NULL && p != this && p->check_value_equals(dubchik_class_name) != 0 &&
            p->variant == 0 && room == p->room) {
            ((TObjEneDubchik *)p)->start_dying();
        }
    }
}

f32 TOCtrlDubchik::receive_weapon_special_attack(TObjChara *attacker, CollisionBody *hit) {
    Vec pos;
    if (mode != 0) {
        if (TObjChara::select_melee_contact_body(attacker, 1.0f) != 0) {
            return TObjChara::receive_physical_attack(attacker, 1.0f);
        }
        if (hit != NULL) {
            VecCopy(&pos, &hit->center);
        } else {
            VecCopy(&pos, &body_center);
        }
        TOCtrlDubchik::create_font((saddr)&pos, (s32)0xFFFF0000, 0x14, "MISS");
    }
    return 0.0f;
}

void TOCtrlDubchik::run_demo_task() {  }

// Clears the two part offsets the constructor zeroes and render reads. Dead-stripped from the game:
// only its 0.0 literal remains.
void TOCtrlDubchik::clear_part_offsets() {
    part_spread = 0.0f;
    effect_scale = 0.0f;
}
