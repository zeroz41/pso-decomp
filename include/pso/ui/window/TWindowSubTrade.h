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
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    virtual void render();
    virtual void run_task();
};

typedef char TWindowSubTrade_size[sizeof(TWindowSubTrade) == 0x38 ? 1 : -1];

extern "C" {
u8 *__dt__15TWindowSubTradeFv(u8 *arg0, s16 arg1);
}

// --- C functions defined in TWindowSubTrade.cpp ---
extern "C" {
u8 *__dt__15TWindowSubTradeFv(u8 *arg0, s16 arg1);
}
// --- end of C functions

#endif
