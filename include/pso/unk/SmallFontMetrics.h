#ifndef PSO_UNK_SMALLFONTMETRICS_H
#define PSO_UNK_SMALLFONTMETRICS_H

#include "types.h"

struct GlyphMetrics {
    f32 width;
    f32 y_offset;
};

extern GlyphMetrics *small_font_metrics_table_ptr;

#endif
