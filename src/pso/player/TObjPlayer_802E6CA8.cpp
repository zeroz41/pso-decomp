#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804E3BD8.h"
#include "pso/player/TUnk_804E3BC0.h"
#include "pso/player/TUnk_804E3BA8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/unk/text_80087278.h"

struct VB_802E74E4 { u8 pad[0xC]; };

struct VObj_802E74E4 : VB_802E74E4 { virtual void m0(int); };

struct Col_802E6CB0 { f32 a; s32 b; s32 c; s32 d; };

struct Part_802E6CB0 { u8 pad0[0x18]; s32 f18; u8 pad1c[4]; s32 f20; f32 f24; s32 type; };

struct Node_802E6CB0 { u8 pad0[4]; s32 model; u8 pad8[0x28]; Node_802E6CB0 *next; };

struct Vec_802E6F10 { f32 x, y, z; };

struct Bone_802E6F10 { u8 pad0[4]; Vec_802E6F10 pos; Vec_802E6F10 rot; };

struct Model_802E6F10 { u8 pad0[4]; Bone_802E6F10 *bones; };

struct Part_802E6F10 {
    Vec_802E6F10 pos;
    Vec_802E6F10 rot;
    s32 f18;
    s32 f1C;
    s32 f20;
    f32 f24;
    s32 f28;
};

struct Vec_802E708C { f32 x, y, z; };

struct Col_802E708C { f32 a; s32 b; s32 c; s32 d; };

struct Part_802E708C { u8 pad0[0x18]; u8 rot[0xC]; f32 f24; s32 type; };

struct Node_802E708C { u8 pad0[4]; s32 model; u8 pad8[0x24]; Node_802E708C *child; Node_802E708C *next; };

typedef struct Vec_802E72DC { f32 x, y, z; } Vec_802E72DC;

typedef struct Src_802E72DC { u8 pad0[4]; Vec_802E72DC a; Vec_802E72DC b; } Src_802E72DC;

typedef struct Tbl_802E72DC { u8 pad0[4]; Src_802E72DC *items; } Tbl_802E72DC;

typedef struct Piece_802E72DC {
    Vec_802E72DC pos;
    Vec_802E72DC rot;
    s32 x18;
    s32 x1C;
    s32 x20;
    f32 x24;
    s32 x28;
} Piece_802E72DC;

typedef struct Obj_802E72DC {
    u8 pad0[0x18];
    s32 *vt;
    Tbl_802E72DC *tbl;
    u8 pad20[4];
    s32 count;
    Piece_802E72DC *pieces;
} Obj_802E72DC;

