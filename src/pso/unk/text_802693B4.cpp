#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard.h"
struct Line_80269454 { u32 flags; u32 f4; };

struct Entry_80269454 { u16 flags; };

struct Win_80269454 { u8 pad[0x5c]; u32 f5c; u8 pad2[0xc]; f32 f6c; u8 pad3[0xc]; Line_80269454 *lines; u8 pad4[4]; f32 f84; u8 pad5[4]; u32 count; };

struct Win_802693B4 { u8 pad[0x6c]; f32 f6c; u8 pad2[0x84 - 0x70]; f32 f84; u8 pad3[4]; u32 count; };


s32 TWindowMessagePage::is_message_window_ready() {
    Entry_80269454 *e;
    u32 i;
    if (((TWindowBase *)this)->is_window_reveal_complete() == 0) {
        return 0;
    }
    if (((struct Win_802693B4 *)this)->f6c != ((struct Win_802693B4 *)this)->f84) {
        return 0;
    }
    for (i = 0; i < ((struct Win_802693B4 *)this)->count; i++) {
        e = (Entry_80269454 *)((TWindowBase *)this)->get_array_entry(i);
        if ((void *)((TWindowSubComCard *)e)->get_field_20() != 0 && !(e->flags & 0x10)) {
            return 0;
        }
    }
    return 1;
}

void TWindowMessage::complete_reveal() {
    Line_80269454 *lines;
    u32 i;
    Entry_80269454 *e;
    ((Win_80269454 *)this)->f5c = 0x01000000;
    ((Win_80269454 *)this)->f6c = ((Win_80269454 *)this)->f84;
    for (i = 0; i < ((Win_80269454 *)this)->count; i++) {
        e = (Entry_80269454 *)((TWindowBase *)this)->get_array_entry(i);
        lines = ((Win_80269454 *)this)->lines;
        if ((void *)((TWindowSubComCard *)e)->get_field_20() != 0) {
            if (lines[i].flags & 8) {
                lines[i].flags &= ~8;
                e->flags &= ~8;
            }
            ((TWindowHelpItem *)e)->reset_float_field();
        }
    }
}
