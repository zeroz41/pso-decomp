#ifndef PSO_UI_CITY_TSHOPITEMLISTWINDOW_H
#define PSO_UI_CITY_TSHOPITEMLISTWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TShopItemListWindow : public TShopWindowBase {
    TShopItemListWindow(s32 parent, s32, s32);
    virtual ~TShopItemListWindow();
    void prepare_tool_purchase();
    void handle_amount_confirm();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void vfunc_6();
    u8 _pad1C[0x4];
    u32 m_20;
    u32 m_24;
    // Child windows, closed by the destructor: names from the window each one holds.
    u32 item_list;      // create_item_list_window
    u32 m_2c;
    u32 confirm_menu;   // two-entry create_window_menu shown once the quantity is confirmed
    u32 quantity_input; // TWindowInputNumber
    u32 help_window;    // TWindowHelpItem
    u32 status_window;  // TWindowSubStatusDisp
    u32 cost_window;    // create_cost_window
    u32 m_44;
    u8 _pad48[0x4];
    u32 m_4c;
    u32 m_50;
    u32 m_54;
    u8 _pad58[0x168];
    u32 m_1c0;
    s32 handle_confirm();
    s32 update();
    static s32 handle_tool_list_select(void *p);
    s32 check_purchase_eligibility();
    static void build_item_list(void *p);
};

typedef char TShopItemListWindow_size[sizeof(TShopItemListWindow) == 0x1C4 ? 1 : -1];

#endif
