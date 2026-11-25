#ifndef PSO_UI_CITY_TSHOPDELETEITEMWINDOW_H
#define PSO_UI_CITY_TSHOPDELETEITEMWINDOW_H

#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TObjPlayer;
struct TWindowMenu;
class TWindowShop;
struct TWindowInputNumber;
struct TWindowHelpItem;

struct TShopDeleteItemWindow : public TShopWindowBase {
    TShopDeleteItemWindow(TObject *parent, TShopWindowBase *owner, TObjPlayer *player);
    virtual ~TShopDeleteItemWindow();
    void sub_80337E2C();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    void (*on_close)(TShopWindowBase *sequence);  // called when the player leaves
    void (*on_empty)(TShopWindowBase *sequence);  // called when there is nothing to list
    TWindowShop *item_list;     // the bank's items
    TWindowMenu *confirm_menu;          // delete yes / no
    TWindowInputNumber *number_input;   // how many of a stacked tool to delete
    TWindowHelpItem *help_window;
    TItemData displayed_item_colored;   // the selected item
    u8 pad_54;
    u8 _pad55[0x3];
    s32 room_table_entry;
    s32 delete_count;
    s32 last_cursor;                    // the entry the help window shows
    TShopWindowBase *sequence;          // the bank sequence that opened it; messages go to it
    void destroy();
    static void update_item_select(void *arg0);
    void handle_number_input();
    void handle_confirm_dialog();
};

LAYOUT_ASSERT(TShopDeleteItemWindow_size, sizeof(TShopDeleteItemWindow) == 0x68);
#endif
