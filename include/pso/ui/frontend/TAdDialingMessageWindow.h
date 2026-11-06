#ifndef PSO_UI_FRONTEND_TADDIALINGMESSAGEWINDOW_H
#define PSO_UI_FRONTEND_TADDIALINGMESSAGEWINDOW_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdDialingMessageWindow : public TObject {
    TAdDialingMessageWindow(void *arg1, void *arg2);
    virtual ~TAdDialingMessageWindow();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    void set_flag_and_notify();
    void run_child_tasks();
    virtual void render();
};

typedef char TAdDialingMessageWindow_size[sizeof(TAdDialingMessageWindow) == 0x2C ? 1 : -1];

extern "C" {
void *__ct__23TAdDialingMessageWindowFPvPv(void *arg0, void *arg1, void *arg2);
void *__dt__23TAdDialingMessageWindowFv(void *arg0, s16 arg1);
}

#endif
