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

typedef char DrawLineKeySize[sizeof(DrawLineKey) == 8 ? 1 : -1];
typedef char DrawLineGroupSize[sizeof(DrawLineGroup) == 12 ? 1 : -1];

#endif
