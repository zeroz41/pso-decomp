#ifndef PSO_UI_CITY_TSHOPARMORLISTWINDOW_H
#define PSO_UI_CITY_TSHOPARMORLISTWINDOW_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

class TWindowBase;
class TWindowShop;
struct TWindowHelpItem;
struct TWindowCost;

struct TWindowMenu;

struct TShopArmorListWindow : public TShopWindowBase {
    TShopArmorListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TShopArmorListWindow();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    TShopWindowBase *sequence;  // the shop sequence that opened it; messages go to it
    TWindowShop *item_list;     // the counter's stock
    TWindowMenu *choice_menu;   // create_window_menu / create_yes_no_window
    TWindowHelpItem *help_window;
    TWindowBase *extra_window;  // never opened here; the destructor closes it
    TWindowCost *cost_window;   // price of the selected item
    u32 pad_40;
    s32 item_count;           // rows of stock in use
    s32 last_cursor;          // the row the help window shows
    TItemData stock[16];      // the counter's items; data2 holds the price
    u8 pad_18C[0x64];
    s32 can_equip;            // check_purchase_eligibility clears it for a unit
    void (*on_close)(TShopWindowBase *sequence);  // called with sequence when the player leaves
    void update_selection(TItemData *item);
    void handle_equip_offer();
    void handle_buy_confirm();
    void open_menu_window();
    void advance_to_preparation_phase();
    void update();
    void handle_select();
    void handle_selection();
    s32 check_purchase_eligibility();
    void refresh_item_list();
};

LAYOUT_ASSERT(TShopArmorListWindow_size, sizeof(TShopArmorListWindow) == 0x1F8);
LAYOUT_ASSERT(TShopArmorListWindow_choice_menu_offset, offsetof(TShopArmorListWindow, choice_menu) == 0x30);

#endif
