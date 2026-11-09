#include "types.h"
#include "pso/unk/text_801E283C.h"
#include "pso/system/date.h"

// Breaks a count of seconds since 2000-01-01 into a DateStamp.
void fill_date_from_seconds(u32 secs, DateStamp *out) {
    u32 days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    u32 leaps;
    u32 years;
    u32 yday;
    u32 total;
    u32 m;
    out->second = secs % 60;
    out->minute = (secs / 60) % 60;
    out->hour = (secs / 3600) % 24;
    total = secs / 86400;
    years = secs / 31536000;
    leaps = years + 1;
    leaps /= 4;
    yday = total % 365;
    if (leaps <= yday) {
        out->year = years + 2000;
        yday -= leaps;
    } else {
        yday += 365 - leaps;
        out->year = years + 1999;
        if (out->year % 4 == 0) {
            yday++;
        }
    }
    m = 1;
    if (out->year % 4 == 0) {
        if (yday >= days[1]) {
            for (m = 2; m < 12; m++) {
                if (yday < days[m] + 1) {
                    break;
                }
            }
        }
    } else {
        for (m = 1; m < 12; m++) {
            if (yday < days[m]) {
                break;
            }
        }
    }
    yday -= days[m - 1];
    out->month = m;
    out->day = yday + 1;
    if (out->year % 4 == 0 && out->month > 2) {
        out->day--;
    }
    out->weekday = calc_day_of_week(out->year, out->month, out->day);
    out->_pad = calc_day_in_cycle((s32 *)out);
}

u8 calc_day_in_cycle(s32 *date) {
    u32 sp8;
    u32 var_r4;
    DateToSeconds((DateStamp *)date, (int *)&sp8);
    if (sp8 >= 0x5CB417D1U) {
        var_r4 = sp8 - 0x5CB417D1U;
        var_r4 = var_r4 % 0x26EE7FU;
    } else {
        var_r4 = 0x5CB417D1U - sp8;
        var_r4 = var_r4 % 0x26EE7FU;
        var_r4 = 0x26EE7FU - var_r4;
    }
    return (u8) (var_r4 / 86400U);
}

u8 calc_day_of_week(u16 year, u8 month, u8 day) {
    if (month <= 2) {
        year--;
        month += 12;
    }
    return (year + (year >> 2) - 15 + (13 * month + 8) / 5 + day) % 7;
}
