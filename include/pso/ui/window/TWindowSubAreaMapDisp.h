#ifndef PSO_UI_WINDOW_TWINDOWSUBAREAMAPDISP_H
#define PSO_UI_WINDOW_TWINDOWSUBAREAMAPDISP_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubStatusDisp;

struct TWindowSubAreaMapDisp : public TWindowBase {
    TWindowSubAreaMapDisp();
    virtual ~TWindowSubAreaMapDisp();
    u8 unk_60[0x4];
    f32 m_64;
    u8 unk_68[0x4];
    u32 m_6c;
    TWindowSubStatusDisp *heading;
    char *title;
    void update_manual_scroll();
    virtual void render();
    virtual void run_task();
    void update_visibility();
};

LAYOUT_ASSERT(TWindowSubAreaMapDisp_size, sizeof(TWindowSubAreaMapDisp) == 0x78);

extern "C" {
void TWindowSubStatusDisp__sub_80271A6C(s32 arg0, u8 *arg1);
void fn_80271848(s32 arg0, u8 *arg1);
}

#endif
