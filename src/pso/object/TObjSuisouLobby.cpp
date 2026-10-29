#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/object/TObjSuisouLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80369DF0_lbl_804F33E0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80369DF0_lbl_804F33E0_size[sizeof(RecoveredGlobal_80369DF0_lbl_804F33E0) == 0x10 ? 1 : -1];

struct Suisou_80369BF4 {
    u8 pad[0xC8];
    s32 state;
    f32 cc;
};

struct Vec_80369ED4 { s32 x, y, z; };

struct Self_80369ED4 {
    u8 pad0[0x24]; s32 x24; u8 pad28[0xC]; s32 x34; u8 x38[0x28]; s32 x60;
    u8 pad64[0x64]; s32 state; f32 cc; s32 padd0; void *p1; void *p2;
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjSuisouLobby__instance;
extern s32 TObjSuisouLobby__lobby_type;
void run_task__15TObjSuisouLobbyFv(Suisou_80369BF4 *self);
u32 create_particle_emitter(void *, int);
s32 __ct__13TUnk_804AFBF8FP7TObject(void *, void *);
s32 is_lobby_event_active(void);
s32 matrix_mult_vec(int, void *, void *);
s32 set_matrix_identity(int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
void TLobby__sub_8001FE7C(void*, int);
s32 scale_matrix(int, f32, f32, f32);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void render_shadows__7TObjectFv(); void vfunc_6__8TObjBaseFPsl(); void apply_object_set_data__8TObjBaseFPv(); void reset_motion_fields__14TObjCollidableFv();
void get_center__8TObjBaseFv(); void update_object_view_visibility__8TObjBaseFff(); void classify_actor_view_detail__8TObjBaseFfff();
void get_name__8TObjBaseFv(); void interact__14TObjCollidableFl();
#pragma readonly_strings on
__declspec(section ".data") void *bm_obj_lobby_suisou_model_names[2] = { (void *)"lobby_suisou_s_waku.gj", 0 };
#pragma explicit_zero_data on
void *bm_obj_lobby_suisou_motion_names = (void *)0;
#pragma explicit_zero_data reset
void *lobby_suisou_resource_descriptor[4] = { (void *)"bm_obj_lobby_suisou.bml", (void *)bm_obj_lobby_suisou_model_names, (void *)&bm_obj_lobby_suisou_motion_names, (void *)0x10000 };
char *lbl_805D44C4 = "TObjSuisouLobby";
void *__vt__15TObjSuisouLobby[14] = {
    0, 0, (void *)__dt__15TObjSuisouLobbyFv, (void *)run_task__15TObjSuisouLobbyFv, (void *)render__15TObjSuisouLobbyFv,
    (void *)render_shadows__7TObjectFv, (void *)vfunc_6__8TObjBaseFPsl, (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__14TObjCollidableFv, (void *)get_center__8TObjBaseFv, (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff, (void *)get_name__8TObjBaseFv, (void *)interact__14TObjCollidableFl,
};
const f32 lbl_8047A3D0[1][3] = { { 0.0f, 0.0f, 60.0f } };
const f32 lbl_8047A3DC[1][3] = { { 0.0f, 0.0f, -60.0f } };
#define lobby_suisou_resource_descriptor (*(RecoveredGlobal_80369DF0_lbl_804F33E0 *)lobby_suisou_resource_descriptor)
#define lbl_8047A3D0 ((const Vec_80369ED4 *)lbl_8047A3D0)
#define lbl_8047A3DC ((const Vec_80369ED4 *)lbl_8047A3DC)
void TObjSuisouLobby__sub_80369B5C(void) {  }

void render__15TObjSuisouLobbyFv(TObjSuisouLobby *arg0) {
    f32 temp_f1;

    if (((s32) arg0->m_c8 != 0) && ((u32) arg0->texlist != 0U)) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(arg0->texlist);
        push_matrix();
        post_translate_matrix((u8 *)arg0 + 0x38);
        rotate_matrix_y(0, arg0->rotation_y);
        if ((s32) arg0->m_c8 != 3) {
            temp_f1 = *(f32 *)((s8 *)arg0 + 0xCC);
            scale_matrix(0, temp_f1, 1.0f, temp_f1);
        }
        draw_ginja_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void run_task__15TObjSuisouLobbyFv(Suisou_80369BF4 *self) {
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjSuisouLobby__sub_80369B5C)(self);
    }
    switch (self->state) {
    case 0:
        if (TLobby::is_connected() != 0) {
            self->state = 2;
        }
        break;
    case 2:
        self->cc += 0.1f;
        if (self->cc >= 1.0f) {
            self->cc = 1.0f;
            self->state = 3;
        }
        break;
    case 1:
        self->cc -= 0.1f;
        if (self->cc <= 0.0f) {
            self->cc = 0.0f;
            self->state = 0;
        }
        break;
    case 3:
    default:
        if (TLobby::is_lobby_obj_active() != 0) {
            self->state = 1;
        }
        break;
    }
    ((TObjSuisouLobby *)self)->update_particle();
}

void TObjSuisouLobby::update_particle() {
    if ((s32) this->m_c8 == 3) {
        if ((u32) this->m_d4 != 0U) {
            ((TParticleCtrl *)(this->m_d4))->clear_active_flag();
        }
        if ((u32) this->m_d8 != 0U) {
            ((TParticleCtrl *)(this->m_d8))->clear_active_flag();
        }
    } else {
        if ((u32) this->m_d4 != 0U) {
            ((TParticleCtrl *)(this->m_d4))->enable();
        }
        if ((u32) this->m_d8 != 0U) {
            ((TParticleCtrl *)(this->m_d8))->enable();
        }
    }
}
void TObjSuisouLobby__sub_80369D68(void) {  }

extern void *tl_05;

void *TObjSuisouLobby::create() {
    void *o = __nw__7TObjectFUl(0xDC);
    if (o != NULL) {
        o = TObjSuisouLobby__ct(o, tl_05, this);
    }
    return o;
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

void *__dt__15TObjSuisouLobbyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__15TObjSuisouLobby;
        if (*(void **)((s8 *)arg0 + 0xD4) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xD4)); ((TObjSuisouLobby *)arg0)->m_d4 = 0; }
        if (*(void **)((s8 *)arg0 + 0xD8) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xD8)); ((TObjSuisouLobby *)arg0)->m_d8 = 0; }
        __dt__13TUnk_804AFBF8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma opt_common_subs off
