#ifndef PSO_UI_TADENTERBASEGC_H
#define PSO_UI_TADENTERBASEGC_H

#include "types.h"
#include "pso/TObject.h"

struct TAdEnterBaseGC : public TObject {
    virtual ~TAdEnterBaseGC();
    void sub_8032B460(int);
    void create_parts();
    struct Position { f32 x, y; };
    void fn_8032B318(Position *position);
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    int m_20;
    u32 m_24;
    int m_28;
    u8 unk_2C[0x4];
    int m_30;
    u8 unk_34[0x4];
};

typedef char TAdEnterBaseGC_size[sizeof(TAdEnterBaseGC) == 0x38 ? 1 : -1];

extern "C" {
void fn_8032AC94(void);
}

// --- C functions defined in TAdEnterBaseGC.cpp ---
extern "C" {
void fn_8032AC94(void);
}
// --- end of C functions

#endif
