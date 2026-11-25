#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/GuildCardEntry.h"


void TWindowSubComCard::update_press() {
    s32 card_entry;

    card_entry = reinterpret_cast<saddr>(TWindowSubComCard::get_card_entry(static_cast<s32>(reinterpret_cast<saddr>(this))));
    if (TWindowSubComCard::scroll_list(card_entry) == 0) {
        TWindowSubComCard::select_card_entry(card_entry);
    }
}

