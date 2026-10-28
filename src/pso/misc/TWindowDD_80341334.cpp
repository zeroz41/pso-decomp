#include "types.h"
#include "pso/misc/TWindowDD_80341334.h"
#include "pso/misc/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/misc/TWindowDD_WS_String.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

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
extern s32 lbl_805D42D8;
extern const s32 lbl_805DFC18;
extern const f32 lbl_805DFC94;
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
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D42D8;
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x64))->copy_vec2((void *)arg1);
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x6C))->copy_vec2((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x60) = arg4;
    window_help_item = (u8 *)(((TUnk_804CE018 *)arg0)->get_array_entry(0));
    if (window_help_item != NULL) {
        set_text_entry_string((window_help_item), (str), 0x80);
        ((TWindowHelpItem *)window_help_item)->m_8 = (f32) lbl_805DFC94;
        *(f32 *)((s8 *)window_help_item + 0xC) = (f32) lbl_805DFC94;
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

void TWindowDD__sub_803414DC(void) {
    *(s32 *)((s8 *)&lbl_804EFC00.value + 0x18) = (s32) TWindowDD__data_805DFC14;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_803414DC_TWindowDD__data_804EFC24 *)&TWindowDD__data_804EFC24).value) + 8) = (f32) lbl_805DFC20;
}


}
