#include "types.h"
#include "pso/misc/TWindowMessageQuest.h"
#include "pso/misc/TLobby_8026B06C.h"
#include "pso/misc/TWindowMessageQuest_8026B118.h"
#include "pso/misc/TWindowBase.h"

struct RecoveredGlobal_8026B118_lbl_8044F464 {
    s32 value;
    u8 remaining[0x8];
};

struct Win_8026B148 {
    u8 pad0[0x24];
    u8 entries[0x5C - 0x24];
    s32 opening;
    u8 pad1[0x90 - 0x60];
    s32 mode;
};

struct Ctx_8026B148 {
    u8 pad0[0x28];
    f32 scaleX;
    f32 scaleY;
    s32 reveal;
};

extern "C" {
s32 get_window_layout_position(int);
extern RecoveredGlobal_8026B118_lbl_8044F464 lbl_8044F464;
Ctx_8026B148 *get_draw_context__11TWindowBaseFPv(void *);
void draw_visible_window_entries(void *, void *, void *);
extern const f32 lbl_805DD260;
typedef char RecoveredGlobal_8026B118_lbl_8044F464_size[sizeof(RecoveredGlobal_8026B118_lbl_8044F464) == 0xC ? 1 : -1];
void create_quest_message_window(void) {
    create_quest_message_window_at((get_window_layout_position(0xAD)), (s32)&lbl_8044F464.value);
}
void TWindowMessageQuest::render() {
    Ctx_8026B148 *c;
    c = get_draw_context__11TWindowBaseFPv(this);
    switch (((Win_8026B148 *)this)->mode) {
    case 0:
        if (c->reveal < 0) {
            c->scaleX = (f32)((Win_8026B148 *)this)->opening / lbl_805DD260;
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
    draw_visible_window_entries(((Win_8026B148 *)this), ((Win_8026B148 *)this)->entries, c);
}

}
