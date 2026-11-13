#ifndef PSO_UI_CHARCREATE_TCHCREFFFADE_H
#define PSO_UI_CHARCREATE_TCHCREFFFADE_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrEffFade : public TObject {
public:
    TChCrEffFade(s32 arg1, s32 arg2, s32 arg3);
    virtual ~TChCrEffFade();
    virtual void run_task();
    virtual void render();
public:
    void update_fade();
    static void draw_fade_strip(f32 farg0);

    s32 step;
    s32 length;
    s32 frame;
    f32 alpha;
    s32 mode;
};

typedef char TChCrEffFade_size[sizeof(TChCrEffFade) == 0x30 ? 1 : -1];

#endif
