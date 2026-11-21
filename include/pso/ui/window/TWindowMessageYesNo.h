#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEYESNO_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEYESNO_H

#include <stddef.h>

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMenu;

struct TWindowMessageYesNo : public TObject {
    TWindowMessageYesNo(TObject *arg1, void *arg2, void *arg3, void *arg4);
    virtual ~TWindowMessageYesNo();
    s32 is_child_visible();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    uaddr m_28;
    TWindowMenu *choice_menu;
    void set_choice_menu_flag70_bit10();
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0, void *arg1, void *arg2, void *arg3);
};

LAYOUT_ASSERT(TWindowMessageYesNoChoiceMenuOffset, offsetof(TWindowMessageYesNo, choice_menu) == 0x2C);
LAYOUT_ASSERT(TWindowMessageYesNo_size, sizeof(TWindowMessageYesNo) == 0x30);
#endif
