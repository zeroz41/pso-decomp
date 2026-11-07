#ifndef PSO_SYSTEM_DATA_PSO_DATE_H
#define PSO_SYSTEM_DATA_PSO_DATE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
void noop_after_system_reset(void);
}
void reset_system(void);
extern "C" {
void system_reset(void);
}

// Draw a Ginja model posed by a blend of two motions.
void draw_ginja_motion_link(NJS_OBJECT *model, NJS_MOTION_LINK *link, f32 frame);

#endif
