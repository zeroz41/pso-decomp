#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/TAdPlyStatusGC_802E1128.h"
#include "pso/system/date.h"
#include "pso/menu/T_ATS_DrawCalendar.h"
#include "pso/ui/TAdPlyStatusGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pt_802E11D4 { f32 x, y; };

struct Date_802E11D4 { u16 year; u8 month; u8 day; u8 hour; u8 min; u8 sec; u8 wday; u32 pad8; };

struct Clock_802E11D4 { u8 pad0[0x1C]; s32 visible; Pt_802E11D4 pos; };

extern "C" {
s32 get_localized_text_entry(s32 arg0, s32 arg1);
int sprintf(char *, const char *, ...);
extern char ply_status_date_format[];
extern char ply_status_date_format_mdy[];
extern char lbl_8047296C[];
extern const f32 lbl_805DE8E8;
extern const f32 lbl_805DE8EC;
extern const f32 lbl_805DE8F0;
extern const f32 lbl_805DE8F4;

s32 TAdPlyStatusGC::get_field_498() { return *(s32*)((char*)this + 0x498); }
void*TAdPlyStatusGC::get_chara_making_data() { return (char*)this + 0x1b8; }
s32 TAdPlyStatusGC::get_field_49c() { return *(s32*)((char*)this + 0x49c); }
s32 TAdPlyStatusGC::get_field_4a0() { return *(s32*)((char*)this + 0x4a0); }
void*TAdPlyStatusGC::get_status_data() { return (char*)this + 0x324; }
s32 TAdPlyStatusGC::get_field_4a4() { return *(s32*)((char*)this + 0x4a4); }
void*TAdPlyStatusGC::get_status_sub() { return (char*)this + 0x490; }

    extern int ply_status_chcr_load_afs;
void TAdPlyStatusGC::set_status_param(int a0, int a1) { ply_status_chcr_load_afs = a1; }

    extern int ply_status_gc_instance;
int TAdPlyStatusGC::get_index() {  return ply_status_gc_instance; }

    extern int ply_status_index;
void TAdPlyStatusGC::set_status_index(int a0, int a1) { ply_status_index = a1; }

extern s32 TAdPlyStatusGC__window_offset_index;

void TAdPlyStatusGC::close_window(s32 arg1) {
    TAdPlyStatusGC__window_offset_index = arg1;
    if ((u32) this->m_6c != 0U) {
        ((TWindowBase *)this->m_6c)->close();
        this->m_6c = 0U;
    }
}

void TAdPlyStatusGC__sub_802E11BC(void* p) { *(s32*)((char*)p + 0x1c) = 0; }
void TAdPlyStatusGC__sub_802E11C8(void* p) { *(s32*)((char*)p + 0x1c) = 1; }
#pragma push
#pragma fp_contract on
void T_ATS_DrawCalendar::render() {
    Clock_802E11D4 *self = (Clock_802E11D4 *)this;
    char buf[0x24];
    Date_802E11D4 date;
    char *s;
    f32 w;
    s32 wd;
    if (self->visible != 0) {
        Pt_802E11D4 pos = self->pos;
        s = (char *)get_localized_text_entry(0x1C, 0xC);
        ((TAdSinglePlyChrSelectGC *)s)->render_status_disp(-(lbl_805DE8E8 * (f32)calc_text_width(s) - pos.x), pos.y);
        pos.y += lbl_805DE8EC;
        getDateStamp((DateStamp *)&date);
        wd = date.wday + 13;
        switch (current_language) {
        case LANGUAGE_JAPANESE:
            sprintf(buf, ply_status_date_format, date.year, date.month, date.day, get_localized_text_entry(0x1C, wd));
            s = buf;
            w = lbl_805DE8F0 * (f32)calc_text_width(s);
            break;
        default:
            sprintf(buf, ply_status_date_format_mdy, date.month, date.day, date.year, get_localized_text_entry(0x1C, wd));
            s = buf;
            w = lbl_805DE8F0 * (f32)TWindowSubStatusDisp__sub_80144E9C(s);
            break;
        }
        ((TAdSinglePlyChrSelectGC *)s)->render_status_disp(pos.x + w, pos.y);
        pos.y += lbl_805DE8F4;
        sprintf(buf, lbl_8047296C, date.hour, date.min, date.sec);
        ((TAdSinglePlyChrSelectGC *)buf)->render_status_disp(-(lbl_805DE8E8 * (f32)calc_text_width(buf) - pos.x), pos.y);
    }
}
#pragma pop

}
