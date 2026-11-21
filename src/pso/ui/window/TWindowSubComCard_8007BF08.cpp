#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 get_card_entry__17TWindowSubComCardFi();

void TWindowSubComCard::update_press() {
    s32 temp_r31;

    temp_r31 = get_card_entry__17TWindowSubComCardFi();
    if (TWindowSubComCard::scroll_list(temp_r31) == 0) {
        TWindowSubComCard::select_card_entry(temp_r31);
    }
}

}
