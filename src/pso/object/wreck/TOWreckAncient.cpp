#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjChip.h"
#include "pso/object/wreck/TOWreckAncient.h"
#include "pso/object/wreck/TOWreckAncient01.h"
#include "pso/object/wreck/TOWreckAncient04.h"
#include "pso/object/wreck/TOWreckAncient05.h"
#include "pso/object/wreck/TOWreckAncient06.h"
#include "pso/object/wreck/TOWreckAncient07.h"
#include "pso/object/wreck/TOWreckAncientBrakable.h"
#include "pso/object/wreck/TOWreckAncientBrakable05.h"
#include "pso/object/wreck/TOWreckAncientBrakable_8017D444.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801542CC.h"

// The wreck family is one TU built with -inline off,deferred: its code runs Brakable05, Brakable, 07, 06, 05,
// 04, 01, TOWreckAncient while its strings, name pointers and vtables run the other way, so the source is
// written last function first.

struct Vec_8017D448 { f32 x, y, z; };

struct Arr_8017D448 { Vec_8017D448 v[9]; };

// Same layout as TObjChipParams (TObjChip.h).
struct Param_8017D448 {
    f32 f0;
    f32 f4;
    f32 f8;
    Vec_8017D448 pos;
    f32 f18[3];
    s32 f24[3];
    s32 f30[2];
    f32 f38;
    f32 f3c;
    s32 f40;
    s32 f44;
    s32 f48;
};

const char *bm_o_wreck_ancient_model_names[8] = {
    "fe_obj_o_zangai02.gj",
    "fe_obj_o_zangai01.gj",
    "fe_obj_o_zangai03.gj",
    "fe_obj_o_zangai05.gj",
    "fe_obj_o_zangai04.gj",
    "fe_obj_o_zangai07.gj",
    "fe_obj_o_zangai06.gj",
    NULL,
};
const char *bm_o_wreck_ancient_motion_names[1] = {NULL};
BmlResourceDescriptor bm_o_wreck_ancient_resource_descriptor = {
    "bm_o_wreck_ancient.bml", bm_o_wreck_ancient_model_names, bm_o_wreck_ancient_motion_names, 7, 0,
};
const char *bm_fe_obj_o_hahen_model_names[10] = {
    "fe_obj_o_hahen01.gj",
    "fe_obj_o_hahen02.gj",
    "fe_obj_o_hahen03.gj",
    "fe_obj_o_hahen04.gj",
    "fe_obj_o_hahen05.gj",
    "fe_obj_o_hahen06.gj",
    "fe_obj_o_hahen07.gj",
    "fe_obj_o_hahen08.gj",
    "fe_obj_o_hahen09.gj",
    NULL,
};
const char *bm_fe_obj_o_hahen_motion_names[1] = {NULL};
BmlResourceDescriptor TOWreckAncient__resource_descriptor = {
    "bm_fe_obj_o_hahen.bml", bm_fe_obj_o_hahen_model_names, bm_fe_obj_o_hahen_motion_names, 9, 0,
};
const char *TOWreckAncient__name = "TOWreckAncient";

// One sphere per wreck model: the subclass passes its model's entry (TOWreckAncient02/03 use it too).
CollisionBody TOWreckAncient__collision_body_templates[7] = {
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 12.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 30.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 17.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 23.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 18.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x10003 },
};

const char *TOWreckAncient01__name = "TOWreckAncient01";
const char *TOWreckAncient04__name = "TOWreckAncient04";
const char *TOWreckAncient05__name = "TOWreckAncient05";
const char *TOWreckAncient06__name = "TOWreckAncient06";
const char *TOWreckAncient07__name = "TOWreckAncient07";
const char *TOWreckAncientBrakable__name = "TOWreckAncientBrakable";
const char *TOWreckAncientBrakable05__name = "TOWreckAncientBrakable05";

