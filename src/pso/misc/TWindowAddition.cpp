#include "types.h"
#include "pso/misc/TLobby_8001D6A0.h"
#include "pso/misc/TWindowSubStatusDisp_80228CC0.h"
#include "pso/misc/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowSubStatusDisp.h"

extern "C" {
extern s32 TWindowSubStatusDisp__count_ratio_value;
extern s32 lbl_805DCAB8;
void sub_802443B4__15TWindowAdditionFv(void *, void *);
void construct_base__9TWindowDDFPUcsPUc(void *);
void __dl__7TObjectFPv(void *);
void destroy_window_base__9TWindowDDFs(void *, int);

extern s32 lbl_804CDFE8[];

void *TWindowAddition::destroy_window(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804CDFE8;
        destroy_window_base__9TWindowDDFs(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TWindowAddition::construct_with_parent(void *arg1) {
    construct_base__9TWindowDDFPUcsPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804CDFE8;
    sub_802443B4__15TWindowAdditionFv(this, arg1);
    return this;
}
void TWindowSubStatusDisp::set_count_ratio_text(s32 arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    text_builder_reset();
    text_builder_append((u8 *)(TQuestVmDownLoadServer__sub_8006EF6C(0x67)));
    append_text_space();
    append_padded_number((arg1), (2U));
    text_builder_append((u8 *)&lbl_805DCAB8);
    append_padded_number((arg2), (2U));
    ((TWindowSubStatusDisp *)arg0)->set_entry_display_value((int) (get_shared_text_buffer()));
    TWindowSubStatusDisp__count_ratio_value = arg1;
}

}
