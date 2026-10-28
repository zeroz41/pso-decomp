#include "types.h"
#include "pso/player/TUnk_804820A8.h"
#include "pso/boss/TBoss8Dragon_8002CC48.h"
#include "pso/player/TObjPlayer_8002E784.h"
#include "pso/system/vector.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/player/TUnk_804820C0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803E2D70.h"

struct Base_8002E784 { char pad[0xC]; };
struct VObj_8002E784 : Base_8002E784 {
    virtual void m0(int);
};

typedef struct Unit { u8 pad[0x2C]; } Unit;

typedef struct Boss2 { u8 pad[0x20]; Unit units[0x13]; } Boss2;

struct Rec_8002ECC4 { u8 pad[0x10]; u8 f10[0xC]; };

struct Obj_8002ECC4 { u8 pad[4]; Rec_8002ECC4 *recs; };

struct Rec_8002ED48 { u8 pad[4]; u8 f4[0xC]; u8 tail[0xC]; };

struct Obj_8002ED48 { u8 pad[4]; Rec_8002ED48 *recs; };

typedef struct Vec_8002EA64 {
    f32 x, y, z;
} Vec_8002EA64;

typedef struct Src_8002EA64 {
    u8 pad0[4];
    Vec_8002EA64 a;
    Vec_8002EA64 b;
} Src_8002EA64;

typedef struct Part_8002EA64 {
    Vec_8002EA64 pos;
    Vec_8002EA64 vel;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
    s32 unk28;
} Part_8002EA64;

typedef struct Obj_8002EA64 {
    u8 pad0[0x18];
    s32 *vtbl;
    u8 pad1C[4];
    Part_8002EA64 parts[19];
} Obj_8002EA64;

struct Color_8002E818 { f32 a, r, g, b; };

struct BreakupNode_8002E818 {
    u8 pad0[4];
    void *model;
    u8 pad8[0x28];
    BreakupNode_8002E818 *next;
};

extern "C" {
extern const f32 lbl_805D8258;
extern u8 *lbl_805D4BA4;
struct VObj8002EB88_8002eb88_8002E784 *shared_breakup_model;
void *lbl_805D4B8C;
f32 lbl_805D4B90;
void __sinit_TObjPlayer_8002E784_cpp(void);
void queue_destruction__7TObjectFv(void *arg0);
s32 create_particle__17TObjBoss2CeilJunkFv(void *, s32);
f32 vec3_add_to(void *, void *);
extern const f32 lbl_805D822C;
extern const f32 lbl_805D8230;
extern const f32 lbl_805D8250;
extern const f32 lbl_805D8254;
extern const f32 lbl_805D8264;
extern const f32 lbl_805D8268;
extern const f32 lbl_805D826C;
extern const f32 lbl_805D8270;
extern const f32 lbl_805D8274;
void scale_matrix(int, f32, f32, f32);
void post_translate_matrix(void *pos);
void rotate_matrix_by_node_angles(void *angles, s32 mode);
void scale_current_matrix(Vec_8002EA64 *scale);
void TObjLight__sub_801337F8(s32 light);
extern s32 current_scene_light;
extern u32 model_render_flags;
extern u32 saved_model_render_flags;
extern Color_8002E818 lbl_804355F0;
extern Vec_8002EA64 lbl_80435600;
void set_matrix_identity(u8 *arg0);
void rotate_vector_by_matrix(int, void *, void *);
void push_matrix(void);
s32 pop_matrix(void);
extern const f32 lbl_805D824C;
void TObjPlayer__sub_8002ECC4(Obj_8002ECC4 *self, s32 n);
extern const f32 lbl_805D8260;
void TObjPlayer__sub_8002ED48(Obj_8002ED48 *self, s32 n);
extern s32 lbl_804820A8[];
extern const f32 lbl_805D8228;
extern const f32 lbl_805D8234;
extern const f32 lbl_805D8238;
extern const f32 lbl_805D823C;
extern const f32 lbl_805D8240;
Obj_8002EA64 *TObjPlayer__sub_8002EA64(Obj_8002EA64 *arg0, void *arg1, Vec_8002EA64 *arg2);
struct VObj8002EB88_8002eb88_8002E784 {
    char pad[0xC];
    virtual void m0(int);
};

void __ct__7TObjectFP7TObject(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 rand();

void TObjPlayer::clear_target_ref() {
    if (lbl_805D4B8C != NULL) {
        ((VObj_8002E784 *)lbl_805D4B8C)->m0(1);
    }
    lbl_805D4B8C = NULL;
}

void TObjPlayer__sub_8002E7C8(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = ((TAdSinglePlyChrSelectGC *)((void *)0x10))->alloc();
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TBreakUpMdl *)temp_r3)->init_from_model(*(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D4BA4 + 0x42C)) + 0x58)));
    }
    (*(u8 * *)&lbl_805D4B8C) = (unsigned char *) ((void *) var_r0);
    TObjPlayer__sub_8002ECC4((Obj_8002ECC4 *)((void *) var_r0), 0x1C);
}

