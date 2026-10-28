#include "types.h"
#include "pso/misc/TOKey_8015845C.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjStendGlassLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80479658[];
extern char lbl_80479670[];
extern const char *bm_obj_lobby_stendglass_motion_names[];
extern const char *bm_obj_lobby_stendglass_model_names[2];
extern BmlResourceDescriptor TObjStendGlassLobby__resource_descriptor;

struct RecoveredGlobal_80359944_lbl_804F1A30 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80359944_lbl_804F1A30_size[sizeof(RecoveredGlobal_80359944_lbl_804F1A30) == 0x10 ? 1 : -1];

struct RecoveredGlobal_803599F4___vt__19TObjStendGlassLobby {
    s32 value;
    u8 remaining[0x34];
};

struct Obj_80359758 { u8 pad[0xC8]; s32 state; f32 val; s32 flag; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjStendGlassLobby__static_model_resource;
extern s32 stend_glass_lobby_type;
extern s32 __vt__19TObjStendGlassLobby[];
extern s32 TObjStendGlassLobby__name;
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjStendGlassLobby__sub_803596C0(void) {  }

void TObjStendGlassLobby::render() {
    f32 temp_f1;

    if (((s32) this->m_c8 != 0) && ((u32) this->texlist != 0U)) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_c8 != 3) {
            temp_f1 = *(f32 *)&this->_padCC;
            scale_matrix(0, temp_f1, (f32) (1.0f), temp_f1);
        }
        draw_ginja_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjStendGlassLobby::run_task() {
    Obj_80359758 *self = (Obj_80359758 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjStendGlassLobby__sub_803596C0)(self);
    }
    switch (*(s32 *)&this->m_c8) {
    case 0:
        if (*(s32 *)&this->m_d0 == TLobby::get_filtered_event_theme()) {
            *(s32 *)&this->m_c8 = 2;
        }
        break;
    case 2:
        {
        f32 lim = 1.0f;
        self->val += 0.1f;
        if (self->val >= lim) {
            self->val = lim;
            *(s32 *)&this->m_c8 = 3;
        }
        }
        break;
    case 1:
        {
        f32 lim = 0.0f;
        self->val -= 0.1f;
        if (self->val <= lim) {
            self->val = lim;
            *(s32 *)&this->m_c8 = 0;
        }
        }
        break;
    case 3:
    default:
        if (*(s32 *)&this->m_d0 != TLobby::get_filtered_event_theme()) {
            *(s32 *)&this->m_c8 = 1;
        }
        break;
    }
}

void TObjStendGlassLobby::update_state() {
    if ((s32) this->set_params[0] < 1) {
        this->m_d0 = 0;
    } else {
        this->m_d0 = 1;
    }
    if ((s32) this->m_d0 == TLobby::get_filtered_event_theme()) {
        this->m_c8 = 3;
        return;
    }
    this->m_c8 = 0;
}

extern void *tl_05;

void *TObjStendGlassLobby::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        o = TObjStendGlassLobby__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjStendGlassLobby::free_static_model() {
    if ((u32) TObjStendGlassLobby__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjStendGlassLobby__static_model_resource, 1);
        TObjStendGlassLobby__static_model_resource = 0U;
    }
}

void TObjStendGlassLobby::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &TObjStendGlassLobby__resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjStendGlassLobby__static_model_resource) = var_r0;
    stend_glass_lobby_type = TLobby::get_lobby_type();
}

void *__dt__19TObjStendGlassLobbyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TObjStendGlassLobby;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_803599F4___vt__19TObjStendGlassLobby_size[sizeof(RecoveredGlobal_803599F4___vt__19TObjStendGlassLobby) == 0x38 ? 1 : -1];
u8 *TObjStendGlassLobby__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_map_object_base((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_803599F4___vt__19TObjStendGlassLobby *)&__vt__19TObjStendGlassLobby).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjStendGlassLobby__name;
    ((TObjStendGlassLobby *)(arg0))->apply_object_set_data((void *)arg2);
    ((TObjStendGlassLobby *)arg0)->update_state();
    *(f32 *)((s8 *)arg0 + 0xCC) = 1.0f;
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjStendGlassLobby__static_model_resource) + 0x42C)) + 8);
    ((TObjStendGlassLobby *)arg0)->texlist = (s32) stend_glass_lobby_type;
    return arg0;
}

__declspec(section ".data") const char *bm_obj_lobby_stendglass_model_names[2] = { lbl_80479658, NULL };
BmlResourceDescriptor TObjStendGlassLobby__resource_descriptor = { lbl_80479670, bm_obj_lobby_stendglass_model_names, bm_obj_lobby_stendglass_motion_names, 1, 0 };
}
