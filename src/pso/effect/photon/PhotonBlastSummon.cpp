#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "types.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/camera/CameraPlayback.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800D8A2C.h"
#include "pso/system/vector.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/render/TFogCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/scene/TScene.h"

#include "pso/map/FloorArea.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixStack.h"

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

extern Vec attachment_up;
extern Vec joint_local_origin;
extern PhotonBlastJointList photon_blast_joint_origins[];

s32 photon_blast_joint_index;
s32 photon_blast_hit_count;
u32 last_photon_blast_hit_identity;
s32 deferred_photon_blast_hit_count;
u32 last_deferred_photon_blast_hit_identity;

void clear_deferred_photon_blast_hits(void) {
    s32 i;
    deferred_photon_blast_hit_count = 0;
    for (i = 0; i < 32; i++) {
        deferred_photon_blast_hit_queue[i].identity = 0xFFFF;
        deferred_photon_blast_hit_queue[i].value = 0.0f;
        deferred_photon_blast_hit_queue[i].kind = -1;
    }
}

void clear_photon_blast_hits(void) {
    s32 i;
    photon_blast_hit_count = 0;
    for (i = 0; i < 32; i++) {
        photon_blast_hit_queue[i].identity = 0xFFFF;
        photon_blast_hit_queue[i].value = 0.0f;
        photon_blast_hit_queue[i].kind = -1;
    }
}

void queue_deferred_photon_blast_hit(u32 identity, s32 kind, s32 allow_duplicate, f32 scale) {
    s32 found = 0;
    if (deferred_photon_blast_hit_count < 0x20) {
        const PhotonBlastEntry *e = get_photon_blast_entry(kind);
        if (allow_duplicate == 0) {
            s32 i;
            for (i = 0; i < deferred_photon_blast_hit_count; i++) {
                if (identity == deferred_photon_blast_hit_queue[i].identity) {
                    found = 1;
                }
            }
        }
        if (found == 0) {
            deferred_photon_blast_hit_queue[deferred_photon_blast_hit_count].kind = kind;
            deferred_photon_blast_hit_queue[deferred_photon_blast_hit_count].value = e->power;
            deferred_photon_blast_hit_queue[deferred_photon_blast_hit_count].identity = identity;
            last_deferred_photon_blast_hit_identity = identity;
            deferred_photon_blast_hit_count++;
        }
    }
}

void queue_photon_blast_hit(u32 identity, s32 kind, s32 allow_duplicate, f32 scale) {
    const PhotonBlastEntry *entry;
    s32 duplicate = 0;
    s32 i;
    if (photon_blast_hit_count >= 32) {
        return;
    }
    entry = get_photon_blast_entry(kind);
    if (allow_duplicate == 0) {
        for (i = 0; i < photon_blast_hit_count; i++) {
            if (photon_blast_hit_queue[i].identity == identity) {
                duplicate = 1;
            }
        }
    }
    if (duplicate == 0) {
        photon_blast_hit_queue[photon_blast_hit_count].kind = kind;
        photon_blast_hit_queue[photon_blast_hit_count].value = entry->power;
        photon_blast_hit_queue[photon_blast_hit_count].identity = identity;
        last_photon_blast_hit_identity = identity;
        photon_blast_hit_count = photon_blast_hit_count + 1;
    }
}

void queue_deferred_photon_blast_support(u32 identity, s32 kind, s32 allow_duplicate) {
    queue_deferred_photon_blast_hit(identity, kind, allow_duplicate, 1.0f);
}

void queue_photon_blast_support(u32 identity, s32 kind, s32 allow_duplicate) {
    queue_photon_blast_hit(identity, kind, allow_duplicate, 1.0f);
}

