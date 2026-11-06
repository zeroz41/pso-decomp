#include "types.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/text_8007F8D0.h"
#include "pso/unk/text_8007FA24.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"

struct RecoveredGlobal_8007FA24_lbl_8048DF88
{
  s32 value;
  u8 remaining[0x8];
};


extern RecoveredGlobal_8007FA24_lbl_8048DF88 lbl_8048DF88;
typedef struct RecoveredGlobal_8007FA24_lbl_8048DF88 RecoveredGlobal_8007FA24_lbl_8048DF88;
typedef char RecoveredGlobal_8007FA24_lbl_8048DF88_size[((sizeof(RecoveredGlobal_8007FA24_lbl_8048DF88)) == 0xC) ? (1) : (-1)];
void TAdTrialModemChkGC__sub_8007FA24(s32 arg0) {
  s32 temp_r31;
  s32 var_r31;
  var_r31 = 0;
  TAdTrialModemChkGC::init_modem_check_params();
  if (TLobby__sub_8014618C() != 0)
  {
    var_r31 = 1;
  }
  temp_r31 = ~(0 - (arg0 == 0));
  temp_r31 = (var_r31 + 1) & temp_r31;
  if ((temp_r31 == 1) != 0)
  {
    TAdTrialModemChkGC::init_modem_check_params();
  }
  launch_switcher_dol((const char *)(*((s32 *) (((s8 *) (((u8 *)&lbl_8048DF88.value) + (temp_r31 * 4))) + 0))));
}

