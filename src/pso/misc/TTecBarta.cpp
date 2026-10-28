#include "types.h"
#include "pso/misc/TTecBarta.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/effect/TUnk_804CCC68.h"

struct RecoveredGlobal_8022B6FC_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_8022B6FC_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
};

#include "pso/misc/TNowLoading.h"
#include "pso/misc/TTecAnti.h"
#include "pso/player/TObjPlayer.h"

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

struct TTecBarta_8022BC10 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vtable;
    void *owner;
    u8 pad20[0xC8 - 0x20];
    s16 fc8;
    u8 padca[0x114 - 0xCA];
    u32 f114;
    u8 pad118[0x134 - 0x118];
    u16 slots[32];
    s32 f174;
};

struct Obj_8022BCB8 {
    u8 pad0[0x18];
    void *vt;
    void *source;
    u8 pad20[0x134 - 0x20];
    u16 ids[32];
};

struct Vec_8022BA98 { f32 x; f32 y; f32 z; };

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
s32 calc_technique_parameters(int, int, int);
s32 is_technique_ready__8TTecCtrlFv();
extern RecoveredGlobal_8022B6FC_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_8022B6FC_lbl_804CC55C lbl_804CC55C;
extern TechniqueContactVtable __vt__9TTecBarta;
extern TechniqueEmitterSourceTable TTecBarta__emitter_bands[];
void queue_destruction__7TObjectFv(void *arg0);
void mem_free(void *p);
void __dl__7TObjectFPv(TTecBarta*);
TTecBarta* __dt__9TTecBartaFv(TTecBarta* self,s16 deleting);
u16 get_entity_id(void *);
void __ct__13TUnk_804CCC68FlPUcPUcl();
extern s32 tec_barta_class_name_ptr;
TTecBarta_8022BC10 *TTecBarta__ct(TTecBarta_8022BC10 *self, void * _w1, void * _w2, void * _w3, void * _w4);
void construct_facing_technique__10TObjPlayerFPviPvii();
s32 get_bml_model(s32, s32);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void *find_entity_by_id(u16 id);
}
extern const f32 lbl_805DC7A8;
u8 *construct_tec_barta_facing(TTecBarta *arg0, void *_w1, void *_w2, void *_w3, void *_w4);
void move_ground_technique_projectile(void *p);
extern s32 technique_effect_bml;
extern s32 lbl_805D63B0;
extern const f32 lbl_805DC7A0;
extern const f32 lbl_805DC7A4;
extern "C" {
s32 get_bml_motion(s32, s32);
void *spawn_continuous_particle_with_direction(void *pos, void *dir, s32 id);
void *create_particle_emitter(void *pos, s32 id);
void *mem_alloc(u32 size);
s32 get_type__10TObjPlayerFPv(void *);
List_8022BD74 *find_area_contact__13TUnk_804CC148Fl(Tec_8022BD74 *, void *);
List_8022BD74 *collect_body_contacts_for_target__10TObjPlayerFl(Tec_8022BD74 *, void *);
s32 play_sound_effect(s32, s32, s32, s32);
void *__nw__7TObjectFUl(int);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);

void TTecBarta::update_technique_by_state() {
    u8 *arg0 = (u8 *)this;
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A604, (int)(arg0 + 0x20), 0, 0);
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A604, (int)(arg0 + 0x20), 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A604, (int)(arg0 + 0x20), 0, 0);
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A604, (int)(arg0 + 0x20), 0, 0);
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A604, (int)(arg0 + 0x20), 0, 0);
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x100, 0);
        }
        break;
    }
}

