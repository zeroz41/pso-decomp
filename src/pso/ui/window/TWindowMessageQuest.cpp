#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/ui/window/TWindowBase.h"
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

struct Ctx_8026B148 {
    u8 pad0[0x28];
    f32 scaleX;
    f32 scaleY;
    s32 reveal;
};

const char *TWindowMessageQuest__name = "TWindowMessageQuest";

// create_quest_message_window_at's second argument (384 x 80: the window's size, inferred)
struct DefaultQuestMessageExtent {
    NJS_POINT2 size;
    f32 reserved;
};

static const DefaultQuestMessageExtent lbl_8044F464 = {{384.0f, 80.0f}, 0.0f};

extern "C" {

TWindowMessageQuest *create_quest_message_window() {
    return create_quest_message_window_at(reinterpret_cast<const NJS_POINT2 *>(get_window_layout_position(0xAD)), &lbl_8044F464.size);
}
void TWindowMessageQuest::render() {
    Ctx_8026B148 *c;
    c = reinterpret_cast<Ctx_8026B148 *>(get_draw_context());
    switch (frame_mode) {
    case 0:
        if (c->reveal < 0) {
            c->scaleX = (f32)((Win_8026B148 *)this)->opening / 7.5f;
            c->scaleY = c->scaleX;
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

}

TWindowMessageQuest::~TWindowMessageQuest() {

}


TWindowMessageQuest::TWindowMessageQuest(s32 parent) : TWindowMessage(parent, 1, local_client_id) {
    this->m_name = TWindowMessageQuest__name;
    frame_mode = 0;
}
