#ifndef PSO_UNK_TSCREENFADECONTROLLER_H
#define PSO_UNK_TSCREENFADECONTROLLER_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TScreenFadeController : public TObject {
public:
    TScreenFadeController(TObject *parent);
    virtual ~TScreenFadeController();
    virtual void run_task();
    virtual void render();
    void step_fade_opacity_decrease();
    void step_fade_opacity_increase();
    void tick_fade_counter();
    f32 alpha; // 0 to 255, like TScreenFade::alpha
    union {
        u32 packed_color; // color[] as one word
        u8 color[4];
    };
    s32 mode;           // 0 idle, 1 fade in, 2 fade out, 3 tick
    void (*callback)(); // called once the fade ends
};
LAYOUT_ASSERT(TScreenFadeController_size, sizeof(TScreenFadeController) == 0x2C);

#endif
