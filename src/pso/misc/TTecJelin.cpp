#include "types.h"
#include "pso/misc/TTecJelin.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/effect/TUnk_804CC148.h"

#include <stddef.h>

#include "pso/misc/TTecAnti.h"
#include "pso/misc/TTecLuker.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802384E0_lbl_804CCB28 { s32 value; u8 remaining[0x14]; };

struct RecoveredGlobal_802385EC_lbl_804CCB28 { s32 value; u8 remaining[0x14]; };

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

struct Damage_802386F8 { s32 kind; f32 power; };

struct VBase_802386F8 { char pad[0x18]; };

struct VObj_802386F8 : VBase_802386F8 {
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
    virtual s32 m21(s32, Damage_802386F8, s32, s32, s32, void *);
};

struct Entry_802336F0 { u16 id; u8 pad[6]; };

struct Self_802336F0 {
    u8 pad0[0x1C];
    u32 target;
    u8 pad1[0xB4 - 0x20];
    u16 owner;
    u8 pad2[0xEC - 0xB6];
    s32 flag;
    s32 count;
    struct Entry_802336F0 entries[1];
};

struct Vec_80233958 { f32 x, y, z; };

struct Eff_80233958 { u8 pad[0xc]; f32 scale; };

struct Holder_80233958 { u8 pad[0xa4]; Eff_80233958 *eff; };

struct Jelin_80233958 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    void *source;
    Vec_80233958 pos;
    u8 pad2c[0x7a - 0x2c];
    s16 level;
    Vec_80233958 src_pos;
    u8 pad88[0x90 - 0x88];
    f32 range;
    u8 pad94[0xb4 - 0x94];
    s16 field_b4;
    u8 padb6[0xe8 - 0xb6];
    Holder_80233958 *holder;
    s32 fec;
    u8 sub[4];
};

struct Vec_80233958;
struct Vec_80233808 { f32 x, y, z; };

struct Eff_80233808 { u8 pad[0xc]; f32 scale; };

struct Holder_80233808 { u8 pad[0xa4]; Eff_80233808 *eff; };

struct Jelin_80233808 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    void *source;
    Vec_80233808 pos;
    u8 pad2c[0x7a - 0x2c];
    s16 level;
    u8 pad7c[0x90 - 0x7c];
    f32 range;
    u8 pad94[0xb4 - 0x94];
    s16 field_b4;
    u8 padb6[0xe8 - 0xb6];
    Holder_80233808 *holder;
    s32 fec;
    u8 sub[4];
};

