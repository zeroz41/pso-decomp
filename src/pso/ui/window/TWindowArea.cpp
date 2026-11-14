#include "types.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TObjResultWin.h"
#include "pso/unk/text_8024450C.h"
#include "pso/ui/window/TWindowRoom.h"
#include "pso/ui/window/TWindowArea.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/TWindowBase.h"

extern "C" {
const char *TWindowArea__name = "TWindowArea";

extern s32 TWindowSubStatusDisp__count_ratio_value;
void sub_802443B4__15TWindowAdditionFv(void *, void *);
void construct_base__9TWindowDDFPUcsPUc(void *);
void __dl__7TObjectFPv(void *);

extern s32 lbl_804CDFE8[];

void *TWindowAddition::destroy_window(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804CDFE8;
        ((TWindowDD *)this)->destroy_window_base(0);
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
    text_builder_append((u8 *)"/");
    append_padded_number((arg2), (2U));
    ((TWindowSubStatusDisp *)arg0)->set_entry_display_value((int) (get_shared_text_buffer()));
    TWindowSubStatusDisp__count_ratio_value = arg1;
}

}


extern "C" {
s32 __nw__7TObjectFUl(int);
u8 *get_title_entry__11TWindowRoomFv(s32);
void fn_8024450C(s32 arg0) {
    s32 var_r30;
    s32 var_r31;
    s32 var_r3;
    s32 var_r5;
    var_r30 = arg0;
    var_r31 = TObjNewFloorWin__sub_8007410C();
    var_r3 = var_r30;
    var_r5 = TWindowSubComCard__sub_80244774();
    ((TWindowSubStatusDisp *)var_r3)->set_count_ratio_text(var_r31, var_r5);
}
#pragma push
#pragma fp_contract on
s32 create_area_window(s32 arg0) {
    s32 object;
    u8 *temp_r31;
    object = __nw__7TObjectFUl(0x64);
    if (object != 0) {
        object = (s32)TWindowArea__ct((u8 *)object);
    }
    ((TWindowSubStatusDisp *)object)->set_entry_display_value(arg0);
    fn_802449E0((u8 *)object);
    temp_r31 = (u8 *)(((TWindowRoom *)object)->get_title_entry());
    *(f32 *)((s8 *)temp_r31 + 8) = 80.0f - 0.5f * (f32) calc_text_width((char *)(arg0));
    return object;
}
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 create_window_area(void) {
    s32 object;
    u8 *temp_r31;
    object = __nw__7TObjectFUl(0x64);
    if (object != 0) {
        object = (s32)TWindowArea__ct((u8 *)object);
    }
    fn_802449E0((u8 *)object);
    fn_8024450C(object);
    temp_r31 = get_title_entry__11TWindowRoomFv(object);
    *(f32 *)((s8 *)temp_r31 + 8) = 80.0f - 0.5f * (f32) calc_text_width((char *)(((TWindowSubComCard *)temp_r31)->get_field_20()));
    return object;
}
#pragma pop


struct RecoveredGlobal_8024470C___vt__11TWindowArea { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8024470C___vt__11TWindowArea_size[sizeof(RecoveredGlobal_8024470C___vt__11TWindowArea) == 0x18 ? 1 : -1];

extern "C" {
u8 * get_window_layout_position(s32);
u8 * __ct__11TWindowRoomFPc(void *, s32);
extern s32 __vt__11TWindowArea[];
void __dl__7TObjectFPv(void *);

void TWindowArea::run_task() { ((TWindowDD *)this)->initialize_subwindow(); ((TWindowBase *)this)->update_window_entry_list((char*)this + 0x24); }

void *__dt__11TWindowAreaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TWindowArea;
        __dt__11TWindowRoomFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TWindowArea__ct(u8 *window_room) {
    s32 *window_layout_position;
    f32 var_f0;
    u8 *var_r31;
    u8 *var_r3;
    window_layout_position = NULL;
    var_r31 = window_room;
    __ct__11TWindowRoomFPc(window_room, 0);
    window_layout_position = (s32 *)(&(*(RecoveredGlobal_8024470C___vt__11TWindowArea *)&__vt__11TWindowArea).value);
    var_r3 = (u8 *)((void *)0x25);
    *(s32 **)((s8 *)var_r31 + 0x18) = &(*(RecoveredGlobal_8024470C___vt__11TWindowArea *)&__vt__11TWindowArea).value;
    *(s32 *)((s8 *)var_r31 + 0) = (s32) TWindowArea__name;
    var_r3 = (var_r31 + 0x40);
    window_layout_position = (s32 *)(get_window_layout_position(0x25));
    ((TWindowSubSymbolChatPartsSet *)var_r3)->copy_vec2((void*)window_layout_position);
    var_f0 = 0.0f;
    var_r3 = var_r31;
    *(f32 *)((s8 *)var_r31 + 0x60) = var_f0;
    return var_r3;
}

}
