#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/effect/photon/TPhotonMylla.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"


#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/system/SoundEffect.h"
#include "pso/effect/photon/TPhotonYoulla.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/TObjBase.h"


const char *TPhotonMylla::class_name = "TPhotonMylla";

// Mylla brings Youlla along; the count byte is not the chain's.
static const PhotonSummonParams photon_mylla_packet_template = { { 0.0f, 0.0f, 0.0f }, 0, 0, 0, { 0 }, 4, 1.0f };

void TPhotonMylla::reset_material_color(u8 count) {
    material_color.a = 0.0f;
    material_color.r = 0.0f;
    material_color.g = 0.0f;
    material_color.b = 0.0f;
}

#pragma push
#pragma opt_common_subs off
void TPhotonMylla::render() {
    if (visible != 0) {
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
        set_material_alpha_compare_reference(0);
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material(&material_color);
        set_photon_blast_joint_callback();
        draw();
        clear_motion_packed_rotation();
        set_material_alpha_compare_reference(0xBF);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        clear_photon_blast_joint_callback();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonMylla::run_task() {
    Vec square_pos;
    Vec first_flash_pos;
    Vec second_flash_pos;
    Vec strike_pos;
    f32 alpha;
    TObjCollidable *owner_object;
    if ((frame == 0x32) && (visible == 0)) {
        visible = 1;
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&square_pos, &owner_object->position);
        }
        square_pos.y += 30.0f;
        new TPhotonMagicSquare(this, 5, &square_pos, 0xAA, 0.5f);
    }
    if ((100.0f == (f32)frame) && (requested_action == 1)) {
        begin_photon_summon_camera(3);
        frame = 0;
        set_requested_action(0);
        spawn_photon_blast_attachment_effects(5);
    }
    last_action = requested_action;
    update_state();
    advance_animation();
    update_photon_blast_attachments();
    uv_scroll = uv_scroll + 0xF;
    uv_scroll = (u8)uv_scroll;
    frame = frame + 1;
    if (118.0f == (f32)frame) {
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&first_flash_pos, &owner_object->position);
        }
        first_flash_pos.y += 45.0f;
        spawn_particle_effect(&first_flash_pos, 0x174);
        spawn_particle_effect(&first_flash_pos, 0x175);
    }
    if (120.0f == (f32)frame) {
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&second_flash_pos, &owner_object->position);
        }
        second_flash_pos.y += 45.0f;
        spawn_particle_effect(&second_flash_pos, 0x169);
    }
    if (122.0f == (f32)frame) {
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&strike_pos, &owner_object->position);
        }
        strike_pos.y += 45.0f;
        spawn_particle_effect(&strike_pos, 0x169);
        if (owner_object != NULL) {
            queue_photon_blast_hit(owner_object->get_entity_id(), 5, 0, power);
        }
    }
    if ((f32)frame > 116.0f) {
        alpha = material_color.a;
        if (alpha > -1.0f) {
            material_color.a = alpha - 0.15f;
        }
    }
    if (visible != 0) {
        play_persistent_sound(0x4002462F, this, NULL, 0, 0);
    }
}
#pragma pop

TPhotonMylla::~TPhotonMylla() {
    update_if_active();
    free_photon();
}

TObjMotionAction photon_mylla_action_table[2] = {
    {MOTION_MODE_ONCE, 0, 6, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 0xD, 1.0f, 0},
};

TPhotonMylla::TPhotonMylla(PhotonSummonParams *params) {
    Vec pos;
    TObjCollidable *owner_object;
    m_name = class_name;
    blast_kind = 5;
    VecCopy(&position, &params->position);
    owner_id = params->owner_id;
    owner = find_entity_by_id(owner_id);
    if (owner != NULL) {
        rotation_y = owner->rotation_y;
    }
    model = photon_blast_shared_resource->models[10].model;
    texlist = photon_blast_shared_resource->models[10].texlist;
    set_action_table(photon_mylla_action_table);
    set_motion_list(photon_blast_shared_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_requested_action(requested_action);
    last_action = 1;
    is_first = params->is_first;
    has_more = params->has_more;
    visible = 0;
    {
        PhotonSummonParams youlla_params = photon_mylla_packet_template;
        youlla_params.position.x = position.x;
        youlla_params.position.y = position.y;
        youlla_params.position.z = position.z;
        youlla_params.owner_id = owner_id;
        youlla_params.is_first = is_first;
        youlla_params.has_more = has_more;
        new TPhotonYoulla(&youlla_params);
    }
    reset_material_color(params->count);
    camera_script = 3;
    enter_scene();
    frame = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON:
    case AREA_DE_ROL_LE:
    case AREA_VOL_OPT:
    case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON:
    case AREA_OLGA_FLOW:
    case AREA_BARBA_RAY:
    case AREA_GOL_DRAGON:
        new TPhotonRainbow(this, &position, 1);
        break;
    default:
        new TPhotonRainbow(this, &position, 0);
        break;
    }
    if (has_more == 1) {
        summon_flags |= 1;
    }
    power = params->level;
    if (is_first == 0) {
        set_requested_action(0);
        begin_photon_summon_camera(3);
        is_first = 1;
        last_action = 0;
        visible = 1;
        owner_object = find_entity_by_id(owner_id);
        if (owner_object != NULL) {
            VecCopy(&pos, &owner_object->position);
        }
        pos.y += 30.0f;
        new TPhotonMagicSquare(this, 5, &pos, 0xAA, 0.5f);
        spawn_photon_blast_attachment_effects(5);
        play_cue_stream_file("maila2.adx");
    } else {
        spawn_photon_blast_opening_effects(5, owner_id);
        play_cue_stream_file("maila.adx");
    }
}

void *mylla_photon_blast_buffer_pair;
void destroy_mylla_photon_blast_model(void) { mylla_photon_blast_buffer_pair = NULL; }

void create_mylla_photon_blast_model(void) {  }
