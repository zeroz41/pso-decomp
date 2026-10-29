#include "types.h"
#include "pso/TMainTask.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fd_obj_n_switch_model_names[] = {"fd_obj_n_switch.gj", NULL};
const char *bm_fd_obj_n_switch_motion_names[] = {"fd_obj_n_switch.njm", NULL};
BmlResourceDescriptor bm_fd_obj_n_switch_resource_descriptor = {
    "bm_fd_obj_n_switch.bml", bm_fd_obj_n_switch_model_names, bm_fd_obj_n_switch_motion_names, 1, 1,
};
CollisionBody key_ancient01_collision_body[] = {
    {{0.0f, 10.0f, 0.0f}, 3.0f, 5.0f, 1, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOKeyAncient01__class_name = "TOKeyAncient01";
BmlResource *TOKeyAncient01__shared_resource_object;
// The model's own texture list, then the b, g and p variants.
s32 *TOKeyAncient01__texture_lists;

void TOKeyAncient01::vfunc_25() {}

void TOKeyAncient01::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        if (is_on != 1) {
            draw_ginja_model_with_motion(model, motion, m_b0);
        } else {
            push_matrix();
            post_translate_matrix(((NJS_OBJECT *)model)->pos);
            rotate_matrix_z(NULL, ((NJS_OBJECT *)model)->ang[2]);
            rotate_matrix_x(NULL, ((NJS_OBJECT *)model)->ang[0]);
            rotate_matrix_y(NULL, ((NJS_OBJECT *)model)->ang[1]);
            draw_ginja_model((s32)((NJS_OBJECT *)model)->model);
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
    if (TOKeyAncient01__texture_lists != NULL) {
        for (s32 i = 1; i < 4; i++) {
            TObjPlayer::free_if_valid(TOKeyAncient01__texture_lists[i]);
        }
        if (TOKeyAncient01__texture_lists != NULL) {
            mem_free(TOKeyAncient01__texture_lists);
            TOKeyAncient01__texture_lists = NULL;
        }
    }
    if (TOKeyAncient01__shared_resource_object != NULL) {
        TLobby__sub_8001FE7C(TOKeyAncient01__shared_resource_object, 1);
        TOKeyAncient01__shared_resource_object = NULL;
    }
}

void TOKeyAncient01::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fd_obj_n_switch_resource_descriptor, 0, 0, 0);
    }
    TOKeyAncient01__shared_resource_object = resource;
    TOKeyAncient01__texture_lists = (s32 *)mem_alloc(0x10);
    TOKeyAncient01__texture_lists[0] = TOKeyAncient01__shared_resource_object->models[0].m_c;
    TOKeyAncient01__texture_lists[1] = (s32)load_gvm_texture_file((s32) "o_key_ancient01b.gvm");
    TOKeyAncient01__texture_lists[2] = (s32)load_gvm_texture_file((s32) "o_key_ancient01g.gvm");
    TOKeyAncient01__texture_lists[3] = (s32)load_gvm_texture_file((s32) "o_key_ancient01p.gvm");
}

TOKeyAncient01::~TOKeyAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOKeyAncient01::TOKeyAncient01(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = TOKeyAncient01__class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    if (set_params[1] < 0) {
        set_params[1] = 0;
    } else if (set_params[1] > 3) {
        set_params[1] = 3;
    }
    texlist = TOKeyAncient01__texture_lists[set_params[1]];
    model = (void *)TOKeyAncient01__shared_resource_object->models[0].model;
    motion = TOKeyAncient01__shared_resource_object->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = 0.99f;
    init_collision_body_parts(this, key_ancient01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    m_c0 = 400.0f;
    model_radius = 40.0f;
    if (mode != KEY_MODE_NONE && scale.x < 0.0f) {
        mode = KEY_MODE_TOGGLE;
    } else {
        mode = KEY_MODE_ONCE;
    }
}
