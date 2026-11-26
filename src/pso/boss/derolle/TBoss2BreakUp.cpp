// The De Rol Le breakup effects: TBoss2BodyBreakUp (the pieces TBoss2DeRolLe spawns), TBoss2JointBreakUp (the pieces
// TBoss2Joint spawns), their base TBoss2BreakUp and the breakup models they start from.
// Built -inline off,deferred: the functions below are written last to first (the vtables
// and TBoss2JointBreakUp::render's .rodata templates before TBoss2BodyBreakUp::render's only come out in that order).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/derolle/TBoss2BreakUp.h"
#include "pso/boss/derolle/RandomAngle.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/vector.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk.h"
#include "pso/unk/text_803DA798.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/model_render_state.h"
#include "pso/render/DebugFont.h"

extern const f32 breakup_unit;
extern const f32 breakup_zero;
extern const f32 breakup_bounce_factor;
extern const f32 breakup_rise_speed_min;
extern const f32 breakup_rise_speed_max;
extern const f32 breakup_back_speed_max;
extern const f32 breakup_spin_max;
extern const f32 breakup_spread_scale;
extern const f32 breakup_gravity;
extern const f32 breakup_fade_step;
extern const f32 breakup_floor_height;

TBreakUpMdlData *joint_breakup_model;
TBreakUpMdlData *body_breakup_model;
f32 boss2_breakup_water_level = boss2_water_level;

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
s32 TBoss2BreakUp::move_piece(BreakupPiece *piece) {
    f32 vel_y;
    f32 pos_y;
    f32 x;
    f32 z;
    s32 state;
    s32 spin;
    s32 sank;
    sank = 0;
    state = piece->state;
    spin = piece->spin;
    switch (state) {
    case 0:
        piece->vel.y = (piece->vel.y - breakup_gravity);
        vec3_add_to(&piece->pos, &piece->vel);
        vel_y = piece->vel.y;
        if (vel_y < breakup_zero) {
            pos_y = piece->pos.y;
            if (pos_y < breakup_floor_height) {
                x = piece->pos.x;
                z = piece->pos.z;
                if ((x <= boss2_platform_max) && (x >= boss2_platform_min) && (z <= 76.0f) && (z >= (-75.0f))) {
                    piece->vel.y = (vel_y * breakup_bounce_factor);
                    piece->state = 2;
                } else if (pos_y < boss2_water_level) {
                    sank = 1;
                    piece->state = 1;
                }
            }
        }
        piece->ang_x = (piece->ang_x + spin);
        piece->ang_z = (piece->ang_z + (spin * 2));
        break;
    case 2:
        piece->vel.y = (piece->vel.y - breakup_gravity);
        vec3_add_to(&piece->pos, &piece->vel);
        piece->alpha = (piece->alpha - breakup_fade_step);
        if (piece->alpha < breakup_zero) {
            piece->alpha = breakup_zero;
            piece->state = 3;
        }
        piece->ang_x = (piece->ang_x + spin);
        piece->ang_z = (piece->ang_z + (spin * 2));
        break;
    case 1:
        piece->pos.y = ((breakup_gravity * piece->vel.y) + piece->pos.y);
        piece->pos.z = (piece->pos.z + piece->vel.z);
        break;
    }
    return sank;
}
#pragma pop

void TBoss2BreakUp::scale_piece_positions(TBreakUpMdlData *model, s32 n) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, boss2_model_scale, boss2_model_scale, boss2_model_scale);
    for (i = 0; i < n; i++) {
        rotate_vector_by_matrix(0, &model->m_records[i].pos, &model->m_records[i].pos);
    }
    pop_matrix();
}

void TBoss2BreakUp::spread_piece_velocities(TBreakUpMdlData *model, s32 n) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, breakup_spread_scale, breakup_zero, breakup_spread_scale);
    for (i = 0; i < n; i++) {
        rotate_vector_by_matrix(0, &model->m_records[i].vel, &model->m_records[i].vel);
    }
    pop_matrix();
}

TBoss2BreakUp::TBoss2BreakUp(TObject *parent) : TObject(parent) {
    m_frames = 0;
}

