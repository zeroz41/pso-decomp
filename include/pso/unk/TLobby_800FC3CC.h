#ifndef PSO_UNK_TLOBBY_800FC3CC_H
#define PSO_UNK_TLOBBY_800FC3CC_H

#include "types.h"

struct GlyphMetrics {
    f32 width;
    f32 y_offset;
};

extern GlyphMetrics *small_font_metrics_table_ptr;

extern "C" {
void TLobby__sub_800FC3CC(void);
}

// --- C functions defined in TLobby_800FC3CC.cpp ---
extern "C" {
void TLobby__sub_800FC3CC(void);
}
// --- end of C functions

#endif
