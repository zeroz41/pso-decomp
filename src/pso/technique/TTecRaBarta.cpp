#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecRaBarta.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/unk/TLobby_8001EF5C.h"

#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"

#include "pso/unk/TLobby_80226070.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/unk/TUnk_804CCB28.h"
#include "pso/technique/TTecCircle.h"
#pragma readonly_strings on

#include <stddef.h>

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecPlayerInfluence.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

struct HitInfo_80237900 { s32 type; f32 power; };

struct VBase_80237900 { char pad[0x18]; };

struct VObj_80237900 : VBase_80237900 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(void *, HitInfo_80237900 *, void *, s32, s32);
};

struct Obj_80237900 {
    u8 pad0[0x1C];
    void *source;
    u8 pad20[0x88 - 0x20];
    f32 power;
    u8 padP[0xB8 - 0x88 - 4];
    void *contact;
    u8 padC[0xF8 - 0xB8 - 4];
    u16 ids[32];
    s32 cursor;
};

struct Owner_80237310
{
  u8 pad[0x30];
  u32 flags;
};

struct Obj_80237310
{
  s32 f0;
  u8 pad4[0x14];
  void *vt;
  Owner_80237310 *owner;
  f32 pos[3];
  f32 f2c;
  f32 f30;
  f32 f34;
  f32 f38;
  f32 f3c;
  f32 f40;
  f32 f44;
  u8 pad48[0x64 - 0x48];
  f32 f64;
  u8 pad68[0x70 - 0x68];
  f32 f70;
  u8 pad74[0xA0 - 0x74];
  s32 fa0;
  s16 level;
  s16 tier;
  u16 fa8;
  u8 padaa[2];
  s32 fac;
  f32 fb0[3];
  f32 fbc;
  f32 fc0;
  s32 fc4;
  s32 fc8;
  u8 padcc[0xDC - 0xCC];
  void *fdc;
};

typedef struct Emitter_80237494
{
  u32 entry;
  u32 flags;
  f32 scale;
} Emitter_80237494;

typedef struct Profile_80237494
{
  Emitter_80237494 *emitters;
  u32 count;
} Profile_80237494;

typedef struct Rabarta_80237494
{
  u8 pad0[0x1C];
  u8 *source;
  u8 pad20[0x7A - 0x20];
  s16 band;
  u8 pad7c[0xF4 - 0x7C];
  void **emitters;
} Rabarta_80237494;

struct RaBarta_802377FC {
    u8 pad[0x78];
    s16 level;
    u8 pad7a[0x88 - 0x7a];
    f32 amount;
    u8 pad8c[0xac - 0x8c];
    s16 per_level;
};

