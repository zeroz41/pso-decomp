#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
extern "C" void *__dt__13TUnk_804CC148Fv(void *, s16);
#include "pso/system/vector.h"
#include "pso/effect/TUnk_804CC148.h"

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {

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

typedef struct RecoveredFields_80230D9C_arg0 RecoveredFields_80230D9C_arg0;

typedef struct RecoveredGlobal_80230D9C_lbl_804CC510 RecoveredGlobal_80230D9C_lbl_804CC510;

typedef struct RecoveredGlobal_80230D9C_lbl_804CC55C RecoveredGlobal_80230D9C_lbl_804CC55C;

typedef char RecoveredGlobal_80230D9C_lbl_804CC510_size[((sizeof(RecoveredGlobal_80230D9C_lbl_804CC510)) == 0x4C) ? (1) : (-1)];

typedef char RecoveredGlobal_80230D9C_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80230D9C_lbl_804CC55C)) == 0x98) ? (1) : (-1)];

struct Task_80231224 {
    u8 pad0[0x18];
    void **vt;
    void **emitters;
    u8 pad1[0x44 - 0x20];
    u8 band;
    u8 pad2[2];
    u8 single;
};

struct Profile_80231224 { u32 a; u32 count; };

struct RecoveredGlobal_80231638___vt__10TTecGiFoie
{
  s32 value;
  u8 remaining[0x24];
};

struct HitInfo_8023154C { s32 type; f32 power; };

struct VBase_8023154C { char pad[0x18]; };

struct VObj_8023154C : VBase_8023154C {
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
    virtual void m21(void *, HitInfo_8023154C *, void *, s32, s32);
};