void TPhotonBlastSummon::begin_photon_summon_camera(s8 script) {
    CameraPlayback playback;
    playback.index = script;
    playback.bank = (s8)(get_current_floor_area() == AREA_DARK_FALZ);
    playback.flags = 0;
    playback.frame = 0.0f;
    playback.frame_step = 1.0f;
    if ((TCameraCtrl::view_state.flags & 4) || (TCameraCtrl::view_state.flags & 8)) {
        TCameraCtrl::select_active_controller(5);
    }
    playback.play(0x4222);
    set_scripted_camera_origin(&this->position, &this->position, (CameraAngles *)&this->rotation_x);
    camera_state = 1;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TPhotonBlastSummon::update_camera_pose(f32 speed) {
    CameraParams parameters;
    approach_vector_fixed_distance(&camera_position, &camera_position_goal, &camera_position, 0.48f);
    approach_vector_fixed_distance(&camera_target, &camera_target_goal, &camera_target, 0.55f);
    VecCopy(&parameters.position, &camera_position);
    VecCopy(&parameters.target, &camera_target);
    parameters.fov = 0x4222;
    set_active_camera_pose_from_params(&parameters);
}

void spawn_photon_blast_opening_effects(s32 kind, s32 owner_id) {
    PhotonOpeningEffect effect;
    Vec pos;
    TObjCollidable *owner;
    PhotonBlastEffectSet *set;
    PhotonOpeningEffect *effects;
    s32 count;
    s32 i;
    owner = find_entity_by_id(owner_id);
    if (owner == NULL) {
        return;
    }
    set = &photon_blast_attachment_table[kind];
    count = set->opening_effect_count;
    if (count <= 0) {
        return;
    }
    effects = set->opening_effects;
    for (i = 0; i < count; i++) {
        copy_effect_params(&effect, &effects[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, owner->rotation_y);
        matrix_mult_vec(0, &effect.offset, &pos);
        pop_matrices(1);
        pos.x += owner->position.x;
        pos.y += 30.0f + owner->position.y;
        pos.z += owner->position.z;
        create_timed_particle_emitter(&pos, effect.effect_id, effect.delay, effect.duration);
    }
}

void copy_effect_params(PhotonOpeningEffect *dst, PhotonOpeningEffect *src) {
    *dst = *src;
}

void publish_photon_blast_joint_origins(NJS_OBJECT *) {
    s32 i;
    for (i = 0; i < photon_blast_joint_origins->count; i++) {
        PhotonBlastAttachment *attachment = &photon_blast_joint_origins->list[i];
        if (photon_blast_joint_index == attachment->joint) {
            Vec origin = joint_local_origin;
            forward_transform_to_view(&origin, &attachment->pos);
        }
    }
    photon_blast_joint_index += 1;
}

#pragma pop

void TPhotonBlastSummon::clear_photon_blast_joint_callback() { set_chunk_model_node_callback(0); }

void TPhotonBlastSummon::set_photon_blast_joint_callback() {
    photon_blast_joint_index = 0;
    photon_blast_joint_origins[0].list = attachments;
    photon_blast_joint_origins[0].count = attachment_count;
    set_chunk_model_node_callback(publish_photon_blast_joint_origins);
}

void TPhotonBlastSummon::update_photon_blast_attachments() {
    u32 i;
    PhotonBlastAttachment *e;
    for (i = 0; i < attachment_count; i++) {
        if (attachments[i].obj->all_parents_unqueued_for_destruction() == 0) {
            attachments[i].obj = NULL;
        }
        e = &attachments[i];
        if (e->obj != NULL) {
            if (e->joint >= 0) {
                e->obj->set_position(&e->pos);
            } else {
                e->obj->set_position(&position);
            }
        }
    }
}

void TPhotonBlastSummon::free_photon() { void *m = attachments; if (m) mem_free(m); }

void TPhotonBlastSummon::spawn_photon_blast_attachment_effects(s32 kind) {
    PhotonBlastEffectSet *set = &photon_blast_attachment_table[kind];
    attachment_count = set->attachment_count;
    if (attachment_count != 0) {
        struct { s32 delay; s32 duration; s32 id; } params;
        s32 angles[3];
        PhotonAttachmentDef *def;
        PhotonAttachmentDef *defs;
        u32 i;
        attachments = (PhotonBlastAttachment *)mem_alloc(attachment_count * sizeof(PhotonBlastAttachment));
        defs = set->attachments;
        for (i = 0; i < attachment_count; i++) {
            def = &defs[i];
            params.delay = def->delay;
            params.duration = def->duration;
            params.id = def->effect_id;
            copy_xyz(angles, def->angles);
            s32 flags = def->flags;
            s32 rot[3];
            Vec dir = attachment_up;
            if (angles[2] || angles[0] || angles[1]) {
                push_matrix_from(identity_matrix);
                rotate_matrix_z(0, angles[2]);
                rotate_matrix_x(0, angles[0]);
                rotate_matrix_y(0, angles[1]);
                matrix_mult_vec(0, &dir, &dir);
                pop_matrices(1);
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, rotation_y);
                matrix_mult_vec(0, &dir, &dir);
                pop_matrices(1);
                direction_to_rotation_xz((u8 *)&dir, &rot[0], &rot[2]);
                rot[1] = 0;
            } else {
                rot[0] = 0;
                rot[1] = 0;
                rot[2] = 0;
            }
            attachments[i].obj = create_timed_particle_emitter_with_angles(&position, rot, params.id, params.delay, params.duration, flags);
            attachments[i].joint = def->joint;
            copy_xyz(attachments[i].angles, angles);
        }
    }
}

void TPhotonBlastSummon::restore_fog() { TFogCtrl::update_all(0); }
void TPhotonBlastSummon::apply_fog() { TFogCtrl::apply_all(63, 0); }

void TPhotonBlastSummon::update_if_active() {
    if (!(summon_flags & 1)) {
        restore_camera();
        show_sky();
        restore_fog();
        enable_player_particle_effect();
    }
    if (tl_05 != 0) {
        tl_05->allow_rendering();
    }
}

void TPhotonBlastSummon::enter_scene() {
    setup_photon_blast_camera();
    hide_sky();
    apply_fog();
    disable_player_particle_effect();
    if (tl_05 != NULL) {
        tl_05->disallow_rendering();
    }
}

void TPhotonBlastSummon::show_sky() {
    TScene::set_ready();
    if (TSceneSora::instance != 0) {
        TSceneSora::sky_active_flag = 1;
    }
}

void TPhotonBlastSummon::hide_sky() {
    TScene::reset_counter();
    if (TSceneSora::instance != 0) {
        TSceneSora::sky_active_flag = 0;
    }
}

void TPhotonBlastSummon::update_state() {
    switch (camera_state) {
    case 0:
        update_camera_pose(1.0f);
        return;
    case 1:
        if ((get_scripted_camera_playback()->flags & CameraPlayback::FLAG_DONE) || (TCameraCtrl::get_active_controller() != 5)) {
            queue_destruction();
        }
        return;
    }
}

void TPhotonBlastSummon::restore_camera() { restore_player_cameras(); TCameraCtrl::release_photon_blast_camera(); }

void TPhotonBlastSummon::setup_photon_blast_camera() {
    Vec position = {-3.0f, 6.7f, 11.0f};
    Vec position_goal = {-9.0f, 58.0f, 32.0f};
    Vec target = {0.0f, 8.0f, 0.0f};
    Vec target_goal = {0.0f, 56.0f, 0.0f};
    TObjPlayer *player;
    if (blast_kind == 0) {
        // Farlla's camera: the y values are lower; the original assigns x twice.
        position_goal.x = -8.75f;
        position_goal.y = 43.92f;
        position_goal.x = 28.79f;
        target_goal.x = 0.0f;
        target_goal.y = 39.0f;
        target_goal.x = 0.0f;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, player->rotation_y);
        matrix_mult_vec(0, &position, &position);
        matrix_mult_vec(0, &position_goal, &position_goal);
        matrix_mult_vec(0, &target, &target);
        matrix_mult_vec(0, &target_goal, &target_goal);
        pop_matrices(1);
        position.x += player->position.x;
        position.y += player->position.y;
        position.z += player->position.z;
        position_goal.x += player->position.x;
        position_goal.y += player->position.y;
        position_goal.z += player->position.z;
        target.x += player->position.x;
        target.y += player->position.y;
        target.z += player->position.z;
        target_goal.x += player->position.x;
        target_goal.y += player->position.y;
        target_goal.z += player->position.z;
        VecCopy(&camera_position, &position);
        VecCopy(&camera_position_goal, &position_goal);
        VecCopy(&camera_target, &target);
        VecCopy(&camera_target_goal, &target_goal);
        activate_camera_mode(9);
    }
}

