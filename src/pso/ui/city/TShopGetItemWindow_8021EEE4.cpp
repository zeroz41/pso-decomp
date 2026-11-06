#include "types.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/ui/hud/TRaderMapCore.h"

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define VA virtual void CAT(f,__LINE__)();
struct Base_8021EEEC_8021EEE4 { char pad[0x18]; };
struct VObj_8021EEEC_8021EEE4 : Base_8021EEEC_8021EEE4 {
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
    virtual s32 m14();
};

struct ShopPlayerHeader { char taskHeader[0x18]; };

struct ShopPlayerLevel : ShopPlayerHeader {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual void reserved11();
    virtual void reserved12();
    virtual void reserved13();
    virtual s32 levelIndex();
};

extern "C" {
void *get_player_by_client_id(s32);
}
void clear_shop_armor_flags(void);
void clear_shop_tool_flags(void);
void clear_shop_weapon_flags(void);
extern s32 TLobby__data_805011D8[];
extern s32 local_client_id;
extern s32 game_difficulty_selection;
extern s32 lbl_805D6238;
extern s32 shop_world_player_level;
extern s32 shop_difficulty_tier;
extern s32 lbl_805D6244;
void init_shop_world_context(void);

s16 TShopGetItemWindow::get_cursor_index() { return *(s16*)((char*)this + 0x74); }

void TShopGetItemWindow::calc_item_count(s32 *arg1) {
    s32 var_r31;
    void *player;

    var_r31 = 1;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        var_r31 = ((VObj_8021EEEC_8021EEE4 *)this)->m14() + 1;
    } else {
        player = get_player_by_client_id(local_client_id);
        if (player != NULL) {
            var_r31 = ((VObj_8021EEEC_8021EEE4 *)player)->m14() + 1;
        }
    }
    if (var_r31 < 1) {
        var_r31 = 1;
    }
    if (var_r31 > 0xC7) {
        var_r31 = 0xC7;
    }
    *arg1 = var_r31;
}
#pragma push
#pragma opt_dead_code off
void init_shop_world_context(void) {
    s32 temp_r3_2;
    s32 temp_r3_3;
    void *player;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        shop_world_player_level = ((ShopPlayerLevel*)player)->levelIndex();
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
    temp_r3_3 = ((TFontSmallTask *)TLobby__data_805011D8)->get_task_id();
    lbl_805D6238 = temp_r3_3;
    if (temp_r3_3 < 0) {
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
