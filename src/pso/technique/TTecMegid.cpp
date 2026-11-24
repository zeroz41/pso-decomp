#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "pso/system/memory.h"
#include "pso/technique/TechniqueBandSound.h"
#include "pso/system/BmlAccessors.h"
#include "pso/unk/text_803D96A8.h"
// ---- pso/technique/TTecMegid
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/technique/TTecShot.h"
#include "pso/technique/TTecMegid.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjChara.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/technique/TTecBarta.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjBase.h"

struct RecoveredFields_80235348_arg0
{
  u8 unknown_0[0x64];
  f32 field_64;
  u8 unknown_68[0x8];
  f32 field_70;
  u8 unknown_74[0x50];
  s16 level;
  u8 unknown_C6[0x6];
  f32 field_CC;
  f32 field_D0;
  f32 field_D4;
  u8 unknown_D8[0x18];
  s16 field_F0;
};

struct RecoveredFields_802308A0_arg0
{
  u8 unknown_0[0x70];
  f32 field_70;
  u8 unknown_74[0x50];
  s16 field_C4;
  u8 unknown_C6[0x6];
  f32 field_CC;
  u8 unknown_D0[0x4];
  f32 field_D4;
  u8 unknown_D8[0x18];
  s16 field_F0;
};


struct HitInfo_80235490 { s32 type; f32 power; };

struct VBase_80235490 { char pad[0x18]; };

struct VObj_80235490 : VBase_80235490 {
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
    virtual void m21(void *, HitInfo_80235490 *, void *, s32, s32);
};


struct Row_80235740 { u32 entry; u32 flags; f32 scale; };

struct Data_80235740 { Row_80235740 *rows; u32 count; };

struct Row_802351B4
{
  u32 entry;
  u32 flags;
  f32 scale;
};

struct Data_802351B4
{
  Row_802351B4 *rows;
  u32 count;
};

struct Arg_802351B4
{
  s32 a;
  s32 b;
  s32 c;
};

struct Obj_802351B4
{
  u8 pad0[0x20];
  Vec pos;
  u8 pad2c[0x54 - 0x2C];
  s32 f54;
  s32 f58;
  s32 f5c;
  u8 pad60[0xC6 - 0x60];
  s16 band;
  u8 padc8[0x130 - 0xC8];
  void **emitters;
};

// inferred: the per-band emitter lists of TTecMegid__emitter_bands, named after their band (technique level tier)
static const TechniqueEmitterSourceRow megid_band0_emitters[2] = {
    {0x1C5, 0, 0.0f}, {0x1C8, 0, 0.0f},
};
static const TechniqueEmitterSourceRow megid_band1_emitters[2] = {
    {0x1C5, 0x40, 1.4f}, {0x1C8, 0x40, 1.4f},
};
static const TechniqueEmitterSourceRow megid_band2_emitters[2] = {
    {0x1C5, 0x40, 1.8f}, {0x1C8, 0x40, 1.8f},
};
static const TechniqueEmitterSourceRow megid_band3_emitters[3] = {
    {0x1C4, 2, 1.0f}, {0x1C5, 0x40, 2.2f}, {0x1C8, 0x40, 2.2f},
};
static const TechniqueEmitterSourceRow megid_band4_emitters[3] = {
    {0x1C4, 2, 1.0f}, {0x1C5, 0x40, 2.6f}, {0x1C8, 0x40, 2.6f},
};
static const TechniqueEmitterSourceRow megid_band5_emitters[5] = {
    {0x1C4, 2, 1.0f}, {0x1C5, 0x40, 3.0f}, {0x1C8, 0x40, 3.0f}, {0x1C7, 0, 1.0f}, {0x1CF, 0x1002, 1.0f},
};
const TechniqueEmitterSourceTable TTecMegid__emitter_bands[6] = {
    {megid_band0_emitters, 2}, {megid_band1_emitters, 2}, {megid_band2_emitters, 2},
    {megid_band3_emitters, 3}, {megid_band4_emitters, 3}, {megid_band5_emitters, 5},
};
// inferred: same <Class>__class_name pattern as TTecBarta__class_name
const char *TTecMegid__class_name = "TTecMegid";
static const Vec tec_megid_offset_vec = {0.0f, 0.0f, -5.0f};

