#include "types.h"
#include "pso/technique/TTecGrants.h"
#include "pso/technique/TTecAnti.h"

struct RecoveredGlobal_80232830_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_80232830_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
};

extern "C" {
s32 calc_technique_parameters(int, int, int);
s32 is_technique_ready__8TTecCtrlFv();
extern RecoveredGlobal_80232830_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_80232830_lbl_804CC55C lbl_804CC55C;
typedef struct RecoveredGlobal_80232830_lbl_804CC510 RecoveredGlobal_80232830_lbl_804CC510;
typedef struct RecoveredGlobal_80232830_lbl_804CC55C RecoveredGlobal_80232830_lbl_804CC55C;
typedef char RecoveredGlobal_80232830_lbl_804CC510_size[((sizeof(RecoveredGlobal_80232830_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_80232830_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80232830_lbl_804CC55C)) == 0x98) ? (1) : (-1)];
void TTecGrants::init_parameters() {
    u8 *arg0 = (u8 *)this;
  s32 *new_var2;
  int new_var3;
  s8 *new_var;
  new_var = (s8 *) arg0;
  new_var3 = (int) calc_technique_parameters(9, this->m_78, 0xFFFF);
  ((TTecAnti *)(arg0 + 0x88))->copy_params((u8 *)new_var3);
  if ((((s16) (*((s16 *)(new_var + 0x78)))) >= 0xF) && (is_technique_ready__8TTecCtrlFv() == 0))
  {
    new_var2 = &tech_high_level_linear_power_table.value;
    new_var = new_var;
    *((f32 *)(new_var + 0x88)) = (f32) ((*((s16 *) (((s8 *) new_var2) + 0x24))) + ((*((s16 *) (((s8 *) new_var2) + 0x26))) * (*((s16 *)(new_var + 0x78)))));
    return;
  }
  *((f32 *)(new_var + 0x88)) = (f32) ((*((f32 *)(new_var + 0x88))) + ((f32) ((*((s16 *)(new_var + 0xAC))) * (*((s16 *)(new_var + 0x78))))));
  if (is_technique_ready__8TTecCtrlFv() != 0)
  {
    *((f32 *)(new_var + 0x88)) = (f32) ((*((f32 *)(new_var + 0x88))) * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x48))));
  }
}

}
