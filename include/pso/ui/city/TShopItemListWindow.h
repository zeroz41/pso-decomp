#ifndef PSO_UI_CITY_TSHOPITEMLISTWINDOW_H
#define PSO_UI_CITY_TSHOPITEMLISTWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

struct TWindowMenu;
class TWindowShop;
struct TWindowInputNumber;
struct TWindowHelpItem;
struct TWindowQuantity;
struct TWindowCost;

struct TShopItemListWindow : public TShopWindowBase {
    TShopItemListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TShopItemListWindow();
    void prepare_tool_purchase();
    void handle_amount_confirm();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    // Child windows, closed by the destructor.
    TWindowShop *item_list;           // the shop's tool stock
    TShopWindowBase *sequence;        // the shop sequence that opened it; messages go to it
    TWindowMenu *confirm_menu;        // two-entry create_window_menu shown once the quantity is confirmed
    TWindowInputNumber *quantity_input;
    TWindowHelpItem *help_window;     // description of the selected item
    TWindowQuantity *status_window;   // how many of the selected item the player carries
    TWindowCost *cost_window;         // price of the selected item
    u32 pad_44;
    s32 item_count;       // rows of shop_items in use
    u32 purchase_step;    // handle_amount_confirm: 0 choosing the amount, 1 the yes / no menu
    u32 purchase_count;   // how many to buy
    s32 last_cursor;      // the row the help, status and cost windows show
    // Each copied shop item stores its meseta price in data2.
    TItemData shop_items[16];
    u8 pad_198[0x28];
    void (*on_close)(TShopWindowBase *sequence);  // called with sequence when the player leaves
    void handle_confirm();
    void update();
    void handle_tool_list_select();
    s32 check_purchase_eligibility();
    void build_item_list();
};

LAYOUT_ASSERT(TShopItemListWindow_size, sizeof(TShopItemListWindow) == 0x1C4);

LAYOUT_ASSERT(TShopItemListWindow_items_offset, offsetof(TShopItemListWindow, shop_items) == 0x58);

#endif
