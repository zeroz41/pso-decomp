#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include "pso/object/cave/TORockCave.h"
#include "pso/object/cave/TORockCaveSimple.h"
#include "pso/object/cave/TORockCaveBrakable.h"
#include "pso/object/cave/TORockCaveS01.h"
#include "pso/object/cave/TORockCaveM01.h"
#include "pso/object/cave/TORockCaveL01.h"
#include "pso/object/cave/TORockCaveS02.h"
#include "pso/object/cave/TORockCaveM02.h"
#include "pso/object/cave/TORockCaveL02.h"
#include "pso/object/cave/TORockCaveSS02.h"
#include "pso/object/cave/TORockCaveSM02.h"
#include "pso/object/cave/TORockCaveSL02.h"
#include "pso/object/cave/TORockCaveS03.h"
#include "pso/object/cave/TORockCaveM03.h"
#include "pso/object/cave/TORockCaveL03.h"
#include "pso/object/cave/TORockCaveBL01.h"
#include "pso/object/cave/TORockCaveBL02.h"
#include "pso/object/cave/TORockCaveBL03.h"
#include "pso/object/TObjChip.h"
#include "pso/system/task/TMainTask.h"
#include "pso/map/FloorArea.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"

// The source is written from the last function back: the unit is built
// -inline off,deferred, which emits it in reverse (the class-name and
// vtable order of .sdata/.data, against the code order, show it).

extern const char *bm_o_rock_cave01_motion_names[1];
extern const char *bm_o_rock_cave02_motion_names[1];
extern const char *bm_o_rock_cave03_motion_names[1];
extern const char *bm_fe_obj_rb_liwa_motion_names[1];
extern const char *bm_fe_obj_rb2_liwa_motion_names[1];
extern const char *bm_fe_obj_rb3_liwa_motion_names[1];

// The rocks of each cave floor (bm_o_rock_cave0N) and the debris pieces of its
// breakable ones (bm_fe_obj_rbN_liwa).
static const char *rock_cave_resource_table[4] = { "fe_obj_liwa01.gj", "fe_obj_miwa01.gj", "fe_obj_siwa01.gj", NULL };
static BmlResourceDescriptor bm_o_rock_cave01_descriptor = { "bm_o_rock_cave01.bml", rock_cave_resource_table, bm_o_rock_cave01_motion_names, 3, 0 };
static const char *bm_o_rock_cave02_resource_bundle[7] = { "fe_obj_liwa02.gj", "fe_obj_miwa02.gj", "fe_obj_siwa02.gj", "fs_obj_liwa025.gj", "fs_obj_miwa025.gj", "fs_obj_siwa025.gj", NULL };
static BmlResourceDescriptor bm_o_rock_cave02_descriptor = { "bm_o_rock_cave02.bml", bm_o_rock_cave02_resource_bundle, bm_o_rock_cave02_motion_names, 6, 0 };
static const char *bm_o_rock_cave03_resource_bundle[4] = { "fe_obj_liwa03.gj", "fe_obj_miwa03.gj", "fe_obj_siwa03.gj", NULL };
static BmlResourceDescriptor bm_o_rock_cave03_descriptor = { "bm_o_rock_cave03.bml", bm_o_rock_cave03_resource_bundle, bm_o_rock_cave03_motion_names, 3, 0 };
static const char *bm_fe_obj_rb_liwa_resource_bundle[7] = { "fe_obj_rb_liwa01.gj", "fe_obj_rb_liwa02.gj", "fe_obj_rb_liwa03.gj", "fe_obj_rb_liwa04.gj", "fe_obj_rb_liwa05.gj", "fe_obj_rb_liwa06.gj", NULL };
static BmlResourceDescriptor bm_fe_obj_rb_liwa_descriptor = { "bm_fe_obj_rb_liwa.bml", bm_fe_obj_rb_liwa_resource_bundle, bm_fe_obj_rb_liwa_motion_names, 6, 0 };
static const char *bm_fe_obj_rb2_liwa_resource_bundle[7] = { "fe_obj_rb2_liwa01.gj", "fe_obj_rb2_liwa02.gj", "fe_obj_rb2_liwa03.gj", "fe_obj_rb2_liwa04.gj", "fe_obj_rb2_liwa05.gj", "fe_obj_rb2_liwa06.gj", NULL };
static BmlResourceDescriptor bm_fe_obj_rb2_liwa_descriptor = { "bm_fe_obj_rb2_liwa.bml", bm_fe_obj_rb2_liwa_resource_bundle, bm_fe_obj_rb2_liwa_motion_names, 6, 0 };
static const char *bm_fe_obj_rb3_liwa_resource_bundle[7] = { "fe_obj_rb3_liwa01.gj", "fe_obj_rb3_liwa02.gj", "fe_obj_rb3_liwa03.gj", "fe_obj_rb3_liwa04.gj", "fe_obj_rb3_liwa05.gj", "fe_obj_rb3_liwa06.gj", NULL };
static BmlResourceDescriptor bm_fe_obj_rb3_liwa_descriptor = { "bm_fe_obj_rb3_liwa.bml", bm_fe_obj_rb3_liwa_resource_bundle, bm_fe_obj_rb3_liwa_motion_names, 6, 0 };
const char *bm_o_rock_cave01_motion_names[1] = { NULL };
const char *bm_o_rock_cave02_motion_names[1] = { NULL };
const char *bm_o_rock_cave03_motion_names[1] = { NULL };
const char *bm_fe_obj_rb_liwa_motion_names[1] = { NULL };
const char *bm_fe_obj_rb2_liwa_motion_names[1] = { NULL };
const char *bm_fe_obj_rb3_liwa_motion_names[1] = { NULL };

