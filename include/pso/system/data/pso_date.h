#ifndef PSO_SYSTEM_DATA_PSO_DATE_H
#define PSO_SYSTEM_DATA_PSO_DATE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

struct DateStamp;

u8 calc_day_in_cycle(s32 *date);

extern "C" {
void fill_date_from_seconds(u32 secs, DateStamp *out);
u8 calc_day_of_week(u16 year, u8 month, u8 day);
void fn_801E2C50(void);
}
void reset_system(void);
extern "C" {
void system_reset(void);
}

// Draw a Ginja model posed by a blend of two motions.
void draw_ginja_motion_link(NJS_OBJECT *model, NJS_MOTION_LINK *link, f32 frame);

#endif
