#ifndef PSO_UI_CHARCREATE_TCHCREFFTAGSTR_H
#define PSO_UI_CHARCREATE_TCHCREFFTAGSTR_H

#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "types.h"

class TChCrEffTagStr : public TObject {
public:
    static const char *name;
    TChCrEffTagStr(TObject *parent, s32 sprite_id, vec2f *pos);
    virtual ~TChCrEffTagStr();
    virtual void run_task();
    virtual void render();
    void start_fade_out();
    static TChCrEffTagStr *create(TObject *parent, s32 sprite_id, vec2f *pos);

    s32 state;
    s32 sprite_id;
    f32 fade;
    vec2f pos;
};

LAYOUT_ASSERT(TChCrEffTagStr_size, sizeof(TChCrEffTagStr) == 0x30);


#endif