typedef struct RecoveredGlobal_8022B6FC_lbl_804CC510 RecoveredGlobal_8022B6FC_lbl_804CC510;
typedef struct RecoveredGlobal_8022B6FC_lbl_804CC55C RecoveredGlobal_8022B6FC_lbl_804CC55C;
typedef char RecoveredGlobal_8022B6FC_lbl_804CC510_size[((sizeof(RecoveredGlobal_8022B6FC_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_8022B6FC_lbl_804CC55C_size[((sizeof(RecoveredGlobal_8022B6FC_lbl_804CC55C)) == 0x98) ? (1) : (-1)];

void TTecBarta::create_particle_emitters() {
#define self ((TTecBarta *)this)
    s32 angles[3];
    s32 reverse[3];
    u32 i;
    TechniqueEmitterSourceRow *row;
    u32 flags;
    s32 base = (s32)this;
    angles[0] = self->angles[0];
    angles[1] = 0;
    angles[2] = self->angles[2];
    self->emitters = (TechniqueParticleEmitter **)mem_alloc(TTecBarta__emitter_bands[self->band].count * 4);
    for (i = 0; i < TTecBarta__emitter_bands[self->band].count; i++) {
        row = &TTecBarta__emitter_bands[self->band].rows[i];
        flags = row->flags;
        if (flags & 2) {
            self->emitters[i] = (TechniqueParticleEmitter *)spawn_continuous_particle_with_direction((f32 *)(base + 0x20), angles, row->entry);
        } else if (flags & 1) {
            reverse[0] = self->angles[0] + 0x8000;
            reverse[1] = 0;
            reverse[2] = self->angles[2];
            self->emitters[i] = (TechniqueParticleEmitter *)spawn_continuous_particle_with_direction((f32 *)(base + 0x20), reverse, TTecBarta__emitter_bands[self->band].rows[i].entry);
        } else {
            self->emitters[i] = (TechniqueParticleEmitter *)create_particle_emitter((f32 *)(base + 0x20), row->entry);
        }
        if (self->emitters[i] != NULL) {
            row = &TTecBarta__emitter_bands[self->band].rows[i];
            if (row->flags & 0x20) {
                attach_particle_model((u8 *)self->emitters[i], (s32)(get_bml_model(technique_effect_bml, 0)), (s32)lbl_805D63B0, (s32)(get_bml_motion(technique_effect_bml, 0)), 0, (f32)lbl_805DC7A0);
            } else {
                ((TObjPlayer *)(self->emitters[i]))->set_position_xy(row->scale, row->scale);
            }
        }
    }
#undef self
}

void TTecBarta::init_parameters() {
    u8 *arg0 = (u8 *)this;
  int new_var;
  new_var = (int) calc_technique_parameters(3, this->level, 0xFFFF);
  ((TTecAnti *)(arg0 + 0xCC))->copy_params((u8 *)new_var);
  if (((this->level) >= 0xF) && (is_technique_ready__8TTecCtrlFv() == 0))
  {
    this->power = (f32) ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0xC))) + ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0xE))) * (this->level)));
  }
  else
  {
    this->power = (f32) ((this->power) + ((f32) ((*((s16 *) (((s8 *) arg0) + 0xF0))) * (this->level))));
    if (is_technique_ready__8TTecCtrlFv() != 0)
    {
      this->power = (f32) ((this->power) * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x18))));
    }
  }
  *((f32 *) (((s8 *) arg0) + 0x64)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0xD0))) + ((f32) (((this->level) / 5) * 2)));
  this->range = (f32) (*((f32 *) (((s8 *) arg0) + 0xD4)));
}

void TTecBarta::create(void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x178);
    if (o != NULL) {
        TTecBarta__ct((TTecBarta_8022BC10 *)(o), this, arg1, arg2, arg3);
    }
}

void TTecBarta::create_ex(void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x178);
    if (o != NULL) {
        construct_tec_barta_facing((TTecBarta *)((u8 *)o), (void *)this, (void *)((void *)arg1), (void *)((void *)arg2), (void *)((void *)arg3));
    }
}

