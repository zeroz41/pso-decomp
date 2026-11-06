#include "types.h"
#include "pso/unk/text_8007B370.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 clear();
s32 scroll_list__17TWindowSubComCardFl(s32);

void TWindowSubComCard::handle_press_b(s32 ply_guild_card_tag, s32 arg1) {
    clear();
    if ((fill_guild_card_from_player((u8 *)ply_guild_card_tag, arg1) != 0) && (scroll_list__17TWindowSubComCardFl(ply_guild_card_tag) == 0)) {
        TWindowSubComCard::select_card_entry(ply_guild_card_tag);
    }
}

}
