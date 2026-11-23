#ifndef PSO_UNK_TUNK_80499970_H
#define PSO_UNK_TUNK_80499970_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_80499970 : public TObject {
public:
    TUnk_80499970(TObject *parent);
    virtual ~TUnk_80499970();
    virtual void run_task();
    virtual void render();
    void step_fade_opacity_decrease();
    void step_fade_opacity_increase();
    void tick_fade_counter();
    f32 alpha; // 0 to 255, like TUnk_804999E8::alpha
    union {
        u32 packed_color; // color[] as one word (inferred name)
        u8 color[4];
    };
    s32 mode;           // 0 idle, 1 fade in, 2 fade out, 3 tick (inferred name)
    void (*callback)(); // called once the fade ends
};
LAYOUT_ASSERT(TUnk_80499970_size, sizeof(TUnk_80499970) == 0x2C);

#endif
