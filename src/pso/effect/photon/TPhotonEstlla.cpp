#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/photon/TPhotonEstlla.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"

#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/object/base/TObjMotion.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/vector.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/photon/TPhotonLine.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/render/model_render_state.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/system/MatrixOps.h"

void TPhotonEstlla::reset_color(u8 summon_count) {
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


const char *TPhotonEstlla::class_name = "TPhotonEstlla";
extern const PhotonLineParams photon_estlla_line_packet_init = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f
};
StripBufferPair *estlla_photon_blast_model;

void TPhotonEstlla::spawn_line() {
    TObjCollidable *owner;
    Vec forward;
    Vec direction;
    owner = find_entity_by_id(owner_id);
    forward.x = 0.0f;
    forward.y = 0.0f;
    forward.z = 1.0f;
    push_matrix_from(identity_matrix);
    if (owner) {
        rotate_matrix_y(0, owner->rotation_y);
    }
    rotate_vector_by_matrix(0, &forward, &direction);
    pop_matrices(1);
    {
        PhotonLineParams packet = photon_estlla_line_packet_init;
        packet.pos = position;
        packet.dir = direction;
        packet.power = power;
        new TPhotonLine(&packet, this, owner_id);
    }
}

void TPhotonEstlla::render() {
    if (started != 0) {
        estlla_photon_blast_model->scroll_uvs(uv_scroll, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        translate_matrix(0, position.x, position.y, position.z);
        rotate_matrix_y(0, rotation_y);
        set_photon_blast_joint_callback();
        saved_model_render_flags = model_render_flags;
        copy_argb(&saved_model_draw_color, &model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        set_motion_packed_rotation();
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material(&color);
        draw();
        clear_motion_packed_rotation();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        clear_photon_blast_joint_callback();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonEstlla::run_task() {
    Vec at;
    TObjCollidable *owner;

    timer++;
    if (timer == 0x32 && started == 0) {
        started = 1;
        owner = find_entity_by_id(owner_id);
        if (owner != NULL) {
            at.x = owner->position.x;
            at.y = 30.0f + owner->position.y;
            at.z = owner->position.z;
        }
        new TPhotonMagicSquare(this, 1, &at, 0x78);
    }
    if (timer == 0x64 && requested_action == 1) {
        begin_photon_summon_camera(0);
        timer = 0;
        set_requested_action(0);
        spawn_photon_blast_attachment_effects(1);
    }
    last_action = requested_action;
    update_state();
    advance_animation();
    update_photon_blast_attachments();
    uv_scroll = uv_scroll + 0xF;
    uv_scroll = (u8)uv_scroll;
    if (90.0f == timer) {
        spawn_line();
    }
    if (timer > 105.0f) {
        if (color.a > -1.0f) {
            color.a = color.a - 0.15f;
        }
    }
    if (started != 0) {
        play_persistent_sound(0x4002462F, this, NULL, 0, 0);
    }
}

TPhotonEstlla::~TPhotonEstlla() {
    update_if_active();
    free_photon();
}

TObjMotionAction photon_estlla_param_table[2] = {
    {MOTION_MODE_ONCE, 0, 5, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 0xC, 1.0f, 0},
};

TPhotonEstlla::TPhotonEstlla(PhotonSummonParams *params) : TPhotonBlastSummon() {
    TObjCollidable *owner;
    m_name = class_name;
    blast_kind = 1;
    VecCopy(&position, &params->position);
    owner_id = params->owner_id;
    owner = find_entity_by_id(owner_id);
    if (owner != NULL) {
        rotation_y = owner->rotation_y;
    }
    model = photon_blast_shared_resource->models[9].model;
    texlist = photon_blast_shared_resource->models[9].texlist;
    set_action_table(photon_estlla_param_table);
    set_motion_list(photon_blast_shared_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_requested_action(requested_action);
    last_action = 1;
    is_first = params->is_first;
    has_more = params->has_more;
    started = 0;
    camera_script = 0;
    enter_scene();
    timer = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
        new TPhotonRainbow(this, &position, 1);
        break;
    default:
        new TPhotonRainbow(this, &position, 0);
        break;
    }
    reset_color(params->count);
    if (has_more == 1) {
        summon_flags |= 1;
    }
    power = params->level;
    if (is_first == 0) {
        Vec at;
        set_requested_action(0);
        begin_photon_summon_camera(0);
        is_first = 1;
        last_action = 0;
        started = 1;
        owner = find_entity_by_id(owner_id);
        if (owner != NULL) {
            at.x = owner->position.x;
            at.y = 30.0f + owner->position.y;
            at.z = owner->position.z;
        }
        new TPhotonMagicSquare(this, 1, &at, 0x78);
        spawn_photon_blast_attachment_effects(1);
        play_cue_stream_file("estla2.adx");
    } else {
        spawn_photon_blast_opening_effects(1, owner_id);
        play_cue_stream_file("estla.adx");
    }
}

void destroy_estlla_photon_blast_model(void) {
    if (estlla_photon_blast_model != NULL) {
        delete estlla_photon_blast_model;
    }
    estlla_photon_blast_model = NULL;
}

void create_estlla_photon_blast_model(void) {
    estlla_photon_blast_model = new StripBufferPair(photon_blast_shared_resource->models[9].model->child, 0);
}
