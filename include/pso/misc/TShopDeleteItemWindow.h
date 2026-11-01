#ifndef PSO_MISC_TSHOPDELETEITEMWINDOW_H
#define PSO_MISC_TSHOPDELETEITEMWINDOW_H

#include "types.h"
#include "pso/TShopWindowBase.h"

struct TShopDeleteItemWindow : public TShopWindowBase {
    virtual ~TShopDeleteItemWindow();
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
    void* m_40;
    u8 _pad44[0x10];
    u8 m_54;
    u8 _pad55[0x7];
    u32 m_5c;
    u32 m_60;
    u32 m_64;
    s32 destroy();
    static s32 update_item_select(void *arg0);
    void handle_number_input();
    void handle_confirm_dialog();
};

typedef char TShopDeleteItemWindow_size[sizeof(TShopDeleteItemWindow) == 0x68 ? 1 : -1];
#endif
