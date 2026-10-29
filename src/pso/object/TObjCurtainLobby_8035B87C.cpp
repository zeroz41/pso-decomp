#include "types.h"
#include "pso/object/TObjCurtainLobby_8035B87C.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjCurtainLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_804798F0[];
extern char lbl_8047990C[];
extern const char *bm_obj_lobby_curtain_model_names[2];
extern BmlResourceDescriptor lobby_curtain_resource_descriptor;
extern const char *bm_obj_lobby_curtain_motion_names[1];


extern "C" {
s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void TLobby__sub_8001FE7C(void*, int);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjCurtainLobby__model_resource;
extern s32 curtain_lobby_type;
extern s32 TObjCurtainLobby__class_name;

#pragma push
#pragma opt_propagation off
s32 get_lobby_theme_clamped__16TObjCurtainLobbyFv(void) {
    s32 filtered_event_theme;
    filtered_event_theme = TLobby::get_filtered_event_theme();
    if (filtered_event_theme < 0xE) {
        if (filtered_event_theme < 0xC) {
            return filtered_event_theme;
        }
        filtered_event_theme = 0xC;
        return filtered_event_theme;
    }
    return filtered_event_theme;
}
#pragma pop

void TObjCurtainLobby__sub_8035B8B4(void) {  }

void TObjCurtainLobby::render() {
    f32 temp_f1;

    if ((this->state != 0) && ((u32) this->texlist != 0U)) {
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
void TObjCurtainLobby::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjCurtainLobby__sub_8035B8B4)(this);
    }
    switch (state) {
    case 0:
        if (((s32 (*)(void *))get_lobby_theme_clamped__16TObjCurtainLobbyFv)(this) == 0xC) {
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
        scale = scale - 0.1f;
        if (scale <= 0.0f) {
            scale = 0.0f;
            state = 0;
        }
        break;
    case 3:
    default:
        if (((s32 (*)(void *))get_lobby_theme_clamped__16TObjCurtainLobbyFv)(this) != 0xC) {
            state = 1;
        }
        break;
    }
}

extern void *tl_05;
void *TObjCurtainLobby::create(void *arg0) {
    return new TObjCurtainLobby((TObject *)tl_05, arg0);
}
void TObjCurtainLobby::close_dialog_window() {
    if ((u32) TObjCurtainLobby__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjCurtainLobby__model_resource, 1);
        TObjCurtainLobby__model_resource = 0U;
    }
}
void TObjCurtainLobby::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &lobby_curtain_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjCurtainLobby__model_resource) = var_r0;
    curtain_lobby_type = TLobby::get_lobby_type();
}
TObjCurtainLobby::~TObjCurtainLobby() {}
TObjCurtainLobby::TObjCurtainLobby(TObject *parent, void *set_data) : TUnk_804AFBF8(parent) {
    m_name = (const char *)TObjCurtainLobby__class_name;
    apply_object_set_data(set_data);
    if (((s32 (*)(void *))get_lobby_theme_clamped__16TObjCurtainLobbyFv)(this) == 0xC) {
        state = 3;
    } else {
        state = 0;
    }
    scale = 1.0f;
    model = (void *) *(s32 *)((s8 *)(*(void **)((s8 *)((void *)TObjCurtainLobby__model_resource) + 0x42C)) + 8);
    texlist = (s32) curtain_lobby_type;
}

__declspec(section ".data") const char *bm_obj_lobby_curtain_model_names[2] = { lbl_804798F0, NULL };
BmlResourceDescriptor lobby_curtain_resource_descriptor = { lbl_8047990C, bm_obj_lobby_curtain_model_names, bm_obj_lobby_curtain_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_obj_lobby_curtain_motion_names[1] = { NULL };
}
