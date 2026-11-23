#ifndef PSO_UNK_TCOLOROVERLAYFADE_H
#define PSO_UNK_TCOLOROVERLAYFADE_H
#include "types.h"
#include "pso/system/task/TObject.h"

// The quest colour overlay (qst_op_add_color_overlay): fades the screen colour from
// its current value to target_color over duration frames.
class TColorOverlayFade : public TObject {
public:
    TColorOverlayFade(TObject *parent, s32 unk_1C, s32 duration, u8 c3, u8 c0, u8 c1, u8 c2);
    virtual ~TColorOverlayFade();
    virtual void run_task();
    s32 lerp_color(f32);
    s32 unk_1C;
    s32 frame;
    s32 duration;
    u8 start_color[4];
    u8 target_color[4];
};
LAYOUT_ASSERT(TColorOverlayFade_size, sizeof(TColorOverlayFade) == 0x30);

#endif
