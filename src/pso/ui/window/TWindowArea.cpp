#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowArea.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
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
#include "pso/ui/window/WindowTextEntry.h"

// The functions are generated last to first.
#pragma defer_codegen on

s32 TWindowSubStatusDisp::count_ratio_value;
const char *TWindowArea::class_name = "TWindowArea";

TWindowArea::TWindowArea() : TWindowRoom(NULL) {
    this->m_name = TWindowArea::class_name;
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
    WindowTextEntry *title_entry;
    object = new TWindowArea();
    hide_window((u8 *)object);
    update_area_count_text(object);
    title_entry = static_cast<WindowTextEntry *>(object->get_title_entry());
    title_entry->x = 80.0f - 0.5f * (f32) calc_text_width(title_entry->get_text());
    return object;
}
#pragma pop

#pragma push
#pragma fp_contract on
TWindowArea *create_area_window(const char *text) {
    TWindowArea *object;
    WindowTextEntry *title_entry;
    object = new TWindowArea();
    ((TWindowSubStatusDisp *)object)->set_entry_display_value(text);
    hide_window((u8 *)object);
    title_entry = static_cast<WindowTextEntry *>(object->get_title_entry());
    title_entry->x = 80.0f - 0.5f * (f32) calc_text_width((char *)text);
    return object;
}
#pragma pop

void update_area_count_text(TWindowArea *area) {
    s32 count = get_current_lobby_id();
    s32 total = get_area_total();
    ((TWindowSubStatusDisp *)area)->set_count_ratio_text(count, total);
}

void TWindowSubStatusDisp::set_count_ratio_text(s32 count, s32 total) {
    text_builder_reset();
    text_builder_append((const char *)(get_message_text(0x67)));
    append_text_space();
    append_padded_number((count), (2U));
    text_builder_append("/");
    append_padded_number((total), (2U));
    this->set_entry_display_value(get_shared_text_buffer());
    TWindowSubStatusDisp::count_ratio_value = count;
}

TWindowAddition::TWindowAddition(u8 *descriptor, s16 client, u8 *parent)
    : TWindowBase(descriptor, client, parent) {
    init_addition(descriptor);
}

TWindowAddition::~TWindowAddition() {}
