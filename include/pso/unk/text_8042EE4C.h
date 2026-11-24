#ifndef PSO_UNK_TEXT_8042EE4C_H
#define PSO_UNK_TEXT_8042EE4C_H

#include "types.h"

s32 fn_8042F108(s8 arg0);

extern "C" {
s32 TAdTrialModemChkGC__sub_8042F080(s16 arg0);
s32 TAdTrialModemChkGC__sub_8042F0D4(s8 arg0);
s32 TLobby__sub_8042EE4C(s32 *arg0);
s32 fn_8042EF48(s8 arg0);
}
s32 set_modem_check_char(s8 arg0);
s32 set_modem_check_param(s32 arg0);
s32 set_modem_check_param_360(s8 arg0);
s32 set_modem_flag(s8 arg0);
s32 set_modem_param(s16 arg0);
s32 set_modem_trial_param(s16 arg0);

#endif
