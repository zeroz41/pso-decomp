#ifndef PSO_BOSS_TBOSS6ZANZO_H
#define PSO_BOSS_TBOSS6ZANZO_H

#include "types.h"
#include "pso/TObject.h"

struct TBoss6Zanzo : public TObject {
    TBoss6Zanzo(TObject *arg1, s32 arg2, s32 arg3);
    virtual ~TBoss6Zanzo();
    void copy_trail_buffer(void *, void *);
    virtual void run_task();
    u32 m_1c;
    u32 m_20;
    s32 m_24;
    s32 m_28;
    virtual void render();
    void sub_803205C4();
};

typedef char TBoss6Zanzo_size[sizeof(TBoss6Zanzo) == 0x2C ? 1 : -1];

extern "C" {
void TBoss6Zanzo__sub_803205A0(s32 *arg0, s32 *arg1);
s32 fn_803204B0(void *p);
}

// --- C functions defined in TBoss6Zanzo.cpp ---
extern "C" {
void TBoss6Zanzo__sub_803205A0(s32 *arg0, s32 *arg1);
s32 fn_803204B0(void *p);
}
// --- end of C functions

#endif
