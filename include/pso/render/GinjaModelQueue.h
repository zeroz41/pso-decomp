#ifndef PSO_RENDER_GINJAMODELQUEUE_H
#define PSO_RENDER_GINJAMODELQUEUE_H

#include "types.h"

extern "C" {
s32 TObjPlayer__sub_803DB23C(void);
s32 TObjPlayer__sub_803DB244(void);
}
void draw_queued_models(u32 count);
void flush_model_draw_queue(void);

// --- C functions defined in GinjaModelQueue.cpp ---
extern "C" {
s32 TObjPlayer__sub_803DB23C(void);
s32 TObjPlayer__sub_803DB244(void);
}
// --- end of C functions

#endif