extern "C" {
void *find_entity_by_id(u16 id);
void run_task__9TTecJelinFv(struct Self_802336F0 *self);
void construct_area_technique_base(void *);
extern s32 tec_jelin_class_name_ptr;
extern s32 __vt__9TTecJelin[];
s32 play_sound_effect(int, void *, int, int);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 get_entity_id(void *);
Jelin_80233958 *construct__9TTecJelinFPviiii(Jelin_80233958 *self, s32 _w1, s32 _w2, s32 _w3, s32 _w4);
void copy_technique_target_list(void *, void *);
void __ct__13TUnk_804CC148Flll(void *, void *, void *, void *);
Jelin_80233808 *TTecJelin__ct(Jelin_80233808 *self, void *_w1, void *_w2, void *_w3, void *_w4);
s32 calc_technique_parameters(s32, s16, s32);
u32 __nw__7TObjectFUl(s32 a0 = 0);

void TTecJelin::init_tech_params() {
    u8 *arg0 = (u8 *)this;
    s32 res;
    res = calc_technique_parameters(0xB, this->m_78, 0xFFFF);
    ((TTecAnti *)(arg0 + 0x88))->copy_params((u8 *)res);
    this->m_88 = (f32) (*(s16 *)&this->m_ac * this->m_78);
}

typedef char RecoveredGlobal_802384E0_lbl_804CCB28_size[sizeof(RecoveredGlobal_802384E0_lbl_804CCB28) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_802385EC_lbl_804CCB28_size[sizeof(RecoveredGlobal_802385EC_lbl_804CCB28) == 0x18 ? 1 : -1];
void TTecJelin::vfunc_6(void *target_arg) {
    u8 *self = (u8 *)this;
    u8 *target = (u8 *)target_arg;
    Damage_802386F8 d;
    d.kind = 0xb;
    d.power = *(f32 *)(self + 0x88);
    ((VObj_802386F8 *)target)->m21(*(s32 *)(self + 0x1C), d, *(s32 *)(self + 0xB8), 0xb, -1, self);
}
typedef struct RecoveredFields_80238D10_arg0 RecoveredFields_80238D10_arg0;
typedef struct RecoveredGlobal_80238D10_lbl_804CC510 RecoveredGlobal_80238D10_lbl_804CC510;
typedef struct RecoveredGlobal_80238D10_lbl_804CC55C RecoveredGlobal_80238D10_lbl_804CC55C;
typedef char RecoveredGlobal_80238D10_lbl_804CC510_size[((sizeof(RecoveredGlobal_80238D10_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_80238D10_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80238D10_lbl_804CC55C)) == 0x98) ? (1) : (-1)];

void TTecJelin::create(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 obj;
    obj = __nw__7TObjectFUl(0x14C);
    if (obj != 0U) {
        construct__9TTecJelinFPviiii((Jelin_80233958 *)(obj), arg0, arg1, arg2, arg3);
    }
}
void TTecJelin::render() {  }

void run_task__9TTecJelinFv(struct Self_802336F0 *self) {
    s32 i;
    u32 id;
    self->target = (u32)find_entity_by_id(self->owner);
    if (self->target == 0) {
        queue_destruction__7TObjectFv((self));
        return;
    }
    if (self->flag != 0) {
        for (i = 0; i < self->count; i++) {
            id = (u32)find_entity_by_id(self->entries[i].id);
            if (TTecLuker::is_parents_unqueued(id) != 0) {
                ((TTecJelin *)(self))->vfunc_6((void *)id);
            }
        }
    } else {
        ((TUnk_804CC148 *)self)->apply_technique_to_area_targets();
    }
    queue_destruction__7TObjectFv((self));
}

}
TTecJelin::~TTecJelin() {

}


Jelin_80233808 *TTecJelin__ct(Jelin_80233808 *self, void *_w1, void *_w2, void *_w3, void *_w4) {
    s32 r;
    __ct__13TUnk_804CC148Flll(self, _w1, _w2, _w4);
    self->vt = __vt__9TTecJelin;
    ((TObjPlayer *)(self->sub))->construct_target_cursor_records();
    self->f0 = tec_jelin_class_name_ptr;
    self->fec = 1;
    copy_technique_target_list(self->sub, _w3);
    ((TTecJelin *)self)->init_tech_params();
    VecCopy((Vec *)((Vec_80233958 *)&self->pos), (const Vec *)((Vec_80233958 *)_w2));
    if (self->holder != 0) {
        self->holder->eff->scale = self->range;
    }
    switch (self->level) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002A315, &self->pos, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002A315, &self->pos, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002A315, &self->pos, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, -0x100, 0);
        }
        break;
    }
    if (self->source != 0) {
        self->field_b4 = get_entity_id(self->source);
    }
    return self;
}

Jelin_80233958 *construct__9TTecJelinFPviiii(Jelin_80233958 *self, s32 _w1, s32 _w2, s32 _w3, s32 _w4) {
    s32 r;
    construct_area_technique_base(self);
    self->vt = ((s32 *)&__vt__9TTecJelin);
    ((TObjPlayer *)(self->sub))->construct_target_cursor_records();
    self->f0 = tec_jelin_class_name_ptr;
    self->fec = 0;
    ((TTecJelin *)self)->init_tech_params();
    VecCopy((Vec *)&self->pos, (const Vec *)&self->src_pos);
    if (self->holder != 0) {
        self->holder->eff->scale = self->range;
    }
    switch (self->level) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002A315, &self->pos, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002A315, &self->pos, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002A315, &self->pos, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, -0x100, 0);
        }
        break;
    }
    if (self->source != 0) {
        self->field_b4 = get_entity_id(self->source);
    }
    return self;
}

