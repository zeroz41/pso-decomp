#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard.h"
struct CompleteRevealLine { u32 flags; u32 f4; };

struct CompleteRevealWindow { u8 pad[0x5c]; u32 f5c; u8 pad2[0xc]; f32 f6c; u8 pad3[0xc]; CompleteRevealLine *lines; u8 pad4[4]; f32 f84; u8 pad5[4]; u32 count; };

struct IsMessageWindowReadyWindow { u8 pad[0x6c]; f32 f6c; u8 pad2[0x84 - 0x70]; f32 f84; u8 pad3[4]; u32 count; };


s32 TWindowMessagePage::is_message_window_ready() {
    WindowTextEntry *e;
    u32 i;
    if (((TWindowBase *)this)->is_window_reveal_complete() == 0) {
        return 0;
    }
    if (((struct IsMessageWindowReadyWindow *)this)->f6c != ((struct IsMessageWindowReadyWindow *)this)->f84) {
        return 0;
    }
    for (i = 0; i < ((struct IsMessageWindowReadyWindow *)this)->count; i++) {
        e = (WindowTextEntry *)((TWindowBase *)this)->get_array_entry(i);
        if (e->get_text() != NULL && !(e->flags & 0x10)) {
            return 0;
        }
    }
    return 1;
}

void TWindowMessage::complete_reveal() {
    CompleteRevealLine *lines;
    u32 i;
    WindowTextEntry *e;
    ((CompleteRevealWindow *)this)->f5c = 0x01000000;
    ((CompleteRevealWindow *)this)->f6c = ((CompleteRevealWindow *)this)->f84;
    for (i = 0; i < ((CompleteRevealWindow *)this)->count; i++) {
        e = (WindowTextEntry *)((TWindowBase *)this)->get_array_entry(i);
        lines = ((CompleteRevealWindow *)this)->lines;
        if (e->get_text() != NULL) {
            if (lines[i].flags & 8) {
                lines[i].flags &= ~8;
                e->flags &= ~8;
            }
            e->reveal_all();
        }
    }
}
