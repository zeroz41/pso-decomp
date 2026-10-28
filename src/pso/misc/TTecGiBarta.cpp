#include "types.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/misc/TParticleCtrl_800867E4.h"
#include "pso/misc/TTecGiZonde_8023A4CC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_800871A0.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/effect/TUnk_804CCC68.h"
#include "pso/misc/TTecGiBarta.h"
#include "pso/misc/TTecAnti.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802308A0_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_802308A0_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
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

struct TTecGiBartaData_80230B48 { u8 pad[4]; u32 count; };

struct TTecGiBarta_80230B48 {
    u8 pad0[0x18];
    void *vtable;
    u8 pad1c[0xC6 - 0x1C];
    s16 band;
    u8 padc8[0x130 - 0xC8];
    void **emitters;
};

struct TTecGiBarta_80230C58 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vtable;
    void *owner;
    u8 pad20[0xC8 - 0x20];
    s16 fc8;
    u8 padca[0x12C - 0xCA];
    f32 f12c;
    u8 pad130[4];
    u16 slots[32];
    s32 f174;
};

struct Vec_802304A0 { f32 x, y, z; };
struct Row_802304A0 { u32 entry; u32 flags; f32 scale; };
struct Band_802304A0 { Row_802304A0 *rows; u32 count; };
struct Angles_802304A0 { s32 a[3]; };
struct Shot_802304A0 {
    u8 pad0[0x20];
    Vec_802304A0 pos;
    u8 pad2C[0x54 - 0x2C];
    s32 f54;
    s32 f58;
    s32 f5C;
    u8 pad60[0xC6 - 0x60];
    s16 band;
    u16 source;
    u8 padCA[0x130 - 0xCA];
    void **emitters;
};

struct Obj_80230CFC {
    u8 pad0[0x134];
    u16 ids[32];
};

extern "C" {
void *get_bml_motion(void *, u32);
void *get_bml_model(void *, u32);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
void *mem_alloc(u32 size);
void matrix_mult_vec(s32, void *, void *);
void rotate_matrix_y(s32, s32);
extern Vec_802304A0 lbl_8044D288;
extern u8 identity_matrix[];
extern void *technique_effect_bml;
extern void *lbl_805D63B0;
extern const f32 lbl_805DC800;
extern const f32 lbl_805DC804;
extern const f32 lbl_805DC808;

s32 calc_technique_parameters(int, int, int);
s32 is_technique_ready__8TTecCtrlFv();
extern RecoveredGlobal_802308A0_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_802308A0_lbl_804CC55C lbl_804CC55C;
u16 get_entity_id(void *);
void mem_free(void *p);
void __dl__7TObjectFPv(void *);
extern void *__vt__11TTecGiBarta[];
TTecGiBarta_80230B48 *__dt__11TTecGiBartaFv(TTecGiBarta_80230B48 *self, s16 deleting);
void __ct__13TUnk_804CCC68FlPUcPUcl();
extern s32 tec_gibarta_class_name_ptr;
extern const f32 lbl_805DC80C;
TTecGiBarta_80230C58 *TTecGiBarta__ct(TTecGiBarta_80230C58 *self, void * _w1, void * _w2, void * _w3, void * _w4);
void construct_facing_technique__10TObjPlayerFPviPvii();
s32 play_sound_effect(s32, s32, s32, s32);
void *find_entity_by_id(u16 id);
void *__nw__7TObjectFUl(int);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);

void TTecGiBarta::update_technique_by_phase() {
    u8 *arg0 = (u8 *)this;
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A605, (int)(arg0 + 0x20), 0, 0);
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A605, (int)(arg0 + 0x20), 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A605, (int)(arg0 + 0x20), 0, 0);
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A605, (int)(arg0 + 0x20), 0, 0);
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A605, (int)(arg0 + 0x20), 0, 0);
        if (handle >= 0) {
            update_technique_slot__10TTecRaFoieFl(handle, -0x100, 0);
        }
        break;
    }
}

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
}
struct Raw_802304A0 { u8 b[12]; };

