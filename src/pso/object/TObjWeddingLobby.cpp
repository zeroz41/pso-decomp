#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjWeddingLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80479940[];
extern char lbl_8047995C[];
extern char lbl_80479978[];
extern char lbl_80479994[];
extern const char *bm_obj_lobby_bell_model_names[3];
extern const char *bm_obj_lobby_bell_motion_names[2];
extern BmlResourceDescriptor wedding_lobby_resource_descriptor;

struct RecoveredGlobal_8035BEB8_lbl_804F1DF4 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8035BEB8_lbl_804F1DF4_size[sizeof(RecoveredGlobal_8035BEB8_lbl_804F1DF4) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8035BF68___vt__16TObjWeddingLobby {
    s32 value;
    u8 remaining[0x38];
};

struct Obj_8035BCE8 {
    u8 pad0[0xB0];
    f32 b0;
    u8 padB4[0xC8 - 0xB4];
    s32 state;
    f32 cc;
};

struct Fish_8035BCE8 { u32 a; u32 n; };

extern "C" {
s32 get_bml_motion(void *, int);
s32 get_bml_model(void *, int);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 draw_ginja_model_with_motion(int, int, f32);
extern u32 TObjWeddingLobby__resource_bundle;
extern u32 wedding_lobby_type;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 init_map_object_base(void *, void *);
extern s32 __vt__16TObjWeddingLobby[];
extern s32 TObjWeddingLobby__class_name;
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjWeddingLobby__sub_8035BC20(void) {  }

extern void *tl_05;

void TObjWeddingLobby::render() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    s32 temp_r31;
    s32 temp_r3;
    if (((s32) this->m_c8 != 0) && ((u32) wedding_lobby_type != 0U)) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(wedding_lobby_type);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_c8 != 3) {
            temp_f1 = *(f32 *)((s8 *)arg0 + 0xCC);
            scale_matrix(0, temp_f1, (f32) (1.0f), temp_f1);
        }
        get_bml_model((void *) ((*(s32 *)&TObjWeddingLobby__resource_bundle)), 0);
        draw_ginja_object();
        draw_ginja_model_with_motion((int) get_bml_model((void *) ((*(s32 *)&TObjWeddingLobby__resource_bundle)), 1), (int) get_bml_motion((void *) ((*(s32 *)&TObjWeddingLobby__resource_bundle)), 0), this->m_b0);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjWeddingLobby::run_task() {
    Obj_8035BCE8 *self = (Obj_8035BCE8 *)this;
    f32 last;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(Obj_8035BCE8 *))TObjWeddingLobby__sub_8035BC20)(self);
    }
    switch (this->m_c8) {
    case 0:
        if (TLobby::get_filtered_event_theme() == 0xA) {
            this->m_c8 = 2;
        }
        break;
    case 2: {
        self->cc += 0.1f;
        if (self->cc >= 1.0f) {
            self->cc = 1.0f;
            this->m_c8 = 3;
        }
        break;
    }
    case 1: {
        self->cc -= 0.1f;
        if (self->cc <= 0.0f) {
            self->cc = 0.0f;
            this->m_c8 = 0;
        }
        break;
    }
    case 3:
    default:
        if (TLobby::get_filtered_event_theme() != 0xA) {
            this->m_c8 = 1;
        }
        break;
    }
    last = (f32)((Fish_8035BCE8 *)get_bml_motion((void *)TObjWeddingLobby__resource_bundle, 0))->n - 1.0f;
    this->m_b0 += 2.0f;
    if (last < this->m_b0) {
        this->m_b0 -= last;
    }
}

void *TObjWeddingLobby::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        o = TObjWeddingLobby__ct((TObjWeddingLobby *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjWeddingLobby::release() {
    if ((u32) TObjWeddingLobby__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjWeddingLobby__resource_bundle, 1);
        TObjWeddingLobby__resource_bundle = 0U;
    }
}

void TObjWeddingLobby::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &wedding_lobby_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjWeddingLobby__resource_bundle) = var_r0;
    (*(s32 *)&wedding_lobby_type) = TLobby::get_lobby_type();
}

void *__dt__16TObjWeddingLobbyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjWeddingLobby;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8035BF68___vt__16TObjWeddingLobby_size[sizeof(RecoveredGlobal_8035BF68___vt__16TObjWeddingLobby) == 0x3C ? 1 : -1];
u8 *TObjWeddingLobby__ct(TObjWeddingLobby *wedding_lobby, s32 arg1, s32 arg2) {
    init_map_object_base((void *)wedding_lobby, (void *)arg1);
    *(s32 **)((s8 *)wedding_lobby + 0x18) = &(*(RecoveredGlobal_8035BF68___vt__16TObjWeddingLobby *)&__vt__16TObjWeddingLobby).value;
    *(s32 *)((s8 *)wedding_lobby + 0) = (s32) TObjWeddingLobby__class_name;
    ((TObjWeddingLobby *)(wedding_lobby))->apply_object_set_data((void *)arg2);
    if (TLobby::get_filtered_event_theme() == 0xA) {
        wedding_lobby->m_c8 = 3;
    } else {
        wedding_lobby->m_c8 = 0;
    }
    *(f32 *)((s8 *)wedding_lobby + 0xCC) = 1.0f;
    wedding_lobby->m_b0 = 0.0f;
    return (u8 *)wedding_lobby;
}

__declspec(section ".data") const char *bm_obj_lobby_bell_model_names[3] = { lbl_80479940, lbl_8047995C, NULL };
__declspec(section ".data") const char *bm_obj_lobby_bell_motion_names[2] = { lbl_80479978, NULL };
BmlResourceDescriptor wedding_lobby_resource_descriptor = { lbl_80479994, bm_obj_lobby_bell_model_names, bm_obj_lobby_bell_motion_names, 2, 1 };
}
