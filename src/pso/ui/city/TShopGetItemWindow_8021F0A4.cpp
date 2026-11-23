#include "types.h"
#include "pso/item/shop/ShopWeaponStock.h"
#include "pso/ui/city/TShopGetItemWindow_8021F0A4.h"
#include "pso/unk/text_8020E700.h"
#include "pso/unk/text_80223B98.h"
#include "pso/ui/font/TFontSmallTask.h"

extern s32 game_difficulty_selection;
extern s32 lbl_805D6238;
extern s32 shop_difficulty_tier;
extern s32 lbl_805D6244;

void reset_shop_stock_and_params(void) {
    s32 section_id;

    clear_shop_weapon_flags();
    clear_shop_armor_flags();
    clear_shop_tool_flags();
    lbl_805D6244 = 0;
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
}
