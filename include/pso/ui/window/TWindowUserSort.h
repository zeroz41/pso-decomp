#ifndef PSO_UI_WINDOW_TWINDOWUSERSORT_H
#define PSO_UI_WINDOW_TWINDOWUSERSORT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct GuildCardRecord;

struct TWindowUserSort : public TWindowBase {
    TWindowUserSort(saddr position, GuildCardRecord *record);
    virtual void render();
    virtual ~TWindowUserSort();
    static const char *class_name;
    GuildCardRecord *m_60;
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowUserSort_size, sizeof(TWindowUserSort) == 0x64);
#endif