void TTecGiBarta::create_particles() {
    extern Band_802304A0 TTecGiBarta__emitter_profile_table[];
    Shot_802304A0 *shot = (Shot_802304A0 *)this;
    Angles_802304A0 angles;
    Vec_802304A0 pos;
    Vec_802304A0 off;
    Vec_802304A0 p2;
    Vec_802304A0 v;
    u32 i;
    void *emitter;
    u8 *src;
    u32 flags;

    angles.a[0] = shot->f54;
    angles.a[1] = 0;
    angles.a[2] = shot->f5C;
    shot->emitters = (void **)mem_alloc(TTecGiBarta__emitter_profile_table[shot->band].count * 4);
    for (i = 0; i < TTecGiBarta__emitter_profile_table[shot->band].count; i++) {
        *(Raw_802304A0 *)&pos = *(Raw_802304A0 *)&shot->pos;
        if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 0x800) {
            pos.y -= lbl_805DC800;
        }
        if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 2) {
            emitter = spawn_continuous_particle_with_direction(&pos, &angles, TTecGiBarta__emitter_profile_table[shot->band].rows[i].entry);
        } else {
            *(Raw_802304A0 *)&off = *(Raw_802304A0 *)&lbl_8044D288;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, shot->f58);
            matrix_mult_vec(0, &off, &off);
            pop_matrices(1);
            p2.x = shot->pos.x + off.x;
            p2.y = shot->pos.y + off.y;
            p2.z = shot->pos.z + off.z;
            if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 0x800) {
                p2.y -= lbl_805DC800;
            }
            emitter = create_particle_emitter(&p2, TTecGiBarta__emitter_profile_table[shot->band].rows[i].entry);
        }
        if (emitter != NULL) {
            if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 0x40) {
                ((TObjPlayer *)emitter)->set_position_xy(TTecGiBarta__emitter_profile_table[shot->band].rows[i].scale, TTecGiBarta__emitter_profile_table[shot->band].rows[i].scale);
            }
            if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 0x20) {
                attach_particle_model((u8 *)emitter, (s32)(get_bml_model(technique_effect_bml, (u16)(TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags >> 16))), (s32)lbl_805D63B0, (s32)NULL, 0, (f32)lbl_805DC804);
            }
        }
        shot->emitters[i] = emitter;
    }
    if (shot->band == 5) {
        VecCopy((Vec *)&v, (const Vec *)&shot->pos);
        v.y -= lbl_805DC808;
        spawn_particle_effect(&v, 0x1E0);
        spawn_particle_effect(&v, 0x1E1);
        src = (u8 *)find_entity_by_id(shot->source);
        if (src != NULL) {
            emitter = spawn_particle_effect(src + 0x38, 0x18B);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, (s32)(get_bml_model(technique_effect_bml, 6)), (s32)lbl_805D63B0, (s32)(get_bml_motion(technique_effect_bml, 2)), 0, (f32)lbl_805DC804);
            }
            emitter = create_timed_particle_emitter(src + 0x38, 0x18B, 5, 1);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, (s32)(get_bml_model(technique_effect_bml, 7)), (s32)lbl_805D63B0, (s32)(get_bml_motion(technique_effect_bml, 2)), 0, (f32)lbl_805DC804);
            }
            emitter = create_timed_particle_emitter(src + 0x38, 0x18B, 10, 1);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, (s32)(get_bml_model(technique_effect_bml, 8)), (s32)lbl_805D63B0, (s32)(get_bml_motion(technique_effect_bml, 2)), 0, (f32)lbl_805DC804);
            }
            emitter = create_timed_particle_emitter(src + 0x38, 0x18F, 20, 1);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, (s32)(get_bml_model(technique_effect_bml, 5)), (s32)lbl_805D63B0, (s32)NULL, 0, (f32)lbl_805DC804);
            }
        }
    }
}
#pragma auto_inline off

typedef struct RecoveredFields_802308A0_arg0 RecoveredFields_802308A0_arg0;
typedef struct RecoveredGlobal_802308A0_lbl_804CC510 RecoveredGlobal_802308A0_lbl_804CC510;
typedef struct RecoveredGlobal_802308A0_lbl_804CC55C RecoveredGlobal_802308A0_lbl_804CC55C;
typedef char RecoveredGlobal_802308A0_lbl_804CC510_size[((sizeof(RecoveredGlobal_802308A0_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_802308A0_lbl_804CC55C_size[((sizeof(RecoveredGlobal_802308A0_lbl_804CC55C)) == 0x98) ? (1) : (-1)];
void TTecGiBarta::calc_params() {
    u8 *arg0 = (u8 *)this;
  s32 new_var;
  new_var = calc_technique_parameters(4, (int) ((RecoveredFields_802308A0_arg0 *) arg0)->field_C4, 0xFFFF);
  ((TTecAnti *)(arg0 + 0xCC))->copy_params((u8 *)new_var);
  if ((((s16) ((RecoveredFields_802308A0_arg0 *) arg0)->field_C4) >= 0xF) && (is_technique_ready__8TTecCtrlFv() == 0))
  {
    ((RecoveredFields_802308A0_arg0 *) arg0)->field_CC = (f32) ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x10))) + ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x12))) * ((RecoveredFields_802308A0_arg0 *) arg0)->field_C4));
  }
  else
  {
    ((RecoveredFields_802308A0_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_802308A0_arg0 *) arg0)->field_CC + ((f32) (((RecoveredFields_802308A0_arg0 *) arg0)->field_F0 * ((RecoveredFields_802308A0_arg0 *) arg0)->field_C4)));
    if (is_technique_ready__8TTecCtrlFv() != 0)
    {
      ((RecoveredFields_802308A0_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_802308A0_arg0 *) arg0)->field_CC * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x20))));
    }
  }
  ((RecoveredFields_802308A0_arg0 *) arg0)->field_70 = (f32) ((RecoveredFields_802308A0_arg0 *) arg0)->field_D4;
}

