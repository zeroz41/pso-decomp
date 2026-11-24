#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TechniqueBandSound.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecShot.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/TObjMotion.h"

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

struct HitInfo_802309AC { s32 type; f32 power; };

struct VBase_802309AC { char pad[0x18]; };

struct VObj_802309AC : VBase_802309AC {
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
    virtual void m21(void *, HitInfo_802309AC *, void *, s32, s32);
};

struct Obj_802309AC {
    u8 pad0[0x1C];
    void *source;
    u8 pad20[0xCC - 0x20];
    f32 power;
    u8 padD0[0xF8 - 0xD0];
    void *contact;
    u8 padFC[0x134 - 0xFC];
    u16 ids[32];
    s32 cursor;
};


struct Row_802304A0 { u32 entry; u32 flags; f32 scale; };
struct Band_802304A0 { const Row_802304A0 *rows; u32 count; };
struct Angles_802304A0 { s32 a[3]; };
struct Shot_802304A0 {
    u8 pad0[0x20];
    Vec pos;
    u8 pad2C[0x54 - 0x2C];
    s32 f54;
    s32 angle;
    s32 f5C;
    u8 pad60[0xC6 - 0x60];
    s16 band;
    u16 source;
    u8 padCA[0x130 - 0xCA];
    void **emitters;
};

extern "C" {


#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TTecGiBarta::update_technique_by_phase() {
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A605, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A605, &position, 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A605, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A605, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A605, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}
#pragma pop

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
}

const Row_802304A0 lbl_8044D180[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.0f},
    {0x182, 0x20022, 0.0f},
};
const Row_802304A0 lbl_8044D1A4[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.2f},
    {0x183, 0x20062, 1.4f},
};
const Row_802304A0 lbl_8044D1C8[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.4f},
    {0x184, 0x20062, 1.4f},
};
const Row_802304A0 lbl_8044D1EC[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.6f},
    {0x185, 0x30062, 1.6f},
};
const Row_802304A0 lbl_8044D210[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.8f},
    {0x186, 0x30062, 1.8f},
};
const Row_802304A0 lbl_8044D234[2] = {
    {0x181, 0x42, 2.2f},
    {0x18E, 0x30062, 2.2f},
};
const Band_802304A0 TTecGiBarta__emitter_profile_table[6] = {
    {lbl_8044D180, 3}, {lbl_8044D1A4, 3}, {lbl_8044D1C8, 3},
    {lbl_8044D1EC, 3}, {lbl_8044D210, 3}, {lbl_8044D234, 2},
};
const char *TTecGiBarta__class_name = "TTecGiBarta";
const Vec lbl_8044D288 = {0.0f, 0.0f, 3.0f};


void TTecGiBarta::create_particles() {
    Angles_802304A0 angles;
    Vec pos;
    Vec off;
    Vec p2;
    Vec v;
    u32 i;
    TParticleCtrl *emitter;
    TObjCollidable *src;

    angles.a[0] = this->angles[0];
    angles.a[1] = 0;
    angles.a[2] = this->angles[2];
    emitters = static_cast<TParticleCtrl **>(mem_alloc(TTecGiBarta__emitter_profile_table[band].count * sizeof(*emitters)));
    for (i = 0; i < TTecGiBarta__emitter_profile_table[band].count; i++) {
#ifdef __MWERKS__
        __memcpy(&pos, &position, sizeof(pos));
#else
        pos = position;
#endif
        if (TTecGiBarta__emitter_profile_table[band].rows[i].flags & 0x800) {
            pos.y -= 5.0f;
        }
        if (TTecGiBarta__emitter_profile_table[band].rows[i].flags & 2) {
            emitter = static_cast<TParticleCtrl *>(spawn_continuous_particle_with_direction(
                &pos, &angles, TTecGiBarta__emitter_profile_table[band].rows[i].entry));
        } else {
#ifdef __MWERKS__
            __memcpy(&off, &lbl_8044D288, sizeof(off));
#else
            off = lbl_8044D288;
#endif
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, this->angles[1]);
            matrix_mult_vec(0, &off, &off);
            pop_matrices(1);
            p2.x = position.x + off.x;
            p2.y = position.y + off.y;
            p2.z = position.z + off.z;
            if (TTecGiBarta__emitter_profile_table[band].rows[i].flags & 0x800) {
                p2.y -= 5.0f;
            }
            emitter = create_particle_emitter(&p2, TTecGiBarta__emitter_profile_table[band].rows[i].entry);
        }
        if (emitter != NULL) {
            if (TTecGiBarta__emitter_profile_table[band].rows[i].flags & 0x40) {
                emitter->set_scale(TTecGiBarta__emitter_profile_table[band].rows[i].scale, TTecGiBarta__emitter_profile_table[band].rows[i].scale);
            }
            if (TTecGiBarta__emitter_profile_table[band].rows[i].flags & 0x20) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, (u16)(TTecGiBarta__emitter_profile_table[band].rows[i].flags >> 16)), technique_texture_list, 0, 0, 1.0f);
            }
        }
        emitters[i] = emitter;
    }
    if (band == 5) {
        VecCopy(&v, &position);
        v.y -= 15.0f;
        spawn_particle_effect(&v, 0x1E0);
        spawn_particle_effect(&v, 0x1E1);
        src = find_entity_by_id(sourceId);
        if (src != NULL) {
            emitter = spawn_particle_effect(&src->position, 0x18B);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 6), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(&src->position, 0x18B, 5, 1);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 7), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(&src->position, 0x18B, 10, 1);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 8), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(&src->position, 0x18F, 20, 1);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 5), technique_texture_list, 0, 0, 1.0f);
            }
        }
    }
}
#pragma auto_inline off

