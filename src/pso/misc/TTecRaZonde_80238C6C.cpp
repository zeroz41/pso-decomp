#include "types.h"
#include "pso/misc/TTecRaZonde.h"
#include "pso/system/vector.h"
#include "pso/misc/TTecZonde.h"
#include "pso/misc/TUnk_804CCB28.h"
#include "pso/effect/TUnk_804CC148.h"
#pragma readonly_strings on

#include <stddef.h>

#include "pso/misc/TTecResta.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TTecAnti.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80238388_lbl_8044DAF0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80230D9C_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_80230D9C_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
};

struct RecoveredFields_80230D9C_arg0
{
  u8 unknown_0[0x78];
  s16 field_78;
  u8 unknown_7A[0xE];
  f32 field_88;
  u8 unknown_8C[0x20];
  s16 field_AC;
};

#pragma fp_contract on
struct Vec_80239070 { f32 x, y, z; };

struct Eff_80239070 { u8 pad[0xC]; f32 scale; };

struct Holder_80239070 { u8 pad[0xA4]; Eff_80239070 *eff; };

struct Self_80239070 {
    u32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    void *source;
    Vec_80239070 pos;
    u8 pad2c[0x78 - 0x2C];
    s16 level;
    s16 band;
    u8 pad7c[0x90 - 0x7C];
    f32 range;
    u8 pad94[0xB4 - 0x94];
    u16 fb4;
    u8 padb6[0xE8 - 0xB6];
    Holder_80239070 *holder;
    u8 padec[0xF0 - 0xEC];
    Vec_80239070 pts[8];
};

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 calc_technique_parameters(int, int, int);
s32 is_technique_ready__8TTecCtrlFv();
extern RecoveredGlobal_80230D9C_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_80230D9C_lbl_804CC55C lbl_804CC55C;
u16 get_entity_id(void *);
void update_technique_slot__10TTecRaFoieFl(s32 handle, s32 pitch, s32 c);
s32 play_sound_effect(s32 id, void *pos, s32 a, s32 b);
void *__nw__7TObjectFUl(int);
u8 *construct_area_technique_base(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 vector_length(void *);
void normalize_vector(void *);
extern void *__vt__11TTecRaZonde[];
extern s32 tl_07;
void *TTecRaZonde__ct(void *self_, void *source, void *origin, void *level);
#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80238388_lbl_8044DAF0_size[sizeof(RecoveredGlobal_80238388_lbl_8044DAF0) == 0x10 ? 1 : -1];

typedef struct RecoveredFields_80230D9C_arg0 RecoveredFields_80230D9C_arg0;
typedef struct RecoveredGlobal_80230D9C_lbl_804CC510 RecoveredGlobal_80230D9C_lbl_804CC510;
typedef struct RecoveredGlobal_80230D9C_lbl_804CC55C RecoveredGlobal_80230D9C_lbl_804CC55C;
typedef char RecoveredGlobal_80230D9C_lbl_804CC510_size[((sizeof(RecoveredGlobal_80230D9C_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_80230D9C_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80230D9C_lbl_804CC55C)) == 0x98) ? (1) : (-1)];

#pragma pop


}
struct RecoveredGlobal_802384E0_lbl_804CCB28;

struct RecoveredGlobal_802384E0_lbl_804CCB28 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_802384E0_lbl_804CCB28_size[sizeof(RecoveredGlobal_802384E0_lbl_804CCB28) == 0x18 ? 1 : -1];

struct RecoveredGlobal_802385EC_lbl_804CCB28 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_802385EC_lbl_804CCB28_size[sizeof(RecoveredGlobal_802385EC_lbl_804CCB28) == 0x18 ? 1 : -1];

struct RecoveredGlobal_80238D10_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_80238D10_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
};

struct RecoveredFields_80238D10_arg0
{
  u8 unknown_0[0x78];
  s16 field_78;
  u8 unknown_7A[0xE];
  f32 field_88;
  u8 unknown_8C[0x20];
  s16 field_AC;
};

typedef struct Point_80238C6C { f32 x, y, z; } Point_80238C6C;

struct Entry_80238C6C { s32 entry; u8 pad[8]; };

struct Profile_80238C6C { struct Entry_80238C6C *entries; u32 count; };

extern const Entry_80238C6C lbl_8044DB08[1] = {{147}};
extern const Entry_80238C6C lbl_8044DB14[2] = {{170}, {173}};
extern const Entry_80238C6C lbl_8044DB2C[2] = {{171}, {174}};
extern const Profile_80238C6C TTecRaZonde__band_profile_table[6] = {
    {(Entry_80238C6C *)lbl_8044DB08, 1}, {(Entry_80238C6C *)lbl_8044DB08, 1}, {(Entry_80238C6C *)lbl_8044DB08, 1},
    {(Entry_80238C6C *)lbl_8044DB14, 2}, {(Entry_80238C6C *)lbl_8044DB14, 2}, {(Entry_80238C6C *)lbl_8044DB2C, 2},
};
const char *TTecRaZonde_class_name = "TTecRaZonde";

