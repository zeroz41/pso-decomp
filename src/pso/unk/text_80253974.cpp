#include "pso/item/MagStats.h"
#include "types.h"
#include "pso/unk/text_80253974.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItemData.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

class Win_80253D10;
typedef void (Win_80253D10::*PM_80253D10)();
struct VBase_80253D10 { u8 pad[4]; };

struct VBar_80253D10 : VBase_80253D10 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

extern "C" {
extern const f32 lbl_805DCDF0;
s32 init_window_layout_entries(void *, void *, s16);
s32 refresh_status_display__9TWindowDDFv(void *);
extern u8 lbl_804CF30C[];
extern PM_80253D10 TWindowHelpItem__mag_growth_update_callback;
extern const f32 lbl_805DCDF4;
extern const f32 lbl_805DCDF8;
s32 TItemData::update_mag_status_gauges() {
    s32 sp8[4];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 var_r31;
    ((MagStats *)sp8)->init();
    var_r31 = 0;
    TItemData::deserialize_mag((void *)(*(saddr *)((s8 *)((u8 *)this) + 0x68)), (void *)sp8);
    a = ((TWindowBase *)((u8 *)this))->get_array_entry(0);
    b = ((TWindowBase *)((u8 *)this))->get_array_entry(1);
    c = ((TWindowBase *)((u8 *)this))->get_array_entry(2);
    d = ((TWindowBase *)((u8 *)this))->get_array_entry(0xF);
    ((TWindowSubStatusDisp *)a)->clear_visible_flag();
    ((TWindowHelpItem *)d)->set_flag0_bit2();
    ((TWindowHelpItem *)b)->set_compare_color((s32) ((MagStats *)sp8)->get_synchro());
    ((TWindowHelpItem *)c)->set_compare_color((s32) ((MagStats *)sp8)->get_iq());
    b = ((TWindowBase *)((u8 *)this))->get_array_entry(4);
    a = ((TWindowBase *)((u8 *)this))->get_array_entry(5);
    if ((s32) *(s32 *)((s8 *)b + 0x20) < ((MagStats *)sp8)->get_def_level()) {
        var_r31 = 1;
        *(f32 *)((s8 *)a + 0x24) = (f32) lbl_805DCDF0;
    } else {
        if (*(f32 *)((s8 *)a + 0x24) != (f32) ((MagStats *)(sp8))->get_def_progress()) {
            var_r31 = 1;
        }
        *(f32 *)((s8 *)a + 0x24) = (f32) ((MagStats *)(sp8))->get_def_progress();
    }
    b = ((TWindowBase *)((u8 *)this))->get_array_entry(7);
    a = ((TWindowBase *)((u8 *)this))->get_array_entry(8);
    if ((s32) *(s32 *)((s8 *)b + 0x20) < ((MagStats *)sp8)->get_pow_level()) {
        var_r31 = 1;
        *(f32 *)((s8 *)a + 0x24) = (f32) lbl_805DCDF0;
    } else {
        if (*(f32 *)((s8 *)a + 0x24) != (f32) ((MagStats *)(sp8))->get_pow_progress()) {
            var_r31 = 1;
        }
        *(f32 *)((s8 *)a + 0x24) = (f32) ((MagStats *)(sp8))->get_pow_progress();
    }
    a = ((TWindowBase *)((u8 *)this))->get_array_entry(0xA);
    b = ((TWindowBase *)((u8 *)this))->get_array_entry(0xB);
    if ((s32) *(s32 *)((s8 *)a + 0x20) < ((MagStats *)sp8)->get_dex_level()) {
        var_r31 = 1;
        *(f32 *)((s8 *)b + 0x24) = (f32) lbl_805DCDF0;
    } else {
        if (*(f32 *)((s8 *)b + 0x24) != (f32) ((MagStats *)(sp8))->get_dex_progress()) {
            var_r31 = 1;
        }
        *(f32 *)((s8 *)b + 0x24) = (f32) ((MagStats *)(sp8))->get_dex_progress();
    }
    b = ((TWindowBase *)((u8 *)this))->get_array_entry(0xD);
    a = ((TWindowBase *)((u8 *)this))->get_array_entry(0xE);
    if ((s32) *(s32 *)((s8 *)b + 0x20) < ((MagStats *)sp8)->get_mind_level()) {
        var_r31 = 1;
        *(f32 *)((s8 *)a + 0x24) = (f32) lbl_805DCDF0;
    } else {
        if (*(f32 *)((s8 *)a + 0x24) != (f32) ((MagStats *)(sp8))->get_mind_progress()) {
            var_r31 = 1;
        }
        *(f32 *)((s8 *)a + 0x24) = (f32) ((MagStats *)(sp8))->get_mind_progress();
    }
    return var_r31;
}
#pragma push
#pragma fp_contract on
void TWindowHelpItem__vt10(u8 *window_base) {
    s32 mag[4];
    s32 a;
    s32 b;
    s32 c;
    s32 lv;
    s32 sy;
    s32 iq;
    s32 up;
    ((MagStats *)mag)->init();
    init_window_layout_entries(window_base + 0x24, lbl_804CF30C, *(s16 *)((s8 *)window_base + 0x20));
    *(PM_80253D10 *)((s8 *)window_base + 0xB0) = TWindowHelpItem__mag_growth_update_callback;
    TItemData::deserialize_mag((void *)(*(saddr *)((s8 *)window_base + 0x68)), (void *)mag);
    lv = ((TWindowBase *)window_base)->get_array_entry(0);
    sy = ((TWindowBase *)window_base)->get_array_entry(1);
    iq = ((TWindowBase *)window_base)->get_array_entry(2);
    up = ((TWindowBase *)window_base)->get_array_entry(0xF);
    ((TWindowHelpItem *)lv)->set_help_text((saddr)TWindowSubStatusDisp::get_message_10(0xA2));
    ((TWindowHelpItem *)sy)->set_help_text((saddr)TWindowSubStatusDisp::get_message_10(0xA3));
    ((TWindowHelpItem *)iq)->set_help_text((saddr)TWindowSubStatusDisp::get_message_10(0xA4));
    ((TWindowHelpItem *)sy)->set_flag0_bit20();
    ((TWindowHelpItem *)lv)->set_flag4_and_field1c(((MagStats *)(mag))->get_level());
    ((TWindowHelpItem *)sy)->set_flag4_and_field1c(((MagStats *)mag)->get_synchro());
    ((TWindowHelpItem *)iq)->set_flag4_and_field1c(((MagStats *)mag)->get_iq());
    refresh_status_display__9TWindowDDFv((void *) up);
    *(f32 *)((s8 *)up + 8) = -(lbl_805DCDF8 * *(f32 *)((s8 *)up + 0x10) - lbl_805DCDF4);
    ((TWindowHelpItem *)up)->set_flag0_bit2();
    a = ((TWindowBase *)window_base)->get_array_entry(3);
    b = ((TWindowBase *)window_base)->get_array_entry(4);
    c = ((TWindowBase *)window_base)->get_array_entry(5);
    ((TWindowHelpItem *)a)->reset_float_field();
    *(s32 *)((s8 *)b + 0x20) = ((MagStats *)mag)->get_def_level();
    *(f32 *)((s8 *)c + 0x24) = (f32) ((MagStats *)(mag))->get_def_progress();
    ((VBar_80253D10 *) c)->m3();
    a = ((TWindowBase *)window_base)->get_array_entry(6);
    b = ((TWindowBase *)window_base)->get_array_entry(7);
    c = ((TWindowBase *)window_base)->get_array_entry(8);
    ((TWindowHelpItem *)a)->reset_float_field();
    *(s32 *)((s8 *)b + 0x20) = ((MagStats *)mag)->get_pow_level();
    *(f32 *)((s8 *)c + 0x24) = (f32) ((MagStats *)(mag))->get_pow_progress();
    ((VBar_80253D10 *) c)->m3();
    a = ((TWindowBase *)window_base)->get_array_entry(9);
    b = ((TWindowBase *)window_base)->get_array_entry(0xA);
    c = ((TWindowBase *)window_base)->get_array_entry(0xB);
    ((TWindowHelpItem *)a)->reset_float_field();
    *(s32 *)((s8 *)b + 0x20) = ((MagStats *)mag)->get_dex_level();
    *(f32 *)((s8 *)c + 0x24) = (f32) ((MagStats *)(mag))->get_dex_progress();
    ((VBar_80253D10 *) c)->m3();
    a = ((TWindowBase *)window_base)->get_array_entry(0xC);
    b = ((TWindowBase *)window_base)->get_array_entry(0xD);
    c = ((TWindowBase *)window_base)->get_array_entry(0xE);
    ((TWindowHelpItem *)a)->reset_float_field();
    *(s32 *)((s8 *)b + 0x20) = ((MagStats *)mag)->get_mind_level();
    *(f32 *)((s8 *)c + 0x24) = (f32) ((MagStats *)(mag))->get_mind_progress();
    ((VBar_80253D10 *) c)->m3();
}
#pragma pop

}
