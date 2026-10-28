#include "types.h"
#include "pso/misc/TTecRaBarta.h"
extern "C" void *__dt__13TUnk_804CC148Fv(void *, s16);
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/misc/TLobby_80226070.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/misc/TUnk_804CCB28.h"
#include "pso/effect/TUnk_804CC148.h"
#pragma readonly_strings on

#include <stddef.h>

#include "pso/misc/TTecAnti.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TTecPlayerInfluence.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80237194_lbl_8044D8EC {
    s32 value;
    u8 remaining[0x8];
};

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

typedef struct Vec_80237494
{
  f32 x;
  f32 y;
  f32 z;
} Vec_80237494;

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

struct Params_802377FC { u8 pad[0x14]; s16 base; s16 per_level; };

struct Scale_802377FC { u8 pad[0x28]; f32 boost; };

struct RaBarta_802377FC {
    u8 pad[0x78];
    s16 level;
    u8 pad7a[0x88 - 0x7a];
    f32 amount;
    u8 pad8c[0xac - 0x8c];
    s16 per_level;
};

extern "C" {
u16 get_entity_id(void *);

void *__nw__7TObjectFUl(u32);
void *get_bml_motion(void *, int);
void *get_bml_model(void *, int);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);

void *mem_alloc(u32 size);
extern void *technique_effect_bml;
extern void *lbl_805D63B0;
s32 is_technique_ready__8TTecCtrlFv();
s32 calc_technique_parameters(s32, s32, s32);
extern Params_802377FC tech_high_level_linear_power_table;
extern Scale_802377FC lbl_804CC55C;
void calc_parameters__11TTecRaBartaFv(RaBarta_802377FC *self);

s32 play_sound_effect(s32, s32, s32, s32);
void __dl__7TObjectFPv(void *);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);

typedef char RecoveredGlobal_80237194_lbl_8044D8EC_size[sizeof(RecoveredGlobal_80237194_lbl_8044D8EC) == 0xC ? 1 : -1];

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
typedef struct Vec_80237494 Vec_80237494;
void TTecRaBarta::vfunc_8(void *pos) {
    Rabarta_80237494 *self = (Rabarta_80237494 *)this;
  u32 i;
  Vec_80237494 point;
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
      ((TObjPlayer *)(self->emitters[i]))->set_position_xy(binding->scale, binding->scale);
    }
    if (rabarta_band_emitter_table[self->band].emitters[i].flags & 0x20)
    {
      u32 mid = rabarta_band_emitter_table[self->band].emitters[i].flags >> 16;
      if (self && self)
      {
      }
      attach_particle_model((u8 *)self->emitters[i], (s32)(get_bml_model(technique_effect_bml, mid)), (s32)lbl_805D63B0, 0, 0, (f32)(1.0f));
    }
  }
  if (self->band == 5)
  {
    Vec_80237494 point2;
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
      attach_particle_model((u8 *)emitter, (s32)(get_bml_model(technique_effect_bml, id)), (s32)lbl_805D63B0, (s32)(get_bml_motion(technique_effect_bml, 1)), 0, (f32)(1.0f));
    }
  }
}

extern const f32 lbl_805DC8C4 = 5.0f;

void TTecRaBarta::vfunc_9() {
    s32 handle;

    switch (*(s16 *)&this->unk_7A) {
    case 0:
        this->m_ec = play_sound_effect(0x4002A706, this->source + 0x2FC, 0, 0);
        handle = this->m_ec;
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, 0x100, 0);
        }
        return;
    case 1:
        this->m_ec = play_sound_effect(0x4002A706, this->source + 0x2FC, 0, 0);
        return;
    case 2:
    case 3:
        this->m_ec = play_sound_effect(0x4002A706, this->source + 0x2FC, 0, 0);
        handle = this->m_ec;
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x180, 0);
        }
        break;
    case 4:
        this->m_ec = play_sound_effect(0x4002A706, this->source + 0x2FC, 0, 0);
        handle = this->m_ec;
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x250, 0);
        }
        break;
    case 5:
        this->m_ec = play_sound_effect(0x4002A706, this->source + 0x2FC, 0, 0);
        handle = this->m_ec;
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x100, 0);
        }
        break;
    }
}

