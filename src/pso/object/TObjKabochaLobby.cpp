#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjKabochaLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80479170[];
extern char lbl_80479184[];
extern const char *bm_obj_lobby_kabocha_model_names[2];
extern BmlResourceDescriptor lobby_pumpkin_resource_descriptor;
extern const char *bm_obj_lobby_kabocha_motion_names[1];


extern "C" {

s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void TLobby__sub_8001FE7C(void*, int);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjKabochaLobby__model_resource;
extern s32 lbl_805D4384;

extern s32 TObjKabochaLobby__lobby_type;

void TObjKabochaLobby::render() {
    f32 temp_f1;

    if ((this->state != 0) && ((u32) TObjKabochaLobby__lobby_type != 0U) && (this->update_object_view_visibility(this->m_c0, this->model_radius) != 0)) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if (this->state != 3) {
            temp_f1 = this->scale;
            scale_matrix(0, temp_f1, (f32) (1.0f), temp_f1);
        }
        draw_ginja_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

extern void *tl_05;

void TObjKabochaLobby::run_task() {
    switch (state) {
    case 0:
        if (TLobby::get_filtered_event_theme() == 5) {
            state = 2;
        }
        break;
    case 2:
        {
        scale += 0.1f;
        if (scale >= 1.0f) {
            scale = 1.0f;
            state = 3;
        }
        }
        break;
    case 1:
        {
        scale -= 0.1f;
        if (scale <= 0.0f) {
            scale = 0.0f;
            state = 0;
        }
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

void *TObjKabochaLobby::create(void *arg0) {
    return new TObjKabochaLobby((TObject *)tl_05, arg0);
}

void TObjKabochaLobby::unload_static_data() {
    if ((u32) TObjKabochaLobby__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjKabochaLobby__model_resource, 1);
        TObjKabochaLobby__model_resource = 0U;
    }
}
void TObjKabochaLobby::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &lobby_pumpkin_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjKabochaLobby__model_resource) = var_r0;
    TObjKabochaLobby__lobby_type = TLobby::get_lobby_type();
}
TObjKabochaLobby::~TObjKabochaLobby() {}
TObjKabochaLobby::TObjKabochaLobby(TObject *parent, void *set_data) : TUnk_804AFBF8(parent) {
    m_name = (const char *)lbl_805D4384;
    apply_object_set_data(set_data);
    if (TLobby::get_filtered_event_theme() == 5) {
        state = 3;
    } else {
        state = 0;
    }
    scale = 1.0f;
    model = (void *) *(s32 *)((s8 *)(*(void **)((s8 *)((void *)TObjKabochaLobby__model_resource) + 0x42C)) + 8);
    texlist = (s32) TObjKabochaLobby__lobby_type;
}

__declspec(section ".data") const char *bm_obj_lobby_kabocha_model_names[2] = { lbl_80479170, NULL };
BmlResourceDescriptor lobby_pumpkin_resource_descriptor = { lbl_80479184, bm_obj_lobby_kabocha_model_names, bm_obj_lobby_kabocha_motion_names, 1, 0 };
}
