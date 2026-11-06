#include "pso/effect/TParticleCtrl.h"
#include "types.h"
#include "pso/unk/text_80086D50.h"
#include "pso/misc/TTecFoie.h"
#include "pso/misc/TTecAnti.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8022FE84_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_8022FE84_lbl_804CC55C
{
  const f32 value;
  u8 remaining[0x94];
};

struct RecoveredFields_8022FE84_arg0
{
  u8 unknown_0[0x64];
  f32 field_64;
  u8 unknown_68[0x8];
  f32 field_70;
  u8 unknown_74[0x50];
  s16 field_C4;
  u8 unknown_C6[0x6];
  f32 field_CC;
  f32 field_D0;
  f32 field_D4;
  u8 unknown_D8[0x18];
  s16 field_F0;
};

struct Dmg_80230004 { s32 kind; f32 amount; };

struct Base_80230004 { u8 pad[0x18]; };

struct Target_80230004 : Base_80230004 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void receive(s32 owner, Dmg_80230004 d, s32 x, s32 y, s32 z);
    u8 pad1c[0x38 - 0x1C];
    f32 pos[3];
};

struct Tec_80230004 { u8 pad[0x1C]; s32 owner; u8 pad20[0xCC - 0x20]; f32 power; u8 padd0[0xF8 - 0xD0]; s32 f8; };

struct TTecFoieData_80230144 { u8 pad[4]; u32 count; };

struct TTecFoie_80230144 {
    u8 pad0[0x18];
    void *vtable;
    u8 pad1c[0xC6 - 0x1C];
    s16 band;
    u8 padc8[0x130 - 0xC8];
    void **emitters;
};

struct Angles_8022FC94
{
  s32 x;
  s32 y;
  s32 z;
};

struct Binding_8022FC94
{
  u32 entry;
  u32 flags;
  f32 scale;
};

struct Foie_8022FC94
{
  u8 pad0[0x20];
  u8 pos[0x54 - 0x20];
  s32 ax;
  s32 ay;
  s32 az;
  u8 pad60[0xC6 - 0x60];
  s16 band;
  u8 padc8[0x130 - 0xC8];
  void **emitters;
};

extern "C" {
s32 calc_technique_parameters(int, int, int);
s32 is_technique_ready__8TTecCtrlFv();
}
s32 clamp_nonnegative_int(s32 x);
extern RecoveredGlobal_8022FE84_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_8022FE84_lbl_804CC55C lbl_804CC55C;
extern "C" {
s32 play_sound_effect(s32 id, void *pos, s32 a, s32 b);
void queue_destruction__7TObjectFv(void *self);
void mem_free(void *p);
void __dl__7TObjectFPv(void *);
extern TTecFoieData_80230144 TTecFoie__emitter_profile_table[];
extern void *__vt__8TTecFoie[];
TTecFoie_80230144 *__dt__8TTecFoieFv(TTecFoie_80230144 *self, s16 deleting);
s32 attach_particle_model(int, int, int, int, int, f32);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, u16 e);
void *spawn_continuous_particle_effect_with_flags(void *, s32, u16);
s32 mem_alloc(s32);
extern s32 lbl_805D63B0;
void *spawn_particle_effect(void *pos, s32 id);
void *TTecFoie__ct(void *, void *, void *, void *, void *);
void *construct_aimed__8TTecFoieFlPUcPUcs(void *, void *, void *, void *, void *);
void *__nw__7TObjectFUl(int);

