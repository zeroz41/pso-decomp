#ifndef PSO_UI_CITY_TSHOPKEEPITEMWINDOW_H
#define PSO_UI_CITY_TSHOPKEEPITEMWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

struct TItem;
struct TObjPlayer;
struct TWindowMenu;
class TWindowMenuIconLine;
struct TWindowInputNumber;
struct TWindowHelpItem;

// One row of the deposit list: the inventory item, a copy of its data and
// its inventory index.
struct TShopKeepItemEntry {
    TItem *item;
    TItemData data;
    s32 inventory_index;
};

struct TShopKeepItemWindow : public TShopWindowBase {
    TShopKeepItemWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TShopKeepItemWindow();
    void handle_deposit_list_select();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    TShopKeepItemEntry entries[30];
    u32 pad_370;
    s32 entry_count;          // rows filled in entries
    s32 deposit_count;        // how many to deposit
    s32 help_item_index;      // row the help window shows
    TShopWindowBase *sequence;        // the bank sequence that opened it; messages go to it
    TWindowMenuIconLine *item_list_window;  // TWindowMenuIconLine listing the items
    TWindowMenu *confirm_window;            // the yes/no window
    TWindowInputNumber *number_window;      // for a stack count
    TWindowHelpItem *help_window;           // for the selected item
    void (*ok_callback)(TShopWindowBase *);      // run by close_with_ok_callback
    void (*cancel_callback)(TShopWindowBase *);  // run by close_with_cancel_callback
    void close_with_cancel_callback();
    void close_with_ok_callback();
    void close();
    void handle_deposit_confirm();
    void update_number_input();
    void rebuild_item_list();
};

LAYOUT_ASSERT(TShopKeepItemWindow_size, sizeof(TShopKeepItemWindow) == 0x39C);

#endif
