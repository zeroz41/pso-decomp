#include "types.h"
#include "pso/unk/text_801E283C.h"
#include "pso/system/date.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Tbl_801E283C { s32 v[12]; };

struct DateStamp_801E283C {
    u16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minute;
    u8 second;
    u8 weekday;
    u8 day_in_cycle;
};

extern "C" {
extern const Tbl_801E283C lbl_80449700[];
u8 calc_day_of_week(u16 year, u8 month, u8 day);
}

#pragma push
#pragma opt_propagation off
static inline int inline_fn2(u32 arg0)
{
  return arg0 / 86400;
}
extern "C" void fill_date_from_seconds(u32 seconds, DateStamp_801E283C *out) {
  unsigned int new_var;
  int new_var4;
  int new_var3;
  DateStamp_801E283C *new_var2;
  s32 tbl[12];
  unsigned int new_var5;
  s32 c24;
  s32 sixty;
  s32 c365;
  s32 *new_var6;
  *((Tbl_801E283C *) tbl) = lbl_80449700[0];
  sixty = 60;
  c365 = 365;
  c24 = 24;
  u32 minutes = seconds / sixty;
  u32 years = seconds / 31536000;
  new_var4 = seconds / 3600;
  u32 hours = new_var4;
  u32 days = inline_fn2(seconds);
  new_var5 = hours / c24;
  out->second = seconds - (minutes * sixty);
  u32 h24 = new_var5;
  new_var = h24 * c24;
  u32 leapc = (years + 1) >> 2;
  u32 m60 = minutes / sixty;
  out->minute = minutes - (m60 * sixty);
  new_var3 = days / c365;
  out->hour = hours - new_var;
  u32 yrs_365 = new_var3;
  u32 rem = days - (yrs_365 * c365);
  u32 doy;
  if (leapc <= rem)
  {
    out->year = years + 2000;
    doy = rem - leapc;
  }
  else
  {
    doy = rem + (365 - leapc);
    out->year = years + 1999;
    if ((out->year % 4) == 0)
    {
      doy += 1;
    }
  }
  u32 month = 1;
  if ((out->year % 4) == 0)
  {
    if (doy >= ((u32) tbl[1]))
    {
      for (month = 2; month < 12; month++)
      {
        new_var6 = tbl;
        new_var = (u32) new_var6[month];
        if (doy < (new_var + 1))
        {
          break;
        }
      }

    }
  }
  else
  {
    for (month = 1; month < 12; month++)
    {
      if (doy < ((u32) tbl[month]))
      {
        break;
      }
    }

  }
  u32 prev = (u32) tbl[month - 1];
  out->month = (u8) month;
  out->day = (u8) ((doy - prev) + 1);
  new_var2 = out;
  if ((out->year % (new_var4 = 4)) == 0)
  {
    if (out->month > 2)
    {
      if (years || tbl)
      {
        out->day = out->day - 1;
      }
      else
      {
        out->day = out->day - 1;
      }
    }
  }
  out->weekday = calc_day_of_week(out->year, out->month, out->day);
  out->day_in_cycle = calc_day_in_cycle((s32 *) new_var2);
}
#pragma pop

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