void TUnk_804820A8::render() {
    u8 *res = *(u8 **)(lbl_805D4BA4 + 0x42C);
    u8 *mdl = *(u8 **)(res + 0x68);
    Color_8002E818 color = lbl_804355F0;
    BreakupNode_8002E818 *node = *(BreakupNode_8002E818 **)(mdl + 0x2C);
    Vec_8002EA64 scale = lbl_80435600;
    Part_8002EA64 *p = ((Obj_8002EA64 *)this)->parts;
    s32 i;

    scale.x = lbl_805D8260;
    scale.y = lbl_805D8260;
    scale.z = lbl_805D8260;
    TObjFish::set_global_param(*(s32 *)(res + 0x2C));
    for (i = 0; i < 19; i++) {
        push_matrix();
        post_translate_matrix(&p->pos);
        rotate_matrix_by_node_angles(&p->unk18, 0);
        scale_current_matrix(&scale);
        switch (p->unk28) {
        case 0:
        case 1:
            draw_chunk_model(node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x8810;
            color.a = p->unk24;
            set_chunk_material_color__13TUnk_80494AE0Fv(&color.a);
            set_chunk_material_override_pair(0xFF00, 0x800);
            set_chunk_blend(0x2500);
            draw_chunk_model(node->model);
            set_chunk_material_override_pair(0xFF00, 0);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
        node = node->next;
        p++;
    }
    TObjLight__sub_801337F8(current_scene_light);
}

void TUnk_804820A8::run_task() {
    u8 *boss2_ceil_junk;
    s32 var_r29;
    Boss2 *self;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) += 1;
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x1C) >= 0xA0) {
        queue_destruction__7TObjectFv((this));
        return;
    }
    var_r29 = 0;
    do {
        boss2_ceil_junk = (u8 *)&((Boss2 *)((u8 *)this))->units[var_r29];
        if (TObjPlayer__sub_8002EDCC(boss2_ceil_junk) != 0) {
            if ((var_r29 % 2) == 0) {
                create_particle__17TObjBoss2CeilJunkFv(boss2_ceil_junk, 0x171);
            }
        }
        var_r29 += 1;
    } while (var_r29 < 0x13);
}

void *__dt__13TUnk_804820A8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804820A8;
        ((TObjPlayer *)arg0)->deleting_dtor((s16)(0));
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

struct VObj8002EB88_8002eb88_8002E784;
Obj_8002EA64 *TObjPlayer__sub_8002EA64(Obj_8002EA64 *arg0, void *arg1, Vec_8002EA64 *arg2) {
    f32 zero;
    f32 scale;
    Part_8002EA64 *p;
    Vec_8002EA64 *v;
    s32 i;
    ((TUnk_804820C0 *)arg0)->init_base();
    scale = lbl_805D8240;
    zero = lbl_805D8228;
    arg0->vtbl = lbl_804820A8;
    for (i = 0, p = arg0->parts; i < 19; i++, p++) {
        VecCopy((Vec *)&p->pos, (const Vec *)arg2);
        vec3_add_to(&p->pos, &(*(Src_8002EA64 **)((u8 *)shared_breakup_model + 4))[i].a);
        v = &p->vel;
        VecCopy((Vec *)v, (const Vec *)(&(*(Src_8002EA64 **)((u8 *)shared_breakup_model + 4))[i].b));
        v->y = lerp__9TDeadSpotFff(lbl_805D8234, lbl_805D8238);
        v->z -= lerp__9TDeadSpotFff(lbl_805D8228, lbl_805D823C);
        p->unk18 = TObjPlayer::calc_random_scaled();
        p->unk1C = (s32)(scale * rand_signed_unit());
        p->unk20 = TObjPlayer::calc_random_scaled();
        p->unk28 = 0;
        p->unk24 = zero;
    }
    return arg0;
}

