#pragma push

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

#include "pso/system/vector.h"
#include "pso/misc/TTecReverser.h"

struct V3_8022BEAC { s32 x; s32 y; s32 z; };

struct T_8022BEAC { u8 pad[0x20]; u8 f20[0xC]; u8 f2c[0x10]; f32 f3c; u8 pad2[0x2c]; s32 state; };

extern "C" {
void TObjRoomId__sub_80141CF4(void *, void *, f32);
extern V3_8022BEAC TTecLuker__render_scale_vec;
extern const f32 lbl_805DC7B0;
#pragma pop

#pragma push

void sub_8022C008__13TUnk_804CC148Fv(u8 *arg0);
void count_if_within_range__13TUnk_804CC148Fv(u8 *arg0);
extern u8 __vt__13TUnk_804CC148[];
}

struct Stack_8022BF8C_more_8022be64_1 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

extern "C" {
f32 vector_length(void *, f32);
s32 approach_vector_fixed_distance(int, void *, int, f32);
void queue_destruction__7TObjectFv(void *arg0);

void TTecReverser::sub_8022BE64(u8 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg1 + 0) = (f32) (*(f32 *)((s8 *)arg1 + 0) + (f32) arg2);
    *(f32 *)((s8 *)arg0 + 0x64) = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg0 + 0x70) = (f32) *(f32 *)((s8 *)arg1 + 8);
}

void TUnk_804CC148::render() {
    T_8022BEAC *self = (T_8022BEAC *)this;
    V3_8022BEAC v = TTecLuker__render_scale_vec;
    switch (this->state) {
    case 0:
        break;
    case 1:
        approach_vector_in_place(&scale, (const Vec *)&v, lbl_805DC7B0);
        break;
    }
    TObjRoomId__sub_80141CF4(self->f20, self->f2c, self->f3c);
}

void TUnk_804CC148::tick_lifetime() {
    this->state = 1;
    this->age = (this->age + 1);
    if ((f32) this->age > *(f32 *)((s8 *)this + 0x70)) {
        queue_destruction__7TObjectFv(this);
    }
}

void TUnk_804CC148::count_if_within_range() {
    u8 *arg0 = (u8 *)this;
    Stack_8022BF8C_more_8022be64_1 stack;
    f32 temp_f1;
    stack.sp8 = *(f32 *)((s8 *)arg0 + 0x20) - this->m_7c;
    stack.spC = *(f32 *)((s8 *)arg0 + 0x24) - *(f32 *)((s8 *)arg0 + 0x80);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x28);
    stack.sp10 = temp_f1 - this->m_84;
    if (vector_length(&stack.sp8, temp_f1) <= *(f32 *)((s8 *)arg0 + 0x64)) {
        this->state = (this->state + 1);
    }
}

void TUnk_804CC148::sub_8022C008() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    temp_r3 = (long) (arg0 + 0x20);
    approach_vector_fixed_distance(temp_r3, (u8 *)&this->m_7c, temp_r3, (f32) (*(f32 *)((s8 *)arg0 + 0x64)));
}

#pragma pop

#define sub_8022C008__13TUnk_804CC148Fv ((s32 (*)())sub_8022C008__13TUnk_804CC148Fv)
#define count_if_within_range__13TUnk_804CC148Fv ((s32 (*)(void *))count_if_within_range__13TUnk_804CC148Fv)
#define __vt__13TUnk_804CC148 ((s32 *)__vt__13TUnk_804CC148)
void free_collision_body_parts(void *);

void TUnk_804CC148::run_task() {

    switch (this->state) {
    case 0:
        sub_8022C008__13TUnk_804CC148Fv();
        count_if_within_range__13TUnk_804CC148Fv(this);
        return;
    case 1:
        this->tick_lifetime();
        return;
    }
}

}
TUnk_804CC148::~TUnk_804CC148() {
    if (*(void * *)&this->m_e8 != NULL) { free_collision_body_parts(*(void * *)&this->m_e8); }
}
#undef sub_8022C008__13TUnk_804CC148Fv
#undef count_if_within_range__13TUnk_804CC148Fv
#undef __vt__13TUnk_804CC148

#include "pso/player/TObjPlayer.h"

#define __vt__13TUnk_804CC148 ((void * *)__vt__13TUnk_804CC148)

