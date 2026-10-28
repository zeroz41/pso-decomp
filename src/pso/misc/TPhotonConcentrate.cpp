#include "types.h"
#include "pso/misc/TPhotonConcentrate.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TPhotonConcentrate.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/object/TObjMotion.h"

extern "C" {

void *create_particle_emitter(void *pos, s32 id);
s32 __ct__14TObjCollidableFP7TObject(s32, s32);
s32 find_entity_by_id(s32, f32);
void __dl__7TObjectFPv(void *);
extern s32 __vt__18TPhotonConcentrate[];
extern s32 lbl_805D34D0;

void render__18TPhotonConcentrateFv(void) { TParticleCtrl::begin_effect_render(); TParticleCtrl::end_effect_render(); }

#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"

extern "C" {

typedef struct Owner_801A7E7C Owner_801A7E7C;
typedef struct PC_801A7E7C PC_801A7E7C;
typedef struct Vec_801A7E7C Vec_801A7E7C;
typedef struct Vec_801A7E7C
{
  f32 x;
  f32 y;
  f32 z;
} Vec_801A7E7C;
typedef struct Owner_801A7E7C
{
  u8 pad[0x60];
  u32 angle;
} Owner_801A7E7C;
typedef struct PC_801A7E7C
{
  u8 pad0[0xAC];
  Vec_801A7E7C origin;
  Vec_801A7E7C pos;
  Vec_801A7E7C vel;
  Vec_801A7E7C target;
  f32 dist;
  f32 total;
  f32 range;
  u8 padE8[4];
  u32 angle;
  u8 padF0[8];
  void *emitter;
  Owner_801A7E7C *owner;
} PC_801A7E7C;
f32 sin_table_lookup(s32);
void vec3_add_to(void *, void *);
f32 vector_length(void *);
void rotate_vector_by_matrix(void *, void *, void *);
void rotate_matrix_y(void *, s32);
void rotate_matrix_z(void *, s32);
void subtract_vector(void *, void *);
f32 xyz_distance(void *, void *);
extern u8 identity_matrix[];
extern const f32 lbl_805DC0F8;
extern const f32 lbl_805DC0FC;
extern const f32 lbl_805DC100;
extern const f32 lbl_805DC104;
extern const f32 lbl_805DC108;
extern const f32 lbl_805DC10C;
void run_task__18TPhotonConcentrateFv(PC_801A7E7C *self) {
  f32 sn;
  Vec_801A7E7C delta;
  float new_var;
  Owner_801A7E7C *owner;
  u32 a;
  VecCopy((Vec *)&delta, (const Vec *)&self->pos);
  subtract_vector(&delta, &self->target);
  self->dist = vector_length(&delta);
  if (self->dist < lbl_805DC0F8)
  {
    queue_destruction__7TObjectFv(self->emitter);
    self->emitter = 0;
    spawn_particle_effect(&self->pos, 0xC6);
    queue_destruction__7TObjectFv(self);
    return;
  }
  if (xyz_distance(&self->origin, &self->pos) > self->range)
  {
    queue_destruction__7TObjectFv(self);
    return;
  }
  vec3_add_to(&self->pos, &self->vel);
  {
    Vec_801A7E7C d2 = self->target;
    subtract_vector(&d2, &self->origin);
    self->total = vector_length(&d2);
    if (lbl_805DC0FC == self->total)
    {
      self->total = lbl_805DC100;
    }
    a = lbl_805DC10C * (self->dist / self->total);
    sn = sin_table_lookup(lbl_805DC108 * ((f32) a));
    {
      f32 scale = self->total / lbl_805DC0F8;
      Vec_801A7E7C off;
      Vec_801A7E7C xf;
      new_var = lbl_805DC104 * scale;
      off.y = (off.z = lbl_805DC0FC);
      off.x = new_var * sn;
      push_matrix_from(identity_matrix);
      rotate_matrix_z(0, lbl_805DC108 * ((f32) self->angle));
      rotate_vector_by_matrix(0, &off, &xf);
      pop_matrices(1);
      VecCopy((Vec *)&off, (const Vec *)&xf);
      push_matrix_from(identity_matrix);
      owner = self->owner;
      if (owner != 0)
      {
        rotate_matrix_y(0, lbl_805DC108 * ((f32) ((s32)(owner->angle - 0x5A))));
        rotate_vector_by_matrix(0, &off, &xf);
      }
      pop_matrices(1);
      {
        Vec_801A7E7C posn = self->pos;
        vec3_add_to(&posn, &xf);
        if (self->emitter != 0)
        {
          ((TNowLoading *)(self->emitter))->copy_pos(&posn);
        }
      }
    }
  }
}

}

}
TPhotonConcentrate::~TPhotonConcentrate() {
    if (*(void **)((s8 *)this + 0xF8) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0xF8)); this->m_f8 = 0; }
}
extern "C" {

}
TPhotonConcentrate::TPhotonConcentrate(u8 *arg1, s32 arg2, s32 arg3) : TObjCollidable((TObject *)arg2) {
    f32 temp_f1;
    *(s32 *)((s8 *)this + 0) = (s32) lbl_805D34D0;
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
    this->m_f8 = (s32)create_particle_emitter(((u8 *)this) + 0xB8, 0x135);
}
extern "C" {

}
