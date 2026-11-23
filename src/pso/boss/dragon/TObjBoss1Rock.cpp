#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/dragon/TObjBoss1Rock.h"

#include "types.h"
#include <stdlib.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/model_render_state.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_8002E174.h"
#include "pso/boss/dragon/ObjBoss1CommonResource.h"
#include "pso/system/BmlResource.h"


const char *TObjBoss1Rock__name = "TObjBoss1Rock";

void TObjBoss1Rock::render() {
    if (m_color.a < 1.0f) {
        saved_model_render_flags = model_render_flags;
        model_render_flags = saved_model_render_flags | 0x810;
        set_chunk_material_override_pair(0xFF00, 0x800);
        set_constant_material(&m_color);
        push_matrix();
        TObjFish::set_global_param(dragon_common_texture_list);
        post_translate_matrix(&m_position.x);
        rotate_matrix_y(NULL, m_rotation_y);
        rotate_matrix_x(NULL, m_rotation_x);
        draw_chunk_object(dragon_ground_resource->models[m_model_index].model);
        pop_matrix();
        set_chunk_material_override_pair(0xFF00, 0);
        model_render_flags = saved_model_render_flags;
    } else {
        push_matrix();
        TObjFish::set_global_param(dragon_common_texture_list);
        post_translate_matrix(&m_position.x);
        rotate_matrix_y(NULL, m_rotation_y);
        rotate_matrix_x(NULL, m_rotation_x);
        draw_chunk_object(dragon_ground_resource->models[m_model_index].model);
        pop_matrix();
    }
}

void TObjBoss1Rock::run_task() {
    m_frames++;
    if (m_frames > 40) {
        m_color.a -= 0.08f;
        if (m_color.a < 0.0f) {
            m_color.a = 0.0f;
            queue_destruction();
        }
    }
    vec3_add_to(&m_position, &m_velocity);
    if (m_position.y < 0.0f) {
        m_position.y *= -1.0f;
        m_velocity.y *= -0.4f;
        m_velocity.x *= 0.7f;
        m_velocity.z *= 0.7f;
    }
    m_velocity.y += -0.5f;
    m_rotation_y += 0x60;
    m_rotation_x += 0x110;
}

TObjBoss1Rock::~TObjBoss1Rock() {}

void TObjBoss1Rock::sub_8002E1CC(const Vec *pos, const Vec *vel, s32 kind) {
    m_name = TObjBoss1Rock__name;
    VecCopy(&m_position, pos);
    VecCopy(&m_velocity, vel);
    m_rotation_y = (s32)(65536.0f * (3.0517578125e-05f * (f32)rand()));
    m_rotation_x = (s32)(65536.0f * (3.0517578125e-05f * (f32)rand()));
    m_frames = 0;
    m_color.a = 1.0f;
    m_color.r = 1.0f;
    m_color.g = 1.0f;
    m_color.b = 1.0f;
    if (kind == 0) {
        m_model_index = 2;
    } else {
        m_model_index = 1;
    }
}

TObjBoss1Rock::TObjBoss1Rock(TObject *parent, const Vec *pos, const Vec *vel, s32 kind) : TObject(parent) {
    sub_8002E1CC(pos, vel, kind);
}

TObjBoss1Rock::TObjBoss1Rock(TObject *parent, const Vec *pos, const Vec *vel) : TObject(parent) {
    s32 kind;
    if (3.0517578125e-05f * (f32)rand() > 0.8f) {
        kind = 0;
    } else {
        kind = 1;
    }
    sub_8002E1CC(pos, vel, kind);
}

void TObjBoss1Rock__sub_8002E3CC(void) {}
void TObjBoss1Rock__sub_8002E3D0(void) {}
