#include "types.h"
#include "pso/ui/city/TShopGetItemWindow_8021EEE4.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/ui/hud/TRaderMapCore.h"

void clear_shop_armor_flags(void);
void clear_shop_tool_flags(void);
void clear_shop_weapon_flags(void);
extern s32 local_client_id;
extern s32 game_difficulty_selection;
s32 lbl_805D6238;
s32 shop_world_player_level;
s32 shop_difficulty_tier;
s32 lbl_805D6244;
s16 TWindowMenuIconLine::get_cursor_index() { return cursor; }

void calc_item_count(TObjPlayer *player, s32 *count) {
    s32 level;
    TObjPlayer *local_player;

    level = 1;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        level = player->get_actor_level_index() + 1;
    } else {
        local_player = get_player_by_client_id(local_client_id);
        if (local_player != NULL) {
            level = local_player->get_actor_level_index() + 1;
        }
    }
    if (level < 1) {
        level = 1;
    }
    if (level > 0xC7) {
        level = 0xC7;
    }
    *count = level;
}
#pragma push
#pragma opt_dead_code off
void init_shop_world_context(void) {
    s32 temp_r3_2;
    s32 section_id;
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        shop_world_player_level = player->get_actor_level_index();
        shop_world_player_level++;
    } else {
        shop_world_player_level = 1;
    }
    if ((s32) shop_world_player_level < 1) {
        shop_world_player_level = 1;
    }
    if ((s32) shop_world_player_level > 0xC7) {
        shop_world_player_level = 0xC7;
    }
    section_id = leader_selection.get_section_id();
    lbl_805D6238 = section_id;
    if (section_id < 0) {
        lbl_805D6238 = 0;
    }
    if ((s32) lbl_805D6238 > 9) {
        lbl_805D6238 = 9;
    }
    shop_difficulty_tier = game_difficulty_selection;
    if ((s32) game_difficulty_selection < 0) {
        shop_difficulty_tier = 0;
    }
    if ((s32) shop_difficulty_tier > 3) {
        shop_difficulty_tier = 3;
    }
    clear_shop_weapon_flags();
    clear_shop_armor_flags();
    clear_shop_tool_flags();
    lbl_805D6244 = 0;
}
#pragma pop
