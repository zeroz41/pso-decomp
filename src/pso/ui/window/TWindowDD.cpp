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

extern const f32 lbl_805DFC34;
extern const f32 lbl_805DFC38;
extern const f32 lbl_805DFC3C;
extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, void *);
s32 TWindowShortListCtrl__check_controller_button(void *, void *);
extern RecoveredGlobal_80340508_lbl_8050E208 controller_input_state;
s32 apply_choice__20TWindowChoiceSettingFllll(void *, void *, int, int);
extern const f32 lbl_805DFC30;

void TWindowDD::reset_entries(f32 v, s32) {
    E_803403F8 *p = (E_803403F8 *)this;
    s32 i;
    for (i = 0; i < 8; i++) {
        p->a = lbl_805DFC30;
        p->b = lbl_805DFC30;
        p->c = v;
        p->d = lbl_805DFC30;
        p->e = lbl_805DFC30;
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
  temp_f8 = lbl_805DFC34 * farg0;
  temp_f7 = lbl_805DFC34 * farg1;
  *((f32 *) (((s8 *) arg0) + 0)) = temp_f8;
  temp_f5 = lbl_805DFC34 * (lbl_805DFC38 + farg1);
  new_var4 = lbl_805DFC34 * temp_f4;
  *((f32 *) (((s8 *) arg0) + 4)) = temp_f7;
  temp_f1 = lbl_805DFC3C + farg0;
  temp_f2 = new_var4;
  *((f32 *) (((s8 *) arg0) + 8)) = temp_f8;
  temp_f1_2 = lbl_805DFC34 * temp_f1;
  *((f32 *) (((s8 *) arg0) + 0xC)) = temp_f5;
  temp_f0 = temp_f1;
  temp_f0 = lbl_805DFC34 * (temp_f0 - farg2);
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
