#ifndef PSO_UI_CITY_TSHOPEQUIPMENTLISTWINDOW_H
#define PSO_UI_CITY_TSHOPEQUIPMENTLISTWINDOW_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/city/TShopWindowBase.h"

struct TWindowMenu;

struct TShopEquipmentListWindow : public TShopWindowBase {
    TShopEquipmentListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TShopEquipmentListWindow();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void display_shop_message(s32 id, s32 flags);
    TShopWindowBase *sequence;  // the shop sequence that opened it; messages go to it
    TWindowMenu *m_2c;
    uaddr m_30;
    uaddr m_34;
    uaddr m_38;
    uaddr m_3c;
    u32 m_40;
    u8 _pad44[0x4];
    u32 m_48;
    u32 m_4c;
    u8 _pad50[0x140];
    u32 m_190;
    void update_list(void *arg1);
    void handle_equip_offer();
    void handle_buy_confirm();
    void open_menu_window();
    void get_list_item8();
    void handle_confirm();
    void handle_select();
    void handle_selection();
    s32 check_purchase_eligibility();
    static void create_buy_list_windows(void *p);
};

LAYOUT_ASSERT(TShopEquipmentListWindow_size, sizeof(TShopEquipmentListWindow) == 0x194);
// --- C functions defined in TShopEquipmentListWindow.cpp ---
extern "C" {
int TShopEquipmentListWindow__sub_8021C85C(int a0);
void *__dt__24TShopEquipmentListWindowFv(TShopEquipmentListWindow *arg0, s16 arg1);
}
// --- end of C functions

LAYOUT_ASSERT(TShopEquipmentListWindow_m_2c_offset, offsetof(TShopEquipmentListWindow, m_2c) == 0x2C);

#endif
