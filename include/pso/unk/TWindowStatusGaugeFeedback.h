#ifndef PSO_UNK_TWINDOW_STATUS_GAUGE_FEEDBACK_H
#define PSO_UNK_TWINDOW_STATUS_GAUGE_FEEDBACK_H
#include "types.h"
#include "pso/unk/TWindowStatusGauge.h"

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
    s32 m_2c;
    u8 unk_30[0x30];
    s32 rising_color;
    s32 falling_color;
};

LAYOUT_ASSERT(TWindowStatusGaugeFeedback_size, sizeof(TWindowStatusGaugeFeedback) == 0x68);

#endif
