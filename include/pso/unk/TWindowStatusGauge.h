#ifndef PSO_UNK_TWINDOW_STATUS_GAUGE_H
#define PSO_UNK_TWINDOW_STATUS_GAUGE_H
#include "types.h"
#include <stddef.h>
#include "pso/unk/TWindowLayoutEntry.h"

struct NJS_POINT2;

struct StatusGaugeLayout;

// A layout entry that renders a gauge and moves its displayed width toward a target.
class TWindowStatusGauge : public TWindowLayoutEntry {
public:
    virtual ~TWindowStatusGauge();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    virtual void calc_bar_width();

    f32 depth;
    f32 x;
    f32 y;
    f32 scale;
    u32 color;
    f32 width;
    f32 maximum;
    f32 target;

    TWindowStatusGauge(StatusGaugeLayout *source, s32 client);
    void draw_status_gauge_bar(WindowDrawContext *context, NJS_POINT2 *position, f32 depth, f32 length);
};

LAYOUT_ASSERT(TWindowStatusGauge_size, sizeof(TWindowStatusGauge) == 0x28);
LAYOUT_ASSERT(TWindowStatusGauge_target_offset, offsetof(TWindowStatusGauge, target) == 0x24);

#endif
