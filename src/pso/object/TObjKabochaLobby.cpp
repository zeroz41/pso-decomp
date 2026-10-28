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

struct VBase18_8035346c { char pad[0x18]; };
struct VObj18_8035346c : VBase18_8035346c {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8(f32, f32);
};

struct Kabocha_80353520 {
    u8 pad0[0xC8];
    s32 state;
    f32 scale;
};

extern "C" {

s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void *__nw__7TObjectFUl(int);
void TLobby__sub_8001FE7C(void*, int);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjKabochaLobby__model_resource;
void __dl__7TObjectFPv(void *);
s32 init_map_object_base();
extern s32 __vt__16TObjKabochaLobby[];
extern s32 lbl_805D4384;

extern s32 TObjKabochaLobby__lobby_type;

void TObjKabochaLobby::render() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;

    if (((s32) *(s32 *)&this->m_c8 != 0) && ((u32) TObjKabochaLobby__lobby_type != 0U) && (((VObj18_8035346c *) arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0)) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) *(s32 *)&this->m_c8 != 3) {
            temp_f1 = *(f32 *)&this->unk_CC;
            scale_matrix(0, temp_f1, (f32) (1.0f), temp_f1);
        }
        draw_ginja_object((void *)(*(s32 *)&this->model));
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

extern void *tl_05;

void TObjKabochaLobby::run_task() {
    Kabocha_80353520 *o = (Kabocha_80353520 *)this;
    switch (o->state) {
    case 0:
        if (TLobby::get_filtered_event_theme() == 5) {
            o->state = 2;
        }
        break;
    case 2:
        {
        o->scale += 0.1f;
        if (o->scale >= 1.0f) {
            o->scale = 1.0f;
            o->state = 3;
        }
        }
        break;
    case 1:
        {
        o->scale -= 0.1f;
        if (o->scale <= 0.0f) {
            o->scale = 0.0f;
            o->state = 0;
        }
        }
        break;
    case 3:
    default:
        if (TLobby::get_filtered_event_theme() != 5) {
            o->state = 1;
        }
        break;
    }
}

void *TObjKabochaLobby::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = ((void *(*)(void *, void *, void *))TObjKabochaLobby__ct)(o, tl_05, arg0);
    }
    return o;
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
void *__dt__16TObjKabochaLobbyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjKabochaLobby;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
void *TObjKabochaLobby__ct(TObjKabochaLobby *kabocha_lobby, s32 arg1, s32 arg2) {
    init_map_object_base();
    *(s32 **)((s8 *)kabocha_lobby + 0x18) = __vt__16TObjKabochaLobby;
    *(s32 *)((s8 *)kabocha_lobby + 0) = (s32) lbl_805D4384;
    kabocha_lobby->apply_object_set_data((void *)arg2);
    if (TLobby::get_filtered_event_theme() == 5) {
        kabocha_lobby->m_c8 = 3;
    } else {
        kabocha_lobby->m_c8 = 0;
    }
    *(f32 *)((s8 *)kabocha_lobby + 0xCC) = 1.0f;
    *(s32 *)((s8 *)kabocha_lobby + 0x34) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)((void *)TObjKabochaLobby__model_resource) + 0x42C)) + 8);
    kabocha_lobby->texlist = (s32) TObjKabochaLobby__lobby_type;
    return kabocha_lobby;
}

__declspec(section ".data") const char *bm_obj_lobby_kabocha_model_names[2] = { lbl_80479170, NULL };
BmlResourceDescriptor lobby_pumpkin_resource_descriptor = { lbl_80479184, bm_obj_lobby_kabocha_model_names, bm_obj_lobby_kabocha_motion_names, 1, 0 };
}