extern "C" {



typedef struct Obj_80237310 Obj_80237310;
typedef struct Owner_80237310 Owner_80237310;

extern "C" {
extern const Emitter_80237494 lbl_8044D920[3] = {{473, 0, 0.0f}, {475, 0, 0.0f}, {479, 0x20060, 1.0f}};
extern const Emitter_80237494 lbl_8044D944[3] = {{473, 0, 0.0f}, {475, 0x40, 1.2f}, {404, 0x20060, 1.2f}};
extern const Emitter_80237494 lbl_8044D968[3] = {{473, 0, 0.0f}, {475, 0x40, 1.2f}, {405, 0x20060, 1.4f}};
extern const Emitter_80237494 lbl_8044D98C[3] = {{473, 0, 0.0f}, {406, 0, 0.0f}, {409, 0x30060, 1.6f}};
extern const Emitter_80237494 lbl_8044D9B0[3] = {{473, 0, 0.0f}, {406, 0x40, 1.2f}, {410, 0x30060, 1.8f}};
extern const Emitter_80237494 lbl_8044D9D4[3] = {{473, 0, 0.0f}, {407, 0, 0.0f}, {411, 0x40060, 1.0f}};
extern const Profile_80237494 rabarta_band_emitter_table[6] = {
    {(Emitter_80237494 *)lbl_8044D920, 3}, {(Emitter_80237494 *)lbl_8044D944, 3}, {(Emitter_80237494 *)lbl_8044D968, 3},
    {(Emitter_80237494 *)lbl_8044D98C, 3}, {(Emitter_80237494 *)lbl_8044D9B0, 3}, {(Emitter_80237494 *)lbl_8044D9D4, 3},
};
extern const Emitter_80237494 lbl_8044DA28 = {470, 0x10828, 0.0f};
const char *TTecRaBarta_class_name = "TTecRaBarta";
__declspec(section ".sdata2") extern const f32 lbl_805DC8C4;
}
typedef struct Emitter_80237494 Emitter_80237494;
typedef struct Profile_80237494 Profile_80237494;
typedef struct Rabarta_80237494 Rabarta_80237494;
void TTecRaBarta::vfunc_8(void *pos) {
    Rabarta_80237494 *self = (Rabarta_80237494 *)this;
  u32 i;
  Vec point;
  Emitter_80237494 *binding;
  self->emitters = (void **)mem_alloc(rabarta_band_emitter_table[self->band].count * 4);
  for (i = 0; i < rabarta_band_emitter_table[self->band].count; i++)
  {
    VecCopy((Vec *)&point, (const Vec *)(self->source + 0x38));
    if (pos != 0)
    {
      VecCopy((Vec *)&point, (const Vec *)pos);
    }
    self->emitters[i] = create_particle_emitter(&point, rabarta_band_emitter_table[self->band].emitters[i].entry);
    binding = &rabarta_band_emitter_table[self->band].emitters[i];
    if ((binding->flags & 0x40) && (self->emitters[i] != 0))
    {
      ((TParticleCtrl *)(self->emitters[i]))->set_scale(binding->scale, binding->scale);
    }
    if (rabarta_band_emitter_table[self->band].emitters[i].flags & 0x20)
    {
      u32 mid = rabarta_band_emitter_table[self->band].emitters[i].flags >> 16;
      if (self && self)
      {
      }
      attach_particle_model(static_cast<TParticleCtrl *>(self->emitters[i]), get_bml_model(technique_effect_bml, mid), technique_texture_list, 0, 0, (f32)(1.0f));
    }
  }
  if (self->band == 5)
  {
    Vec point2;
    Emitter_80237494 *b2 = (Emitter_80237494 *)&lbl_8044DA28;
    f32 dy = lbl_805DC8C4;
    u32 id;
    void *emitter;
    if (pos != 0)
    {
      VecCopy((Vec *)&point2, (const Vec *)pos);
    }
    else
    {
      VecCopy((Vec *)&point2, (const Vec *)(self->source + 0x38));
    }
    point2.y += dy;
    emitter = spawn_particle_effect(&point2, b2->entry);
    id = b2->flags >> 16;
    if (emitter != 0)
    {
      attach_particle_model(static_cast<TParticleCtrl *>(emitter), get_bml_model(technique_effect_bml, id), technique_texture_list, get_bml_motion(technique_effect_bml, 1), 0, (f32)(1.0f));
    }
  }
}

extern const f32 lbl_805DC8C4 = 5.0f;

void TTecRaBarta::vfunc_9() {
    s32 handle;

    switch (this->band) {
    case 0:
        this->m_ec = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        handle = this->m_ec;
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        this->m_ec = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        return;
    case 2:
    case 3:
        this->m_ec = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        handle = this->m_ec;
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        this->m_ec = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        handle = this->m_ec;
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        this->m_ec = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        handle = this->m_ec;
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}

void TTecRaBarta::calc_parameters() {
    RaBarta_802377FC *self = (RaBarta_802377FC *)this;
    TechniqueParams *res = calc_technique_parameters(5, self->level, 0xFFFF);
    ((TechniqueParams *)(&self->amount))->copy((TechniqueParams *)res);
    if (self->level >= 0xF && TTecCtrl::is_technique_ready() == 0) {
        self->amount = tech_high_level_linear_power_table[5].base + tech_high_level_linear_power_table[5].per_level * self->level;
        return;
    }
    self->amount = self->amount + (f32)(self->per_level * self->level);
    if (TTecCtrl::is_technique_ready() != 0) {
        self->amount = self->amount * technique_scale_table[5].power;
    }
}

void TTecRaBarta::vfunc_6(void *target) {
    Obj_80237900 *self = (Obj_80237900 *)this;
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (self->ids[i] == ((TObjBase *)target)->get_entity_id()) {
            found = 1;
        }
    }
    if (found == 0) {
        self->ids[*(s32 *)&this->m_138] = ((TObjBase *)target)->get_entity_id();
        *(s32 *)&this->m_138 += 1;
        if (*(s32 *)&this->m_138 >= 32) {
            *(s32 *)&this->m_138 = 31;
        }
        HitInfo_80237900 tmp;
        tmp.type = 2;
        tmp.power = this->power;
        HitInfo_80237900 info = tmp;
        ((VObj_80237900 *)target)->m21(self->source, &info, self->contact, 5, -1);
    }
}

}

