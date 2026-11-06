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
