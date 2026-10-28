#ifndef PSO_MISC_TSHOPEQUIPMENTLISTWINDOW_H
#define PSO_MISC_TSHOPEQUIPMENTLISTWINDOW_H

#include "types.h"
#include "pso/TShopWindowBase.h"

struct TShopEquipmentListWindow : public TShopWindowBase {
    virtual ~TShopEquipmentListWindow();
    virtual void vfunc_11();
    virtual void vfunc_7();
    virtual void vfunc_6();
    u8 _pad1C[0x4];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;
    u32 m_40;
    u8 _pad44[0x4];
    u32 m_48;
    u32 m_4c;
    u8 _pad50[0x140];
    u32 m_190;
    void update_list(void *arg1);
    void handle_equip_offer();
    void handle_buy_confirm();
    s32 open_menu_window();
    int get_list_item8();
    s32 handle_confirm();
    s32 handle_select();
    void handle_selection();
    s32 check_purchase_eligibility();
    static void create_buy_list_windows(void *p);
};

typedef char TShopEquipmentListWindow_size[sizeof(TShopEquipmentListWindow) == 0x194 ? 1 : -1];
// --- C functions defined in TShopEquipmentListWindow.cpp ---
extern "C" {
u8 *TShopEquipmentListWindow__ct(u8 *shop_equipment_list_window, s32 arg1, s32 arg2, s32 arg3);
int TShopEquipmentListWindow__sub_8021C85C(int a0);
void *__dt__24TShopEquipmentListWindowFv(TShopEquipmentListWindow *arg0, s16 arg1);
}
// --- end of C functions

#endif
