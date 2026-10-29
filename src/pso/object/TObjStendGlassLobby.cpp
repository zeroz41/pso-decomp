#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMapObject.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjStendGlassLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

extern const char *bm_obj_lobby_stendglass_motion_names[1];
extern const char *bm_obj_lobby_stendglass_model_names[2];
extern BmlResourceDescriptor TObjStendGlassLobby__resource_descriptor;

struct RecoveredGlobal_80359944_lbl_804F1A30 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80359944_lbl_804F1A30_size[sizeof(RecoveredGlobal_80359944_lbl_804F1A30) == 0x10 ? 1 : -1];


extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjStendGlassLobby__static_model_resource;
extern s32 stend_glass_lobby_type;
extern const char *TObjStendGlassLobby__name;
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();

void TObjStendGlassLobby__sub_803596C0(void) {  }

void TObjStendGlassLobby::render() {
    f32 temp_f1;

    if (((s32) this->fade_state != 0) && ((u32) this->texlist != 0U)) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->fade_state != 3) {
            temp_f1 = this->fade_scale;
            scale_matrix(0, temp_f1, (f32) (1.0f), temp_f1);
        }
        draw_ginja_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjStendGlassLobby::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjStendGlassLobby__sub_803596C0)(this);
    }
    switch (*(s32 *)&this->fade_state) {
    case 0:
        if (*(s32 *)&this->event_theme == TLobby::get_filtered_event_theme()) {
            *(s32 *)&this->fade_state = 2;
        }
        break;
    case 2:
        {
        f32 lim = 1.0f;
        this->fade_scale += 0.1f;
        if (this->fade_scale >= lim) {
            this->fade_scale = lim;
            *(s32 *)&this->fade_state = 3;
        }
        }
        break;
    case 1:
        {
        f32 lim = 0.0f;
        this->fade_scale -= 0.1f;
        if (this->fade_scale <= lim) {
            this->fade_scale = lim;
            *(s32 *)&this->fade_state = 0;
        }
        }
        break;
    case 3:
    default:
        if (*(s32 *)&this->event_theme != TLobby::get_filtered_event_theme()) {
            *(s32 *)&this->fade_state = 1;
        }
        break;
    }
}

void TObjStendGlassLobby::update_state() {
    if ((s32) this->set_params[0] < 1) {
        this->event_theme = 0;
    } else {
        this->event_theme = 1;
    }
    if ((s32) this->event_theme == TLobby::get_filtered_event_theme()) {
        this->fade_state = 3;
        return;
    }
    this->fade_state = 0;
}

extern void *tl_05;

void *TObjStendGlassLobby::create(void *arg0) {
    return new TObjStendGlassLobby((TObject *)tl_05, arg0);
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

TObjStendGlassLobby::~TObjStendGlassLobby() {}

TObjStendGlassLobby::TObjStendGlassLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TObjStendGlassLobby__name;
    apply_object_set_data(set_data);
    update_state();
    fade_scale = 1.0f;
    model = (void *)*(s32 *)(*(u8 **)((u8 *)TObjStendGlassLobby__static_model_resource + 0x42C) + 8);
    texlist = stend_glass_lobby_type;
}

__declspec(section ".data") const char *bm_obj_lobby_stendglass_model_names[2] = { "lobby_win_s_waku1.gj", NULL };
BmlResourceDescriptor TObjStendGlassLobby__resource_descriptor = { "bm_obj_lobby_stendglass.bml", bm_obj_lobby_stendglass_model_names, bm_obj_lobby_stendglass_motion_names, 1, 0 };

const char *bm_obj_lobby_stendglass_motion_names[1] = { NULL };
const char *TObjStendGlassLobby__name = "TObjStendGlassLobby";
u32 TObjStendGlassLobby__static_model_resource;
s32 stend_glass_lobby_type;
}