extern "C" {
f32 vec3_add_to(void *, void *);
extern const f32 lbl_805DE9CC;
extern const f32 lbl_805DE9D0;
extern const f32 lbl_805DE9E8;
extern const f32 lbl_805DE9EC;
extern const float lbl_805DE9F0;
extern const f32 lbl_805DE9FC;
extern const f32 lbl_805DEA00;
extern const f32 lbl_805DEA04;
extern const f32 lbl_805DEA08;
extern const f32 lbl_805DEA0C;
s32 TObjPlayer__sub_802E76C8(u8 *arg0);
void mem_free(void *p);
void __dl__7TObjectFPv(void *);
extern s32 __vt__13TUnk_804E3BD8[];
u8 *__dt__13TUnk_804E3BD8Fv(u8 *arg0, s16 arg1);
s32 TObjLight__sub_801337F8(s32);
u8 *queue_boss_effect__10TObjPlayerFPv(s32);
s32 rotate_matrix_z(int, s32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
}
void set_chunk_blend(u32 x);
void draw_chunk_model(void *arg0);
extern Col_802E6CB0 lbl_80472C9C;
extern s32 current_scene_light;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern "C" {
f32 lerp__9TDeadSpotFff(f32, f32);
f32 rand_signed_unit();
s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *arg0);
s32 rotate_vector_by_matrix(int, void *, void *);
extern s32 lbl_804E3BA8[];
extern const f32 lbl_805DE9C8;
extern const f32 lbl_805DE9D4;
extern const f32 lbl_805DE9D8;
extern const f32 lbl_805DE9DC;
extern const f32 lbl_805DE9E0;
s32 rotate_matrix_by_node_angles(void *, int);
s32 scale_current_matrix(Vec_802E708C *);
extern Col_802E708C lbl_80472C80;
extern Vec_802E708C lbl_80472C90;
extern const f32 lbl_805DE9F8;
void queue_destruction__7TObjectFv(void *arg0);
void TObjPlayer__sub_802E7640(void *);
extern s32 lbl_80472C68[];
extern s32 lbl_804E3BC0[];
Obj_802E72DC *TObjPlayer__sub_802E72DC(Obj_802E72DC *arg0, s32 arg1, Vec_802E72DC *arg2, s32 arg3);
void *__dt__13TUnk_804E3BA8Fv(void *arg0, s16 arg1);
void TObjPlayer__sub_802E7084(void);
void TObjPlayer__sub_802E7088(void);
void *__dt__13TUnk_804E3BC0Fv(void *arg0, s16 arg1);
void TObjPlayer__sub_802E746C(void);
void TObjPlayer__sub_802E7470(void);
s32 *init_from_model__11TBreakUpMdlFl(s32 *, s32);
void TObjPlayer__sub_802E75B8(void *, s32 *);
s32 scale_matrix(int, f32, f32, f32);
extern const f32 lbl_805DE9E4;
void __ct__7TObjectFP7TObject(void *);
void *mem_alloc(u32 size);

    extern int multiplay_texture_f512_handle;
int TObjPlayer::get_instance() {  return multiplay_texture_f512_handle; }

void TUnk_804E3BA8::render() {
    Node_802E6CB0 *node;
    Part_802E6CB0 *part;
    s32 i;
    u8 *fx = queue_boss_effect__10TObjPlayerFPv(2);
    Col_802E6CB0 c = lbl_80472C9C;
    node = *(Node_802E6CB0 **)((s8 *)fx + 0x2C);
    part = *(Part_802E6CB0 * *)&this->unk_28;
    TObjPlayer::draw_effect();
    push_matrix();
    for (i = 0; i < this->m_24; i++) {
        push_matrix();
        post_translate_matrix(part);
        rotate_matrix_z(0, part->f20);
        rotate_matrix_x(0, part->f18);
        translate_matrix(0, -this->m_30, -*(f32 *)&this->unk_34, -this->m_38);
        TObjPlayer::concat_matrix(0, *(s32 *)&this->unk_2C);
        switch (part->type) {
        case 0:
        case 1:
            draw_chunk_model((void *)node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x8810;
            c.a = part->f24;
            set_constant_material((const NJS_ARGB *)(((f32 *)&c)));
            set_chunk_material_override_pair(0xFF00, 0x800);
            set_chunk_blend(0x2500);
            draw_chunk_model((void *)node->model);
            set_chunk_material_override_pair(0xFF00, 0);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
        node = node->next;
        part++;
    }
    pop_matrix();
    TObjLight__sub_801337F8(current_scene_light);
}

void TUnk_804E3BA8::run_task() {
    s32 off;
    s32 i;
    (*(s32 *)(unk_1C + 4))++;
    if (*(s32 *)(unk_1C + 4) >= 0xA0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    for (i = 0, off = 0; i < m_24; i++, off += 0x2C) {
        if (TObjPlayer__sub_802E76C8(*(u8 **)unk_28 + off) != 0 && i % 2 == 0) {
            spawn_particle_effect(*(u8 **)unk_28 + off, 0x200);
        }
    }
}

void *__dt__13TUnk_804E3BA8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E3BA8;
        __dt__13TUnk_804E3BD8Fv((u8 *)arg0, (s16)(0));
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjPlayer::init_breakup_pieces(void *arg1, s32 arg2) {
    Part_802E6F10 *part;
    s32 i;
    this->init_zeroed_object();
    *(u8 **)((s8 *)((u8 *)this) + 0x18) = ((u8 *)&lbl_804E3BA8);
    ((TUnk_804E3BD8 *)((u8 *)this))->alloc_breakup_model(((s32)queue_boss_effect__10TObjPlayerFPv(2)));
    *(s32 *)((s8 *)((u8 *)this) + 0x2C) = arg2;
    part = *(Part_802E6F10 * *)&this->m_28;
    push_matrix();
    set_matrix_identity(0);
    TObjPlayer::concat_matrix(0, *(s32 *)((s8 *)((u8 *)this) + 0x2C));
    (*(Vec_802E6F10 *)((s8 *)((u8 *)this) + 0x30)).z = (*(Vec_802E6F10 *)((s8 *)((u8 *)this) + 0x30)).y = (*(Vec_802E6F10 *)((s8 *)((u8 *)this) + 0x30)).x = lbl_805DE9CC;
    matrix_mult_vec(0, ((u8 *)this) + 0x30, ((u8 *)this) + 0x30);
    for (i = 0; i < this->texture_id; i++) {
        matrix_mult_vec(0, &(*(Model_802E6F10 **)((s8 *)((u8 *)this) + 0x1C))->bones[i].pos, &part->pos);
        rotate_vector_by_matrix(0, &(*(Model_802E6F10 **)((s8 *)((u8 *)this) + 0x1C))->bones[i].rot, &part->rot);
        part->rot.y = lerp__9TDeadSpotFff(lbl_805DE9D4, lbl_805DE9D8);
        part->rot.z -= lerp__9TDeadSpotFff(lbl_805DE9C8, lbl_805DE9DC);
        part->f18 = 0;
        part->f1C = lbl_805DE9E0 * rand_signed_unit();
        part->f20 = 0;
        part->f28 = 0;
        part->f24 = lbl_805DE9C8;
        part++;
    }
    pop_matrix();
    return ((u8 *)this);
}

void TObjPlayer__sub_802E7084(void) {  }
void TObjPlayer__sub_802E7088(void) {  }

void TUnk_804E3BC0::render() {
    Node_802E708C *node;
    Part_802E708C *part;
    u8 *fx = queue_boss_effect__10TObjPlayerFPv(3);
    Col_802E708C c = lbl_80472C80;
    node = *(Node_802E708C **)((s8 *)fx + 0x2C);
    Vec_802E708C s = lbl_80472C90;
    s.z = s.y = s.x = lbl_805DE9F8;
    part = *(Part_802E708C * *)&this->unk_28;
    TObjPlayer::draw_effect();
    for (node = node->child; node != NULL; node = node->next) {
        push_matrix();
        post_translate_matrix(part);
        rotate_matrix_by_node_angles(part->rot, 0);
        scale_current_matrix(&s);
        switch (part->type) {
        case 0:
        case 1:
            draw_chunk_model((void *)node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x8810;
            c.a = part->f24;
            set_constant_material((const NJS_ARGB *)((&c)));
            set_chunk_material_override_pair(0xFF00, 0x800);
            set_chunk_blend(0x2500);
            draw_chunk_model((void *)node->model);
            set_chunk_material_override_pair(0xFF00, 0);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
        part++;
    }
    TObjLight__sub_801337F8(current_scene_light);
}

void TUnk_804E3BC0::run_task() {
    s32 off;
    s32 i;
    (*(s32 *)(unk_1C + 4))++;
    if (*(s32 *)(unk_1C + 4) >= 0xA0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    for (i = 0, off = 0; i < m_24; i++, off += 0x2C) {
        if (TObjPlayer__sub_802E76C8(*(u8 **)unk_28 + off) != 0 && i % 2 == 0) {
            spawn_particle_effect(*(u8 **)unk_28 + off, 0x200);
        }
    }
}

void *__dt__13TUnk_804E3BC0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E3BC0;
        __dt__13TUnk_804E3BD8Fv((u8 *)arg0, (s16)(0));
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Obj_802E72DC *TObjPlayer__sub_802E72DC(Obj_802E72DC *arg0, s32 arg1, Vec_802E72DC *arg2, s32 arg3) {
    s32 n;
    Piece_802E72DC *p;
    Vec_802E72DC *q;
    s32 i;
    ((TObjPlayer *)arg0)->init_zeroed_object();
    arg0->vt = lbl_804E3BC0;
    if (arg3 >= 0 && (u32)arg3 < 6) {
        n = lbl_80472C68[arg3];
    } else {
        n = -1;
    }
    if (n > 0) {
        ((TUnk_804E3BD8 *)arg0)->alloc_breakup_model((s32)find_model_node((u32)queue_boss_effect__10TObjPlayerFPv(3), n));
        TObjPlayer__sub_802E7640(arg0);
        p = arg0->pieces;
        for (i = 0; i < arg0->count; i++, p++) {
            VecCopy((Vec *)&p->pos, (const Vec *)arg2);
            vec3_add_to(&p->pos, &arg0->tbl->items[i].a);
            q = &p->rot;
            VecCopy((Vec *)q, (const Vec *)&arg0->tbl->items[i].b);
            q->y = lerp__9TDeadSpotFff(lbl_805DE9D4, lbl_805DE9D8);
            q->z -= lerp__9TDeadSpotFff(lbl_805DE9C8, lbl_805DE9DC);
            p->x18 = TObjPlayer::calc_random_scaled();
            p->x1C = lbl_805DE9E0 * rand_signed_unit();
            p->x20 = TObjPlayer::calc_random_scaled();
            p->x28 = 0;
            p->x24 = lbl_805DE9C8;
        }
    } else {
        queue_destruction__7TObjectFv(arg0);
    }
    return arg0;
}

void TObjPlayer__sub_802E746C(void) {  }
void TObjPlayer__sub_802E7470(void) {  }
void TUnk_804E3BD8::alloc_breakup_model(s32 arg1) {
    s32 *temp_r4;
    s32 *var_r0;

    var_r0 = (s32 *)::operator new(0x10);
    if (var_r0 != NULL) {
        var_r0 = init_from_model__11TBreakUpMdlFl(var_r0, arg1);
    }
    *(s32 **)((s8 *)this + 0x1C) = var_r0;
    temp_r4 = *(s32 **)((s8 *)this + 0x1C);
    this->m_24 = (s32) *temp_r4;
    TObjPlayer__sub_802E75B8(this, temp_r4);
    *(s32 *)&(this->unk_28) = (s32)mem_alloc(this->m_24 * 0x2C);
}
}

TUnk_804E3BD8::~TUnk_804E3BD8() {
    VObj_802E74E4 *temp_r3;
    mem_free((void *)(*(s32 *)((s8 *)this + 0x28)));
    temp_r3 = *(VObj_802E74E4 **)((s8 *)this + 0x1C);
    if (temp_r3 != NULL) {
        temp_r3->m0(1);
    }
}

void *TObjPlayer::init_zeroed_object() {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804E3BD8;
    *(u32 *)&this->m_20 = 0;
    *(u32 *)((s8 *)this + 0x1C) = 0;
    *(u32 *)&this->texture_id = 0;
    (*(u32 *)&this->m_28) = 0;
    return this;
}

void TObjPlayer__sub_802E75B8(void *arg0, s32 *) {
    TUnk_804E3BD8 *self = (TUnk_804E3BD8 *)arg0;
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, lbl_805DE9E4, lbl_805DE9CC, lbl_805DE9E4);
    for (i = 0; i < *(s32 *)*(Model_802E6F10 **)self->unk_1C; i++) {
        rotate_vector_by_matrix(0, &(*(Model_802E6F10 **)self->unk_1C)->bones[i].rot, &(*(Model_802E6F10 **)self->unk_1C)->bones[i].rot);
    }
    pop_matrix();
}

void TObjPlayer__sub_802E7640(void *arg0) {
    TUnk_804E3BD8 *self = (TUnk_804E3BD8 *)arg0;
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, lbl_805DE9F8, lbl_805DE9F8, lbl_805DE9F8);
    for (i = 0; i < *(s32 *)*(Model_802E6F10 **)self->unk_1C; i++) {
        rotate_vector_by_matrix(0, &(*(Model_802E6F10 **)self->unk_1C)->bones[i].pos, &(*(Model_802E6F10 **)self->unk_1C)->bones[i].pos);
    }
    pop_matrix();
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
s32 TObjPlayer__sub_802E76C8(u8 *arg0) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_r0;
    s32 temp_r31;
    s32 var_r30;
    var_r30 = 0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x28);
    temp_r31 = *(s32 *)((s8 *)arg0 + 0x1C);
    switch (temp_r0) {
    case 0:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - lbl_805DE9E8);
        vec3_add_to(arg0, arg0 + 0xC);
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x10);
        if (temp_f1 < lbl_805DE9CC) {
            temp_f2 = *(f32 *)((s8 *)arg0 + 4);
            if (temp_f2 < lbl_805DE9FC) {
                temp_f3 = *(f32 *)((s8 *)arg0 + 0);
                temp_f4 = *(f32 *)((s8 *)arg0 + 8);
                if ((temp_f3 <= lbl_805DEA00) && (temp_f3 >= lbl_805DEA04) && (temp_f4 <= lbl_805DEA08) && (temp_f4 >= lbl_805DEA0C)) {
                    *(f32 *)((s8 *)arg0 + 0x10) = (f32) (temp_f1 * lbl_805DE9D0);
                    *(s32 *)((s8 *)arg0 + 0x28) = 2;
                } else if (temp_f2 < (*(const f32 *)&lbl_805DE9F0)) {
                    var_r30 = 1;
                    *(s32 *)((s8 *)arg0 + 0x28) = 1;
                }
            }
        }
        *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) + temp_r31);
        *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) + (temp_r31 * 2));
        break;
    case 2:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - lbl_805DE9E8);
        vec3_add_to(arg0, arg0 + 0xC);
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) (*(f32 *)((s8 *)arg0 + 0x24) - lbl_805DE9EC);
        if (*(f32 *)((s8 *)arg0 + 0x24) < lbl_805DE9CC) {
            *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805DE9CC;
            *(s32 *)((s8 *)arg0 + 0x28) = 3;
        }
        *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) + temp_r31);
        *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) + (temp_r31 * 2));
        break;
    case 1:
        *(f32 *)((s8 *)arg0 + 4) = (f32) ((lbl_805DE9E8 * *(f32 *)((s8 *)arg0 + 0x10)) + *(f32 *)((s8 *)arg0 + 4));
        *(f32 *)((s8 *)arg0 + 8) = (f32) (*(f32 *)((s8 *)arg0 + 8) + *(f32 *)((s8 *)arg0 + 0x14));
        break;
    }
    return var_r30;
}
#pragma pop

f32 lbl_805D6910 = lbl_805DE9F0;
