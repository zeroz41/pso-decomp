#ifndef PSO_ENEMY_MORFOS_TWINDOWSUBTRADEMAIN_H
#define PSO_ENEMY_MORFOS_TWINDOWSUBTRADEMAIN_H

#include "types.h"

class TWindowInputNumber;
class TWindowBase;
class TWindowMenuIconLine;
struct TWindowMenu;
class TWindowHelpItem;
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMenu;
struct TWindowSubEquipKind;
struct TWindowMessageYesNo;
class TWindowChat;
struct NJS_POINT2;

struct TWindowSubTradeMain : public TObject {
    TWindowSubTradeMain(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubTradeMain();
    static const char *class_name;
    TWindowMessageYesNo *open_confirm_prompt();
    TWindowSubEquipKind *create_trade_window();
    TWindowSubEquipKind *open_trade_equip_window();
    TWindowSubEquipKind *create_list();
    TWindowInputNumber *create_input_number(s32 maximum);
    TWindowHelpItem *create_help_item();
    void set_displayed_item(s32);
    void set_labels(s32);
    void set_child_windows_enabled(s32);
    u8 state;
    u8 flags;
    u8 pad_1E[0x2];
    s32 timer;
    u32 displayed_item;
    u32 client_id;
    TWindowMainMenu *parent_menu;
    TWindowMenu *menu;
    TWindowMenu *confirm;
    TWindowMessageYesNo *dialog;
    TWindowSubEquipKind *offer;
    TWindowSubEquipKind *request;
    TWindowSubEquipKind *list;
    TWindowInputNumber *input_number;
    TWindowHelpItem *help_item;
    TWindowChat *chat;
    void *submission;
    static int get_warp_state();
    void finish();
    static void draw_offer(u32 item_id, s32 amount);
    static void draw_request(u32 item_id, s32 amount);
    // Opens the status window once the trade list was sent.
    void show_trade_status();
    TWindowMessageYesNo *open_confirm_yes_no();
    TWindowMessageYesNo *open_option_dialog(saddr message);
    TWindowMessageYesNo *open_option_dialog_thunk(saddr message);
    TWindowMessageYesNo *open_status_window();
    TWindowMessageYesNo *update_from_lobby();
    TWindowMenu *create_trade_menu();
    TWindowMenu *build_trade_menu();
    virtual void render();
    virtual void run_task();
    u8 pad_58[0x50];
    void forward_to_child(s32 trade_state);
    void notify_child_if_present(s32 trade_state);
    void draw_item_slot();
    void update_trade_window();
    void update_position_if_changed(TWindowBase *window, NJS_POINT2 *position);
};

LAYOUT_ASSERT(TWindowSubTradeMain_size, sizeof(TWindowSubTradeMain) == 0xA8);
#endif
