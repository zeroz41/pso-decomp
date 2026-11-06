#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 init_guild_card_tag__17TWindowSubComCardFi(s32 *);

void TWindowSubComCard::init_and_press_b(s32 arg0) {
    u8 ply_guild_card_tag[0x84];

    init_guild_card_tag__17TWindowSubComCardFi((s32 *) ply_guild_card_tag);
    TWindowSubComCard::handle_press_b((s32)((s32 *) ply_guild_card_tag), (s32)arg0);
}

}
