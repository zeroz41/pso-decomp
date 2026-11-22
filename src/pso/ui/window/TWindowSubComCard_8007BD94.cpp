#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 TWindowSubComCard__sub_8007B0D0(s32, s32, s32);

s32 TWindowSubComCard::scroll_list(s32 ply_guild_card_tag) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    return TWindowSubComCard__sub_8007B0D0(ply_guild_card_tag, tmp, 0x1C);
}

}
