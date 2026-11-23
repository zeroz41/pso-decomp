#ifndef PSO_ENEMY_MORFOS_TWINDOWSUBTRADEMAIN_H
#define PSO_ENEMY_MORFOS_TWINDOWSUBTRADEMAIN_H

#include "types.h"

class TWindowInputNumber;
class TWindowHelpItem;
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMessageYesNo;
class TWindowChat;

struct TWindowSubTradeMain : public TObject {
    TWindowSubTradeMain(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubTradeMain();
    TWindowMessageYesNo *open_confirm_prompt();
    saddr create_trade_window();
    saddr open_trade_equip_window();
    saddr create_list();
    TWindowInputNumber *create_input_number(s32 maximum);
    TWindowHelpItem *create_help_item();
    void set_displayed_item(s32);
    void set_labels(s32);
    void set_child_windows_enabled(s32);
    u8 state;
    u8 flags;
    u8 pad_1E[0x2];
    u32 timer;
    u32 displayed_item;
    u32 client_id;
    TWindowMainMenu *parent_menu;
    uaddr menu;
    uaddr confirm;
    TWindowMessageYesNo *dialog;
    uaddr offer;
    uaddr request;
    uaddr list;
    uaddr input_number;
    TWindowHelpItem *help_item;
    TWindowChat *chat;
    void *submission;
    void clear_trade_flag();
    void send_60_update();
    void bswap_6x6A_packet();
    void init_pkt_cmd_6A();
    static int get_warp_state();
    void set_close_flag();
    void set_visible();
    void update_trade_state();
    void close();
    void finish();
    void clear_flag();
    void clear_flag70_bit80();
    void set_trade_state(s16 trade_state);
    static s32 get_state();
    static void draw_offer(void *item, void *amount);
    static void draw_request(void *item, void *amount);
    TWindowMessageYesNo *open_confirm_yes_no();
    TWindowMessageYesNo *open_option_dialog(saddr message);
    TWindowMessageYesNo *open_option_dialog_thunk(saddr message);
    TWindowMessageYesNo *open_status_window();
    TWindowMessageYesNo *update_from_lobby();
    saddr create_trade_menu();
    saddr build_trade_menu();
    virtual void render();
    virtual void run_task();
    u8 pad_58[0x18];
    u16 m_70;
    u8 unk_72[0x2];
    s16 m_74;
    u8 unk_76[0xA];
    uaddr m_80;
    u8 unk_84[0x4];
    s16 trade_state;
    u8 unk_8A[0x1E];
    void forward_to_child(s32 trade_state);
    void notify_child_if_present(s32 trade_state);
    void draw_item_slot();
    void update_trade_window();
    static void update_position_if_changed(saddr owner, u8 *window, u8 *position);
};

LAYOUT_ASSERT(TWindowSubTradeMain_size, sizeof(TWindowSubTradeMain) == 0xA8);
#endif