extern "C" {
void mem_free(void *p);
}
u32 get_technique_caster_flags(s32 technique, u16 actor);
extern "C" {


#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TTecMegid::update_by_state() {
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A60B, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A60B, &position, 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A60B, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A60B, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A60B, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}
#pragma pop

typedef struct RecoveredFields_80235348_arg0 RecoveredFields_80235348_arg0;

typedef struct Arg_802351B4 Arg_802351B4;
typedef struct Data_802351B4 Data_802351B4;
typedef struct Obj_802351B4 Obj_802351B4;
typedef struct Row_802351B4 Row_802351B4;
typedef struct TTecGiBartaData_80230B48 TTecGiBartaData_80230B48;
void TTecMegid::spawn_particle_emitters() {
  Obj_802351B4 *self = (Obj_802351B4 *) this;
  u32 fl;
  u32 flags;
  Row_802351B4 *row;
  u32 i;
  long long new_var;
  s32 mode;
  Arg_802351B4 dir;
  dir.a = self->f54;
  dir.b = 0;
  dir.c = self->f5c;
  self->emitters = static_cast<void **>(mem_alloc(TTecMegid__emitter_bands[band].count * sizeof(*self->emitters)));
  for (i = 0; i < ((Data_802351B4 *) TTecMegid__emitter_bands)[this->band].count; i++)
  {
    mode = 0;
    row = &((Data_802351B4 *) TTecMegid__emitter_bands)[this->band].rows[i];
    flags = row->flags;
    if (flags & 0x1000)
    {
      mode = 0x2000;
    }
    if (flags & 2)
    {
      self->emitters[i] = spawn_particle_effect_with_rotation(&self->pos, &dir, row->entry, mode | 0x1000);
    }
    else
    {
      self->emitters[i] = spawn_continuous_particle_effect_with_flags(&self->pos, row->entry, mode | 0x1000);
    }
    if (self->emitters[i] != 0)
    {
      row = &((Data_802351B4 *) TTecMegid__emitter_bands)[this->band].rows[i];
      if (row->flags & 0x40)
      {
        ((TParticleCtrl *)(self->emitters[i]))->set_scale(row->scale, row->scale);
      }
      if (((Data_802351B4 *) TTecMegid__emitter_bands)[this->band].rows[i].flags & 0x20)
      {
        new_var = ((Data_802351B4 *) TTecMegid__emitter_bands)[this->band].rows[i].flags >> 16;
        attach_particle_model(static_cast<TParticleCtrl *>(self->emitters[i]), get_bml_model(technique_effect_bml, new_var), technique_texture_list, 0, 1, 1.0f);
      }
    }
  }
}

void TTecMegid::init_parameters() {
    u8 *arg0 = (u8 *)this;
  TechniqueParams *new_var;
  new_var = calc_technique_parameters(0x12, (int) ((RecoveredFields_80235348_arg0 *) arg0)->level, 0xFFFF);
  ((TechniqueParams *)(arg0 + 0xCC))->copy((TechniqueParams *)new_var);
  if ((((s16) ((RecoveredFields_80235348_arg0 *) arg0)->level) >= 0xF) && (TTecCtrl::is_technique_ready() == 0))
  {
    ((RecoveredFields_80235348_arg0 *) arg0)->field_CC = (f32) (tech_high_level_linear_power_table[18].base + (tech_high_level_linear_power_table[18].per_level * ((RecoveredFields_80235348_arg0 *) arg0)->level));
  }
  else
  {
    ((RecoveredFields_80235348_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_80235348_arg0 *) arg0)->field_CC + ((f32) (((RecoveredFields_80235348_arg0 *) arg0)->field_F0 * ((RecoveredFields_80235348_arg0 *) arg0)->level)));
    if (TTecCtrl::is_technique_ready() != 0)
    {
      ((RecoveredFields_80235348_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_80235348_arg0 *) arg0)->field_CC * technique_scale_table[18].power);
    }
  }
  ((RecoveredFields_80235348_arg0 *) arg0)->field_64 = (f32) (((RecoveredFields_80235348_arg0 *) arg0)->field_D0 + ((f32) ((((s16) ((RecoveredFields_80235348_arg0 *) arg0)->level) / 5) * 2)));
  ((RecoveredFields_80235348_arg0 *) arg0)->field_70 = (f32) ((RecoveredFields_80235348_arg0 *) arg0)->field_D4;
}

