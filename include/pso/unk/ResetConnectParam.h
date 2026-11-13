#ifndef PSO_UNK_RESETCONNECTPARAM_H
#define PSO_UNK_RESETCONNECTPARAM_H

#include "types.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/text_8042EE4C.h"

extern "C" {
int sprintf(char *, const char *, ...);
void *memset(void *, int, unsigned long);
}

// Clears the connect parameters and fills in their defaults.
inline s32 reset_connect_param(const char *name) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    memset(&lbl_805D7CC0->connect_param, 0, sizeof(SharedMemoryConnectParam));
    lbl_805D7CC0->connect_param_size = 0x674;
    sprintf(lbl_805D7CC4->name, name);
    TAdPlayerLoadGC__sub_8042F108(0);
    TAdTrialModemChkGC__sub_8042F0D4(3);
    set_modem_trial_param(1);
    TAdTrialModemChkGC__sub_8042F080(3);
    set_modem_check_param(3);
    set_modem_flag(1);
    set_modem_check_char(1);
    set_modem_param(5);
    set_modem_check_param_360(0);
    lbl_805D7CC0->flags &= ~SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

#endif
