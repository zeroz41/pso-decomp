#include "types.h"
#include <dolphin/base/PPCArch.h>
#include "pso/system/task/TMainTask.h"
#include "pso/object/mine/TOCapsuleMachine01.h"
#include "pso/render/TextureState.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/math/MatrixReflect.h"
#include "pso/player/LocalClientId.h"

// The game's frame counter (main's .sbss; no module header owns it yet).

const char *bm_fs_obj_cap_moto_model_names[] = {"fs_obj_cap_moto.gj", NULL};
const char *bm_fs_obj_cap_moto_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_cap_moto_resource_descriptor = {
    "bm_fs_obj_cap_moto.bml", bm_fs_obj_cap_moto_model_names, bm_fs_obj_cap_moto_motion_names, 1, 0,
};
CollisionBody capsule_machine01_collision_body[] = {
    {{0.0f, 32.5f, 0.0f}, 22.0f, 13.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOCapsuleMachine01_class_name = "TOCapsuleMachine01";
BmlResource *capsule_machine01_model_resource;
s32 lbl_805D58C4;
s32 capsule_machine01_last_update_frame_tick;
GinjaModel *capsule_machine_ginja_mesh_handle;

// Scrolls the capsule's light mesh once per frame, however many capsules
// stand on the floor.
void TOCapsuleMachine01::run_task() {
    if (capsule_machine01_last_update_frame_tick != actor_frame_tick) {
        capsule_machine01_last_update_frame_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(capsule_machine_ginja_mesh_handle, 0, 5, 4, 1);
        PPCSync();
    }
}

void TOCapsuleMachine01::render() {
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation.y);
        set_texture_list(texlist);
        draw_ginja_object(model);
        pop_matrix();
    }
}

void *TOCapsuleMachine01::create(ObjectSetData *set_data) {
    return new TOCapsuleMachine01(set_data);
}

void TOCapsuleMachine01::reset_static_state() {
    capsule_machine01_last_update_frame_tick = 0;
    lbl_805D58C4 = 0;
    if (capsule_machine01_model_resource != NULL) {
        delete capsule_machine01_model_resource;
        capsule_machine01_model_resource = NULL;
    }
}

void TOCapsuleMachine01::alloc_and_load_resource() {
    BmlResource *resource = new BmlResource(1, &bm_fs_obj_cap_moto_resource_descriptor, 0, 0, NULL);
    NJS_OBJECT *root;
    capsule_machine01_model_resource = resource;
    root = (NJS_OBJECT *)resource->models[0].model;
    capsule_machine_ginja_mesh_handle = root->child->sibling->child->sibling->ginja_model;
    capsule_machine01_last_update_frame_tick = 0;
}

TOCapsuleMachine01::~TOCapsuleMachine01() {
    free_collision_body_parts(this);
    unregister_object_by_id();
}

TOCapsuleMachine01::TOCapsuleMachine01(ObjectSetData *set_data) : TObjMapObject(tl_05) {
    m_name = TOCapsuleMachine01_class_name;
    apply_object_set_data(set_data);
    model = capsule_machine01_model_resource->models[0].model;
    texlist = capsule_machine01_model_resource->models[0].texlist;
    view_range = 500.0f;
    model_radius = 50.0f;
    actorFlags |= 0x40000000;
    init_collision_body_parts(this, capsule_machine01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}
