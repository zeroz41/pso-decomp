#ifndef PSO_UI_CITY_TSHOPEQUIPMENTSELLWINDOW_H
#define PSO_UI_CITY_TSHOPEQUIPMENTSELLWINDOW_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TWindowMenu;

struct TShopEquipmentSellWindow : public TShopWindowBase {
    TShopEquipmentSellWindow(void *arg1, void *arg2, void *arg3, void *arg4);
    virtual ~TShopEquipmentSellWindow();
    int get_item_count();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    void* m_28;
    u8 unk_2C[0x34];
    u16 m_60;
    u8 unk_62[0xA];
    s32 m_6c;
    u8 unk_70[0x2];
    s16 m_72;
    u8 unk_74[0x2];
    s16 m_76;
    u8 unk_78[0x2F8];
    u32 m_370;
    u32 m_374;
    u32 m_378;
    u32 m_37c;
    u32 m_380;
    u32 m_384;
    TShopWindowBase *sequence;  // the shop sequence that opened it; messages go to it
    uaddr m_38c;
    TWindowMenu *confirm_menu;
    uaddr m_394;
    uaddr m_398;
    uaddr m_39c;
    uaddr m_3a0;
    u32 m_3a4;
    u32 m_3a8;
    void update();
    void handle_sell_confirm();
    void handle_input_window_result();
    void close();
    void handle_selection();
    void build_sell_list();
    static s32 get_item_data_value(uaddr arg0);
    int is_confirmed();
    s32 get_result();
    static void set_entry_count(void *window, void *arg2);
    void add_item(saddr arg1, s32 arg2, s32 arg3);
};

LAYOUT_ASSERT(TShopEquipmentSellWindow_size, sizeof(TShopEquipmentSellWindow) == 0x3AC);
LAYOUT_ASSERT(TShopEquipmentSellWindow_confirm_menu_offset, offsetof(TShopEquipmentSellWindow, confirm_menu) == 0x390);
#endif
