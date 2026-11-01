#ifndef PSO_MISC_TSHOPITEMLISTWINDOW_H
#define PSO_MISC_TSHOPITEMLISTWINDOW_H

#include "types.h"
#include "pso/TShopWindowBase.h"

struct TShopItemListWindow : public TShopWindowBase {
    virtual ~TShopItemListWindow();
    s32 prepare_tool_purchase();
    s32 handle_amount_confirm();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
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
    u32 m_44;
    u8 _pad48[0x4];
    u32 m_4c;
    u32 m_50;
    u32 m_54;
    u8 _pad58[0x168];
    u32 m_1c0;
    s32 handle_confirm();
    s32 update();
    static s32 handle_tool_list_select(void *p);
    s32 check_purchase_eligibility();
    static void build_item_list(void *p);
};

typedef char TShopItemListWindow_size[sizeof(TShopItemListWindow) == 0x1C4 ? 1 : -1];

extern "C" {
u8 *TShopItemListWindow__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void *__dt__19TShopItemListWindowFv(TShopItemListWindow *arg0, s16 arg1);
}

// --- C functions defined in TShopItemListWindow.cpp ---
extern "C" {
u8 *TShopItemListWindow__ct(u8 *shop_item_list_window, s32 arg1, s32 arg2, s32 arg3);
void *__dt__19TShopItemListWindowFv(TShopItemListWindow *arg0, s16 arg1);
}
// --- end of C functions

#endif
