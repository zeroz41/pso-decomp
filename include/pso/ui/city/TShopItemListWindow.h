#ifndef PSO_UI_CITY_TSHOPITEMLISTWINDOW_H
#define PSO_UI_CITY_TSHOPITEMLISTWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

struct TWindowMenu;

struct TShopItemListWindow : public TShopWindowBase {
    TShopItemListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TShopItemListWindow();
    void prepare_tool_purchase();
    void handle_amount_confirm();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    // Child windows, closed by the destructor: names from the window each one holds.
    uaddr item_list;      // create_item_list_window
    TShopWindowBase *sequence;  // the shop sequence that opened it; messages go to it
    TWindowMenu *confirm_menu;   // two-entry create_window_menu shown once the quantity is confirmed
    uaddr quantity_input; // TWindowInputNumber
    uaddr help_window;    // TWindowHelpItem
    uaddr status_window;  // TWindowSubStatusDisp
    uaddr cost_window;    // create_cost_window
    u32 pad_44;
    s32 item_count;       // rows of shop_items in use
    u32 purchase_step;    // handle_amount_confirm: 0 choosing the amount, 1 the yes / no menu
    u32 purchase_count;   // how many to buy
    s32 last_cursor;      // the row the help, status and cost windows show
    // Each copied shop item stores its meseta price in data2.
    TItemData shop_items[16];
    u8 _pad198[0x28];
    u32 pad_1C0;
    void handle_confirm();
    void update();
    static void handle_tool_list_select(void *p);
    s32 check_purchase_eligibility();
    static void build_item_list(void *p);
};

LAYOUT_ASSERT(TShopItemListWindow_size, sizeof(TShopItemListWindow) == 0x1C4);

LAYOUT_ASSERT(TShopItemListWindow_items_offset, offsetof(TShopItemListWindow, shop_items) == 0x58);

#endif
