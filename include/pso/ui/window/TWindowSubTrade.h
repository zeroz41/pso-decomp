#ifndef PSO_UI_WINDOW_TWINDOWSUBTRADE_H
#define PSO_UI_WINDOW_TWINDOWSUBTRADE_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMenu;
struct TWindowMessage;
struct TWindowMessageYesNo;

struct TWindowSubTrade : public TObject {
    TWindowSubTrade(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubTrade();
    static const char *class_name;
    TWindowMessage *open_player_message_window(s32 player, const char *text);
    TWindowMessageYesNo *open_trade_confirm_prompt(s32 player);
    // Hands control back to the main menu and closes (state 7).
    void finish();
    u8 state;
    u8 _pad1D[0x3];
    uaddr client_id;
    u32 selected_player;
    TWindowMainMenu *parent_menu;
    TWindowMenu *m_player_list;
    TWindowMessage *m_message_window;
    TWindowMessageYesNo *m_confirm_prompt;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubTrade_player_list_offset, offsetof(TWindowSubTrade, m_player_list) == 0x2C);
LAYOUT_ASSERT(TWindowSubTrade_message_window_offset, offsetof(TWindowSubTrade, m_message_window) == 0x30);
LAYOUT_ASSERT(TWindowSubTrade_confirm_prompt_offset, offsetof(TWindowSubTrade, m_confirm_prompt) == 0x34);
LAYOUT_ASSERT(TWindowSubTrade_size, sizeof(TWindowSubTrade) == 0x38);

#endif
