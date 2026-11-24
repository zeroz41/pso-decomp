#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TechniqueBandSound.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/technique/TTecBarta.h"
#include "pso/technique/TTecCircle.h"
#include "pso/technique/TTecShot.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"

#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

struct HitInfo_8022B8F4 { s32 type; f32 power; };

struct VBase_8022B8F4 { char pad[0x18]; };

struct VObj_8022B8F4 : VBase_8022B8F4 {
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
    virtual void m21(void *, HitInfo_8022B8F4 *, void *, s32, s32);
};

struct Obj_8022B8F4 {
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

struct List_8022BD74 { u32 ids[16]; s32 vals[16]; s32 count; };

struct VBase_8022BD74 { u8 pad[0x18]; };

struct VObj_8022BD74 : VBase_8022BD74 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(u32 target);
};

struct Tec_8022BD74 {
    u8 pad0[0x1C];
    void *owner;
    u8 pad20[0xB8 - 0x20];
    s32 fb8;
    u8 padbc[0xE8 - 0xBC];
    u32 fe8;
};

extern "C" {

}

const TechniqueEmitterSourceRow lbl_8044CC78[3] = {
    {0x190, 2, 1.0f}, {0x191, 0, 1.0f}, {0x192, 0, 1.0f},
};
const TechniqueEmitterSourceRow lbl_8044CC9C[3] = {
    {0x190, 2, 1.2f}, {0x191, 2, 1.2f}, {0x192, 0, 1.0f},
};
const TechniqueEmitterSourceRow lbl_8044CCC0[3] = {
    {0x190, 2, 1.4f}, {0x191, 2, 1.4f}, {0x192, 0, 1.0f},
};
const TechniqueEmitterSourceRow lbl_8044CCE4[4] = {
    {0x190, 2, 1.0f}, {0x191, 2, 1.0f}, {0x192, 0, 1.0f}, {0x198, 1, 1.0f},
};
const TechniqueEmitterSourceRow lbl_8044CD14[4] = {
    {0x190, 2, 1.2f}, {0x191, 2, 1.2f}, {0x192, 0, 1.0f}, {0x198, 1, 1.0f},
};
const TechniqueEmitterSourceRow lbl_8044CD44[7] = {
    {0x190, 2, 1.6f}, {0x191, 2, 1.6f}, {0x192, 0, 1.0f}, {0x198, 1, 1.0f},
    {0x193, 0x20, 1.0f}, {0x1D8, 0x20, 1.0f}, {0x1D7, 0x20, 1.0f},
};
const TechniqueEmitterSourceTable TTecBarta__emitter_bands[6] = {
    {lbl_8044CC78, 3}, {lbl_8044CC9C, 3}, {lbl_8044CCC0, 3},
    {lbl_8044CCE4, 4}, {lbl_8044CD14, 4}, {lbl_8044CD44, 7},
};
const char *TTecBarta__class_name = "TTecBarta";
extern "C" {
s32 get_type__10TObjPlayerFPv(void *);
List_8022BD74 *find_area_contact__10TTecCircleFl(Tec_8022BD74 *, void *);

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TTecBarta::update_technique_by_state() {
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A604, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A604, &position, 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A604, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A604, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A604, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}
#pragma pop


void TTecBarta::create_particle_emitters() {
    s32 angles[3];
    s32 reverse[3];
    u32 i;
    const TechniqueEmitterSourceRow *row;
    u32 flags;
    saddr base = (saddr)this;
    angles[0] = this->angles[0];
    angles[1] = 0;
    angles[2] = this->angles[2];
    this->emitters = (TechniqueParticleEmitter **)mem_alloc(TTecBarta__emitter_bands[this->band].count * 4);
    for (i = 0; i < TTecBarta__emitter_bands[this->band].count; i++) {
        row = &TTecBarta__emitter_bands[this->band].rows[i];
        flags = row->flags;
        if (flags & 2) {
            this->emitters[i] = (TechniqueParticleEmitter *)spawn_continuous_particle_with_direction((f32 *)(base + 0x20), angles, row->entry);
        } else if (flags & 1) {
            reverse[0] = this->angles[0] + 0x8000;
            reverse[1] = 0;
            reverse[2] = this->angles[2];
            this->emitters[i] = (TechniqueParticleEmitter *)spawn_continuous_particle_with_direction((f32 *)(base + 0x20), reverse, TTecBarta__emitter_bands[this->band].rows[i].entry);
        } else {
            this->emitters[i] = (TechniqueParticleEmitter *)create_particle_emitter((f32 *)(base + 0x20), row->entry);
        }
        if (this->emitters[i] != NULL) {
            row = &TTecBarta__emitter_bands[this->band].rows[i];
            if (row->flags & 0x20) {
                attach_particle_model(reinterpret_cast<TParticleCtrl *>(this->emitters[i]), get_bml_model(technique_effect_bml, 0), technique_texture_list, get_bml_motion(technique_effect_bml, 0), 0, 1.0f);
            } else {
                ((TParticleCtrl *)(this->emitters[i]))->set_scale(row->scale, row->scale);
            }
        }
    }
}

void TTecBarta::init_parameters() {
    u8 *arg0 = (u8 *)this;
  saddr new_var;
  new_var = (saddr) calc_technique_parameters(3, this->level, 0xFFFF);
  ((TechniqueParams *)(arg0 + 0xCC))->copy((TechniqueParams *)new_var);
  if (((this->level) >= 0xF) && (TTecCtrl::is_technique_ready() == 0))
  {
    this->power = (f32) (tech_high_level_linear_power_table[3].base + (tech_high_level_linear_power_table[3].per_level * (this->level)));
  }
  else
  {
    this->power = (f32) ((this->power) + ((f32) ((*((s16 *) (((s8 *) arg0) + 0xF0))) * (this->level))));
    if (TTecCtrl::is_technique_ready() != 0)
    {
      this->power = (f32) ((this->power) * technique_scale_table[3].power);
    }
  }
  this->speed = (f32) ((*((f32 *) (((s8 *) arg0) + 0xD0))) + ((f32) (((this->level) / 5) * 2)));
  this->range = (f32) (*((f32 *) (((s8 *) arg0) + 0xD4)));
}

void TTecBarta::create(void *source, void *origin, void *aim, s32 level) {
    new TTecBarta((saddr)source, (u8 *)origin, (u8 *)aim, level);
}

void TTecBarta::create_ex(void *source, void *origin, s32 angle, s32 level) {
    new TTecBarta((saddr)source, (Vec *)origin, angle, level);
}

void TTecBarta::vfunc_8(void *target) {
    Obj_8022B8F4 *self = (Obj_8022B8F4 *)this;
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
        HitInfo_8022B8F4 tmp;
        tmp.type = 19;
        tmp.power = this->power;
        HitInfo_8022B8F4 info = tmp;
        ((VObj_8022B8F4 *)target)->m21(self->source, &info, this->contact, 3, -1);
    }
}

