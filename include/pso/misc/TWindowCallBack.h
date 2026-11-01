#ifndef PSO_MISC_TWINDOWCALLBACK_H
#define PSO_MISC_TWINDOWCALLBACK_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowCallBack : public TWindowBase {
    virtual ~TWindowCallBack();
    void render();
    void run_task();
    void* m_38;
    u8 _pad3C[0x24];
    u32 m_60;
    u8 unk_48[0x1C];
};

typedef char TWindowCallBack_size[sizeof(TWindowCallBack) == 0x64 ? 1 : -1];
extern "C" {
u8 *TWindowCallBack__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
void *__dt__15TWindowCallBackFv(void *arg0, s16 arg1);
}
void build_6xA3_olga_flow_boss_actions(void *p);
extern "C" {
void fn_802ACD40(void *p);
void fn_802ACD60(void *p);
void run_task__15TWindowCallBackFv(void *p);
void set_field_60__15TWindowCallBackFPvi(void *p, s32 v);
}

#endif
