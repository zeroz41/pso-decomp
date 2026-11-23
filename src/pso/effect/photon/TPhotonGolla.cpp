#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include <stdlib.h>
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/effect/photon/TPhotonGolla.h"
#include "pso/map/FloorArea.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/player/TObjPlayer_801AC0D8.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/effect/photon/TPhotonConcentrate.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803D853C.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/BmlResource.h"
#include "pso/player/PhotonBlastResults.h"

extern "C" s32 scroll_strip_uvs(void *, s16, int);

void *golla_photon_blast_buffer_pair;

const char *TPhotonGolla__class_name = "TPhotonGolla";
extern const PhotonConcentrateParams photon_golla_concentrate_packet = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 500.0f, 5.0f, 30.0f }, NULL, 0
};

void TPhotonGolla::reset_material_color(u8 count) {
    material_color.a = 0.0f;
    material_color.r = 0.0f;
    material_color.g = 0.0f;
    material_color.b = 0.0f;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
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
        local.z = 1e+02f;
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

    angle = (u32)(3.6e+02f * (3.0517578e-05f * (f32)rand()) + 1.0f);
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
    beam = new TPhotonConcentrate((u8 *)&params, (saddr)this, owner_id);
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
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
        queue_photon_blast_hit(get_entity_id(target), 2, 0, power);
    }
    hit_target = target;
}
#pragma pop

void TPhotonGolla::render() {
    if (visible != 0) {
        scroll_strip_uvs(golla_photon_blast_buffer_pair, uv_scroll, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(texlist));
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
        pos.y += 3e+01f;
        new TPhotonMagicSquare(this, 3, &pos, 0xFA, 0.5f);
    }
    if ((5e+01f == (f32)frame) && (requested_action == 1)) {
        begin_photon_summon_camera(5);
        frame = 0;
        set_field_b8(0);
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
        play_persistent_sound(0x4002462F, (saddr)this, 0, 0, 0);
    }
}

extern "C" {
extern void *lbl_804C35F4[];

void *destroy__12TPhotonGollaFPvs(TPhotonGolla *golla, s16 mode) {
    if (golla != NULL) {
        *(void ***)((u8 *)golla + 0x18) = lbl_804C35F4;
        golla->update_if_active();
        golla->free_photon();
        golla->unregister_object_by_id();
        free_collision_body_parts(golla);
        __dt__18TPhotonBlastSummonFv(golla, 0);
        if (mode > 0) {
            TObject::operator delete(golla);
        }
    }
    return golla;
}

void vfunc_6__8TObjBaseFPsl();
void interact__14TObjCollidableFl();
void get_name__8TObjBaseFv();
void get_center__8TObjBaseFv();
void apply_object_set_data__8TObjBaseFPv();
void classify_actor_view_detail__8TObjBaseFfff();
void enter_scene__18TPhotonBlastSummonFv();
void render__12TPhotonGollaFv();
void render_shadows__7TObjectFv();
void reset_motion_fields__10TObjMotionFv();
void run_task__12TPhotonGollaFv();
void update_if_active__18TPhotonBlastSummonFv();
void update_object_view_visibility__8TObjBaseFff();

#pragma push
#pragma opt_propagation off
TObjMotionAction photon_blast_golla_params[2] = {
    {MOTION_MODE_ONCE, 0, 4, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 0xB, 1.0f, 0},
};

CollisionBody golla_collision_bodies[1] = {
    {{0.0f, -30.0f, 0.0f}, 500.0f, 500.0f, 0, 0x18007, {0.0f, 0.0f, 0.0f}, 0.0f},
};
void *lbl_804C35F4[17] = {
    NULL, NULL, (void *)&destroy__12TPhotonGollaFPvs, (void *)&run_task__12TPhotonGollaFv,
    (void *)&render__12TPhotonGollaFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__10TObjMotionFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&enter_scene__18TPhotonBlastSummonFv, (void *)&update_if_active__18TPhotonBlastSummonFv,
    NULL,
};
TPhotonGolla *TPhotonGolla__ct(TPhotonGolla *summon, PhotonSummonParams *params) {
    Vec pos;
    TObjCollidable *owner_object;
    __ct__18TPhotonBlastSummonFv(summon);
    *(void ***)((u8 *)summon + 0x18) = lbl_804C35F4;
    summon->m_name = TPhotonGolla__class_name;
    summon->blast_kind = 2;
    VecCopy(&summon->position, &params->position);
    summon->owner_id = params->owner_id;
    init_collision_body_parts(summon, golla_collision_bodies, 1);
    summon->refresh_collision_body_centers();
    summon->register_object_by_id();
    summon->target = NULL;
    summon->owner = find_entity_by_id(summon->owner_id);
    if (summon->owner != NULL) {
        summon->rotation_y = summon->owner->rotation_y;
    } else {
        summon->rotation_y = 0;
    }
    summon->model = photon_blast_shared_resource->models[4].model;
    summon->texlist = (saddr)photon_blast_shared_resource->models[4].m_c;
    summon->set_field_d8((saddr)photon_blast_golla_params);
    summon->set_field_dc((saddr)photon_blast_shared_resource->motions);
    summon->requested_action = 1;
    summon->set_animation(summon->requested_action);
    summon->set_field_b8(summon->requested_action);
    summon->last_action = 1;
    summon->is_first = params->is_first;
    summon->has_more = params->has_more;
    summon->visible = 0;
    summon->camera_script = 5;
    summon->enter_scene();
    summon->frame = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
        new TPhotonRainbow(summon, &summon->position, 1);
        break;
    default:
        new TPhotonRainbow(summon, &summon->position, 0);
        break;
    }
    summon->hit_target = NULL;
    summon->collect_hit_targets();
    summon->reset_material_color(params->count);
    if (summon->has_more == 1) {
        summon->summon_flags |= 1;
    }
    summon->power = params->level;
    if (summon->is_first == 0) {
        summon->set_field_b8(0);
        summon->begin_photon_summon_camera(5);
        summon->is_first = 1;
        summon->last_action = 0;
        summon->visible = 1;
        owner_object = find_entity_by_id(summon->owner_id);
        if (owner_object != NULL) {
            VecCopy(&pos, &owner_object->position);
        }
        pos.y += 3e+01f;
        new TPhotonMagicSquare(summon, 3, &pos, 0x96, 0.5f);
        summon->spawn_photon_blast_attachment_effects(2);
        play_cue_stream_file((saddr)"goula2.adx");
    } else {
        spawn_photon_blast_opening_effects(2, summon->owner_id);
        play_cue_stream_file((saddr)"goula.adx");
    }
    return summon;
}
#pragma pop
}

void destroy_golla_photon_blast_model(void) {
    if (golla_photon_blast_buffer_pair != NULL) {
        destroy_buffer_pair(golla_photon_blast_buffer_pair, 1);
    }
    golla_photon_blast_buffer_pair = NULL;
}

void create_golla_photon_blast_model(void) {
    TLobby *tables = (TLobby *)::operator new(0x14);
    if (tables != NULL) {
        tables = (TLobby *)tables->alloc_tables((saddr)photon_blast_shared_resource->models[4].model, 0);
    }
    golla_photon_blast_buffer_pair = tables;
}
