#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/weapon/TItemWeapon.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804F0A00.h"
#include "pso/weapon/TUnk_804F0AF8.h"
#include "pso/weapon/TUnk_804F0908.h"
#include "pso/weapon/TUnk_804F0810.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TUnk_804F0BF0.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/effect/item/TUnk_804F0C08.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"

extern s32 saved_model_draw_color[];
extern s32 model_material_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
// Built with -inline off,deferred: functions are written last to first, so
// the vtables come out 0BF0, 0C08, 0C28 as in the original.
// The functions from 0x8034FE28 on were a separate unit; their literals continue
// this TU's .sdata2 pool at 0x805DFE14 (a 4-mod-8 address, so no TU starts there).
const char *TItemEffPG__name = "TItemEffPG";

S_8035016C *S_8035016C::init_params() {
    TObjPlayer__sub_802E451C(this);
    hits = 10;
    pad_28 = 50.0f;
    required_charge = 1.0f;
    pad_30 = 2.5f;
    return this;
}

void TItemEffPG::create(TObject *parent, S_8035016C *params) {
    new TItemEffPG(parent, params);
}

TItemEffPG::TItemEffPG(TObject *parent, S_8035016C *params) : TUnk_804E355C(parent, params) {
    m_name = TItemEffPG__name;
    pad_C4 = params->pad_28;
    if (50.0f < pad_C4) {
        pad_C4 = 50.0f;
    }
    m_c8 = params->pad_30;
    required_charge = params->required_charge;
    pad_B0 *= 3.0f;
    m_d0 = new TUnk_804F0BF0(this, params);
}

TItemEffPG::~TItemEffPG() {}

void TItemEffPG::run_task() {
    f32 temp_f1;
    f32 temp_f1_2;
    s32 var_r31;

    var_r31 = 1;
    if (has_game_join_id() == 0) {
        var_r31 = 0;
    }
    if (this->vfunc_7() == 0) {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        temp_f1 = this->body.radius;
        if (temp_f1 < this->pad_C4) {
            this->body.radius = (f32) (temp_f1 + this->m_c8);
            temp_f1_2 = this->pad_C4;
            if (temp_f1_2 < this->body.radius) {
                this->body.radius = temp_f1_2;
            }
        }
        check_hits();
        return;
    }
    if ((uaddr) this->m_down == 0U) {
        queue_destruction();
        disallow_rendering();
        return;
    }
    if (m_d0 != NULL) {
        TItemEffPG__begin_visual_fade(m_d0);
        m_d0 = NULL;
    }
}

s32 TItemEffPG::vfunc_7() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return 0;
    }
    if (player->get_photon_blast_charge() < required_charge) {
        return 0;
    }
    player->spend_photon_blast_charge(required_charge);
    return 1;
}

void TItemEffPG::create(TObject *parent, S_8035016C *params, s32 count) {
    new TUnk_804F0C08(parent, params, count);
}

TUnk_804F0C08::TUnk_804F0C08(TObject *parent, S_8035016C *params, s32 count) : TItemEffPG(parent, params) {
    pad_D4 = count;
}

TUnk_804F0C08::~TUnk_804F0C08() {}

s32 TUnk_804F0C08::vfunc_7() {
    s32 temp_r4;

    temp_r4 = this->pad_D4;
    if (temp_r4 > 0) {
        this->pad_D4 = (temp_r4 - 1);
        return 1;
    }
    return 0;
}

TUnk_804F0BF0::TUnk_804F0BF0(TItemEffPG *parent, S_8035016C *params) : TObject(parent) {
    item_id = params->item_id;
    m_20 = params->pad_34;
    texture_list = params->pad_38;
    scale_step = params->pad_30;
    max_scale = params->pad_28;
    VecCopy(&position, &params->position);
    f32 radius = params->radius;
    scale.z = radius;
    scale.y = radius;
    scale.x = radius;
    rotation_y = 0;
    m_40 = 0;
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    m_38 = create_particle_emitter(&position, 0x83);
    m_58 = 0;
}

TUnk_804F0BF0::~TUnk_804F0BF0() {
    if (m_38 != NULL) {
        m_38->queue_destruction();
        m_38 = NULL;
    }
}

void TUnk_804F0BF0::run_task() {
    rotation_y += 0x71C;
    m_40 -= 0xE38;
    if (m_58 == 0) {
        f32 current_scale = scale.z;
        if (current_scale < max_scale) {
            scale.z = current_scale + scale_step;
            f32 limit = max_scale;
            if (limit < scale.z) {
                scale.z = limit;
            }
        }
        f32 final_scale = scale.z;
        scale.y = final_scale;
        scale.x = final_scale;
    } else {
        f32 opacity = color.a;
        if (opacity <= -1.0f) {
            queue_destruction();
            disallow_rendering();
        } else {
            color.a = opacity - 0.06666667f;
        }
    }
    play_persistent_sound(0x4001A343, (saddr)this, (uaddr)&position, 0, 0);
}

void TUnk_804F0BF0::render() {
    if (all_parents_unqueued_for_destruction() == 0 || find_equipped_item(item_id) == 0) {
        return;
    }
    if ((m_20 != NULL) && (TMainTask::get_render_pass() == 1)) {
        set_draw_list_mask(3);
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
        model_render_flags |= 0x20;
        set_constant_material(&color);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        push_matrix();
        rotate_matrix_y(NULL, rotation_y);
        scale_current_matrix(&scale.x);
        draw_ginja_model(m_20->model);
        pop_matrix();
        push_matrix();
        rotate_matrix_y(NULL, m_40);
        scale_current_matrix(&scale.x);
        draw_ginja_model(m_20->child->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    }
}

void TItemEffPG__begin_visual_fade(TUnk_804F0BF0 *visual) {
    visual->m_58 = 1;
}
