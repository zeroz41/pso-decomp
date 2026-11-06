#ifndef PSO_UI_CITY_TSHOPKEEPITEMWINDOW_H
#define PSO_UI_CITY_TSHOPKEEPITEMWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

struct TItem;

// One row of the deposit list: the inventory item, a copy of its data and
// its inventory index (field names inferred from rebuild_item_list).
struct TShopKeepItemEntry {
    TItem *item;
    TItemData data;
    s32 inventory_index;
};

struct TShopKeepItemWindow : public TShopWindowBase {
    TShopKeepItemWindow(void *arg1, void *arg2, void *arg3);
    virtual ~TShopKeepItemWindow();
    void handle_deposit_list_select();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void vfunc_6();
    u8 _pad1C[0x4];
    u32 m_20;
    u32 m_24;
    TShopKeepItemEntry entries[30];
    u32 m_370;
    s32 entry_count;          // (inferred) rows filled in entries
    s32 deposit_count;        // (inferred) how many to deposit
    s32 help_item_index;      // (inferred) row the help window shows
    u32 message_window;       // (inferred) display_message forwards to it
    u32 item_list_window;     // TWindowMenuIconLine listing the items
    u32 confirm_window;       // the yes/no window
    u32 number_window;        // TWindowInputNumber for a stack count
    u32 help_window;          // TWindowHelpItem for the selected item
    s32 (*ok_callback)(s32);      // (inferred) run by close_with_ok_callback
    s32 (*cancel_callback)(s32);  // (inferred) run by close_with_cancel_callback
    s32 close_with_cancel_callback();
    s32 close_with_ok_callback();
    s32 close();
    void handle_deposit_confirm();
    void update_number_input();
    s32 rebuild_item_list();
};

typedef char TShopKeepItemWindow_size[sizeof(TShopKeepItemWindow) == 0x39C ? 1 : -1];

#endif
