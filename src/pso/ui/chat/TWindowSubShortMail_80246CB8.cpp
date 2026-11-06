#include "types.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/ui/chat/TWindowSubShortMail.h"

extern u16 lbl_805D63FC;

s32 is_trade_active(void) {
    return ((u16) lbl_805D63FC >> 3U) & 1;
}

s32 TWindowSubShortMail::is_active() {
    return lbl_805D63FC & 1;
}

s32 is_com_card_active(void) {
    return ((u16) lbl_805D63FC >> 2U) & 1;
}

s32 is_guild_card_receive_active(void) {
    return ((u16) lbl_805D63FC >> 1U) & 1;
}
