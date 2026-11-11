#include "pso/ui/window/TWindowDD.h"

#include "types.h"

struct RecoveredGlobal_80340508_lbl_8050E208
{
  s32 value;
  u8 remaining[0x1AC];
};

struct RecoveredGlobal_803404A4_lbl_8050E208
{
  s32 value;
  u8 remaining[0x1AC];
};

struct E_803403F8 { f32 a; f32 b; f32 c; f32 d; f32 e; s32 f; };

// Window layout constants shared by the TWindowDD files (one definition here, extern elsewhere).
extern const f32 TWindowDD__data_805DFB18 = 0.00390625f;
extern const f32 lbl_805DFB1C = 16.0f;
extern const f32 TWindowDD__data_805DFB20 = 20.0f;
extern const f32 lbl_805DFB24 = 18.0f;
extern const f32 lbl_805DFB28 = 16.0f;
extern const f32 lbl_805DFB2C = 202.0f;
extern const f32 lbl_805DFB30 = 216.0f;
extern const f32 lbl_805DFB34 = 102.0f;
extern const f32 lbl_805DFB38 = 14.0f;
extern const f32 lbl_805DFB3C = 14.0f;
extern const f32 lbl_805DFB40 = 199.0f;
extern const f32 lbl_805DFB44 = 219.0f;
extern const f32 lbl_805DFB48 = 0.015625f;
extern const f32 lbl_805DFB4C = 18.0f;
extern const s32 TWindowDD__data_805DFB50 = 6;
extern const f32 lbl_805DFB54 = 6.0f;
extern const f32 TWindowDD__data_805DFB58 = 4.0f;
extern const f32 lbl_805DFB5C = 0.0f;
extern const f32 lbl_805DFB60 = -20.0f;
extern const f32 lbl_805DFB64 = 680.0f;
extern const f32 lbl_805DFB68 = 480.0f;
extern const f32 TWindowDD__data_805DFB6C = 50.0f;
extern const f32 lbl_805DFB70 = 310.0f;
extern const f32 TWindowDD__data_805DFB74 = 240.0f;
extern const f32 lbl_805DFB78 = 120.0f;
extern const f32 lbl_805DFB7C = 480.0f;
extern const f32 lbl_805DFB80 = 370.0f;
extern const f32 lbl_805DFB84 = 310.0f;
extern const f32 lbl_805DFB88 = 240.0f;
extern const f32 lbl_805DFB8C = 120.0f;
extern const f32 lbl_805DFB90 = -260.0f;
extern const f32 lbl_805DFB94 = 660.0f;
extern const f32 lbl_805DFB98 = 310.0f;
extern const f32 lbl_805DFB9C = 240.0f;
extern const f32 lbl_805DFBA0 = 120.0f;
extern const f32 lbl_805DFBA4 = 50.0f;
extern const f32 lbl_805DFBA8 = 290.0f;
extern const f32 lbl_805DFBAC = 168.0f;
extern const f32 lbl_805DFBB0 = 370.0f;
extern const f32 lbl_805DFBB4 = 290.0f;
extern const f32 lbl_805DFBB8 = 166.0f;
extern const f32 lbl_805DFBBC = 18.0f;
extern const f32 lbl_805DFBC0 = 120.0f;
extern const f32 lbl_805DFBC4 = 32.0f;
extern const f32 lbl_805DFBC8 = 310.0f;
extern const f32 lbl_805DFBCC = 2.0f;
extern const f32 lbl_805DFBD0 = 70.0f;
extern const f32 lbl_805DFBD4 = 430.0f;
extern const f32 lbl_805DFBD8 = 120.0f;
extern const f32 lbl_805DFBDC = 30.0f;
extern const f32 lbl_805DFBE0 = 224.0f;
extern const f32 lbl_805DFBE4 = 240.0f;
extern const f32 lbl_805DFBE8 = 40.0f;
extern const f32 lbl_805DFBEC = 244.0f;
extern const f32 lbl_805DFBF0 = 30.0f;
extern const f32 lbl_805DFBF4 = 204.0f;
extern const f32 lbl_805DFBF8 = 30.0f;
extern const f32 TWindowDD__data_805DFBFC = 290.0f;
extern const f32 lbl_805DFC00 = 310.0f;
extern const f32 lbl_805DFC04 = 64.0f;
extern const f32 lbl_805DFC08 = 18.0f;
extern const f32 lbl_805DFC0C = 530.0f;
extern const f32 TWindowDD__data_805DFC10 = 594.0f;
extern const u32 TWindowDD__data_805DFC14 = 0xFFFFFFFF;
extern const u32 lbl_805DFC18 = 0xFF000000;
extern const f32 lbl_805DFC1C = 50039.0f;
extern const f32 lbl_805DFC20 = 50038.0f;
extern const f32 lbl_805DFC24 = 50040.0f;
extern const f32 lbl_805DFC28 = 50037.0f;
extern const f32 lbl_805DFC2C = 50040.0f;

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, void *);
s32 TWindowShortListCtrl__check_controller_button(void *, void *);
extern RecoveredGlobal_80340508_lbl_8050E208 controller_input_state;
s32 apply_choice__20TWindowChoiceSettingFllll(void *, void *, int, int);

