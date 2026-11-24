#include "pso/effect/photon/TPhotonGolla.h"
#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include <stdlib.h>
#include "pso/system/vector.h"
#include "pso/map/FloorArea.h"

#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/object/base/TObjBase.h"

// The original emits code in reverse definition order.
#pragma defer_codegen on
#pragma fp_contract on


StripBufferPair *golla_photon_blast_buffer_pair;

const char *TPhotonGolla::class_name = "TPhotonGolla";
extern const PhotonConcentrateParams photon_golla_concentrate_packet = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 500.0f, 5.0f, 30.0f, NULL, 0
};

TObjMotionAction photon_blast_golla_params[2] = {
    {MOTION_MODE_ONCE, 0, 4, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 0xB, 1.0f, 0},
};

CollisionBody golla_collision_bodies[1] = {
    {{0.0f, -30.0f, 0.0f}, 500.0f, 500.0f, 0, 0x18007, {0.0f, 0.0f, 0.0f}, 0.0f},
};

void create_golla_photon_blast_model(void) {
    golla_photon_blast_buffer_pair = new StripBufferPair(photon_blast_shared_resource->models[4].model, 0);
}

void destroy_golla_photon_blast_model(void) {
    if (golla_photon_blast_buffer_pair != NULL) {
        delete golla_photon_blast_buffer_pair;
    }
    golla_photon_blast_buffer_pair = NULL;
}

TPhotonGolla::TPhotonGolla(PhotonSummonParams *params) : TPhotonBlastSummon() {
    Vec pos;
    TObjCollidable *owner_object;
    m_name = class_name;
    blast_kind = 2;
    VecCopy(&position, &params->position);
    owner_id = params->owner_id;
    init_collision_body_parts(this, golla_collision_bodies, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    target = NULL;
    owner = find_entity_by_id(owner_id);
    if (owner != NULL) {
        rotation_y = owner->rotation_y;
    } else {
        rotation_y = 0;
    }
    model = photon_blast_shared_resource->models[4].model;
    texlist = photon_blast_shared_resource->models[4].texlist;
    set_action_table(photon_blast_golla_params);
    set_motion_list(photon_blast_shared_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_requested_action(requested_action);
    last_action = 1;
    is_first = params->is_first;
    has_more = params->has_more;
    visible = 0;
    camera_script = 5;
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
    hit_target = NULL;
    collect_hit_targets();
    reset_material_color(params->count);
    if (has_more == 1) {
        summon_flags |= 1;
    }
    power = params->level;
    if (is_first == 0) {
        set_requested_action(0);
        begin_photon_summon_camera(5);
        is_first = 1;
        last_action = 0;
        visible = 1;
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&pos, &owner_object->position);
        }
        pos.y += 30.0f;
        new TPhotonMagicSquare(this, 3, &pos, 0x96, 0.5f);
        spawn_photon_blast_attachment_effects(2);
        play_cue_stream_file("goula2.adx");
    } else {
        spawn_photon_blast_opening_effects(2, owner_id);
        play_cue_stream_file("goula.adx");
    }
}

TPhotonGolla::~TPhotonGolla() {
    update_if_active();
    free_photon();
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TPhotonGolla::run_task() {
    Vec pos;
    s32 now;
    TObjCollidable *owner_object;
    frame = frame + 1;
    if ((frame == 0x32) && (visible == 0)) {
        visible = 1;
        frame = 0;
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&pos, &owner_object->position);
        }
        pos.y += 30.0f;
        new TPhotonMagicSquare(this, 3, &pos, 0xFA, 0.5f);
    }
    if ((50.0f == (f32)frame) && (requested_action == 1)) {
        begin_photon_summon_camera(5);
        frame = 0;
        set_requested_action(0);
        spawn_photon_blast_attachment_effects(2);
    }
    last_action = requested_action;
    update_state();
    advance_animation();
    update_photon_blast_attachments();
    uv_scroll = uv_scroll + 0xF;
    uv_scroll = (u8)uv_scroll;
    if (frame == 0x50) {
        VecCopy(&beam_origin, &attachments[2].pos);
        spawn_particle_effect(&beam_origin, 0x133);
        spawn_concentrate();
    }
    now = frame;
    if ((now == 0x56) || (now == 0x5C) || (now == 0x62) || (now == 0x68) || (now == 0x6E) || (now == 0x74)) {
        spawn_concentrate();
    }
    if (visible != 0) {
        play_persistent_sound(0x4002462F, this, NULL, 0, 0);
    }
}

