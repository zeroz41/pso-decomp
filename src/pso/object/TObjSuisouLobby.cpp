#include "types.h"
#include "pso/object/TObjSuisouLobby.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/boss/TBoss5GryphonLightningWing.h"
#include "pso/math/MatrixVector.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"

#pragma readonly_strings on

extern "C" {
void TLobby__sub_8001FE7C(BmlResource *resource, s32 del);
BmlResource *load_resource_from_descriptor(void *resource, s32 kind, BmlResourceDescriptor *descriptor, s32, s32, s32);
}

__declspec(section ".data") const char *bm_obj_lobby_suisou_model_names[2] = { "lobby_suisou_s_waku.gj", NULL };
__declspec(section ".sdata") const char *bm_obj_lobby_suisou_motion_names[1] = { NULL };
BmlResourceDescriptor bm_obj_lobby_suisou_resource_descriptor = { "bm_obj_lobby_suisou.bml", bm_obj_lobby_suisou_model_names, bm_obj_lobby_suisou_motion_names, 1, 0 };
const char *obj_suisou_lobby_class_name = "TObjSuisouLobby";
// Where the two bubble emitters sit, in the tank's own space.
const Vec obj_suisou_lobby_front_bubbles = { 0.0f, 0.0f, 60.0f };
const Vec obj_suisou_lobby_back_bubbles = { 0.0f, 0.0f, -60.0f };
BmlResource *TObjSuisouLobby::model_resource;
u32 TObjSuisouLobby::lobby_texlist;

void TObjSuisouLobby::demo_step() {}

void TObjSuisouLobby::render() {
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

void TObjSuisouLobby::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        demo_step();
    }
    switch (fade_state) {
    case 0:
        if (TLobby::is_connected() != 0) {
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
        if (TLobby::is_lobby_obj_active() != 0) {
            fade_state = 1;
        }
        break;
    }
    update_particle();
}

void TObjSuisouLobby::update_particle() {
    if (fade_state == 3) {
        if (emitter0 != NULL) {
            emitter0->clear_active_flag();
        }
        if (emitter1 != NULL) {
            emitter1->clear_active_flag();
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

void TObjSuisouLobby::sub_80369D68() {}

void *TObjSuisouLobby::create(void *set_data) {
    return new TObjSuisouLobby(tl_05, set_data);
}

void TObjSuisouLobby::free_resources() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TObjSuisouLobby::load_resources() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &bm_obj_lobby_suisou_resource_descriptor, 0, 0, 0);
    }
    model_resource = (BmlResource *)resource;
    lobby_texlist = TLobby::get_lobby_texlist();
}

TObjSuisouLobby::~TObjSuisouLobby() {
    if (emitter0 != NULL) {
        emitter0->queue_destruction();
        emitter0 = NULL;
    }
    if (emitter1 != NULL) {
        emitter1->queue_destruction();
        emitter1 = NULL;
    }
}

TObjSuisouLobby::TObjSuisouLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_suisou_lobby_class_name;
    apply_object_set_data(set_data);
    {
        Vec pos = obj_suisou_lobby_front_bubbles;
        push_matrix();
        set_matrix_identity(NULL);
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        matrix_mult_vec(NULL, &pos, &pos);
        emitter0 = create_particle_emitter(&pos, 0x222);
        pop_matrix();
        if (emitter0 != NULL) {
            emitter0->enable();
        }
    }
    {
        Vec pos = obj_suisou_lobby_back_bubbles;
        push_matrix();
        set_matrix_identity(NULL);
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        matrix_mult_vec(NULL, &pos, &pos);
        emitter1 = create_particle_emitter(&pos, 0x222);
        pop_matrix();
        if (emitter1 != NULL) {
            emitter1->enable();
        }
    }
    if (is_lobby_event_active() != 0) {
        fade_state = 0;
    } else {
        fade_state = 3;
    }
    sub_80369D68();
    fade_scale = 1.0f;
    model = (void *)model_resource->models->model;
    texlist = lobby_texlist;
}
