#include "types.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowSubComCard.h"

void TWindowSubComCard::select_card_entry(saddr ply_guild_card_tag) {
    saddr tmp = TWindowSubComCard::get_card_slot(0);
    TWindowSubComCard__sub_8007B1AC((void *)ply_guild_card_tag, (u8 *)tmp, 0x1C);
}
