#include "types.h"
#include "pso/object/TObjLobbyMain.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/math/MatrixVector.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobbyEventTheme.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaUvScroll.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include <dolphin/base/PPCArch.h>

// Written from its last function back: the unit is built -inline off,deferred
// (configure.py), which emits the functions in reverse and puts the vtable
// ahead of the switch tables as in the original.

#pragma readonly_strings on

extern "C" {
void TLobby__sub_8001FE7C(BmlResource *resource, s32 del);
BmlResource *load_resource_from_descriptor(void *resource, s32 kind, BmlResourceDescriptor *descriptor, s32, s32, s32);
AnimationMotion *get_bml_motion(BmlResource *resource, s32 index);
void draw_ginja_model_with_motion(s32 model, AnimationMotion *motion, f32 frame);
extern s32 actor_frame_tick;
}

// One model per lobby theme; the themes with a motion have it in the motion
// list at the index lobby_main_model_motions gives.
__declspec(section ".data") const char *bm_obj_lobby_main_model_names[19] = {
    "lobby_kusabatake_waku.gj",
    "lobby_chou_nobana.gj",
    "lobby_obj_funsui.gj",
    "lobby_suisou_waku.gj",
    "lobby_tree_waku.gj",
    "lobby_window_waku.gj",
    "lobby_yukidaruma_waku.gj",
    "lobby_fuusya_waku.gj",
    "lobby_nijipipe_waku.gj",
    "lobby_planet_waku.gj",
    "lobby_obj_kadomatu_waku.gj",
    "lobby_tree_sakura_waku.gj",
    "lobby_ivent_christmas.gj",
    "lobby_momiji_waku.gj",
    "lobby_egg_kago.gj",
    "lobby_kabocya_l.gj",
    "lobby_obj_vday_main.gj",
    "lobby_obj_wday_main.gj",
    NULL,
};
__declspec(section ".data") const char *bm_obj_lobby_main_motion_names[6] = {
    "lobby_fuusya_waku.njm",
    "lobby_nijipipe_waku.njm",
    "lobby_planet_waku.njm",
    "lobby_kabocya_l.njm",
    "lobby_obj_vday_main.njm",
    NULL,
};
BmlResourceDescriptor bm_obj_lobby_main_resource_descriptor = { "bm_obj_lobby_main.bml", bm_obj_lobby_main_model_names, bm_obj_lobby_main_motion_names, 0x12, 5 };
CollisionBody lobby_main_collision_body = { { 0.0f, 0.0f, 0.0f }, 32.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f };
// The motion each model plays (5: none).
extern const s32 lobby_main_model_motions[18] = { 5, 5, 5, 5, 5, 5, 5, 0, 1, 2, 5, 5, 5, 5, 5, 3, 4, 4 };
const char *obj_lobby_main_class_name = "TObjLobbyMain";
BmlResource *TObjLobbyMain::model_resource;
u32 TObjLobbyMain::lobby_texlist;
NJS_CNK_MODEL *TObjLobbyMain::computer_screen_model;
NJS_CNK_MODEL *TObjLobbyMain::computer_screen_model_b;
s32 TObjLobbyMain::computer_last_frame_tick;

TObjLobbyMain::TObjLobbyMain(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_lobby_main_class_name;
    apply_object_set_data(set_data);
    emitter0 = create_particle_emitter(&position, 0x222);
    if (emitter0 != NULL) {
        ((TBoss4Type2 *)emitter0)->set_flags(0x40);
        emitter0->enable();
    }
    emitter1 = create_particle_emitter(&position, 0x222);
    if (emitter1 != NULL) {
        ((TBoss4Type2 *)emitter1)->set_flags(0x40);
        emitter1->enable();
    }
    set_mode_index_from_state();
    resolve_theme_index();
    update_emitter_positions();
    fade_scale = 1.0f;
    fade_state = 2;
    model_radius = 120.0f;
    m_b0 = 0.0f;
    init_collision_body_parts(this, &lobby_main_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TObjLobbyMain::~TObjLobbyMain() {
    if (emitter0 != NULL) {
        emitter0->queue_destruction();
        emitter0 = NULL;
    }
    if (emitter1 != NULL) {
        emitter1->queue_destruction();
        emitter1 = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjLobbyMain::load_resources() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &bm_obj_lobby_main_resource_descriptor, 0, 0, 0);
    }
    model_resource = (BmlResource *)resource;
    lobby_texlist = TLobby::get_lobby_texlist();
    computer_screen_model = (NJS_CNK_MODEL *)((NJS_OBJECT *)get_bml_model(model_resource, 6))
        ->child->sibling->sibling->sibling->sibling->sibling->sibling->model;
    computer_screen_model_b = (NJS_CNK_MODEL *)((NJS_OBJECT *)get_bml_model(model_resource, 2))
        ->child->sibling->sibling->sibling->model;
    computer_last_frame_tick = 0;
}

void TObjLobbyMain::free_resources() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void *TObjLobbyMain::create(void *set_data) {
    return new TObjLobbyMain(tl_05, set_data);
}

void TObjLobbyMain::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        demo_step();
    }
    switch (fade_state) {
    case 0:
        update_fade();
        break;
    case 1:
        update_fade_in();
        break;
    default:
    case 2:
        check_event_theme();
        break;
    }
    update_computer_machines();
    advance_motion_frame();
    update_particles();
}

