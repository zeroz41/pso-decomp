#ifndef PSO_UNK_TEXT_801E283C_H
#define PSO_UNK_TEXT_801E283C_H

#include "types.h"

struct DateStamp;

u8 calc_day_in_cycle(s32 *date);

// --- C functions defined in text_801E283C.cpp ---
extern "C" {
void fill_date_from_seconds(u32 secs, DateStamp *out);
u8 calc_day_of_week(u16 year, u8 month, u8 day);
}
// --- end of C functions

#endif
