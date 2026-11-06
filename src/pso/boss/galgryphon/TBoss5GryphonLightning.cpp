#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "pso/system/task/TObject_80019A50.h"
#include "types.h"

TBoss5GryphonLightning::~TBoss5GryphonLightning() {
    if (m_44 != nullptr) { queue_destruction__7TObjectFv(m_44); m_44 = nullptr; }
    if (m_40 != nullptr) { queue_destruction__7TObjectFv(m_40); m_40 = nullptr; }
    if (m_3c != nullptr) { queue_destruction__7TObjectFv(m_3c); m_3c = nullptr; }
    if (m_38 != nullptr) { queue_destruction__7TObjectFv(m_38); m_38 = nullptr; }
}

struct Vec_80324F4C { f32 x, y, z; };

struct Seg_80324F4C { Vec_80324F4C v; f32 f; };

struct Self_80324F4C {
    s32 f0;
    char pad4[0x14];
    void *vt;
    f32 scale;
    Vec_80324F4C v20;
    Vec_80324F4C v2c;
    void *eff38;
    void *eff3c;
    void *eff40;
    void *eff44;
    Seg_80324F4C segs[4];
    f32 f88;
    f32 f8c;
    s32 n90;
    s32 n94;
};

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
int VecCopy__FP3VecPC3Vec(void *, void *);
void *spawn_continuous_particle_effect_with_flags(void *, s32, s32);
extern s32 __vt__22TBoss5GryphonLightning[];
extern s32 lbl_805D4180;

Self_80324F4C *TBoss5GryphonLightning__ct(Self_80324F4C *self, void *parent,
                                          Vec_80324F4C *pos, f32 p_scale) {
    register s32 dpos, dlen;
    s32 i;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__22TBoss5GryphonLightning;
    self->f0 = lbl_805D4180;
    VecCopy__FP3VecPC3Vec((void *)&self->v20, (void *)pos);
    VecCopy__FP3VecPC3Vec((void *)&self->v2c, (void *)&self->v20);
    self->scale = p_scale;
    self->n94 = 0;
    self->eff38 = spawn_continuous_particle_effect_with_flags(&self->v20, 0x20c, 0x40);
    self->eff3c = spawn_continuous_particle_effect_with_flags(&self->v20, 0x20e, 0x40);
    self->eff40 = spawn_continuous_particle_effect_with_flags(&self->v2c, 0x20f, 0x40);
    self->eff44 = spawn_continuous_particle_effect_with_flags(&self->v2c, 0x216, 0x40);
    for (i = 0; i < 4; i++) {
        VecCopy__FP3VecPC3Vec((void *)&self->segs[i].v, (void *)&self->v20);
        self->segs[i].f = 0.0f;
    }
    self->f88 = 0.0f;
    self->f8c = 0.0f;
    self->n90 = 1;
    return self;
}
}
#pragma pop
