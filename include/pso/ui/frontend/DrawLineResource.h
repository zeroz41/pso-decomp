#ifndef PSO_UI_DRAWLINERESOURCE_H
#define PSO_UI_DRAWLINERESOURCE_H

#include "types.h"

struct DrawLineRecord;

struct DrawLineKey {
    s32 key;
    s32 line_index;
};

struct DrawLineGroup {
    s32 key_count;
    DrawLineKey *keys;
    DrawLineRecord *lines;
};

void free_draw_line_task_resource();
void load_draw_line_task_resource();

// Relocated AdDrawLineTask.prs root; one group per controller.
extern DrawLineGroup *draw_line_task_data;

LAYOUT_ASSERT(DrawLineKeySize, sizeof(DrawLineKey) == 8);
LAYOUT_ASSERT(DrawLineGroupSize, sizeof(DrawLineGroup) == 12);

#endif
