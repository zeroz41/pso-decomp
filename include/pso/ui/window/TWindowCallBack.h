#ifndef PSO_UI_WINDOW_TWINDOWCALLBACK_H
#define PSO_UI_WINDOW_TWINDOWCALLBACK_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowCallBack : public TWindowBase {
    TWindowCallBack(s32 arg1, u8 *arg2, s32 arg3);
    virtual ~TWindowCallBack();
    void render();
    void run_task();
    void (*callback)(TWindowCallBack *, s32);
};

typedef char TWindowCallBack_size[sizeof(TWindowCallBack) == 0x64 ? 1 : -1];
void build_6xA3_olga_flow_boss_actions(void *p);
extern "C" {
void fn_802ACD40(void *p);
void fn_802ACD60(void *p);
void run_task__15TWindowCallBackFv(void *p);
void set_field_60__15TWindowCallBackFPvi(void *p, s32 v);
}

#endif
