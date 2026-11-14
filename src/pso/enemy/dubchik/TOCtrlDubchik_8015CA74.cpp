#define TOBJECT_OUT_OF_LINE_HELPERS
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
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

// What receive_weapon_special_attack's second argument points at: its hit position at 0x1C.
struct A_8015C9D4 { u8 pad[0x1C]; Vec pos; };

static const char *bm_fs_obj_zombie_con_model_names[2] = { "fs_obj_zombie_con.gj", NULL };
static const char *bm_fs_obj_zombie_con_motion_names[1] = { NULL };
static BmlResourceDescriptor bm_fs_obj_zombie_con_resource_descriptor = {
    "bm_fs_obj_zombie_con.bml", bm_fs_obj_zombie_con_model_names, bm_fs_obj_zombie_con_motion_names, 1, 0,
};
static CollisionBody TOCtrlDubchik__collision_body = { { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8005, { 0.0f, 0.0f, 0.0f }, 0.0f };
static const char *TOCtrlDubchik__name = "TOCtrlDubchik";

extern "C" {
s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TOCtrlDubchik__shared_resource;
s32 try_start_action__9TObjCharaFll(void *, void *, void *);
s32 roll_physical_accuracy__9TObjCharaFPvlf(void *, void *, void *, f32);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
void dubchik_start_dying(u8 *arg0);
void free_bin_model_request(void*, int);
s32 select_melee_contact_body__9TObjCharaFPvf();
void TOCtrlDubchik__sub_8015C9D0(u8 *);

void TOCtrlDubchik::apply_knockback_from_attacker(u8 *, f32) {  }

s32 TOCtrlDubchik::roll_physical_accuracy(void *arg1, s32 arg2, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    if (this->mode != 0) {
        return roll_physical_accuracy__9TObjCharaFPvlf((void *)arg0, (void *)arg1, (void *)arg2, (f32)farg0);
    }
    return 0;
}

s32 TOCtrlDubchik::try_start_action(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (this->mode != 0) {
        return try_start_action__9TObjCharaFll((void *)arg0, (void *)arg1, (void *)arg2);
    }
    return 0;
}

f32 TOCtrlDubchik::receive_direct_attack(void *attacker, DirectAttackPayload payload, void *hit, s32, s32) {
    if (mode != 0) {
        return TObjChara::receive_direct_attack(attacker, payload, hit, -1, -1);
    }
    return 0.0f;
}

s32 TOCtrlDubchik::select_melee_contact_body(void *, f32) {
    if (this->mode != 0) {
        return select_melee_contact_body__9TObjCharaFPvf();
    }
    return 0;
}

TOCtrlDubchik::TOCtrlDubchik(TObject *parent, void *set_data) : TObjEnemy(parent) {
    m_name = TOCtrlDubchik__name;
    apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    model = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOCtrlDubchik__shared_resource) + 0x42C)) + 8));
    texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOCtrlDubchik__shared_resource) + 0x42C)) + 0xC);
    init_collision_body_parts(this, &TOCtrlDubchik__collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    set_indexed_flags(0, 0x08000000);
    mode = 0;
    hp = 0x12C;
    hpmax = 0x12C;
    view_range = 400.0f;
    model_radius = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)model + 4)) + 0x14);
    hover_height = 60.0f;
    bob_phase = 0;
    part_spread = 0.0f;
    effect_scale = 0.0f;
    spin_angle = 0;
    VecCopy(&shadow_pos, (const Vec *)((u8 *)this + 0x50));
    visible = 1;
}

TOCtrlDubchik::~TOCtrlDubchik() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOCtrlDubchik::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_zombie_con_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TOCtrlDubchik__shared_resource) = var_r0;
}

void TOCtrlDubchik::destroy_instance() {
    if ((u32) TOCtrlDubchik__shared_resource != 0U) {
        free_bin_model_request((void*)TOCtrlDubchik__shared_resource, 1);
        TOCtrlDubchik__shared_resource = 0U;
    }
}

