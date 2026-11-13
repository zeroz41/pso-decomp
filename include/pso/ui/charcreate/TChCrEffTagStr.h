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

typedef char TChCrEffTagStr_size[sizeof(TChCrEffTagStr) == 0x30 ? 1 : -1];

extern "C" {
void TChCrEffTagStr__sub_8029AED0(TChCrEffTagStr *p);
}

#endif