void TPhotonGolla::render() {
    if (visible != 0) {
        golla_photon_blast_buffer_pair->scroll_uvs(uv_scroll, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
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

void TPhotonGolla::collect_hit_targets() {
    s32 i;
    TObjChara *candidate;
    TObjPlayer::init_all_slots();
    mark_enemy_body_contacts();
    if (bodies->flags & 0x100000) {
        for (i = 0; i < 16; i++) {
            candidate = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (candidate != NULL) {
                if (target != NULL) {
                    Vec selected_delta = target->body_center;
                    TObjCollidable *owner_object;
                    f32 selected_distance;
                    subtract_vector(&selected_delta, &position);
                    Vec candidate_delta = candidate->body_center;
                    subtract_vector(&candidate_delta, &position);
                    selected_distance = vec_squared_length(&selected_delta);
                    if (vec_squared_length(&candidate_delta) < selected_distance) {
                        target = candidate;
                    }
                    owner_object = find_entity_by_id(owner_id);
                    Vec direction = target->body_center;
                    Vec forward;
                    Vec left;
                    Vec right;
                    if (owner_object != NULL) {
                        subtract_vector(&direction, &owner_object->position);
                    }
                    normalize_vector(&direction);
                    forward.y = forward.x = 0.0f;
                    forward.z = 1.0f;
                    push_matrix_from(identity_matrix);
                    if (owner_object != NULL) {
                        rotate_matrix_y(0, owner_object->rotation_y + 0x1555);
                    }
                    rotate_vector_by_matrix(0, &forward, &left);
                    pop_matrices(1);
                    push_matrix_from(identity_matrix);
                    if (owner_object != NULL) {
                        rotate_matrix_y(0, owner_object->rotation_y - 0x1555);
                    }
                    rotate_vector_by_matrix(0, &forward, &right);
                    pop_matrices(1);
                    vec3_dot(&direction, &left);
                    vec3_dot(&direction, &right);
                    if (!(vec3_dot(&direction, &left) > 0.65f) ||
                        !(vec3_dot(&direction, &right) > 0.65f)) {
                        target = NULL;
                    }
                } else {
                    target = candidate;
                }
            }
        }
    }
    if (target != NULL) {
        queue_photon_blast_hit(target->get_entity_id(), 2, 0, power);
    }
    hit_target = target;
}

void TPhotonGolla::spawn_concentrate() {
    Vec target_pos;
    Vec local;
    Vec rotated;
    TObjCollidable *owner_object;
    u32 angle;
    TPhotonConcentrate *beam;
    if (hit_target == NULL) {
        owner_object = find_entity_by_id(owner_id);
        local.x = 0.0f;
        if (owner_object != NULL) {
            local.y = owner_object->position.y;
        }
        local.z = 100.0f;
        push_matrix_from(identity_matrix);
        if (owner_object != NULL) {
            rotate_matrix_y(0, owner_object->rotation_y);
        }
        rotate_vector_by_matrix(0, &local, &rotated);
        pop_matrices(1);
        VecCopy(&target_pos, &position);
        vec3_add_to(&target_pos, &rotated);
    } else {
        VecCopy(&target_pos, &target->body_center);
    }
    Vec direction = target_pos;
    subtract_vector(&direction, &beam_origin);
    normalize_vector(&direction);

    angle = (u32)(360.0f * (3.0517578e-05f * (f32)rand()) + 1.0f);
    PhotonConcentrateParams params = photon_golla_concentrate_packet;
    params.origin.x = beam_origin.x;
    params.origin.y = beam_origin.y;
    params.origin.z = beam_origin.z;
    params.target.x = target_pos.x;
    params.target.y = target_pos.y;
    params.target.z = target_pos.z;
    params.direction.x = direction.x;
    params.direction.y = direction.y;
    params.direction.z = direction.z;
    params.target_object = target;
    params.angle = angle;
    beam = new TPhotonConcentrate(&params, this, owner_id);
}

void TPhotonGolla::reset_material_color(u8 count) {
    material_color.a = 0.0f;
    material_color.r = 0.0f;
    material_color.g = 0.0f;
    material_color.b = 0.0f;
}
