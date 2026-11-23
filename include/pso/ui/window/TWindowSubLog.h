#ifndef PSO_UI_WINDOW_TWINDOWSUBLOG_H
#define PSO_UI_WINDOW_TWINDOWSUBLOG_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;

struct TWindowSubLog : public TObject {
    TWindowSubLog(TObject *parent, void *arg2);
    virtual ~TWindowSubLog();
    u32 m_1c;
    TWindowMainMenu *parent_menu;
    uaddr m_24;
    uaddr chat;
    void* m_2c;
    virtual void render();
    virtual void run_task();
    u8 unk_30[0x1C];
    u32 m_4c;
    u8 unk_50[0x30];
};

LAYOUT_ASSERT(TWindowSubLog_size, sizeof(TWindowSubLog) == 0x80);

extern "C" {
void *__dt__13TWindowSubLogFv(void *arg0, s16 arg1);
void fn_8027B2A8(void *p);
}

// --- C functions defined in TWindowSubLog.cpp ---
extern "C" {
void fn_8027B2A8(void *p);
}
// --- end of C functions

#endif
