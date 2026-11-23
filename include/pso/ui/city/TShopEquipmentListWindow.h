#ifndef PSO_UI_CITY_TSHOPEQUIPMENTLISTWINDOW_H
#define PSO_UI_CITY_TSHOPEQUIPMENTLISTWINDOW_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

struct TWindowMenu;
class TWindowMenuIconLine;
struct TWindowHelpItem;
struct TWindowCost;
class TWindowBase;

struct TShopEquipmentListWindow : public TShopWindowBase {
    TShopEquipmentListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TShopEquipmentListWindow();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    TShopWindowBase *sequence;  // the shop sequence that opened it; messages go to it
    TWindowMenu *confirm_menu;          // buy / cancel, then the equip yes / no
    TWindowMenuIconLine *item_list;     // the shop's stock
    TWindowHelpItem *help_window;       // describes the item under the cursor
    TWindowBase *pad_38;
    TWindowCost *cost_window;           // the price of the item under the cursor
    u32 pad_40;
    s32 item_count;
    s32 last_cursor;                    // the cursor the help and cost windows show
    s32 can_equip;                      // check_purchase_eligibility: the player can equip it
    TItemData stock[16];                // data2.price is each item's price
    void (*on_close)(TShopWindowBase *sequence);
    void update_list(TItemData *item);
    void handle_equip_offer();
    void handle_buy_confirm();
    void open_menu_window();
    void get_list_item8();
    void handle_confirm();
    void handle_select();
    void handle_selection();
    s32 check_purchase_eligibility();
    void create_buy_list_windows();
};

LAYOUT_ASSERT(TShopEquipmentListWindow_size, sizeof(TShopEquipmentListWindow) == 0x194);
// --- C functions defined in TShopEquipmentListWindow.cpp ---
extern "C" {
int TShopEquipmentListWindow__sub_8021C85C(int a0);
void *__dt__24TShopEquipmentListWindowFv(TShopEquipmentListWindow *arg0, s16 arg1);
}
// --- end of C functions

LAYOUT_ASSERT(TShopEquipmentListWindow_stock_offset, offsetof(TShopEquipmentListWindow, stock) == 0x50);

#endif
