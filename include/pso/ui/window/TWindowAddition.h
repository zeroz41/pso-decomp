#ifndef PSO_UI_WINDOW_TWINDOWADDITION_H
#define PSO_UI_WINDOW_TWINDOWADDITION_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowAddition : public TWindowBase {
public:
    static const char *class_name;
    TWindowAddition(u8 *descriptor, s16 client, u8 *parent);
    virtual ~TWindowAddition();
    s32 sub_80266B18(s32);
    void init_addition(u8 *descriptor);
    WindowDrawContext *get_draw_context();
    void step_window_tween();
    void set_position_xy(f32, f32);

    f32 content_scale[2];
    f32 scroll_offset[2];
};

LAYOUT_ASSERT(WindowAdditionSize, sizeof(TWindowAddition) == 0x70);
LAYOUT_ASSERT(WindowContentScaleOffset, offsetof(TWindowAddition, content_scale) == 0x60);
LAYOUT_ASSERT(WindowScrollOffset, offsetof(TWindowAddition, scroll_offset) == 0x68);

#endif
