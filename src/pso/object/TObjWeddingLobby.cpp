#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMapObject.h"
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
extern const char *TObjWeddingLobby__class_name;
void TLobby__sub_8001FE7C(void*, int);

void TObjWeddingLobby__sub_8035BC20(void) {  }

extern void *tl_05;

void TObjWeddingLobby::render() {
    f32 temp_f1;
    s32 temp_r31;
    s32 temp_r3;
    if (((s32) this->fade_state != 0) && ((u32) wedding_lobby_type != 0U)) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(wedding_lobby_type);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->fade_state != 3) {
            temp_f1 = this->fade_scale;
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
    f32 last;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjWeddingLobby__sub_8035BC20)(this);
    }
    switch (this->fade_state) {
    case 0:
        if (TLobby::get_filtered_event_theme() == 0xA) {
            this->fade_state = 2;
        }
        break;
    case 2: {
        this->fade_scale += 0.1f;
        if (this->fade_scale >= 1.0f) {
            this->fade_scale = 1.0f;
            this->fade_state = 3;
        }
        break;
    }
    case 1: {
        this->fade_scale -= 0.1f;
        if (this->fade_scale <= 0.0f) {
            this->fade_scale = 0.0f;
            this->fade_state = 0;
        }
        break;
    }
    case 3:
    default:
        if (TLobby::get_filtered_event_theme() != 0xA) {
            this->fade_state = 1;
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
    return new TObjWeddingLobby((TObject *)tl_05, arg0);
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

TObjWeddingLobby::~TObjWeddingLobby() {}

TObjWeddingLobby::TObjWeddingLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TObjWeddingLobby__class_name;
    apply_object_set_data(set_data);
    if (TLobby::get_filtered_event_theme() == 0xA) {
        fade_state = 3;
    } else {
        fade_state = 0;
    }
    fade_scale = 1.0f;
    m_b0 = 0.0f;
}

__declspec(section ".data") const char *bm_obj_lobby_bell_model_names[3] = { lbl_80479940, lbl_8047995C, NULL };
__declspec(section ".data") const char *bm_obj_lobby_bell_motion_names[2] = { lbl_80479978, NULL };
BmlResourceDescriptor wedding_lobby_resource_descriptor = { lbl_80479994, bm_obj_lobby_bell_model_names, bm_obj_lobby_bell_motion_names, 2, 1 };
}
