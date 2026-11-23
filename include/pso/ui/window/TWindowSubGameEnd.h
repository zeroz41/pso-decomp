#ifndef PSO_UI_WINDOW_TWINDOWSUBGAMEEND_H
#define PSO_UI_WINDOW_TWINDOWSUBGAMEEND_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMessageYesNo;

// Main-menu "end the game" prompt: a yes/no window; yes logs out and returns to
// character select.
struct TWindowSubGameEnd : public TObject {
    TWindowSubGameEnd(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubGameEnd();
    u32 state;
    saddr client;
    TWindowMainMenu *parent_menu;
    TWindowMessageYesNo *yes_no_window;
    static const char *class_name;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubGameEnd_size, sizeof(TWindowSubGameEnd) == 0x2C);

// --- C functions defined in TWindowSubGameEnd.cpp ---
extern "C" {
void TLobby__sub_802796FC(void);
void TLobby__sub_80279708(void);
}
// --- end of C functions

#endif
