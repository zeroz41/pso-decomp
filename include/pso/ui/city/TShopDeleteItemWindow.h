#ifndef PSO_UI_CITY_TSHOPDELETEITEMWINDOW_H
#define PSO_UI_CITY_TSHOPDELETEITEMWINDOW_H

#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TObjPlayer;
struct TWindowMenu;
class TWindowMenuIconLine;
struct TWindowInputNumber;
struct TWindowHelpItem;

struct TShopDeleteItemWindow : public TShopWindowBase {
    TShopDeleteItemWindow(void *arg1, void *arg2, void *arg3);
    virtual ~TShopDeleteItemWindow();
    void sub_80337E2C();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    u8 _pad1C[0x4];
    u32 m_20;
    TObjPlayer *m_24;
    void (*m_28)(TShopWindowBase *);  // called when the player leaves
    void (*m_2c)(TShopWindowBase *);  // called when there is nothing to list
    TWindowMenuIconLine *m_30;
    TWindowMenu *m_34;
    TWindowInputNumber *m_38;
    TWindowHelpItem *m_3c;
    TItemData displayed_item_colored;  // the selected item
    u8 m_54;
    u8 _pad55[0x3];
    s32 room_table_entry;
    s32 m_5c;  // quantity
    s32 m_60;  // cursor
    TShopWindowBase *m_64;  // owner
    void destroy();
    static void update_item_select(void *arg0);
    void handle_number_input();
    void handle_confirm_dialog();
};

LAYOUT_ASSERT(TShopDeleteItemWindow_size, sizeof(TShopDeleteItemWindow) == 0x68);
#endif
