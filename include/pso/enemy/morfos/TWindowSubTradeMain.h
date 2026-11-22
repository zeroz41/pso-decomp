#ifndef PSO_ENEMY_MORFOS_TWINDOWSUBTRADEMAIN_H
#define PSO_ENEMY_MORFOS_TWINDOWSUBTRADEMAIN_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMessageYesNo;

struct TWindowSubTradeMain : public TObject {
    TWindowSubTradeMain(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubTradeMain();
    TWindowMessageYesNo *open_confirm_prompt();
    saddr create_trade_window();
    saddr open_trade_equip_window();
    saddr create_list();
    saddr create_input_number(s32);
    saddr create_help_item();
    void set_displayed_item(s32);
    void set_labels(s32);
    void set_child_windows_enabled(s32);
    u8 m_1c;
    u8 m_1d;
    u8 _pad1E[0x2];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    TWindowMainMenu *parent_menu;
    uaddr m_30;
    uaddr m_34;
    TWindowMessageYesNo *dialog;
    uaddr m_3c;
    uaddr m_40;
    uaddr m_44;
    uaddr m_48;
    uaddr m_4c;
    uaddr m_50;
    void* m_54;
    s32 add_text_entry(saddr arg1, s32 arg2, s32 arg3, s32 arg4);
    void clear_trade_flag();
    void send_60_update();
    void bswap_6x6A_packet();
    void init_pkt_cmd_6A();
    static int get_warp_state();
    void set_close_flag();
    void set_visible();
    void update_trade_state();
    void close();
    void clear_flag();
    void clear_flag70_bit80();
    void set_trade_state(s16 arg1);
    void refresh_item_list(void* a1);
    static s32 get_state();
    static void draw_offer(void *arg0, void *arg1);
    static void draw_request(void *arg0, void *arg1);
    TWindowMessageYesNo *open_confirm_yes_no();
    TWindowMessageYesNo *open_option_dialog(saddr message);
    TWindowMessageYesNo *open_option_dialog_thunk(saddr message);
    TWindowMessageYesNo *open_status_window();
    TWindowMessageYesNo *update_from_lobby();
    saddr create_trade_menu();
    saddr build_trade_menu();
    virtual void render();
    virtual void run_task();
    u8 unk_58[0x18];
    u16 m_70;
    u8 unk_72[0x2];
    s16 m_74;
    u8 unk_76[0xA];
    uaddr m_80;
    u8 unk_84[0x4];
    s16 m_88;
    u8 unk_8A[0x1E];
    void forward_to_child(s32 arg1);
    void notify_child_if_present(s32 arg1);
    void draw_item_slot();
    void update_trade_window();
    static void update_position_if_changed(saddr arg0, u8 *arg1, u8 *arg2);
};

LAYOUT_ASSERT(TWindowSubTradeMain_size, sizeof(TWindowSubTradeMain) == 0xA8);
#endif
