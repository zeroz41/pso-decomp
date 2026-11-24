#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/photon/TPhotonYoulla.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/CollisionActorLookup.h"

#pragma readonly_strings on


const char *TPhotonYoulla::class_name = "TPhotonYoulla";
void *youlla_photon_blast_buffer_pair;


#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"

TObjMotionAction photon_blast_youlla_params[2] = {
    {MOTION_MODE_ONCE, 0, 7, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 14, 1.0f, 0},
};

void TPhotonYoulla::reset_material_color(u8 count) {
    material_color.a = 0.0f;
    material_color.r = 0.0f;
    material_color.g = 0.0f;
    material_color.b = 0.0f;
}

void TPhotonYoulla::render() {
    if (visible != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        saved_model_render_flags = model_render_flags;
        copy_argb(&saved_model_draw_color, &model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        set_motion_packed_rotation();
        set_material_alpha_compare_reference(0);
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material(&material_color);
        set_photon_blast_joint_callback();
        draw();
        clear_motion_packed_rotation();
        set_material_alpha_compare_reference(0xBF);
        clear_photon_blast_joint_callback();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonYoulla::run_task() {
    f32 alpha;

    if ((frame == 0x32) && (visible == 0)) {
        visible = 1;
    }
    if ((100.0f == (f32)frame) && (requested_action == 1)) {
        spawn_photon_blast_attachment_effects(6);
        frame = 0;
        set_requested_action(0);
    }
    last_action = requested_action;
    advance_animation();
    update_photon_blast_attachments();
    uv_scroll = uv_scroll + 0xF;
    uv_scroll = (u8)uv_scroll;
    frame = frame + 1;
    if ((f32)frame > 116.0f) {
        alpha = material_color.a;
        if (alpha > -1.0f) {
            material_color.a = alpha - 0.15f;
        }
    }
    if (123.0f == (f32)frame) {
        queue_destruction();
    }
}

TPhotonYoulla::~TPhotonYoulla() {
    free_photon();
}

TPhotonYoulla::TPhotonYoulla(PhotonSummonParams *params) {
    TObjCollidable *owner_object;
    m_name = class_name;
    blast_kind = 5;
    VecCopy(&position, &params->position);
    owner_id = params->owner_id;
    owner = find_entity_by_id(owner_id);
    owner_object = owner;
    if (owner_object != NULL) {
        rotation_y = owner_object->rotation_y;
    }
    model = photon_blast_shared_resource->models[11].model;
    texlist = photon_blast_shared_resource->models[11].texlist;
    set_action_table(photon_blast_youlla_params);
    set_motion_list(photon_blast_shared_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_requested_action(requested_action);
    last_action = 1;
    is_first = params->is_first;
    has_more = params->has_more;
    visible = 0;
    reset_material_color(params->count);
    frame = 0;
    if (is_first == 0) {
        set_requested_action(0);
        is_first = 1;
        last_action = 0;
        visible = 1;
        spawn_photon_blast_attachment_effects(6);
    } else {
        spawn_photon_blast_opening_effects(6, owner_id);
    }
}

void destroy_youlla_photon_blast_model(void) { youlla_photon_blast_buffer_pair = NULL; }

void create_youlla_photon_blast_model(void) {  }