void TObjPlayer__sub_8002EB88(void) {
    if (shared_breakup_model != NULL) {
        shared_breakup_model->m0(1);
    }
    shared_breakup_model = NULL;
}

extern s32 lbl_804820C0[];

void TObjPlayer::create_breakup_model() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = ((TAdSinglePlyChrSelectGC *)((void *)0x10))->alloc();
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TBreakUpMdl *)temp_r3)->init_from_model(*(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D4BA4 + 0x42C)) + 0x68)));
    }
    (*(u8 * *)&shared_breakup_model) = (unsigned char *) ((void *) var_r0);
    TObjPlayer__sub_8002ED48((Obj_8002ED48 *)((void *) var_r0), 0x13);
    TObjPlayer__sub_8002ECC4((Obj_8002ECC4 *)((*(u8 * *)&shared_breakup_model)), 0x13);
}

void *TObjPlayer::deleting_dtor(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804820C0;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_804820C0::init_base() {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804820C0;
    *(u32 *)&this->unk_1C = 0;
    return this;
}

extern const f32 lbl_805D8244;
extern const f32 lbl_805D8248;

void TObjPlayer__sub_8002ECC4(Obj_8002ECC4 *self, s32 n) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, lbl_805D824C, lbl_805D822C, lbl_805D824C);
    for (i = 0; i < n; i++) {
        rotate_vector_by_matrix(0, self->recs[i].f10, self->recs[i].f10);
    }
    pop_matrix();
}

void TObjPlayer__sub_8002ED48(Obj_8002ED48 *self, s32 n) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, lbl_805D8260, lbl_805D8260, lbl_805D8260);
    for (i = 0; i < n; i++) {
        rotate_vector_by_matrix(0, self->recs[i].f4, self->recs[i].f4);
    }
    pop_matrix();
}

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
s32 TObjPlayer__sub_8002EDCC(u8 *arg0) {
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
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - lbl_805D8250);
        vec3_add_to(arg0, arg0 + 0xC);
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x10);
        if (temp_f1 < lbl_805D822C) {
            temp_f2 = *(f32 *)((s8 *)arg0 + 4);
            if (temp_f2 < lbl_805D8264) {
                temp_f3 = *(f32 *)((s8 *)arg0 + 0);
                temp_f4 = *(f32 *)((s8 *)arg0 + 8);
                if ((temp_f3 <= lbl_805D8268) && (temp_f3 >= lbl_805D826C) && (temp_f4 <= lbl_805D8270) && (temp_f4 >= lbl_805D8274)) {
                    *(f32 *)((s8 *)arg0 + 0x10) = (f32) (temp_f1 * lbl_805D8230);
                    *(s32 *)((s8 *)arg0 + 0x28) = 2;
                } else if (temp_f2 < lbl_805D8258) {
                    var_r30 = 1;
                    *(s32 *)((s8 *)arg0 + 0x28) = 1;
                }
            }
        }
        *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) + temp_r31);
        *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) + (temp_r31 * 2));
        break;
    case 2:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - lbl_805D8250);
        vec3_add_to(arg0, arg0 + 0xC);
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) (*(f32 *)((s8 *)arg0 + 0x24) - lbl_805D8254);
        if (*(f32 *)((s8 *)arg0 + 0x24) < lbl_805D822C) {
            *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805D822C;
            *(s32 *)((s8 *)arg0 + 0x28) = 3;
        }
        *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) + temp_r31);
        *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) + (temp_r31 * 2));
        break;
    case 1:
        *(f32 *)((s8 *)arg0 + 4) = (f32) ((lbl_805D8250 * *(f32 *)((s8 *)arg0 + 0x10)) + *(f32 *)((s8 *)arg0 + 4));
        *(f32 *)((s8 *)arg0 + 8) = (f32) (*(f32 *)((s8 *)arg0 + 8) + *(f32 *)((s8 *)arg0 + 0x14));
        break;
    }
    return var_r30;
}
#pragma pop

void __sinit_TObjPlayer_8002E784_cpp(void) {
    lbl_805D4B90 = lbl_805D8258;
}

__declspec(section ".ctors") static void *const __sinit_TObjPlayer_8002E784_cpp_ref = (void *)__sinit_TObjPlayer_8002E784_cpp;

s32 TObjPlayer::calc_random_scaled() {
    return (s32) (lbl_805D8248 * (lbl_805D8244 * (f32) rand()));
}

#pragma push
#pragma opt_common_subs off

#pragma pop

}
