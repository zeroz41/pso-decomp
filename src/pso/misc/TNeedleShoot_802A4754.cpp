#include "types.h"
#include "pso/misc/TNeedleShoot.h"


struct Vec_802A47C8 {
    f32 x, y, z;
};

struct TNeedleShoot_802A47C8 {
    u32 f0;
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
f32 fabs_float(f32);
f32 atan2_float(f32, f32);
void init_collision_body_parts(void *, void *, int);
void *__ct__14TObjCollidableFP7TObject(void *, void *);
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *, void *);
f32 vector_length(Vec_802A47C8 *);
void normalize_vector(Vec_802A47C8 *);
extern const f64 lbl_80466688[];
extern s32 __vt__12TNeedleShoot[];
extern u32 TNeedleShoot__name;
extern void *tl_06;
extern const f32 lbl_805DDF6C;
extern const f32 lbl_805DDF70;
extern const f32 lbl_805DDF74;
extern const f32 lbl_805DDF78;
extern const f32 lbl_805DDF7C;
TNeedleShoot_802A47C8 *TNeedleShoot__ct(TNeedleShoot_802A47C8 *self, s32 arg1, Vec_802A47C8 *from, Vec_802A47C8 *to);
void free_collision_body_parts(void *);
int queue_destruction__7TObjectFv(void*);

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
    self->fa0 = lbl_80466688[0] * atan2_float(fabs_float(dy), fabs_float(dz));
    self->fa4 = lbl_80466688[0] * atan2_float(dx, dz);
    self->fa8 = lbl_80466688[0] * atan2_float(dx, dy);
    self->fb4 = lbl_805DDF6C;
    self->f88 = lbl_805DDF70;
    self->f8c = lbl_805DDF70;
    self->f90 = lbl_805DDF70;
    self->f24 = lbl_805DDF74;
    self->f1c = arg1;
    self->fac = lbl_805DDF78;
    self->f20 = lbl_805DDF7C;
    self->fb0 = 0;
    self->fb8 = 1;
    self->dir.x = dx;
    self->dir.y = dy;
    self->dir.z = dz;
    if (lbl_805DDF74 != vector_length(&self->dir)) {
        normalize_vector(&self->dir);
    }
    self->f3c = lbl_805DDF74;
    self->f40 = lbl_805DDF74;
    self->f44 = lbl_805DDF74;
    self->f48 = lbl_805DDF78;
    self->f4c = lbl_805DDF70;
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

int TNeedleShoot::vfunc_6() { return queue_destruction__7TObjectFv(this); }
int TNeedleShoot::queue_destruction() { return queue_destruction__7TObjectFv(this); }
void TNeedleShoot::vfunc_9(void *) {  }

