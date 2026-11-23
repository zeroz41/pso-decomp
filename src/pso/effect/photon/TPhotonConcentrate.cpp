#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/effect/photon/TPhotonConcentrate.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"

const char *TPhotonConcentrate__class_name = "TPhotonConcentrate";

extern "C" {

s32 find_entity_by_id(s32, f32);

void render__18TPhotonConcentrateFv(void) { TParticleCtrl::begin_effect_render(); TParticleCtrl::end_effect_render(); }

#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"

extern "C" {

typedef struct Owner_801A7E7C Owner_801A7E7C;
typedef struct PC_801A7E7C PC_801A7E7C;
typedef struct Owner_801A7E7C
{
  u8 pad[0x60];
  u32 angle;
} Owner_801A7E7C;
typedef struct PC_801A7E7C
{
  u8 pad0[0xAC];
  Vec origin;
  Vec pos;
  Vec vel;
  Vec target;
  f32 dist;
  f32 total;
  f32 range;
  u8 padE8[4];
  u32 angle;
  u8 padF0[8];
  void *emitter;
  Owner_801A7E7C *owner;
} PC_801A7E7C;
void vec3_add_to(void *, void *);
f32 vector_length(void *);
void rotate_vector_by_matrix(void *, void *, void *);
void rotate_matrix_y(void *, s32);
void rotate_matrix_z(void *, s32);
void subtract_vector(void *, void *);
f32 xyz_distance(void *, void *);
extern u8 identity_matrix[];
void run_task__18TPhotonConcentrateFv(PC_801A7E7C *self) {
  Vec delta;
  Owner_801A7E7C *owner;
  u32 a;
  VecCopy((Vec *)&delta, (const Vec *)&self->pos);
  subtract_vector(&delta, &self->target);
  self->dist = vector_length(&delta);
  if (self->dist < 10.0f)
  {
    ((TObject *)self->emitter)->queue_destruction();
    self->emitter = 0;
    spawn_particle_effect(&self->pos, 0xC6);
    ((TObject *)self)->queue_destruction();
    return;
  }
  if (xyz_distance(&self->origin, &self->pos) > self->range)
  {
    ((TObject *)self)->queue_destruction();
    return;
  }
  vec3_add_to(&self->pos, &self->vel);
  {
    Vec d2 = self->target;
    subtract_vector(&d2, &self->origin);
    self->total = vector_length(&d2);
    if (0.0f == self->total)
    {
      self->total = 0.00001f;
    }
    a = 180.0f * (self->dist / self->total);
    {
      Vec off;
      Vec xf;
      off.x = 4.0f * (self->total / 10.0f) * sin_table_lookup(182.04445f * ((f32) a));
      off.y = (off.z = 0.0f);
      push_matrix_from(identity_matrix);
      rotate_matrix_z(0, 182.04445f * ((f32) self->angle));
      rotate_vector_by_matrix(0, &off, &xf);
      pop_matrices(1);
      VecCopy((Vec *)&off, (const Vec *)&xf);
      push_matrix_from(identity_matrix);
      owner = self->owner;
      if (owner != 0)
      {
        rotate_matrix_y(0, 182.04445f * ((f32) ((s32)(owner->angle - 0x5A))));
        rotate_vector_by_matrix(0, &off, &xf);
      }
      pop_matrices(1);
      {
        Vec posn = self->pos;
        vec3_add_to(&posn, &xf);
        if (self->emitter != 0)
        {
          ((TParticleCtrl *)self->emitter)->set_position(&posn);
        }
      }
    }
  }
}

}

}
TPhotonConcentrate::~TPhotonConcentrate() {
    if (*(void **)((s8 *)this + 0xF8) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0xF8)))->queue_destruction(); this->m_f8 = 0; }
}
TPhotonConcentrate::TPhotonConcentrate(u8 *arg1, saddr parent, s32 arg3) : TObjCollidable((TObject *)parent) {
    f32 temp_f1;
    *(saddr *)((s8 *)this + 0) = (saddr) TPhotonConcentrate__class_name;
    VecCopy((Vec *)(((u8 *)this) + 0xAC), (const Vec *)(VecCopy((Vec *)(((u8 *)this) + 0xB8), (const Vec *)((const Vec *)arg1))));
    VecCopy((Vec *)(((u8 *)this) + 0xD0), (const Vec *)(arg1 + 0xC));
    VecCopy((Vec *)(((u8 *)this) + 0xC4), (const Vec *)(arg1 + 0x18));
    *(f32 *)((s8 *)this + 0xC4) = (f32) (*(f32 *)((s8 *)this + 0xC4) * *(f32 *)((s8 *)arg1 + 0x28));
    *(f32 *)((s8 *)this + 0xC8) = (f32) (*(f32 *)((s8 *)this + 0xC8) * *(f32 *)((s8 *)arg1 + 0x28));
    temp_f1 = this->m_cc;
    this->m_cc = (f32) (temp_f1 * *(f32 *)((s8 *)arg1 + 0x28));
    this->m_e4 = (f32) *(f32 *)((s8 *)arg1 + 0x24);
    *(f32 *)((s8 *)this + 0xE8) = (f32) *(f32 *)((s8 *)arg1 + 0x2C);
    this->m_f0 = (s32) *(s32 *)((s8 *)arg1 + 0x30);
    this->m_ec = (s32) *(s32 *)((s8 *)arg1 + 0x34);
    this->m_fc = find_entity_by_id(arg3, temp_f1);
    this->m_f8 = (uaddr)create_particle_emitter(((u8 *)this) + 0xB8, 0x135);
}
