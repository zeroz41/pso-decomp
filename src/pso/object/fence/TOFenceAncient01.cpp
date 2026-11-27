#include "types.h"
#include "pso/object/fence/TOFenceAncient01.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"

const char *bm_fd_obj_n_saku_4x2_model_names[2] = { "fd_obj_n_saku_4x2.gj", NULL };
const char *bm_fd_obj_n_saku_4x2_motion_names[2] = { "fd_obj_n_saku_4x2.njm", NULL };
BmlResourceDescriptor bm_fd_obj_n_saku_4x2_resource_descriptor = {
    "bm_fd_obj_n_saku_4x2.bml", bm_fd_obj_n_saku_4x2_model_names, bm_fd_obj_n_saku_4x2_motion_names, 1, 1
};
// The fence's 50-wide box and the two posts at its ends.
CollisionBody fence_ancient01_collision_bodies[3] = {
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 25.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -20.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 20.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *TOFenceAncient01::class_name = "TOFenceAncient01";
BmlResource *TOFenceAncient01::model_resource;
NJS_TEXLIST **TOFenceAncient01::texlists;

void TOFenceAncient01::update_demo() {}

void TOFenceAncient01::close() {
    object_state = 0;
    is_open = 0;
    clear_player_status_flag(0, 8);
}

void TOFenceAncient01::open() {
    object_state = 1;
    is_open = 1;
    set_indexed_flags(0, 8);
}

void *TOFenceAncient01::create(ObjectSetData *set_data) {
    return new TOFenceAncient01(tl_05, set_data);
}

void TOFenceAncient01::unload_resources() {
    s32 i;
    if (texlists != NULL) {
        for (i = 1; i < 4; i++) {
            free_if_valid(texlists[i]);
        }
        if (texlists != NULL) {
            delete[] texlists;
            texlists = NULL;
        }
    }
    if (model_resource != NULL) {
        delete (BmlResource *)model_resource;
        model_resource = NULL;
    }
}

void TOFenceAncient01::load_resources() {
    BmlResource *resource = new BmlResource(1, &bm_fd_obj_n_saku_4x2_resource_descriptor, 0, 0, NULL);
    model_resource = resource;
    NJS_TEXLIST **lists = new NJS_TEXLIST *[4];
    texlists = lists;
    lists[0] = model_resource->models[0].texlist;
    texlists[1] = LoadPvmFileTls(texture_file_b);
    texlists[2] = LoadPvmFileTls(texture_file_g);
    texlists[3] = LoadPvmFileTls(texture_file_p);
}

// Defined after load_resources, which addresses each by its own symbol.
__declspec(section ".rodata") const char TOFenceAncient01::texture_file_b[] = "o_fence_ancient_b.gvm";
__declspec(section ".rodata") const char TOFenceAncient01::texture_file_g[] = "o_fence_ancient_g.gvm";
__declspec(section ".rodata") const char TOFenceAncient01::texture_file_p[] = "o_fence_ancient_p.gvm";

TOFenceAncient01::~TOFenceAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOFenceAncient01::TOFenceAncient01(TObject *parent, ObjectSetData *set_data) : TOFenceBase(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = model_resource->models[0].model;
    texlist = texlists[read_texture_variant()];
    motion = model_resource->motions[0].motion;
    animation_end_frame = (f32)motion->nbFrame - 1.0f;
    init_collision_body_parts(this, fence_ancient01_collision_bodies, 3);
    refresh_collision_body_centers();
    register_object_by_id();
    read_trigger_params();
    view_range = 400.0f;
    model_radius = 40.0f;
}

// The base's set-data readers are emitted here, after their first caller:
// the linker keeps this TU's copies for all four fences.
s32 TOFenceBase::read_trigger_params() {
    switch_id = set_params[0];
    if (switch_id > 0x100) {
        trigger_mode = 0;
    } else if (switch_id < 0) {
        trigger_mode = 1;
    } else {
        trigger_mode = 2;
    }
    return switch_id;
}

s32 TOFenceBase::read_texture_variant() {
    texture_variant = set_params[1];
    if (texture_variant < 0) {
        texture_variant = 0;
    } else if (texture_variant >= 4) {
        texture_variant = 3;
    }
    return texture_variant;
}
