#include "types.h"
#include "pso/unk/text_8007B370.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 clear();

void TWindowSubComCard::handle_press_b(saddr ply_guild_card_tag, s32 client_id) {
    clear();
    if ((fill_guild_card_from_player((u8 *)ply_guild_card_tag, client_id) != 0) && (TWindowSubComCard::scroll_list(ply_guild_card_tag) == 0)) {
        TWindowSubComCard::select_card_entry(ply_guild_card_tag);
    }
}

}

extern "C" {

s32 init_guild_card_tag__17TWindowSubComCardFi(s32 *);

void TWindowSubComCard::init_and_press_b(s32 client_id) {
    u8 ply_guild_card_tag[0x84];

    init_guild_card_tag__17TWindowSubComCardFi((s32 *) ply_guild_card_tag);
    TWindowSubComCard::handle_press_b((saddr)((s32 *) ply_guild_card_tag), (s32)client_id);
}

}
