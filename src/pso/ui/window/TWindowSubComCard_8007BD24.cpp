#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"

extern "C" {
s32 TWindowSubComCard__sub_8007B010(s32, s32);
s32 TWindowSubComCard__sub_8007B0D0(s32, s32, s32);
}

s32 TWindowSubComCard::init_card() {
    return TWindowSubComCard__sub_8007B010(TWindowSubComCard::get_card_slot(0), 0x1C);
}

void TWindowSubComCard::remove_entry(s32 index) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    TWindowGetComCard::remove_entry(index, reinterpret_cast<GuildCardEntry *>(tmp), 0x1C);
}

s32 TWindowSubComCard::scroll_list(s32 ply_guild_card_tag) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    return TWindowSubComCard__sub_8007B0D0(ply_guild_card_tag, tmp, 0x1C);
}

void TWindowSubComCard::handle_press_a(saddr ply_guild_card_tag, s32 id) {
    clear((void *)ply_guild_card_tag);
    if ((fn_8007B2E0((u8 *)ply_guild_card_tag, id) != 0) && (TWindowSubComCard::scroll_list(ply_guild_card_tag) == 0)) {
        TWindowSubComCard::select_card_entry(ply_guild_card_tag);
    }
}

void TWindowSubComCard::init_and_press_a(s32 id) {
    u8 ply_guild_card_tag[0x84];

    init_guild_card_tag__17TWindowSubComCardFi((saddr)ply_guild_card_tag);
    TWindowSubComCard::handle_press_a((saddr)((s32 *)ply_guild_card_tag), id);
}

void TWindowSubComCard::handle_press_b(saddr ply_guild_card_tag, s32 client_id) {
    clear((void *)ply_guild_card_tag);
    if ((fill_guild_card_from_player((u8 *)ply_guild_card_tag, client_id) != 0) && (TWindowSubComCard::scroll_list(ply_guild_card_tag) == 0)) {
        TWindowSubComCard::select_card_entry(ply_guild_card_tag);
    }
}

void TWindowSubComCard::init_and_press_b(s32 client_id) {
    u8 ply_guild_card_tag[0x84];

    init_guild_card_tag__17TWindowSubComCardFi((saddr)ply_guild_card_tag);
    TWindowSubComCard::handle_press_b((saddr)((s32 *)ply_guild_card_tag), client_id);
}

void TWindowSubComCard::update_press() {
    saddr entry = reinterpret_cast<saddr>(TWindowSubComCard::get_card_entry(reinterpret_cast<saddr>(this)));
    if (TWindowSubComCard::scroll_list(entry) == 0) {
        TWindowSubComCard::select_card_entry(entry);
    }
}

void TWindowSubComCard::select_card_entry(saddr ply_guild_card_tag) {
    saddr slots = TWindowSubComCard::get_card_slot(0);
    TWindowSubComCard__sub_8007B1AC((void *)ply_guild_card_tag, (u8 *)slots, 0x1C);
}