void TTecRaBarta::calc_parameters() {
    RaBarta_802377FC *self = (RaBarta_802377FC *)this;
    s32 res = calc_technique_parameters(5, self->level, 0xFFFF);
    ((TTecAnti *)(&self->amount))->copy_params((u8 *)res);
    if (self->level >= 0xF && is_technique_ready__8TTecCtrlFv() == 0) {
        self->amount = tech_high_level_linear_power_table.base + tech_high_level_linear_power_table.per_level * self->level;
        return;
    }
    self->amount = self->amount + (f32)(self->per_level * self->level);
    if (is_technique_ready__8TTecCtrlFv() != 0) {
        self->amount = self->amount * lbl_804CC55C.boost;
    }
}

void TTecRaBarta::vfunc_6(void *target) {
    Obj_80237900 *self = (Obj_80237900 *)this;
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (self->ids[i] == get_entity_id(((VObj_80237900 *)target))) {
            found = 1;
        }
    }
    if (found == 0) {
        self->ids[*(s32 *)&this->m_138] = get_entity_id(((VObj_80237900 *)target));
        *(s32 *)&this->m_138 += 1;
        if (*(s32 *)&this->m_138 >= 32) {
            *(s32 *)&this->m_138 = 31;
        }
        HitInfo_80237900 tmp;
        tmp.type = 2;
        tmp.power = this->m_88;
        HitInfo_80237900 info = tmp;
        ((VObj_80237900 *)target)->m21(self->source, &info, self->contact, 5, -1);
    }
}

}

#define TTecRaBarta_class_name ((u32)TTecRaBarta_class_name)
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
#define rabarta_band_emitter_table ((struct Profile_80237A94 *)rabarta_band_emitter_table)
#define __dl__7TObjectFPv ((s32 (*)(void *))__dl__7TObjectFPv)
#define calc_parameters__11TTecRaBartaFv ((void (*)(void *))calc_parameters__11TTecRaBartaFv)

struct Vec_80237DAC { f32 x, y, z; };

typedef struct Ids_80237CCC { u8 pad[0xF8]; u16 ids[32]; } Ids_80237CCC;

typedef struct Vec_80237FB8 { f32 x, y, z; } Vec_80237FB8;

typedef struct TTecRaFoie_80237FB8 {
    u8 pad0[0x7C];
    Vec_80237FB8 target;
    u8 pad1[0xEC - 0x88];
    s32 target_count;
    u16 first_id;
    u8 pad2[0x148 - 0xF2];
    s32 explicit_position;
} TTecRaFoie_80237FB8;

typedef struct TObjPlayer_80237FB8 {
    u8 pad0[0x2FC];
    Vec_80237FB8 pos;
} TObjPlayer_80237FB8;

struct Eff_80237BD8 { u8 pad[0xc]; f32 scale; };

struct Holder_80237BD8 { u8 pad[0xa4]; Eff_80237BD8 *eff; };

struct Self_80237BD8 {
    u32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    void *source;
    u8 pos[0xc];
    u8 pad2c[0x7c - 0x2c];
    u8 src_pos[0xc];
    u8 pad88[0x90 - 0x88];
    f32 range;
    u8 pad94[0xb4 - 0x94];
    u16 fb4;
    u8 padb6[0xe8 - 0xb6];
    Holder_80237BD8 *holder;
    u8 padec[4];
    s32 ff0;
    u8 padf4[4];
    u16 ids[32];
    s32 f138;
};

extern "C" {
void *find_entity_by_id(u16 id);
s32 apply_technique_to_area_targets__13TUnk_804CC148Fv(void *, int);

u8 *construct_area_technique_base(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern s32 __vt__11TTecRaBarta[];
struct Profile_80237A94 { void *entries; u32 count; };
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

void mem_free(void *p);

void *TTecRaBarta__ct(void *self_, void *source, void *origin, void *pos, void *level);
void create__11TTecRaBartaFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);

void create__11TTecRaBartaFPvPvPvPv(void *source, void *origin, void *pos, void *level) {
    void *o;
    o = __nw__7TObjectFUl(0x13C);
    if (o != NULL) {
        TTecRaBarta__ct(o, source, origin, pos, level);
    }
}

void TTecRaBarta::create(void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x13C);
    if (o != NULL) {
        ((TTecRaBarta *)o)->construct_area(this, arg1, arg2);
    }
}