TPhotonBlastSummon::~TPhotonBlastSummon() {
    attachments = 0;
}

TPhotonBlastSummon::TPhotonBlastSummon() : TObjMotion(tl_06) {
    this->camera_script = 0;
    this->attachment_count = 0;
    this->blast_kind = 0;
    this->power = 1.0f;
    this->summon_flags = 0;
    this->pad_13C[0] = 0.0f;
    this->pad_13C[1] = 0.0f;
    this->pad_13C[2] = 0.0f;
    this->attachments = 0;
    this->uv_scroll = 0;
    camera_state = 0;
    camera_target.x = 0.0f;
    camera_target.y = 0.0f;
    camera_target.z = 0.0f;
    camera_position.x = 0.0f;
    camera_position.y = 0.0f;
    camera_position.z = 0.0f;
    camera_target_goal.x = 0.0f;
    camera_target_goal.y = 0.0f;
    camera_target_goal.z = 1.0f;
    camera_position_goal.x = 0.0f;
    camera_position_goal.y = 0.0f;
    camera_position_goal.z = 1.0f;
}

PhotonAttachmentDef pilla_attachment_effects[10] = {
    {0x136, 0x1e, 0x14, 0x27, {0, 0, 0}, 0},
    {0x137, 0x14, 0x28, 0x11, {0, 0, 0}, 0},
    {0x137, 0x14, 0x28, 0x1b, {0, 0, 0}, 0},
    {0x138, 0x2d, 1, 0x27, {0, 0, 0}, 0},
    {0x139, 0xa, 0x32, 0x27, {0, 0, 0}, 0},
    {0x13a, 0x34, 0x14, 0x27, {0, 0, 0}, 0},
    {0x13b, 0x34, 0x14, 0x27, {0, 0, 0}, 0},
    {0x13d, 0x39, 1, 0x27, {0, 0, 0}, 0},
    {0x13c, 0x6b, 1, -2, {0, 0, 0}, 0},
    {0x140, 0x6b, 1, -2, {0, 0, 0}, 0},
};

