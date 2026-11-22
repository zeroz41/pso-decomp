#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/item/TItemEffBringer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"

#include "types.h"
#include "dolphin/mtx.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"

const char *TItemEffBringer__class_name = "TItemEffBringer";

struct Bringer_8010834C {
    const char *f0;
    u8 pad4[0x18 - 4];
    void *vt;
    u8 pad1C[0x2C - 0x1C];
    s32 f2C;
    u8 pad30[0x38 - 0x30];
    Vec f38;
    u8 pad44[0x58 - 0x44];
    void *m_particles[10];
    s32 m_particle_count;
    Vec m_84;
};

extern "C" {
void *__ct__10TItemShootFPvPC3VecPC3Vecf(void *, u32, s32, s32, f32);
void subtract_vector(Vec*, Vec*);
void transform_point_by_current_matrix(void *, void *);
extern void *__vt__15TItemEffBringer[];
void *__ct__15TItemEffBringerFv(Bringer_8010834C *self, u32 arg1, Vec *src, s32 arg3, f32 farg0);
}
void TItemEffBringer::hook() {
    Vec work = this->m_pos;
    for (int i = 0; i != this->m_particle_count; i++) {
        spawn_particle_effect(&work, 0x9C);
        subtract_vector(&work, &this->m_84);
    }
}

TItemEffBringer::~TItemEffBringer() {
    for (int i = 0; i != this->m_particle_count; i++) {
        TParticleCtrl::release(this->m_particles[i]);
    }
}

#include "pso/player/TObjPlayer.h"


#pragma push
#pragma fp_contract on
void *__ct__15TItemEffBringerFv(Bringer_8010834C *self, u32 arg1, Vec *src, s32 arg3, f32 farg0) {
    Vec w;
    Vec out;
    Vec z;
    f32 r;
    f32 n;
    s32 i;
    __ct__10TItemShootFPvPC3VecPC3Vecf(self, arg1, (saddr)src, arg3, farg0);
    self->vt = __vt__15TItemEffBringer;
    self->f0 = TItemEffBringer__class_name;
    push_matrix();
    z.x = z.y = z.z = 0.0f;
    TObjPlayer::invert_matrix_in_place(0);
    transform_point_by_current_matrix(&z, &out);
    VecCopy((Vec *)&w, (const Vec *)src);
    subtract_vector((Vec*)((Vec *)&w), (Vec*)((Vec *)&out));
    pop_matrix();
    r = sin_table_lookup(self->f2C - (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(w.x, w.z)));
    if (r < 0.0f) {
        r *= -1.0f;
    }
    n = 4.0f * r + 1.0f;
    VecCopy((Vec *)&self->m_84, (const Vec *)&self->f38);
    self->m_84.x /= n;
    self->m_84.y /= n;
    self->m_84.z /= n;
    self->m_particle_count = (s32)n + 1;
    for (i = 0; i != self->m_particle_count; i++) {
        self->m_particles[i] = 0;
    }
    ((TObject *)self)->disallow_rendering();
    return self;
}
#pragma pop

void *TItemEffBringer::create(u32 arg0, saddr src, s32 arg2, f32 farg0) {
    if ((0.0f != farg0) && (arg0 != 0U)) {
        void *obj = TObject::operator new(0x90);
        if (obj != NULL) {
            obj = __ct__15TItemEffBringerFv((Bringer_8010834C *)(obj), arg0, (Vec *)(src), arg2, farg0);
        }
        return obj;
    }
    return NULL;
}

