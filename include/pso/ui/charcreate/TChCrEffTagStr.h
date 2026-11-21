#ifndef PSO_UI_CHARCREATE_TCHCREFFTAGSTR_H
#define PSO_UI_CHARCREATE_TCHCREFFTAGSTR_H

#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "types.h"

class TChCrEffTagStr : public TObject {
public:
    TChCrEffTagStr(TObject *arg1, void *arg2, void *arg3);
    virtual ~TChCrEffTagStr();
    virtual void run_task();
    virtual void render();

    s32 state;
    s32 sprite_id;
    f32 fade;
    vec2f pos;
};

LAYOUT_ASSERT(TChCrEffTagStr_size, sizeof(TChCrEffTagStr) == 0x30);

extern "C" {
void TChCrEffTagStr__sub_8029AED0(TChCrEffTagStr *p);
}

// --- C functions defined in TChCrEffTagStr.cpp ---
extern "C" {
void TChCrEffTagStr__sub_8029AED0(TChCrEffTagStr *p);
}
// --- end of C functions

#endif
