#ifndef PSO_UI_CITY_TSHOPITEMTECSEQUENCE_H
#define PSO_UI_CITY_TSHOPITEMTECSEQUENCE_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TObjPlayer;
class TWindowBase;
struct TWindowMenu;
struct TShopJudgmentItemWindow;
struct TItemData;
class TShopWindowBase;

struct TShopItemTecSequence : public TShopSequence {
    static s32 slot_table[4];
    TShopItemTecSequence(TObject *parent, TObjPlayer *player);
    virtual ~TShopItemTecSequence();
    virtual void update_state();
    TWindowBase *meseta_window;     // 0x2C: create_meseta_window
    TWindowMenu *choice_menu;       // 0x30: the buy/sell create_window_menu
    TObject *counter_camera;        // 0x34: set_service_counter_camera
    void handle_select();
    void close_if_done();
    void open_sell_window();
    void open_item_list_window();
    void update_buy_sell_choice();
    void open_greeting();
    // Window callbacks: the player left the window / has nothing the shop buys.
    static void close(TShopWindowBase *window);
    static void select_and_advance(TShopWindowBase *window);
};

LAYOUT_ASSERT(TShopItemTecSequence_size, sizeof(TShopItemTecSequence) == 0x38);
LAYOUT_ASSERT(TShopItemTecSequence_choice_menu_offset, offsetof(TShopItemTecSequence, choice_menu) == 0x30);

extern "C" {
int get_shop_tool_stock_count(int a0);
void TShopItemTecSequence__sub_80220538(void);
void TShopItemTecSequence__sub_80220560(void);
}
void set_judgment_target_flag(TShopJudgmentItemWindow *window, TItemData *item);

#endif
