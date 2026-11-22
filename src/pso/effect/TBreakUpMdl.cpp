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
#include "pso/camera/TCameraCtrl_803D6538.h"
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

struct Seg_80096EBC { s32 a; f32 x; f32 y; f32 z; u8 pad[12]; };

struct Brk_80096EBC { s32 count; Seg_80096EBC *segs; };

struct Part_8009680C { u8 pos[0x18]; u8 rot[0x10]; };

struct Chunk_8009680C { void *model; u8 pad[0x18]; };

struct Model_8009680C { u8 pad0[4]; Chunk_8009680C *chunks; s32 is_chunk; };

struct BreakUp_8009680C {
    u8 pad0[0x1C];
    s32 count;
    Model_8009680C *model;
    void *texlist;
    f32 alpha;
    u8 pad2C[0x34 - 0x2C];
    Part_8009680C *parts;
};

struct Part_8009693C {
    f32 x, y, z;
    f32 vx, vy, vz;
    s32 rx, ry, rz;
    s32 spin;
};

struct BreakUp_8009693C {
    u8 pad0[0x1C];
    s32 count;
    u8 pad20[0x28 - 0x20];
    f32 alpha;
    u8 pad2C[0x30 - 0x2C];
    f32 speed;
    Part_8009693C *parts;
    u8 pad38[0x3C - 0x38];
    f32 fade;
    u8 pad40[0x44 - 0x40];
    f32 damping;
    f32 gravity;
};

struct Part_80096AD8 { Vec pos; f32 vel[3]; s32 f18; s32 f1c; s32 f20; s32 f24; };

struct Seg_80096AD8 { s32 f0; Vec a; f32 b[3]; };

struct Model_80096AD8 { s32 count; Seg_80096AD8 *segs; };

// The parameter row the ctor copies to +0x38 (the defaults when the caller passes none); field names follow
// the run_task/ctor uses (init_alpha(fade_frames, fade), speed, damping, gravity, the rise base and scale).
struct BreakUpParamRow {
    s32 fade_frames;
    f32 fade;
    f32 speed;
    f32 damping;
    f32 gravity;
    f32 rise_base;
    f32 rise_scale;
};

struct BreakUp_80096AD8 {
    saddr f0;
    u8 pad4[0x18 - 0x4];
    s32 *vtable;
    s32 count;
    Model_80096AD8 *model;
    s32 f24;
    u8 pad28[0x30 - 0x28];
    f32 f30;
    Part_80096AD8 *parts;
    s32 f38;
    f32 f3C;
    f32 f40;
    u8 pad44[0x4C - 0x44];
    f32 f4C;
    f32 f50;
};

extern "C" {
s32 rotate_matrix_by_node_angles(void *, int);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
void alloc_breakup_piece_records(Brk_80096EBC *arg0, NJS_OBJECT *model);
void __ct__7TObjectFP7TObject(void *, void *);
void rotate_vector_by_matrix(saddr, void *, void *);
extern s32 __vt__11TBreakUpMdl[];
static const BreakUpParamRow breakup_default_param_row = { 12, 0.07f, 1.5f, 0.9f, 0.12f, 0.5f, 0.5f };
const char *TBreakUpMdl__class_name = "TBreakUpMdl";
static const NJS_ARGB breakup_default_color = { 1.0f, 1.0f, 1.0f, 1.0f };
u8 *TBreakUpMdl__ct(u8 *arg0, void *arg1, Model_80096AD8 *arg2, void *arg3, s32 arg4, void *arg5, s32 arg6);
}

void TBreakUpMdl::copy(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_next = *(f32*)((char*)q + 0xc); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x10); *(f32 *)&this->m_down = *(f32*)((char*)q + 0x14); *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x18); }

TUnk_8048FA00::TUnk_8048FA00(long model) {
    alloc_breakup_piece_records((Brk_80096EBC *)this, (NJS_OBJECT *)model);
    push_matrix_from((void *)&identity_matrix);
    build_node_records((u8 *)model, 0);
    pop_matrix();
    m_8 = 0;
}