// Class names of the rock family (each constructor stores its own).
const char *TORockCave__class_name = "TORockCave";
const char *TORockCaveSimple__class_name = "TORockCaveSimple";
const char *TORockCaveBrakable__name = "TORockCaveBrakable";
const char *TORockCaveS01__name = "TORockCaveS01";
const char *TORockCaveS02__name = "TORockCaveS02";
const char *TORockCaveSS02__name = "TORockCaveSS02";
const char *TORockCaveS03__name = "TORockCaveS03";
const char *TORockCaveM01__name = "TORockCaveM01";
const char *TORockCaveM02__name = "TORockCaveM02";
const char *TORockCaveSM02__class_name = "TORockCaveSM02";
const char *TORockCaveM03__name = "TORockCaveM03";
const char *TORockCaveL01_class_name = "TORockCaveL01";
const char *TORockCaveL02__name = "TORockCaveL02";
const char *TORockCaveSL02__name = "TORockCaveSL02";
const char *TORockCaveL03__name = "TORockCaveL03";
const char *TORockCaveBL01__name = "TORockCaveBL01";
const char *TORockCaveBL02__name = "TORockCaveBL02";
const char *TORockCaveBL03__name = "TORockCaveBL03";

// One sphere each for the small, middle and large rocks (S, M and L models).
CollisionBody cave_rock_collision_body_templates[3] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 25.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 30.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

BmlResource *cave_rock_resource_bundle;  // the floor's rock models
BmlResource *rock_cave_model_resource;   // the floor's debris pieces

void TORockCave::vfunc_15() {}

void TORockCave::vfunc_14() {}

TORockCave::TORockCave() : TObjCollidable(tl_05) {
    m_name = TORockCave__class_name;
    unk_AC = 500.0f;
    m_b0 = 0.0f;
}

TORockCave::~TORockCave() {}

void TORockCave::load_resources() {
    BmlResource *resource;

    switch (get_current_floor_area()) {
    case AREA_CAVE1:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_o_rock_cave01_descriptor, 0, 0, 0);
        }
        cave_rock_resource_bundle = resource;
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_fe_obj_rb_liwa_descriptor, 0, 0, 0);
        }
        rock_cave_model_resource = resource;
        break;
    case AREA_CAVE2:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_o_rock_cave02_descriptor, 0, 0, 0);
        }
        cave_rock_resource_bundle = resource;
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_fe_obj_rb2_liwa_descriptor, 0, 0, 0);
        }
        rock_cave_model_resource = resource;
        break;
    case AREA_CAVE3:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_o_rock_cave03_descriptor, 0, 0, 0);
        }
        cave_rock_resource_bundle = resource;
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_fe_obj_rb3_liwa_descriptor, 0, 0, 0);
        }
        rock_cave_model_resource = resource;
        break;
    default:
        cave_rock_resource_bundle = NULL;
        rock_cave_model_resource = NULL;
        break;
    }
}

