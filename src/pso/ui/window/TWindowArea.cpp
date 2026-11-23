#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowArea.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TObjResultWin.h"
#include "pso/ui/window/TWindowRoom.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/vector.h"

// The functions are generated last to first.
#pragma defer_codegen on

s32 TWindowSubStatusDisp__count_ratio_value;
const char *TWindowArea__name = "TWindowArea";

extern "C" {
u8 *get_window_layout_position(s32);
}

TWindowArea::TWindowArea() : TWindowRoom(NULL) {
    this->m_name = TWindowArea__name;
    u8 *position = get_window_layout_position(0x25);
    copy_vec2(frame_position, position);
    this->tabParameter = 0.0f;
}

TWindowArea::~TWindowArea() {}

void TWindowArea::run_task() { ((TWindowDD *)this)->initialize_subwindow(); this->update_window_entry_list(&entry_list); }

#pragma push
#pragma fp_contract on
TWindowArea *create_window_area() {
    TWindowArea *object;
    u8 *title_entry;
    object = new TWindowArea();
    fn_802449E0((u8 *)object);
    fn_8024450C(reinterpret_cast<saddr>(object));
    title_entry = (u8 *)((TWindowRoom *)object)->get_title_entry();
    *(f32 *)((s8 *)title_entry + 8) = 80.0f - 0.5f * (f32) calc_text_width((char *)(((TWindowSubComCard *)title_entry)->get_field_20()));
    return object;
}
#pragma pop

extern "C" {
#pragma push
#pragma fp_contract on
TWindowArea *create_area_window(void *text) {
    TWindowArea *object;
    u8 *title_entry;
    object = new TWindowArea();
    ((TWindowSubStatusDisp *)object)->set_entry_display_value((saddr)text);
    fn_802449E0((u8 *)object);
    title_entry = reinterpret_cast<u8 *>(object->get_title_entry());
    *(f32 *)((s8 *)title_entry + 8) = 80.0f - 0.5f * (f32) calc_text_width((char *)text);
    return object;
}
#pragma pop
}

extern "C" {
void fn_8024450C(s32 arg0) {
    s32 var_r30;
    s32 var_r31;
    saddr var_r3;
    s32 var_r5;
    var_r30 = arg0;
    var_r31 = TObjNewFloorWin__sub_8007410C();
    var_r3 = var_r30;
    var_r5 = TWindowSubComCard__sub_80244774();
    ((TWindowSubStatusDisp *)var_r3)->set_count_ratio_text(var_r31, var_r5);
}
}

void TWindowSubStatusDisp::set_count_ratio_text(s32 arg1, s32 arg2) {
    saddr arg0 = (saddr)this;
    text_builder_reset();
    text_builder_append((u8 *)(get_message_text(0x67)));
    append_text_space();
    append_padded_number((arg1), (2U));
    text_builder_append((u8 *)"/");
    append_padded_number((arg2), (2U));
    ((TWindowSubStatusDisp *)arg0)->set_entry_display_value((saddr) (get_shared_text_buffer()));
    TWindowSubStatusDisp__count_ratio_value = arg1;
}

TWindowAddition::TWindowAddition(u8 *descriptor, s16 client, u8 *parent)
    : TWindowBase(descriptor, client, parent) {
    sub_802443B4(descriptor);
}

TWindowAddition::~TWindowAddition() {}
