#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/map/FloorArea.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/key/TOKeyGenericSw.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/TObjCharaHelpers.h"

const char *fs_obj_hanyousu_body1_model_names[] = {"fs_obj_hanyousu_body1.gj", NULL};
const char *fs_obj_hanyousu_body1_motion_names[] = {NULL};
BmlResourceDescriptor fs_obj_hanyousu_body1_resource_descriptor = {
    "fs_obj_hanyousu_body1.bml", fs_obj_hanyousu_body1_model_names, fs_obj_hanyousu_body1_motion_names, 1, 0,
};
const char *fs_obj_hanyousu_light_model_names[] = {"fs_obj_hanyousu_light.gj", NULL};
const char *fs_obj_hanyousu_light_motion_names[] = {"fs_obj_hanyousu_light.njm", NULL};
BmlResourceDescriptor fs_obj_hanyousu_light_resource_descriptor = {
    "fs_obj_hanyousu_light.bml", fs_obj_hanyousu_light_model_names, fs_obj_hanyousu_light_motion_names, 1, 1,
};
const char *fs_obj_hanyousu_body1_j_model_names[] = {"fs_obj_hanyousu_body1.gj", NULL};
const char *fs_obj_hanyousu_body1_j_motion_names[] = {NULL};
BmlResourceDescriptor fs_obj_hanyousu_body1_j_resource_descriptor = {
    "fs_obj_hanyousu_body1_j.bml", fs_obj_hanyousu_body1_j_model_names, fs_obj_hanyousu_body1_j_motion_names, 1, 0,
};
const char *fs_obj_hanyousu_light_j_model_names[] = {"fs_obj_hanyousu_light.gj", NULL};
const char *fs_obj_hanyousu_light_j_motion_names[] = {"fs_obj_hanyousu_light.njm", NULL};
BmlResourceDescriptor fs_obj_hanyousu_light_j_resource_descriptor = {
    "fs_obj_hanyousu_light_j.bml", fs_obj_hanyousu_light_j_model_names, fs_obj_hanyousu_light_j_motion_names, 1, 1,
};
CollisionBody key_generic_sw_collision_body[] = {
    {{0.0f, 10.0f, 0.0f}, 5.0f, 5.0f, 0, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *key_generic_sw_name = "TOKeyGenericSw";
// The body and the light.
BmlResource *key_generic_sw_shared_resource_ptrs[2];
// The body's texture list, the light's, then light_ao for the lit light.
struct NJS_TEXLIST;

NJS_TEXLIST **key_generic_sw_texture_lists;

void TOKeyGenericSw::vfunc_25() {}

void TOKeyGenericSw::render() {
    if (update_object_view_visibility(view_range, model_radius) == 0) {
        return;
    }
    push_matrix();
    texlist = key_generic_sw_texture_lists[0];
    model = key_generic_sw_shared_resource_ptrs[0]->models[0].model;
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    set_texture_list(texlist);
    draw_ginja_object(model);
    pop_matrix();
    TParticleCtrl::begin_effect_render();
    push_matrix();
    switch (is_on) {
    case 0:
        texlist = key_generic_sw_texture_lists[1];
        break;
    case 1:
        texlist = key_generic_sw_texture_lists[2];
        break;
    }
    model = key_generic_sw_shared_resource_ptrs[1]->models[0].model;
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    set_texture_list(texlist);
    draw_ginja_model_with_motion(model, motion, animation_frame);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TOKeyGenericSw::update_switch_off() {
    update_anim_phase();
    submit_cursor_target();
    off_state = 1;
    on_state = 0;
    on_state_copy = 0;
    off_state_copy = off_state;
}

void TOKeyGenericSw::update_switch_on() {
    update_anim_phase();
    submit_cursor_target();
    on_state = 1;
    off_state = 0;
    off_state_copy = 0;
    on_state_copy = on_state;
}

void *TOKeyGenericSw::create(void *set_data) {
    return new TOKeyGenericSw(tl_05, set_data);
}

void TOKeyGenericSw::free_shared_resources() {
    if (key_generic_sw_texture_lists != NULL) {
        TObjPlayer::free_if_valid((saddr)key_generic_sw_texture_lists[2]);
        if (key_generic_sw_texture_lists != NULL) {
            mem_free(key_generic_sw_texture_lists);
            key_generic_sw_texture_lists = NULL;
        }
    }
    if (key_generic_sw_shared_resource_ptrs[1] != NULL) {
        delete (BmlResource *)key_generic_sw_shared_resource_ptrs[1];
        key_generic_sw_shared_resource_ptrs[1] = NULL;
    }
    if (key_generic_sw_shared_resource_ptrs[0] != NULL) {
        delete (BmlResource *)key_generic_sw_shared_resource_ptrs[0];
        key_generic_sw_shared_resource_ptrs[0] = NULL;
    }
}

void TOKeyGenericSw::load_resources() {
    s32 area = get_current_floor_area();
    BmlResource *resource;

    if (TContainerAncient01::is_global_state_in_table() == 1 || area == AREA_SEABED_UPPER || area == AREA_SEABED_LOWER) {
        resource = new BmlResource(1, &fs_obj_hanyousu_body1_j_resource_descriptor, 0, 0, NULL);
        key_generic_sw_shared_resource_ptrs[0] = resource;
        resource = new BmlResource(1, &fs_obj_hanyousu_light_j_resource_descriptor, 0, 0, NULL);
        key_generic_sw_shared_resource_ptrs[1] = resource;
        key_generic_sw_texture_lists = (NJS_TEXLIST **)mem_alloc(3 * sizeof(*key_generic_sw_texture_lists));
        key_generic_sw_texture_lists[0] = key_generic_sw_shared_resource_ptrs[0]->models[0].texlist;
        key_generic_sw_texture_lists[1] = key_generic_sw_shared_resource_ptrs[1]->models[0].texlist;
        key_generic_sw_texture_lists[2] = LoadPvmFileTls("fs_obj_hanyousu_light_ao_j.GVM");
    } else {
        resource = new BmlResource(1, &fs_obj_hanyousu_body1_resource_descriptor, 0, 0, NULL);
        key_generic_sw_shared_resource_ptrs[0] = resource;
        resource = new BmlResource(1, &fs_obj_hanyousu_light_resource_descriptor, 0, 0, NULL);
        key_generic_sw_shared_resource_ptrs[1] = resource;
        key_generic_sw_texture_lists = (NJS_TEXLIST **)mem_alloc(3 * sizeof(*key_generic_sw_texture_lists));
        key_generic_sw_texture_lists[0] = key_generic_sw_shared_resource_ptrs[0]->models[0].texlist;
        key_generic_sw_texture_lists[1] = key_generic_sw_shared_resource_ptrs[1]->models[0].texlist;
        key_generic_sw_texture_lists[2] = LoadPvmFileTls("fs_obj_hanyousu_light_ao.GVM");
    }
}

TOKeyGenericSw::~TOKeyGenericSw() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOKeyGenericSw::TOKeyGenericSw(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = key_generic_sw_name;
    apply_object_set_data(set_data);
    init_switch_id();
    model = key_generic_sw_shared_resource_ptrs[1]->models[0].model;
    motion = key_generic_sw_shared_resource_ptrs[1]->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 2.0f;
    texlist = key_generic_sw_texture_lists[1];
    init_collision_body_parts(this, key_generic_sw_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    view_range = 400.0f;
    model_radius = 40.0f;
    if (mode != KEY_MODE_NONE && scale.x < 0.0f) {
        mode = KEY_MODE_TOGGLE;
    } else {
        mode = KEY_MODE_ONCE;
    }
    floor_area = get_current_floor_area();
    on_state = 0;
    on_state_copy = 0;
    off_state = 0;
    off_state_copy = 0;
}