#define self ((Self_80369ED4 *)arg0)
void *TObjSuisouLobby__ct(void *arg0, void *arg1, void *arg2) {
    __ct__13TUnk_804AFBF8FP7TObject(arg0, arg1);
    *(void ***)((u8 *)arg0 + 0x18) = ((void * *)__vt__15TObjSuisouLobby);
    *(s32 *)arg0 = (s32)lbl_805D44C4;
    ((TObjSuisouLobby *)arg0)->apply_object_set_data(arg2);
    {
        Vec_80369ED4 v = lbl_8047A3D0[0];
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(self->x38);
        rotate_matrix_y(0, self->x60);
        matrix_mult_vec(0, &v, &v);
        self->p1 = (void *)create_particle_emitter(&v, 0x222);
        pop_matrix();
        if (self->p1 != NULL) {
            ((TParticleCtrl *)(self->p1))->enable();
        }
    }
    {
        Vec_80369ED4 v = lbl_8047A3DC[0];
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(self->x38);
        rotate_matrix_y(0, self->x60);
        matrix_mult_vec(0, &v, &v);
        self->p2 = (void *)create_particle_emitter(&v, 0x222);
        pop_matrix();
        if (self->p2 != NULL) {
            ((TParticleCtrl *)(self->p2))->enable();
        }
    }
    if (is_lobby_event_active() != 0) {
        self->state = 0;
    } else {
        self->state = 3;
    }
    ((void (*)(void *))TObjSuisouLobby__sub_80369D68)(arg0);
    self->cc = 1.0f;
    self->x34 = *(s32 *)(*(u8 **)((u8 *)TObjSuisouLobby__instance + 0x42C) + 8);
    self->x24 = TObjSuisouLobby__lobby_type;
    return arg0;
}
#pragma pop

}
