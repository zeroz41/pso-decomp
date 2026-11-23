#ifndef PSO_UI_CITY_TSHOPGETITEMWINDOW_H
#define PSO_UI_CITY_TSHOPGETITEMWINDOW_H

#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TObjPlayer;
struct TWindowMenu;
class TWindowMenuIconLine;
struct TWindowInputNumber;
struct TWindowHelpItem;

struct TShopGetItemWindow : public TShopWindowBase {
    TShopGetItemWindow(void *arg1, void *arg2, void *arg3);
    virtual ~TShopGetItemWindow();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    u8 _pad1C[0x4];
    u32 m_20;
    TObjPlayer *m_24;
    TWindowMenuIconLine *m_28;
    TWindowMenu *m_2c;
    TWindowInputNumber *m_30;
    TWindowHelpItem *m_34;
    TItemData displayed_item_colored;  // the selected item
    u8 m_4c;
    u8 _pad4D[0x3];
    s32 room_table_entry;
    s32 m_54;  // quantity
    s32 m_58;  // cursor
    TShopWindowBase *m_5c; // owning shop sequence (TCheckRoomSequence::open_get_item_window passes itself)
    void (*m_60)(TShopWindowBase *);  // called when the player leaves
    void (*m_64)(TShopWindowBase *);  // called when there is nothing to list
    void close();
    void update_input_number();
    void handle_withdraw_list_input();
    void rebuild_item_list();
    s16 get_cursor_index();
    void handle_withdraw_confirm();
};

LAYOUT_ASSERT(TShopGetItemWindow_size, sizeof(TShopGetItemWindow) == 0x68);
#endif
