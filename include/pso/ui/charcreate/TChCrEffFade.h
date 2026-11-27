#ifndef PSO_UI_CHARCREATE_TCHCREFFFADE_H
#define PSO_UI_CHARCREATE_TCHCREFFFADE_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrEffFade : public TObject {
public:
    static const char *class_name;
    TChCrEffFade(s32 new_step, s32 new_length, s32 unused);
    virtual ~TChCrEffFade();
    virtual void run_task();
    virtual void render();
public:
    void update_fade();
    void draw_fade_strip(f32 alpha);

    s32 step;
    s32 length;
    s32 frame;
    f32 alpha;
    s32 mode;
};

LAYOUT_ASSERT(TChCrEffFade_size, sizeof(TChCrEffFade) == 0x30);

TChCrEffFade *create_fade_effect(s32 duration, s32 mode);

void draw_hexagon(void *context, void *center, u32 color, f32 scale, f32 alpha);
void draw_hexagon_grid(void *context, f32 scale);

#endif
