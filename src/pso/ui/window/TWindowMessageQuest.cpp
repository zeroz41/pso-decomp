#include "types.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_8026B06C.h"
#include "pso/network/client_id.h"
#include <dolphin/mtx/GeoTypes.h>

#pragma readonly_strings on

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

const char *TWindowMessageQuest__name = "TWindowMessageQuest";

// create_quest_message_window_at's second argument (384 x 80: the window's size, inferred)
static const Vec lbl_8044F464 = {384.0f, 80.0f, 0.0f};

extern "C" {
s32 get_window_layout_position(int);
Ctx_8026B148 *get_draw_context__11TWindowBaseFPv(void *);
void draw_visible_window_entries(void *, void *, void *);

void create_quest_message_window(void) {
    create_quest_message_window_at((get_window_layout_position(0xAD)), (s32)&lbl_8044F464);
}
void TWindowMessageQuest::render() {
    Ctx_8026B148 *c;
    c = get_draw_context__11TWindowBaseFPv(this);
    switch (((Win_8026B148 *)this)->mode) {
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
    draw_visible_window_entries(((Win_8026B148 *)this), ((Win_8026B148 *)this)->entries, c);
}

}

TWindowMessageQuest::~TWindowMessageQuest() {

}


TWindowMessageQuest::TWindowMessageQuest(s32 arg1) : TWindowMessage(arg1, 1, local_client_id) {
    this->m_name = TWindowMessageQuest__name;
    *(s32 *)((s8 *)this + 0x90) = 0;
}
