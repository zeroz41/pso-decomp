#include "types.h"
#include "pso/object/TObjRainbowLobby.h"
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
// Defined (returning u8) in the lobby-event module; the original callers test
// the full register.
s32 is_lobby_event_active(void);
}

const char *bm_obj_lobby_rainbow_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_obj_lobby_rainbow_model_names[2] = { "lobby_obj_niji.gj", NULL };
BmlResourceDescriptor bm_obj_lobby_rainbow_resource_descriptor = { "bm_obj_lobby_rainbow.bml", bm_obj_lobby_rainbow_model_names, bm_obj_lobby_rainbow_motion_names, 1, 0 };
const char *obj_rainbow_lobby_class_name = "TObjRainbowLobby";
BmlResource *TObjRainbowLobby::shared_model_resource;

void TObjRainbowLobby::render() {
    if (state != 0) {
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

void TObjRainbowLobby::run_task() {
    switch (state) {
    case 0:
        if (TLobby::is_connected() != 0) {
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
        if (TLobby::is_lobby_obj_active() != 0) {
            state = 1;
        }
        break;
    }
}

void *TObjRainbowLobby::create(void *set_data) {
    return new TObjRainbowLobby(tl_05, set_data);
}

void TObjRainbowLobby::free_static_data() {
    if (shared_model_resource != NULL) {
        TLobby__sub_8001FE7C(shared_model_resource, 1);
        shared_model_resource = NULL;
    }
}

void TObjRainbowLobby::load_shared_resource() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_obj_lobby_rainbow_resource_descriptor, 0, 0, 0);
    }
    shared_model_resource = (BmlResource *)resource;
}

TObjRainbowLobby::~TObjRainbowLobby() {}

TObjRainbowLobby::TObjRainbowLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_rainbow_lobby_class_name;
    apply_object_set_data(set_data);
    if (is_lobby_event_active() != 0) {
        state = 0;
    } else {
        state = 3;
    }
    scale = 1.0f;
    model = (void *)shared_model_resource->models->model;
    texlist = shared_model_resource->models->m_c;
}
