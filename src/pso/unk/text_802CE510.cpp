#include "pso/enemy/TObjEnemy.h"
#include "pso/TParticleCtrl.h"
#include "types.h"
#include "pso/unk/text_800D8830.h"
#include "pso/boss/TBoss8Dragon_80065C90.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_802CE510.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"

struct Stack_802CE510
{
  s32 sp8;
  f32 spC;
  u8 trailing_storage[0x4];
};

struct RecoveredFields_802CE510_temp_r3
{
  int field_0;
  int field_4;
};

extern "C" {
void *spawn_particle_effect(void *pos, s32 id);
extern const f32 lbl_805DE6E8;
extern const f32 lbl_805DE6EC;
extern const f32 lbl_805DE6F0;
extern const f32 lbl_805DE6F4;
extern const f32 lbl_805DE6F8;
extern const f32 lbl_805DE6FC;
typedef struct RecoveredFields_802CE510_temp_r3 RecoveredFields_802CE510_temp_r3;
typedef struct Stack_802CE510 Stack_802CE510;
void fn_802CE510(int arg0) {
  Stack_802CE510 stack;
  int temp_r31_2;
  int new_var;
  unsigned int temp_r31;
  unsigned int particle_effect;
  unsigned int temp_r3_3;
  unsigned int temp_r3_4;
  u8 *temp_r3;
  VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
  stack.spC += lbl_805DE6E8;
  temp_r3 = (u8 *) csnVectorUnder((Vec *)&stack.sp8, (u32 *)(arg0 + 0x120), 0x15);
  if (temp_r3 != 0)
  {
    temp_r31 = ((RecoveredFields_802CE510_temp_r3 *) temp_r3)->field_0 & 4;
    if (temp_r31 != 0)
    {
      fn_800D8830((void *)arg0, (void *)(arg0 + 0x38));
    }
    else
    {
      play_persistent_sound((s32)((void *) ((TObjEnemy *)((void *) arg0))->remap_sound_for_area((s32)(0x3B211))), arg0, (arg0 + 0x38), 0, 0);
    }
    if (((((TObjMotion *)arg0)->is_passing_frame((f32)((f32) lbl_805DE6EC)) != 0) || (((TObjMotion *)arg0)->is_passing_frame((f32)((f32) lbl_805DE6E8)) != 0)) || (((TObjMotion *)arg0)->is_passing_frame((f32)((f32) lbl_805DE6F0)) != 0))
    {
      if (temp_r31 != 0)
      {
        particle_effect = (unsigned int)spawn_particle_effect((void *)(((RecoveredFields_802CE510_temp_r3 *) temp_r3)->field_4 + 0x38), 0x49);
        if (particle_effect != 0U)
        {
          ;
          attach_particle_model((u8 *)particle_effect, (s32)((int) TParticleCtrl::get_particle_model(2)), (s32)((int) TParticleCtrl::get_instance()), 0, 1, (f32)((f32) lbl_805DE6F4));
          temp_r3 = temp_r3;
          new_var = (int) particle_effect;
          ((TParticleCtrl *)new_var)->set_scale((f32) lbl_805DE6EC, (f32) lbl_805DE6F4);
        }
        temp_r3_3 = (unsigned int)spawn_particle_effect((void *)(((RecoveredFields_802CE510_temp_r3 *) temp_r3)->field_4 + 0x38), 0xA4);
        if (temp_r3_3 != 0U)
        {
          ((TParticleCtrl *)temp_r3_3)->set_scale((f32) lbl_805DE6EC, (f32) lbl_805DE6F8);
        }
      }
      else
      {
        temp_r3_4 = (unsigned int)spawn_particle_effect((void *)(arg0 + 0x38), 0xF3);
        if (temp_r3_4 != 0U)
        {
          ((TParticleCtrl *)temp_r3_4)->set_scale((f32) lbl_805DE6EC, (f32) lbl_805DE6FC);
        }
      }
    }
  }
}

}
