#ifndef PSO_UI_FRONTEND_TADMCCHECKGC_H
#define PSO_UI_FRONTEND_TADMCCHECKGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdMcCheckGC : public TObject {
    TAdMcCheckGC(TObject *arg1, void *arg2);
    virtual ~TAdMcCheckGC();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    uaddr m_28;
    uaddr m_2c;
    uaddr m_30;
    uaddr m_34;
    uaddr m_38;
    virtual void render();
    s32 create(s32 arg1);
    virtual void run_task();
};

LAYOUT_ASSERT(TAdMcCheckGC_size, sizeof(TAdMcCheckGC) == 0x3C);

extern "C" {
void TLobby__sub_8033EE38(void *p);
u8 *__dt__12TAdMcCheckGCFv(TAdMcCheckGC *arg0, s16 arg1);
}

// --- C functions defined in TAdMcCheckGC.cpp ---
extern "C" {
void TLobby__sub_8033EE38(void *p);
}
// --- end of C functions

#endif
