#ifndef PSO_UI_WINDOW_TWINDOWSUBGAMEEND_H
#define PSO_UI_WINDOW_TWINDOWSUBGAMEEND_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubGameEnd : public TObject {
    virtual ~TWindowSubGameEnd();
    u32 m_1c;
    saddr m_20;
    u32 m_24;
    uaddr m_28;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubGameEnd_size, sizeof(TWindowSubGameEnd) == 0x2C);

extern "C" {
void TLobby__sub_802796FC(void);
void TLobby__sub_80279708(void);
void *TWindowSubGameEnd__ct(TWindowSubGameEnd *arg0, s32 arg1, s32 arg2);
void *__dt__17TWindowSubGameEndFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowSubGameEnd.cpp ---
extern "C" {
void TLobby__sub_802796FC(void);
void TLobby__sub_80279708(void);
void *TWindowSubGameEnd__ct(TWindowSubGameEnd *window_sub_game_end, s32 arg1, s32 arg2);
}
// --- end of C functions

#endif
