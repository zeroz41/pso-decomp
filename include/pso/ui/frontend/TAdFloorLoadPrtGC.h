#ifndef PSO_UI_FRONTEND_TADFLOORLOADPRTGC_H
#define PSO_UI_FRONTEND_TADFLOORLOADPRTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdFloorLoadPrtGC : public TObject {
    virtual ~TAdFloorLoadPrtGC();
    void* m_1c;
    u8 _pad20[0x37C];
    u32 m_39c;
    virtual void render();
    virtual void run_task();
};

typedef char TAdFloorLoadPrtGC_size[sizeof(TAdFloorLoadPrtGC) == 0x3A0 ? 1 : -1];

extern "C" {
void fn_8034AD28(void);
void fn_8034AD2C(void);
}

// --- C functions defined in TAdFloorLoadPrtGC.cpp ---
extern "C" {
void fn_8034AD28(void);
void fn_8034AD2C(void);
}
// --- end of C functions

#endif