TTecBarta::~TTecBarta() {
    for (u32 i = 0; i < TTecBarta__emitter_bands[band].count; ++i) {
        if (emitters[i]) {
            ((TObject *)emitters[i])->queue_destruction();
            emitters[i] = 0;
        }
    }
    mem_free(emitters);
}

void TTecBarta::run_task() {
    s32 i;
    this->source = (uaddr)find_entity_by_id(this->sourceId);
    if (this->source == NULL) {
        ((TObject *)this)->queue_destruction();
        return;
    }
    for (i = 0; i < TTecBarta__emitter_bands[this->band].count; i++) {
        Vec pos = *(Vec *)&this->position;
        if (TTecBarta__emitter_bands[this->band].rows[i].flags & 0x20) {
            pos.y -= 10.0f;
        }
        if (this->emitters[i] != NULL) {
            ((TParticleCtrl *)this->emitters[i])->set_position(&pos);
        }
        if (this->band == 5 && i == 5 && this->emitters[i] != NULL) {
            ((TParticleCtrl *)this->emitters[i])->set_position(&pos);
        }
    }
    if (this->band == 5) {
        TechniqueParticleEmitter *e = (TechniqueParticleEmitter *)create_timed_particle_emitter(&this->position.x, 0x18A, 0x14, 1);
        if (e != NULL) {
            attach_particle_model(reinterpret_cast<TParticleCtrl *>(e), get_bml_model(technique_effect_bml, 5), technique_texture_list, 0, 0, 1.0f);
        }
    }
    move_ground_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_all_technique_contacts();
}

void TTecBarta::render() {  }

}

TTecBarta::TTecBarta(saddr source, u8 *pos, u8 *target, s32 level)
    : TTecShot(source, pos, target, level) {
    s32 i;
    m_name = TTecBarta__class_name;
    init_parameters();
    collisionBody.flags = 0x40003;
    for (i = 0; i < 32; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    create_particle_emitters();
    update_technique_by_state();
    if (this->source) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

// The facing form starts 5 units higher.
TTecBarta::TTecBarta(saddr source, Vec *pos, s32 angle, s32 level)
    : TTecShot(source, pos, angle, level) {
    s32 i;
    m_name = TTecBarta__class_name;
    init_parameters();
    for (i = 0; i < 32; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    collisionBody.flags = 0x40003;
    position.y += 5.0f;
    create_particle_emitters();
    update_technique_by_state();
    if (this->source) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

void TTecShot::vfunc_6() {  }
struct TechniqueParticleEmitter;
void TTecCircle::apply_technique_to_area_targets() {
    List_8022BD74 *list;
    s32 i;
    u32 id;
    if (((Tec_8022BD74 *)this)->fe8 == 0) {
        ((TObject *)((TechniqueParticleEmitter *)((Tec_8022BD74 *)this)))->queue_destruction();
        return;
    }
    if (((TObjBase *)(((Tec_8022BD74 *)this)->owner))->get_entity_id() < 4) {
        if (get_type__10TObjPlayerFPv((u8 *)((Tec_8022BD74 *)this)->owner + 0x828) != 0) {
            list = (List_8022BD74 *)collect_body_contacts_for_target((saddr)((Tec_8022BD74 *)this)->owner);
        } else {
            list = find_area_contact__10TTecCircleFl(((Tec_8022BD74 *)this), ((Tec_8022BD74 *)this)->owner);
        }
    } else {
        list = (List_8022BD74 *)collect_body_contacts_for_target((saddr)((Tec_8022BD74 *)this)->owner);
    }
    for (i = 0; i < list->count; i++) {
        if (TObjPlayer::is_valid_and_active(list->ids[i]) != 0) {
            id = list->ids[i];
            ((Tec_8022BD74 *)this)->fb8 = list->vals[i];
            ((VObj_8022BD74 *)((Tec_8022BD74 *)this))->m4(id);
        }
    }
}