void TTecBarta::vfunc_8(void *target) {
    Obj_8022B8F4 *self = (Obj_8022B8F4 *)this;
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (self->ids[i] == get_entity_id(((VObj_8022B8F4 *)target))) {
            found = 1;
        }
    }
    if (found == 0) {
        self->ids[this->hitCursor] = get_entity_id(((VObj_8022B8F4 *)target));
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

TTecBarta* __dt__9TTecBartaFv(TTecBarta* self,s16 deleting) {
    if(self) {
        *(void **)((u8 *)self + 0x18) = &__vt__9TTecBarta;
        for(u32 i=0;i<TTecBarta__emitter_bands[self->band].count;++i) {
            if(self->emitters[i]) {
                queue_destruction__7TObjectFv(self->emitters[i]);
                self->emitters[i]=0;
            }
        }
        mem_free(self->emitters);
        ((TObjPlayer *)self)->destroy_technique_effect_resources(0);
        if(deleting>0)__dl__7TObjectFPv(self);
    }
    return self;
}

void TTecBarta::run_task() {
    s32 i;
    this->source = (u32)find_entity_by_id(this->sourceId);
    if (this->source == NULL) {
        queue_destruction__7TObjectFv((TechniqueParticleEmitter *)this);
        return;
    }
    for (i = 0; i < TTecBarta__emitter_bands[this->band].count; i++) {
        Vec_8022BA98 pos = *(Vec_8022BA98 *)&this->position;
        if (TTecBarta__emitter_bands[this->band].rows[i].flags & 0x20) {
            pos.y -= lbl_805DC7A4;
        }
        if (this->emitters[i] != NULL) {
            ((TNowLoading *)(this->emitters[i]))->copy_pos(&pos);
        }
        if (this->band == 5 && i == 5 && this->emitters[i] != NULL) {
            ((TNowLoading *)(this->emitters[i]))->copy_pos(&pos);
        }
    }
    if (this->band == 5) {
        TechniqueParticleEmitter *e = (TechniqueParticleEmitter *)create_timed_particle_emitter(&this->position.x, 0x18A, 0x14, 1);
        if (e != NULL) {
            attach_particle_model((u8 *)e, (s32)(get_bml_model(technique_effect_bml, 5)), (s32)lbl_805D63B0, 0, 0, (f32)lbl_805DC7A0);
        }
    }
    move_ground_technique_projectile(this);
    advance_lifetime_or_destroy();
    dispatch_all_technique_contacts();
}

void TTecBarta::render() {  }

TTecBarta_8022BC10 *TTecBarta__ct(TTecBarta_8022BC10 *self, void * _w1, void * _w2, void * _w3, void * _w4) {
    s32 i;
    __ct__13TUnk_804CCC68FlPUcPUcl();
    self->vtable = ((void * *)&__vt__9TTecBarta);
    self->f0 = tec_barta_class_name_ptr;
    ((TTecBarta *)self)->init_parameters();
    self->f114 = 0x40003;
    for (i = 0; i < 32; i++) {
        self->slots[i] = 0xFFFF;
    }
    self->f174 = 0;
    ((TTecBarta *)self)->create_particle_emitters();
    ((TTecBarta *)self)->update_technique_by_state();
    if (self->owner) {
        self->fc8 = ((s16)get_entity_id(self->owner));
    }
    return self;
}
}

u8 *construct_tec_barta_facing(TTecBarta *tec_barta, void * _w1, void * _w2, void * _w3, void * _w4) {
    s32 i;
    construct_facing_technique__10TObjPlayerFPviPvii();
    *(void **)((s8 *)tec_barta + 0x18) = ((u8 *)&__vt__9TTecBarta);
    *(s32 *)((s8 *)tec_barta + 0) = tec_barta_class_name_ptr;
    tec_barta->init_parameters();
    for (i = 0; i < 0x20; i++) {
        ((Obj_8022BCB8 *)tec_barta)->ids[i] = 0xFFFF;
    }
    tec_barta->hitCursor = 0;
    *(s32 *)((s8 *)tec_barta + 0x114) = 0x40003;
    *(f32 *)((s8 *)tec_barta + 0x24) = *(f32 *)((s8 *)tec_barta + 0x24) + lbl_805DC7A8;
    tec_barta->create_particle_emitters();
    tec_barta->update_technique_by_state();
    if (*(void **)((s8 *)tec_barta + 0x1C) != 0) {
        tec_barta->sourceId = get_entity_id(*(void **)((s8 *)tec_barta + 0x1C));
    }
    return (u8 *)tec_barta;
}

void TUnk_804CCC68::vfunc_6() {  }
struct TechniqueParticleEmitter;
void TUnk_804CC148::apply_technique_to_area_targets() {
    List_8022BD74 *list;
    s32 i;
    u32 id;
    if (((Tec_8022BD74 *)this)->fe8 == 0) {
        queue_destruction__7TObjectFv((TechniqueParticleEmitter *)((Tec_8022BD74 *)this));
        return;
    }
    if (get_entity_id(((Tec_8022BD74 *)this)->owner) < 4) {
        if (get_type__10TObjPlayerFPv((u8 *)((Tec_8022BD74 *)this)->owner + 0x828) != 0) {
            list = collect_body_contacts_for_target__10TObjPlayerFl(((Tec_8022BD74 *)this), ((Tec_8022BD74 *)this)->owner);
        } else {
            list = find_area_contact__13TUnk_804CC148Fl(((Tec_8022BD74 *)this), ((Tec_8022BD74 *)this)->owner);
        }
    } else {
        list = collect_body_contacts_for_target__10TObjPlayerFl(((Tec_8022BD74 *)this), ((Tec_8022BD74 *)this)->owner);
    }
    for (i = 0; i < list->count; i++) {
        if (TObjPlayer::is_valid_and_active(list->ids[i]) != 0) {
            id = list->ids[i];
            ((Tec_8022BD74 *)this)->fb8 = list->vals[i];
            ((VObj_8022BD74 *)((Tec_8022BD74 *)this))->m4(id);
        }
    }
}