void TTecMegid::vfunc_8(void *target) {
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (hitIds[i] == ((TObjBase *)(target))->get_entity_id()) {
            found = 1;
        }
    }
    if (found == 0) {
        hitIds[hitCursor] = ((TObjBase *)(target))->get_entity_id();
        hitCursor += 1;
        if (hitCursor >= 32) {
            hitCursor = 31;
        }
        HitInfo_80235490 tmp;
        tmp.type = 5;
        tmp.power = power;
        if (((TObjBase *)(target))->get_entity_id() < 4 && ((TObjChara *)target)->obj_isState3_324() != 0) {
            return;
        }
        HitInfo_80235490 info = tmp;
        ((VObj_80235490 *)target)->m21((void *)source, &info, contact, 0x12, -1);
        play_sound_effect(0x4002AD29, &static_cast<TObjBase *>(target)->position, 0, 0);
        if (sourceId < 12) {
            if ((get_technique_caster_flags(0x12, sourceId) & 1) == 0) {
                queue_destruction();
            }
        }
    }
}

void TTecMegid::create(saddr source, saddr pos, saddr arg2, s32 level) {
    new TTecMegid(source, (u8 *)pos, (u8 *)arg2, level);
}
void TTecMegid::create_ex(saddr source, saddr pos, s32 arg2, s32 level) {
    new TTecMegid(source, (Vec *)pos, arg2, level);
}
void TTecMegid::render() {  }

typedef struct RecoveredFields_802308A0_arg0 RecoveredFields_802308A0_arg0;
TTecMegid::~TTecMegid() {
    for (u32 i = 0; i < TTecMegid__emitter_bands[band].count; ++i) {
        if (emitters[i]) {
            ((TObject *)emitters[i])->queue_destruction();
        }
    }
    mem_free(emitters);
}

void TTecMegid::run_task() {
    u32 i;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    for (i = 0; i < ((Data_80235740 *)TTecMegid__emitter_bands)[band].count; i++) {
        if (((Data_80235740 *)TTecMegid__emitter_bands)[band].rows[i].flags & 4) {
            Vec off = tec_megid_offset_vec;
            Vec p;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, angles[1]);
            matrix_mult_vec(0, &off, &off);
            pop_matrices(1);
            p.x = position.x + off.x;
            p.y = position.y + off.y;
            p.z = position.z + off.z;
            ((TParticleCtrl *)emitters[i])->set_position(&p);
        } else {
            ((TParticleCtrl *)emitters[i])->set_position(&position);
        }
    }
    move_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_technique_contact(1);
}

// The aimed form: the technique flies from `pos` towards `target`.
TTecMegid::TTecMegid(saddr source, u8 *pos, u8 *target, s32 level) : TTecShot(source, pos, target, level) {
    s32 i;
    m_name = TTecMegid__class_name;
    init_parameters();
    *(f32 *)((s8 *)this + 0x178) = 0.0f;
    for (i = 0; i < 0x20; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    spawn_particle_emitters();
    update_by_state();
    if (*(void **)((s8 *)this + 0x1C) != 0) {
        sourceId = ((TObjBase *)(*(void **)((s8 *)this + 0x1C)))->get_entity_id();
    }
}
}

// The facing form: the technique starts at `pos` and flies along the y angle `angle`.
TTecMegid::TTecMegid(saddr source, Vec *pos, s32 angle, s32 level) : TTecShot(source, pos, angle, level) {
    s32 i;
    m_name = TTecMegid__class_name;
    init_parameters();
    *(f32 *)((s8 *)this + 0x178) = 0.0f;
    for (i = 0; i < 0x20; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    spawn_particle_emitters();
    update_by_state();
    if (*(void **)((s8 *)this + 0x1C) != 0) {
        sourceId = ((TObjBase *)(*(void **)((s8 *)this + 0x1C)))->get_entity_id();
    }
}
