#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 get_card_entry__17TWindowSubComCardFi();

void TWindowSubComCard::update_press() {
    s32 ply_guild_card_tag;

    ply_guild_card_tag = get_card_entry__17TWindowSubComCardFi();
    if (TWindowSubComCard::scroll_list(ply_guild_card_tag) == 0) {
        TWindowSubComCard::select_card_entry(ply_guild_card_tag);
    }
}

}
