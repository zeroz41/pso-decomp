#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 get_card_entry__17TWindowSubComCardFi();
s32 scroll_list__17TWindowSubComCardFl();

void TWindowSubComCard::update_press() {
    s32 temp_r31;

    temp_r31 = get_card_entry__17TWindowSubComCardFi();
    if (scroll_list__17TWindowSubComCardFl() == 0) {
        TWindowSubComCard::select_card_entry(temp_r31);
    }
}

}
