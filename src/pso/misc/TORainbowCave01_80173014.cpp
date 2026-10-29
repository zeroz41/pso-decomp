#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/misc/TORainbowCave01_80173014.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TORainbowCave01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80173330_lbl_804B3A18 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80173330_lbl_804B3A18_size[sizeof(RecoveredGlobal_80173330_lbl_804B3A18) == 0x10 ? 1 : -1];

struct Color_8017310C { f32 a, b, c, d; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80173330_lbl_804B3A18 abeniji_fe_obj001_niji_resource_descriptor;
extern u32 TORainbowCave01__static_model_resource;
extern const char *TORainbowCave01__name;
void rotate_matrix_y(s32, s32);
void push_matrix(void);
void scale_current_matrix(void *);
void post_translate_matrix(void *);
extern Color_8017310C chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void TLobby__sub_8001FE7C(void*, int);
f32 horizontal_distance_squared(const Vec *a, const Vec *b);
TObjCollidable *find_entity_by_id(u16 id);

extern s32 local_client_id;

s32 TORainbowCave01::is_player_in_range(f32 farg0) {
    TObjCollidable *player = find_entity_by_id((u16) local_client_id);
    if ((player != NULL) && (horizontal_distance_squared(&position, &player->position) < farg0)) {
        return 1;
    }
    return 0;
}

extern void *tl_05;

#pragma push
#pragma fp_contract on
void TORainbowCave01::init_light_params() {
    f32 k = 0.0009765625f;
    m_c8 = 1.0f / ((f32) this->set_params[0] * k + 29.999998f);
    this->m_d0 = 4e+04f + (f32) *(s32 *)&this->set_params[2];
    VecCopy(&m_d4, &scale);
}
#pragma pop

void TORainbowCave01::render() {
    Color_8017310C c;
    s32 old;
    if (update_object_view_visibility(m_c0, model_radius) != 0 && -1.0f < m_cc) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(texlist);
        old = model_render_flags;
        saved_model_render_flags = old;
        model_render_flags = old | 0x20;
        c.d = c.c = c.b = 0.0f;
        if (TObjPlayer::check_demo_mode() == 1) {
            c.a = 0.0f;
        } else {
            c.a = m_cc;
        }
        set_constant_material((const NJS_ARGB *)(((f32 *)&c)));
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        scale_current_matrix(&m_d4);
        draw_ginja_object(model);
        pop_matrix();
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
    }
}

void TORainbowCave01::run_task() {
    s32 in = (is_player_in_range(m_d0) == 1) ? 1 : 0;
    switch (in + 1) {
    case 1:
        m_cc += m_c8;
        if (0.0f <= m_cc) {
            m_cc = 0.0f;
        }
        break;
    case 2:
        m_cc -= m_c8;
        if (m_cc <= -1.0f) {
            m_cc = -1.0f;
        }
        break;
    }
    TObjMapObject::run_task();
}

void *TORainbowCave01::create(void *arg0) {
    return new TORainbowCave01((TObject *)tl_05, arg0);
}

void TORainbowCave01::free_static_data() {
    if ((u32) TORainbowCave01__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TORainbowCave01__static_model_resource, 1);
        TORainbowCave01__static_model_resource = 0U;
    }
}

void TORainbowCave01::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &abeniji_fe_obj001_niji_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TORainbowCave01__static_model_resource) = var_r0;
}

TORainbowCave01::~TORainbowCave01() {}

TORainbowCave01::TORainbowCave01(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TORainbowCave01__name;
    apply_object_set_data(set_data);
    model = (void *)((BmlResource *)TORainbowCave01__static_model_resource)->models[0].model;
    texlist = ((BmlResource *)TORainbowCave01__static_model_resource)->models[0].m_c;
    m_c0 = 400.0f;
    model_radius = 40000.0f;
    m_cc = 0.0f;
    init_light_params();
}

}
