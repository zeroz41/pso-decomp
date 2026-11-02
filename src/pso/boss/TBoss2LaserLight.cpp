#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/boss/TBoss2LaserLight.h"
#include "pso/boss/TUnk_80482C58.h"
#include "pso/object/TObjLight.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct V3_80037264 { f32 x, y, z; };

struct S_80037264 {
    u8 pad0[0x18];
    void *vt;
    V3_80037264 recs[20];
    s32 a10c, a110, a114, a118, a11c, a120;
};

struct Obj_800372F0 {
    u8 pad0[0x1C];
    s32 f1C;
    s32 state;
    u32 req;
    u8 pad28[0x38 - 0x28];
    f32 f38;
    f32 f3C;
    void *light;
};

extern "C" {
s32 noop_laser__23TAdSinglePlyChrSelectGCFv(void *);
s32 TAdSinglePlyChrSelectGC__sub_80133508(void *);
extern const char *lbl_805D26C8;
extern void *__vt__16TBoss2LaserLight[];
void __ct__7TObjectFP7TObject(TObject *self, TObject *parent);

}

#pragma defer_codegen on


struct LaserLightParams_80037500 {
    u8 pad0[0x28];
    f32 position[2];
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
};

extern "C" TBoss2LaserLight *TBoss2LaserLight__ct(TBoss2LaserLight *self, TObject *parent, u32 arg2) {
    LaserLightParams_80037500 *p = (LaserLightParams_80037500 *)self;

    __ct__7TObjectFP7TObject(self, parent);
    *(void ***)((u8 *)self + 0x18) = __vt__16TBoss2LaserLight;
    self->m_name = lbl_805D26C8;
    self->m_1c = arg2;
    self->m_20 = 0;
    self->m_24 = 0;
    p->position[0] = 1.0f;
    p->position[1] = 1.0f;
    p->f30 = 0.2f;
    p->f34 = 2.0f;
    p->f38 = 0.0f;
    p->f3C = 0.0f;
    self->m_40 = TObjLight::alloc_light_slot();
    if (self->m_40 == 0) {
        self->queue_destruction();
        return self;
    }
    noop_laser__23TAdSinglePlyChrSelectGCFv((void *)self->m_40);
    ((TAdSinglePlyChrSelectGC *)self->m_40)->set_position(&p->position);
    ((TAdSinglePlyChrSelectGC *)self->m_40)->forward_to_field_0x14(&p->f38);
    return self;
}

TBoss2LaserLight::~TBoss2LaserLight() {
    if (*(void **)((s8 *)this + 0x40) != NULL) { ((TObjLight *)(*(void **)((s8 *)this + 0x40)))->unregister_and_free(); this->m_40 = 0; }
}

void TBoss2LaserLight__sub_80037480(void* p) { *(s32*)((char*)p + 0x24) = 1; }
void TBoss2LaserLight__sub_80037474(void* p) { *(s32*)((char*)p + 0x24) = 2; }

void TBoss2LaserLight::run_task() {
    Obj_800372F0 *self = (Obj_800372F0 *)this;
    f32 v;
    switch (self->state) {
    case 0:
    case 3:
        if (self->req == 1) {
            self->req = 0;
            self->state = 1;
            TAdSinglePlyChrSelectGC__sub_80133508(self->light);
        }
        break;
    case 1:
    case 2:
        if (self->req == 2) {
            self->req = 0;
            self->state = 3;
        }
        break;
    }
    switch (self->state) {
    case 0:
        break;
    case 1:
        v = self->f38;
        v += 3.0f;
        if (v >= 60.0f) {
            v = 60.0f;
            self->state = 2;
        }
        self->f38 = v;
        self->f3C = 40.0f + v;
        ((TAdSinglePlyChrSelectGC *)(self->light))->forward_to_field_0x14(&self->f38);
        ((TAdSinglePlyChrSelectGC *)(self->light))->set_vec3((void*)self->f1C);
        break;
    case 2:
        ((TAdSinglePlyChrSelectGC *)(self->light))->set_vec3((void*)self->f1C);
        break;
    case 3:
        v = self->f38;
        v -= 3.0f;
        if (v <= 0.0f) {
            v = 0.0f;
            self->state = 0;
            noop_laser__23TAdSinglePlyChrSelectGCFv(self->light);
        }
        self->f38 = v;
        self->f3C = 40.0f + v;
        ((TAdSinglePlyChrSelectGC *)(self->light))->forward_to_field_0x14(&self->f38);
        ((TAdSinglePlyChrSelectGC *)(self->light))->set_vec3((void*)self->f1C);
        break;
    }
}

void TBoss2LaserLight::render() {  }

TUnk_80482C58::TUnk_80482C58(TObject *parent, s32 arg2, s32 arg3) : TObject(parent) {
    s32 i;
    for (i = 0; i < 20; i++) {
        ((S_80037264 *)this)->recs[i].x = 0.0f;
        ((S_80037264 *)this)->recs[i].y = 0.0f;
        ((S_80037264 *)this)->recs[i].z = 0.0f;
    }
    ((S_80037264 *)this)->a10c = 0;
    ((S_80037264 *)this)->a110 = 0;
    ((S_80037264 *)this)->a114 = arg2;
    ((S_80037264 *)this)->a118 = arg3;
    ((S_80037264 *)this)->a11c = 0;
    ((S_80037264 *)this)->a120 = 0;
}

TUnk_80482C58::~TUnk_80482C58() {
    if (this->m_11c != NULL) { queue_destruction__7TObjectFv(this->m_11c); *(s32 *)((s8 *)this + 0x11C) = 0; }
}
