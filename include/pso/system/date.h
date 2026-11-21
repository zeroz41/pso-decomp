#ifndef PSO_SYSTEM_DATE_H
#define PSO_SYSTEM_DATE_H

#include "types.h"

struct DateStamp {
    u16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minute;
    u8 second;
    u8 weekday;
    u8 _pad;
};

// Timestamp recorded by the memory-card write request.
struct CardWriteDate {
    u16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minute;
    u8 second;
    u8 weekday;
};

LAYOUT_ASSERT(CardWriteDate_size, sizeof(CardWriteDate) == 8);

int getDateStamp(DateStamp *out);
void DateToSeconds(DateStamp *date, int *seconds);

#endif