struct Self_80237A94 {
    u8 pad0[0x18];
    void *vtable;
    u8 pad1[0x7A - 0x1C];
    s16 band;
    u8 pad2[0xEC - 0x7C];
    void *emitters;
    u8 pad3[0xF4 - 0xF0];
    void **objs;
};

void TTecRaBarta::create(void *source, void *origin, void *pos, s32 level) {
    new TTecRaBarta((saddr)source, (Vec *)origin, (Vec *)pos, level);
}

void TTecRaBarta::create(void *source, void *origin, s32 level) {
    new TTecRaBarta((saddr)source, (Vec *)origin, level);
}

TTecRaBarta::~TTecRaBarta() {
    u32 i;
    void *obj;
    for (i = 0; i < rabarta_band_emitter_table[((struct Self_80237A94 *)this)->band].count; i++) {
        obj = ((struct Self_80237A94 *)this)->objs[i];
        if (obj != NULL) {
            ((TObject *)obj)->queue_destruction();
        }
    }
    stop_sound_request((saddr)((struct Self_80237A94 *)this)->emitters);
    mem_free(((struct Self_80237A94 *)this)->objs);
}


void TTecRaBarta::render() {  }

void TTecRaBarta::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((uaddr) this->collidable == 0U) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    this->source = (uaddr)find_entity_by_id((this->sourceId));
    if ((u32) this->source == 0U) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    this->age = this->age + 1;
    apply_technique_to_area_targets();
    if ((s32) this->age > (s16) this->m_a8) {
        ((TObject *)arg0)->queue_destruction();
    }
}

#pragma push
#pragma opt_common_subs off

TTecRaBarta::TTecRaBarta(saddr source, Vec *origin, Vec *pos, s32 level) : TTecCircle(source, origin, pos, level) {
    s32 i;
    m_name = TTecRaBarta_class_name;
    calc_parameters();
    m_f0 = 1;
    VecCopy(&position, VecCopy(&target, pos));
    if (collidable != NULL) {
        collidable->bodies->radius = scope;
    }
    for (i = 0; i < 32; i++) {
        hit_ids[i] = 0xFFFF;
    }
    m_138 = 0;
    vfunc_8(&position);
    vfunc_9();
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}
#pragma pop

TTecRaBarta::TTecRaBarta(saddr source, Vec *origin, s32 level) : TTecCircle(source, origin, origin, level) {
    s32 i;
    m_name = TTecRaBarta_class_name;
    m_f0 = 0;
    calc_parameters();
    if (collidable != NULL) {
        collidable->bodies->radius = scope;
    }
    for (i = 0; i < 32; i++) {
        hit_ids[i] = 0xFFFF;
    }
    m_138 = 0;
    vfunc_8(0);
    vfunc_9();
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}
