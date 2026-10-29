#include "types.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/MatrixVector.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TOKeyAncient02.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaModel.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_o_doorswitch01_model_names[] = {"ds_obj_o_doorswitch01_glass.gj", "fs_obj_o_doorswitch01.gj", NULL};
const char *bm_fs_obj_o_doorswitch01_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_o_doorswitch01_resource_descriptor = {
    "bm_fs_obj_o_doorswitch01.bml", bm_fs_obj_o_doorswitch01_model_names, bm_fs_obj_o_doorswitch01_motion_names, 2, 0,
};
CollisionBody key_ancient02_collision_body[] = {
    {{0.0f, 10.0f, 0.0f}, 3.0f, 0.0f, 0, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOKeyAncient02__class_name = "TOKeyAncient02";
BmlResource *TOKeyAncient02__model_archive;
NJS_OBJECT *TOKeyAncient02__glass_model;
// The glass's own texture list while off, o_key_ancient02.gvm while on.
s32 *TOKeyAncient02__texture_lists;

void TOKeyAncient02::vfunc_25() {}

void TOKeyAncient02::render() {
    NJS_OBJECT *object;

    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        object = (NJS_OBJECT *)model;
        push_matrix();
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        object = object->child;
        push_matrix();
        post_translate_matrix(object->pos);
        scale_matrix_vec3(NULL, (u8 *)&scale);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((s32)object->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        object = object->sibling;
        push_matrix();
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        pop_matrix();
        TObjFish::set_global_param(TOKeyAncient02__texture_lists[is_on]);
        TParticleCtrl::begin_effect_render();
        object = TOKeyAncient02__glass_model;
        push_matrix();
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        object = object->child;
        push_matrix();
        post_translate_matrix(object->pos);
        rotate_matrix_y(NULL, lamp_angle);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TOKeyAncient02::update_switch_off() {
    if (pulse_flags & 1) {
        scale.y += 0.01f;
        scale.x += 0.05f;
        scale.z = scale.x;
        if (1.1f <= scale.y) {
            pulse_flags &= ~1;
        }
    } else {
        scale.y -= 0.01f;
        scale.x -= 0.05f;
        scale.z = scale.x;
        if (scale.y <= 1.0f) {
            pulse_flags |= 1;
        }
    }
    lamp_angle += 0x222;
    submit_cursor_target();
}

void TOKeyAncient02::update_switch_on() {
    if (pulse_flags & 1) {
        scale.y += 0.01f;
        scale.x += 0.05f;
        scale.z = scale.x;
        if (1.1f <= scale.y) {
            pulse_flags &= ~1;
        }
    } else {
        scale.y -= 0.01f;
        scale.x -= 0.05f;
        scale.z = scale.x;
        if (scale.y <= 1.0f) {
            pulse_flags |= 1;
        }
    }
    lamp_angle += 0x444;
    submit_cursor_target();
}

void *TOKeyAncient02::create(void *set_data) {
    return new TOKeyAncient02(tl_05, set_data);
}

void TOKeyAncient02::free_static() {
    if (TOKeyAncient02__texture_lists != NULL) {
        TObjPlayer::free_if_valid(TOKeyAncient02__texture_lists[1]);
        if (TOKeyAncient02__texture_lists != NULL) {
            mem_free(TOKeyAncient02__texture_lists);
            TOKeyAncient02__texture_lists = NULL;
        }
    }
    if (TOKeyAncient02__model_archive != NULL) {
        TLobby__sub_8001FE7C(TOKeyAncient02__model_archive, 1);
        TOKeyAncient02__model_archive = NULL;
    }
    TOKeyAncient02__glass_model = NULL;
}

void TOKeyAncient02::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_o_doorswitch01_resource_descriptor, 0, 0, 0);
    }
    TOKeyAncient02__model_archive = resource;
    TOKeyAncient02__texture_lists = (s32 *)mem_alloc(8);
    TOKeyAncient02__texture_lists[0] = TObjFish__sub_8001EDB0(TOKeyAncient02__model_archive, 0);
    TOKeyAncient02__texture_lists[1] = (s32)load_gvm_texture_file((s32) "o_key_ancient02.gvm");
    TOKeyAncient02__glass_model = (NJS_OBJECT *)get_bml_model(TOKeyAncient02__model_archive, 0);
}

TOKeyAncient02::~TOKeyAncient02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOKeyAncient02::TOKeyAncient02(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = TOKeyAncient02__class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    model = (void *)get_bml_model(TOKeyAncient02__model_archive, 1);
    texlist = TObjFish__sub_8001EDB0(TOKeyAncient02__model_archive, 1);
    init_collision_body_parts(this, key_ancient02_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    m_c0 = 400.0f;
    model_radius = 50.0f + ((GinjaModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    pulse_flags = 0;
    lamp_angle = 0;
    if (mode != KEY_MODE_NONE && set_params[1] < 0) {
        mode = KEY_MODE_TOGGLE;
    } else {
        mode = KEY_MODE_ONCE;
    }
    scale.z = 1.0f;
    scale.y = 1.0f;
    scale.x = 1.0f;
}
