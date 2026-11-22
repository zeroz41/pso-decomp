#ifndef PSO_UI_CITY_TSHOPARMORLISTWINDOW_H
#define PSO_UI_CITY_TSHOPARMORLISTWINDOW_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/city/TShopWindowBase.h"

class TWindowBase;

struct TWindowMenu;

struct TShopArmorListWindow : public TShopWindowBase {
    TShopArmorListWindow(saddr parent, saddr sequence, s32 player);
    virtual ~TShopArmorListWindow();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    u8 _pad1C[0x4];
    u32 m_20;
    uaddr m_24;
    TShopWindowBase *sequence;  // the shop sequence that opened it; messages go to it
    TWindowBase *item_list;   // 0x2C: create_item_list_window
    TWindowMenu *choice_menu;          // 0x30: create_window_menu / create_yes_no_window
    TWindowBase *help_window; // 0x34: a TWindowHelpItem
    uaddr m_38;
    TWindowBase *cost_window; // 0x3C: create_cost_window
    u32 m_40;
    u8 _pad44[0x4];
    u32 m_48;
    u8 unk_4C[0x26];
    s16 m_72;
    s16 m_74;
    u8 unk_76[0x2];
    s16 m_78;
    u8 unk_7A[0x2];
    s32 m_7c;
    u8 unk_80[0x170];
    u32 m_1f0;
    u32 m_1f4;
    void update_selection(void *arg1);
    void handle_equip_offer();
    void open_menu_window();
    void advance_to_preparation_phase();
    void update();
    void handle_select();
    void handle_selection();
    s32 check_purchase_eligibility();
    static void refresh_item_list(void *p);
    void clamp_selection_to_valid_entry();
    void save_cursor_selection();
    void close_list();
    void save_and_refresh_cursor(void* a1, void* a2);
    void save_and_close();
};

LAYOUT_ASSERT(TShopArmorListWindow_size, sizeof(TShopArmorListWindow) == 0x1F8);
LAYOUT_ASSERT(TShopArmorListWindow_choice_menu_offset, offsetof(TShopArmorListWindow, choice_menu) == 0x30);

#endif
