#include "types.h"
#include "pso/ui/chat/TWindowSubShortMailActiveChecks.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowCtrl.h"


s32 is_trade_active(void) {
    return ((u16) short_mail_flags >> 3U) & 1;
}

s32 TWindowSubShortMail::is_active() {
    return short_mail_flags & 1;
}

s32 is_com_card_active(void) {
    return ((u16) short_mail_flags >> 2U) & 1;
}

s32 is_guild_card_receive_active(void) {
    return ((u16) short_mail_flags >> 1U) & 1;
}
