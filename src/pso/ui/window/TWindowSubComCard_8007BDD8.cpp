#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 clear();
s32 fn_8007B2E0(u8 *ply_guild_card_tag, s32 id);

void TWindowSubComCard::handle_press_a(saddr ply_guild_card_tag, s32 id) {
    clear();
    if ((fn_8007B2E0((u8 *)ply_guild_card_tag, id) != 0) && (TWindowSubComCard::scroll_list(ply_guild_card_tag) == 0)) {
        TWindowSubComCard::select_card_entry(ply_guild_card_tag);
    }
}

}

extern "C" {

s32 init_guild_card_tag__17TWindowSubComCardFi(s32 *);

void TWindowSubComCard::init_and_press_a(s32 id) {
    u8 ply_guild_card_tag[0x84];

    init_guild_card_tag__17TWindowSubComCardFi((s32 *) ply_guild_card_tag);
    TWindowSubComCard::handle_press_a((saddr)((s32 *) ply_guild_card_tag), (s32)id);
}

}
