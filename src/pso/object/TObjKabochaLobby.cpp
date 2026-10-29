#include "types.h"
#include "pso/object/TObjKabochaLobby.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
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

const char *bm_obj_lobby_kabocha_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_obj_lobby_kabocha_model_names[2] = { "lobby_kabocya_s.gj", NULL };
BmlResourceDescriptor lobby_pumpkin_resource_descriptor = { "bm_obj_lobby_kabocha.bml", bm_obj_lobby_kabocha_model_names, bm_obj_lobby_kabocha_motion_names, 1, 0 };
const char *obj_kabocha_lobby_class_name = "TObjKabochaLobby";
BmlResource *TObjKabochaLobby::model_resource;
u32 TObjKabochaLobby::lobby_texlist;

void TObjKabochaLobby::render() {
    if (state != 0 && lobby_texlist != 0 && update_object_view_visibility(m_c0, model_radius) != 0) {
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

void TObjKabochaLobby::run_task() {
    switch (state) {
    case 0:
        if (TLobby::get_filtered_event_theme() == 5) {
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
        if (TLobby::get_filtered_event_theme() != 5) {
            state = 1;
        }
        break;
    }
}

void *TObjKabochaLobby::create(void *set_data) {
    return new TObjKabochaLobby(tl_05, set_data);
}

void TObjKabochaLobby::unload_static_data() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TObjKabochaLobby::load_resources() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &lobby_pumpkin_resource_descriptor, 0, 0, 0);
    }
    model_resource = (BmlResource *)resource;
    lobby_texlist = TLobby::get_lobby_texlist();
}

TObjKabochaLobby::~TObjKabochaLobby() {}

TObjKabochaLobby::TObjKabochaLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_kabocha_lobby_class_name;
    apply_object_set_data(set_data);
    if (TLobby::get_filtered_event_theme() == 5) {
        state = 3;
    } else {
        state = 0;
    }
    scale = 1.0f;
    model = (void *)model_resource->models->model;
    texlist = lobby_texlist;
}