struct Obj_8023154C {
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

struct Vec_802312E4 { f32 x, y, z; };

struct Rot_802312E4 { s32 x, y, z; };

struct Part_802312E4 { s32 id; u32 flags; u8 pad8[4]; };

struct Profile_802312E4 { Part_802312E4 *parts; u32 count; };

struct Task_802312E4 {
    u8 pad0[0x18];
    void **vt;
    u32 *emitters;
    Vec_802312E4 pos;
    Vec_802312E4 pos2;
    f32 x38;
    s32 x3c;
    s32 x40;
    u8 band;
    s8 x45;
    u8 x46;
    u8 single;
};

typedef struct RecoveredGlobal_80231638___vt__10TTecGiFoie RecoveredGlobal_80231638___vt__10TTecGiFoie;

typedef char RecoveredGlobal_80231638___vt__10TTecGiFoie_size[((sizeof(RecoveredGlobal_80231638___vt__10TTecGiFoie)) == 0x28) ? (1) : (-1)];

struct Vec_8023179C { f32 x, y, z; };

struct Task_8023179C;

struct GiFoie_8023179C {
    u32 x0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    void *source;
    Vec_8023179C pos;
    u8 pad2c[0x78 - 0x2C];
    s16 level;
    s16 band;
    u8 pad7c[0x90 - 0x7C];
    f32 radius;
    u8 pad94[0xB4 - 0x94];
    u16 fb4;
    u8 padb6[0xE8 - 0xB6];
    u8 *effect;
    Task_8023179C *tasks[3];
    u16 ids[32];
    s32 cursor;
};

struct Task_802312E4;

struct Vec_802312E4;

void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
void *spawn_continuous_particle_with_direction(void *pos, void *dir, s32 id);
void mem_free(void *);
void *mem_alloc(u32 size);
void * find_entity_by_id(u16);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __dt__7TObjectFv(void *, int);
void __ct__7TObjectFP7TObject(void *, void *);
void construct_area_technique_base(void *, void *, void *, void *, void *);
s32 calc_technique_parameters(int, int, int);
u8 * __dt__13TUnk_804CC800Fv(Task_80231224 *task, s16 flag);
Task_802312E4 * construct_orbit__10TTecGiFoieFPvPviUciPvUc(Task_802312E4 *self, Vec_802312E4 *pos, s32 arg2, u8 band, s32 arg4, void *parent, u8 single);
u8 * __dt__10TTecGiFoieFv(u8 *arg0, s16 arg1);
void run_task__10TTecGiFoieFv(u8 *self);
void * TTecGiFoie__ct(void *self_, void *source, void *origin, void *level);
void matrix_mult_vec(void *, void *, void *);

extern const f32 TTecGiFoie__data_805DC81C;
extern RecoveredGlobal_80231638___vt__10TTecGiFoie __vt__10TTecGiFoie;
extern Profile_802312E4 TTecGiFoie__emitter_profile_table[];
extern u8 lbl_8044D324[];
extern Vec_8023179C lbl_8044D32C;
extern RecoveredGlobal_80230D9C_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_80230D9C_lbl_804CC55C lbl_804CC55C;
extern void *lbl_804CC800[];
extern const f32 lbl_8044D338[3];
extern const Vec lbl_8044D344;
extern u32 TTecGiFoie__name;
extern const f32 lbl_805DC810;
extern const f32 lbl_805DC818;
extern const f32 lbl_805DC820;
extern const f32 lbl_805DC824;
extern s32 tl_07;

void TTecGiFoie::calc_params() {
    u8 *arg0 = (u8 *)this;
  int new_var;
 new_var = (int) calc_technique_parameters(1, (int) ((RecoveredFields_80230D9C_arg0 *) arg0)->field_78, 0xFFFF); do { ((TTecAnti *)(arg0 + ((0, 0x88))))->copy_params((u8 *)new_var); if ((((s16) ((RecoveredFields_80230D9C_arg0 *) arg0)->field_78) >= 0xF) && (TTecCtrl::is_technique_ready() == 0)) { ((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 = (f32) ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 4))) + ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 6))) * ((RecoveredFields_80230D9C_arg0 *) arg0)->field_78)); return; } } while (0);
  ((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 = (f32) (((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 + ((f32) (((RecoveredFields_80230D9C_arg0 *) arg0)->field_AC * ((RecoveredFields_80230D9C_arg0 *) arg0)->field_78)));
  if (TTecCtrl::is_technique_ready())
  {
    ((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 = (f32) (((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 8))));
  }
}

void TUnk_804CC800::run_task() {
    s32 rot[3];
    s32 bob;
    switch (pad_44) {
    case 0:
        bob = 0;
        break;
    case 1:
        bob = 1;
        break;
    case 2:
        bob = 2;
        break;
    case 3:
        bob = 0;
        break;
    case 4:
        bob = 1;
        break;
    case 5:
        bob = 2;
        break;
    default:
        bob = 0;
        break;
    }
    pad_40++;
    if (pad_46) {
        Vec offset;
        pad_38 += 0.015;
        pad_3C += 0x1C71;
        offset.x = pad_38 * cos_table_lookup(pad_3C);
        offset.z = pad_38 * sin_table_lookup(pad_3C);
        offset.y = 0.0f;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, pad_48);
        rotate_matrix_x(0, 0x4000);
        rotate_vector_by_matrix(0, &offset, &offset);
        pop_matrix();
        pad_2C.x = pad_20.x + offset.x;
        pad_2C.y = pad_20.y + offset.y;
        pad_2C.z = pad_20.z + offset.z;
    } else {
        pad_38 += 0.55f;
        pad_3C += (s32)(182.04445f * (f32)(pad_44 + 9));
        pad_2C.y = lbl_8044D338[bob] * sin_table_lookup((s32)(182.04445f * (f32)(pad_40 * 15))) + pad_20.y;
        pad_2C.x = pad_38 * cos_table_lookup(pad_3C) + pad_20.x;
        pad_2C.z = pad_38 * sin_table_lookup(pad_3C) + pad_20.z;
    }
    if (pad_47) {
        Vec dir = lbl_8044D344;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, pad_48);
        rotate_vector_by_matrix(0, &dir, &dir);
        pop_matrix();
        rot[0] = 0;
        rot[1] = 0;
        rot[2] = 0;
        direction_to_rotation_xz((u8 *)&dir, &rot[0], &rot[2]);
        pad_1C[0]->set_position(&pad_2C);
        pad_1C[0]->set_direction(rot);
    } else {
        u32 i = 0;
        rot[1] = (s32)(10430.38043493439 * atan2_float(pad_2C.x - pad_20.x, pad_2C.z - pad_20.z));
        rot[0] = rot[1] - 0x8000;
        rot[1] = 0;
        rot[2] = 0x4000;
        for (; i < TTecGiFoie__emitter_profile_table[pad_44].count; i++) {
            pad_1C[i]->set_position(&pad_2C);
            pad_1C[i]->set_direction(rot);
        }
    }
}

u8 *__dt__13TUnk_804CC800Fv(Task_80231224 *task, s16 flag) {
    u32 i;
    if (task != NULL) {
        task->vt = lbl_804CC800;
        if (task->single != 0) {
            ((TObject *)task->emitters[0])->queue_destruction();
        } else {
            for (i = 0; i < ((Profile_80231224 *)&TTecGiFoie__emitter_profile_table)[task->band].count; i++) {
                ((TObject *)task->emitters[i])->queue_destruction();
            }
        }
        mem_free(task->emitters);
        __dt__7TObjectFv(task, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(task);
        }
    }
    return (u8 *)task;
}

Task_802312E4 *construct_orbit__10TTecGiFoieFPvPviUciPvUc(Task_802312E4 *self, Vec_802312E4 *pos, s32 arg2, u8 band, s32 arg4, void *parent, u8 single) {
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = lbl_804CC800;
    self->x46 = 0;
    self->pos.x = pos->x;
    self->pos.y = pos->y;
    self->pos.z = pos->z;
    self->band = band;
    self->x45 = arg4;
    VecCopy((Vec *)&self->pos2, (const Vec *)&self->pos);
    self->x3c = arg2;
    self->x38 = lbl_805DC810;
    self->x40 = 0;
    self->single = single;
    if (self->single != 0) {
        Rot_802312E4 r;
        self->emitters = (u32 *)mem_alloc(4);
        r.x = 0;
        r.y = 0;
        r.z = 0x4000;
        self->emitters[0] = (u32)spawn_continuous_particle_with_direction(&self->pos, &r, 0x19D);
        self->x38 = TTecGiFoie__data_805DC81C;
    } else {
        s32 i;
        self->emitters = (u32 *)mem_alloc(TTecGiFoie__emitter_profile_table[self->band].count * 4);
        for (i = 0; i < TTecGiFoie__emitter_profile_table[self->band].count; i++) {
            Rot_802312E4 r;
            Part_802312E4 *p;
            r.x = 0;
            r.y = 0;
            r.z = 0x4000;
            p = &TTecGiFoie__emitter_profile_table[self->band].parts[i];
            self->emitters[i] = (u32)spawn_particle_effect_with_rotation(&self->pos, &r, p->id, (p->flags & 0x1000) ? 0x2000 : 0);
            if (self->band == 2) {
                if (arg4 >= 0xF && arg4 < 0x19) {
                    if (i <= 1 && self->emitters[i] != 0) {
                        ((TParticleCtrl *)(self->emitters[i]))->set_scale(lbl_805DC820, lbl_805DC820);
                    }
                } else if (arg4 >= 0x19 && arg4 < 0x1E) {
                    if (i <= 1 && self->emitters[i] != 0) {
                        ((TParticleCtrl *)(self->emitters[i]))->set_scale(lbl_805DC820, lbl_805DC824);
                    }
                }
            }
        }
    }
    return self;
}

void TTecGiFoie::create(void *arg0, void *origin, void *level) {
    void *o;
    o = __nw__7TObjectFUl(0x13C);
    if (o != NULL) {
        TTecGiFoie__ct(o, arg0, origin, level);
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TTecGiFoie::vfunc_6(void *target) {
    Obj_8023154C *self = (Obj_8023154C *)this;
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (self->ids[i] == get_entity_id((TObjBase *)target)) {
            found = 1;
        }
    }
    if (found == 0) {
        self->ids[*(s32 *)&this->m_138] = get_entity_id((TObjBase *)target);
        *(s32 *)&this->m_138 += 1;
        if (*(s32 *)&this->m_138 >= 32) {
            *(s32 *)&this->m_138 = 31;
        }
        HitInfo_8023154C tmp;
        tmp.type = 1;
        tmp.power = this->m_88;
        HitInfo_8023154C info = tmp;
        ((VObj_8023154C *)target)->m21(self->source, &info, self->contact, 1, -1);
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
u8 *__dt__10TTecGiFoieFv(u8 *arg0, s16 arg1) {
  s32 temp_r30;
  s32 var_r29;
  s32 var_r31;
  if (arg0 != 0)
  {
    var_r31 = 0;
    var_r29 = var_r31;
    var_r31 = 0;
    *((s32 **) (((s8 *) arg0) + 0x18)) = &__vt__10TTecGiFoie.value;
    do
    {
      temp_r30 = var_r31 + 0xEC;
      if (TTecLuker::is_parents_unqueued(*((s32 *) (((s8 *) arg0) + temp_r30))) != 0)
      {
        ((TObject *)((void *)(*((s32 *) (((s8 *) arg0) + temp_r30)))))->queue_destruction();
      }
      var_r29 += 1;
      var_r31 += 4;
    }
    while (var_r29 < 3);
    __dt__13TUnk_804CC148Fv((void *)((TUnk_804CC148 *)arg0), 0);
    if (arg1 > 0)
    {
      ((s32 (*)(void *))__dl__7TObjectFPv)((void *) arg0);
    }
  }
  return arg0;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void run_task__10TTecGiFoieFv(u8 *self) {
    f32 distance;
    if (*(void **)((s8 *)self + 0xE8) == NULL) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    *(void **)((s8 *)self + 0x1C) = find_entity_by_id(((TTecGiFoie *)self)->m_b4);
    if (*(void **)((s8 *)self + 0x1C) == NULL) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (TTecLuker::is_parents_unqueued(((TTecGiFoie *)self)->m_ec) != 0) {
        distance = newton_sqrtf(horizontal_distance_squared((Vec *)(*(u8 **)((s8 *)self + 0xEC) + 0x2C), (Vec *)(self + 0x20)));
        if (*(u8 **)((s8 *)self + 0xE8) != NULL) {
            *(f32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)self + 0xE8)) + 0xA4)) + 0xC) = TTecGiFoie__data_805DC81C + distance;
        }
        ((TUnk_804CC148 *)self)->apply_technique_to_area_targets();
        if (distance >= ((TTecGiFoie *)self)->m_90) {
            ((TObject *)self)->queue_destruction();
        }
    }
}
#pragma pop

void *TTecGiFoie__ct(void *self_, void *source, void *origin, void *level) {
#define self ((GiFoie_8023179C *)self_)
    s32 i;
    s32 j;
    s32 k;
    s32 r;
    construct_area_technique_base(self_, source, origin, origin, level);
    self->vt = &__vt__10TTecGiFoie.value;
    self->x0 = TTecGiFoie__name;
    ((TTecGiFoie *)self_)->calc_params();
    if (self->effect != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)self->effect + 0xA4)) + 0xC) = TTecGiFoie__data_805DC81C + self->radius;
    }
    for (i = 0; i < 32; i++) {
        self->ids[i] = 0xFFFF;
    }
    for (j = 0; j < 3; j++) {
        self->tasks[j] = 0;
    }
    self->cursor = 0;
    for (k = 0; k < lbl_8044D324[self->band]; k++) {
        Vec_8023179C v = lbl_8044D32C;
        Vec_8023179C p;
        s32 angle;
        s32 step;
        void *o;
        step = (s32)(lbl_805DC818 * (f32)(360 / lbl_8044D324[self->band]));
        angle = step * k + 0x4000;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        matrix_mult_vec(0, &v, &v);
        pop_matrices(1);
        p.x = self->pos.x + v.x;
        p.y = self->pos.y + v.y;
        p.z = self->pos.z + v.z;
        o = __nw__7TObjectFUl(0x4C);
        if (o != NULL) {
            o = ((Task_8023179C *(*)(void *, Vec_8023179C *, s32, s32, s32, void *, u8))construct_orbit__10TTecGiFoieFPvPviUciPvUc)(o, &p, angle, self->band, self->level, (void *)tl_07, 0);
        }
        self->tasks[k] = (Task_8023179C *)o;
    }
    switch (self->band) {
    case 0:
        r = play_sound_effect(0x4002A801, (u8 *)self_ + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, 0x100, 0);
        }
        break;
    case 1:
        play_sound_effect(0x4002A801, (u8 *)self_ + 0x20, 0, 0);
        break;
    case 2:
    case 3:
        r = play_sound_effect(0x4002A801, (u8 *)self_ + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, -0x180, 0);
        }
        break;
    case 4:
        r = play_sound_effect(0x4002A801, (u8 *)self_ + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, -0x250, 0);
        }
        break;
    case 5:
        r = play_sound_effect(0x4002A801, (u8 *)self_ + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, -0x100, 0);
        }
        break;
    default:
        play_sound_effect(0x4002A801, (u8 *)self_ + 0x20, 0, 0);
        break;
    }
    if (self->source != NULL) {
        self->fb4 = get_entity_id((TObjBase *)self->source);
    }
    return self_;
#undef self
}

void TTecGiFoie::render() {  }

}
