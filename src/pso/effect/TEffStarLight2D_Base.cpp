#include "types.h"
#include "pso/effect/TEffStarLight2D_Base.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/effect/TEffStarLight2D.h"
#include "pso/misc/TUnk_8048E640.h"
#include "pso/object/TObjMotion.h"

#include <stddef.h>
#include "pso/player/TObjPlayer_80141D1C.h"
struct Stack_80084C10 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

struct RecoveredGlobal_80084C10_lbl_804393AC {
    s32 value;
    u8 remaining[0x10];
};

struct Stack_80084DD4 {
    f32 sp8;
    f32 spC;
    s8 sp10;
    s8 sp11;
    s8 sp12;
    s8 sp13;
    s32 sp14;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_80084DD4_lbl_8048E640 { s32 value; u8 remaining[0x30]; };

struct Sprite_80084C64 {
    f32 x;
    f32 y;
    u8 a;
    u8 r;
    u8 g;
    u8 b;
    s32 flags;
    u8 pad14[4];
};

struct Eff_80084C64 {
    u8 pad0[0x38];
    u8 pos[0x30];
    f32 x;
    f32 y;
    f32 alpha;
    u8 pad74[0x10];
    s32 r;
    s32 g;
    s32 b;
    void *sub;
};

extern "C" {
s32 TObjRoomId__sub_80141CF4(void *, void *, int, int, int, void *, f32);
extern RecoveredGlobal_80084C10_lbl_804393AC star_light_2d_base_color;
extern const f32 lbl_805D9450;
u8 * __ct__15TEffStarLight2DFPvPvP7TObject(void *, s32, s32, s32);
u8 * __ct__8TObjBaseFP7TObject(void *);
void * __nw__7TObjectFUl(s32, s32);
extern s32 lbl_8048E640[];
extern void *tl_particle;
void __dl__7TObjectFPv(void *);

void *TEffStarLight2D_Base__create(void *arg0, s32 _w1) {
    void *o = __nw__7TObjectFUl(0x94, _w1);
    if (o != NULL) {
        o = TEffStarLight2D_Base__ct((u8 *)o, (s32)tl_particle, (s32)arg0);
    }
    return o;
}

typedef char RecoveredGlobal_80084C10_lbl_804393AC_size[sizeof(RecoveredGlobal_80084C10_lbl_804393AC) == 0x14 ? 1 : -1];
void TUnk_8048E640::render() {
    s32 arg0 = (s32)this;
    typedef char sp8_offset[(offsetof(Stack_80084C10, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80084C10, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80084C10, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80084C10, sp14) == 0xC) ? 1 : -1];
    Stack_80084C10 stack;
    stack.sp8 = *(s32 *)((s8 *)&star_light_2d_base_color.value + 0);
    stack.spC = *(s32 *)((s8 *)&star_light_2d_base_color.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&star_light_2d_base_color.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&star_light_2d_base_color.value + 0xC);
    TObjRoomId__sub_80141CF4((void *)(arg0 + 0x38), (void *)&stack.sp8, (int) (*(s32 *)((s8 *)&star_light_2d_base_color.value + 8)), (int) (*(s32 *)((s8 *)&star_light_2d_base_color.value + 4)), (int) (*(s32 *)((s8 *)&star_light_2d_base_color.value + 0)), (void *)&star_light_2d_base_color.value, lbl_805D9450);
}

void TUnk_8048E640::run_task() {
    Eff_80084C64 *self = (Eff_80084C64 *)this;
    Sprite_80084C64 s;
    if (self->sub == NULL) {
        return;
    }
    ((void (*)(void *, void *))copy_position__15TEffStarLight2DFPv)(self->sub, self->pos);
    s.x = self->x;
    s.y = self->y;
    s.a = self->alpha;
    s.r = (f32)self->r;
    s.g = (f32)self->g;
    s.b = (f32)self->b;
    s.flags = 0;
    ((TEffStarLight2D *)(self->sub))->copy_from_subobject(&s);
}

void *__dt__20TEffStarLight2D_BaseFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8048E640;
        if (*(void **)((s8 *)arg0 + 0x90) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x90)); *(s32 *)((s8 *)arg0 + 0x90) = 0; }
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TEffStarLight2D_Base__ct(u8 *arg0, s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_80084DD4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80084DD4, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80084DD4, sp10) == 0x8) ? 1 : -1];
    typedef char sp11_offset[(offsetof(Stack_80084DD4, sp11) == 0x9) ? 1 : -1];
    typedef char sp12_offset[(offsetof(Stack_80084DD4, sp12) == 0xA) ? 1 : -1];
    typedef char sp13_offset[(offsetof(Stack_80084DD4, sp13) == 0xB) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80084DD4, sp14) == 0xC) ? 1 : -1];
    Stack_80084DD4 stack;
    s32 temp_r4;
    u8 *eff_star_light2_d;
    u8 *var_r0;
    __ct__8TObjBaseFP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80084DD4_lbl_8048E640 *)&lbl_8048E640).value;
    ((TUnk_8048E640 *)(arg0))->apply_object_set_data((void *)arg2);
    stack.sp8 = ((TUnk_8048E640 *)arg0)->scale.x;
    stack.spC = ((TUnk_8048E640 *)arg0)->scale.y;
    stack.sp10 = (s8) *(f32 *)((s8 *)arg0 + 0x70);
    stack.sp11 = (s8) ((TUnk_8048E640 *)arg0)->set_params[0];
    stack.sp12 = (s8) *(s32 *)((s8 *)arg0 + 0x88);
    temp_r4 = ((TUnk_8048E640 *)arg0)->set_params[2];
    stack.sp13 = (s8) temp_r4;
    stack.sp14 = 0;
    eff_star_light2_d = (u8 *)(((u8 *)__nw__7TObjectFUl(0x4C, temp_r4)));
    var_r0 = eff_star_light2_d;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(__ct__15TEffStarLight2DFPvPvP7TObject(eff_star_light2_d, (s32)(arg0 + 0x38), (s32) &stack.sp8, (*(s32 *)&tl_particle)));
    }
    *(u8 **)((s8 *)arg0 + 0x90) = var_r0;
    return arg0;
}

}

