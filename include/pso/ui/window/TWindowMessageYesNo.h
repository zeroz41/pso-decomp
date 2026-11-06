#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEYESNO_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEYESNO_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMessageYesNo : public TObject {
    TWindowMessageYesNo(TObject *arg1, void *arg2, void *arg3, void *arg4);
    virtual ~TWindowMessageYesNo();
    s32 is_child_visible();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0, void *arg1, void *arg2, void *arg3);
};

typedef char TWindowMessageYesNo_size[sizeof(TWindowMessageYesNo) == 0x30 ? 1 : -1];
#endif
