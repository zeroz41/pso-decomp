#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_800A887C.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_800A887C_lbl_80491260
{
  s32 value;
  u8 remaining[0x5C];
};

extern "C" {
s32 play_sound_effect(s32, u32, s16, s32);
s32 obj_setFlags30(void *, int);
s32 set_flag_start_effect__10TObjPlayerFv();
extern RecoveredGlobal_800A887C_lbl_80491260 lbl_80491260;
extern s32 breakup_model_ptr;
typedef struct RecoveredGlobal_800A887C_lbl_80491260 RecoveredGlobal_800A887C_lbl_80491260;
void dubchik_update_dying(u8 *arg0) {
  s16 temp_r3;
  set_flag_start_effect__10TObjPlayerFv();
  temp_r3 = (*((s16 *) (((s8 *) arg0) + 0x33C)) = (*((s16 *) (((s8 *) arg0) + 0x33C))) - 1);
  if (temp_r3 <= 0)
  {
    if (TLobby::get_instance() != 0)
    {
      play_sound_effect(0x4003AD10, (u32)(arg0 + 0x38), 0, 0);
    }
    else
    {
      play_sound_effect(((TObjEnemy *)((void *) arg0))->remap_sound_for_area((s32)(0x4003AD16)), (u32)(arg0 + 0x38), 0, 0);
    }
    TBoss3Volopt::create_breakup_mdl((s32)((void *) breakup_model_ptr), (s32)&lbl_80491260.value, (s32)((int) (*((s32 *) (((s8 *) arg0) + 0x24)))), (s32)(arg0 + 0x2FC), (s32)((int) (*((s32 *) (((s8 *) arg0) + 0x60)))));
    ((TObjPlayer *)arg0)->refresh_lobby_state();
    ((TObjEnemy *)arg0)->send_entity_set_flags();
    ((TObjPlayer *)(arg0 + 0x2FC))->trigger_dell_biter_events();
    obj_setFlags30((void *) arg0, 0x800);
    queue_destruction__7TObjectFv(arg0);
  }
}

}
