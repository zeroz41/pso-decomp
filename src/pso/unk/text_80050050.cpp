#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/TObjDFDemoF.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80050050_lbl_80485864
{
  s32 value;
  u8 remaining[0x8];
};

extern "C" {
s32 queue_destruction__7TObjectFv();
extern const f32 lbl_805D8A20;
extern const f32 lbl_805D8A24;
s32 push_matrix();
f32 post_translate_matrix(void *);
extern RecoveredGlobal_80050050_lbl_80485864 three_part_model_translate_offset;

typedef struct RecoveredGlobal_80050050_lbl_80485864 RecoveredGlobal_80050050_lbl_80485864;
typedef char RecoveredGlobal_80050050_lbl_80485864_size[((sizeof(RecoveredGlobal_80050050_lbl_80485864)) == 0xC) ? (1) : (-1)];
void TObjDFDemoF::render() {
    u8 *arg0 = (u8 *)this;
  int var_r31;
  unsigned int temp_r4;
  u8 *temp_r30;
  int var_r29;
  push_matrix();
  set_motion_packed_rotation();
  post_translate_matrix(&three_part_model_translate_offset.value);
  var_r29 = 0;
  var_r31 = 0;
  do
  {
    temp_r30 = (u8 *) (arg0 + var_r31);
    TObjFish::set_global_param((int) (*((int *) (((s8 *) temp_r30) + 0xA0))));
    temp_r4 = *((unsigned int *) (((s8 *) temp_r30) + 0xAC));
    if (temp_r4 == 0U)
    {
      draw_chunk_object((void *)(*((int *) (((s8 *) temp_r30) + 0x94))));
    }
    else
    {
      draw_model_motion((void *)(*((int *) (((s8 *) temp_r30) + 0x94))), (void *)temp_r4, this->m_b8);
    }
    var_r29 += 1;
    var_r31 += 4;
  }
  while (var_r29 < 3);
  clear_motion_packed_rotation();
  pop_matrix();
}

#pragma push
#pragma opt_common_subs off
void TObjDFDemoF::run_task() {
    f32 temp_f1;
    s32 temp_r0;
    temp_f1 = this->m_b8 + lbl_805D8A20;
    this->m_b8 = temp_f1;
    if (temp_f1 >= lbl_805D8A24) {
        this->m_b8 = (f32) lbl_805D8A24;
    }
    temp_r0 = this->m_90 + 1;
    this->m_90 = temp_r0;
    if (temp_r0 >= 0x78) {
        queue_destruction__7TObjectFv();
    }
}
#pragma pop

}
