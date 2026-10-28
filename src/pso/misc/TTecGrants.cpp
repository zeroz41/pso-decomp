#include "types.h"
#include "pso/misc/TTecGrants.h"
#include "pso/object/TObject_80019A50.h"

#include "pso/effect/TUnk_804CC148.h"

struct RecoveredGlobal_80233350___vt__10TTecGrants {
    s32 value;
    u8 remaining[0x24];
};

#include <stddef.h>
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

extern "C" {
void *find_entity_by_id(u16 id);
u8 * __ct__13TUnk_804CC888FPUclP7TObject(void *, s32, s32, s32);
void *__nw__7TObjectFUl(int);
extern s32 tl_07;
void run_task__10TTecGrantsFv(TTecGrants *arg0);
s32 get_entity_id(int);
s32 copy_technique_target_list(void *, void *);
s32 __ct__13TUnk_804CC148Flll(void *, void *, void *, void *);
extern s32 __vt__10TTecGrants[];
extern s32 tec_grants_class_name;
u8 *TTecGrants__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void TTecGrants::render() {  }

typedef char RecoveredGlobal_802384E0_lbl_804CCB28_size[sizeof(RecoveredGlobal_802384E0_lbl_804CCB28) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_802385EC_lbl_804CCB28_size[sizeof(RecoveredGlobal_802385EC_lbl_804CCB28) == 0x18 ? 1 : -1];
void TTecGrants::vfunc_6(void *target_arg) {
    u8 *self = (u8 *)this;
    u8 *target = (u8 *)target_arg;
    Damage_802386F8 d;
    d.kind = 0x4;
    d.power = *(f32 *)(self + 0x88);
    ((VObj_802386F8 *)target)->m21(*(s32 *)(self + 0x1C), d, *(s32 *)(self + 0xB8), 0x9, -1, self);
}
typedef struct RecoveredFields_80238D10_arg0 RecoveredFields_80238D10_arg0;
typedef struct RecoveredGlobal_80238D10_lbl_804CC510 RecoveredGlobal_80238D10_lbl_804CC510;
typedef struct RecoveredGlobal_80238D10_lbl_804CC55C RecoveredGlobal_80238D10_lbl_804CC55C;
typedef char RecoveredGlobal_80238D10_lbl_804CC510_size[((sizeof(RecoveredGlobal_80238D10_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_80238D10_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80238D10_lbl_804CC55C)) == 0x98) ? (1) : (-1)];

void TTecGrants::create(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x14C);
    if (o != NULL) {
        TTecGrants__ct((u8 *)o, (s32)arg0, (s32)arg1, (s32)arg2, (s32)arg3);
    }
}

void run_task__10TTecGrantsFv(TTecGrants *tec_grants) {
    u32 entity;
    u8 *temp_r3_2;
    *(u8 **)((s8 *)tec_grants + 0x1C) = (u8 *)find_entity_by_id(tec_grants->m_b4);
    if ((void *) *(u8 **)((s8 *)tec_grants + 0x1C) == NULL) {
        queue_destruction__7TObjectFv((tec_grants));
        return;
    }
    if ((s32) tec_grants->m_ec == 0) {
        queue_destruction__7TObjectFv((tec_grants));
        return;
    }
    entity = (unsigned long) (find_entity_by_id(tec_grants->m_f0));
    if ((TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0) && ((s32) tec_grants->m_148 == 0)) {
        temp_r3_2 = (u8 *)(((u8 *)__nw__7TObjectFUl(0x3C)));
        if (temp_r3_2 != NULL) {
            __ct__13TUnk_804CC888FPUclP7TObject(temp_r3_2, (s32) entity, (s32) tec_grants->m_78, tl_07);
        }
    }
    tec_grants->m_148 = (tec_grants->m_148 + 1);
    if ((s32) tec_grants->m_148 > 0x1E) {
        if ((entity != 0) && (TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0)) {
            ((TTecGrants *)(tec_grants))->vfunc_6((void *)entity);
        }
        queue_destruction__7TObjectFv((tec_grants));
    }
}

}
TTecGrants::~TTecGrants() {

}

typedef char RecoveredGlobal_80233350___vt__10TTecGrants_size[sizeof(RecoveredGlobal_80233350___vt__10TTecGrants) == 0x28 ? 1 : -1];
u8 *TTecGrants__ct(u8 *tec_grants, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 temp_r3;
    __ct__13TUnk_804CC148Flll((void *)tec_grants, (void *)arg1, (void *)arg2, (void *)arg4);
    *(s32 **)((s8 *)tec_grants + 0x18) = &(*(RecoveredGlobal_80233350___vt__10TTecGrants *)&__vt__10TTecGrants).value;
    ((TObjPlayer *)(tec_grants + 0xEC))->construct_target_cursor_records();
    *(s32 *)((s8 *)tec_grants + 0) = (s32) tec_grants_class_name;
    ((TTecGrants *)tec_grants)->init_parameters();
    copy_technique_target_list(tec_grants + 0xEC, (void *)arg3);
    ((TTecGrants *)tec_grants)->m_148 = 0;
    temp_r3 = ((TTecGrants *)tec_grants)->source;
    if (temp_r3 != 0U) {
        ((TTecGrants *)tec_grants)->m_b4 = get_entity_id(temp_r3);
    }
    return tec_grants;
}

