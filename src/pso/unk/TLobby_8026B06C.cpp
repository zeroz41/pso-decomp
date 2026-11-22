#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/unk/TLobby_8026B06C.h"

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
    TLobby__sub_80269DA4(extent, 1);
    return new TWindowMessageQuest(reinterpret_cast<saddr>(position));
}
