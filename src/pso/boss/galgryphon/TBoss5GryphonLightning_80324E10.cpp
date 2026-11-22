#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningEff.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "pso/system/task/TObject.h"

extern "C" {
u8 *__ct__25TBoss5GryphonLightningEffFv(void *, s32, s32, s32, f32, f32, f32);
extern s32 tl_07;
#pragma fp_contract on
void TBoss5GryphonLightning::spawn_gryphon_lightning() {
    u8 *self = (u8 *)this;
  unsigned char temp_r3;
  u32 temp_r4;
  u8 *temp_r3_2;
  u8 *var_r0;
  temp_r4 = *((u32 *) (((s8 *) self) + 0x94));
  temp_r3 = temp_r4 >> 0x1FU;
  *((u32 *) (((s8 *) self) + 0x94)) = (temp_r4 + 1);
  if ((((temp_r4 & 1) ^ temp_r3) - temp_r3) == 0)
  {
    temp_r3_2 = (u8 *) (u8 *)TObject::operator new(0x264);
    var_r0 = (u8 *) temp_r3_2;
    if (var_r0 != 0)
    {
      var_r0 = (u8 *) __ct__25TBoss5GryphonLightningEffFv(temp_r3_2, tl_07, (saddr)(self + 0x48), *((s32 *) (((s8 *) self) + 0x90)), *((f32 *) (((s8 *) self) + 0x88)), *((f32 *) (((s8 *) self) + 0x8C)), *((f32 *) (((s8 *) self) + 0x1C)));
    }
    TBoss5GryphonLightningEff__sub_80325064(var_r0);
  }
}

}
