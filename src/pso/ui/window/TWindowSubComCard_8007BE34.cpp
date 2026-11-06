#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 init_guild_card_tag__17TWindowSubComCardFi(s32 *);

void TWindowSubComCard::init_and_press_a(s32 id) {
    u8 sp8[0x84];

    init_guild_card_tag__17TWindowSubComCardFi((s32 *) sp8);
    TWindowSubComCard::handle_press_a((s32)((s32 *) sp8), (s32)id);
}

}