PhotonAttachmentDef golla_attachment_effects[9] = {
    {0x130, 0xa, 0x42, 0x21, {0, 0, 0}, 0},
    {0x131, 0x37, 0xf, 0x21, {0, 0, 0}, 0},
    {0x132, 0x37, 0x14, 0x21, {0, 0, 0}, 0},
    {0x132, 0x55, 3, 0x21, {0x4000, 0, 0}, 0},
    {0x133, 0x39, 1, 0x21, {0, 0, 0}, 0},
    {0x133, 0x4b, 1, 0x21, {0x4000, 0, 0}, 0},
    {0x141, 0x5a, 0x28, 4, {0, 0, 0}, 0},
    {0x141, 0x87, 5, 4, {0, 0, 0}, 0},
    {0x141, 0x91, 2, 4, {0, 0, 0}, 0},
};

PhotonAttachmentDef leilla_attachment_effects[32] = {
    {0x154, 1, 0x73, 0x15, {0, 0, 0}, 0},
    {0x155, 2, 0x73, 0x15, {0, 0, 0}, 0},
    {0x154, 1, 0x73, 0x1c, {0, 0, 0}, 0},
    {0x155, 2, 0x73, 0x1c, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x22, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x22, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x29, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x29, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x37, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x37, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x3e, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x3e, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x31, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x31, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x46, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x46, {0, 0, 0}, 0},
    {0x154, 1, 0x73, 0x4e, {0, 0, 0}, 0},
    {0x155, 2, 0x73, 0x4e, {0, 0, 0}, 0},
    {0x158, 1, 1, 2, {0, 0, 0}, 0},
    {0x158, 0x3c, 1, 2, {0, 0, 0}, 0},
    {0x15b, 1, 1, 2, {0, 0, 0}, 0},
    {0x15b, 0x3c, 1, 2, {0, 0, 0}, 0},
    {0x15e, 0x6a, 1, 0xc, {0, 0, 0}, 0},
    {0x15e, 0x6c, 1, 0xc, {0, 0, 0}, 0},
    {0x159, 0x6c, 7, 0xc, {0, 0x8000, 0}, 0},
    {0x156, 0x75, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x157, 0x75, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x156, 0x77, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x157, 0x77, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x156, 0x79, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x157, 0x79, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x174, 0x6a, 1, 0x4e, {0, 0, 0}, 0},
};

PhotonAttachmentDef mylla_attachment_effects[6] = {
    {0x164, 0x4e, 1, 0x21, {0, 0, 0}, 0},
    {0x167, 1, 0x6e, 0x25, {0, 0, 0}, 0},
    {0x167, 1, 0x6e, 0x29, {0, 0, 0}, 0},
    {0x168, 0x57, 1, 5, {0, 0, 0}, 0},
    {0x168, 0x59, 1, 5, {0, 0, 0}, 0},
    {0x166, 1, 1, 5, {0, 0, 0}, 0},
};

