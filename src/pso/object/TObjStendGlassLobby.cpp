#include "types.h"
#include "pso/object/TObjStendGlassLobby.h"
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

const char *bm_obj_lobby_stendglass_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_obj_lobby_stendglass_model_names[2] = { "lobby_win_s_waku1.gj", NULL };
BmlResourceDescriptor bm_obj_lobby_stendglass_resource_descriptor = { "bm_obj_lobby_stendglass.bml", bm_obj_lobby_stendglass_model_names, bm_obj_lobby_stendglass_motion_names, 1, 0 };
const char *obj_stendglass_lobby_class_name = "TObjStendGlassLobby";
BmlResource *TObjStendGlassLobby::static_model_resource;
u32 TObjStendGlassLobby::lobby_texlist;

void TObjStendGlassLobby::demo_step() {}

void TObjStendGlassLobby::render() {
    if (fade_state != 0 && (u32)texlist != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (fade_state != 3) {
            scale_matrix(NULL, fade_scale, 1.0f, fade_scale);
        }
        draw_ginja_object(model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjStendGlassLobby::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        demo_step();
    }
    switch (fade_state) {
    case 0:
        if (event_theme == TLobby::get_filtered_event_theme()) {
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
        if (event_theme != TLobby::get_filtered_event_theme()) {
            fade_state = 1;
        }
        break;
    }
}

void TObjStendGlassLobby::update_state() {
    if ((s32)set_params[0] < 1) {
        event_theme = 0;
    } else {
        event_theme = 1;
    }
    if (event_theme == TLobby::get_filtered_event_theme()) {
        fade_state = 3;
        return;
    }
    fade_state = 0;
}

void *TObjStendGlassLobby::create(void *set_data) {
    return new TObjStendGlassLobby(tl_05, set_data);
}

void TObjStendGlassLobby::free_static_model() {
    if (static_model_resource != NULL) {
        TLobby__sub_8001FE7C(static_model_resource, 1);
        static_model_resource = NULL;
    }
}

void TObjStendGlassLobby::load_resources() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &bm_obj_lobby_stendglass_resource_descriptor, 0, 0, 0);
    }
    static_model_resource = (BmlResource *)resource;
    lobby_texlist = TLobby::get_lobby_texlist();
}

TObjStendGlassLobby::~TObjStendGlassLobby() {}

TObjStendGlassLobby::TObjStendGlassLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_stendglass_lobby_class_name;
    apply_object_set_data(set_data);
    update_state();
    fade_scale = 1.0f;
    model = (void *)static_model_resource->models->model;
    texlist = lobby_texlist;
}