void TTecGiBarta::vfunc_8(void *target) {
    Obj_802309AC *self = (Obj_802309AC *)this;
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (self->ids[i] == get_entity_id(((VObj_802309AC *)target))) {
            found = 1;
        }
    }
    if (found == 0) {
        self->ids[*(s32 *)&this->m_174] = get_entity_id(((VObj_802309AC *)target));
        *(s32 *)&this->m_174 += 1;
        if (*(s32 *)&this->m_174 >= 32) {
            *(s32 *)&this->m_174 = 31;
        }
        HitInfo_802309AC tmp;
        tmp.type = 2;
        tmp.power = this->power;
        HitInfo_802309AC info = tmp;
        ((VObj_802309AC *)target)->m21(self->source, &info, *(void * *)&this->contact, 4, -1);
    }
}

void TTecGiBarta::create(void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x178);
    if (o != NULL) {
        TTecGiBarta__ct((TTecGiBarta_80230C58 *)(o), this, arg1, arg2, arg3);
    }
}

void TTecGiBarta::create_ex(void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x178);
    if (o != NULL) {
        ((TTecGiBarta *)o)->construct_facing(this, arg1, arg2, arg3);
    }
}

TTecGiBarta_80230B48 *__dt__11TTecGiBartaFv(TTecGiBarta_80230B48 *self, s16 deleting) {
    extern TTecGiBartaData_80230B48 TTecGiBarta__emitter_profile_table[];
    if (self) {
        self->vtable = __vt__11TTecGiBarta;
        for (u32 i = 0; i < TTecGiBarta__emitter_profile_table[self->band].count; ++i) {
            if (self->emitters[i]) {
                queue_destruction__7TObjectFv(self->emitters[i]);
            }
        }
        mem_free(self->emitters);
        ((TObjPlayer *)self)->destroy_technique_effect_resources(0);
        if (deleting > 0) __dl__7TObjectFPv(self);
    }
    return self;
}

void TTecGiBarta::run_task() {
    this->source = (u32)find_entity_by_id(this->sourceId);
    if ((u32) this->source == 0U) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    move_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_all_technique_contacts();
}

TTecGiBarta_80230C58 *TTecGiBarta__ct(TTecGiBarta_80230C58 *self, void * _w1, void * _w2, void * _w3, void * _w4) {
    s32 i;
    __ct__13TUnk_804CCC68FlPUcPUcl();
    self->vtable = __vt__11TTecGiBarta;
    self->f0 = tec_gibarta_class_name_ptr;
    ((TTecGiBarta *)self)->calc_params();
    self->f12c = lbl_805DC80C;
    for (i = 0; i < 32; i++) {
        self->slots[i] = 0xFFFF;
    }
    self->f174 = 0;
    if (self->owner) {
        self->fc8 = ((s16)get_entity_id(self->owner));
    }
    ((TTecGiBarta *)self)->create_particles();
    ((TTecGiBarta *)self)->update_technique_by_phase();
    return self;
}

u8 *TTecGiBarta::construct_facing(void * _w1, void * _w2, void * _w3, void * _w4) {
    u8 *arg0 = (u8 *)this;
    s32 i;
    construct_facing_technique__10TObjPlayerFPviPvii();
    (*(void * *)((u8 *)this + 0x18)) = __vt__11TTecGiBarta;
    *(s32 *)&this->m_name = tec_gibarta_class_name_ptr;
    calc_params();
    for (i = 0; i < 0x20; i++) {
        ((Obj_80230CFC *)arg0)->ids[i] = 0xFFFF;
    }
    this->m_174 = 0;
    if (this->source != 0) {
        *(s16 *)&this->sourceId = get_entity_id(*(void * *)&this->source);
    }
    create_particles();
    update_technique_by_phase();
    return arg0;
}

void TTecGiBarta::render() {  }