PhotonAttachmentDef youlla_attachment_effects[6] = {
    {0x164, 0x58, 1, 0x21, {0, 0, 0}, 0},
    {0x167, 1, 0x6e, 0x25, {0, 0, 0}, 0},
    {0x167, 1, 0x6e, 0x29, {0, 0, 0}, 0},
    {0x168, 0x57, 1, 5, {0, 0, 0}, 0},
    {0x168, 0x59, 1, 5, {0, 0, 0}, 0},
    {0x166, 1, 1, 5, {0, 0, 0}, 0},
};

PhotonAttachmentDef farlla_attachment_effects[6] = {
    {0x152, 0x6d, 0xf, 0x11, {0, 0, 0}, 0},
    {0x152, 0x7c, 0xf, 0xc, {0, 0, 0}, 0},
    {0x165, 1, 1, 0x31, {0, 0, 0}, 0},
    {0x15b, 1, 1, 0x31, {0, 0, 0}, 0},
    {0x173, 0x42, 0x36, 0x1e, {0, 0, 0}, 0},
    {0x173, 0x42, 0x36, 0x28, {0, 0, 0}, 0},
};

PhotonAttachmentDef estlla_attachment_effects[19] = {
    {0x15c, 1, 0x6e, 0x22, {0, 0, 0}, 0},
    {0x15c, 1, 0x6e, 0x23, {0, 0, 0}, 0},
    {0x15d, 0x55, 0x16, 0xc, {-0x4000, -0x38e, 0}, 0},
    {0x15d, 0x55, 0x16, 0x11, {-0x4000, 0x38e, 0}, 0},
    {0x159, 0x57, 0xc, 7, {0x4000, 0, 0}, 0},
    {0x175, 0x5f, 1, 7, {0, 0, 0}, 0},
    {0x175, 0x64, 1, 7, {0, 0, 0}, 0},
    {0x175, 0x6e, 1, 7, {0, 0, 0}, 0},
    {0x163, 0x18, 2, 0x1d, {0, 0, 0}, 0},
    {0x163, 0x3a, 2, 7, {0, 0, 0}, 0},
    {0x162, 0x3b, 2, 7, {0, 0, 0}, 0},
    {0x163, 0x55, 2, 0x1d, {0, 0, 0}, 0},
    {0x15a, 5, 1, 7, {0, 0, 0}, 0},
    {0x172, 4, 1, 7, {0, 0, 0}, 0},
    {0x15b, 6, 1, 7, {0, 0, 0}, 0},
    {0x15a, 0x41, 1, 7, {0, 0, 0}, 0},
    {0x172, 0x3f, 1, 7, {0, 0, 0}, 0},
    {0x15b, 0x40, 1, 7, {0, 0, 0}, 0},
    {0x174, 0x6c, 1, 7, {0, 0, 0}, 0},
};

PhotonOpeningEffect pilla_opening_effects[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

PhotonOpeningEffect golla_opening_effects[4] = {
    {0x13e, 0, 1, {0.0f, 20.0f, 50.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 50.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 20.0f, 50.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 20.0f, 50.0f}, 0},
};

PhotonOpeningEffect leilla_opening_effects[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

PhotonOpeningEffect mylla_opening_effects[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

PhotonOpeningEffect farlla_opening_effects[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

PhotonOpeningEffect estlla_opening_effects[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

PhotonBlastEffectSet photon_blast_attachment_table[7] = {
    {farlla_attachment_effects, 6, farlla_opening_effects, 4},
    {estlla_attachment_effects, 19, estlla_opening_effects, 4},
    {golla_attachment_effects, 9, golla_opening_effects, 4},
    {pilla_attachment_effects, 10, pilla_opening_effects, 4},
    {leilla_attachment_effects, 32, leilla_opening_effects, 4},
    {mylla_attachment_effects, 6, mylla_opening_effects, 4},
    {youlla_attachment_effects, 6, mylla_opening_effects, 4},
};

PhotonBlastJointList photon_blast_joint_origins[1];
PhotonBlastHit photon_blast_hit_queue[32];
PhotonBlastHit deferred_photon_blast_hit_queue[32];

__declspec(section ".rodata") Vec attachment_up = { 0, 1.0f };
__declspec(section ".rodata") Vec joint_local_origin = { 0 };
