#ifndef PSO_UI_CITY_TSHOPARMORLISTWINDOW_H
#define PSO_UI_CITY_TSHOPARMORLISTWINDOW_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

class TWindowBase;

struct TWindowMenu;

struct TShopArmorListWindow : public TShopWindowBase {
    TShopArmorListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TShopArmorListWindow();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    TShopWindowBase *sequence;  // the shop sequence that opened it; messages go to it
    TWindowBase *item_list;   // 0x2C: create_item_list_window
    TWindowMenu *choice_menu;          // 0x30: create_window_menu / create_yes_no_window
    TWindowBase *help_window; // 0x34: a TWindowHelpItem
    uaddr m_38;
    TWindowBase *cost_window; // 0x3C: create_cost_window
    u32 pad_40;
    s32 item_count;           // 0x44: rows of stock in use
    s32 last_cursor;          // 0x48: the row the help window shows
    TItemData stock[16];      // 0x4C: the counter's items; data2 holds the price
    u8 pad_18C[0x64];
    u32 can_equip;            // 0x1F0: check_purchase_eligibility clears it for a unit
    void (*on_close)(TShopWindowBase *sequence);  // 0x1F4: called with sequence when the player leaves
    void update_selection(void *arg1);
    void handle_equip_offer();
    void handle_buy_confirm();
    void open_menu_window();
    void advance_to_preparation_phase();
    void update();
    void handle_select();
    void handle_selection();
    s32 check_purchase_eligibility();
    static void refresh_item_list(void *p);
};

LAYOUT_ASSERT(TShopArmorListWindow_size, sizeof(TShopArmorListWindow) == 0x1F8);
LAYOUT_ASSERT(TShopArmorListWindow_choice_menu_offset, offsetof(TShopArmorListWindow, choice_menu) == 0x30);

#endif
