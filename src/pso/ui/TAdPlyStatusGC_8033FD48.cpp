#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/ui/TAdPlyStatusGC_8033FD48.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/TAdPlyStatusGC.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8033FDB0_lbl_80478430
{
  s32 value;
  u8 remaining[0x8];
};

extern "C" {
s32 push_matrix();
f32 post_translate_matrix(void *);
extern RecoveredGlobal_8033FDB0_lbl_80478430 lbl_80478430;
extern const f32 lbl_805DFAF8;
u32 TAdPlyStatusGC__ct(u32, s32, s32);
u32 __nw__7TObjectFUl(s32);

extern u32 ply_status_gc_instance;

u32 TAdPlyStatusGC::get_instance(s32 arg0, s32 arg1) {
    u32 var_r0;

    if ((u32) ply_status_gc_instance == 0U) {
        var_r0 = __nw__7TObjectFUl(0x70);
        if (var_r0 != 0U) {
            var_r0 = TAdPlyStatusGC__ct(var_r0, arg0, arg1);
        }
        ply_status_gc_instance = var_r0;
    }
    return ply_status_gc_instance;
}

    extern int guide_button_instance;
int TAdPlyStatusGC::get_player_index() {  return guide_button_instance; }
typedef struct RecoveredGlobal_8033FDB0_lbl_80478430 RecoveredGlobal_8033FDB0_lbl_80478430;
typedef char RecoveredGlobal_8033FDB0_lbl_80478430_size[((sizeof(RecoveredGlobal_8033FDB0_lbl_80478430)) == 0xC) ? (1) : (-1)];
void TObjPlayer__sub_8033FDB0(s32 arg0) {
  s32 var_r31;
  u8 *temp_r30;
  s32 var_r29;
  push_matrix();
  set_motion_packed_rotation();
  post_translate_matrix(&lbl_80478430.value);
  var_r29 = 0;
  var_r31 = 0;
  do
  {
    temp_r30 = (u8 *) (arg0 + (var_r31 & 0xFFFFFFFFFFFFFFFF));
    TObjFish::set_global_param((int) (*((s32 *) (((s8 *) temp_r30) + 0x2C))));
    draw_model_motion((void *)(*((s32 *) (((s8 *) temp_r30) + 0x28))), (void *)(*((s32 *) (((s8 *) temp_r30) + 0x30))), (f32) lbl_805DFAF8);
    var_r29 += 1;
    var_r31 += 0xC;
  }
  while (var_r29 < 2);
  clear_motion_packed_rotation();
  pop_matrix();
}

}
