#include "types.h"
#include <dolphin/base/PPCArch.h>
#include "pso/TMainTask.h"
#include "pso/misc/TOCapsuleMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

// The game's frame counter (main's .sbss; no module header owns it yet).
extern s32 actor_frame_tick;

const char *bm_fs_obj_cap_moto_model_names[] = {"fs_obj_cap_moto.gj", NULL};
const char *bm_fs_obj_cap_moto_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_cap_moto_resource_descriptor = {
    "bm_fs_obj_cap_moto.bml", bm_fs_obj_cap_moto_model_names, bm_fs_obj_cap_moto_motion_names, 1, 0,
};
CollisionBody capsule_machine01_collision_body[] = {
    {{0.0f, 32.5f, 0.0f}, 22.0f, 13.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOCapsuleMachine01_class_name = "TOCapsuleMachine01";
BmlResource *TOCapsuleMachine01__model_resource;
s32 lbl_805D58C4;
s32 TOCapsuleMachine01__last_update_frame_tick;
void *capsule_machine_ginja_mesh_handle;

// Scrolls the capsule's light mesh once per frame, however many capsules
// stand on the floor.
void TOCapsuleMachine01::run_task() {
    if (TOCapsuleMachine01__last_update_frame_tick != actor_frame_tick) {
        TOCapsuleMachine01__last_update_frame_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(capsule_machine_ginja_mesh_handle, 0, 5, 4, 1);
        PPCSync();
    }
}

void TOCapsuleMachine01::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_object(model);
        pop_matrix();
    }
}

void *TOCapsuleMachine01::create(void *set_data) {
    return new TOCapsuleMachine01(set_data);
}

void TOCapsuleMachine01::reset_static_state() {
    TOCapsuleMachine01__last_update_frame_tick = 0;
    lbl_805D58C4 = 0;
    if (TOCapsuleMachine01__model_resource != NULL) {
        TLobby__sub_8001FE7C(TOCapsuleMachine01__model_resource, 1);
        TOCapsuleMachine01__model_resource = NULL;
    }
}

void TOCapsuleMachine01::alloc_and_load_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    NJS_OBJECT *root;
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_cap_moto_resource_descriptor, 0, 0, 0);
    }
    TOCapsuleMachine01__model_resource = resource;
    root = (NJS_OBJECT *)resource->models[0].model;
    capsule_machine_ginja_mesh_handle = root->child->sibling->child->sibling->model;
    TOCapsuleMachine01__last_update_frame_tick = 0;
}

TOCapsuleMachine01::~TOCapsuleMachine01() {
    free_collision_body_parts(this);
    unregister_object_by_id();
}

TOCapsuleMachine01::TOCapsuleMachine01(void *set_data) : TObjMapObject(tl_05) {
    m_name = TOCapsuleMachine01_class_name;
    apply_object_set_data(set_data);
    model = (void *)TOCapsuleMachine01__model_resource->models[0].model;
    texlist = TOCapsuleMachine01__model_resource->models[0].m_c;
    m_c0 = 500.0f;
    model_radius = 50.0f;
    actorFlags |= 0x40000000;
    init_collision_body_parts(this, capsule_machine01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}