struct Self_80238C6C {
    u8 pad0[0x7A];
    s16 band;
    u8 pad1[0xEC - 0x7C];
    s32 *emitters;
    Point_80238C6C points[8];
};

struct Elec_80238E14 { s32 type; f32 val; };

struct VBase_18_9c98dd { char pad[0x18]; };

struct VObj_18_9c98dd : VBase_18_9c98dd {
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
    virtual s32 m21(s32, Elec_80238E14, s32, s32, s32);
};

extern "C" {
void *find_entity_by_id(u16 id);
void update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
void *create_particle_emitter(void *pos, s32 id);
void *mem_alloc(u32 size);

typedef struct RecoveredFields_80238D10_arg0 RecoveredFields_80238D10_arg0;
typedef struct RecoveredGlobal_80238D10_lbl_804CC510 RecoveredGlobal_80238D10_lbl_804CC510;
typedef struct RecoveredGlobal_80238D10_lbl_804CC55C RecoveredGlobal_80238D10_lbl_804CC55C;
typedef char RecoveredGlobal_80238D10_lbl_804CC510_size[((sizeof(RecoveredGlobal_80238D10_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_80238D10_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80238D10_lbl_804CC55C)) == 0x98) ? (1) : (-1)];

#pragma push
#pragma opt_common_subs off
#pragma pop

void TTecRaZonde::vfunc_8(void *) {
    struct Self_80238C6C *self = (struct Self_80238C6C *)this;
    u32 i;
    self->emitters = (s32 *)mem_alloc(TTecRaZonde__band_profile_table[self->band].count * 4);
    for (i = 0; i < TTecRaZonde__band_profile_table[self->band].count; i++) {
        self->emitters[i] = (s32)create_particle_emitter(&self->points[i], TTecRaZonde__band_profile_table[self->band].entries[i].entry);
    }
}

void TTecRaZonde::calc_damage() {
    u8 *arg0 = (u8 *)this;
  s32 new_var;
  new_var = calc_technique_parameters(8, (int) ((RecoveredFields_80238D10_arg0 *) arg0)->field_78, 0xFFFF);
  ((TTecAnti *)(arg0 + 0x88))->copy_params((u8 *)new_var);
  if ((((s16) ((RecoveredFields_80238D10_arg0 *) arg0)->field_78) >= 0xF) && (is_technique_ready__8TTecCtrlFv() == 0))
  {
    ((RecoveredFields_80238D10_arg0 *) arg0)->field_88 = (f32) ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x20))) + ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x22))) * ((RecoveredFields_80238D10_arg0 *) arg0)->field_78));
    return;
  }
  ((RecoveredFields_80238D10_arg0 *) arg0)->field_88 = (f32) (((RecoveredFields_80238D10_arg0 *) arg0)->field_88 + ((f32) (((RecoveredFields_80238D10_arg0 *) arg0)->field_AC * ((RecoveredFields_80238D10_arg0 *) arg0)->field_78)));
  if (is_technique_ready__8TTecCtrlFv() != 0)
  {
    ((RecoveredFields_80238D10_arg0 *) arg0)->field_88 = (f32) (((RecoveredFields_80238D10_arg0 *) arg0)->field_88 * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x40))));
  }
}
void TTecRaZonde::vfunc_6(void *arg1_arg) {
    u8 *arg1 = (u8 *)arg1_arg;
    Elec_80238E14 d;
    d.type = 3;
    d.val = this->m_88;
    ((VObj_18_9c98dd *)(arg1))->m21(this->source, d, 0, 8, -1);
}

}

struct Tec_802393D0 { u8 pad[0x20]; f32 pos[3]; u8 pad2c[0xA6 - 0x2C]; s16 band; };

struct RBurst_80238F84 { s32 entry; s32 flags; f32 scale; };

struct RProfile_80238F84 { RBurst_80238F84 *entries; u32 count; };

struct Obj_80238F84 {
    u8 pad0[0x1C];
    void *source;
    u8 pad20[0x7A - 0x20];
    s16 band;
    u8 pad7C[0xB4 - 0x7C];
    u16 sourceId;
    u8 padB6[0xE8 - 0xB6];
    void *proxy;
};

extern "C" {
void create_timed_particle_emitter(void *, s32, s32, s32, void *);
void spawn_particle_effect(void *, s32, void *);
void run_task__11TTecRaZondeFv(Obj_80238F84 *self);
void TTecRaZonde::create(void *origin, void *level) {
    void *o;
    o = __nw__7TObjectFUl(0x150);
    if (o != NULL) {
        TTecRaZonde__ct(o, this, origin, level);
    }
}

}
struct Self_80238EC8 {
    u8 pad0[0x18];
    void *vtable;
    u8 pad1[0x7A - 0x1C];
    s16 band;
    u8 pad2[0xEC - 0x7C];
    void **objs;
};
extern "C" {
void mem_free(void *);

}
TTecRaZonde::~TTecRaZonde() {
    u32 i;
    for (i = 0; i < ((RProfile_80238F84 *)TTecRaZonde__band_profile_table)[((Self_80238EC8 *)this)->band].count; i++) {
        if (((Self_80238EC8 *)this)->objs[i] != 0) {
            queue_destruction__7TObjectFv(((Self_80238EC8 *)this)->objs[i]);
            ((Self_80238EC8 *)this)->objs[i] = 0;
        }
    }
    mem_free(((Self_80238EC8 *)this)->objs);
}


