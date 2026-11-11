#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_803411E8.h"
#include "pso/ui/window/TWindowDD_80341334.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

#pragma readonly_strings on

extern "C" {

s32 draw_visible_window_entries(s32, s32, void *, f32);
int update_window_entry_list__11TWindowBaseFPv(void*, void*);
void *draw_default_entry__9TWindowDDFl();
int update_fade__11TWindowBaseFv(void*);

void TWindowDD_WS_String::render() {
    f32 ctx;
    void *temp_r3;
    s32 arg0 = (s32)this;

    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowBase *)arg0)->calc_inner_rect((u8 *)temp_r3);
    ((TWindowDD_WS_String *)arg0)->draw_entry_if_visible(temp_r3);
    ctx = *(f32 *)((s8 *)temp_r3 + 0x14);
    *(f32 *)((s8 *)temp_r3 + 0x14) += 1.0f;
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3, ctx);
}

void TWindowDD_WS_String::draw_entry_if_visible(void *arg1) {
    if ((s32) *(s32 *)((s8 *)arg1 + 0x30) >= 0) {
        draw((s32)arg1, (s32)(*(s32 *)&(*(u32 *)((u8 *)this + 0x60))), 0.0f);
    }
}

void TWindowDD::init_window() { initialize_subwindow(); update_fade__11TWindowBaseFv(this); update_window_entry_list__11TWindowBaseFPv(this, (char*)this + 0x24); }

}

extern const f32 TWindowDD__data_805DFB58;
void TWindowDD::init_and_set_field50(void *arg1) {
    ((TWindowSubSymbolChatPartsSet *)((char *)this + 48))->copy_vec2((void *)((void *)((char *)this + 100)));
    *(void **)((s8 *)this + 0x50) = arg1;
}

void TWindowDD::update_position(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x30))->copy_vec2(arg0 + 0x6C);
    *(s32 *)((s8 *)arg0 + 0x50) = arg1;
    if (*(f32 *)((s8 *)arg0 + 0x6C) < 0.0f) {
        *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)((s8 *)arg0 + 0x30) - *(f32 *)((s8 *)arg0 + 0x38));
    }
    if (*(f32 *)((s8 *)arg0 + 0x70) < 0.0f) {
        *(f32 *)((s8 *)arg0 + 0x34) = (f32) (*(f32 *)((s8 *)arg0 + 0x34) - *(f32 *)((s8 *)arg0 + 0x3C));
    }
}

void TWindowDD__sub_803412A0(u8 *arg0) {
    s32 temp_r3;
    temp_r3 = ((TWindowBase *)arg0)->get_array_entry(0);
    if (temp_r3 != 0) {
        TWindowDD::refresh_status_display();
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) ((2.0f * TWindowDD__data_805DFB58) + *(f32 *)((s8 *)temp_r3 + 0x10));
    }
}

void TWindowDD::set_first_entry_text(u32 str) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((TWindowBase *)arg0)->get_array_entry(0));
    if (temp_r3 != NULL) {
        set_text_entry_string(temp_r3, str, 0x80);
    }
}

extern "C" {
const char *lbl_805D42D8 = "TWindowDD_WS_String";
}


struct RecoveredGlobal_8034138C_TWindowDD__data_804EFC24 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8034138C_lbl_804EFC38 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_803414DC_lbl_804EFC00 {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_803414DC_TWindowDD__data_804EFC24 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8034146C_TWindowDD__data_804EFC24 {
    s32 value;
    u8 remaining[0x10];
};

extern "C" {
s32 refresh_status_display__9TWindowDDFv(int);
extern RecoveredGlobal_8034138C_TWindowDD__data_804EFC24 TWindowDD__data_804EFC24;
extern s32 lbl_804EFC38[];
extern const char *lbl_805D42D8;
extern const s32 lbl_805DFC18;
extern RecoveredGlobal_803414DC_lbl_804EFC00 lbl_804EFC00;
extern const s32 TWindowDD__data_805DFC14;
extern const f32 lbl_805DFC20;
s32 __nw__7TObjectFUl(int);
extern const f32 TWindowDD__data_805DFB20;
void __dl__7TObjectFPv(void *);

void *__dt__9TWindowDDFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EFC38;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8034138C_TWindowDD__data_804EFC24_size[sizeof(RecoveredGlobal_8034138C_TWindowDD__data_804EFC24) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_8034138C_lbl_804EFC38_size[sizeof(RecoveredGlobal_8034138C_lbl_804EFC38) == 0x18 ? 1 : -1];
u8 *TWindowDD__sub_8034138C(u8 *arg0, s32 arg1, s32 arg2, s32 str, s32 arg4) {
    s32 temp_r0;
    u8 *window_help_item;
    ((TWindowDD *)arg0)->construct_base((u8 *)&TWindowDD__data_804EFC24.value, (s16)(4), (u8 *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8034138C_lbl_804EFC38 *)&lbl_804EFC38).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) ((s32)lbl_805D42D8);
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x64))->copy_vec2((void *)arg1);
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x6C))->copy_vec2((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x60) = arg4;
    window_help_item = (u8 *)(((TWindowBase *)arg0)->get_array_entry(0));
    if (window_help_item != NULL) {
        set_text_entry_string((window_help_item), (str), 0x80);
        ((TWindowHelpItem *)window_help_item)->m_8 = 0.0f;
        *(f32 *)((s8 *)window_help_item + 0xC) = 0.0f;
        refresh_status_display__9TWindowDDFv((int)window_help_item);
        ((TWindowHelpItem *)window_help_item)->reset_float_field();
    }
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x60);
    if ((temp_r0 == 1) || (temp_r0 == 3)) {
        *(s32 *)((s8 *)window_help_item + 0x24) = (s32) lbl_805DFC18;
    }
    ((TWindowDD_WS_String *)arg0)->m_5c = 0x01000000;
    return arg0;
}
typedef char RecoveredGlobal_803414DC_lbl_804EFC00_size[sizeof(RecoveredGlobal_803414DC_lbl_804EFC00) == 0x24 ? 1 : -1];
typedef char RecoveredGlobal_803414DC_TWindowDD__data_804EFC24_size[sizeof(RecoveredGlobal_803414DC_TWindowDD__data_804EFC24) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_8034146C_TWindowDD__data_804EFC24_size[sizeof(RecoveredGlobal_8034146C_TWindowDD__data_804EFC24) == 0x14 ? 1 : -1];
s32 TWindowDD__sub_8034146C(s32 arg0, s32 arg1, s32 str, s32 arg3, f32 farg0) {
    s32 temp_r3;
    s32 var_r0;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8034146C_TWindowDD__data_804EFC24 *)&TWindowDD__data_804EFC24).value) + 0) = farg0;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8034146C_TWindowDD__data_804EFC24 *)&TWindowDD__data_804EFC24).value) + 4) = (f32) TWindowDD__data_805DFB20;
    temp_r3 = __nw__7TObjectFUl(0x74);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = ((s32)TWindowDD__sub_8034138C((u8 *)temp_r3, (s32)arg0, (s32)arg1, (s32)str, (s32)arg3));
    }
    return var_r0;
}

void __sinit_TWindowDD_80341334_cpp(void) {
    *(s32 *)((s8 *)&lbl_804EFC00.value + 0x18) = (s32) TWindowDD__data_805DFC14;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_803414DC_TWindowDD__data_804EFC24 *)&TWindowDD__data_804EFC24).value) + 8) = lbl_805DFC20;
}

static void (*s_ctor_defaults)(void) __attribute__((section(".ctors"))) = __sinit_TWindowDD_80341334_cpp;


}
