#include "types.h"
#include "pso/misc/TOComputerMachine01.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/NinjaUtil.h"
#include "pso/unk/text_803D8F74.h"

// TCameraCtrl.h does not declare the instance yet: 28 files that include it
// still redeclare it with their own types.
extern TCameraCtrl *camera_ctrl_instance;

const char *bm_fs_obj_kenkyu_com_model_names[2] = { "fs_obj_kenkyu_com.gj", NULL };
const char *bm_fs_obj_kenkyu_com_motion_names[1] = { NULL };
BmlResourceDescriptor bm_fs_obj_kenkyu_com_resource_descriptor = {
    "bm_fs_obj_kenkyu_com.bml", bm_fs_obj_kenkyu_com_model_names, bm_fs_obj_kenkyu_com_motion_names, 1, 0
};
CollisionBody computer_machine01_collision_body = {
    { 0.0f, 15.0f, 0.0f }, 9.0f, 24.0f, 1, 0x30003, { 0.0f, 0.0f, 0.0f }, 0.0f
};
const char *TOComputerMachine01::class_name = "TOComputerMachine01";
BmlResource *TOComputerMachine01::model_resource;
s32 TOComputerMachine01::last_scroll_frame;
void *TOComputerMachine01::screen_meshes[4];

s32 TOComputerMachine01::update_object_view_visibility(f32 range, f32 radius) {
    if (xz_distance_squared(&position, (Vec *)&camera_ctrl_instance->m_178) < radius * radius) {
        visibility = 1;
        return visibility;
    }
    return TObjMapObject::update_object_view_visibility(range, radius);
}

void TOComputerMachine01::render() {
    NJS_OBJECT *body;
    NJS_OBJECT *screen;
    visible = update_object_view_visibility(m_c0, model_radius);
    if (visible == 1) {
        if (last_scroll_frame != actor_frame_tick) {
            last_scroll_frame = actor_frame_tick;
            scroll_ginja_mesh_uvs(screen_meshes[0], 0, 2, 7, 1);
            scroll_ginja_mesh_uvs(screen_meshes[1], 0, -2, 7, 1);
            scroll_ginja_mesh_uvs(screen_meshes[2], 0, 1, 7, 1);
            scroll_ginja_mesh_uvs(screen_meshes[3], 0, -1, 7, 1);
        }
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        body = (NJS_OBJECT *)model;
        draw_ginja_model((s32)body->model);
        TParticleCtrl::begin_effect_render();
        screen = body->child;
        draw_ginja_model((s32)screen->model);
        screen = screen->sibling;
        draw_ginja_model((s32)screen->model);
        screen = screen->sibling;
        draw_ginja_model((s32)screen->model);
        draw_ginja_model((s32)screen->sibling->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOComputerMachine01::create(void *set_data) {
    return new TOComputerMachine01(set_data);
}

void TOComputerMachine01::unload_resources() {
    s32 i;
    last_scroll_frame = 0;
    for (i = 0; i < 4; i++) {
        screen_meshes[i] = NULL;
    }
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TOComputerMachine01::load_resources() {
    NJS_OBJECT *screen;
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_kenkyu_com_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
    screen = ((NJS_OBJECT *)resource->models->model)->child;
    screen_meshes[3] = screen->model;
    screen_meshes[2] = screen->sibling->model;
    screen_meshes[1] = screen->sibling->sibling->model;
    screen_meshes[0] = screen->sibling->sibling->sibling->model;
    last_scroll_frame = 0;
}

TOComputerMachine01::~TOComputerMachine01() {
    free_collision_body_parts(this);
    unregister_object_by_id();
}

TOComputerMachine01::TOComputerMachine01(void *set_data) : TUnk_804B27D8(tl_05) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)model_resource->models->model;
    texlist = model_resource->models->m_c;
    m_c0 = 500.0f;
    model_radius = 50.0f;
    actorFlags |= 0x40000000;
    init_collision_body_parts(this, &computer_machine01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    read_set_params();
}

// The base's empty animation step (see TUnk_804B27D8.h): this TU is the
// first in link order whose vtable uses it.
void TUnk_804B27D8::animate() {}
