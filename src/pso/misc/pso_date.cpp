#include "types.h"
#include "pso/misc/pso_date.h"
#include "pso/misc/TCameraCtrl_803D6538.h"
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
void draw_ginja_model_lists();
extern void *model_draw_context;
extern const Tbl_801E2B24 date_month_start_days[] = {
    {{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}}
};
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
    bind_motion_blend_channels((u8 *)link, frame);
    void *g = model_draw_context;
    *(void (**)())((s8 *)g + 0xC) = draw_ginja_model_lists;
    prepare_ginja_model(g);
    TObjPlayer::render_model_tree(model);
    end_ginja_model_draw();
}