struct Self_80237A94 *__dt__11TTecRaBartaFv(struct Self_80237A94 *self, s16 arg1) {
    u32 i;
    void *obj;

    if (self != NULL) {
        self->vtable = __vt__11TTecRaBarta;
        for (i = 0; i < rabarta_band_emitter_table[self->band].count; i++) {
            obj = self->objs[i];
            if (obj != NULL) {
                queue_destruction__7TObjectFv(obj);
            }
        }
        stop_sound_request((s32)self->emitters);
        mem_free(self->objs);
        __dt__13TUnk_804CC148Fv((void *)((TUnk_804CC148 *)self), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

void TTecRaBarta::render() {  }

void TTecRaBarta::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    if ((u32) this->m_e8 == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    this->source = (u32)find_entity_by_id((this->m_b4));
    if ((u32) this->source == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    temp_r4 = this->age;
    this->age = (temp_r4 + 1);
    apply_technique_to_area_targets__13TUnk_804CC148Fv(arg0, temp_r4);
    if ((s32) this->age > (s16) this->m_a8) {
        queue_destruction__7TObjectFv((arg0));
    }
}

#pragma push
#pragma opt_common_subs off
struct Vec_80237DAC;

#define self ((Self_80237BD8 *)self_)
void *TTecRaBarta__ct(void *self_, void *source, void *origin, void *pos, void *level) {
    s32 i;
    typedef Vec_80237DAC *(*VecCopyFn_80237BD8)(void *, void *);
    construct_area_technique_base((u8 *)self_, (s32)source, (s32)origin, (s32)pos, (s32)level);
    self->vt = __vt__11TTecRaBarta;
    self->f0 = TTecRaBarta_class_name;
    calc_parameters__11TTecRaBartaFv(self);
    self->ff0 = 1;
    ((VecCopyFn_80237BD8)VecCopy)(self->pos, ((VecCopyFn_80237BD8)VecCopy)(self->src_pos, pos));
    if (self->holder != 0) {
        self->holder->eff->scale = self->range;
    }
    for (i = 0; i < 32; i++) {
        self->ids[i] = 0xFFFF;
    }
    self->f138 = 0;
    ((TTecRaBarta *)self)->vfunc_8((void *)((s32)self->pos));
    ((TTecRaBarta *)self)->vfunc_9();
    if (self->source != 0) {
        self->fb4 = get_entity_id(self->source);
    }
    return self_;
}
#undef self
#pragma pop

void *TTecRaBarta::construct_area(void *source, void *origin, void *level) {
    s32 i;
    construct_area_technique_base((u8 *)this, (s32)source, (s32)origin, (s32)origin, (s32)level);
    *(s32 **)((s8 *)this + 0x18) = __vt__11TTecRaBarta;
    *(u32 *)&this->m_name = TTecRaBarta_class_name;
    this->m_f0 = 0;
    calc_parameters__11TTecRaBartaFv(this);
    if (this->m_e8 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)(this->m_e8 + 0xA4)) + 0xC) = this->m_90;
    }
    for (i = 0; i < 32; i++) {
        ((Ids_80237CCC *) this)->ids[i] = 0xFFFF;
    }
    this->m_138 = 0;
    this->vfunc_8(0);
    this->vfunc_9();
    if (this->source != NULL) {
        this->m_b4 = get_entity_id(*(void * *)&this->source);
    }
    return this;
}

}

#undef calc_parameters__11TTecRaBartaFv

#undef __dl__7TObjectFPv
#undef rabarta_band_emitter_table
#undef __nw__7TObjectFUl
#undef TTecRaBarta_class_name
