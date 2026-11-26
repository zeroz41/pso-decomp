#ifndef PSO_UNK_RESETCONNECTPARAM_H
#define PSO_UNK_RESETCONNECTPARAM_H

#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/unk/SharedMemory.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"


// Clears the connect parameters and fills in their defaults.
inline s32 reset_connect_param(const char *name) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    memset(&shared_memory_block->connect_param, 0, sizeof(SharedMemoryConnectParam));
    shared_memory_block->connect_param_size = 0x674;
    sprintf(shared_memory_connect_param->name, name);
    ntUtlExSetDialType(0);
    TAdTrialModemChkGC__sub_8042F0D4(3);
    set_modem_trial_param(1);
    TAdTrialModemChkGC__sub_8042F080(3);
    set_modem_check_param(3);
    set_modem_flag(1);
    set_modem_check_char(1);
    set_modem_param(5);
    set_modem_check_param_360(0);
    shared_memory_block->flags &= ~SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

#endif
