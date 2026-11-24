#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeEff.h"
#include "pso/system/memory.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecRaZonde.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/unk/TUnk_804CCB28.h"
#include "pso/technique/TTecCircle.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#pragma readonly_strings on

#include <stddef.h>

#include "pso/technique/TTecResta.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

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

extern "C" {
f32 vector_length(void *);
#pragma push
#pragma opt_common_subs off

typedef struct RecoveredFields_80230D9C_arg0 RecoveredFields_80230D9C_arg0;

#pragma pop


}

struct RecoveredFields_80238D10_arg0
{
  u8 unknown_0[0x78];
  s16 field_78;
  u8 unknown_7A[0xE];
  f32 field_88;
  u8 unknown_8C[0x20];
  s16 field_AC;
};

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
    Vec points[8];
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

typedef struct RecoveredFields_80238D10_arg0 RecoveredFields_80238D10_arg0;

#pragma push
#pragma opt_common_subs off
#pragma pop

void TTecRaZonde::vfunc_8(void *) {
    struct Self_80238C6C *self = (struct Self_80238C6C *)this;
    u32 i;
    self->emitters = (s32 *)mem_alloc(TTecRaZonde__band_profile_table[self->band].count * 4);
    for (i = 0; i < TTecRaZonde__band_profile_table[self->band].count; i++) {
        self->emitters[i] = (saddr)create_particle_emitter(&self->points[i], TTecRaZonde__band_profile_table[self->band].entries[i].entry);
    }
}

void TTecRaZonde::calc_damage() {
    u8 *arg0 = (u8 *)this;
  TechniqueParams *new_var;
  new_var = calc_technique_parameters(8, (int) ((RecoveredFields_80238D10_arg0 *) arg0)->field_78, 0xFFFF);
  ((TechniqueParams *)(arg0 + 0x88))->copy((TechniqueParams *)new_var);
  if ((((s16) ((RecoveredFields_80238D10_arg0 *) arg0)->field_78) >= 0xF) && (TTecCtrl::is_technique_ready() == 0))
  {
    ((RecoveredFields_80238D10_arg0 *) arg0)->field_88 = (f32) (tech_high_level_linear_power_table[8].base + (tech_high_level_linear_power_table[8].per_level * ((RecoveredFields_80238D10_arg0 *) arg0)->field_78));
    return;
  }
  ((RecoveredFields_80238D10_arg0 *) arg0)->field_88 = (f32) (((RecoveredFields_80238D10_arg0 *) arg0)->field_88 + ((f32) (((RecoveredFields_80238D10_arg0 *) arg0)->field_AC * ((RecoveredFields_80238D10_arg0 *) arg0)->field_78)));
  if (TTecCtrl::is_technique_ready() != 0)
  {
    ((RecoveredFields_80238D10_arg0 *) arg0)->field_88 = (f32) (((RecoveredFields_80238D10_arg0 *) arg0)->field_88 * technique_scale_table[8].power);
  }
}
void TTecRaZonde::vfunc_6(void *arg1_arg) {
    u8 *arg1 = (u8 *)arg1_arg;
    Elec_80238E14 d;
    d.type = 3;
    d.val = this->power;
    ((VObj_18_9c98dd *)(arg1))->m21(this->source, d, 0, 8, -1);
}

}

struct Tec_802393D0 { u8 pad[0x20]; f32 pos[3]; u8 pad2c[0xA6 - 0x2C]; s16 band; };

struct RBurst_80238F84 { s32 entry; s32 flags; f32 scale; };

struct RProfile_80238F84 { RBurst_80238F84 *entries; u32 count; };

