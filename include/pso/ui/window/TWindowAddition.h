#ifndef PSO_UI_WINDOW_TWINDOWADDITION_H
#define PSO_UI_WINDOW_TWINDOWADDITION_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowAddition : public TWindowBase {
public:
    TWindowAddition(u8 *descriptor, s16 client, u8 *parent);
    virtual ~TWindowAddition();
    s32 sub_80266B18(s32);
    void sub_802443B4(u8 *descriptor);
    WindowDrawContext *get_draw_context();
    void step_window_tween();
    void set_position_xy(f32, f32);

    f32 content_scale[2];
    f32 scroll_offset[2];
};

LAYOUT_ASSERT(WindowAdditionSize, sizeof(TWindowAddition) == 0x70);
LAYOUT_ASSERT(WindowContentScaleOffset, offsetof(TWindowAddition, content_scale) == 0x60);
LAYOUT_ASSERT(WindowScrollOffset, offsetof(TWindowAddition, scroll_offset) == 0x68);

extern "C" {
// TWindowAddition::TWindowAddition(u8 *, s16, u8 *), called by the constructors that are still written by hand.
void *__ct__15TWindowAdditionFPUcsPUc(void *self, u8 *descriptor, s16 client, u8 *parent);
// TWindowAddition::~TWindowAddition(), called by the destructors that are still written by hand.
void *__dt__15TWindowAdditionFv(void *p, s16 flags);
}

#endif
