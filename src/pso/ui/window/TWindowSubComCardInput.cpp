#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/ui/window/TWindowSubComCardEntries.h"

s32 TWindowSubComCard::init_card() {
    return has_free_card_slot(reinterpret_cast<GuildCardEntry *>(TWindowSubComCard::get_card_slot(0)), 0x1C);
}

void TWindowSubComCard::remove_entry(s32 index) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    remove_guild_card_entry(index, reinterpret_cast<GuildCardEntry *>(tmp), 0x1C);
}

s32 TWindowSubComCard::scroll_list(s32 ply_guild_card_tag) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    return update_matching_card_slot(reinterpret_cast<GuildCardSlotBase *>(ply_guild_card_tag), reinterpret_cast<GuildCardSlotBase *>(tmp), 0x1C);
}

void TWindowSubComCard::handle_press_a(saddr ply_guild_card_tag, s32 id) {
    clear((void *)ply_guild_card_tag);
    if ((fill_guild_card_from_short_mail(reinterpret_cast<GuildCardEntry *>(ply_guild_card_tag), id) != 0) && (TWindowSubComCard::scroll_list(ply_guild_card_tag) == 0)) {
        TWindowSubComCard::select_card_entry(ply_guild_card_tag);
    }
}

void TWindowSubComCard::init_and_press_a(s32 id) {
    GuildCardEntry card;

    TWindowSubComCard::handle_press_a(reinterpret_cast<saddr>(&card), id);
}

void TWindowSubComCard::handle_press_b(saddr ply_guild_card_tag, s32 client_id) {
    clear((void *)ply_guild_card_tag);
    if ((fill_guild_card_from_player((GuildCardEntry *)ply_guild_card_tag, client_id) != 0) && (TWindowSubComCard::scroll_list(ply_guild_card_tag) == 0)) {
        TWindowSubComCard::select_card_entry(ply_guild_card_tag);
    }
}

void TWindowSubComCard::init_and_press_b(s32 client_id) {
    GuildCardEntry card;

    TWindowSubComCard::handle_press_b(reinterpret_cast<saddr>(&card), client_id);
}

void TWindowSubComCard::update_press(s32 index) {
    saddr card_entry = reinterpret_cast<saddr>(TWindowSubComCard::get_card_entry(index));
    if (TWindowSubComCard::scroll_list(card_entry) == 0) {
        TWindowSubComCard::select_card_entry(card_entry);
    }
}

void TWindowSubComCard::select_card_entry(saddr ply_guild_card_tag) {
    saddr slots = TWindowSubComCard::get_card_slot(0);
    replace_matching_card(reinterpret_cast<GuildCardSlotBase *>(ply_guild_card_tag), reinterpret_cast<GuildCardSlotBase *>(slots), 0x1C);
}
