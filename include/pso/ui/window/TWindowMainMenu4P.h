#ifndef PSO_UI_WINDOW_TWINDOWMAINMENU4P_H
#define PSO_UI_WINDOW_TWINDOWMAINMENU4P_H

#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"

struct TWindowMainMenu4P : public TWindowMainMenu {
    TWindowMainMenu4P(TObject *parent, s32 client);
    virtual ~TWindowMainMenu4P();
    virtual void vfunc_6();
    virtual void vfunc_8();
    virtual void vfunc_9();
    void render();
    void run_task();
};

typedef char TWindowMainMenu4P_size[sizeof(TWindowMainMenu4P) == 0x60 ? 1 : -1];

extern "C" {
void *__dt__17TWindowMainMenu4PFv(void *arg0, s16 arg1);
}

#endif