void TORockCave::free_instances() {
    if (rock_cave_model_resource != NULL) {
        free_bin_model_request(rock_cave_model_resource, 1);
        rock_cave_model_resource = NULL;
    }
    if (cave_rock_resource_bundle != NULL) {
        free_bin_model_request(cave_rock_resource_bundle, 1);
        cave_rock_resource_bundle = NULL;
    }
}

void TORockCave::render() {
    if (update_object_view_visibility(unk_AC, m_b0) != 0) {
        vfunc_14();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_object(model);
        pop_matrix();
        vfunc_15();
    }
}

TORockCaveSimple::TORockCaveSimple() {
    m_name = TORockCaveSimple__class_name;
}

TORockCaveSimple::~TORockCaveSimple() {}

void TORockCaveSimple::render() {
    if (update_object_view_visibility(unk_AC, m_b0) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_object(model);
        pop_matrix();
    }
}

TORockCaveBrakable::TORockCaveBrakable() {
    m_name = TORockCaveBrakable__name;
    m_b4 = 0;
    m_b8 = -1;
}

TORockCaveBrakable::~TORockCaveBrakable() {}

void TORockCaveBrakable::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        vfunc_19();
        return;
    }
    switch (m_b4) {
    default:
        m_b4 = 0;
    case 0:
        if (m_b8 >= 0 && m_b8 < 0x100 && is_current_floor_switch_set((u16)m_b8) == 1) {
            m_b4 = 1;
            spawn_break_effect();
            vfunc_16();
        }
        break;
    case 1:
        set_flag8();
        queue_destruction();
        break;
    }
}

void TORockCaveBrakable::spawn_break_effect() {
    vfunc_18();
    spawn_particle_effect(&position, 0x45);
    spawn_particle_effect(&position, 0x46);
}

// Throws the rock's six debris chips.
void TORockCaveBrakable::vfunc_16() {
    Vec offsets[6] = {
        { 12.0f, 7.0f, 12.0f }, { -14.0f, 16.0f, 13.0f }, { -3.0f, 51.0f, 11.0f },
        { 7.0f, 49.0f, -11.0f }, { -7.0f, 38.0f, -14.0f }, { 8.0f, 16.0f, -16.0f },
    };
    TObjChipParams params = {
        { 0.25f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 7.5f, 5.0f },
        { 1024, 256, 1024 }, { 1, 30 }, { 0.0f, 0.6f }, 0, 0, 22,
    };
    Vec offset;
    s32 i;

    params.pos[0] = position.x;
    params.pos[1] = position.y;
    params.pos[2] = position.z;
    params.pad_38[0] = params.pos[1];
    for (i = 0; i < 6; i++) {
        VecCopy(&offset, &offsets[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(NULL, rotation_y);
        rotate_vector_by_matrix(0, &offset, &offset);
        pop_matrix();
        VecCopy((Vec *)params.pos, &position);
        vec3_add_to((Vec *)params.pos, &offset);
        params.model = get_bml_model(rock_cave_model_resource, i);
        params.textures = TObjFish__sub_8001EDB0(rock_cave_model_resource, i);
        new TObjChip(tl_05, &params);
    }
}

void TORockCaveBrakable::vfunc_18() {
    play_sound_effect(277521, &position, 0, 0);
}

void TORockCaveBrakable::vfunc_19() {}

TORockCaveS01::TORockCaveS01(void *set_data) {
    m_name = TORockCaveS01__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 2);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 2);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[0], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveS01::~TORockCaveS01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveS01__create(void *set_data) {
    return new TORockCaveS01(set_data);
}

TORockCaveM01::TORockCaveM01(void *set_data) {
    m_name = TORockCaveM01__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 1);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 1);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[1], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveM01::~TORockCaveM01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveM01__create(void *set_data) {
    return new TORockCaveM01(set_data);
}

