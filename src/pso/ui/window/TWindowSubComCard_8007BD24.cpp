#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowGetComCard.h"

extern "C" {

s32 TWindowSubComCard__sub_8007B010(s32, s32);

s32 TWindowSubComCard::init_card() {
    return TWindowSubComCard__sub_8007B010(TWindowSubComCard::get_card_slot(0), 0x1C);
}

void TWindowSubComCard::remove_entry(s32 index) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    TWindowGetComCard::remove_entry(index, reinterpret_cast<GuildCardEntry *>(tmp), 0x1C);
}

}
