#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include "pso/object/jungle/TORockJungleL01.h"
#include "pso/object/jungle/TORockJungleM01.h"
#include "pso/object/jungle/TORockJungleS01.h"
#include "pso/object/TObjChip.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/system/task/TMainTask.h"
#include "pso/map/FloorArea.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/render_util.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixVector.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_80011014.h"

// The source is written from the last function back: the unit is built
// -inline off,deferred, which emits it in reverse (the vtables L01, M01, S01
// follow the code order while the class names and chip tables do not).

extern const char *bm_o_rock_jungle_motion_names[1];

// The jungle rocks (gc11m, gc31m, gc52m) and the pieces the small and
// middle ones break into (hahen).
const char *bm_o_rock_jungle_model_names[6] = {
    "fe_objiwa_gc11m.gj", "fe_objiwa_gc11mhahen.gj", "fe_objiwa_gc31m.gj",
    "fe_objiwa_gc31mhahen.gj", "fe_objiwa_gc52m.gj", NULL,
};
BmlResourceDescriptor TORockJungleS01_resource_descriptor = {
    "bm_o_rock_jungle.bml", bm_o_rock_jungle_model_names, bm_o_rock_jungle_motion_names, 5, 0,
};
// One collision body each for the small, middle and large rocks.
CollisionBody rock_jungle_collision_body_parts[3] = {
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 8.0f, 12.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 20.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
// The scale of the map collision each rock creates.
Vec rock_jungle_vec3_table[3] = {
    { 32.0f, 20.0f, 12.0f },
    { 32.0f, 20.0f, 12.0f },
    { 32.0f, 20.0f, 12.0f },
};
const char *bm_o_rock_jungle_motion_names[1] = { NULL };

BmlResource *TORockJungleS01__bml_resource;
NJS_TEXLIST *TORockJungleS01__texture_resource;

const char *TORockJungleS01__name = "TORockJungleS01";

// The original reaches each texture-list name with its own lis/addi while the
// L01 constructor reaches its .rodata from one pooled base: pool_data is off
// for this function only.
#pragma pool_data off
void TORockJungleS01::load_resources() {
    BmlResource *resource;

    resource = new BmlResource(1, &TORockJungleS01_resource_descriptor, 0, 0, NULL);
    TORockJungleS01__bml_resource = resource;
    switch (get_current_floor_area()) {
    case AREA_SEASIDE:
        TORockJungleS01__texture_resource = load_gvm_texture_file("o_rock_jungle_05.GVM");
        break;
    case AREA_MOUNTAIN:
        TORockJungleS01__texture_resource = load_gvm_texture_file("o_rock_jungle_04.GVM");
        break;
    case AREA_JUNGLE_EAST:
    default:
        TORockJungleS01__texture_resource = load_gvm_texture_file("o_rock_jungle_123.GVM");
        break;
    }
    TObjNpcEnemy::register_ginja(0x3E, get_model(0),
                           get_jungle_rock_texture_resource(0), 5.0f, 0.0f);
}
#pragma pool_data reset

void TORockJungleS01::free_globals() {
    if (TORockJungleS01__texture_resource != NULL) {
        release_texture_list(TORockJungleS01__texture_resource);
        safe_free(TORockJungleS01__texture_resource);
        TORockJungleS01__texture_resource = NULL;
    }
    if (TORockJungleS01__bml_resource != NULL) {
        delete TORockJungleS01__bml_resource;
        TORockJungleS01__bml_resource = NULL;
    }
}

NJS_OBJECT *TORockJungleS01::get_model(s32 index) {
    if (TORockJungleS01__bml_resource != NULL) {
        return get_bml_model(TORockJungleS01__bml_resource, index);
    }
    return 0;
}

// Every rock uses the floor's one texture list, whatever its model.
NJS_TEXLIST *get_jungle_rock_texture_resource(s32 index) {
    if (TORockJungleS01__texture_resource != NULL) {
        return TORockJungleS01__texture_resource;
    }
    return NULL;
}

TORockJungleS01::TORockJungleS01(void *set_data) {
    m_name = TORockJungleS01__name;
    apply_object_set_data(set_data);
    model = get_model(0);
    texlist = get_jungle_rock_texture_resource(0);
    m_b0 = 50.0f + ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->model)->r;
    init_collision_body_parts(this, &rock_jungle_collision_body_parts[0], 1);
    refresh_collision_body_centers();
    register_object_by_id();
    m_b8 = set_params[0];
    if (m_b8 < 0 || m_b8 >= 0x100) {
        m_b8 = -1;
    }
    ObjectSetData csn_data = *(ObjectSetData *)set_data;
    VecCopy(&csn_data.scale, &rock_jungle_vec3_table[0]);
    map_csn = TObjMapCsn::create(&csn_data);
}