void *TOCtrlDubchik::create(void *arg0) {
    return new TOCtrlDubchik(tl_05, arg0);
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
        TObjFish::set_global_param(texlist);
        node = (NJS_OBJECT *)model;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1] + part_spread, node->pos[2]);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        push_matrix();
        node = node->sibling;
        translate_matrix(0, node->pos[0], node->pos[1] - part_spread, node->pos[2]);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        push_matrix();
        node = node->sibling;
        post_translate_matrix(node->pos);
        rotate_matrix_y(NULL, spin_angle);
        draw_ginja_model((s32)node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        post_translate_matrix(node->pos);
        scale_matrix(NULL, effect_scale, 1.0f, effect_scale);
        draw_ginja_model((s32)node->model);
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
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TOCtrlDubchik__sub_8015C9D0(arg0);
        return;
    }
    if (((TObjCollidable *)arg0)->obj_testFlags30(0x800) != 0) {
        *(s16 *)(arg0 + 0x326) = 6;
    } else if (this->update_movement_status() != 0) {
        ((TObjCollidable *)arg0)->refresh_collision_body_centers();
        submit_cursor_candidate(arg0, -1);
        return;
    }
    switch (*(s16 *)(arg0 + 0x326)) {
    case 0:
        ((TOCtrlDubchik *)arg0)->sub_8015CE80();
        break;
    case 1:
        ((TOCtrlDubchik *)arg0)->update_bobbing();
        break;
    case 2:
        ((TOCtrlDubchik *)arg0)->sub_8015CCF4();
        break;
    case 3:
        ((TOCtrlDubchik *)arg0)->update_spin();
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
    VecCopy((Vec *)&this->m_2fc, (const Vec *)&this->position);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    submit_cursor_candidate(arg0, -1);
}

void TOCtrlDubchik::sub_8015CE80() {
    s32 i;
    u8 *p;
    bob_phase += 2184.0f;
    hover_height = 60.0f + sin_table_lookup(bob_phase);
    apply_actor_gravity(this, (s32 *)&shadow_pos, hover_height);
    for (i = registered_player_count; i < registered_player_count + lbl_805D5870; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (p != NULL && p != ((u8 *)this) && ((TObjCollidable *)p)->obj_testFlags30(0x800) != 0 &&
            ((TUnk_804B6C24 *)p)->check_value_equals((s32)TObjEneDubchik__class_name) != 0 &&
            *(s32 *)(p + 0x368) == 0 && *(s16 *)(((u8 *)this) + 0x28) == *(s16 *)(p + 0x28)) {
            this->mode = 1;
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

void TOCtrlDubchik::sub_8015CCF4() {
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
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    if (exchange_object_state__9TObjEnemyFls(arg0, &sp8, 1) != 0) {
        sp8 = 1;
        ((TObjEnemy *)arg0)->send_6x0A_enemy_state(&sp8);
        exchange_object_state__9TObjEnemyFls(arg0, &sp8, 0);
        vfunc_79(&sp8);
        ((TOCtrlDubchik *)arg0)->sub_8015CA74();
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
    }
}

void TOCtrlDubchik::sub_8015CA74() {
    u8 *arg0 = (u8 *)this;
    s32 area;
    s32 i;
    u8 *p;
    spawn_particle_effect(&this->position, 0x45);
    spawn_particle_effect(&this->position, 0x46);
    area = get_current_floor_area();
    if (area >= 0x17 || area < 0x13) {
        play_sound_effect(0x4003AD16, (u8 *)&this->position, 0, 0);
    }
    for (i = registered_player_count; i < registered_player_count + lbl_805D5870; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (p != NULL && p != arg0 && ((TUnk_804B6C24 *)p)->check_value_equals((s32)TObjEneDubchik__class_name) != 0 &&
            *(s32 *)(p + 0x368) == 0 && *(s16 *)(arg0 + 0x28) == *(s16 *)(p + 0x28)) {
            dubchik_start_dying(p);
        }
    }
}

f32 TOCtrlDubchik::receive_weapon_special_attack(void *attacker, void *hit) {
    Vec pos;
    if (mode != 0) {
        if (TObjChara::select_melee_contact_body(attacker, 1.0f) != 0) {
            return TObjChara::receive_physical_attack(attacker, 1.0f);
        }
        if (hit != NULL) {
            VecCopy(&pos, &((A_8015C9D4 *)hit)->pos);
        } else {
            VecCopy(&pos, (Vec *)&m_2fc);
        }
        TOCtrlDubchik::create_font((s32)&pos, (s32)0xFFFF0000, 0x14, (s32)"MISS");
    }
    return 0.0f;
}

void TOCtrlDubchik__sub_8015C9D0(u8 *) {  }

// Dead-stripped from the DOL: no code of it survives. The TU's .sdata2 pool opens
// with 0.0 (0x805DB3A8) ahead of receive_weapon_special_attack's 1.0 although that
// function loads 1.0 first, so a function before it used 0.0 first. Minimal body:
// it clears the two part offsets the constructor zeroes and render reads.
// Name inferred from that role.
void TOCtrlDubchik::clear_part_offsets() {
    part_spread = 0.0f;
    effect_scale = 0.0f;
}


}

extern "C" {
u32 TOCtrlDubchik__shared_resource;
}
