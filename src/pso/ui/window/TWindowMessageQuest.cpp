#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/unk/TLobby_8026B06C.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/network/client_id.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowLayout.h"

extern "C" {
int append_message_window_line(TWindowMessage *window, s32 text, s32 flags, s32 color);
void TWindowMessageQuest::set_frame_mode(s32 mode) {
    frame_mode = mode;
}
}

int dispatch_message_window_text(TWindowMessageQuest *window, s32 text, s32 flags) {
    switch (window->frame_mode) {
    case 0:
        return append_message_window_line(window, text, flags, 0xFF000000);
    case 1:
    case 2:
        return window->append_line(text, flags);
    default:
        return 0;
    }
}

TWindowMessageQuest *create_quest_message_window_at(const NJS_POINT2 *position, const NJS_POINT2 *extent) {
    set_message_window_size(extent, 1);
    return new TWindowMessageQuest(position);
}

#pragma readonly_strings on

const char *TWindowMessageQuest::class_name = "TWindowMessageQuest";

static const DefaultQuestMessageExtent default_quest_message_extent = {{384.0f, 80.0f}, 0.0f};


TWindowMessageQuest *create_quest_message_window() {
    return create_quest_message_window_at(reinterpret_cast<const NJS_POINT2 *>(get_window_layout_position(0xAD)), &default_quest_message_extent.size);
}
void TWindowMessageQuest::render() {
    WindowDrawContext *c;
    c = get_draw_context();
    switch (frame_mode) {
    case 0:
        if (c->open_tick < 0) {
            c->scale[0] = (f32)open_tick / 7.5f;
            c->scale[1] = c->scale[0];
        }
        this->draw_quest_message_frame(c);
        break;
    case 1:
        draw_window_frame(c);
        break;
    case 2:
        break;
    }
    draw_visible_window_entries(this, &entry_list, c);
}


TWindowMessageQuest::~TWindowMessageQuest() {

}


TWindowMessageQuest::TWindowMessageQuest(const NJS_POINT2 *position) : TWindowMessage(position, 1, local_client_id) {
    this->m_name = TWindowMessageQuest::class_name;
    frame_mode = 0;
}
