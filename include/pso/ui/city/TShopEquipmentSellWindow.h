#ifndef PSO_UI_CITY_TSHOPEQUIPMENTSELLWINDOW_H
#define PSO_UI_CITY_TSHOPEQUIPMENTSELLWINDOW_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

#include "pso/item/TItemData.h"

struct TItem;
struct TWindowMenu;
class TWindowMenuIconLine;
struct TWindowInputNumber;
struct TWindowQuantity;
struct TWindowHelpItem;
struct TWindowCost;

// An inventory item the shop buys: the item, a copy of its data (data2.price
// is what the shop pays for one) and its inventory slot.
struct TShopSellEntry {
    TItem *item;
    TItemData data;
    s32 index;
};

struct TShopEquipmentSellWindow : public TShopWindowBase {
    TShopEquipmentSellWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player, s32 title_text);
    virtual ~TShopEquipmentSellWindow();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    TShopSellEntry entries[30];
    u32 pad_370;
    s32 entry_count;
    s32 title_text;                     // shop text id of the item list's title
    s32 sell_count;                     // how many of a stacked tool to sell
    s32 cursor;                         // the list cursor kept across a sale
    s32 last_cursor;                    // the entry the help, owned and cost windows show
    TShopWindowBase *sequence;          // the shop sequence that opened it; messages go to it
    TWindowMenuIconLine *item_list;
    TWindowMenu *confirm_menu;          // sell yes / no
    TWindowInputNumber *number_input;   // how many of a stacked tool to sell
    TWindowQuantity *owned_window;      // how many of the entry the player carries
    TWindowHelpItem *help_window;
    TWindowCost *cost_window;
    void (*on_close)(TShopWindowBase *sequence);    // the player left the window
    void (*on_empty)(TShopWindowBase *sequence);    // the player has nothing the shop buys
    void update();
    void handle_sell_confirm();
    void handle_input_window_result();
    void close();
    void handle_selection();
    void build_sell_list();
    static s32 get_item_data_value(uaddr arg0);
};

LAYOUT_ASSERT(TShopSellEntry_size, sizeof(TShopSellEntry) == 0x1C);
LAYOUT_ASSERT(TShopEquipmentSellWindow_size, sizeof(TShopEquipmentSellWindow) == 0x3AC);
LAYOUT_ASSERT(TShopEquipmentSellWindow_entries_offset, offsetof(TShopEquipmentSellWindow, entries) == 0x28);
LAYOUT_ASSERT(TShopEquipmentSellWindow_sequence_offset, offsetof(TShopEquipmentSellWindow, sequence) == 0x388);
LAYOUT_ASSERT(TShopEquipmentSellWindow_confirm_menu_offset, offsetof(TShopEquipmentSellWindow, confirm_menu) == 0x390);
#endif