TUnk_8048FA00::TUnk_8048FA00(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame) {
    m_8 = 0;
    alloc_breakup_piece_records((Brk_80096EBC *)this, model);
    bind_motion_context(motion, frame);
    push_matrix_from((void *)&identity_matrix);
    collect_node_positions((u8 *)model, 0);
    pop_matrix();
}

TUnk_8048FA00::TUnk_8048FA00(long model, long motion, f32 frame) {
    m_8 = 1;
    alloc_breakup_piece_records((Brk_80096EBC *)this, (NJS_OBJECT *)model);
    bind_motion_context((NJS_MOTION *)motion, frame);
    push_matrix_from(&identity_matrix);
    collect_node_positions((u8 *)model, 0);
    pop_matrix();
}

void alloc_breakup_piece_records(Brk_80096EBC *arg0, NJS_OBJECT *model) {
    s32 i;
    arg0->count = count_visible_nodes(model);
    arg0->segs = (Seg_80096EBC *)mem_alloc(arg0->count * 0x1C);
    for (i = 0; i < arg0->count; i++) {
        arg0->segs[i].a = 0;
        arg0->segs[i].x = 0.0f;
        arg0->segs[i].y = 0.0f;
        arg0->segs[i].z = 0.0f;
    }
}

TUnk_8048FA00::~TUnk_8048FA00() {
    mem_free(this->m_records);
    this->m_records = 0;
}

#pragma push
#pragma fp_contract on
s32 TUnk_8048FA00::build_node_records(u8 *model, s32 arg2) {
    u8 *temp_r31;
    s32 temp_r30;
    Vec *pos;
    s32 index;
    u8 *var_r28;
    var_r28 = model;
    index = arg2;
    do {
        push_matrix();
        post_translate_matrix(var_r28 + 8);
        rotate_matrix_by_node_angles(var_r28 + 0x14, 0);
        scale_current_matrix(var_r28 + 0x20);
        temp_r30 = *(s32 *)((s8 *)var_r28 + 0);
        if (!(temp_r30 & 8)) {
            temp_r31 = (u8 *)m_records + index * 0x1C;
            pos = (Vec *)(temp_r31 + 4);
            matrix_mult_vec(NULL, pos, pos);
            VecCopy((Vec *)(temp_r31 + 0x10), (const Vec *)(temp_r31 + 4));
            normalize_vector_xz((Vec *)(temp_r31 + 0x10));
            index += 1;
            *(s32 *)temp_r31 = *(s32 *)((s8 *)var_r28 + 4);
        }
        if (!(temp_r30 & 0x10)) {
            index = build_node_records(*(u8 **)((s8 *)var_r28 + 0x2C), index);
        }
        pop_matrix();
        var_r28 = (u8 *)(*(u8 **)((s8 *)var_r28 + 0x30));
    } while (var_r28 != NULL);
    return index;
}

s32 TUnk_8048FA00::collect_node_positions(u8 *model, s32 arg2) {
    u8 *temp_r31;
    s32 temp_r30;
    Vec *pos;
    s32 index;
    u8 *var_r28;
    var_r28 = model;
    index = arg2;
    do {
        push_matrix();
        compose_motion_node_matrix((var_r28));
        temp_r30 = *(s32 *)((s8 *)var_r28 + 0);
        if (!(temp_r30 & 8)) {
            temp_r31 = (u8 *)m_records + index * 0x1C;
            pos = (Vec *)(temp_r31 + 4);
            matrix_mult_vec(NULL, pos, pos);
            VecCopy((Vec *)(temp_r31 + 0x10), (const Vec *)(temp_r31 + 4));
            normalize_vector_xz((Vec *)(temp_r31 + 0x10));
            index += 1;
            *(s32 *)temp_r31 = *(s32 *)((s8 *)var_r28 + 4);
        }
        if (!(temp_r30 & 0x10)) {
            index = collect_node_positions(*(u8 **)((s8 *)var_r28 + 0x2C), index);
        }
        pop_matrix();
        var_r28 = (u8 *)(*(u8 **)((s8 *)var_r28 + 0x30));
    } while (var_r28 != NULL);
    return index;
}

