#ifndef PSO_UNK_TEXT_8042EE4C_H
#define PSO_UNK_TEXT_8042EE4C_H

#include "types.h"

s32 ntUtlExSetDialType(s8 value);

extern "C" {
s32 TAdTrialModemChkGC__sub_8042F080(s16 value);
s32 TAdTrialModemChkGC__sub_8042F0D4(s8 value);
}
s32 get_network_adapter_type(s32 *out_type);
extern "C" {
s32 fn_8042EF48(s8 value);
}
s32 set_modem_check_char(s8 value);
s32 set_modem_check_param(s32 value);
s32 set_modem_check_param_360(s8 value);
s32 set_modem_flag(s8 value);
s32 set_modem_param(s16 value);
s32 set_modem_trial_param(s16 value);

#endif
