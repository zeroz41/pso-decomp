#include "types.h"
#include <stdlib.h>
#include "pso/system/task/TMainTask.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/ScratchVectors.h"
#include "pso/boss/darkfalz/TOBoss4.h"
#include "pso/boss/darkfalz/TOBoss4Bird.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/boss/darkfalz/TOBoss4Tower.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModel.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"

const char *bm_o_boss4_model_names[7] = {
    "df_obj_bird.gj", "df_obj_iwa_l.gj", "df_obj_iwa_m.gj", "df_obj_iwa_s1.gj",
    "df_obj_iwa_s2.gj", "fd_obj810_df2_tower.gj", NULL,
};
const char *bm_o_boss4_motion_names[2] = {"df_obj_bird.njm", NULL};
BmlResourceDescriptor bm_o_boss4_resource_descriptor = {
    "bm_o_boss4.bml", bm_o_boss4_model_names, bm_o_boss4_motion_names, 6, 1,
};
const char *TOBoss4::class_name = "TOBoss4";
const char *TOBoss4Bird::class_name = "TOBoss4Bird";
const char *TOBoss4Tower::class_name = "TOBoss4Tower";
const char *TOBoss4Rock::class_name = "TOBoss4Rock";
BmlResource *TOBoss4::model_resource;

// The flock's V formation.
struct TOBoss4BirdFormation {
    Vec offsets[6];
};
const TOBoss4BirdFormation boss4_bird_vec_table = {{
    {0.0f, 0.0f, 0.0f},     {-10.0f, 5.0f, -10.0f}, {10.0f, 0.0f, -10.0f},
    {-20.0f, 5.0f, -20.0f}, {0.0f, 0.0f, -20.0f},   {20.0f, 5.0f, -20.0f},
}};

TOBoss4::TOBoss4() : TObjBase(tl_05) {
    m_name = class_name;
    view_range = 2000.0f;
    model_radius = 0.0f;
}

TOBoss4::~TOBoss4() {
}

void TOBoss4::load_static_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_o_boss4_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
}

void TOBoss4::free_instance() {
    if (model_resource != NULL) {
        free_bin_model_request(model_resource, 1);
        model_resource = NULL;
    }
}

TOBoss4Bird::TOBoss4Bird(void *set_data) {
    s32 i;
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(model_resource, 0);
    model_radius = ((GinjaModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    texlist = TObjFish__sub_8001EDB0(model_resource, 0);
    motion = get_bml_motion(model_resource, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 1.0f;
    animation_frame = 0.0f;
    speed = 1.0f + scale.x;
    wander_height = 50.0f + scale.y;
    wander_radius = 100.0f + scale.z;
    state = 0;
    count = set_params[0] + 3;
    if (count < 0) {
        count = 1;
    } else if (count > 6) {
        count = 6;
    }
    offsets = (Vec *)mem_alloc(count * 0xC);
    angles = (s32 *)mem_alloc(count * 4);
    {
        TOBoss4BirdFormation formation = boss4_bird_vec_table;
        for (i = 0; i < count; i++) {
            VecCopy(&offsets[i], &formation.offsets[i]);
            angles[i] = 0x8000;
        }
    }
    target.x = target.y = target.z = 0.0f;
    bob_rate = 0.1f * (f32)set_params[1] + 1.0f;
    bob_angle_step = (s32)(182.04445f * (360.0f / (30.0f / bob_rate)));
    bob_angle = (s32)(182.04445f * (360.0f * ((1.0f / 32768.0f) * (f32)rand())));
    bob_height = 0.1f * (f32)set_params[2] + 1.0f;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
    flight_timer = 0;
}

TOBoss4Bird::~TOBoss4Bird() {
    if (offsets != NULL) {
        mem_free(offsets);
    }
    if (angles != NULL) {
        mem_free(angles);
    }
}

void *TOBoss4Bird::create(void *set_data) {
    return new TOBoss4Bird(set_data);
}

void TOBoss4Bird::render() {
    s32 i;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        TObjFish::set_global_param(texlist);
        for (i = 0; i < count; i++) {
            push_matrix();
            translate_matrix(0, 0.0f, bob_offset, 0.0f);
            post_translate_matrix(&offsets[i].x);
            rotate_matrix_y(NULL, rotation_y);
            rotate_matrix_y(NULL, angles[i]);
            draw_ginja_model_with_motion(model, motion, animation_frame);
            pop_matrix();
        }
        pop_matrix();
    }
}

void TOBoss4Bird::run_task() {
    animation_frame += animation_step;
    if (animation_end_frame < animation_frame) {
        animation_frame -= animation_end_frame;
    }
    bob_angle += bob_angle_step;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
    switch (state) {
    case 0:
        state = 1;
        scratch_vec.x = 0.0f;
        scratch_vec.y = wander_height * ((1.0f / 32768.0f) * (f32)rand());
        scratch_vec.z = wander_radius * ((1.0f / 32768.0f) * (f32)rand());
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(NULL, (s32)(182.04445f * (360.0f * ((1.0f / 32768.0f) * (f32)rand()))));
        rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
        pop_matrices(1);
        VecCopy(&target, &home_position);
        vec3_add_to(&target, &scratch_vec);
        break;
    case 1:
        VecCopy(&scratch_vec, &target);
        subtract_vector(&scratch_vec, &position);
        rotation_y = approach_angle_limited(
            rotation_y, (s32)(10430.38043493439 * atan2_float(scratch_vec.x, scratch_vec.z)), 0x100);
        lbl_8050BF00.x = lbl_8050BF00.y = 0.0f;
        lbl_8050BF00.z = speed;
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(NULL, rotation_y);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&position, &lbl_8050BF00);
        if (horizontal_distance_squared(&target, &position) < wander_radius || 150.0f < (f32)flight_timer++) {
            state = 0;
            flight_timer = 0;
        }
        break;
    }
}

TOBoss4Tower::TOBoss4Tower(void *set_data) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(model_resource, 5);
    model_radius = 60.0f;
    texlist = TObjFish__sub_8001EDB0(model_resource, 5);
}

