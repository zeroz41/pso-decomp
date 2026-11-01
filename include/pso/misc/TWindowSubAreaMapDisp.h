#ifndef PSO_MISC_TWINDOWSUBAREAMAPDISP_H
#define PSO_MISC_TWINDOWSUBAREAMAPDISP_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowSubAreaMapDisp : public TWindowBase {
    virtual ~TWindowSubAreaMapDisp();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 unk_22[0xA];
    s32 m_2c;
    u8 unk_30[0x2C];
    u32 m_5c;
    u8 unk_60[0x4];
    f32 m_64;
    u8 unk_68[0x4];
    u32 m_6c;
    u32 m_70;
    u32 m_74;
    void update_manual_scroll();
    virtual void render();
    virtual void run_task();
    void update_visibility();
};

typedef char TWindowSubAreaMapDisp_size[sizeof(TWindowSubAreaMapDisp) == 0x78 ? 1 : -1];

extern "C" {
u8 *TWindowSubAreaMapDisp__ct(TWindowSubAreaMapDisp *arg0);
void TWindowSubStatusDisp__sub_80271A6C(s32 arg0, u8 *arg1);
u8 *__dt__21TWindowSubAreaMapDispFv(TWindowSubAreaMapDisp *arg0, s16 arg1);
void fn_80271848(s32 arg0, u8 *arg1);
}

#endif