TBoss2BreakUp::~TBoss2BreakUp() {
}

void TBoss2JointBreakUp::create_model() {
    TBreakUpMdlData *model = new TBreakUpMdlData(boss2_derolle_resource->models[6].model);
    joint_breakup_model = model;
    scale_piece_positions(model, 0x13);
    spread_piece_velocities(joint_breakup_model, 0x13);
}

void TBoss2JointBreakUp::free_model() {
    delete joint_breakup_model;
    joint_breakup_model = NULL;
}

TBoss2JointBreakUp::TBoss2JointBreakUp(TObject *parent, const Vec *pos) : TBoss2BreakUp(parent) {
    f32 alpha;
    f32 spin_max;
    BreakupPiece *p;
    Vec *v;
    s32 i;
    spin_max = breakup_spin_max;
    alpha = breakup_unit;
    for (i = 0, p = m_pieces; i < 19; i++, p++) {
        VecCopy(&p->pos, pos);
        vec3_add_to(&p->pos, &joint_breakup_model->m_records[i].pos);
        v = &p->vel;
        VecCopy(v, &joint_breakup_model->m_records[i].vel);
        v->y = random_range(breakup_rise_speed_min, breakup_rise_speed_max);
        v->z -= random_range(breakup_unit, breakup_back_speed_max);
        p->ang_x = random_angle();
        p->spin = (s32)(spin_max * rand_signed_unit());
        p->ang_z = random_angle();
        p->state = 0;
        p->alpha = alpha;
    }
}

TBoss2JointBreakUp::~TBoss2JointBreakUp() {
}

void TBoss2JointBreakUp::run_task() {
    BreakupPiece *piece;
    s32 i;
    m_frames += 1;
    if (m_frames >= 0xA0) {
        queue_destruction();
        return;
    }
    i = 0;
    do {
        piece = &m_pieces[i];
        if (move_piece(piece) != 0) {
            if ((i % 2) == 0) {
                TObjBoss2CeilJunk::create_particle(&piece->pos, 0x171);
            }
        }
        i += 1;
    } while (i < 0x13);
}

