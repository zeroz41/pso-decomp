#ifndef PSO_UI_CITY_TSHOPGETITEMWINDOW_H
#define PSO_UI_CITY_TSHOPGETITEMWINDOW_H

#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TObjPlayer;
struct TWindowMenu;
class TWindowShop;
struct TWindowInputNumber;
struct TWindowHelpItem;

struct TShopGetItemWindow : public TShopWindowBase {
    TShopGetItemWindow(TObject *parent, TShopWindowBase *owner, TObjPlayer *player);
    virtual ~TShopGetItemWindow();
    virtual void update_state();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    TWindowShop *item_list;     // the bank's items
    TWindowMenu *confirm_menu;          // withdraw yes / no
    TWindowInputNumber *number_input;   // how many of a stacked tool to withdraw
    TWindowHelpItem *help_window;
    TItemData displayed_item_colored;   // the selected item
    u8 pad_4C;
    u8 _pad4D[0x3];
    s32 room_table_entry;
    s32 withdraw_count;
    s32 last_cursor;                    // the entry the help window shows
    TShopWindowBase *sequence;          // the bank sequence that opened it; messages go to it
    void (*on_close)(TShopWindowBase *sequence);  // called when the player leaves
    void (*on_empty)(TShopWindowBase *sequence);  // called when there is nothing to list
    void close();
    void update_input_number();
    void handle_withdraw_list_input();
    void rebuild_item_list();
    void handle_withdraw_confirm();
};

LAYOUT_ASSERT(TShopGetItemWindow_size, sizeof(TShopGetItemWindow) == 0x68);

struct TObjPlayer;
// The shop's item level: the player's level plus one, clamped to 1..199.
void calc_item_count(TObjPlayer *player, s32 *count);
void init_shop_world_context(void);
// Section ID the shop stock is rolled for (0..9).
extern s32 shop_section_id;
void clear_all_shop_stock(void);
void reset_shop_stock_and_params(void);
#endif