void TTecRaZonde::render() {  }

void run_task__11TTecRaZondeFv(Obj_80238F84 *self) {
    s32 i;
    if (self->proxy == NULL) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    self->source = find_entity_by_id(self->sourceId);
    if (self->source == NULL) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    for (i = 0; i < ((RProfile_80238F84 *)TTecRaZonde__band_profile_table)[self->band].count; i++) {
        if (self->sourceId < 12) {
            if (i == 1) {
                create_timed_particle_emitter((u8 *)self->source + 0x2FC, ((RProfile_80238F84 *)TTecRaZonde__band_profile_table)[self->band].entries[i].entry, 0, 60, self->source);
            } else {
                spawn_particle_effect((u8 *)self->source + 0x2FC, ((RProfile_80238F84 *)TTecRaZonde__band_profile_table)[self->band].entries[i].entry, self->source);
            }
        }
    }
    ((TUnk_804CC148 *)self)->apply_technique_to_area_targets();
    queue_destruction__7TObjectFv(self);
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#define self ((Self_80239070 *)self_)
void *TTecRaZonde__ct(void *self_, void *source, void *origin, void *level) {
    s32 ang;
    s32 i;
    s32 j;
    f32 r;
    f32 len;
    Vec_80239070 a;
    Vec_80239070 b;
    construct_area_technique_base((u8 *)self_, (s32)source, (s32)origin, (s32)origin, (s32)level);
    self->vt = __vt__11TTecRaZonde;
    self->f0 = (u32)TTecRaZonde_class_name;
    ((TTecRaZonde *)self)->calc_damage();
    if (self->holder != 0) {
        self->holder->eff->scale = (5.0f) + self->range;
    }
    ((TTecRaZonde *)self)->vfunc_8(0);
    r = (0.0f);
    ang = 0;
    for (i = 0; i < 8; i++) {
        s16 lv = self->level;
        f32 step = (5.4f);
        if (lv >= 15 && lv < 25) {
            step = (8.1f);
        } else if (lv >= 25 && lv < 30) {
            step = (10.8f);
        }
        r += step;
        ang += 0x2AAA;
        self->pts[i].x = r * cos_table_lookup(ang) + self->pos.x;
        self->pts[i].y = self->pos.y;
        self->pts[i].z = r * sin_table_lookup(ang) + self->pos.z;
    }
    for (j = 0; j < 7; j++) {
        VecCopy((Vec *)&a, (const Vec *)&self->pts[j]);
        VecCopy((Vec *)&b, (const Vec *)&self->pts[j + 1]);
        b.x = b.x - a.x;
        b.y = b.y - a.y;
        b.z = b.z - a.z;
        len = vector_length(&b);
        if ((0.0f) != len) {
            normalize_vector(&b);
        }
        {
            u8 *o = (u8 *)__nw__7TObjectFUl(0x260);
            if (o != 0) {
                ((TTecZonde *)o)->construct_bolt_effect((u8 *)tl_07, (u8 *)&a, (u8 *)&b, 0x14000000, 6, len, (5.0f));
            }
        }
        if (self->band == 5) {
            u8 *o = (u8 *)__nw__7TObjectFUl(0x260);
            if (o != 0) {
                ((TTecZonde *)o)->construct_bolt_effect((u8 *)tl_07, (u8 *)&a, (u8 *)&b, 0x14000000, 6, len, (0.5f));
            }
        }
    }
    switch (self->band) {
    case 0: {
        s32 h = play_sound_effect(0x4002A50A, &self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, 0x100, 0);
        }
        break;
    }
    case 1:
        play_sound_effect(0x4002A50A, &self->pos, 0, 0);
        break;
    case 2:
    case 3: {
        s32 h = play_sound_effect(0x4002A50A, &self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x180, 0);
        }
        break;
    }
    case 4: {
        s32 h = play_sound_effect(0x4002A50A, &self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x250, 0);
        }
        break;
    }
    case 5: {
        s32 h = play_sound_effect(0x4002A50A, &self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x100, 0);
        }
        break;
    }
    }
    if (self->source != 0) {
        self->fb4 = get_entity_id(self->source);
    }
    return self_;
}
#undef self
#pragma pop

void TTecResta::play_launch_sound() {
    Tec_802393D0 *self = (Tec_802393D0 *)this;
    s32 h;
    switch (self->band) {
    case 0:
    case 1:
        h = play_sound_effect(0x4002AB0E, self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AB0E, self->pos, 0, 0);
        break;
    case 4:
    case 5:
        h = play_sound_effect(0x4002AB0E, self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x100, 0);
        }
        break;
    }
}

