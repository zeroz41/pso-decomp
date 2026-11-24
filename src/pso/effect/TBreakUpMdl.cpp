#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/animation/MotionContext.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stdlib.h>
#include "pso/effect/TBreakUpMdl.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/render/GinjaView.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"
#include "pso/enemy/bringer/TObjEneDf2Bringer.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/NinjaTypes.h"

static const BreakUpParamRow breakup_default_param_row = { 12, 0.07f, 1.5f, 0.9f, 0.12f, 0.5f, 0.5f };
const char *TBreakUpMdl::class_name = "TBreakUpMdl";
static const NJS_ARGB breakup_default_color = { 1.0f, 1.0f, 1.0f, 1.0f };

void BreakUpParamRow::copy(BreakUpParamRow *src) {
    fade_frames = src->fade_frames;
    fade = src->fade;
    speed = src->speed;
    damping = src->damping;
    gravity = src->gravity;
    rise_base = src->rise_base;
    rise_scale = src->rise_scale;
}


TBreakUpMdlData::TBreakUpMdlData(NJS_OBJECT *model) {
    alloc_breakup_piece_records(model);
    push_matrix_from(&identity_matrix);
    build_node_records(model, 0);
    pop_matrix();
    is_ginja = 0;
}

TBreakUpMdlData::TBreakUpMdlData(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame) {
    is_ginja = 0;
    alloc_breakup_piece_records(model);
    bind_motion_context(motion, frame);
    push_matrix_from(&identity_matrix);
    collect_node_positions(model, 0);
    pop_matrix();
}

TBreakUpMdlData::TBreakUpMdlData(long model, long motion, f32 frame) {
    is_ginja = 1;
    alloc_breakup_piece_records((NJS_OBJECT *)model);
    bind_motion_context((NJS_MOTION *)motion, frame);
    push_matrix_from(&identity_matrix);
    collect_node_positions((NJS_OBJECT *)model, 0);
    pop_matrix();
}

void TBreakUpMdlData::alloc_breakup_piece_records(NJS_OBJECT *model) {
    s32 i;
    m_count = count_visible_nodes(model);
    m_records = (BreakupNodeRecord *)mem_alloc(m_count * sizeof(BreakupNodeRecord));
    for (i = 0; i < m_count; i++) {
        m_records[i].model = NULL;
        m_records[i].pos.x = 0.0f;
        m_records[i].pos.y = 0.0f;
        m_records[i].pos.z = 0.0f;
    }
}

TBreakUpMdlData::~TBreakUpMdlData() {
    mem_free(m_records);
    m_records = NULL;
}