const Arr_8017D448 TOWreckAncientBrakable__debris_table = {
    {
        { -7.0f, 12.0f, 9.0f },
        { 0.0f, 25.0f, -5.0f },
        { -8.0f, 12.0f, -6.0f },
        { -8.0f, 27.0f, 5.0f },
        { 8.0f, 14.0f, -6.0f },
        { 8.0f, 15.0f, 9.0f },
        { 4.0f, 30.0f, 9.0f },
        { -7.0f, 32.0f, 4.0f },
        { 3.0f, 29.0f, -1.0f },
    }
};

const Param_8017D448 TOWreckAncientBrakable__debris_param_table = {
    0.25f, 0.07f, 0.26f,
    { 0.0f, 0.0f, 0.0f },
    { 5.0f, 7.5f, 5.0f },
    { 0x400, 0x100, 0x400 },
    { 1, 30 },
    0.0f, 0.6f,
    0, 0, 30,
};

u32 wreck_ancient_bml_resource;
u32 wreck_ancient_brakable_bml_resource;

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void free_bin_model_request(void*, int);
s32 post_translate_matrix(void *);
s32 push_matrix();
void vec3_add_to(Vec_8017D448 *, Vec_8017D448 *);
void rotate_vector_by_matrix(int, Vec_8017D448 *, Vec_8017D448 *);
extern u8 identity_matrix[];
u8 is_current_floor_switch_set(u16);
}

// --- TOWreckAncient ---

TOWreckAncient::TOWreckAncient(s32 model_index) : TObjCollidable(tl_05) {
    m_name = TOWreckAncient__name;
    model = (void *)get_bml_model((void *)wreck_ancient_bml_resource, model_index);
    texlist = TObjFish__sub_8001EDB0((void *)wreck_ancient_bml_resource, model_index);
    view_far_depth = 400.0f;
    view_radius = 40.0f;
}

TOWreckAncient::~TOWreckAncient() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOWreckAncient::load_resources() {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_o_wreck_ancient_resource_descriptor, 0, 0, 0));
    }
    wreck_ancient_bml_resource = var_r0;
    temp_r3_2 = (int)::operator new(0x440);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = (long) (load_resource_from_descriptor((void *) temp_r3_2, 1, &TOWreckAncient__resource_descriptor, 0, 0, 0));
    }
    wreck_ancient_brakable_bml_resource = var_r0_2;
}

void TOWreckAncient::free_statics() {
    if (wreck_ancient_bml_resource != 0U) {
        free_bin_model_request((void*)wreck_ancient_bml_resource, 1);
        wreck_ancient_bml_resource = 0U;
    }
    if (wreck_ancient_brakable_bml_resource != 0U) {
        free_bin_model_request((void*)wreck_ancient_brakable_bml_resource, 1);
        wreck_ancient_brakable_bml_resource = 0U;
    }
}

void TOWreckAncient::render() {
    if (update_object_view_visibility(view_far_depth, view_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_object(model);
        pop_matrix();
    }
}

// --- TOWreckAncient01 ---

TOWreckAncient01::TOWreckAncient01(void *set_data) : TOWreckAncient(1) {
    m_name = TOWreckAncient01__name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient__collision_body_templates[1], 1);
    register_object_by_id();
}

TOWreckAncient01::~TOWreckAncient01() {
}

void *TOWreckAncient01__create(void *set_data) {
    return new TOWreckAncient01(set_data);
}

// --- TOWreckAncient04 ---

TOWreckAncient04::TOWreckAncient04(void *set_data) : TOWreckAncient(4) {
    m_name = TOWreckAncient04__name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient__collision_body_templates[4], 1);
    register_object_by_id();
}

TOWreckAncient04::~TOWreckAncient04() {
}

void *TOWreckAncient04__create(void *set_data) {
    return new TOWreckAncient04(set_data);
}

// --- TOWreckAncient05 ---

TOWreckAncient05::TOWreckAncient05(void *set_data) : TOWreckAncient(3) {
    m_name = TOWreckAncient05__name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient__collision_body_templates[3], 1);
    register_object_by_id();
}

