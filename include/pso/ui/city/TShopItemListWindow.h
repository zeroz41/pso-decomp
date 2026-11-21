#ifndef PSO_UI_CITY_TSHOPITEMLISTWINDOW_H
#define PSO_UI_CITY_TSHOPITEMLISTWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

struct TWindowMenu;

struct TShopItemListWindow : public TShopWindowBase {
    TShopItemListWindow(saddr parent, saddr sequence, s32 player);
    virtual ~TShopItemListWindow();
    void prepare_tool_purchase();
    void handle_amount_confirm();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void vfunc_6(s32 id, s32 flags);
    u8 _pad1C[0x4];
    u32 m_20;
    uaddr m_24;
    // Child windows, closed by the destructor: names from the window each one holds.
    uaddr item_list;      // create_item_list_window
    TShopWindowBase *sequence;  // the shop sequence that opened it; messages go to it
    TWindowMenu *confirm_menu;   // two-entry create_window_menu shown once the quantity is confirmed
    uaddr quantity_input; // TWindowInputNumber
    uaddr help_window;    // TWindowHelpItem
    uaddr status_window;  // TWindowSubStatusDisp
    uaddr cost_window;    // create_cost_window
    u32 m_44;
    u8 _pad48[0x4];
    u32 m_4c;
    u32 m_50;
    u32 m_54;
    // Each copied shop item stores its meseta price in data2.
    TItemData shop_items[16];
    u8 _pad198[0x28];
    u32 m_1c0;
    void handle_confirm();
    void update();
    static void handle_tool_list_select(void *p);
    s32 check_purchase_eligibility();
    static void build_item_list(void *p);
};

LAYOUT_ASSERT(TShopItemListWindow_size, sizeof(TShopItemListWindow) == 0x1C4);

LAYOUT_ASSERT(TShopItemListWindow_items_offset, offsetof(TShopItemListWindow, shop_items) == 0x58);

#endif
