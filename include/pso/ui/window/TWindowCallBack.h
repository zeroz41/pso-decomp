#ifndef PSO_UI_WINDOW_TWINDOWCALLBACK_H
#define PSO_UI_WINDOW_TWINDOWCALLBACK_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowCallBack : public TWindowBase {
    TWindowCallBack(s32 arg1, u8 *arg2, s32 arg3);
    virtual ~TWindowCallBack();
    void render();
    void run_task();
    u8 _pad1C[0x1C];
    void* m_38;
    u8 _pad3C[0x24];
    void (*callback)(TWindowCallBack *, s32);
};

LAYOUT_ASSERT(TWindowCallBack_size, sizeof(TWindowCallBack) == 0x64);
void build_6xA3_olga_flow_boss_actions(void *p);
extern "C" {
void fn_802ACD40(void *p);
void fn_802ACD60(void *p);
void run_task__15TWindowCallBackFv(void *p);
void set_field_60__15TWindowCallBackFPvi(void *p, s32 v);
}

#endif