void TWindowDD::reset_entries(f32 v, s32) {
    E_803403F8 *p = (E_803403F8 *)this;
    s32 i;
    for (i = 0; i < 8; i++) {
        p->a = 0.0f;
        p->b = 0.0f;
        p->c = v;
        p->d = 0.0f;
        p->e = 0.0f;
        p->f = -1;
        p++;
    }
}

void TWindowDD::set_quad_corners_scaled(f32 farg0, f32 farg1, f32 farg2) {
    u8 *arg0 = (u8 *)this;
  f32 temp_f0;
  f32 temp_f1;
  f32 temp_f1_2;
  s8 *new_var;
  f32 temp_f2;
  f32 temp_f4;
  float new_var4;
  f32 temp_f5;
  int new_var3;
  f32 temp_f7;
  f32 temp_f8;
  s8 *new_var2;
  temp_f4 = farg0 + farg2;
  temp_f8 = TWindowDD__data_805DFB18 * farg0;
  temp_f7 = TWindowDD__data_805DFB18 * farg1;
  *((f32 *) (((s8 *) arg0) + 0)) = temp_f8;
  temp_f5 = TWindowDD__data_805DFB18 * (TWindowDD__data_805DFB20 + farg1);
  new_var4 = TWindowDD__data_805DFB18 * temp_f4;
  *((f32 *) (((s8 *) arg0) + 4)) = temp_f7;
  temp_f1 = 48.0f + farg0;
  temp_f2 = new_var4;
  *((f32 *) (((s8 *) arg0) + 8)) = temp_f8;
  temp_f1_2 = TWindowDD__data_805DFB18 * temp_f1;
  *((f32 *) (((s8 *) arg0) + 0xC)) = temp_f5;
  temp_f0 = temp_f1;
  temp_f0 = TWindowDD__data_805DFB18 * (temp_f0 - farg2);
  new_var2 = ((s8 *) arg0) + 0x28;
  *((f32 *) (((s8 *) arg0) + 0x10)) = temp_f2;
  *((f32 *) (((s8 *) arg0) + 0x14)) = temp_f7;
  *((f32 *) (((s8 *) arg0) + 0x18)) = temp_f2;
  *((f32 *) (((s8 *) arg0) + 0x1C)) = temp_f5;
  *((f32 *) (((s8 *) arg0) + 0x20)) = temp_f0;
  *((f32 *) (((s8 *) arg0) + 0x24)) = temp_f7;
  new_var3 = 0x30;
  *((f32 *) new_var2) = temp_f0;
  *((f32 *) (((s8 *) arg0) + 0x2C)) = temp_f5;
  *((f32 *) (((s8 *) arg0) + new_var3)) = temp_f1_2;
  *((f32 *) (((s8 *) arg0) + 0x34)) = temp_f7;
  new_var = ((s8 *) arg0) + 0x38;
  *((f32 *) new_var) = temp_f1_2;
  *((f32 *) (((s8 *) arg0) + 0x3C)) = temp_f5;
}

typedef struct RecoveredGlobal_80340508_lbl_8050E208 RecoveredGlobal_80340508_lbl_8050E208;
typedef char RecoveredGlobal_80340508_lbl_8050E208_size[((sizeof(RecoveredGlobal_80340508_lbl_8050E208)) == 0x1B0) ? (1) : (-1)];

#pragma push
#pragma opt_dead_assignments off
typedef struct RecoveredGlobal_803404A4_lbl_8050E208 RecoveredGlobal_803404A4_lbl_8050E208;
typedef char RecoveredGlobal_803404A4_lbl_8050E208_size[((sizeof(RecoveredGlobal_803404A4_lbl_8050E208)) == 0x1B0) ? (1) : (-1)];
s32 TWindowDD::apply_both_choices(s32 arg0, s32 arg1) {
  return apply_choice__20TWindowChoiceSettingFllll((void *) (((u8 *) (&(*(RecoveredGlobal_803404A4_lbl_8050E208 *)&controller_input_state).value)) + 0x20), (void *) arg1, 6, 1) | apply_choice__20TWindowChoiceSettingFllll((void *) (((u8 *) (&(*(RecoveredGlobal_803404A4_lbl_8050E208 *)&controller_input_state).value)) + 0x160), (void *) arg1, 6, 1);
}
}
#pragma pop

s32 TWindowDD_check_input_mask(void *input_context, s32 arg1) {
  return TWindowShortListCtrl__check_controller_button((void *) (((u8 *)&controller_input_state.value) + 0x20), (void *) arg1) | test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) (((u8 *)&controller_input_state.value) + 0x160), (void *) arg1);
}
