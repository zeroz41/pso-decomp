#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/object/TObjRainbowLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_obj_lobby_rainbow_motion_names[1];
extern const char *bm_obj_lobby_rainbow_model_names[2];
const char *bm_obj_lobby_rainbow_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_obj_lobby_rainbow_model_names[2] = { "lobby_obj_niji.gj", NULL };
BmlResourceDescriptor bm_obj_lobby_rainbow_resource_descriptor = { "bm_obj_lobby_rainbow.bml", bm_obj_lobby_rainbow_model_names, bm_obj_lobby_rainbow_motion_names, 1, 0 };
const char *lbl_805D435C = "TObjRainbowLobby";
u32 TObjRainbowLobby__shared_model_resource;
}


struct RecoveredGlobal_80350808_lbl_804F0DF0 { s32 value; u8 remaining[0xC]; };
struct Obj_803506A4 { u8 pad[0xC8]; s32 state; f32 val; };

extern "C" {

s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void *__nw__7TObjectFUl(int);
void TLobby__sub_8001FE7C(void*, int);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern BmlResourceDescriptor bm_obj_lobby_rainbow_resource_descriptor;
extern u32 TObjRainbowLobby__shared_model_resource;
void __dl__7TObjectFPv(void *);
s32 __ct__13TUnk_804AFBF8FP7TObject();
s32 is_lobby_event_active();
extern s32 __vt__16TObjRainbowLobby[];
extern const char *lbl_805D435C;

void TObjRainbowLobby::render() {
    f32 temp_f1;

    if ((s32) this->m_c8 != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_c8 != 3) {
            temp_f1 = *(f32 *)&this->unk_CC;
            scale_matrix(0, temp_f1, (f32) (1.0f), temp_f1);
        }
        draw_ginja_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

extern void *tl_05;

void TObjRainbowLobby::run_task() {
    Obj_803506A4 *arg0 = (Obj_803506A4 *)this;
    switch (arg0->state) {
    case 0:
        if (TLobby::is_connected() != 0) {
            arg0->state = 2;
        }
        break;
    case 2:
        arg0->val += 0.1f;
        if (arg0->val >= 1.0f) {
            arg0->val = 1.0f;
            arg0->state = 3;
        }
        break;
    case 1:
        arg0->val -= 0.1f;
        if (arg0->val <= 0.0f) {
            arg0->val = 0.0f;
            arg0->state = 0;
        }
        break;
    case 3:
    default:
        if (TLobby::is_lobby_obj_active() != 0) {
            arg0->state = 1;
        }
        break;
    }
}

void *TObjRainbowLobby::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = ((void *(*)(void *, void *, void *))TObjRainbowLobby__ct)(o, tl_05, arg0);
    }
    return o;
}

void TObjRainbowLobby::free_static_data() {
    if ((u32) TObjRainbowLobby__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjRainbowLobby__shared_model_resource, 1);
        TObjRainbowLobby__shared_model_resource = 0U;
    }
}
void TObjRainbowLobby::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_obj_lobby_rainbow_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjRainbowLobby__shared_model_resource) = var_r0;
}
void *__dt__16TObjRainbowLobbyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjRainbowLobby;
        __dt__13TUnk_804AFBF8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
void *TObjRainbowLobby__ct(TObjRainbowLobby *rainbow_lobby, s32 arg1, s32 arg2) {
    __ct__13TUnk_804AFBF8FP7TObject();
    *(s32 **)((s8 *)rainbow_lobby + 0x18) = __vt__16TObjRainbowLobby;
    *(s32 *)((s8 *)rainbow_lobby + 0) = (s32) ((s32)lbl_805D435C);
    rainbow_lobby->apply_object_set_data((void *)arg2);
    if (is_lobby_event_active() != 0) {
        rainbow_lobby->m_c8 = 0;
    } else {
        rainbow_lobby->m_c8 = 3;
    }
    *(f32 *)((s8 *)rainbow_lobby + 0xCC) = 1.0f;
    *(s32 *)((s8 *)rainbow_lobby + 0x34) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)((void *)TObjRainbowLobby__shared_model_resource) + 0x42C)) + 8);
    rainbow_lobby->texlist = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)((void *)TObjRainbowLobby__shared_model_resource) + 0x42C)) + 0xC);
    return rainbow_lobby;
}

}