void TObjLobbyMain::check_event_theme() {
    if (event_theme != get_theme_lobby_type()) {
        fade_state = 0;
        fade_scale = 1.0f;
    }
}

void TObjLobbyMain::update_fade() {
    fade_scale -= 0.1f;
    if (fade_scale <= 0.0f) {
        fade_state = 1;
        fade_scale = 0.0f;
        resolve_theme_index();
        update_emitter_positions();
        m_b0 = 0.0f;
    }
}

void TObjLobbyMain::update_fade_in() {
    fade_scale += 0.1f;
    if (fade_scale >= 1.0f) {
        fade_state = 2;
        fade_scale = 1.0f;
    }
}

void TObjLobbyMain::advance_motion_frame() {
    f32 last;
    s32 motion = lobby_main_model_motions[model_index];
    if (motion != 5) {
        last = (f32)get_bml_motion(model_resource, motion)->frameCount - 1.0f;
        m_b0 += 1.0f;
        if (last < m_b0) {
            m_b0 -= last;
        }
    }
}

void TObjLobbyMain::update_computer_machines() {
    if (computer_last_frame_tick != actor_frame_tick) {
        computer_last_frame_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(computer_screen_model, 1, 1, 10, 1);
        scroll_ginja_mesh_uvs(computer_screen_model_b, 0, -20, 26, 1);
        PPCSync();
    }
}

void TObjLobbyMain::render() {
    s16 index;
    s32 motion;
    if (lobby_texlist != 0 && update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (fade_state != 2) {
            scale_matrix(NULL, fade_scale, 1.0f, fade_scale);
        }
        TObjFish::set_global_param(lobby_texlist);
        index = model_index;
        motion = lobby_main_model_motions[index];
        if (motion != 5) {
            draw_ginja_model_with_motion(get_bml_model(model_resource, model_index), get_bml_motion(model_resource, motion), m_b0);
        } else {
            draw_ginja_object((void *)get_bml_model(model_resource, index));
        }
        pop_matrix();
    }
}

void TObjLobbyMain::update_particles() {
    if (fade_state == 2) {
        switch (model_index) {
        case 3:
            if (emitter0 != NULL) {
                emitter0->clear_active_flag();
            }
            if (emitter1 != NULL) {
                emitter1->clear_active_flag();
            }
            break;
        default:
            if (emitter0 != NULL) {
                emitter0->enable();
            }
            if (emitter1 != NULL) {
                emitter1->enable();
            }
            break;
        }
    } else {
        if (emitter0 != NULL) {
            emitter0->enable();
        }
        if (emitter1 != NULL) {
            emitter1->enable();
        }
    }
}

void TObjLobbyMain::update_emitter_positions() {
    switch (model_index) {
    case 3:
        if (emitter0 != NULL) {
            Vec pos = { 0.0f, 0.0f, 18.0f };
            ((TBoss4Type2 *)emitter0)->set_param_ptr(0x222);
            push_matrix();
            set_matrix_identity(NULL);
            post_translate_matrix(&position.x);
            rotate_matrix_y(NULL, rotation_y);
            matrix_mult_vec(NULL, &pos, &pos);
            emitter0->set_position(&pos);
            pop_matrix();
        }
        if (emitter1 != NULL) {
            Vec pos = { 0.0f, 0.0f, -18.0f };
            ((TBoss4Type2 *)emitter1)->set_param_ptr(0x222);
            push_matrix();
            set_matrix_identity(NULL);
            post_translate_matrix(&position.x);
            rotate_matrix_y(NULL, rotation_y);
            matrix_mult_vec(NULL, &pos, &pos);
            emitter1->set_position(&pos);
            pop_matrix();
        }
        break;
    }
}

void TObjLobbyMain::set_mode_index_from_state() {
    switch (set_params[0]) {
    case 1:
        set_model_index = 1;
        return;
    case 2:
        set_model_index = 2;
        return;
    case 3:
        set_model_index = 3;
        return;
    case 4:
        set_model_index = 4;
        return;
    case 5:
        set_model_index = 5;
        return;
    case 6:
        set_model_index = 6;
        return;
    case 7:
        set_model_index = 7;
        return;
    case 8:
        set_model_index = 8;
        return;
    case 9:
        set_model_index = 9;
        return;
    default:
        set_model_index = 0;
        return;
    }
}

void TObjLobbyMain::resolve_theme_index() {
    event_theme = get_theme_lobby_type();
    switch (event_theme) {
    case 1:
        model_index = 12;
        return;
    case 5:
        model_index = 15;
        return;
    case 7:
        model_index = 10;
        return;
    case 3:
        model_index = 16;
        return;
    case 9:
        model_index = 17;
        return;
    case 8:
        model_index = 11;
        return;
    case 4:
        model_index = 14;
        return;
    case 10:
        model_index = 1;
        return;
    case 11:
        model_index = 13;
        return;
    default:
        model_index = set_model_index;
        return;
    }
}

void TObjLobbyMain::demo_step() {}
