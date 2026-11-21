#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/text_803D96A8.h"
#include "types.h"
#include "pso/effect/photon/TPhotonLaser.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/effect/photon/TPhotonLeilla.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"

#pragma readonly_strings on


const char *TPhotonLaser__name = "TPhotonLaser";



struct Laser_801AC36C {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x334 - 0x1C];
    Vec f334;
    Vec f340;
    Vec f34C;
    f32 f358;
    f32 f35C;
    u8 pad360[4];
    saddr f364;
    u8 pad368[4];
    s32 f36C;
    s16 f370;
};

struct Laser_801AC17C {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x334 - 0x1C];
    Vec f334;
    Vec f340;
    Vec f34C;
    f32 f358;
    f32 f35C;
    u8 pad360[4];
    void *f364;
    f32 f368;
    u32 f36C;
    u16 f370;
};

extern "C" {
TParticleCtrl *create_particle_emitter(const void *pos, s32 id);
void *find_entity_by_id(u16);
void vec3_add_to(void *, void *);
void rotate_vector_by_matrix(int, void *, void *);
void rotate_matrix_y(int, int);
}
extern u8 identity_matrix[];
extern "C" {
void run_task__12TPhotonLaserFv(Laser_801AC17C *o);
s32 free_collision_body_parts(void *);

void TPhotonLaser::render() { TParticleCtrl::begin_effect_render(); TParticleCtrl::end_effect_render(); }

void run_task__12TPhotonLaserFv(Laser_801AC17C *o) {
    Vec in;
    Vec out;
    void *owner;
    o->f368 += 1.0f;
    in.y = in.x = 0.0f;
    in.z = 10.0f;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, (s32)(182.04445f * (f32)o->f36C));
    rotate_vector_by_matrix(0, &in, &out);
    pop_matrices(1);
    vec3_add_to(&o->f340, &out);
    o->f36C += 0x24;
    vec3_add_to(&o->f340, &o->f34C);
    if (o->f364 != 0) {
        ((TParticleCtrl *)o->f364)->set_position(&o->f340);
    }
    owner = find_entity_by_id(o->f370);
    if (owner == 0) {
        if (o->f364 != 0) {
            ((TObject *)o->f364)->queue_destruction();
            o->f364 = 0;
        }
        o->f34C.x = 0.0f;
        o->f34C.y = 0.0f;
        o->f34C.z = 0.0f;
    } else if (o->f340.y < *(f32 *)((u8 *)owner + 0x3C)) {
        if (o->f364 != 0) {
            ((TObject *)o->f364)->queue_destruction();
            o->f364 = 0;
        }
        o->f34C.x = 0.0f;
        o->f34C.y = 0.0f;
        o->f34C.z = 0.0f;
        spawn_particle_effect(&o->f340, 0x13D);
        ((TObject *)o)->queue_destruction();
    }
}
}
TPhotonLaser::~TPhotonLaser() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
    if ((u32) this->m_364 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x364)))->queue_destruction();
        this->m_364 = 0U;
    }
}


TPhotonLaser::TPhotonLaser(PhotonLaserParams *p, TObject *parent, u16 arg3) : TObjChara(parent) {
    Laser_801AC36C *self = (Laser_801AC36C *)this;
    self->f0 = ((saddr)TPhotonLaser__name);
    VecCopy((Vec *)&self->f334, (const Vec *)(VecCopy((Vec *)((Vec *)&self->f340), (const Vec *)((const Vec *)&p->pos))));
    self->f370 = arg3;
    VecCopy((Vec *)&self->f34C, (const Vec *)&p->dir);
    self->f34C.x *= p->scale;
    self->f34C.y *= p->scale;
    self->f34C.z *= p->scale;
    self->f358 = p->unk_24;
    self->f35C = p->unk_2C;
    self->f364 = (saddr)create_particle_emitter(&self->f340, 0x134);
    self->f36C = 0;
}


