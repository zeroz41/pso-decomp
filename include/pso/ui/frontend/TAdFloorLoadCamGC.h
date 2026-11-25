#ifndef PSO_UI_FRONTEND_TADFLOORLOADCAMGC_H
#define PSO_UI_FRONTEND_TADFLOORLOADCAMGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct TAdFloorLoadCamGC : public TObject {
    TAdFloorLoadCamGC(TObject *parent, s32 mode);
    virtual ~TAdFloorLoadCamGC();
    s32 mode;           // 0: the up vector follows the camera, otherwise it is mirrored
    s32 ticks;
    s32 angle;          // 0x10000 per turn
    Vec pos;
    Vec target;
    Vec up;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdFloorLoadCamGC_size, sizeof(TAdFloorLoadCamGC) == 0x4C);

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
