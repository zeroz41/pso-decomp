#ifndef PSO_UI_WINDOW_TWINDOWSUBTRADE_H
#define PSO_UI_WINDOW_TWINDOWSUBTRADE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubTrade : public TObject {
    TWindowSubTrade(TObject *arg1, void *arg2);
    virtual ~TWindowSubTrade();
    s32 open_player_message_window(s32, s32);
    s32 open_trade_confirm_prompt(s32);
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    u32 m_24;
    uaddr m_28;
    uaddr m_player_list; // inferred names: the windows run_task opens (trade partner list,
    uaddr m_message_window; // player message window,
    uaddr m_confirm_prompt; // trade yes/no prompt)
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubTrade_size, sizeof(TWindowSubTrade) == 0x38);

#endif
