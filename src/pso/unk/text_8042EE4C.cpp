#include "types.h"
#include "pso/unk/text_8042EE4C.h"

extern "C" {
u32 exi_read_status_byte__6TLobbyFv();
s32 EXIGetType(int, int, void *);
u32 lbl_805D7CC8;

extern s32 lbl_805D7CA8;
extern s8 *lbl_805D7CB8;
extern u8 *lbl_805D7CC0;

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
            if (exi_read_status_byte__6TLobbyFv() == 0U) {
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
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x1000);
    return 0;
}
}

extern u8 *lbl_805D7CC4;

s32 set_modem_check_param_360(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *(s8 *)((s8 *)lbl_805D7CC4 + 0x360) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}

s32 set_modem_param(s16 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *(s16 *)((s8 *)lbl_805D7CC4 + 0x23E) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}

s32 set_modem_check_char(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *(s8 *)((s8 *)lbl_805D7CC4 + 0x23D) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}

s32 set_modem_flag(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *(s8 *)((s8 *)lbl_805D7CC4 + 0x23C) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}

s32 set_modem_check_param(s32 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *(s32 *)((s8 *)lbl_805D7CC4 + 0xF4) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}

s32 TAdTrialModemChkGC__sub_8042F080(s16 arg0) {
    *(s16 *)((s8 *)lbl_805D7CC4 + 0x1C2) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}

s32 set_modem_trial_param(s16 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *(s16 *)((s8 *)lbl_805D7CC4 + 0x1C0) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}

s32 TAdTrialModemChkGC__sub_8042F0D4(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *(s8 *)((s8 *)lbl_805D7CC4 + 0x13D) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}

s32 TAdPlayerLoadGC__sub_8042F108(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    *(s8 *)((s8 *)lbl_805D7CC4 + 0x13C) = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x800);
    return 0;
}
