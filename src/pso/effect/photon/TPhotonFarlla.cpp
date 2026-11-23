#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/photon/TPhotonFarlla.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/system/BmlResource.h"

const char *TPhotonFarlla_name = "TPhotonFarlla";

#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/vector.h"
#include <stddef.h>
#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/BmlResource.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/map/FloorArea.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/CollisionActorLookup.h"

#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/model_render_state.h"

extern "C" s32 scroll_strip_uvs(void *, s16, int);

void *farlla_photon_blast_model_buffers;

void TPhotonFarlla::reset_material_color(u8 count) {
    material_color.a = 0.0f;
    material_color.r = 0.0f;
    material_color.g = 0.0f;
    material_color.b = 0.0f;
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
                queue_photon_blast_hit(get_entity_id(candidate), 0, 0, power);
            }
        }
    }
}

void TPhotonFarlla::render() {
    if (visible != 0) {
        scroll_strip_uvs(farlla_photon_blast_model_buffers, uv_scroll, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(texlist));
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

#pragma push
#pragma opt_common_subs off
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
        play_persistent_sound(0x4002462F, (saddr)this, 0, 0, 0);
    }
}
#pragma pop

extern "C" {
extern void *lbl_804C3564[];

void *destroy__13TPhotonFarllaFPvs(TPhotonFarlla *farlla, s16 mode) {
    if (farlla != NULL) {
        *(void ***)((u8 *)farlla + 0x18) = lbl_804C3564;
        farlla->update_if_active();
        farlla->free_photon();
        farlla->unregister_object_by_id();
        free_collision_body_parts(farlla);
        __dt__18TPhotonBlastSummonFv(farlla, 0);
        if (mode > 0) {
            TObject::operator delete(farlla);
        }
    }
    return farlla;
}

void vfunc_6__8TObjBaseFPsl();
void interact__14TObjCollidableFl();
void get_name__8TObjBaseFv();
void get_center__8TObjBaseFv();
void apply_object_set_data__8TObjBaseFPv();
void classify_actor_view_detail__8TObjBaseFfff();
void enter_scene__18TPhotonBlastSummonFv();
void render__13TPhotonFarllaFv();
void render_shadows__7TObjectFv();
void reset_motion_fields__10TObjMotionFv();
void run_task__13TPhotonFarllaFv();
void update_if_active__18TPhotonBlastSummonFv();
void update_object_view_visibility__8TObjBaseFff();

#pragma push
#pragma opt_propagation off
TObjMotionAction photon_blast_farlla_params[2] = {
    {MOTION_MODE_ONCE, 0, 0, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 8, 1.0f, 0},
};

CollisionBody farlla_collision_bodies[1] = {
    {{0.0f, 0.0f, 0.0f}, 170.0f, 30.0f, 0, 0x2003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
void *lbl_804C3564[17] = {
    NULL, NULL, (void *)&destroy__13TPhotonFarllaFPvs, (void *)&run_task__13TPhotonFarllaFv,
    (void *)&render__13TPhotonFarllaFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__10TObjMotionFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&enter_scene__18TPhotonBlastSummonFv, (void *)&update_if_active__18TPhotonBlastSummonFv,
    NULL,
};
TPhotonFarlla *TPhotonFarlla__ct(TPhotonFarlla *summon, PhotonSummonParams *params) {
    Vec pos;
    TObjCollidable *owner_object;
    __ct__18TPhotonBlastSummonFv(summon);
    *(void ***)((u8 *)summon + 0x18) = lbl_804C3564;
    summon->m_name = TPhotonFarlla_name;
    summon->blast_kind = 0;
    VecCopy(&summon->position, &params->position);
    summon->owner_id = params->owner_id;
    init_collision_body_parts(summon, farlla_collision_bodies, 1);
    summon->refresh_collision_body_centers();
    summon->register_object_by_id();
    summon->owner = find_entity_by_id(summon->owner_id);
    if (summon->owner != NULL) {
        summon->rotation_y = summon->owner->rotation_y;
    }
    summon->model = photon_blast_shared_resource->models[0].model;
    summon->texlist = (saddr)photon_blast_shared_resource->models[0].m_c;
    summon->set_action_table((saddr)photon_blast_farlla_params);
    summon->set_motion_list((saddr)photon_blast_shared_resource->motions);
    summon->requested_action = 1;
    summon->set_animation(summon->requested_action);
    summon->set_requested_action(summon->requested_action);
    summon->last_action = 1;
    summon->is_first = params->is_first;
    summon->has_more = params->has_more;
    summon->visible = 0;
    summon->camera_script = 1;
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
    summon->reset_material_color(params->count);
    if (summon->has_more == 1) {
        summon->summon_flags |= 1;
    }
    summon->power = params->level;
    if (summon->is_first == 0) {
        summon->set_requested_action(0);
        summon->begin_photon_summon_camera(1);
        summon->is_first = 1;
        summon->last_action = 0;
        summon->visible = 1;
        owner_object = find_entity_by_id(summon->owner_id);
        if (owner_object != NULL) {
            VecCopy(&pos, &owner_object->position);
            pos.y += 30.0f;
        }
        new TPhotonMagicSquare(summon, 0, &pos, 0x78);
        summon->spawn_photon_blast_attachment_effects(0);
        play_cue_stream_file((saddr)"farla2.adx");
    } else {
        spawn_photon_blast_opening_effects(0, summon->owner_id);
        play_cue_stream_file((saddr)"farla.adx");
    }
    return summon;
}
#pragma pop
}

void destroy_farlla_photon_blast_model(void) {
    if (farlla_photon_blast_model_buffers != NULL) {
        destroy_buffer_pair(farlla_photon_blast_model_buffers, 1);
    }
    farlla_photon_blast_model_buffers = NULL;
}

void create_farlla_photon_blast_model(void) {
    TLobby *tables = (TLobby *)::operator new(0x14);
    if (tables != NULL) {
        tables = (TLobby *)tables->alloc_tables((saddr)photon_blast_shared_resource->models[0].model, 0);
    }
    farlla_photon_blast_model_buffers = tables;
}
