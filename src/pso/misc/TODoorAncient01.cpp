#include "types.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

// This unit is compiled with deferred code generation like
// TOBarrierEnergy01's, which emits the functions in reverse: the file is
// written from the last function back to the first.

__declspec(section ".data") const char *bm_fe_obj_o_door01l_model_names[2] = {
    "fe_obj_o_door01l.gj",
    NULL,
};
__declspec(section ".data") const char *bm_fe_obj_o_door01l_motion_names[2] = {
    "fe_obj_o_door01l.njm",
    NULL,
};
BmlResourceDescriptor bm_fe_obj_o_door01l_resource_descriptor = {
    "bm_fe_obj_o_door01l.bml",
    bm_fe_obj_o_door01l_model_names,
    bm_fe_obj_o_door01l_motion_names,
    1,
    1,
};
CollisionBody door_ancient01_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TODoorAncient01_name = "TODoorAncient01";

// Defined in TLobby_8001EF5C.cpp, whose header cannot declare them yet (its
// definitions take that file's private archive types).
extern "C" {
BmlResource *load_resource_from_descriptor(void *resource, s32 kind, const BmlResourceDescriptor *desc, s32, s32, s32);
BmlResource *TLobby__sub_8001FE7C(BmlResource *resource, s16 del);
}

static BmlResource *door_ancient01_archive;
static s32 *door_ancient01_texlists;

TODoorAncient01::TODoorAncient01(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = TODoorAncient01_name;
    apply_object_set_data(set_data);
    model = (void *)door_ancient01_archive->models[0].model;
    texlist = door_ancient01_texlists[1];
    motion = door_ancient01_archive->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = animation_end_frame / 30.0f;
    init_collision_body_parts(this, door_ancient01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
}

TODoorAncient01::~TODoorAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TODoorAncient01::load_assets() {
    BmlResource *archive = (BmlResource *)::operator new(0x440);
    if (archive != NULL) {
        archive = load_resource_from_descriptor(archive, 1, &bm_fe_obj_o_door01l_resource_descriptor, 0, 0, 0);
    }
    door_ancient01_archive = archive;
    s32 *texlists = (s32 *)mem_alloc(2 * sizeof(s32));
    door_ancient01_texlists = texlists;
    texlists[0] = door_ancient01_archive->models[0].m_c;
    door_ancient01_texlists[1] = (s32)load_gvm_texture_file((s32)"fe_obj_o_door01g.gvm");
}

void TODoorAncient01::free_statics() {
    if (door_ancient01_texlists != NULL) {
        TObjPlayer::free_if_valid(door_ancient01_texlists[1]);
        if (door_ancient01_texlists != NULL) {
            mem_free(door_ancient01_texlists);
            door_ancient01_texlists = NULL;
        }
    }
    if (door_ancient01_archive != NULL) {
        TLobby__sub_8001FE7C(door_ancient01_archive, 1);
        door_ancient01_archive = NULL;
    }
}

void *TODoorAncient01::create(void *set_data) {
    return new TODoorAncient01(tl_05, set_data);
}

void TODoorAncient01::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0 && is_in_view_depth(30.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(door_ancient01_texlists[door_flags & DOOR_FLAG_UNLOCKED]);
        if (m_ac == DOOR_CLOSED) {
            NJS_OBJECT *node = (NJS_OBJECT *)model;
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
            node = node->child;
            push_matrix();
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
            pop_matrix();
            TParticleCtrl::begin_effect_render();
            node = node->sibling;
            push_matrix();
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
            pop_matrix();
            node = node->sibling;
            push_matrix();
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        } else {
            draw_ginja_model_with_motion(model, motion, m_b0);
        }
        pop_matrix();
    }
}

void TODoorAncient01::update_closed() {
    if ((door_flags & DOOR_FLAG_UNLOCKED) && is_any_player_within_radius_xz(4900.0f) != 0) {
        m_ac = DOOR_OPENING;
        set_indexed_flags(0, 8);
        play_sound_effect(0x4004B708, &position, 0, 0);
    }
}

void TODoorAncient01::update_open() {
    if (!(door_flags & DOOR_FLAG_UNLOCKED) || is_any_player_within_radius_xz(10000.0f) == 0) {
        m_ac = DOOR_CLOSING;
        clear_player_status_flag(0, 8);
        play_sound_effect(0x4004B708, &position, 0, 0);
    }
}

void TODoorAncient01::update_demo() {}
