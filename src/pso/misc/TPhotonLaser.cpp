#include "types.h"
#include "pso/misc/TPhotonLaser.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/TPhotonLeilla.h"
#include "pso/misc/TPhotonLaser.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/misc/TNowLoading.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D34F0 = "TPhotonLaser";
}


typedef struct Vec_801AC36C { f32 x, y, z; } Vec_801AC36C;

struct Params_801AC36C {
    Vec_801AC36C pos;
    u8 padC[0x18 - 0xC];
    Vec_801AC36C dir;
    f32 f24;
    f32 scale;
    f32 f2C;
};

struct Laser_801AC36C {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x334 - 0x1C];
    Vec_801AC36C f334;
    Vec_801AC36C f340;
    Vec_801AC36C f34C;
    f32 f358;
    f32 f35C;
    u8 pad360[4];
    s32 f364;
    u8 pad368[4];
    s32 f36C;
    s16 f370;
};

struct Laser_801AC17C {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x334 - 0x1C];
    Vec_801AC36C f334;
    Vec_801AC36C f340;
    Vec_801AC36C f34C;
    f32 f358;
    f32 f35C;
    u8 pad360[4];
    void *f364;
    f32 f368;
    u32 f36C;
    u16 f370;
};

extern "C" {
void __ct__9TObjCharaFP7TObject(void *, void *);
void *create_particle_emitter(void *pos, s32 id);
extern s32 __vt__12TPhotonLaser[];
extern const char *lbl_805D34F0;
Laser_801AC36C *TPhotonLaser__ct(Laser_801AC36C *self, Params_801AC36C *p, void *parent, s16 arg3);
void queue_destruction__7TObjectFv(void *arg0);
void *spawn_particle_effect(void *pos, s32 id);
void *find_entity_by_id(u16);
void vec3_add_to(void *, void *);
void rotate_vector_by_matrix(int, void *, void *);
void rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrices(s32 arg0);
extern u8 identity_matrix[];
void run_task__12TPhotonLaserFv(Laser_801AC17C *o);
void *__dt__12TPhotonLaserFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

void TPhotonLaser::render() { TParticleCtrl::begin_effect_render(); TParticleCtrl::end_effect_render(); }

void run_task__12TPhotonLaserFv(Laser_801AC17C *o) {
    Vec_801AC36C in;
    Vec_801AC36C out;
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
            queue_destruction__7TObjectFv(o->f364);
            o->f364 = 0;
        }
        o->f34C.x = 0.0f;
        o->f34C.y = 0.0f;
        o->f34C.z = 0.0f;
    } else if (o->f340.y < *(f32 *)((u8 *)owner + 0x3C)) {
        if (o->f364 != 0) {
            queue_destruction__7TObjectFv(o->f364);
            o->f364 = 0;
        }
        o->f34C.x = 0.0f;
        o->f34C.y = 0.0f;
        o->f34C.z = 0.0f;
        spawn_particle_effect(&o->f340, 0x13D);
        queue_destruction__7TObjectFv(o);
    }
}

}
TPhotonLaser::~TPhotonLaser() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
    if ((u32) this->m_364 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x364));
        this->m_364 = 0U;
    }
}
extern "C" {

Laser_801AC36C *TPhotonLaser__ct(Laser_801AC36C *self, Params_801AC36C *p, void *parent, s16 arg3) {
    __ct__9TObjCharaFP7TObject(self, parent);
    self->vt18 = ((s32 *)&__vt__12TPhotonLaser);
    self->f0 = ((s32)lbl_805D34F0);
    VecCopy((Vec *)&self->f334, (const Vec *)(VecCopy((Vec *)((Vec *)&self->f340), (const Vec *)((const Vec *)&p->pos))));
    self->f370 = arg3;
    VecCopy((Vec *)&self->f34C, (const Vec *)&p->dir);
    self->f34C.x *= p->scale;
    self->f34C.y *= p->scale;
    self->f34C.z *= p->scale;
    self->f358 = p->f24;
    self->f35C = p->f2C;
    self->f364 = (s32)create_particle_emitter(&self->f340, 0x134);
    self->f36C = 0;
    return self;
}



}
