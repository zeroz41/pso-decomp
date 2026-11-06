#ifndef PSO_UI_FRONTEND_TADFLOORLOADCAMGC_H
#define PSO_UI_FRONTEND_TADFLOORLOADCAMGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdFloorLoadCamGC : public TObject {
    TAdFloorLoadCamGC(TObject *arg1, void *arg2);
    virtual ~TAdFloorLoadCamGC();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    void* m_28;
    u8 _pad2C[0x8];
    void* m_34;
    u8 _pad38[0x8];
    void* m_40;
    virtual void render();
    virtual void run_task();
    u8 unk_44[0x4];
    f32 m_48;
};

typedef char TAdFloorLoadCamGC_size[sizeof(TAdFloorLoadCamGC) == 0x4C ? 1 : -1];

extern "C" {
void *__dt__17TAdFloorLoadCamGCFv(void *arg0, s16 arg1);
u16 fn_8034BE30(void *p);
void fn_8034BE38(void *p);
void fn_8034BE48(void *p);
}

// --- C functions defined in TAdFloorLoadCamGC.cpp ---
extern "C" {
u16 fn_8034BE30(void *p);
void fn_8034BE38(void *p);
void fn_8034BE48(void *p);
}
// --- end of C functions

#endif