TOWreckAncient05::~TOWreckAncient05() {
}

void *TOWreckAncient05__create(void *set_data) {
    return new TOWreckAncient05(set_data);
}

// --- TOWreckAncient06 ---

TOWreckAncient06::TOWreckAncient06(void *set_data) : TOWreckAncient(6) {
    m_name = TOWreckAncient06__name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient__collision_body_templates[6], 1);
    register_object_by_id();
}

TOWreckAncient06::~TOWreckAncient06() {
}

void *TOWreckAncient06__create(void *set_data) {
    return new TOWreckAncient06(set_data);
}

// --- TOWreckAncient07 ---

TOWreckAncient07::TOWreckAncient07(void *set_data) : TOWreckAncient(5) {
    m_name = TOWreckAncient07__name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient__collision_body_templates[5], 1);
    register_object_by_id();
}

TOWreckAncient07::~TOWreckAncient07() {
}

void *TOWreckAncient07__create(void *set_data) {
    return new TOWreckAncient07(set_data);
}

// --- TOWreckAncientBrakable ---


TOWreckAncientBrakable::TOWreckAncientBrakable(s32 model_index) : TOWreckAncient(model_index) {
    m_name = TOWreckAncientBrakable__name;
    state = 0;
    switch_id = -1;
}

TOWreckAncientBrakable::~TOWreckAncientBrakable() {
}

void TOWreckAncientBrakable::run_task() {
    s32 temp_r0_2;

    if (TObjPlayer::check_demo_mode() == 1) {
        TOWreckAncientBrakable__sub_8017D444(this);
        return;
    }
    switch (state) {
    default:
        state = 0;
    case 0:
        temp_r0_2 = switch_id;
        if ((temp_r0_2 >= 0) && (temp_r0_2 < 0x100) && (is_current_floor_switch_set((u16) temp_r0_2) == 1)) {
            state = 1;
            play_sound_effect(0x43C11, (u8 *)&this->position, 0, 0);
            spawn_particle_effect(&this->position, 0x45);
            spawn_particle_effect(&this->position, 0x46);
            spawn_debris();
        }
        return;
    case 1:
        set_flag8();
        queue_destruction();
        break;
    }
}

void TOWreckAncientBrakable::spawn_debris() {
    Vec_8017D448 tmp;
    Arr_8017D448 arr = TOWreckAncientBrakable__debris_table;
    Param_8017D448 p = TOWreckAncientBrakable__debris_param_table;
    s32 i;
    p.pos.x = position.x;
    p.pos.y = position.y;
    p.pos.z = position.z;
    p.f38 = p.pos.y;
    for (i = 0; i < 9; i++) {
        VecCopy((Vec *)&tmp, (const Vec *)&arr.v[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, rotation_y);
        rotate_vector_by_matrix(0, &tmp, &tmp);
        pop_matrix();
        VecCopy((Vec *)&p.pos, &position);
        vec3_add_to(&p.pos, &tmp);
        p.f40 = get_bml_model((void *) wreck_ancient_brakable_bml_resource, i);
        p.f44 = TObjFish__sub_8001EDB0((void *) wreck_ancient_brakable_bml_resource, i);
        new TObjChip(tl_05, (const TObjChipParams *)&p);
    }
}

void TOWreckAncientBrakable__sub_8017D444(void *) {  }


// --- TOWreckAncientBrakable05 ---

TOWreckAncientBrakable05::TOWreckAncientBrakable05(void *set_data) : TOWreckAncientBrakable(3) {
    m_name = TOWreckAncientBrakable05__name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient__collision_body_templates[3], 1);
    register_object_by_id();
    switch_id = set_params[0];
    if (switch_id < 0 || switch_id >= 0x100) {
        switch_id = -1;
    }
}

TOWreckAncientBrakable05::~TOWreckAncientBrakable05() {
}

void *TOWreckAncientBrakable05__create(void *set_data) {
    return new TOWreckAncientBrakable05(set_data);
}
