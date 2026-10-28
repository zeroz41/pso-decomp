#include "types.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss8Dragon_8002CC48.h"
#include "pso/boss/TObjBoss2Tunnel_8007E418.h"
#include "pso/misc/TCameraCtrl_803D6538.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneDf2Bringer.h"

#include "pso/TParticleCtrl.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80096F54_TBreakUpMdl__data_8048FA00 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80096F54_TBreakUpMdl__data_8048FA00_size[sizeof(RecoveredGlobal_80096F54_TBreakUpMdl__data_8048FA00) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80096F54_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_80096F54_lbl_8058D490_size[sizeof(RecoveredGlobal_80096F54_lbl_8058D490) == 0x30 ? 1 : -1];

struct RecoveredGlobal_80096FD8_TBreakUpMdl__data_8048FA00 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80096FD8_TBreakUpMdl__data_8048FA00_size[sizeof(RecoveredGlobal_80096FD8_TBreakUpMdl__data_8048FA00) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80096FD8_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_80096FD8_lbl_8058D490_size[sizeof(RecoveredGlobal_80096FD8_lbl_8058D490) == 0x30 ? 1 : -1];

struct RecoveredGlobal_8009705C_TBreakUpMdl__data_8048FA00 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8009705C_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Seg_80096EBC { s32 a; f32 x; f32 y; f32 z; u8 pad[12]; };

struct Brk_80096EBC { s32 count; Seg_80096EBC *segs; };

struct Color_8009680C { f32 a; f32 r; f32 g; f32 b; };

struct Part_8009680C { u8 pos[0x18]; u8 rot[0x10]; };

struct Chunk_8009680C { s32 model; u8 pad[0x18]; };

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

struct RecoveredGlobal_80096F54_lbl_8058D490;
struct Part_80096AD8 { f32 pos[3]; f32 vel[3]; s32 f18; s32 f1c; s32 f20; s32 f24; };

struct Seg_80096AD8 { s32 f0; f32 a[3]; f32 b[3]; };

struct Model_80096AD8 { s32 count; Seg_80096AD8 *segs; };

struct BreakUp_80096AD8 {
    s32 f0;
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
s32 matrix_mult_vec(int, int, int);
s32 push_matrix();
s32 rotate_matrix_by_node_angles(void *, int);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern s32 TBreakUpMdl__vtable[];
extern RecoveredGlobal_80096F54_lbl_8058D490 identity_matrix;
u8 *init__11TBreakUpMdlFPviif(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
extern const f32 lbl_805D97C8;
void *mem_alloc(u32 size);
extern const f32 lbl_805D97CC;
void alloc_breakup_piece_records(Brk_80096EBC *arg0, void *arg1);
extern Color_8009680C breakup_default_color;
extern u32 saved_model_render_flags;
extern u32 model_render_flags;
void __ct__7TObjectFP7TObject(void *, void *);
s32 rand(void);
void rotate_vector_by_matrix(s32, void *, void *);
void rotate_matrix_y(s32, s32);
extern u8 breakup_default_param_row[];
extern s32 __vt__11TBreakUpMdl[];
extern s32 TBreakUpMdl__class_name;
extern const f32 lbl_805D97D0;
extern const f32 lbl_805D97D4;
u8 *TBreakUpMdl__ct(u8 *arg0, void *arg1, Model_80096AD8 *arg2, void *arg3, s32 arg4, void *arg5, s32 arg6);
void *__dt_deleting__11TBreakUpMdlFPvs(void *arg0, s16 arg1);
void mem_free(void *);

void TBreakUpMdl::render() {
    BreakUp_8009680C *self = (BreakUp_8009680C *)this;
    Part_8009680C *part;
    s32 i;
    if (self->texlist != 0) {
        TObjFish::set_global_param((s32)self->texlist);
    }
    saved_model_render_flags = model_render_flags;
    if (self->alpha < lbl_805D97C8) {
        Color_8009680C color = breakup_default_color;
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(0xFF00, 0x800);
        color.a = self->alpha;
        ((TUnk_80494AE0 *)((f32 *)&color))->set_chunk_material_color();
    }
    for (i = 0; i < self->count; i++) {
        part = &self->parts[i];
        push_matrix();
        post_translate_matrix(part->pos);
        rotate_matrix_by_node_angles(part->rot, 0);
        if (self->model->is_chunk != 0) {
            draw_ginja_model(self->model->chunks[i].model);
        } else {
            draw_chunk_model((void *)self->model->chunks[i].model);
        }
        pop_matrix();
    }
    set_chunk_material_override_pair(0xFF00, 0);
    model_render_flags = saved_model_render_flags;
}

#pragma push
#pragma fp_contract on
void TBreakUpMdl::run_task() {
    BreakUp_8009693C *self = (BreakUp_8009693C *)this;
    Part_8009693C *p;
    s32 i;
    f32 gravity;
    self->alpha -= self->fade;
    if (self->alpha <= lbl_805D97CC) {
        queue_destruction__7TObjectFv(self);
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

#pragma push
#pragma fp_contract on
void TBreakUpMdl::init_alpha(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) ((farg0 * (f32) arg1) + lbl_805D97C8);
}
#pragma pop

}
TBreakUpMdl::~TBreakUpMdl() {
    mem_free((void *)(*(void **)((s8 *)this + 0x34)));
    this->m_34 = 0;
}


#pragma push
#pragma fp_contract on
u8 *TBreakUpMdl__ct(u8 *break_up_mdl, void *arg1, Model_80096AD8 *arg2, void *arg3, s32 arg4, void *arg5, s32 arg6) {
    BreakUp_80096AD8 *self = (BreakUp_80096AD8 *)break_up_mdl;
    f32 base;
    f32 scale;
    Part_80096AD8 *part;
    s32 i;
    __ct__7TObjectFP7TObject(self, arg1);
    self->vtable = __vt__11TBreakUpMdl;
    self->f0 = TBreakUpMdl__class_name;
    self->model = arg2;
    if (arg3 == NULL) {
        ((TBreakUpMdl *)(&self->f38))->copy(breakup_default_param_row);
    } else {
        ((TBreakUpMdl *)(&self->f38))->copy(arg3);
    }
    self->f24 = arg4;
    self->count = self->model->count;
    base = self->f4C;
    scale = self->f50;
    self->parts = (Part_80096AD8 *)mem_alloc(self->count * 0x28);
    push_matrix_from(&identity_matrix);
    post_translate_matrix(arg5);
    rotate_matrix_y(0, arg6);
    for (i = 0; i < self->count; i++) {
        part = &self->parts[i];
        matrix_mult_vec(0, (int)self->model->segs[i].a, (int)part);
        rotate_vector_by_matrix(0, self->model->segs[i].b, part->vel);
        ((TObjBoss2Tunnel *)(part->vel))->clamp_velocity();
        part->vel[1] = scale * (lbl_805D97D0 * (f32)rand()) + base;
        part->f18 = 0;
        part->f1c = arg6;
        part->f20 = 0;
        part->f24 = (s32)(lbl_805D97D4 * rand_signed_unit());
    }
    pop_matrix();
    ((TBreakUpMdl *)break_up_mdl)->init_alpha(self->f38, self->f3C);
    self->f30 = self->f40;
    return break_up_mdl;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TBreakUpMdl::collect_node_positions(u8 *arg1, s32 arg2) {
    u8 *temp_r31;
    s32 temp_r30;
    s32 temp_r4;
    s32 var_r29;
    u8 *var_r28;
    var_r28 = arg1;
    var_r29 = arg2;
    do {
        push_matrix();
        compose_motion_node_matrix((var_r28));
        temp_r30 = *(s32 *)((s8 *)var_r28 + 0);
        if (!(temp_r30 & 8)) {
            temp_r31 = (u8 *)(*(s32 *)&this->m_flags + (var_r29 * 0x1C));
            temp_r4 = (long) (temp_r31 + 4);
            matrix_mult_vec(0, temp_r4, temp_r4);
            VecCopy((Vec *)(temp_r31 + 0x10), (const Vec *)(temp_r31 + 4));
            ((TObjBoss2Tunnel *)(temp_r31 + 0x10))->clamp_velocity();
            var_r29 += 1;
            *(s32 *)temp_r31 = *(s32 *)((s8 *)var_r28 + 4);
        }
        if (!(temp_r30 & 0x10)) {
            var_r29 = collect_node_positions(*(u8 **)((s8 *)var_r28 + 0x2C), var_r29);
        }
        pop_matrix();
        var_r28 = (u8 *)(*(u8 **)((s8 *)var_r28 + 0x30));
    } while (var_r28 != NULL);
    return var_r29;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TBreakUpMdl::build_node_records(u8 *arg1, s32 arg2) {
    u8 *temp_r31;
    s32 temp_r30;
    s32 temp_r4;
    s32 var_r29;
    u8 *var_r28;
    var_r28 = arg1;
    var_r29 = arg2;
    do {
        push_matrix();
        post_translate_matrix(var_r28 + 8);
        rotate_matrix_by_node_angles(var_r28 + 0x14, 0);
        scale_current_matrix(var_r28 + 0x20);
        temp_r30 = *(s32 *)((s8 *)var_r28 + 0);
        if (!(temp_r30 & 8)) {
            temp_r31 = (u8 *)(*(s32 *)&this->m_flags + (var_r29 * 0x1C));
            temp_r4 = (long) (temp_r31 + 4);
            matrix_mult_vec(0, temp_r4, temp_r4);
            VecCopy((Vec *)(temp_r31 + 0x10), (const Vec *)(temp_r31 + 4));
            ((TObjBoss2Tunnel *)(temp_r31 + 0x10))->clamp_velocity();
            var_r29 += 1;
            *(s32 *)temp_r31 = *(s32 *)((s8 *)var_r28 + 4);
        }
        if (!(temp_r30 & 0x10)) {
            var_r29 = build_node_records(*(u8 **)((s8 *)var_r28 + 0x2C), var_r29);
        }
        pop_matrix();
        var_r28 = (u8 *)(*(u8 **)((s8 *)var_r28 + 0x30));
    } while (var_r28 != NULL);
    return var_r29;
}
#pragma pop

void *__dt_deleting__11TBreakUpMdlFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0xC) = TBreakUpMdl__vtable;
        mem_free((void *)(*(s32 *)((s8 *)arg0 + 4)));
        *(s32 *)((s8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

void alloc_breakup_piece_records(Brk_80096EBC *arg0, void *boss2_tunnel) {
    s32 i;
    arg0->count = count_active_segments__15TObjBoss2TunnelFPv(boss2_tunnel);
    arg0->segs = (Seg_80096EBC *)mem_alloc(arg0->count * 0x1C);
    for (i = 0; i < arg0->count; i++) {
        arg0->segs[i].a = 0;
        arg0->segs[i].x = lbl_805D97CC;
        arg0->segs[i].y = lbl_805D97CC;
        arg0->segs[i].z = lbl_805D97CC;
    }
}

u8 *TBreakUpMdl::setup_pieces(s32 boss2_tunnel, s32 arg2, f32 farg0) {
    *(s32 * *)&this->m_next = &(*(RecoveredGlobal_80096F54_TBreakUpMdl__data_8048FA00 *)&TBreakUpMdl__vtable).value;
    *(s32 *)&this->m_prev = 1;
    alloc_breakup_piece_records((Brk_80096EBC *)(this), (void *)boss2_tunnel);
    bind_motion_context(arg2, farg0);
    push_matrix_from(&identity_matrix.value);
    this->collect_node_positions((u8 *)((void *) boss2_tunnel), 0);
    pop_matrix();
    return ((u8 *)this);
}

u8 *init__11TBreakUpMdlFPviif(u8 *break_up_mdl, s32 boss2_tunnel, s32 arg2, f32 farg0) {
    *(s32 * *)&((TBreakUpMdl *)break_up_mdl)->m_next = &(*(RecoveredGlobal_80096FD8_TBreakUpMdl__data_8048FA00 *)&TBreakUpMdl__vtable).value;
    *(s32 *)((s8 *)break_up_mdl + 8) = 0;
    alloc_breakup_piece_records((Brk_80096EBC *)(break_up_mdl), (void *)boss2_tunnel);
    bind_motion_context(arg2, farg0);
    push_matrix_from((void *)((u32) &(*(RecoveredGlobal_80096FD8_lbl_8058D490 *)&identity_matrix).value));
    ((TBreakUpMdl *)break_up_mdl)->collect_node_positions((u8 *)((void *) boss2_tunnel), 0);
    pop_matrix();
    return break_up_mdl;
}

typedef char RecoveredGlobal_8009705C_TBreakUpMdl__data_8048FA00_size[sizeof(RecoveredGlobal_8009705C_TBreakUpMdl__data_8048FA00) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8009705C_lbl_8058D490_size[sizeof(RecoveredGlobal_8009705C_lbl_8058D490) == 0x30 ? 1 : -1];
u8 *TBreakUpMdl::init_from_model(s32 boss2_tunnel) {
    *(s32 * *)&this->m_next = &(*(RecoveredGlobal_8009705C_TBreakUpMdl__data_8048FA00 *)&TBreakUpMdl__vtable).value;
    alloc_breakup_piece_records((Brk_80096EBC *)(this), (void *)boss2_tunnel);
    push_matrix_from((void *)((u32) &(*(RecoveredGlobal_8009705C_lbl_8058D490 *)&identity_matrix).value));
    this->build_node_records((u8 *)((void *) boss2_tunnel), 0);
    pop_matrix();
    this->m_prev = 0;
    return ((u8 *)this);
}

void TBreakUpMdl::copy(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_next = *(f32*)((char*)q + 0xc); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x10); *(f32 *)&this->m_down = *(f32*)((char*)q + 0x14); *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x18); }