extern "C" {
u16 get_entity_id(s32);
s32 get_type__10TObjPlayerFPv(void *p);
void *__ct__7TEffectFv(void *);
s32 init_collision_body_parts(u32, void *, s32);
u32 __ct__13TUnk_804AF8A0FP7TObject(u32, void *);
u32 __nw__7TObjectFUl(s32);
extern const f32 lbl_805DC7B4;
extern const f32 lbl_805DC7B8;
extern const f32 lbl_805DC7BC;
extern const f32 lbl_805DC7C0;
extern const f32 lbl_805DC7C4;
extern const f32 lbl_805DC7C8;
u8 *construct_area_technique_base(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

}
TUnk_804CC148::TUnk_804CC148(s32 arg1, s32 arg2, s32 arg4) : TEffect() {
    u32 var_r0;
    this->m_b4 = 0xFFFF;
    VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)arg2);
    this->m_7c = lbl_805DC7B4;
    *(f32 *)((s8 *)this + 0x80) = lbl_805DC7B4;
    this->m_84 = lbl_805DC7B4;
    this->m_b8 = 0;
    *(f32 *)((s8 *)this + 0x3C) = lbl_805DC7B8;
    *(f32 *)((s8 *)this + 0x40) = lbl_805DC7B8;
    *(f32 *)((s8 *)this + 0x44) = lbl_805DC7B8;
    this->m_74 = 0;
    this->source = arg1;
    if (arg4 < 0) {
        this->m_78 = 0;
    } else if (arg4 >= 0x1E) {
        this->m_78 = 0x1E;
    } else {
        this->m_78 = arg4;
    }
    *(s16 *)((s8 *)this + 0x7A) = TObjPlayer::get_level_tier(this->m_78);
    *(f32 *)((s8 *)this + 0x2C) = lbl_805DC7BC;
    *(f32 *)((s8 *)this + 0x30) = lbl_805DC7B8;
    *(f32 *)((s8 *)this + 0x34) = lbl_805DC7B8;
    *(f32 *)((s8 *)this + 0x38) = lbl_805DC7B8;
    *(f32 *)((s8 *)this + 0x64) = lbl_805DC7C0;
    *(f32 *)((s8 *)this + 0x70) = lbl_805DC7C4;
    *(f32 *)((s8 *)this + 0xBC) = lbl_805DC7B4;
    this->m_c0 = lbl_805DC7B4;
    *(f32 *)((s8 *)this + 0xC4) = lbl_805DC7B4;
    this->m_c8 = lbl_805DC7C8;
    *(f32 *)((s8 *)this + 0xCC) = lbl_805DC7B8;
    this->m_d0 = 0;
    if (get_entity_id(this->source) < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
            *(s32 *)((s8 *)this + 0xD4) = 0x40007;
        } else {
            *(s32 *)((s8 *)this + 0xD4) = 0x40107;
        }
    } else {
        *(s32 *)((s8 *)this + 0xD4) = 0x40007;
    }
    var_r0 = __nw__7TObjectFUl(0xAC);
    if (var_r0 != 0U) {
        var_r0 = __ct__13TUnk_804AF8A0FP7TObject(var_r0, this);
    }
    this->m_e8 = var_r0;
    if (this->m_e8 != 0U) {
        init_collision_body_parts(this->m_e8, ((u8 *)this) + 0xBC, 1);
    }
}

u8 *construct_area_technique_base(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 var_r0;
    __ct__7TEffectFv(arg0);
    *(void ***)((s8 *)arg0 + 0x18) = __vt__13TUnk_804CC148;
    ((TUnk_804CC148 *)arg0)->m_b4 = 0xFFFF;
    VecCopy((Vec *)(arg0 + 0x20), (const Vec *)arg2);
    VecCopy((Vec *)(arg0 + 0x7C), (const Vec *)arg3);
    *(f32 *)((s8 *)arg0 + 0x3C) = lbl_805DC7B8;
    *(f32 *)((s8 *)arg0 + 0x40) = lbl_805DC7B8;
    *(f32 *)((s8 *)arg0 + 0x44) = lbl_805DC7B8;
    ((TUnk_804CC148 *)arg0)->m_74 = 0;
    ((TUnk_804CC148 *)arg0)->m_b8 = 0;
    ((TUnk_804CC148 *)arg0)->source = arg1;
    if (arg4 < 0) {
        ((TUnk_804CC148 *)arg0)->m_78 = 0;
    } else if (arg4 >= 0x1E) {
        ((TUnk_804CC148 *)arg0)->m_78 = 0x1E;
    } else {
        ((TUnk_804CC148 *)arg0)->m_78 = arg4;
    }
    *(s16 *)((s8 *)arg0 + 0x7A) = TObjPlayer::get_level_tier(((TUnk_804CC148 *)arg0)->m_78);
    *(f32 *)((s8 *)arg0 + 0x2C) = lbl_805DC7BC;
    *(f32 *)((s8 *)arg0 + 0x30) = lbl_805DC7B8;
    *(f32 *)((s8 *)arg0 + 0x34) = lbl_805DC7B8;
    *(f32 *)((s8 *)arg0 + 0x38) = lbl_805DC7B8;
    *(f32 *)((s8 *)arg0 + 0x64) = lbl_805DC7C0;
    *(f32 *)((s8 *)arg0 + 0x70) = lbl_805DC7C4;
    *(f32 *)((s8 *)arg0 + 0xBC) = lbl_805DC7B4;
    ((TUnk_804CC148 *)arg0)->m_c0 = lbl_805DC7B4;
    *(f32 *)((s8 *)arg0 + 0xC4) = lbl_805DC7B4;
    ((TUnk_804CC148 *)arg0)->m_c8 = lbl_805DC7C8;
    *(f32 *)((s8 *)arg0 + 0xCC) = lbl_805DC7B8;
    ((TUnk_804CC148 *)arg0)->m_d0 = 0;
    if (get_entity_id(((TUnk_804CC148 *)arg0)->source) < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(((TUnk_804CC148 *)arg0)->source + 0x828)) != 0) {
            *(s32 *)((s8 *)arg0 + 0xD4) = 0x40007;
        } else {
            *(s32 *)((s8 *)arg0 + 0xD4) = 0x40107;
        }
    } else {
        *(s32 *)((s8 *)arg0 + 0xD4) = 0x40007;
    }
    var_r0 = __nw__7TObjectFUl(0xAC);
    if (var_r0 != 0U) {
        var_r0 = __ct__13TUnk_804AF8A0FP7TObject(var_r0, arg0);
    }
    ((TUnk_804CC148 *)arg0)->m_e8 = var_r0;
    if (((TUnk_804CC148 *)arg0)->m_e8 != 0U) {
        init_collision_body_parts(((TUnk_804CC148 *)arg0)->m_e8, arg0 + 0xBC, 1);
    }
    return arg0;
}

#undef __vt__13TUnk_804CC148
