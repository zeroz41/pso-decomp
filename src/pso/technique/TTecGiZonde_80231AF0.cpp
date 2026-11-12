#include "types.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecCtrl.h"

struct RecoveredGlobal_8023C558_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_8023C558_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
};

struct RecoveredFields_8023C558_arg0
{
  u8 unknown_0[0xC4];
  s16 field_C4;
  u8 unknown_C6[0x6];
  f32 field_CC;
  u8 unknown_D0[0x20];
  s16 field_F0;
};

extern "C" {
s32 calc_technique_parameters(int, int, int);
extern RecoveredGlobal_8023C558_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_8023C558_lbl_804CC55C lbl_804CC55C;
typedef struct RecoveredFields_8023C558_arg0 RecoveredFields_8023C558_arg0;
typedef struct RecoveredGlobal_8023C558_lbl_804CC510 RecoveredGlobal_8023C558_lbl_804CC510;
typedef struct RecoveredGlobal_8023C558_lbl_804CC55C RecoveredGlobal_8023C558_lbl_804CC55C;
typedef char RecoveredGlobal_8023C558_lbl_804CC510_size[((sizeof(RecoveredGlobal_8023C558_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_8023C558_lbl_804CC55C_size[((sizeof(RecoveredGlobal_8023C558_lbl_804CC55C)) == 0x98) ? (1) : (-1)];
void TTecGiZonde::init_parameters() {
    u8 *arg0 = (u8 *)this;
  s32 new_var;
  new_var = calc_technique_parameters(0x7, (int) ((RecoveredFields_8023C558_arg0 *) arg0)->field_C4, 0xFFFF);
  ((TTecAnti *)(arg0 + 0xCC))->copy_params((u8 *)new_var);
  if ((((s16) ((RecoveredFields_8023C558_arg0 *) arg0)->field_C4) >= 0xF) && (TTecCtrl::is_technique_ready() == 0))
  {
    ((RecoveredFields_8023C558_arg0 *) arg0)->field_CC = (f32) ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x1c))) + ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x1e))) * ((RecoveredFields_8023C558_arg0 *) arg0)->field_C4));
    return;
  }
  ((RecoveredFields_8023C558_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) arg0)->field_CC + ((f32) (((RecoveredFields_8023C558_arg0 *) arg0)->field_F0 * ((RecoveredFields_8023C558_arg0 *) arg0)->field_C4)));
  if (TTecCtrl::is_technique_ready())
  {
    ((RecoveredFields_8023C558_arg0 *) arg0)->field_CC = (f32) (((RecoveredFields_8023C558_arg0 *) arg0)->field_CC * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x38))));
  }
}

}
