#ifndef PSO_MISC_TSHOPGETITEMWINDOW_H
#define PSO_MISC_TSHOPGETITEMWINDOW_H

#include "types.h"
#include "pso/TShopWindowBase.h"

struct TShopGetItemWindow : public TShopWindowBase {
    virtual ~TShopGetItemWindow();
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
    void* m_38;
    u8 _pad3C[0x10];
    u8 m_4c;
    u8 _pad4D[0x7];
    u32 m_54;
    u32 m_58;
    u32 m_5c;
    u32 m_60;
    u32 m_64;
    s32 close();
    void update_input_number();
    s32 handle_withdraw_list_input();
    void rebuild_item_list();
    s16 get_cursor_index();
    void calc_item_count(s32 *arg1);
    void handle_withdraw_confirm();
};

typedef char TShopGetItemWindow_size[sizeof(TShopGetItemWindow) == 0x68 ? 1 : -1];
#endif
