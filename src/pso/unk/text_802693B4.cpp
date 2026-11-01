#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowMessagePage.h"
#include "pso/misc/TWindowHelpItem.h"
struct Line_80269454 { u32 flags; u32 f4; };

struct Entry_80269454 { u16 flags; };

struct Win_80269454 { u8 pad[0x5c]; u32 f5c; u8 pad2[0xc]; f32 f6c; u8 pad3[0xc]; Line_80269454 *lines; u8 pad4[4]; f32 f84; u8 pad5[4]; u32 count; };

struct Win_802693B4 { u8 pad[0x6c]; f32 f6c; u8 pad2[0x84 - 0x70]; f32 f84; u8 pad3[4]; u32 count; };

extern "C" {
Entry_80269454 *get_array_entry__11TWindowBaseFi(void *, s32);
void *get_field_20__17TWindowSubComCardFv(void *);
s32 is_window_reveal_complete__11TWindowBaseFv();

s32 TWindowMessagePage::is_message_window_ready() {
    Entry_80269454 *e;
    u32 i;
    if (is_window_reveal_complete__11TWindowBaseFv() == 0) {
        return 0;
    }
    if (((struct Win_802693B4 *)this)->f6c != ((struct Win_802693B4 *)this)->f84) {
        return 0;
    }
    for (i = 0; i < ((struct Win_802693B4 *)this)->count; i++) {
        e = get_array_entry__11TWindowBaseFi(((struct Win_802693B4 *)this), i);
        if (get_field_20__17TWindowSubComCardFv(e) != 0 && !(e->flags & 0x10)) {
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
        e = get_array_entry__11TWindowBaseFi(this, i);
        lines = ((Win_80269454 *)this)->lines;
        if (get_field_20__17TWindowSubComCardFv(e) != 0) {
            if (lines[i].flags & 8) {
                lines[i].flags &= ~8;
                e->flags &= ~8;
            }
            ((TWindowHelpItem *)e)->reset_float_field();
        }
    }
}

}
