#include "pso/system/ModelDrawCallback.h"
#include "types.h"
#include "pso/system/data/pso_date.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/system/date.h"
#include "dolphin/os/OSTime.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Tbl_801E2B24 { s32 v[12]; };

struct DateStamp_801E2B24 {
    u16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 min;
    u8 sec;
};

extern "C" {
void prepare_ginja_model(void *);
extern const Tbl_801E2B24 date_month_start_days[] = {
    {{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}}
};
}

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

extern "C" {
void DateToSeconds__FP9DateStampPi(DateStamp_801E2B24 *ds, s32 *out);
#pragma push
#pragma opt_propagation off
void DateToSeconds__FP9DateStampPi(DateStamp_801E2B24 *ds, s32 *out) {
    s32 tbl[12];
    *(Tbl_801E2B24 *)tbl = *date_month_start_days;
    s32 y = ds->year - 0x7D0;
    u32 t = y + 2;
    s32 d = (t >> 2) + y * 0x16D;
    if ((t & 3) == 0 && ds->month <= 2) {
        d -= 1;
    }
    d += tbl[ds->month - 1];
    d += ds->day - 1;
    *out = ds->sec + ((ds->min + ((ds->hour + d * 0x18) * 0x3C))) * 0x3C;
}
}
void end_ginja_model_draw();
#pragma pop

int getDateStamp(DateStamp* out) {
    OSCalendarTime cal;
    OSTicksToCalendarTime(OSGetTime(), &cal);
    out->year = cal.year;
    out->month = cal.mon + 1;
    out->day = cal.mday;
    out->hour = cal.hour;
    out->minute = cal.min;
    out->second = cal.sec;
    out->weekday = cal.wday;
    out->_pad = 0;
    return 1;
}

#include "pso/player/TObjPlayer.h"

extern "C" {

int OSResetSystem(int, int, int);
int VIWaitForRetrace(void);
int VIFlush(void);
int VISetBlack(int);

void fn_801E2C50(void) {  }
}
void reset_system(void) { VISetBlack(1); VIFlush(); VIWaitForRetrace(); OSResetSystem(1, 0, 0); }
void system_reset(void) { VISetBlack(1); VIFlush(); VIWaitForRetrace(); OSResetSystem(1, 0, 1); }
void draw_ginja_motion_link(NJS_OBJECT *model, NJS_MOTION_LINK *link, f32 frame) {
    bind_motion_blend_channels(link, frame);
    ModelDrawContext *g = model_draw_context;
    g->draw = draw_ginja_model_lists;
    prepare_ginja_model(g);
    TObjPlayer::render_model_tree(model);
    end_ginja_model_draw();
}
