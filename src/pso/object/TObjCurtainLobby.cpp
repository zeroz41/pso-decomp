#include "types.h"
#include "pso/object/TObjCurtainLobby.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
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
}

__declspec(section ".sdata") const char *bm_obj_lobby_curtain_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_obj_lobby_curtain_model_names[2] = { "lobby_kouhaku_hashira.gj", NULL };
BmlResourceDescriptor bm_obj_lobby_curtain_resource_descriptor = { "bm_obj_lobby_curtain.bml", bm_obj_lobby_curtain_model_names, bm_obj_lobby_curtain_motion_names, 1, 0 };
const char *obj_curtain_lobby_class_name = "TObjCurtainLobby";
BmlResource *TObjCurtainLobby::model_resource;
u32 TObjCurtainLobby::lobby_texlist;

s32 TObjCurtainLobby::get_lobby_theme_clamped() {
    s32 theme = TLobby::get_filtered_event_theme();
    switch (theme) {
    case 12:
    case 13:
        theme = 12;
        break;
    }
    return theme;
}

void TObjCurtainLobby::demo_step() {}

void TObjCurtainLobby::render() {
    if (state != 0 && (u32)texlist != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (state != 3) {
            scale_matrix(NULL, scale, 1.0f, scale);
        }
        draw_ginja_object(model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjCurtainLobby::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        demo_step();
    }
    switch (state) {
    case 0:
        if (get_lobby_theme_clamped() == 12) {
            state = 2;
        }
        break;
    case 2:
        scale += 0.1f;
        if (scale >= 1.0f) {
            scale = 1.0f;
            state = 3;
        }
        break;
    case 1:
        scale -= 0.1f;
        if (scale <= 0.0f) {
            scale = 0.0f;
            state = 0;
        }
        break;
    case 3:
    default:
        if (get_lobby_theme_clamped() != 12) {
            state = 1;
        }
        break;
    }
}

void *TObjCurtainLobby::create(void *set_data) {
    return new TObjCurtainLobby(tl_05, set_data);
}

void TObjCurtainLobby::free_resources() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TObjCurtainLobby::load_resources() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &bm_obj_lobby_curtain_resource_descriptor, 0, 0, 0);
    }
    model_resource = (BmlResource *)resource;
    lobby_texlist = TLobby::get_lobby_texlist();
}

TObjCurtainLobby::~TObjCurtainLobby() {}

TObjCurtainLobby::TObjCurtainLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_curtain_lobby_class_name;
    apply_object_set_data(set_data);
    if (get_lobby_theme_clamped() == 12) {
        state = 3;
    } else {
        state = 0;
    }
    scale = 1.0f;
    model = (void *)model_resource->models->model;
    texlist = lobby_texlist;
}