u8 *TBreakUpMdl__ct(u8 *break_up_mdl, void *parent, Model_80096AD8 *arg2, void *arg3, s32 texlist, void *arg5, s32 arg6) {
    BreakUp_80096AD8 *self = (BreakUp_80096AD8 *)break_up_mdl;
    f32 base;
    f32 scale;
    Part_80096AD8 *part;
    s32 i;
    __ct__7TObjectFP7TObject(self, parent);
    self->vtable = __vt__11TBreakUpMdl;
    self->f0 = (saddr)TBreakUpMdl__class_name;
    self->model = arg2;
    if (arg3 == NULL) {
        ((TBreakUpMdl *)(&self->f38))->copy((void *)&breakup_default_param_row);
    } else {
        ((TBreakUpMdl *)(&self->f38))->copy(arg3);
    }
    self->f24 = texlist;
    self->count = self->model->count;
    base = self->f4C;
    scale = self->f50;
    self->parts = (Part_80096AD8 *)mem_alloc(self->count * 0x28);
    push_matrix_from(&identity_matrix);
    post_translate_matrix(arg5);
    rotate_matrix_y(0, arg6);
    for (i = 0; i < self->count; i++) {
        part = &self->parts[i];
        matrix_mult_vec(NULL, &self->model->segs[i].a, &part->pos);
        rotate_vector_by_matrix(0, self->model->segs[i].b, part->vel);
        normalize_vector_xz((Vec *)(part->vel));
        part->vel[1] = scale * (3.0517578e-05f * (f32)rand()) + base;
        part->f18 = 0;
        part->f1c = arg6;
        part->f20 = 0;
        part->f24 = (s32)(5000.0f * rand_signed_unit());
    }
    pop_matrix();
    ((TBreakUpMdl *)break_up_mdl)->init_alpha(self->f38, self->f3C);
    self->f30 = self->f40;
    return break_up_mdl;
}

#pragma pop
TBreakUpMdl::~TBreakUpMdl() {
    mem_free((void *)(*(void **)((s8 *)this + 0x34)));
    this->m_34 = 0;
}

#pragma push
#pragma fp_contract on

void TBreakUpMdl::init_alpha(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) ((farg0 * (f32) arg1) + 1.0f);
}

void TBreakUpMdl::run_task() {
    BreakUp_8009693C *self = (BreakUp_8009693C *)this;
    Part_8009693C *p;
    s32 i;
    f32 gravity;
    self->alpha -= self->fade;
    if (self->alpha <= 0.0f) {
        ((TObject *)self)->queue_destruction();
    }
    gravity = self->gravity;
    for (i = 0; i < self->count; i++) {
        p = &self->parts[i];
        p->x = p->vx * self->speed + p->x;
        p->y = p->y + p->vy;
        p->z = p->vz * self->speed + p->z;
        p->vy = p->vy - gravity;
        p->rx = p->rx + p->spin;
        p->ry = p->ry + p->spin / 2;
    }
    self->speed = self->speed * self->damping;
}
#pragma pop
void TBreakUpMdl::render() {
    BreakUp_8009680C *self = (BreakUp_8009680C *)this;
    Part_8009680C *part;
    s32 i;
    if (self->texlist != 0) {
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(self->texlist));
    }
    saved_model_render_flags = model_render_flags;
    if (self->alpha < 1.0f) {
        NJS_ARGB color = breakup_default_color;
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(0xFF00, 0x800);
        color.a = self->alpha;
        set_constant_material((const NJS_ARGB *)(((f32 *)&color)));
    }
    for (i = 0; i < self->count; i++) {
        part = &self->parts[i];
        push_matrix();
        post_translate_matrix(part->pos);
        rotate_matrix_by_node_angles(part->rot, 0);
        if (self->model->is_chunk != 0) {
            draw_ginja_model(self->model->chunks[i].model);
        } else {
            draw_chunk_model(self->model->chunks[i].model);
        }
        pop_matrix();
    }
    set_chunk_material_override_pair(0xFF00, 0);
    model_render_flags = saved_model_render_flags;
}
