#include "types.h"
#include "pso/misc/TOFenceAncient03.h"
#include "pso/TMainTask.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"

const char *bm_fd_obj_n_saku_4x4_model_names[2] = { "fd_obj_n_saku_4x4.gj", NULL };
const char *bm_fd_obj_n_saku_4x4_motion_names[2] = { "fd_obj_n_saku_4x4.njm", NULL };
BmlResourceDescriptor bm_fd_obj_n_saku_4x4_resource_descriptor = {
    "bm_fd_obj_n_saku_4x4.bml", bm_fd_obj_n_saku_4x4_model_names, bm_fd_obj_n_saku_4x4_motion_names, 1, 1
};
// The fence's four 40-long walls and the four corner posts.
CollisionBody fence_ancient03_collision_bodies[8] = {
    { { 0.0f, 0.0f, 20.0f }, 3.0f, 20.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, -20.0f }, 3.0f, 20.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 20.0f, 0.0f, 0.0f }, 20.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -20.0f, 0.0f, 0.0f }, 20.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -20.0f, 0.0f, -20.0f }, 3.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 20.0f, 0.0f, -20.0f }, 3.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -20.0f, 0.0f, 20.0f }, 3.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 20.0f, 0.0f, 20.0f }, 3.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *TOFenceAncient03::class_name = "TOFenceAncient03";
BmlResource *TOFenceAncient03::model_resource;
s32 *TOFenceAncient03::texlists;

void TOFenceAncient03::update_demo() {}

void TOFenceAncient03::close() {
    s32 i;
    object_state = 0;
    is_open = 0;
    for (i = 0; i < 4; i++) {
        clear_player_status_flag(i, 8);
    }
}

void TOFenceAncient03::open() {
    s32 i;
    object_state = 1;
    is_open = 1;
    for (i = 0; i < 4; i++) {
        set_indexed_flags(i, 8);
    }
}

void *TOFenceAncient03::create(void *set_data) {
    return new TOFenceAncient03(tl_05, set_data);
}

void TOFenceAncient03::unload_resources() {
    s32 i;
    if (texlists != NULL) {
        for (i = 1; i < 4; i++) {
            TObjPlayer::free_if_valid(texlists[i]);
        }
        if (texlists != NULL) {
            mem_free(texlists);
            texlists = NULL;
        }
    }
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TOFenceAncient03::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fd_obj_n_saku_4x4_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
    s32 *lists = (s32 *)mem_alloc(4 * sizeof(s32));
    texlists = lists;
    lists[0] = model_resource->models[0].m_c;
    texlists[1] = (s32)load_gvm_texture_file((s32)texture_file_b);
    texlists[2] = (s32)load_gvm_texture_file((s32)texture_file_g);
    texlists[3] = (s32)load_gvm_texture_file((s32)texture_file_p);
}

// Defined after load_resources, which addresses each by its own symbol.
__declspec(section ".rodata") const char TOFenceAncient03::texture_file_b[] = "o_fence_ancient_b.gvm";
__declspec(section ".rodata") const char TOFenceAncient03::texture_file_g[] = "o_fence_ancient_g.gvm";
__declspec(section ".rodata") const char TOFenceAncient03::texture_file_p[] = "o_fence_ancient_p.gvm";

TOFenceAncient03::~TOFenceAncient03() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOFenceAncient03::TOFenceAncient03(TObject *parent, void *set_data) : TUnk_804B1B80(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)model_resource->models[0].model;
    texlist = texlists[read_texture_variant()];
    motion = model_resource->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    init_collision_body_parts(this, fence_ancient03_collision_bodies, 8);
    refresh_collision_body_centers();
    register_object_by_id();
    read_trigger_params();
    view_range = 400.0f;
    model_radius = 40.0f;
}