TORockCaveL01::TORockCaveL01(void *set_data) {
    m_name = TORockCaveL01_class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 0);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 0);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[2], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveL01::~TORockCaveL01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveL01__create(void *set_data) {
    return new TORockCaveL01(set_data);
}

TORockCaveS02::TORockCaveS02(void *set_data) {
    m_name = TORockCaveS02__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 2);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 2);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[0], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveS02::~TORockCaveS02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveS02__create(void *set_data) {
    return new TORockCaveS02(set_data);
}

TORockCaveM02::TORockCaveM02(void *set_data) {
    m_name = TORockCaveM02__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 1);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 1);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[1], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveM02::~TORockCaveM02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveM02__create(void *set_data) {
    return new TORockCaveM02(set_data);
}

TORockCaveL02::TORockCaveL02(void *set_data) {
    m_name = TORockCaveL02__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 0);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 0);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[2], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveL02::~TORockCaveL02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveL02__create(void *set_data) {
    return new TORockCaveL02(set_data);
}

TORockCaveSS02::TORockCaveSS02(void *set_data) {
    m_name = TORockCaveSS02__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 5);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 5);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[0], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveSS02::~TORockCaveSS02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveSS02__create(void *set_data) {
    return new TORockCaveSS02(set_data);
}

TORockCaveSM02::TORockCaveSM02(void *set_data) {
    m_name = TORockCaveSM02__class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 4);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 4);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[1], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveSM02::~TORockCaveSM02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveSM02__create(void *set_data) {
    return new TORockCaveSM02(set_data);
}

TORockCaveSL02::TORockCaveSL02(void *set_data) {
    m_name = TORockCaveSL02__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 3);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 3);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[2], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveSL02::~TORockCaveSL02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveSL02__create(void *set_data) {
    return new TORockCaveSL02(set_data);
}

TORockCaveS03::TORockCaveS03(void *set_data) {
    m_name = TORockCaveS03__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 2);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 2);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[0], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveS03::~TORockCaveS03() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveS03__create(void *set_data) {
    return new TORockCaveS03(set_data);
}

TORockCaveM03::TORockCaveM03(void *set_data) {
    m_name = TORockCaveM03__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 1);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 1);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[1], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveM03::~TORockCaveM03() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveM03__create(void *set_data) {
    return new TORockCaveM03(set_data);
}

TORockCaveL03::TORockCaveL03(void *set_data) {
    m_name = TORockCaveL03__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 0);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 0);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[2], 1);
    refresh_collision_body_centers();
    register_object_by_id();
}

TORockCaveL03::~TORockCaveL03() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveL03__create(void *set_data) {
    return new TORockCaveL03(set_data);
}

TORockCaveBL01::TORockCaveBL01(void *set_data) {
    m_name = TORockCaveBL01__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 0);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 0);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[2], 1);
    refresh_collision_body_centers();
    register_object_by_id();
    m_b8 = set_params[0];
    if (m_b8 < 0 || m_b8 >= 0x100) {
        m_b8 = -1;
    }
}

TORockCaveBL01::~TORockCaveBL01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveBL01__create(void *set_data) {
    return new TORockCaveBL01(set_data);
}

TORockCaveBL02::TORockCaveBL02(void *set_data) {
    m_name = TORockCaveBL02__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 0);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 0);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[2], 1);
    refresh_collision_body_centers();
    register_object_by_id();
    m_b8 = set_params[0];
    if (m_b8 < 0 || m_b8 >= 0x100) {
        m_b8 = -1;
    }
}

TORockCaveBL02::~TORockCaveBL02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveBL02__create(void *set_data) {
    return new TORockCaveBL02(set_data);
}

TORockCaveBL03::TORockCaveBL03(void *set_data) {
    m_name = TORockCaveBL03__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(cave_rock_resource_bundle, 0);
    texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 0);
    m_b0 = 40.0f;
    init_collision_body_parts(this, &cave_rock_collision_body_templates[2], 1);
    refresh_collision_body_centers();
    register_object_by_id();
    m_b8 = set_params[0];
    if (m_b8 < 0 || m_b8 >= 0x100) {
        m_b8 = -1;
    }
}

TORockCaveBL03::~TORockCaveBL03() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockCaveBL03__create(void *set_data) {
    return new TORockCaveBL03(set_data);
}
