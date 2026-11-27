#ifndef PSO_UI_WINDOW_TWINDOWAREA_H
#define PSO_UI_WINDOW_TWINDOWAREA_H

#include "types.h"
#include "pso/ui/window/TWindowRoom.h"

class TWindowArea : public TWindowRoom {
public:
    static const char *class_name;
    // The count last shown by set_count_ratio_text; the area map window reads it back.
    static s32 count_ratio_value;
    TWindowArea();
    virtual ~TWindowArea();
    virtual void run_task();
    // Shows "<label> count/total" in the title entry.
    void set_count_ratio_text(s32 count, s32 total);
};

void update_area_count_text(TWindowArea *area);
TWindowArea *create_area_window(const char *text);
TWindowArea *create_window_area();

#endif