void TBoss2JointBreakUp::render() {
    BmlModelEntry *models = boss2_derolle_resource->models;
    NJS_OBJECT *mdl = models[6].model;
    NJS_ARGB color = {1.0f, 1.0f, 1.0f, 1.0f};
    NJS_OBJECT *node = mdl->child;
    Vec scale = {0.0f, 0.0f, 0.0f};
    BreakupPiece *p = m_pieces;
    s32 i;

    scale.x = boss2_model_scale;
    scale.y = boss2_model_scale;
    scale.z = boss2_model_scale;
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(models[2].texlist));
    for (i = 0; i < 19; i++) {
        push_matrix();
        post_translate_matrix(&p->pos.x);
        rotate_matrix_by_node_angles(&p->ang_x, 0);
        scale_current_matrix(&scale.x);
        switch (p->state) {
        case 0:
        case 1:
            draw_chunk_model(node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x8810;
            color.a = p->alpha;
            set_constant_material(&color);
            set_chunk_material_override_pair(0xFF00, 0x800);
            set_chunk_blend(0x2500);
            draw_chunk_model(node->model);
            set_chunk_material_override_pair(0xFF00, 0);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
        node = node->sibling;
        p++;
    }
    current_scene_light->sub_801337F8();
}

void TBoss2BodyBreakUp::create_model() {
    TBreakUpMdlData *model = new TBreakUpMdlData(boss2_derolle_resource->models[5].model);
    body_breakup_model = model;
    spread_piece_velocities(model, 0x1C);
}

void TBoss2BodyBreakUp::free_model() {
    delete body_breakup_model;
    body_breakup_model = NULL;
}

TBoss2BodyBreakUp::TBoss2BodyBreakUp(TObject *parent, const f32 (*matrix)[4]) : TBoss2BreakUp(parent) {
    BreakupPiece *p;
    s32 i;
    Vec *v;
    p = m_pieces;
    m_matrix = matrix;
    push_matrix();
    set_matrix_identity(0);
    ::concat_matrix(NULL, m_matrix);
    v = &m_origin;
    v->x = breakup_zero;
    v->y = breakup_zero;
    v->z = breakup_zero;
    matrix_mult_vec(NULL, v, v);
    for (i = 0; i < 0x1C; i++, p++) {
        matrix_mult_vec(NULL, &body_breakup_model->m_records[i].pos, &p->pos);
        rotate_vector_by_matrix(0, &body_breakup_model->m_records[i].vel, &p->vel);
        p->vel.y = random_range(breakup_rise_speed_min, breakup_rise_speed_max);
        p->vel.z -= random_range(breakup_unit, breakup_back_speed_max);
        p->ang_x = 0;
        p->spin = (s32)(breakup_spin_max * rand_signed_unit());
        p->ang_z = 0;
        p->state = 0;
        p->alpha = breakup_unit;
    }
    pop_matrix();
}

TBoss2BodyBreakUp::~TBoss2BodyBreakUp() {
}

void TBoss2BodyBreakUp::run_task() {
    BreakupPiece *piece;
    s32 i;
    m_frames += 1;
    if (m_frames >= 0xA0) {
        queue_destruction();
        return;
    }
    i = 0;
    do {
        piece = &m_pieces[i];
        if (move_piece(piece) != 0) {
            if ((i % 2) == 0) {
                TObjBoss2CeilJunk::create_particle(&piece->pos, 0x170);
            }
        }
        i += 1;
    } while (i < 0x1C);
}

void TBoss2BodyBreakUp::render() {
    NJS_OBJECT *n;
    BreakupPiece *p;
    s32 i;
    BmlModelEntry *models;
    NJS_OBJECT *mesh;
    p = m_pieces;
    models = boss2_derolle_resource->models;
    mesh = models[5].model;
    {
        NJS_ARGB c = {1.0f, 1.0f, 1.0f, 1.0f};
        n = mesh->child;
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(models[2].texlist));
        push_matrix();
        for (i = 0; i < 0x1C; i++, n = n->sibling, p++) {
            push_matrix();
            post_translate_matrix(&p->pos.x);
            rotate_matrix_z(0, p->ang_z);
            rotate_matrix_x(0, p->ang_x);
            translate_matrix(0, -m_origin.x, -m_origin.y, -m_origin.z);
            ::concat_matrix(NULL, m_matrix);
            switch (p->state) {
            case 0:
            case 1:
                draw_chunk_model(n->model);
                break;
            case 2:
                saved_model_render_flags = model_render_flags;
                model_render_flags = saved_model_render_flags | 0x8810;
                c.a = p->alpha;
                set_constant_material(&c);
                set_chunk_material_override_pair(0xFF00, 0x800);
                set_chunk_blend(0x2500);
                draw_chunk_model(n->model);
                set_chunk_material_override_pair(0xFF00, 0);
                model_render_flags = saved_model_render_flags;
                break;
            }
            pop_matrix();
        }
    }
    pop_matrix();
    current_scene_light->sub_801337F8();
}

extern const f32 breakup_unit = 1.0f;
extern const f32 breakup_zero = 0.0f;
extern const f32 breakup_bounce_factor = -0.8f;
extern const f32 breakup_rise_speed_min = 2.0f;
extern const f32 breakup_rise_speed_max = 6.0f;
extern const f32 breakup_back_speed_max = 5.0f;
extern const f32 breakup_spin_max = 3400.0f;
extern const f32 random_unit_scale = 3.0517578e-05f;
extern const f32 random_angle_range = 65536.0f;
extern const f32 breakup_spread_scale = 1.1f;
extern const f32 breakup_gravity = 0.2f;
extern const f32 breakup_fade_step = 0.05f;
extern const f32 boss2_water_level = -10.0f;
extern const f32 boss2_tunnel_splash_y = -5.0f;
extern const f32 boss2_model_scale = 2.0f;
extern const f32 breakup_floor_height = 1.15f;
extern const f32 boss2_platform_max = 76.0f;
extern const f32 boss2_platform_min = -75.0f;
