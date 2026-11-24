#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjChip.h"
#include "pso/object/wreck/TOWreckAncient.h"
#include "pso/object/wreck/TOWreckAncientResources.h"
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
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"

// The wreck family is one TU built with -inline off,deferred: its code runs Brakable05, Brakable, 07, 06, 05,
// 04, 01, TOWreckAncient while its strings, name pointers and vtables run the other way, so the source is
// written last function first.

static __declspec(section ".rodata") const char wreck_model_02[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_zangai02.gj";
static __declspec(section ".rodata") const char wreck_model_01[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_zangai01.gj";
static __declspec(section ".rodata") const char wreck_model_03[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_zangai03.gj";
static __declspec(section ".rodata") const char wreck_model_05[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_zangai05.gj";
static __declspec(section ".rodata") const char wreck_model_04[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_zangai04.gj";
static __declspec(section ".rodata") const char wreck_model_07[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_zangai07.gj";
static __declspec(section ".rodata") const char wreck_model_06[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_zangai06.gj";
static __declspec(section ".rodata") const char wreck_archive[] ATTRIBUTE_ALIGN(4) = "bm_o_wreck_ancient.bml";
static __declspec(section ".rodata") const char debris_model_01[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen01.gj";
static __declspec(section ".rodata") const char debris_model_02[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen02.gj";
static __declspec(section ".rodata") const char debris_model_03[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen03.gj";
static __declspec(section ".rodata") const char debris_model_04[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen04.gj";
static __declspec(section ".rodata") const char debris_model_05[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen05.gj";
static __declspec(section ".rodata") const char debris_model_06[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen06.gj";
static __declspec(section ".rodata") const char debris_model_07[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen07.gj";
static __declspec(section ".rodata") const char debris_model_08[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen08.gj";
static __declspec(section ".rodata") const char debris_model_09[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_hahen09.gj";
static __declspec(section ".rodata") const char debris_archive[] ATTRIBUTE_ALIGN(4) = "bm_fe_obj_o_hahen.bml";

const char *bm_o_wreck_ancient_model_names[8] = {
    wreck_model_02,
    wreck_model_01,
    wreck_model_03,
    wreck_model_05,
    wreck_model_04,
    wreck_model_07,
    wreck_model_06,
    NULL,
};
const char *bm_o_wreck_ancient_motion_names[1] = {NULL};
BmlResourceDescriptor bm_o_wreck_ancient_resource_descriptor = {
    wreck_archive, bm_o_wreck_ancient_model_names, bm_o_wreck_ancient_motion_names, 7, 0,
};
const char *bm_fe_obj_o_hahen_model_names[10] = {
    debris_model_01,
    debris_model_02,
    debris_model_03,
    debris_model_04,
    debris_model_05,
    debris_model_06,
    debris_model_07,
    debris_model_08,
    debris_model_09,
    NULL,
};
const char *bm_fe_obj_o_hahen_motion_names[1] = {NULL};
BmlResourceDescriptor TOWreckAncient__resource_descriptor = {
    debris_archive, bm_fe_obj_o_hahen_model_names, bm_fe_obj_o_hahen_motion_names, 9, 0,
};
const char *TOWreckAncient__name = "TOWreckAncient";

// One sphere per wreck model: the subclass passes its model's entry (TOWreckAncient02/03 use it too).
extern __declspec(section ".data") const CollisionBody TOWreckAncient__collision_body_templates[7] = {
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

extern const AncientWreckDebrisOffsets TOWreckAncientBrakable__debris_table = {
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

extern const TObjChipParams TOWreckAncientBrakable__debris_param_table = {
    0.25f, 0.07f, 0.26f,
    { 0.0f, 0.0f, 0.0f },
    { 5.0f, 7.5f, 5.0f },
    { 0x400, 0x100, 0x400 },
    1, 30,
    0.0f, 0.6f,
    0, 0, 30,
};

BmlResource *wreck_ancient_bml_resource;
BmlResource *wreck_ancient_brakable_bml_resource;

extern "C" {


s32 post_translate_matrix(void *);
}

// --- TOWreckAncient ---

TOWreckAncient::TOWreckAncient(s32 model_index) : TObjCollidable(tl_05) {
    m_name = TOWreckAncient__name;
    model = (void *)get_bml_model((BmlResource *)wreck_ancient_bml_resource, model_index);
    texlist = get_bml_texlist((BmlResource *)wreck_ancient_bml_resource, model_index);
    view_far_depth = 400.0f;
    view_radius = 40.0f;
}

TOWreckAncient::~TOWreckAncient() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOWreckAncient::load_resources() {
    saddr var_r0;
    saddr var_r0_2;
    var_r0 = (saddr)new BmlResource(1, &bm_o_wreck_ancient_resource_descriptor, 0, 0, NULL);
    wreck_ancient_bml_resource = (BmlResource *)var_r0;
    var_r0_2 = (saddr)new BmlResource(1, &TOWreckAncient__resource_descriptor, 0, 0, NULL);
    wreck_ancient_brakable_bml_resource = (BmlResource *)var_r0_2;
}

void TOWreckAncient::free_statics() {
    if (wreck_ancient_bml_resource != NULL) {
        delete (BmlResource *)wreck_ancient_bml_resource;
        wreck_ancient_bml_resource = NULL;
    }
    if (wreck_ancient_brakable_bml_resource != NULL) {
        delete wreck_ancient_brakable_bml_resource;
        wreck_ancient_brakable_bml_resource = NULL;
    }
}

void TOWreckAncient::render() {
    if (update_object_view_visibility(view_far_depth, view_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
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

void *TOWreckAncient01::create(void *set_data) {
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

void *TOWreckAncient04::create(void *set_data) {
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

void *TOWreckAncient05::create(void *set_data) {
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

void *TOWreckAncient06::create(void *set_data) {
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

void *TOWreckAncient07::create(void *set_data) {
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
    s32 id;

    if (TObjPlayer::check_demo_mode() == 1) {
        TOWreckAncientBrakable__sub_8017D444(this);
        return;
    }
    switch (state) {
    default:
        state = 0;
    case 0:
        id = switch_id;
        if ((id >= 0) && (id < 0x100) && (is_current_floor_switch_set((u16) id) == 1)) {
            state = 1;
            play_sound_effect(0x43C11, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
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
    Vec tmp;
    AncientWreckDebrisOffsets arr = TOWreckAncientBrakable__debris_table;
    TObjChipParams p = TOWreckAncientBrakable__debris_param_table;
    s32 i;
    p.pos.x = position.x;
    p.pos.y = position.y;
    p.pos.z = position.z;
    p.floor_y = p.pos.y;
    for (i = 0; i < 9; i++) {
        VecCopy(&tmp, &arr.offsets[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, rotation_y);
        rotate_vector_by_matrix(0, &tmp, &tmp);
        pop_matrix();
        VecCopy(&p.pos, &position);
        vec3_add_to(&p.pos, &tmp);
        p.model = get_bml_model(wreck_ancient_brakable_bml_resource, i);
        p.textures = get_bml_texlist(wreck_ancient_brakable_bml_resource, i);
        new TObjChip(tl_05, &p);
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

void *TOWreckAncientBrakable05::create(void *set_data) {
    return new TOWreckAncientBrakable05(set_data);
}
