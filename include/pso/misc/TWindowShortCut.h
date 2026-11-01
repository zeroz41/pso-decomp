#ifndef PSO_MISC_TWINDOWSHORTCUT_H
#define PSO_MISC_TWINDOWSHORTCUT_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowShortCut : public TWindowBase {
    virtual ~TWindowShortCut();
    virtual void render();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 _pad28[0x38];
    u32 m_60;
    u32 m_64;
    u32 m_68;
    u32 m_6c;
    u32 m_70;
    virtual void run_task();
};

typedef char TWindowShortCut_size[sizeof(TWindowShortCut) == 0x74 ? 1 : -1];

extern "C" {
u8 *TWindowShortCut__ct(TWindowShortCut *arg0, s32 arg1, s32 arg2, s32 arg3);
void *__dt__15TWindowShortCutFv(void *arg0, s16 arg1);
void render__15TWindowShortCutFv(u8 *arg0);
}

// --- C functions defined in TWindowShortCut.cpp ---
extern "C" {
u8 *TWindowShortCut__ct(TWindowShortCut *window_short_cut, s32 arg1, s32 arg2, s32 arg3);
void *__dt__15TWindowShortCutFv(void *arg0, s16 arg1);
void render__15TWindowShortCutFv(u8 *arg0);
}
// --- end of C functions

#endif
