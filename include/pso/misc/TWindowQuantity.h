#ifndef PSO_MISC_TWINDOWQUANTITY_H
#define PSO_MISC_TWINDOWQUANTITY_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowQuantity : public TWindowBase {
    virtual ~TWindowQuantity();
    virtual void render();
    u8 _pad1C[0x8];
    void* m_24;
    u8 unk_28[0x38];
    f32 m_60;
    void* m_64;
    void set_position(s32 arg1);
    virtual void run_task();
    u8 unk_68[0x4];
};

typedef char TWindowQuantity_size[sizeof(TWindowQuantity) == 0x6C ? 1 : -1];

extern "C" {
void *TWindowQuantity__ct(void *arg0, void *arg1);
void *__dt__15TWindowQuantityFv(void *arg0, s16 arg1);
void *create_window_quantity(void *arg0);
void render__15TWindowQuantityFv(s32 arg0);
}

// --- C functions defined in TWindowQuantity.cpp ---
extern "C" {
void *TWindowQuantity__ct(void *arg0, void *arg1);
void *__dt__15TWindowQuantityFv(void *arg0, s16 arg1);
void *create_window_quantity(void *arg0);
void render__15TWindowQuantityFv(s32 arg0);
}
// --- end of C functions

#endif
