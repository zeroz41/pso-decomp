#include "types.h"
#include "pso/unk/text_8042EAD4.h"
#include "pso/unk/text_8042EE4C.h"
struct Ctx_8042EBA4 { u8 pad[0x100]; s32 f100; s32 f104; s32 f108; };

typedef struct Ctx_8042ED98 {
    u8 pad[0x8c];
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
