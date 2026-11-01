#ifndef PSO_MISC_TSHOPARMORLISTWINDOW_H
#define PSO_MISC_TSHOPARMORLISTWINDOW_H

#include "types.h"
#include "pso/TShopWindowBase.h"

struct TShopArmorListWindow : public TShopWindowBase {
    virtual ~TShopArmorListWindow();
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
    s32 open_menu_window();
    int advance_to_preparation_phase();
    s32 update();
    s32 handle_select();
    void handle_selection();
    s32 check_purchase_eligibility();
    static void refresh_item_list(void *p);
    void clamp_selection_to_valid_entry();
    void save_cursor_selection();
    void close_list();
    void save_and_refresh_cursor(void* a1, void* a2);
    void save_and_close();
};

typedef char TShopArmorListWindow_size[sizeof(TShopArmorListWindow) == 0x1F8 ? 1 : -1];
#endif
