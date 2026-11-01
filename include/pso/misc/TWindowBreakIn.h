#ifndef PSO_MISC_TWINDOWBREAKIN_H
#define PSO_MISC_TWINDOWBREAKIN_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowBreakIn : public TWindowBase {
    virtual ~TWindowBreakIn();
    u8 _pad1C[0x8];
    void* m_24;
    virtual void render();
    virtual void run_task();
    u8 unk_28[0x38];
};

typedef char TWindowBreakIn_size[sizeof(TWindowBreakIn) == 0x60 ? 1 : -1];

extern "C" {
u8 *TWindowBreakIn__ct(u8 *arg0);
void *__dt__14TWindowBreakInFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowBreakIn.cpp ---
extern "C" {
u8 *TWindowBreakIn__ct(u8 *window_dd);
void *__dt__14TWindowBreakInFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
