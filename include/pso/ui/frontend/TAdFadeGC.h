#ifndef PSO_UI_FRONTEND_TADFADEGC_H
#define PSO_UI_FRONTEND_TADFADEGC_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TAdFadeGC : public TObject {
public:
    TAdFadeGC(TObject *arg1, void *arg2);
    virtual ~TAdFadeGC();
    virtual void run_task();
    virtual void render();
public:
    void draw_fade();
    void start_fade(void *arg1);

    s32 elapsed_frames;
    f32 wipe_width;
    u8 pad_24[4];
    s32 fade_mode;
    f32 opacity;
    u32 fade_color;
    f32 opacity_step;
};

LAYOUT_ASSERT(TAdFadeGCSize, sizeof(TAdFadeGC) == 0x38);
LAYOUT_ASSERT(TAdFadeGCModeOffset, offsetof(TAdFadeGC, fade_mode) == 0x28);
LAYOUT_ASSERT(TAdFadeGCColorOffset, offsetof(TAdFadeGC, fade_color) == 0x30);

#endif
