#include "types.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowSubComCard.h"

void TWindowSubComCard::select_card_entry(s32 arg0) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    TWindowSubComCard__sub_8007B1AC((void *)arg0, (u8 *)tmp, 0x1C);
}
