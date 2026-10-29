#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMapObject.h"
#include "pso/object/TObjSuisouLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80369DF0_lbl_804F33E0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80369DF0_lbl_804F33E0_size[sizeof(RecoveredGlobal_80369DF0_lbl_804F33E0) == 0x10 ? 1 : -1];


struct Vec_80369ED4 { s32 x, y, z; };


extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjSuisouLobby__instance;
extern s32 TObjSuisouLobby__lobby_type;
u32 create_particle_emitter(void *, int);
s32 is_lobby_event_active(void);
s32 matrix_mult_vec(int, void *, void *);
s32 set_matrix_identity(int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
void TLobby__sub_8001FE7C(void*, int);
s32 scale_matrix(int, f32, f32, f32);

#pragma readonly_strings on
__declspec(section ".data") void *bm_obj_lobby_suisou_model_names[2] = { (void *)"lobby_suisou_s_waku.gj", 0 };
#pragma explicit_zero_data on
void *bm_obj_lobby_suisou_motion_names = (void *)0;
#pragma explicit_zero_data reset
void *lobby_suisou_resource_descriptor[4] = { (void *)"bm_obj_lobby_suisou.bml", (void *)bm_obj_lobby_suisou_model_names, (void *)&bm_obj_lobby_suisou_motion_names, (void *)0x10000 };
char *lbl_805D44C4 = "TObjSuisouLobby";
const f32 lbl_8047A3D0[1][3] = { { 0.0f, 0.0f, 60.0f } };
const f32 lbl_8047A3DC[1][3] = { { 0.0f, 0.0f, -60.0f } };
#define lobby_suisou_resource_descriptor (*(RecoveredGlobal_80369DF0_lbl_804F33E0 *)lobby_suisou_resource_descriptor)
#define lbl_8047A3D0 ((const Vec_80369ED4 *)lbl_8047A3D0)
#define lbl_8047A3DC ((const Vec_80369ED4 *)lbl_8047A3DC)
void TObjSuisouLobby__sub_80369B5C(void) {  }

void TObjSuisouLobby::render() {
    f32 temp_f1;

    if (((s32) this->fade_state != 0) && ((u32) this->texlist != 0U)) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->fade_state != 3) {
            temp_f1 = this->fade_scale;
            scale_matrix(0, temp_f1, 1.0f, temp_f1);
        }
        draw_ginja_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjSuisouLobby::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjSuisouLobby__sub_80369B5C)(this);
    }
    switch (this->fade_state) {
    case 0:
        if (TLobby::is_connected() != 0) {
            this->fade_state = 2;
        }
        break;
    case 2:
        this->fade_scale += 0.1f;
        if (this->fade_scale >= 1.0f) {
            this->fade_scale = 1.0f;
            this->fade_state = 3;
        }
        break;
    case 1:
        this->fade_scale -= 0.1f;
        if (this->fade_scale <= 0.0f) {
            this->fade_scale = 0.0f;
            this->fade_state = 0;
        }
        break;
    case 3:
    default:
        if (TLobby::is_lobby_obj_active() != 0) {
            this->fade_state = 1;
        }
        break;
    }
    this->update_particle();
}

void TObjSuisouLobby::update_particle() {
    if ((s32) this->fade_state == 3) {
        if (this->emitter0 != NULL) {
            this->emitter0->clear_active_flag();
        }
        if (this->emitter1 != NULL) {
            this->emitter1->clear_active_flag();
        }
    } else {
        if (this->emitter0 != NULL) {
            this->emitter0->enable();
        }
        if (this->emitter1 != NULL) {
            this->emitter1->enable();
        }
    }
}
void TObjSuisouLobby__sub_80369D68(void) {  }

extern void *tl_05;

void *TObjSuisouLobby::create() {
    return new TObjSuisouLobby((TObject *)tl_05, this);
}

void TObjSuisouLobby::destroy_instance() {
    if ((u32) TObjSuisouLobby__instance != 0U) {
        TLobby__sub_8001FE7C((void*)TObjSuisouLobby__instance, 1);
        TObjSuisouLobby__instance = 0U;
    }
}

void TObjSuisouLobby::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &lobby_suisou_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjSuisouLobby__instance) = var_r0;
    TObjSuisouLobby__lobby_type = TLobby::get_lobby_type();
}

TObjSuisouLobby::~TObjSuisouLobby() {
    if (emitter0 != NULL) {
        queue_destruction__7TObjectFv(emitter0);
        emitter0 = 0;
    }
    if (emitter1 != NULL) {
        queue_destruction__7TObjectFv(emitter1);
        emitter1 = 0;
    }
}

#pragma push
#pragma opt_common_subs off
TObjSuisouLobby::TObjSuisouLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = lbl_805D44C4;
    apply_object_set_data(set_data);
    {
        Vec_80369ED4 v = lbl_8047A3D0[0];
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        matrix_mult_vec(0, &v, &v);
        emitter0 = (TParticleCtrl *)create_particle_emitter(&v, 0x222);
        pop_matrix();
        if (emitter0 != NULL) {
            emitter0->enable();
        }
    }
    {
        Vec_80369ED4 v = lbl_8047A3DC[0];
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        matrix_mult_vec(0, &v, &v);
        emitter1 = (TParticleCtrl *)create_particle_emitter(&v, 0x222);
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
    ((void (*)(void *))TObjSuisouLobby__sub_80369D68)(this);
    fade_scale = 1.0f;
    model = (void *)*(s32 *)(*(u8 **)((u8 *)TObjSuisouLobby__instance + 0x42C) + 8);
    texlist = TObjSuisouLobby__lobby_type;
}
#pragma pop

}
