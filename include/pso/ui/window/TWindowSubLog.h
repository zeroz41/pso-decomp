#ifndef PSO_UI_WINDOW_TWINDOWSUBLOG_H
#define PSO_UI_WINDOW_TWINDOWSUBLOG_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubLog : public TObject {
    TWindowSubLog(TObject *arg1, void *arg2);
    virtual ~TWindowSubLog();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    void* m_2c;
    virtual void render();
    virtual void run_task();
    void clear_flag4c_bit8();
    int cleanup();
    void set_flag4c_bit8();
    u8 unk_30[0x1C];
    u32 m_4c;
    u8 unk_50[0x30];
};

typedef char TWindowSubLog_size[sizeof(TWindowSubLog) == 0x80 ? 1 : -1];

extern "C" {
void *__dt__13TWindowSubLogFv(void *arg0, s16 arg1);
int fn_8027B288(void *p);
void fn_8027B2A8(void *p);
}

// --- C functions defined in TWindowSubLog.cpp ---
extern "C" {
int fn_8027B288(void *p);
void fn_8027B2A8(void *p);
}
// --- end of C functions

#endif