extern "C" {
void TTecRaZonde::create(void *source, void *origin, s32 level) {
    new TTecRaZonde((saddr)source, (Vec *)origin, level);
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
TTecRaZonde::~TTecRaZonde() {
    u32 i;
    for (i = 0; i < ((RProfile_80238F84 *)TTecRaZonde__band_profile_table)[((Self_80238EC8 *)this)->band].count; i++) {
        if (((Self_80238EC8 *)this)->objs[i] != 0) {
            ((TObject *)(((Self_80238EC8 *)this)->objs[i]))->queue_destruction();
            ((Self_80238EC8 *)this)->objs[i] = 0;
        }
    }
    mem_free(((Self_80238EC8 *)this)->objs);
}


void TTecRaZonde::render() {  }

void TTecRaZonde::run_task() {
    s32 i;
    if (this->collidable == NULL) {
        queue_destruction();
        return;
    }
    this->source = (uaddr)find_entity_by_id(this->sourceId);
    if (this->source == 0) {
        queue_destruction();
        return;
    }
    for (i = 0; i < TTecRaZonde__band_profile_table[this->band].count; i++) {
        if (this->sourceId < 12) {
            if (i == 1) {
                create_timed_particle_emitter((u8 *)this->source + 0x2FC, TTecRaZonde__band_profile_table[this->band].entries[i].entry, 0, 60);
            } else {
                spawn_particle_effect((const Vec *)((u8 *)this->source + 0x2FC), TTecRaZonde__band_profile_table[this->band].entries[i].entry);
            }
        }
    }
    apply_technique_to_area_targets();
    queue_destruction();
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
TTecRaZonde::TTecRaZonde(saddr source, Vec *origin, s32 level) : TTecCircle(source, origin, origin, level) {
    s32 ang;
    s32 i;
    s32 j;
    f32 r;
    f32 len;
    Vec a;
    Vec b;
    m_name = TTecRaZonde_class_name;
    calc_damage();
    if (collidable != NULL) {
        collidable->bodies->radius = (5.0f) + scope;
    }
    vfunc_8(0);
    r = (0.0f);
    ang = 0;
    for (i = 0; i < 8; i++) {
        s16 lv = this->level;
        f32 step = (5.4f);
        if (lv >= 15 && lv < 25) {
            step = (8.1f);
        } else if (lv >= 25 && lv < 30) {
            step = (10.8f);
        }
        r += step;
        ang += 0x2AAA;
        bolt_points[i].x = r * cos_table_lookup(ang) + position.x;
        bolt_points[i].y = position.y;
        bolt_points[i].z = r * sin_table_lookup(ang) + position.z;
    }
    for (j = 0; j < 7; j++) {
        VecCopy((Vec *)&a, (const Vec *)&bolt_points[j]);
        VecCopy((Vec *)&b, (const Vec *)&bolt_points[j + 1]);
        b.x = b.x - a.x;
        b.y = b.y - a.y;
        b.z = b.z - a.z;
        len = vector_length(&b);
        if ((0.0f) != len) {
            normalize_vector(&b);
        }
        new TTecZondeEff(tl_07, &a, &b, 0x14000000, 6, len, 5.0f);
        if (band == 5) {
            new TTecZondeEff(tl_07, &a, &b, 0x14000000, 6, len, 0.5f);
        }
    }
    switch (band) {
    case 0: {
        s32 h = play_sound_effect(0x4002A50A, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    }
    case 1:
        play_sound_effect(0x4002A50A, &position, 0, 0);
        break;
    case 2:
    case 3: {
        s32 h = play_sound_effect(0x4002A50A, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x180, 0);
        }
        break;
    }
    case 4: {
        s32 h = play_sound_effect(0x4002A50A, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x250, 0);
        }
        break;
    }
    case 5: {
        s32 h = play_sound_effect(0x4002A50A, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
    }
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}
#pragma pop

void TTecResta::play_launch_sound() {
    Tec_802393D0 *self = (Tec_802393D0 *)this;
    s32 h;
    switch (self->band) {
    case 0:
    case 1:
        h = play_sound_effect(0x4002AB0E, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AB0E, &position, 0, 0);
        break;
    case 4:
    case 5:
        h = play_sound_effect(0x4002AB0E, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
}
