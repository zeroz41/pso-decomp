#include "types.h"
#include "pso/misc/TWindowDD_803411E8.h"
#include "pso/misc/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

extern const f32 TWindowDD__data_805DFB58;
extern const f32 lbl_805DFC98;
void TWindowDD::init_and_set_field50(void *arg1) {
    ((TWindowSubSymbolChatPartsSet *)((char *)this + 48))->copy_vec2((void *)((void *)((char *)this + 100)));
    *(void **)((s8 *)this + 0x50) = arg1;
}

extern const f32 lbl_805DFC94;

void TWindowDD::update_position(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x30))->copy_vec2(arg0 + 0x6C);
    *(s32 *)((s8 *)arg0 + 0x50) = arg1;
    if (*(f32 *)((s8 *)arg0 + 0x6C) < lbl_805DFC94) {
        *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)((s8 *)arg0 + 0x30) - *(f32 *)((s8 *)arg0 + 0x38));
    }
    if (*(f32 *)((s8 *)arg0 + 0x70) < lbl_805DFC94) {
        *(f32 *)((s8 *)arg0 + 0x34) = (f32) (*(f32 *)((s8 *)arg0 + 0x34) - *(f32 *)((s8 *)arg0 + 0x3C));
    }
}

#pragma push
#pragma fp_contract on
void TWindowDD__sub_803412A0(u8 *arg0) {
    s32 temp_r3;
    temp_r3 = ((TWindowBase *)arg0)->get_array_entry(0);
    if (temp_r3 != 0) {
        TWindowDD::refresh_status_display();
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) ((lbl_805DFC98 * TWindowDD__data_805DFB58) + *(f32 *)((s8 *)temp_r3 + 0x10));
    }
}
#pragma pop

void TWindowDD::set_first_entry_text(u32 str) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((TWindowBase *)arg0)->get_array_entry(0));
    if (temp_r3 != NULL) {
        set_text_entry_string(temp_r3, str, 0x80);
    }
}