#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int VecCopy__FP3VecPC3Vec(void*);

int copy_position__15TEffStarLight2DFPv(void* p) { return VecCopy__FP3VecPC3Vec((char*)p + 0x2c); }

struct N_800850CC { u8 pad[0xc]; N_800850CC *next; u8 pad10[0x10]; };
struct T_800850CC { u8 pad[0x14]; N_800850CC *head; };
struct S_80084EBC;
struct V2_80084EBC;
void TEffStarLight2D__sub_80084EBC(S_80084EBC *s, V2_80084EBC *p0, V2_80084EBC *p1, V2_80084EBC *p2, V2_80084EBC *p3, s32 i);

#pragma opt_propagation off
void render__15TEffStarLight2DFv(T_800850CC *arg0) {
    s32 n = 0;
    N_800850CC *nx;
    N_800850CC *p;

    for (p = arg0->head; p != NULL; p = p->next) {
        if (p != NULL && p->next != NULL) {
            nx = p->next;
            if (((TObject *)p)->all_parents_unqueued_for_destruction() != 0 &&
                ((TObject *)nx)->all_parents_unqueued_for_destruction() != 0) {
                TEffStarLight2D__sub_80084EBC((S_80084EBC *)arg0, (V2_80084EBC *)((u8 *)p + 0x20), (V2_80084EBC *)((u8 *)p + 0x28), (V2_80084EBC *)((u8 *)nx + 0x28), (V2_80084EBC *)((u8 *)nx + 0x20), n);
                n++;
            }
        }
    }
    set_default_alpha_blend();
}
#pragma opt_propagation reset

}