typedef struct RecoveredFields_8022FE84_arg0 RecoveredFields_8022FE84_arg0;
typedef struct RecoveredGlobal_8022FE84_lbl_804CC510 RecoveredGlobal_8022FE84_lbl_804CC510;
typedef struct RecoveredGlobal_8022FE84_lbl_804CC55C RecoveredGlobal_8022FE84_lbl_804CC55C;
typedef char RecoveredGlobal_8022FE84_lbl_804CC510_size[((sizeof(RecoveredGlobal_8022FE84_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_8022FE84_lbl_804CC55C_size[((sizeof(RecoveredGlobal_8022FE84_lbl_804CC55C)) == 0x98) ? (1) : (-1)];

typedef struct Angles_8022FC94 Angles_8022FC94;
typedef struct Binding_8022FC94 Binding_8022FC94;
typedef struct Foie_8022FC94 Foie_8022FC94;
typedef struct TTecFoieData_80230144 TTecFoieData_80230144;
void TTecFoie::create_particle_emitters() {
    Foie_8022FC94 *self = (Foie_8022FC94 *)this;
  Angles_8022FC94 fwd;
  Angles_8022FC94 rev;
  u32 i;
  s32 f;
  fwd.x = self->ax;
  fwd.y = 0;
  fwd.z = self->az;
  spawn_directional_particle(self->pos, &fwd, 0x18);
  self->emitters = (void **) mem_alloc(TTecFoie__emitter_profile_table[self->band].count * 4);
  for (i = 0; i < TTecFoie__emitter_profile_table[self->band].count; i++)
  {
    Binding_8022FC94 *b = &(*((Binding_8022FC94 **) (&TTecFoie__emitter_profile_table[self->band])))[i];
    f = (b->flags & 0x1000) ? (0x2000) : (0);
    if ((&(*((Binding_8022FC94 **) (&TTecFoie__emitter_profile_table[self->band])))[i])->flags & 1)
    {
      rev.x = self->ax + 0x8000;
      rev.y = 0;
      rev.z = self->az;
      self->emitters[i] = spawn_particle_effect_with_rotation(self->pos, &rev, (*((Binding_8022FC94 **) (&TTecFoie__emitter_profile_table[self->band])))[i].entry, f);
    }
    else
      if ((&(*((Binding_8022FC94 **) (&TTecFoie__emitter_profile_table[self->band])))[i])->flags & 2)
    {
      self->emitters[i] = spawn_particle_effect_with_rotation(self->pos, &fwd, (&(*((Binding_8022FC94 **) (&TTecFoie__emitter_profile_table[self->band])))[i])->entry, f);
    }
    else
    {
      self->emitters[i] = spawn_continuous_particle_effect_with_flags(self->pos, b->entry, f);
    }
    if (self->emitters[i] != 0)
    {
      if ((*((Binding_8022FC94 **) (&TTecFoie__emitter_profile_table[self->band])))[i].flags & 0x20)
      {
        attach_particle_model((int) self->emitters[i], TParticleCtrl::get_particle_model(0), lbl_805D63B0, 0, 1, 1.0f);
      }
      ((TParticleCtrl *)(self->emitters[i]))->set_scale((*((Binding_8022FC94 **) (&TTecFoie__emitter_profile_table[self->band])))[i].scale, (*((Binding_8022FC94 **) (&TTecFoie__emitter_profile_table[self->band])))[i].scale);
    }
  }
}

void TTecFoie::init_projectile_params() {
    u8 *arg0 = (u8 *)this;
  s32 new_var;
  new_var = calc_technique_parameters(0, (int) ((RecoveredFields_8022FE84_arg0 *) arg0)->field_C4, 0xFFFF);
  ((TTecAnti *)(arg0 + 0xCC))->copy_params((u8 *)new_var);
  if ((((s16) ((RecoveredFields_8022FE84_arg0 *) arg0)->field_C4) >= 0xF) && (is_technique_ready__8TTecCtrlFv() == 0))
  {
    ((RecoveredFields_8022FE84_arg0 *) arg0)->field_CC = (f32) ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0))) + ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 2))) * ((RecoveredFields_8022FE84_arg0 *) arg0)->field_C4));
  }
  else
  {
    ((RecoveredFields_8022FE84_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_8022FE84_arg0 *) arg0)->field_CC + ((f32) (((RecoveredFields_8022FE84_arg0 *) arg0)->field_F0 * ((RecoveredFields_8022FE84_arg0 *) arg0)->field_C4)));
    if (is_technique_ready__8TTecCtrlFv() != 0)
    {
      ((RecoveredFields_8022FE84_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_8022FE84_arg0 *) arg0)->field_CC * lbl_804CC55C.value);
    }
  }
  ((RecoveredFields_8022FE84_arg0 *) arg0)->field_64 = (f32) (((RecoveredFields_8022FE84_arg0 *) arg0)->field_D0 + ((f32) clamp_nonnegative_int((((RecoveredFields_8022FE84_arg0 *) arg0)->field_C4 - 4))));
  ((RecoveredFields_8022FE84_arg0 *) arg0)->field_70 = (f32) ((RecoveredFields_8022FE84_arg0 *) arg0)->field_D4;
}

void TTecFoie::vfunc_6() {
    s32 arg0 = (s32)this;
    spawn_particle_effect((void *)(arg0 + 0x20), 0x1DC);
    spawn_particle_effect((void *)(arg0 + 0x20), 0x1DD);
}

void TTecFoie::vfunc_8(void *target_arg) {
    Target_80230004 *target = (Target_80230004 *)target_arg;
    Dmg_80230004 d;
    d.kind = 1;
    d.amount = this->power;
    target->receive(((Tec_80230004 *)this)->owner, d, ((Tec_80230004 *)this)->f8, 0, -1);
    play_sound_effect(0x4002A828, target->pos, 0, 0);
    queue_destruction__7TObjectFv(this);
}

void TTecFoie::create_ex(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x134);
    if (o != NULL) {
        construct_aimed__8TTecFoieFlPUcPUcs(o, arg0, arg1, arg2, arg3);
    }
}

void TTecFoie::create(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x134);
    if (o != NULL) {
        TTecFoie__ct(o, arg0, arg1, arg2, arg3);
    }
}
TTecFoie_80230144 *__dt__8TTecFoieFv(TTecFoie_80230144 *self, s16 deleting) {
    if (self) {
        self->vtable = __vt__8TTecFoie;
        for (u32 i = 0; i < TTecFoie__emitter_profile_table[self->band].count; ++i) {
            queue_destruction__7TObjectFv(self->emitters[i]);
        }
        mem_free(self->emitters);
        ((TObjPlayer *)self)->destroy_technique_effect_resources(0);
        if (deleting > 0) __dl__7TObjectFPv(self);
    }
    return self;
}
}
