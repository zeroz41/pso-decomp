#ifndef PSO_UI_WINDOW_TWINDOWMAINMENU4P_H
#define PSO_UI_WINDOW_TWINDOWMAINMENU4P_H

#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"

struct TWindowMainMenu4P : public TWindowMainMenu {
    TWindowMainMenu4P(TObject *parent, s32 client);
    virtual ~TWindowMainMenu4P();
    virtual void open_main_menu();
    virtual void close_main_menu();
    virtual void on_submenu_closed();
    void render();
    void run_task();
};

LAYOUT_ASSERT(TWindowMainMenu4P_size, sizeof(TWindowMainMenu4P) == 0x60);

extern "C" {
void *__dt__17TWindowMainMenu4PFv(void *arg0, s16 arg1);
}

#endif
