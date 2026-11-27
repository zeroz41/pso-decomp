#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/key/TOKeyAncient01.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/math/MatrixReflect.h"

const char *bm_fd_obj_n_switch_model_names[] = {"fd_obj_n_switch.gj", NULL};
const char *bm_fd_obj_n_switch_motion_names[] = {"fd_obj_n_switch.njm", NULL};
BmlResourceDescriptor bm_fd_obj_n_switch_resource_descriptor = {
    "bm_fd_obj_n_switch.bml", bm_fd_obj_n_switch_model_names, bm_fd_obj_n_switch_motion_names, 1, 1,
};
CollisionBody key_ancient01_collision_body[] = {
    {{0.0f, 10.0f, 0.0f}, 3.0f, 5.0f, 1, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *key_ancient01_class_name = "TOKeyAncient01";
BmlResource *key_ancient01_shared_resource_object;
// The model's own texture list, then the b, g and p variants.
struct NJS_TEXLIST;

NJS_TEXLIST **key_ancient01_texture_lists;

void TOKeyAncient01::vfunc_25() {}

void TOKeyAncient01::render() {
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        set_texture_list(texlist);
        if (is_on != 1) {
            draw_ginja_model_with_motion(model, motion, animation_frame);
        } else {
            push_matrix();
            post_translate_matrix(model->pos);
            rotate_matrix_z(NULL, model->ang[2]);
            rotate_matrix_x(NULL, model->ang[0]);
            rotate_matrix_y(NULL, model->ang[1]);
            draw_ginja_model(model->model);
            pop_matrix();
        }
        pop_matrix();
    }
}

void TOKeyAncient01::update_switch_off() {
    update_anim_phase();
    submit_cursor_target();
}

void TOKeyAncient01::update_switch_on() {
    submit_cursor_target();
}

void *TOKeyAncient01::create(void *set_data) {
    return new TOKeyAncient01(tl_05, set_data);
}

void TOKeyAncient01::free_shared_resources() {
    if (key_ancient01_texture_lists != NULL) {
        for (s32 i = 1; i < 4; i++) {
            TObjPlayer::free_if_valid(key_ancient01_texture_lists[i]);
        }
        if (key_ancient01_texture_lists != NULL) {
            mem_free(key_ancient01_texture_lists);
            key_ancient01_texture_lists = NULL;
        }
    }
    if (key_ancient01_shared_resource_object != NULL) {
        delete key_ancient01_shared_resource_object;
        key_ancient01_shared_resource_object = NULL;
    }
}

void TOKeyAncient01::load_resources() {
    BmlResource *resource = new BmlResource(1, &bm_fd_obj_n_switch_resource_descriptor, 0, 0, NULL);
    key_ancient01_shared_resource_object = resource;
    key_ancient01_texture_lists = (NJS_TEXLIST **)mem_alloc(4 * sizeof(*key_ancient01_texture_lists));
    key_ancient01_texture_lists[0] = key_ancient01_shared_resource_object->models[0].texlist;
    key_ancient01_texture_lists[1] = LoadPvmFileTls("o_key_ancient01b.gvm");
    key_ancient01_texture_lists[2] = LoadPvmFileTls("o_key_ancient01g.gvm");
    key_ancient01_texture_lists[3] = LoadPvmFileTls("o_key_ancient01p.gvm");
}

TOKeyAncient01::~TOKeyAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOKeyAncient01::TOKeyAncient01(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = key_ancient01_class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    if (set_params[1] < 0) {
        set_params[1] = 0;
    } else if (set_params[1] > 3) {
        set_params[1] = 3;
    }
    texlist = key_ancient01_texture_lists[set_params[1]];
    model = key_ancient01_shared_resource_object->models[0].model;
    motion = key_ancient01_shared_resource_object->motions[0].motion;
    animation_end_frame = (f32)motion->nbFrame - 1.0f;
    animation_step = 0.99f;
    init_collision_body_parts(this, key_ancient01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    view_range = 400.0f;
    model_radius = 40.0f;
    if (mode != KEY_MODE_NONE && scale.x < 0.0f) {
        mode = KEY_MODE_TOGGLE;
    } else {
        mode = KEY_MODE_ONCE;
    }
}
