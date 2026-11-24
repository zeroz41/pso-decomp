#include "pso/effect/photon/TPhotonFarlla.h"
#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/effect/particle/ParticleFactory.h"

#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/StripBufferPair.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/vector.h"

#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/BmlResource.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/model_render_state.h"
#include "pso/object/base/TObjBase.h"


// The original emits code in reverse definition order.
#pragma defer_codegen on


const char *TPhotonFarlla::class_name = "TPhotonFarlla";
StripBufferPair *farlla_photon_blast_model_buffers;

TObjMotionAction photon_blast_farlla_params[2] = {
    {MOTION_MODE_ONCE, 0, 0, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 8, 1.0f, 0},
};

CollisionBody farlla_collision_bodies[1] = {
    {{0.0f, 0.0f, 0.0f}, 170.0f, 30.0f, 0, 0x2003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

void create_farlla_photon_blast_model(void) {
    farlla_photon_blast_model_buffers = new StripBufferPair(photon_blast_shared_resource->models[0].model, 0);
}

void destroy_farlla_photon_blast_model(void) {
    if (farlla_photon_blast_model_buffers != NULL) {
        delete farlla_photon_blast_model_buffers;
    }
    farlla_photon_blast_model_buffers = NULL;
}

TPhotonFarlla::TPhotonFarlla(PhotonSummonParams *params) : TPhotonBlastSummon() {
    Vec pos;
    TObjCollidable *owner_object;
    m_name = class_name;
    blast_kind = 0;
    VecCopy(&position, &params->position);
    owner_id = params->owner_id;
    init_collision_body_parts(this, farlla_collision_bodies, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    owner = find_entity_by_id(owner_id);
    if (owner != NULL) {
        rotation_y = owner->rotation_y;
    }
    model = photon_blast_shared_resource->models[0].model;
    texlist = photon_blast_shared_resource->models[0].texlist;
    set_action_table(photon_blast_farlla_params);
    set_motion_list(photon_blast_shared_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_requested_action(requested_action);
    last_action = 1;
    is_first = params->is_first;
    has_more = params->has_more;
    visible = 0;
    camera_script = 1;
    enter_scene();
    frame = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
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
        begin_photon_summon_camera(1);
        is_first = 1;
        last_action = 0;
        visible = 1;
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&pos, &owner_object->position);
            pos.y += 30.0f;
        }
        new TPhotonMagicSquare(this, 0, &pos, 0x78);
        spawn_photon_blast_attachment_effects(0);
        play_cue_stream_file("farla2.adx");
    } else {
        spawn_photon_blast_opening_effects(0, owner_id);
        play_cue_stream_file("farla.adx");
    }
}

TPhotonFarlla::~TPhotonFarlla() {
    update_if_active();
    free_photon();
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TPhotonFarlla::run_task() {
    Vec square_pos;
    Vec burst_pos;
    Vec flash_pos;
    f32 alpha;
    s32 now;
    TObjCollidable *owner_object;
    frame = frame + 1;
    if ((frame == 0x32) && (visible == 0)) {
        visible = 1;
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&square_pos, &owner_object->position);
            square_pos.y += 30.0f;
        }
        new TPhotonMagicSquare(this, 0, &square_pos, 0x78);
    }
    if ((frame == 0x64) && (requested_action == 1)) {
        begin_photon_summon_camera(1);
        frame = 0;
        set_requested_action(0);
        spawn_photon_blast_attachment_effects(0);
    }
    last_action = requested_action;
    update_state();
    advance_animation();
    update_photon_blast_attachments();
    uv_scroll = uv_scroll + 0xF;
    uv_scroll = (u8)uv_scroll;
    if (140.0f == (f32)frame) {
        collect_hit_targets();
    }
    if (130.0f == (f32)frame) {
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&burst_pos, &owner_object->position);
        }
        burst_pos.y += 10.0f;
        spawn_particle_effect(&burst_pos, 0x151);
        burst_pos.y += 5.0f;
        spawn_particle_effect(&burst_pos, 0x15F);
    }
    now = frame;
    if ((133.0f == (f32)now) || (135.0f == (f32)now)) {
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&flash_pos, &owner_object->position);
            flash_pos.y += 10.0f;
        }
        spawn_particle_effect(&flash_pos, 0x151);
    }
    if ((f32)frame > 138.0f) {
        alpha = material_color.a;
        if (alpha > -1.0f) {
            material_color.a = alpha - 0.15f;
        }
    }
    if (visible != 0) {
        play_persistent_sound(0x4002462F, this, NULL, 0, 0);
    }
}

void TPhotonFarlla::render() {
    if (visible != 0) {
        farlla_photon_blast_model_buffers->scroll_uvs(uv_scroll, 0);
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
        set_constant_material(&material_color);
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

void TPhotonFarlla::collect_hit_targets() {
    s32 i;
    TObjChara *candidate;
    TObjPlayer::init_all_slots();
    mark_enemy_body_contacts();
    if (bodies->flags & 0x100000) {
        for (i = 0; i < 16; i++) {
            candidate = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (candidate != NULL) {
                queue_photon_blast_hit(candidate->get_entity_id(), 0, 0, power);
            }
        }
    }
}

void TPhotonFarlla::reset_material_color(u8 count) {
    material_color.a = 0.0f;
    material_color.r = 0.0f;
    material_color.g = 0.0f;
    material_color.b = 0.0f;
}