TORockJungleS01::~TORockJungleS01() {
    if (map_csn != NULL) {
        map_csn->queue_destruction();
        map_csn = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockJungleS01::create(void *set_data) {
    return new TORockJungleS01(set_data);
}

// Throws the rock's one debris piece.
void TORockJungleS01::vfunc_16() {
    Vec offsets[1] = { { 0.0f, 0.0f, 0.0f } };
    TObjChipParams params = {
        0.25f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 7.5f, 5.0f },
        { 1024, 256, 1024 }, 1, 30, 0.0f, 0.6f, 0, 0, 22,
    };
    Vec offset;
    s32 i;

    params.pos.x = position.x;
    params.pos.y = position.y;
    params.pos.z = position.z;
    params.floor_y = params.pos.y;
    for (i = 0; i < 1; i++) {
        VecCopy(&offset, &offsets[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(NULL, rotation_y);
        rotate_vector_by_matrix(0, &offset, &offset);
        pop_matrix();
        VecCopy(&params.pos, &position);
        vec3_add_to(&params.pos, &offset);
        params.model = get_model(1);
        params.textures = get_jungle_rock_texture_resource(1);
        new TObjChip(tl_05, &params);
    }
}

void TORockJungleS01::vfunc_18() {
    play_sound_effect(310297, &position, 0, 0);
}

const char *TORockJungleM01_name_ref = "TORockJungleM01";

// Fades the rock out while the camera is close to it (not in split screen).
void TORockJungleM01::vfunc_14() {
    Vec view;

    set_cull_back();
    matrix_mult_vec(NULL, &position, &view);
    if (-view.z < 38.0f) {
        fade.fadeOut();
    } else {
        fade.restore();
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        fade_active = 0;
    } else {
        fade_active = fade.isFading();
    }
    if (fade_active != 0) {
        fade.set_flags_and_apply_damage_color();
    }
}

void TORockJungleM01::vfunc_15() {
    if (fade_active != 0) {
        fade.clear_flag_and_notify();
    }
    set_cull_none();
}

TORockJungleM01::TORockJungleM01(void *set_data) {
    m_name = TORockJungleM01_name_ref;
    apply_object_set_data(set_data);
    model = TORockJungleS01::get_model(2);
    texlist = get_jungle_rock_texture_resource(2);
    m_b0 = 50.0f + ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->model)->r;
    init_collision_body_parts(this, &rock_jungle_collision_body_parts[1], 1);
    refresh_collision_body_centers();
    register_object_by_id();
    m_b8 = set_params[0];
    if (m_b8 < 0 || m_b8 >= 0x100) {
        m_b8 = -1;
    }
    ObjectSetData csn_data = *(ObjectSetData *)set_data;
    VecCopy(&csn_data.scale, &rock_jungle_vec3_table[0]);
    map_csn = TObjMapCsn::create(&csn_data);
    fade.activate_and_dispatch();
}

TORockJungleM01::~TORockJungleM01() {
    if (map_csn != NULL) {
        map_csn->queue_destruction();
        map_csn = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockJungleM01::create(void *set_data) {
    return new TORockJungleM01(set_data);
}

// Throws the rock's one debris piece.
void TORockJungleM01::vfunc_16() {
    Vec offsets[1] = { { 0.0f, 0.0f, 0.0f } };
    TObjChipParams params = {
        0.25f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 7.5f, 5.0f },
        { 1024, 256, 1024 }, 1, 30, 0.0f, 0.6f, 0, 0, 22,
    };
    Vec offset;
    s32 i;

    params.pos.x = position.x;
    params.pos.y = position.y;
    params.pos.z = position.z;
    params.floor_y = params.pos.y;
    for (i = 0; i < 1; i++) {
        VecCopy(&offset, &offsets[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(NULL, rotation_y);
        rotate_vector_by_matrix(0, &offset, &offset);
        pop_matrix();
        VecCopy(&params.pos, &position);
        vec3_add_to(&params.pos, &offset);
        params.model = TORockJungleS01::get_model(3);
        params.textures = get_jungle_rock_texture_resource(3);
        new TObjChip(tl_05, &params);
    }
}

void TORockJungleM01::vfunc_18() {
    play_sound_effect(310297, &position, 0, 0);
}

void TORockJungleM01::run_task() {
    fade.update();
    TORockCaveBrakable::run_task();
}

const char *TORockJungleL01_name_ref = "TORockJungleL01";

TORockJungleL01::TORockJungleL01(void *set_data) {
    m_name = TORockJungleL01_name_ref;
    apply_object_set_data(set_data);
    model = TORockJungleS01::get_model(4);
    texlist = get_jungle_rock_texture_resource(4);
    m_b0 = 50.0f + ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->model)->r;
    init_collision_body_parts(this, &rock_jungle_collision_body_parts[2], 1);
    refresh_collision_body_centers();
    register_object_by_id();
    ObjectSetData csn_data = *(ObjectSetData *)set_data;
    VecCopy(&csn_data.scale, &rock_jungle_vec3_table[0]);
    map_csn = TObjMapCsn::create(&csn_data);
    fade.activate_and_dispatch();
}

TORockJungleL01::~TORockJungleL01() {
    if (map_csn != NULL) {
        map_csn->queue_destruction();
        map_csn = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TORockJungleL01::create(void *set_data) {
    return new TORockJungleL01(set_data);
}

// Fades the rock out while the camera is close to it (not in split screen).
void TORockJungleL01::vfunc_14() {
    Vec view;

    set_cull_back();
    matrix_mult_vec(NULL, &position, &view);
    if (-view.z < 38.0f) {
        fade.fadeOut();
    } else {
        fade.restore();
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        fade_active = 0;
    } else {
        fade_active = fade.isFading();
    }
    if (fade_active != 0) {
        fade.set_flags_and_apply_damage_color();
    }
}

void TORockJungleL01::vfunc_15() {
    if (fade_active != 0) {
        fade.clear_flag_and_notify();
    }
    set_cull_none();
}

void TORockJungleL01::run_task() {
    fade.update();
}
