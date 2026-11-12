#include "types.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/network/TLobby_80429598.h"

extern "C" {
s32 EXIGetType(int, int, void *);
u32 lbl_805D7CC8;

extern s8 *lbl_805D7CB8;

s32 TLobby__sub_8042EE4C(s32 *arg0) {
    s32 sp8;
    if ((u32) lbl_805D7CC8 == 2U) {
        *arg0 = 2;
        goto block_18;
    }
    if ((u32) lbl_805D7CC8 == 5U) {
        *arg0 = 5;
        goto block_18;
    }
    if (EXIGetType(0, 2, &sp8) != 0) {
        switch (sp8) {
        case -1:
            *arg0 = 0;
            break;
        case 33685504:
            *arg0 = 2;
            lbl_805D7CC8 = 2U;
            break;
        case 67240448:
            if (exi_read_status_byte() == 0U) {
                *arg0 = 5;
                lbl_805D7CC8 = 5U;
            } else {
                *arg0 = 1;
            }
            break;
        default:
            *arg0 = 1;
            break;
        }
    } else {
        return -5;
    }
block_18:
    return 0;
}

s32 fn_8042EF48(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *lbl_805D7CB8 = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_DISC_MESSAGES_SET;
    return 0;
}
}

s32 set_modem_check_param_360(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->check_param_360 = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_param(s16 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->modem_param = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_check_char(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->check_char = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_flag(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->modem_flag = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_check_param(s32 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->check_param = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 TAdTrialModemChkGC__sub_8042F080(s16 arg0) {
    lbl_805D7CC4->unk_1C2 = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_trial_param(s16 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->trial_param = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 TAdTrialModemChkGC__sub_8042F0D4(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->unk_13D = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 TAdPlayerLoadGC__sub_8042F108(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->unk_13C = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}
