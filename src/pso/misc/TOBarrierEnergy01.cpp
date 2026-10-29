#include "types.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TLobby_80156B18.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/unk/text_803D8F74.h"

// This unit is compiled with deferred code generation (its vtable comes ahead
// of play_ambient_loop_sound's switch table), which emits the functions in
// reverse: the file is written from the last function back to the first.

const char *bm_fs_obj_lazerguard_model_names[3] = {
    "fe_obj_laz_guard_moto.gj",
    "fs_obj_laz_guard.gj",
    NULL,
};
__declspec(section ".data") const char *bm_fs_obj_lazerguard_motion_names[2] = {
    "fs_obj_laz_guard.njm",
    NULL,
};
BmlResourceDescriptor bm_fs_obj_lazerguard_resource_descriptor = {
    "bm_fs_obj_lazerguard.bml",
    bm_fs_obj_lazerguard_model_names,
    bm_fs_obj_lazerguard_motion_names,
    2,
    1,
};
CollisionBody barrier_energy01_collision_body_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 5.0f, 20.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TOBarrierEnergy01_name = "TOBarrierEnergy01";

// Defined in TLobby_8001EF5C.cpp, whose header cannot declare them yet (its
// definitions take that file's private archive types).
extern "C" {
BmlResource *load_resource_from_descriptor(void *resource, s32 kind, const BmlResourceDescriptor *desc, s32 arg3, s32 arg4, s32 arg5);
BmlResource *TLobby__sub_8001FE7C(BmlResource *resource, s16 del);
}

static BmlResource *barrier_energy_shared_bml_archive;
// [0] closed, [1] open, [2] the frame model's texture list.
static s32 *barrier_energy_texlists;
static void *barrier_energy_model;

TOBarrierEnergy01::TOBarrierEnergy01(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = TOBarrierEnergy01_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(barrier_energy_shared_bml_archive, 1);
    texlist = barrier_energy_texlists[0];
    motion = get_bml_motion(barrier_energy_shared_bml_archive, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = 2.0f;
    init_collision_body_parts(this, barrier_energy01_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
    m_c0 = 400.0f;
    model_radius = 40.0f;
}

TOBarrierEnergy01::~TOBarrierEnergy01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOBarrierEnergy01::load_resources() {
    BmlResource *archive = (BmlResource *)::operator new(0x440);
    if (archive != NULL) {
        archive = load_resource_from_descriptor(archive, 1, &bm_fs_obj_lazerguard_resource_descriptor, 0, 0, 0);
    }
    barrier_energy_shared_bml_archive = archive;
    barrier_energy_model = (void *)get_bml_model(archive, 0);
    barrier_energy_texlists = (s32 *)mem_alloc(3 * sizeof(s32));
    barrier_energy_texlists[0] = (s32)load_gvm_texture_file((s32)"fs_obj_laz_guard_r.gvm");
    barrier_energy_texlists[1] = TObjFish__sub_8001EDB0(barrier_energy_shared_bml_archive, 1);
    barrier_energy_texlists[2] = TObjFish__sub_8001EDB0(barrier_energy_shared_bml_archive, 0);
}

void TOBarrierEnergy01::free_resources() {
    if (barrier_energy_texlists != NULL) {
        TObjPlayer::free_if_valid(barrier_energy_texlists[0]);
        if (barrier_energy_texlists != NULL) {
            mem_free(barrier_energy_texlists);
            barrier_energy_texlists = NULL;
        }
    }
    if (barrier_energy_shared_bml_archive != NULL) {
        TLobby__sub_8001FE7C(barrier_energy_shared_bml_archive, 1);
        barrier_energy_shared_bml_archive = NULL;
    }
}

void *TOBarrierEnergy01::create(void *set_data) {
    return new TOBarrierEnergy01(tl_05, set_data);
}

void TOBarrierEnergy01::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(model, motion, m_b0);
        TParticleCtrl::end_effect_render();
        TObjFish::set_global_param(barrier_energy_texlists[2]);
        draw_ginja_object(barrier_energy_model);
        pop_matrix();
    }
}

void TOBarrierEnergy01::update_closed() {
    update_anim_phase();
    play_ambient_loop_sound();
    if (door_flags & DOOR_FLAG_UNLOCKED) {
        m_ac = DOOR_OPENING;
        set_indexed_flags(0, 8);
        texlist = barrier_energy_texlists[1];
    }
}

void TOBarrierEnergy01::update_opening() {
    update_anim_phase();
    play_ambient_loop_sound();
    m_ac = DOOR_OPEN;
}

void TOBarrierEnergy01::update_open() {
    update_anim_phase();
    play_ambient_loop_sound();
    if (!(door_flags & DOOR_FLAG_UNLOCKED)) {
        m_ac = DOOR_CLOSING;
        clear_player_status_flag(0, 8);
        texlist = barrier_energy_texlists[0];
    }
}

void TOBarrierEnergy01::update_closing() {
    update_anim_phase();
    m_ac = DOOR_CLOSED;
    play_ambient_loop_sound();
}

void TOBarrierEnergy01::play_ambient_loop_sound() {
    switch (get_current_floor_area()) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_persistent_sound(0x4CB09, (s32)this, (u32)&position, 0, 0);
        return;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_persistent_sound(0x44B08, (s32)this, (u32)&position, 0, 0);
        return;
    case AREA_MINE1:
    case AREA_MINE2:
        play_persistent_sound(0x4004CB02, (s32)this, (u32)&position, 0, 0);
        return;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_persistent_sound(0x4004CB09, (s32)this, (u32)&position, 0, 0);
        return;
    case AREA_PIONEER2_EP1:
        return;
    case AREA_DRAGON:
        return;
    case AREA_DE_ROL_LE:
        return;
    case AREA_VOL_OPT:
        return;
    case AREA_DARK_FALZ:
        return;
    case AREA_LOBBY:
        return;
    }
}

void TOBarrierEnergy01::update_demo() {}

TOBarrierEnergy01 *TOBarrierEnergy01::init() {
    TLobby__sub_80156BA8(this);
    return this;
}