typedef struct RecoveredFields_802308A0_arg0 RecoveredFields_802308A0_arg0;
void TTecGiBarta::calc_params() {
    u8 *arg0 = (u8 *)this;
  TechniqueParams *new_var;
  new_var = calc_technique_parameters(4, (int) ((RecoveredFields_802308A0_arg0 *) arg0)->field_C4, 0xFFFF);
  ((TechniqueParams *)(arg0 + 0xCC))->copy((TechniqueParams *)new_var);
  if ((((s16) ((RecoveredFields_802308A0_arg0 *) arg0)->field_C4) >= 0xF) && (TTecCtrl::is_technique_ready() == 0))
  {
    ((RecoveredFields_802308A0_arg0 *) arg0)->field_CC = (f32) (tech_high_level_linear_power_table[4].base + (tech_high_level_linear_power_table[4].per_level * ((RecoveredFields_802308A0_arg0 *) arg0)->field_C4));
  }
  else
  {
    ((RecoveredFields_802308A0_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_802308A0_arg0 *) arg0)->field_CC + ((f32) (((RecoveredFields_802308A0_arg0 *) arg0)->field_F0 * ((RecoveredFields_802308A0_arg0 *) arg0)->field_C4)));
    if (TTecCtrl::is_technique_ready() != 0)
    {
      ((RecoveredFields_802308A0_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_802308A0_arg0 *) arg0)->field_CC * technique_scale_table[4].power);
    }
  }
  ((RecoveredFields_802308A0_arg0 *) arg0)->field_70 = (f32) ((RecoveredFields_802308A0_arg0 *) arg0)->field_D4;
}

void TTecGiBarta::vfunc_8(void *target) {
    Obj_802309AC *self = (Obj_802309AC *)this;
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (self->ids[i] == ((TObjBase *)target)->get_entity_id()) {
            found = 1;
        }
    }
    if (found == 0) {
        self->ids[this->hitCursor] = ((TObjBase *)target)->get_entity_id();
        this->hitCursor += 1;
        if (this->hitCursor >= 32) {
            this->hitCursor = 31;
        }
        HitInfo_802309AC tmp;
        tmp.type = 2;
        tmp.power = this->power;
        HitInfo_802309AC info = tmp;
        ((VObj_802309AC *)target)->m21(self->source, &info, *(void * *)&this->contact, 4, -1);
    }
}

void TTecGiBarta::create(void *owner, Vec *position, Vec *target, s32 level) {
    new TTecGiBarta((saddr)owner, (u8 *)position, (u8 *)target, level);
}

void TTecGiBarta::create_ex(void *owner, Vec *position, s32 angle, s32 level) {
    new TTecGiBarta((saddr)owner, position, angle, level);
}

TTecGiBarta::~TTecGiBarta() {
    for (u32 i = 0; i < TTecGiBarta__emitter_profile_table[band].count; ++i) {
        if (emitters[i]) {
            emitters[i]->queue_destruction();
        }
    }
    mem_free(emitters);
}

void TTecGiBarta::run_task() {
    this->source = (uaddr)find_entity_by_id(this->sourceId);
    if ((u32) this->source == 0U) {
        queue_destruction();
        return;
    }
    move_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_all_technique_contacts();
}

TTecGiBarta::TTecGiBarta(saddr source, u8 *pos, u8 *target, s32 level)
    : TTecShot(source, pos, target, level) {
    s32 i;
    m_name = TTecGiBarta__class_name;
    calc_params();
    halfWidth = 12.0f;
    for (i = 0; i < 32; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    if (this->source) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
    create_particles();
    update_technique_by_phase();
}

TTecGiBarta::TTecGiBarta(saddr source, Vec *pos, s32 angle, s32 level)
    : TTecShot(source, pos, angle, level) {
    s32 i;
    m_name = TTecGiBarta__class_name;
    calc_params();
    for (i = 0; i < 0x20; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
    create_particles();
    update_technique_by_phase();
}

void TTecGiBarta::render() {  }
