#ifndef PSO_MISC_TSHOPEQUIPMENTSELLWINDOW_H
#define PSO_MISC_TSHOPEQUIPMENTSELLWINDOW_H

#include "types.h"
#include "pso/TShopWindowBase.h"

struct TShopEquipmentSellWindow : public TShopWindowBase {
    virtual ~TShopEquipmentSellWindow();
    virtual void vfunc_11();
    virtual void display_message(const char *text, s32 flags);
    virtual void vfunc_6();
    u8 _pad1C[0x4];
    u32 m_20;
    u32 m_24;
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
    u32 m_388;
    u32 m_38c;
    u32 m_390;
    u32 m_394;
    u32 m_398;
    u32 m_39c;
    u32 m_3a0;
    u32 m_3a4;
    u32 m_3a8;
    s32 update();
    void handle_sell_confirm();
    void handle_input_window_result();
    s32 close();
    void handle_selection();
    void build_sell_list();
    static s32 get_item_data_value(u32 arg0);
    int is_confirmed();
    s32 get_result();
    static void set_entry_count(void *arg1, void *arg2);
    int get_item_count();
    void add_item(s32 arg1, s32 arg2, s32 arg3);
};

typedef char TShopEquipmentSellWindow_size[sizeof(TShopEquipmentSellWindow) == 0x3AC ? 1 : -1];
#endif
