#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjDFDemo4.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"

typedef struct Rec_8004F2A8 {
    s32 a;
    s32 b;
    s32 c;
} Rec_8004F2A8;

typedef struct Obj_8004F2A8 {
    u8 pad0[0xAC];
    Rec_8004F2A8 recs[2];
    u8 padc4[0xE8 - 0xC4];
    f32 fe8[3];
    s32 ff4;
    s32 ff8;
} Obj_8004F2A8;

struct Vec_8004F3D4
{
  f32 x;
  f32 y;
  f32 z;
};

struct Self_8004F3D4
{
  u8 pad0[0xA4];
  u32 hA4;
  u32 hA8;
  u8 padac[0xE8 - 0xAC];
  Vec_8004F3D4 pos;
  s32 fF4;
  s32 fF8;
  f32 fFC;
  u8 pad100[4];
  Vec_8004F3D4 vecs[2];
};

extern "C" {
void rotate_matrix_y(s32, s32);
void push_matrix();
void post_translate_matrix(void *);
extern const f32 lbl_805D89F4;
extern const f32 lbl_805D89F8;
void set_scripted_camera_pose(void *, void *, void *);
void *spawn_particle_effect(void *pos, s32 id);
void *create_particle_emitter(void *pos, s32 id);
void play_sound_effect(s32, void *, s32, s32);
extern Vec_8004F3D4 lbl_804373F4[];
extern Vec_8004F3D4 boss4_type2_effect_offset_vec[];
extern const f32 lbl_805D89FC;
extern const f32 lbl_805D8A00;
void TObjDFDemo4::sub_8004F2A8() {
    Obj_8004F2A8 *arg0 = (Obj_8004F2A8 *)this;
    f32 alpha;
    s32 i;
    alpha = 1.0f;
    if (*(s32 *)&this->m_f8 > 0x4C) {
        return;
    }
    if (*(s32 *)&this->m_f8 > 0x44) {
        alpha = (f32)(0x4C - *(s32 *)&this->m_f8) * lbl_805D89F4;
    }
    if (alpha < 1.0f) {
        TObjPlayer__sub_80052390(alpha);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(arg0->fe8);
    rotate_matrix_y(0, *(s32 *)&this->m_f4);
    for (i = 0; i < 2; i++) {
        TObjFish::set_global_param(arg0->recs[i].b);
        draw_model_motion((void *)arg0->recs[i].a, (void *)arg0->recs[i].c, lbl_805D89F8);
    }
    clear_motion_packed_rotation();
    pop_matrix();
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}

void TObjDFDemo4::render() { sub_8004F2A8(); sub_8004F1FC(); }
typedef struct Self_8004F3D4 Self_8004F3D4;
typedef struct Vec_8004F3D4 Vec_8004F3D4;
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjDFDemo4::run_task() {
    Self_8004F3D4 *self = (Self_8004F3D4 *)this;
  f32 f;
  const f32 *new_var;
  u32 r;
  u32 *p;
  s32 i;
  if ((self->fF8 <= 0x3C) && ((r = (u32)spawn_particle_effect(&self->pos, 0x14E)) != 0))
  {
    ((TParticleCtrl *)r)->set_flags(0x40);
  }
  if (self->fF8 == 0x44)
  {
    if ((r = (u32)spawn_particle_effect(&self->pos, 0x17B)) != 0)
    {
      ((TParticleCtrl *)r)->set_flags(0x40);
    }
    if ((r = (u32)spawn_particle_effect(&self->pos, 0x17C)) != 0)
    {
      ((TParticleCtrl *)r)->set_flags(0x40);
    }
  }
  if (self->fF8 == 0x48)
  {
    if ((r = (u32)spawn_particle_effect(&self->pos, 0x17A)) != 0)
    {
      ((TParticleCtrl *)r)->set_flags(0x40);
    }
    play_sound_effect(0x40039E09, &self->pos, 0, 1);
    start_pad_rumble_all(0xC0, 0xF);
  }
  if (self->fF8 == 0x72)
  {
    play_sound_effect(0x4003B227, &self->pos, 0, 1);
  }
  if (self->fF8 >= 0xAA)
  {
    p = &self->hA4;
    for (i = 0; i < 2; i++)
    {
      Vec_8004F3D4 *v = &self->vecs[i];
      if ((*p) == 0)
      {
        *p = (u32)create_particle_emitter(v, 0x147);
        if ((*p) != 0)
        {
          ((TParticleCtrl *)(*p))->set_flags(0x40);
        }
      }
      else
      {
        ((TParticleCtrl *)*p)->set_position(v);
      }
      p = &self->hA8;
    }
  }
  if (self->fF8 == 0x72)
  {
    Vec_8004F3D4 a = lbl_804373F4[0];
    Vec_8004F3D4 b = boss4_type2_effect_offset_vec[0];
    VecCopy((Vec *)&self->pos, (const Vec *)&a);
    self->fF4 = 0;
    set_scripted_camera_pose(&self->pos, &self->pos, &b);
  }
  f = self->fFC + lbl_805D89FC;
  self->fFC = f;
  if (f > (*(new_var = &lbl_805D8A00)))
  {
    self->fFC = *new_var;
  }
  ((TBoss4Type2 *)(((u8 *) self) - -0x90))->scroll_strips();
  if ((++self->fF8) >= 0xF0)
  {
    queue_destruction__7TObjectFv(self);
  }
}

}
