#include "types.h"
#include "pso/unk/text_8042EAD4.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/network/TLobby_80429598.h"

struct Ctx_8042EBA4 { u8 pad[0x100]; s32 f100; s32 f104; s32 f108; };

typedef struct Ctx_8042ED98 {
    s8 pad_0; // set by fn_8042EF48
    u8 pad_1[0x8b];
    char name[5][0x100];
} Ctx_8042ED98;

extern "C" {
char *strcpy(char *, const char *);
void LaunchDol(Ctx_8042EBA4 *);
extern char lbl_80480404[];
extern Ctx_8042EBA4 *lbl_805D7CB0;
char *strncpy(char *, const char *, unsigned long);
void *memset(void *, int, unsigned long);
unsigned long strlen(const char *);
extern s32 lbl_805D7CA8;
extern Ctx_8042ED98 *lbl_805D7CB8;
extern u8 *lbl_805D7CC0;
s32 fn_8042E8B8(void);
int sprintf(char *, const char *, ...);
extern char lbl_80480240[];
extern u32 lbl_805D7CB4;
extern const s32 lbl_805E11F0;
extern u8 *lbl_805D7CC4;
extern u8 *lbl_805D7CBC;

#pragma push
#pragma optimize_for_size off
s32 fn_8042EAD4(u8 *arg0, u32 arg1) {
    u8 *dst;
    u32 i;
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    if (arg1 > 0x800U) {
        return -2;
    }
    dst = lbl_805D7CC0 + 0x6020;
    for (i = arg1; i != 0; i--) {
        *dst++ = *arg0++;
    }
    *(u32 *)((s8 *)lbl_805D7CC0 + 0x14) = arg1;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 1);
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size off
void fn_8042EBA4(s32 arg0, s32 arg1) {
    strcpy((char *)lbl_805D7CB0, lbl_80480404);
    lbl_805D7CB0->f100 = arg1;
    lbl_805D7CB0->f104 = arg0;
    lbl_805D7CB0->f108 = 0x8000;
    LaunchDol(lbl_805D7CB0);
}
#pragma pop

#pragma push
#pragma optimize_for_size off
void TAdTrialModemChkGC__sub_8042EC14(void) {
    u8 *p;
    char *msgs = lbl_80480240;
    lbl_805D7CB4 = lbl_805E11F0;
    if ((s32) lbl_805D7CA8 == 0) {
        lbl_805D7CB0 = (Ctx_8042EBA4 *) fn_8042E8B8();
        p = (u8 *) *(Ctx_8042EBA4 *volatile *) &lbl_805D7CB0 + 0x110;
        lbl_805D7CA8 = 1;
        lbl_805D7CC0 = p;
        lbl_805D7CC4 = p + 0x7020;
        lbl_805D7CBC = p + 0x6820;
        lbl_805D7CB8 = (Ctx_8042ED98 *) (p + 0x7820);
        if (*(u32 *) p == 0x53454741) {
            return;
        }
        memset(p, 0, 0x8000);
        *(u32 *) lbl_805D7CC0 = 0x53454741;
        *(u32 *)((s8 *) lbl_805D7CC0 + 4) = 0x40;
        if ((s32) lbl_805D7CA8 != 0) {
            memset(lbl_805D7CC0 + 0x7020, 0, 0x800);
            *(s32 *)((s8 *) lbl_805D7CC0 + 0x1C) = 0x674;
            sprintf((char *) (lbl_805D7CC4 + 4), msgs + 0x30);
            TAdPlayerLoadGC__sub_8042F108(0);
            TAdTrialModemChkGC__sub_8042F0D4(3);
            set_modem_trial_param(1);
            TAdTrialModemChkGC__sub_8042F080(3);
            set_modem_check_param(3);
            set_modem_flag(1);
            set_modem_check_char(1);
            set_modem_param(5);
            set_modem_check_param_360(0);
            *(s32 *)((s8 *) lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *) lbl_805D7CC0 + 4) & 0xFFFFF7FF);
        }
        fn_8042ED98(0, msgs + 0x1D0);
        fn_8042ED98(1, msgs + 0x220);
        fn_8042ED98(2, msgs + 0x25C);
        fn_8042ED98(3, msgs + 0x2E0);
        fn_8042ED98(4, msgs + 0x324);
    }
}
#pragma pop

#pragma push
#pragma optimize_for_size off
s32 fn_8042ED98(s32 arg0, const char *arg1) {
    s32 ret = 0;
    if (lbl_805D7CA8 == 0) {
        return -1;
    }
    if (arg0 < 0 || arg0 > 4) {
        return -2;
    }
    memset(lbl_805D7CB8->name[arg0], 0, 0x100);
    strncpy(lbl_805D7CB8->name[arg0], arg1, 0xFF);
    if (strlen(arg1) >= 0x100) {
        ret = -2;
    }
    return ret;
}
#pragma pop

}

extern "C" {
s32 EXIGetType(int, int, void *);
u32 lbl_805D7CC8;


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
    lbl_805D7CB8->pad_0 = arg0;
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) | 0x1000);
    return 0;
}
}


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