#pragma push
#pragma fp_contract on
s32 TBreakUpMdlData::build_node_records(NJS_OBJECT *node, s32 index) {
    BreakupNodeRecord *record;
    u32 flags;
    do {
        push_matrix();
        post_translate_matrix(node->pos);
        rotate_matrix_by_node_angles(node->ang, 0);
        scale_current_matrix(node->scl);
        flags = node->evalflags;
        if (!(flags & NJD_EVAL_HIDE)) {
            record = &m_records[index];
            matrix_mult_vec(NULL, &record->pos, &record->pos);
            VecCopy(&record->vel, &record->pos);
            normalize_vector_xz(&record->vel);
            index++;
            record->model = node->model;
        }
        if (!(flags & NJD_EVAL_BREAK)) {
            index = build_node_records(node->child, index);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
    return index;
}

s32 TBreakUpMdlData::collect_node_positions(NJS_OBJECT *node, s32 index) {
    BreakupNodeRecord *record;
    u32 flags;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        flags = node->evalflags;
        if (!(flags & NJD_EVAL_HIDE)) {
            record = &m_records[index];
            matrix_mult_vec(NULL, &record->pos, &record->pos);
            VecCopy(&record->vel, &record->pos);
            normalize_vector_xz(&record->vel);
            index++;
            record->model = node->model;
        }
        if (!(flags & NJD_EVAL_BREAK)) {
            index = collect_node_positions(node->child, index);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
    return index;
}

TBreakUpMdl::TBreakUpMdl(TObject *parent, TBreakUpMdlData *model, BreakUpParamRow *params, NJS_TEXLIST *texlist,
                         Vec *position, s32 rotation_y) : TObject(parent) {
    f32 base;
    f32 scale;
    BreakUpPiece *piece;
    s32 i;
    m_name = class_name;
    this->model = model;
    if (params == NULL) {
        this->params.copy((BreakUpParamRow *)&breakup_default_param_row);
    } else {
        this->params.copy(params);
    }
    this->texlist = texlist;
    piece_count = this->model->m_count;
    base = this->params.rise_base;
    scale = this->params.rise_scale;
    pieces = (BreakUpPiece *)mem_alloc(piece_count * sizeof(BreakUpPiece));
    push_matrix_from(&identity_matrix);
    post_translate_matrix(&position->x);
    rotate_matrix_y(NULL, rotation_y);
    for (i = 0; i < piece_count; i++) {
        piece = &pieces[i];
        matrix_mult_vec(NULL, &this->model->m_records[i].pos, &piece->pos);
        rotate_vector_by_matrix(0, &this->model->m_records[i].vel, &piece->velocity);
        normalize_vector_xz(&piece->velocity);
        piece->velocity.y = scale * (3.0517578e-05f * (f32)rand()) + base;
        piece->angle[0] = 0;
        piece->angle[1] = rotation_y;
        piece->angle[2] = 0;
        piece->spin = (s32)(5000.0f * rand_signed_unit());
    }
    pop_matrix();
    init_alpha(this->params.fade_frames, this->params.fade);
    speed = this->params.speed;
}

#pragma pop
TBreakUpMdl::~TBreakUpMdl() {
    mem_free(pieces);
    pieces = NULL;
}

#pragma push
#pragma fp_contract on

void TBreakUpMdl::init_alpha(s32 frames, f32 fade) {
    alpha = fade * (f32)frames + 1.0f;
}

void TBreakUpMdl::run_task() {
    BreakUpPiece *piece;
    s32 i;
    f32 gravity;
    alpha -= params.fade;
    if (alpha <= 0.0f) {
        queue_destruction();
    }
    gravity = params.gravity;
    for (i = 0; i < piece_count; i++) {
        piece = &pieces[i];
        piece->pos.x = piece->velocity.x * speed + piece->pos.x;
        piece->pos.y = piece->pos.y + piece->velocity.y;
        piece->pos.z = piece->velocity.z * speed + piece->pos.z;
        piece->velocity.y = piece->velocity.y - gravity;
        piece->angle[0] = piece->angle[0] + piece->spin;
        piece->angle[1] = piece->angle[1] + piece->spin / 2;
    }
    speed = speed * params.damping;
}
#pragma pop
void TBreakUpMdl::render() {
    BreakUpPiece *piece;
    s32 i;
    if (texlist != NULL) {
        TObjFish::set_global_param(texlist);
    }
    saved_model_render_flags = model_render_flags;
    if (alpha < 1.0f) {
        NJS_ARGB color = breakup_default_color;
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(0xFF00, 0x800);
        color.a = alpha;
        set_constant_material(&color);
    }
    for (i = 0; i < piece_count; i++) {
        piece = &pieces[i];
        push_matrix();
        post_translate_matrix(&piece->pos.x);
        rotate_matrix_by_node_angles(piece->angle, 0);
        if (model->is_ginja != 0) {
            draw_ginja_model(model->m_records[i].model);
        } else {
            draw_chunk_model(model->m_records[i].model);
        }
        pop_matrix();
    }
    set_chunk_material_override_pair(0xFF00, 0);
    model_render_flags = saved_model_render_flags;
}
