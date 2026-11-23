#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/GuildCardEntry.h"

extern "C" {

void TWindowSubComCard::update_press() {
    s32 temp_r31;

    temp_r31 = reinterpret_cast<saddr>(TWindowSubComCard::get_card_entry(static_cast<s32>(reinterpret_cast<saddr>(this))));
    if (TWindowSubComCard::scroll_list(temp_r31) == 0) {
        TWindowSubComCard::select_card_entry(temp_r31);
    }
}

}
