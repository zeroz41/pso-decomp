#include "types.h"
#include "pso/technique/TTecGiZonde_80231BF4.h"
#include "pso/technique/TTecGiZonde.h"

#include <stddef.h>
#pragma fp_contract on
struct RecoveredGlobal_802384E0_lbl_804CCB28;

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

typedef struct Point_80238C6C { f32 x, y, z; } Point_80238C6C;

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

typedef char RecoveredGlobal_802384E0_lbl_804CCB28_size[sizeof(RecoveredGlobal_802384E0_lbl_804CCB28) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_802385EC_lbl_804CCB28_size[sizeof(RecoveredGlobal_802385EC_lbl_804CCB28) == 0x18 ? 1 : -1];
#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80238388_lbl_8044DAF0_size[sizeof(RecoveredGlobal_80238388_lbl_8044DAF0) == 0x10 ? 1 : -1];
typedef struct RecoveredFields_80230D9C_arg0 RecoveredFields_80230D9C_arg0;
typedef struct RecoveredGlobal_80230D9C_lbl_804CC510 RecoveredGlobal_80230D9C_lbl_804CC510;
typedef struct RecoveredGlobal_80230D9C_lbl_804CC55C RecoveredGlobal_80230D9C_lbl_804CC55C;
typedef char RecoveredGlobal_80230D9C_lbl_804CC510_size[((sizeof(RecoveredGlobal_80230D9C_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_80230D9C_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80230D9C_lbl_804CC55C)) == 0x98) ? (1) : (-1)];
#pragma pop
typedef struct RecoveredFields_80238D10_arg0 RecoveredFields_80238D10_arg0;
typedef struct RecoveredGlobal_80238D10_lbl_804CC510 RecoveredGlobal_80238D10_lbl_804CC510;
typedef struct RecoveredGlobal_80238D10_lbl_804CC55C RecoveredGlobal_80238D10_lbl_804CC55C;
typedef char RecoveredGlobal_80238D10_lbl_804CC510_size[((sizeof(RecoveredGlobal_80238D10_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_80238D10_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80238D10_lbl_804CC55C)) == 0x98) ? (1) : (-1)];
#pragma push
#pragma opt_common_subs off
#pragma pop
void TTecGiZonde::vfunc_8(void *arg1_arg) {
    u8 *arg1 = (u8 *)arg1_arg;
    Elec_80238E14 d;
    d.type = 3;
    d.val = this->power;
    ((VObj_18_9c98dd *)(arg1))->m21(this->source, d, 0, 0x7, -1);
}
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#define self ((Self_80239070 *)self_)
#undef self
#pragma pop
