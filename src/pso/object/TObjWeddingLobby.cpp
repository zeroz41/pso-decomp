#include "types.h"
#include "pso/object/TObjWeddingLobby.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"

#pragma readonly_strings on

extern "C" {
void TLobby__sub_8001FE7C(BmlResource *resource, s32 del);
BmlResource *load_resource_from_descriptor(void *resource, s32 kind, BmlResourceDescriptor *descriptor, s32, s32, s32);
AnimationMotion *get_bml_motion(BmlResource *resource, s32 index);
void draw_ginja_model_with_motion(s32 model, AnimationMotion *motion, f32 frame);
}

__declspec(section ".data") const char *bm_obj_lobby_bell_model_names[3] = { "lobby_obj_bell_D8_yane.gj", "lobby_obj_bell_VN_null1.gj", NULL };
__declspec(section ".data") const char *bm_obj_lobby_bell_motion_names[2] = { "lobby_obj_bell_VN_null1.njm", NULL };
BmlResourceDescriptor bm_obj_lobby_bell_resource_descriptor = { "bm_obj_lobby_bell.bml", bm_obj_lobby_bell_model_names, bm_obj_lobby_bell_motion_names, 2, 1 };
const char *obj_wedding_lobby_class_name = "TObjWeddingLobby";
BmlResource *TObjWeddingLobby::resource_bundle;
u32 TObjWeddingLobby::lobby_texlist;

void TObjWeddingLobby::demo_step() {}

void TObjWeddingLobby::render() {
    if (fade_state != 0 && lobby_texlist != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(lobby_texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (fade_state != 3) {
            scale_matrix(NULL, fade_scale, 1.0f, fade_scale);
        }
        draw_ginja_object((void *)get_bml_model(resource_bundle, 0));
        draw_ginja_model_with_motion(get_bml_model(resource_bundle, 1), get_bml_motion(resource_bundle, 0), m_b0);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjWeddingLobby::run_task() {
    f32 last;
    if (TObjPlayer::check_demo_mode() == 1) {
        demo_step();
    }
    switch (fade_state) {
    case 0:
        if (TLobby::get_filtered_event_theme() == 10) {
            fade_state = 2;
        }
        break;
    case 2:
        fade_scale += 0.1f;
        if (fade_scale >= 1.0f) {
            fade_scale = 1.0f;
            fade_state = 3;
        }
        break;
    case 1:
        fade_scale -= 0.1f;
        if (fade_scale <= 0.0f) {
            fade_scale = 0.0f;
            fade_state = 0;
        }
        break;
    case 3:
    default:
        if (TLobby::get_filtered_event_theme() != 10) {
            fade_state = 1;
        }
        break;
    }
    last = (f32)get_bml_motion(resource_bundle, 0)->frameCount - 1.0f;
    m_b0 += 2.0f;
    if (last < m_b0) {
        m_b0 -= last;
    }
}

void *TObjWeddingLobby::create(void *set_data) {
    return new TObjWeddingLobby(tl_05, set_data);
}

void TObjWeddingLobby::free_resources() {
    if (resource_bundle != NULL) {
        TLobby__sub_8001FE7C(resource_bundle, 1);
        resource_bundle = NULL;
    }
}

void TObjWeddingLobby::load_resources() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &bm_obj_lobby_bell_resource_descriptor, 0, 0, 0);
    }
    resource_bundle = (BmlResource *)resource;
    lobby_texlist = TLobby::get_lobby_texlist();
}

TObjWeddingLobby::~TObjWeddingLobby() {}

TObjWeddingLobby::TObjWeddingLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_wedding_lobby_class_name;
    apply_object_set_data(set_data);
    if (TLobby::get_filtered_event_theme() == 10) {
        fade_state = 3;
    } else {
        fade_state = 0;
    }
    fade_scale = 1.0f;
    m_b0 = 0.0f;
}
