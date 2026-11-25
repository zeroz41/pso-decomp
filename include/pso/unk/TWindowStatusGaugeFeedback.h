#ifndef PSO_UNK_TWINDOW_STATUS_GAUGE_FEEDBACK_H
#define PSO_UNK_TWINDOW_STATUS_GAUGE_FEEDBACK_H
#include "types.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/system/NinjaTypes.h"

struct LayoutEntryCopyRecord;

// A status gauge that displays color changes and can play a sound when the value changes.
class TWindowStatusGaugeFeedback : public TWindowStatusGauge {
public:
    virtual ~TWindowStatusGaugeFeedback();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    virtual void calc_bar_width();

    TWindowStatusGaugeFeedback(LayoutEntryCopyRecord *source, s32 client);

    s16 shown;
    s16 timer;
    u32 goal_color;        // the colour the text fades to (0x00RRGGBB in the low bytes)
    NJS_ARGB fade_target;  // goal_color's channels as floats
    NJS_ARGB fade_current;
    NJS_ARGB fade_step;    // per-frame change, (target - current) / frames
    s32 rising_color;
    s32 falling_color;

    // Steps fade_current toward fade_target; returns the colour to draw and clears flag 0x40 when done.
    u32 update_text_color_transition();
    // Starts a fade to rgb over time frames, unless rgb is already the goal.
    void start_text_color_transition(u32 rgb, f32 time);
};

LAYOUT_ASSERT(TWindowStatusGaugeFeedback_size, sizeof(TWindowStatusGaugeFeedback) == 0x68);

#endif
