#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/enemy/TNeedleShoot.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"
#include "pso/math/AngleUnits.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

const char *TNeedleShoot__name = "TNeedleShoot";

struct Stack_802A4544 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
};

struct Base_802A4668 { char pad[0x18]; };
struct VObj_802A4668 : Base_802A4668 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};

struct Vec_802A47C8 {
    f32 x, y, z;
};

struct TNeedleShoot_802A47C8 {
    const char *f0;
    u8 pad04[0x18 - 0x04];
    void *vt;
    s32 f1c;
    f32 f20;
    f32 f24;
    u8 pad28[0x34 - 0x28];
    u16 f34;
    u8 pad36[0x3c - 0x36];
    f32 f3c;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4c;
    s32 f50;
    s32 f54;
    u8 pad58[0x68 - 0x58];
    void *f68;
    Vec_802A47C8 pos;
    u8 pad78[0x88 - 0x78];
    f32 f88;
    f32 f8c;
    f32 f90;
    Vec_802A47C8 dir;
    s32 fa0;
    s32 fa4;
    s32 fa8;
    f32 fac;
    s32 fb0;
    f32 fb4;
    s32 fb8;
};

extern "C" {
u8 *csnVector(f32 *, f32 *, s32);
void init_collision_body_parts(void *, void *, int);
void *__ct__14TObjCollidableFP7TObject(void *, void *);
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *, void *);
f32 vector_length(Vec_802A47C8 *);
void normalize_vector(Vec_802A47C8 *);
extern s32 __vt__12TNeedleShoot[];
extern void *tl_06;
TNeedleShoot_802A47C8 *TNeedleShoot__ct(TNeedleShoot_802A47C8 *self, s32 arg1, Vec_802A47C8 *from, Vec_802A47C8 *to);
void free_collision_body_parts(void *);

void TNeedleShoot::vfunc_8() {  }

#pragma push
#pragma opt_common_subs off
void TNeedleShoot::check_wall_hit() {
    typedef char sp8_offset[(offsetof(Stack_802A4544, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802A4544, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802A4544, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_802A4544, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_802A4544, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_802A4544, sp1C) == 0x14) ? 1 : -1];
    Stack_802A4544 stack;
    u8 *temp_r3;
    stack.sp8 = *(f32 *)((s8 *)((u8 *)this) + 0x28);
    stack.spC = this->m_2c;
    stack.sp10 = *(f32 *)&this->unk_30;
    stack.sp14 = *(f32 *)&this->m_6c;
    stack.sp18 = *(f32 *)&this->unk_70;
    stack.sp1C = this->m_74;
    temp_r3 = (u8 *)(csnVector(&stack.sp8, &stack.sp14, 0x100));
    if (temp_r3 != NULL) {
        VecCopy((Vec *)(((u8 *)this) + 0x6C), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4)));
        this->vfunc_6();
    }
}
#pragma pop

void TNeedleShoot::render() {
    NJS_ARGB color = {1.0f, 1.0f, 1.0f, 1.0f};
    debug_draw_sphere((const Vec *)((u8 *)this + 0x6C), &color, 10.0f);
}

void TObjEneMe1GiGueMissile::update_lifetime() {
    f32 temp_f1;

    temp_f1 = this->m_24;
    if (temp_f1 > *(f32 *)&this->unk_20) {
        TObject::queue_destruction();
        return;
    }
    this->m_24 = (f32) (temp_f1 + *(f32 *)&this->_padAC);
}

void TNeedleShoot__sub_802A4668(void *arg0) {
    struct VObj_802A4668 *o = (struct VObj_802A4668 *)arg0;
    o->m5();
}

#pragma push
#pragma fp_contract on
void TNeedleShoot::update_position() {
    VecCopy((Vec *)((u8 *)this + 0x28), (const Vec *)((u8 *)this + 0x6C));
    *(f32 *)&this->m_6c = (*(f32 *)&this->m_94 * *(f32 *)&this->_padAC) + *(f32 *)&this->m_6c;
    *(f32 *)&this->unk_70 = (*(f32 *)&this->unk_98 * *(f32 *)&this->_padAC) + *(f32 *)&this->unk_70;
    this->m_74 = (this->m_9c * *(f32 *)&this->_padAC) + this->m_74;
    check_wall_hit();
}
#pragma pop

void TNeedleShoot::run_task() {
    if ((s32) this->m_b8 == 1) {
        update_position();
        ((TObjEneMe1GiGueMissile *)this)->update_lifetime();
        return;
    }
    TNeedleShoot__sub_802A4668(this);
}

}

TNeedleShoot::~TNeedleShoot() {
    if (*(void **)((s8 *)this + 0x68) != NULL) { free_collision_body_parts(*(void **)((s8 *)this + 0x68)); this->m_68 = 0; }
}


TNeedleShoot_802A47C8 *TNeedleShoot__ct(TNeedleShoot_802A47C8 *self, s32 arg1, Vec_802A47C8 *from, Vec_802A47C8 *to) {
    f32 dx;
    f32 dz;
    f32 dy;
    void *p;
    __ct__7TObjectFP7TObject(self, tl_06);
    self->vt = ((s32 *)&__vt__12TNeedleShoot);
    self->f0 = TNeedleShoot__name;
    self->f34 = 0xFFFF;
    dx = to->x - from->x;
    dz = to->z - from->z;
    dy = to->y - from->y;
    self->pos.x = from->x;
    self->pos.y = from->y;
    self->pos.z = from->z;
    self->fa0 = RADIANS_TO_ANGLE * atan2_float(fabs_float(dy), fabs_float(dz));
    self->fa4 = RADIANS_TO_ANGLE * atan2_float(dx, dz);
    self->fa8 = RADIANS_TO_ANGLE * atan2_float(dx, dy);
    self->fb4 = 4.0f;
    self->f88 = 1.0f;
    self->f8c = 1.0f;
    self->f90 = 1.0f;
    self->f24 = 0.0f;
    self->f1c = arg1;
    self->fac = 5.0f;
    self->f20 = 1000.0f;
    self->fb0 = 0;
    self->fb8 = 1;
    self->dir.x = dx;
    self->dir.y = dy;
    self->dir.z = dz;
    if (0.0f != vector_length(&self->dir)) {
        normalize_vector(&self->dir);
    }
    self->f3c = 0.0f;
    self->f40 = 0.0f;
    self->f44 = 0.0f;
    self->f48 = 5.0f;
    self->f4c = 1.0f;
    self->f50 = 1;
    self->f54 = 0x40007;
    p = __nw__7TObjectFUl(0xAC);
    if (p != NULL) {
        p = __ct__14TObjCollidableFP7TObject(p, self);
    }
    self->f68 = p;
    if (self->f68 != NULL) {
        init_collision_body_parts(self->f68, &self->f3c, 1);
    }
    return self;
}

int TNeedleShoot::vfunc_6() { TObject::queue_destruction(); }
int TNeedleShoot::queue_destruction() { TObject::queue_destruction(); }
void TNeedleShoot::vfunc_9(void *) {  }
