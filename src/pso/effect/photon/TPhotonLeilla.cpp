#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/photon/TPhotonLeilla.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/system/BmlResource.h"
#include "pso/object/base/TObjBase.h"

const char *TPhotonLeilla::class_name = "TPhotonLeilla";

#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"

#include "pso/object/base/TObjMotion.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/CollisionActorLookup.h"

void release_photon_laser_resources(void) {}
void load_photon_laser_resources(void) {}

#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/model_render_state.h"


StripBufferPair *leilla_photon_buffer_pair;

void TPhotonLeilla::reset_material_color(u8 count) {
    material_color.a = 0.0f;
    material_color.r = 0.0f;
    material_color.g = 0.0f;
    material_color.b = 0.0f;
}

void TPhotonLeilla::render() {
    if (visible != 0) {
        leilla_photon_buffer_pair->scroll_uvs(uv_scroll, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        translate_matrix(0, position.x, position.y, position.z);
        rotate_matrix_y(0, rotation_y);
        saved_model_render_flags = model_render_flags;
        copy_argb(&saved_model_draw_color, &model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        set_motion_packed_rotation();
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material(&material_color);
        set_photon_blast_joint_callback();
        draw();
        clear_motion_packed_rotation();
        clear_photon_blast_joint_callback();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonLeilla::run_task() {
    Vec square_pos;
    f32 alpha;
    TObjCollidable *owner_object;
    frame = frame + 1;
    if ((frame == 0x32) && (visible == 0)) {
        visible = 1;
        frame = 0;
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&square_pos, &owner_object->position);
        }
        square_pos.y += 3e+01f;
        new TPhotonMagicSquare(this, 4, &square_pos, 0x78);
    }
    if ((5e+01f == (f32)frame) && (requested_action == 1)) {
        begin_photon_summon_camera(2);
        frame = 0;
        set_requested_action(0);
        spawn_photon_blast_attachment_effects(4);
    }
    last_action = requested_action;
    update_state();
    advance_animation();
    update_photon_blast_attachments();
    uv_scroll = uv_scroll + 0xF;
    uv_scroll = (u8)uv_scroll;
    if (1.3e+02f == (f32)frame) {
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            queue_photon_blast_hit(owner_object->get_entity_id(), 4, 0, power);
        }
    }
    if ((f32)frame > 109.0f) {
        alpha = material_color.a;
        if (alpha > -1.0f) {
            material_color.a = alpha - 0.15;
        }
    }
    if (visible != 0) {
        play_persistent_sound(0x4002462F, this, NULL, 0, 0);
    }
}

TPhotonLeilla::~TPhotonLeilla() {
    update_if_active();
    free_photon();
}

TObjMotionAction photon_blast_leilla_params[2] = {
    {MOTION_MODE_ONCE, 0, 1, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 9, 1.0f, 0},
};

TPhotonLeilla::TPhotonLeilla(PhotonSummonParams *params) {
    Vec pos;
    TObjCollidable *owner_object;
    m_name = class_name;
    blast_kind = 4;
    VecCopy(&position, &params->position);
    owner_id = params->owner_id;
    owner_object = find_entity_by_id(owner_id);
    if (owner_object != NULL) {
        rotation_y = owner_object->rotation_y;
    }
    model = photon_blast_shared_resource->models[1].model;
    texlist = photon_blast_shared_resource->models[1].texlist;
    set_action_table(photon_blast_leilla_params);
    set_motion_list(photon_blast_shared_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_requested_action(requested_action);
    last_action = 1;
    is_first = params->is_first;
    has_more = params->has_more;
    visible = 0;
    camera_script = 2;
    enter_scene();
    frame = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON:
    case AREA_DE_ROL_LE:
    case AREA_VOL_OPT:
    case AREA_DARK_FALZ:
        new TPhotonRainbow(this, &position, 1);
        break;
    default:
        new TPhotonRainbow(this, &position, 0);
        break;
    }
    reset_material_color(params->count);
    if (has_more == 1) {
        summon_flags |= 1;
    }
    power = params->level;
    if (is_first == 0) {
        set_requested_action(0);
        begin_photon_summon_camera(2);
        is_first = 1;
        last_action = 0;
        visible = 1;
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&pos, &owner_object->position);
        }
        pos.y += 3e+01f;
        new TPhotonMagicSquare(this, 4, &pos, 0x78);
        spawn_photon_blast_attachment_effects(4);
        play_cue_stream_file("reila2.adx");
    } else {
        spawn_photon_blast_opening_effects(4, owner_id);
        play_cue_stream_file("reila.adx");
    }
}

void destroy_leilla_photon_blast_model(void) {
    if (leilla_photon_buffer_pair != NULL) {
        delete leilla_photon_buffer_pair;
    }
    leilla_photon_buffer_pair = NULL;
}

void create_leilla_photon_blast_model(void) {
    leilla_photon_buffer_pair = new StripBufferPair(photon_blast_shared_resource->models[0].model->child, 0);
}
