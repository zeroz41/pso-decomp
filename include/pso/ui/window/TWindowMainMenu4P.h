#ifndef PSO_UI_WINDOW_TWINDOWMAINMENU4P_H
#define PSO_UI_WINDOW_TWINDOWMAINMENU4P_H

#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"

struct TWindowMainMenu4P : public TWindowMainMenu {
    virtual ~TWindowMainMenu4P();
    void show_child_window();
    virtual void vfunc_6();
    virtual void vfunc_8();
    virtual void vfunc_9();
    void render();
    void run_task();
    u8 unk_44[0x8];
    s32 m_4c;
    u8 unk_50[0x4];
    u32 m_54;
    u8 unk_58[0x8];
};

typedef char TWindowMainMenu4P_size[sizeof(TWindowMainMenu4P) == 0x60 ? 1 : -1];

extern "C" {
void *TWindowMainMenu4P__ct(void *arg0);
void *__dt__17TWindowMainMenu4PFv(void *arg0, s16 arg1);
}

#endif
