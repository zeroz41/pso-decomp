#ifndef PSO_UI_CHARCREATE_TOBJCMHEXTILE_H
#define PSO_UI_CHARCREATE_TOBJCMHEXTILE_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"

class TObjCMHexTile : public TObject {
public:
    TObjCMHexTile(TObject *parent, void *pos);
    virtual ~TObjCMHexTile();
    virtual void run_task();
    virtual void render();

    s32 state;
    s32 state_end_frame[3];
    vec2f drift_offset;
    vec2f offset;
    vec2f pos;
    f32 scale_rate;
    f32 scale;
    f32 alpha;
    s32 frame;
};

LAYOUT_ASSERT(TObjCMHexTile_size, sizeof(TObjCMHexTile) == 0x54);

extern "C" {
void fn_802947A8(void);
}

// --- C functions defined in TObjCMHexTile.cpp ---
extern "C" {
void fn_802947A8(void);
}
// --- end of C functions

#endif
