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
#include "pso/render/MaterialColorFade.h"
#include "pso/system/SoundEffect.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/PlayerSlots.h"

// Built with -inline off,deferred: functions are written last to first, so
// the vtables come out in the original's order.
const char *TItemEffPG::class_name = "TItemEffPG";

ItemEffPGParams *ItemEffPGParams::init_params() {
    reset_attack_params(this);
    hits = 10;
    max_radius = 50.0f;
    required_charge = 1.0f;
    radius_step = 2.5f;
    return this;
}

void TItemEffPG::create(TObject *parent, ItemEffPGParams *params) {
    new TItemEffPG(parent, params);
}

TItemEffPG::TItemEffPG(TObject *parent, ItemEffPGParams *params) : TUnk_804E355C(parent, params) {
    m_name = class_name;
    max_radius = params->max_radius;
    if (50.0f < max_radius) {
        max_radius = 50.0f;
    }
    radius_step = params->radius_step;
    required_charge = params->required_charge;
    pad_B0 *= 3.0f;
    visual = new TItemEffPGModel(this, params);
}

TItemEffPG::~TItemEffPG() {}

void TItemEffPG::run_task() {
    s32 active;

    active = 1;
    if (has_game_join_id() == 0) {
        active = 0;
    }
    if (consume_charge() == 0) {
        active = 0;
    }
    if (active != 0) {
        f32 radius = body.radius;
        if (radius < max_radius) {
            body.radius = radius + radius_step;
            f32 limit = max_radius;
            if (limit < body.radius) {
                body.radius = limit;
            }
        }
        check_hits();
        return;
    }
    if (m_down == NULL) {
        queue_destruction();
        disallow_rendering();
        return;
    }
    if (visual != NULL) {
        visual->begin_fade();
        visual = NULL;
    }
}

s32 TItemEffPG::consume_charge() {
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

void TItemEffPG::create(TObject *parent, ItemEffPGParams *params, s32 count) {
    new TItemEffPGLimited(parent, params, count);
}

TItemEffPGLimited::TItemEffPGLimited(TObject *parent, ItemEffPGParams *params, s32 count) : TItemEffPG(parent, params) {
    uses_left = count;
}

TItemEffPGLimited::~TItemEffPGLimited() {}

s32 TItemEffPGLimited::consume_charge() {
    s32 left = uses_left;
    if (left > 0) {
        uses_left = left - 1;
        return 1;
    }
    return 0;
}

TItemEffPGModel::TItemEffPGModel(TItemEffPG *parent, ItemEffPGParams *params) : TObject(parent) {
    item_id = params->item_id;
    model = params->model;
    texture_list = params->texture_list;
    scale_step = params->radius_step;
    max_scale = params->max_radius;
    VecCopy(&position, &params->position);
    f32 radius = params->radius;
    scale.z = radius;
    scale.y = radius;
    scale.x = radius;
    rotation_y = 0;
    child_rotation_y = 0;
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    particle = create_particle_emitter(&position, 0x83);
    fading = 0;
}

TItemEffPGModel::~TItemEffPGModel() {
    if (particle != NULL) {
        particle->queue_destruction();
        particle = NULL;
    }
}

void TItemEffPGModel::run_task() {
    rotation_y += 0x71C;
    child_rotation_y -= 0xE38;
    if (fading == 0) {
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
    play_persistent_sound(0x4001A343, this, &position, 0, 0);
}

void TItemEffPGModel::render() {
    if (all_parents_unqueued_for_destruction() == 0 || find_equipped_item(item_id) == 0) {
        return;
    }
    if ((model != NULL) && (TMainTask::get_render_pass() == 1)) {
        set_draw_list_mask(3);
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb(&saved_model_draw_color, &model_material_color);
        model_render_flags |= 0x20;
        set_constant_material(&color);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        push_matrix();
        rotate_matrix_y(NULL, rotation_y);
        scale_current_matrix(&scale.x);
        draw_ginja_model(model->model);
        pop_matrix();
        push_matrix();
        rotate_matrix_y(NULL, child_rotation_y);
        scale_current_matrix(&scale.x);
        draw_ginja_model(model->child->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        copy_argb(&model_material_color, &saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    }
}

void TItemEffPGModel::begin_fade() {
    fading = 1;
}
