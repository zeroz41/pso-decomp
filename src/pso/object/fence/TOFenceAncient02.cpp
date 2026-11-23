#include "types.h"
#include "pso/object/fence/TOFenceAncient02.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"

const char *bm_fd_obj_n_saku_6x2_model_names[2] = { "fd_obj_n_saku_6x2.gj", NULL };
const char *bm_fd_obj_n_saku_6x2_motion_names[2] = { "fd_obj_n_saku_6x2.njm", NULL };
BmlResourceDescriptor bm_fd_obj_n_saku_6x2_resource_descriptor = {
    "bm_fd_obj_n_saku_6x2.bml", bm_fd_obj_n_saku_6x2_model_names, bm_fd_obj_n_saku_6x2_motion_names, 1, 1
};
// The fence's 60-wide box and the two posts at its ends.
CollisionBody fence_ancient02_collision_bodies[3] = {
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 35.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -30.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 30.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *TOFenceAncient02::class_name = "TOFenceAncient02";
BmlResource *TOFenceAncient02::model_resource;
NJS_TEXLIST **TOFenceAncient02::texlists;

void TOFenceAncient02::update_demo() {}

void TOFenceAncient02::close() {
    object_state = 0;
    is_open = 0;
    clear_player_status_flag(0, 8);
}

void TOFenceAncient02::open() {
    object_state = 1;
    is_open = 1;
    set_indexed_flags(0, 8);
}

void *TOFenceAncient02::create(void *set_data) {
    return new TOFenceAncient02(tl_05, set_data);
}

void TOFenceAncient02::unload_resources() {
    s32 i;
    if (texlists != NULL) {
        for (i = 1; i < 4; i++) {
            TObjPlayer::free_if_valid((saddr)texlists[i]);
        }
        if (texlists != NULL) {
            mem_free(texlists);
            texlists = NULL;
        }
    }
    if (model_resource != NULL) {
        delete (BmlResource *)model_resource;
        model_resource = NULL;
    }
}

void TOFenceAncient02::load_resources() {
    BmlResource *resource = new BmlResource(1, &bm_fd_obj_n_saku_6x2_resource_descriptor, 0, 0, NULL);
    model_resource = resource;
    NJS_TEXLIST **lists = (NJS_TEXLIST **)mem_alloc(4 * sizeof(NJS_TEXLIST *));
    texlists = lists;
    lists[0] = model_resource->models[0].texlist;
    texlists[1] = load_gvm_texture_file(texture_file_b);
    texlists[2] = load_gvm_texture_file(texture_file_g);
    texlists[3] = load_gvm_texture_file(texture_file_p);
}

// Defined after load_resources, which addresses each by its own symbol.
__declspec(section ".rodata") const char TOFenceAncient02::texture_file_b[] = "o_fence_ancient_b.gvm";
__declspec(section ".rodata") const char TOFenceAncient02::texture_file_g[] = "o_fence_ancient_g.gvm";
__declspec(section ".rodata") const char TOFenceAncient02::texture_file_p[] = "o_fence_ancient_p.gvm";

TOFenceAncient02::~TOFenceAncient02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOFenceAncient02::TOFenceAncient02(TObject *parent, void *set_data) : TOFenceBase(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)model_resource->models[0].model;
    texlist = texlists[read_texture_variant()];
    motion = model_resource->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    init_collision_body_parts(this, fence_ancient02_collision_bodies, 3);
    refresh_collision_body_centers();
    register_object_by_id();
    read_trigger_params();
    view_range = 400.0f;
    model_radius = 40.0f;
}
