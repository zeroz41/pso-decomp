#include "types.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_80222C28.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/network/TLobby.h"
#include "pso/ui/Language.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/city/TShopGetItemWindow.h"

#pragma readonly_strings on


const char *text_shop_rel_name_table[6] = { "TextShopJapanese.rel", "TextShopEnglish.rel", "TextShopGerman.rel", "TextShopFrench.rel", "TextShopSpanish.rel", NULL };
const char *quest_and_shop_error_text = "Error";
// Text groups of the loaded TextShop*.rel: (*shop_text_groups)[group][index] is a string.
const char ****shop_text_groups;
// Text group per appraisal kind (shop_section_id indexes it), then per game play mode.
static const s32 appraisal_text_group_table[10] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
static const s32 guild_text_play_mode_table[4] = {1, 2, 3, 0};

saddr get_quest_list_text(s32 group, s32 index) {
    if (shop_text_groups != NULL) {
        return (saddr)(*shop_text_groups)[group][index];
    }
    return (saddr)quest_and_shop_error_text;
}

saddr get_guild_text(s32 index) {
    s32 group;
    if (shop_text_groups != NULL) {
        group = guild_text_play_mode_table[get_game_play_mode()];
        return (saddr)(*shop_text_groups)[group][index];
    }
    return (saddr)quest_and_shop_error_text;
}

saddr get_appraisal_text(s32 index) {
    if (shop_text_groups != NULL) {
        return (saddr)(*shop_text_groups)[appraisal_text_group_table[shop_section_id]][index];
    }
    return (saddr)quest_and_shop_error_text;
}

saddr get_shop_text(s32 index) {
    if (shop_text_groups != NULL) {
        return (saddr)(**shop_text_groups)[index];
    }
    return (saddr)quest_and_shop_error_text;
}


void TLobby::free_singleton() {
    if ((uaddr) shop_text_groups != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)shop_text_groups));
        shop_text_groups = 0U;
    }
}
void TLobby::create_named_lobby_object() {
    if (((s32) shop_section_id < 0) || ((s32) shop_section_id > 9)) {
        shop_section_id = 0;
    }
    shop_text_groups = static_cast<const char ****>(create_named_object(text_shop_rel_name_table[current_language]));
}
#pragma push
#pragma scheduling off
u16 get_client_split_screen_slot(u16 client) {
    return is_split_screen() == 1 ? client : (u16)0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma pop