TOBoss4Tower::~TOBoss4Tower() {
}

void TOBoss4Tower::render() {
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_object(model);
        pop_matrix();
    }
}

void *TOBoss4Tower::create(void *set_data) {
    return new TOBoss4Tower(set_data);
}

TOBoss4Rock::TOBoss4Rock(void *set_data) {
    s32 i;
    int model;
    f32 base;

    m_name = class_name;
    apply_object_set_data(set_data);
    this->model = (void *)get_bml_model(model_resource, 1);
    model_radius = ((GinjaModelBounds *)((NJS_OBJECT *)this->model)->model)->radius;
    texlist = TObjFish__sub_8001EDB0(model_resource, 1);
    spread = 50.0f + scale.x;
    if (scale.y < 0.0f) {
        scale.y *= -1.0f;
    }
    count = set_params[0];
    if (count < 1) {
        count = 1;
    } else if (count > 8) {
        count = 8;
    }
    models = (s32 *)mem_alloc(count * 4);
    texlists = (s32 *)mem_alloc(count * 4);
    positions = (Vec *)mem_alloc(count * 0xC);
    speeds = (f32 *)mem_alloc(count * 4);
    rotations = (TOBoss4RockAngles *)mem_alloc(count * 0xC);
    rotation_speeds = (TOBoss4RockAngles *)mem_alloc(count * 0xC);
    for (i = 0; i < count; i++) {
        model = 4.0f * ((1.0f / 32768.0f) * (f32)rand());
        models[i] = get_bml_model(model_resource, model);
        texlists[i] = TObjFish__sub_8001EDB0(model_resource, model);
        positions[i].x = spread * ((1.0f / 32768.0f) * (f32)rand());
        positions[i].y = 0.0f;
        positions[i].z = spread * ((1.0f / 32768.0f) * (f32)rand());
        base = 0.5f * scale.y;
        speeds[i] = base * ((1.0f / 32768.0f) * (f32)rand()) + base;
        rotations[i].x = (s32)(65535.0f * ((1.0f / 32768.0f) * (f32)rand()));
        rotations[i].y = (s32)(65535.0f * ((1.0f / 32768.0f) * (f32)rand()));
        rotations[i].z = (s32)(65535.0f * ((1.0f / 32768.0f) * (f32)rand()));
        rotation_speeds[i].x = (s32)(4096.0f * ((1.0f / 32768.0f) * (f32)rand()));
        rotation_speeds[i].y = (s32)(4096.0f * ((1.0f / 32768.0f) * (f32)rand()));
        rotation_speeds[i].z = (s32)(4096.0f * ((1.0f / 32768.0f) * (f32)rand()));
    }
}

TOBoss4Rock::~TOBoss4Rock() {
    if (models != NULL) {
        mem_free(models);
    }
    if (texlists != NULL) {
        mem_free(texlists);
    }
    if (positions != NULL) {
        mem_free(positions);
    }
    if (speeds != NULL) {
        mem_free(speeds);
    }
    if (rotations != NULL) {
        mem_free(rotations);
    }
    if (rotation_speeds != NULL) {
        mem_free(rotation_speeds);
    }
}

void *TOBoss4Rock::create(void *set_data) {
    return new TOBoss4Rock(set_data);
}

void TOBoss4Rock::render() {
    s32 i;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        for (i = 0; i < count; i++) {
            TObjFish::set_global_param(texlists[i]);
            push_matrix();
            post_translate_matrix(&positions[i].x);
            rotate_matrix_z(NULL, rotations[i].z);
            rotate_matrix_x(NULL, rotations[i].x);
            rotate_matrix_y(NULL, rotations[i].y);
            draw_ginja_object((void *)models[i]);
            pop_matrix();
        }
        pop_matrix();
    }
}

void TOBoss4Rock::run_task() {
    s32 i;
    int model;
    f32 base;

    for (i = 0; i < count; i++) {
        rotations[i].x += rotation_speeds[i].x;
        rotations[i].y += rotation_speeds[i].y;
        rotations[i].z += rotation_speeds[i].z;
        positions[i].y += speeds[i];
        if (2000.0f < positions[i].y) {
            model = 4.0f * ((1.0f / 32768.0f) * (f32)rand());
            models[i] = get_bml_model(model_resource, model);
            texlists[i] = TObjFish__sub_8001EDB0(model_resource, model);
            positions[i].x = spread * ((1.0f / 32768.0f) * (f32)rand());
            positions[i].y = 0.0f;
            positions[i].z = spread * ((1.0f / 32768.0f) * (f32)rand());
            base = 0.5f * scale.y;
            speeds[i] = base * ((1.0f / 32768.0f) * (f32)rand()) + base;
            rotations[i].x = (s32)(65535.0f * ((1.0f / 32768.0f) * (f32)rand()));
            rotations[i].y = (s32)(65535.0f * ((1.0f / 32768.0f) * (f32)rand()));
            rotations[i].z = (s32)(65535.0f * ((1.0f / 32768.0f) * (f32)rand()));
            rotation_speeds[i].x = (s32)(4096.0f * ((1.0f / 32768.0f) * (f32)rand()));
            rotation_speeds[i].y = (s32)(4096.0f * ((1.0f / 32768.0f) * (f32)rand()));
            rotation_speeds[i].z = (s32)(4096.0f * ((1.0f / 32768.0f) * (f32)rand()));
        }
    }
}
