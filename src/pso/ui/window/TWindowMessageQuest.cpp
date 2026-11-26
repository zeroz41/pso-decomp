#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TLobby_8026B06C.h"
#include "pso/network/client_id.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowLayout.h"

#pragma readonly_strings on

struct Win_8026B148 {
    u8 pad0[0x24];
    u8 entries[0x5C - 0x24];
    s32 opening;
    u8 pad1[0x90 - 0x60];
};

const char *TWindowMessageQuest::class_name = "TWindowMessageQuest";

// create_quest_message_window_at's second argument (384 x 80: the window's size, inferred)
struct DefaultQuestMessageExtent {
    NJS_POINT2 size;
    f32 reserved;
};

static const DefaultQuestMessageExtent lbl_8044F464 = {{384.0f, 80.0f}, 0.0f};


TWindowMessageQuest *create_quest_message_window() {
    return create_quest_message_window_at(reinterpret_cast<const NJS_POINT2 *>(get_window_layout_position(0xAD)), &lbl_8044F464.size);
}
void TWindowMessageQuest::render() {
    WindowDrawContext *c;
    c = get_draw_context();
    switch (frame_mode) {
    case 0:
        if (c->open_tick < 0) {
            c->scale[0] = (f32)((Win_8026B148 *)this)->opening / 7.5f;
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
    draw_visible_window_entries(
        reinterpret_cast<const void *>(((Win_8026B148 *)this)),
        reinterpret_cast<const WindowLayoutEntries *>(((Win_8026B148 *)this)->entries),
        reinterpret_cast<WindowDrawContext *>(c));
}


TWindowMessageQuest::~TWindowMessageQuest() {

}


TWindowMessageQuest::TWindowMessageQuest(const NJS_POINT2 *position) : TWindowMessage(position, 1, local_client_id) {
    this->m_name = TWindowMessageQuest::class_name;
    frame_mode = 0;
}
