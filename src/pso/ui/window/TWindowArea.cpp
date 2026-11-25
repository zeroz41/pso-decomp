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
#include "pso/ui/window/WindowLayout.h"

// The functions are generated last to first.
#pragma defer_codegen on

s32 TWindowSubStatusDisp__count_ratio_value;
const char *TWindowArea__name = "TWindowArea";

TWindowArea::TWindowArea() : TWindowRoom(NULL) {
    this->m_name = TWindowArea__name;
    const NJS_POINT2 *position = get_window_layout_position(0x25);
    copy_vec2(frame_position, (void *)position);
    this->tabParameter = 0.0f;
}

TWindowArea::~TWindowArea() {}

void TWindowArea::run_task() { update_window(); this->update_window_entry_list(&entry_list); }

#pragma push
#pragma fp_contract on
TWindowArea *create_window_area() {
    TWindowArea *object;
    u8 *title_entry;
    object = new TWindowArea();
    fn_802449E0((u8 *)object);
    fn_8024450C(object);
    title_entry = (u8 *)object->get_title_entry();
    *(f32 *)((s8 *)title_entry + 8) = 80.0f - 0.5f * (f32) calc_text_width((char *)(((TWindowSubComCard *)title_entry)->get_field_20()));
    return object;
}
#pragma pop

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

void fn_8024450C(TWindowArea *area) {
    s32 count = TObjNewFloorWin__sub_8007410C();
    s32 total = get_area_total();
    ((TWindowSubStatusDisp *)area)->set_count_ratio_text(count, total);
}

void TWindowSubStatusDisp::set_count_ratio_text(s32 count, s32 total) {
    text_builder_reset();
    text_builder_append((u8 *)(get_message_text(0x67)));
    append_text_space();
    append_padded_number((count), (2U));
    text_builder_append((u8 *)"/");
    append_padded_number((total), (2U));
    this->set_entry_display_value((saddr) (get_shared_text_buffer()));
    TWindowSubStatusDisp__count_ratio_value = count;
}

TWindowAddition::TWindowAddition(u8 *descriptor, s16 client, u8 *parent)
    : TWindowBase(descriptor, client, parent) {
    sub_802443B4(descriptor);
}

TWindowAddition::~TWindowAddition() {}
