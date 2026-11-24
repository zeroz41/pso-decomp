#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/photon/TPhotonPilla.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"
#include "pso/effect/photon/TPhotonLaser.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/model_render_state.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/object/base/TObjBase.h"

// The original emits code in reverse definition order.
#pragma defer_codegen on


const char *TPhotonPilla::class_name = "TPhotonPilla";
StripBufferPair *pilla_photon_blast_model;
extern const PhotonLaserParams photon_pilla_laser_packet = {
    { 0.0f, 0.0f, 0.0f }, { 0 }, { 0.0f, -1.0f, 0.0f }, 300.0f, 30.0f, 30.0f
};

TObjMotionAction photon_pilla_action_table[2] = {
    {MOTION_MODE_ONCE, 0, 3, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 0xA, 1.0f, 0},
};
CollisionBody photon_pilla_collision_body = {
    { 0.0f, 0.0f, 0.0f }, 120.0f, 30.0f, 0, 0x8007, { 0.0f, 0.0f, 0.0f }, 0.0f
};
// Where spawn_laser places each of the six lasers around the summon, 300 up.
Vec photon_pilla_laser_offset_table[6] = {
    { 0.0f, 300.0f, 50.0f },
    { 25.0f, 300.0f, 25.0f },
    { 25.0f, 300.0f, -25.0f },
    { 0.0f, 300.0f, -50.0f },
    { -25.0f, 300.0f, -25.0f },
    { 25.0f, 300.0f, 25.0f },
};

void create_pilla_photon_blast_model(void) {
    pilla_photon_blast_model = new StripBufferPair(photon_blast_shared_resource->models[0].model->child, 0);
}

void destroy_pilla_photon_blast_model(void) {
    if (pilla_photon_blast_model != NULL) {
        delete pilla_photon_blast_model;
    }
    pilla_photon_blast_model = NULL;
}

TPhotonPilla::TPhotonPilla(PhotonSummonParams *params) : TPhotonBlastSummon() {
    m_name = class_name;
    blast_kind = 3;
    VecCopy(&position, &params->position);
    owner_id = params->owner_id;
    init_collision_body_parts(this, &photon_pilla_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    owner = find_entity_by_id(owner_id);
    if (owner != NULL) {
        rotation_y = owner->rotation_y;
    }
    model = photon_blast_shared_resource->models[3].model;
    texlist = photon_blast_shared_resource->models[3].texlist;
    set_action_table(photon_pilla_action_table);
    set_motion_list(photon_blast_shared_resource->motions);
    requested_action = 1;
    set_animation(requested_action);
    set_requested_action(requested_action);
    last_action = 1;
    is_first = params->is_first;
    has_more = params->has_more;
    started = 0;
    camera_script = 4;
    enter_scene();
    timer = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON:
    case AREA_DE_ROL_LE:
    case AREA_VOL_OPT:
    case AREA_DARK_FALZ: {
        new TPhotonRainbow(this, &position, 1);
        break;
    }
    default: {
        new TPhotonRainbow(this, &position, 0);
        break;
    }
    }
    laser_count = 0;
    reset_color(params->count);
    if (has_more == 1) {
        summon_flags |= 1;
    }
    power = params->level;
    if (is_first == 0) {
        set_requested_action(0);
        begin_photon_summon_camera(4);
        is_first = 1;
        last_action = 0;
        started = 1;
        Vec at = position;
        at.y += 40.0f;
        new TPhotonMagicSquare(this, 3, &at, 0xAA, 0.5f);
        spawn_photon_blast_attachment_effects(3);
        play_cue_stream_file("paila2.adx");
    } else {
        spawn_photon_blast_opening_effects(3, owner_id);
        play_cue_stream_file("paila.adx");
    }
}

TPhotonPilla::~TPhotonPilla() {
    update_if_active();
    free_photon();
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TPhotonPilla::run_task() {
    Vec at;
    TObjCollidable *summoner;
    s32 frame;

    timer++;
    if (timer == 0x32 && started == 0) {
        started = 1;
        timer = 0;
        summoner = find_entity_by_id(owner_id);
        if (summoner != NULL) {
            VecCopy(&at, &summoner->position);
        }
        at.y += 30.0f;
        new TPhotonMagicSquare(this, 3, &at, 0xD2, 0.5f);
    }
    if (50.0f == timer && requested_action == 1 && started == 1) {
        begin_photon_summon_camera(4);
        timer = 0;
        set_requested_action(0);
        spawn_photon_blast_attachment_effects(3);
    }
    last_action = requested_action;
    update_state();
    advance_animation();
    update_photon_blast_attachments();
    uv_scroll = uv_scroll + 0xF;
    uv_scroll = (u8)uv_scroll;
    frame = timer;
    if (80.0f == frame || 82.0f == frame || 84.0f == frame || 86.0f == frame || 88.0f == frame || 90.0f == frame) {
        spawn_laser();
    }
    if (110.0f == timer) {
        apply_photon_blast_effects();
    }
    if (started != 0) {
        play_persistent_sound(0x4002462F, this, NULL, 0, 0);
    }
}

void TPhotonPilla::render() {
    if (started != 0) {
        pilla_photon_blast_model->scroll_uvs(uv_scroll, 0);
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

void TPhotonPilla::spawn_laser() {
    Vec at;
    at.x = position.x;
    at.y = 300.0f;
    at.z = position.z;
    vec3_add_to(&at, &photon_pilla_laser_offset_table[laser_count]);
    laser_count++;
    PhotonLaserParams packet = photon_pilla_laser_packet;
    packet.pos.x = at.x;
    packet.pos.y = at.y;
    packet.pos.z = at.z;
    new TPhotonLaser(&packet, this, owner_id);
}

void TPhotonPilla::apply_photon_blast_effects() {
    s32 index;

    TObjPlayer::init_all_slots();
    mark_enemy_body_contacts();
    if (bodies->flags & 0x100000) {
        index = 0;
        do {
            saddr player = TObjPlayer::get_battle_param(index);
            if (player != 0U) {
                queue_photon_blast_hit(((TObjBase *)player)->get_entity_id(), 2, 0, power);
            }
            index += 1;
        } while (index < 0x10);
    }
}

void TPhotonPilla::reset_color(u8 summon_count) {
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}
