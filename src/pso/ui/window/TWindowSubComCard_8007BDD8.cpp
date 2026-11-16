#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 clear();
s32 fn_8007B2E0(u8 *arg0, s32 id);
s32 scroll_list__17TWindowSubComCardFl(s32);

void TWindowSubComCard::handle_press_a(s32 arg0, s32 id) {
    clear();
    if ((fn_8007B2E0((u8 *)arg0, id) != 0) && (scroll_list__17TWindowSubComCardFl(arg0) == 0)) {
        TWindowSubComCard::select_card_entry(arg0);
    }
}

}

extern "C" {

s32 init_guild_card_tag__17TWindowSubComCardFi(s32 *);

void TWindowSubComCard::init_and_press_a(s32 id) {
    u8 sp8[0x84];

    init_guild_card_tag__17TWindowSubComCardFi((s32 *) sp8);
    TWindowSubComCard::handle_press_a((s32)((s32 *) sp8), (s32)id);
}

}
