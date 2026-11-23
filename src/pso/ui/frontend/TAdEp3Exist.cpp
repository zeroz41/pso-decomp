#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdEp3Exist.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/unk/text_8036F764.h"
#include <string.h>
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"

#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"

#pragma readonly_strings on

const f32 lbl_8047B8A8[2] = { 89.0f, 394.0f };
const f32 lbl_8047B8B0[2] = { 462.0f, 18.0f };
const char *TAdEp3Exist__name = "TAdEp3Exist";
const f32 lbl_8047B8C4[2] = { 85.0f, 384.0f };
const f32 lbl_8047B8CC[2] = { 470.0f, 32.0f };

void *TAdEp3Exist::vfunc_6() {
    return TAdEnterSerialAccessGC::create_callback((void *)lbl_8047B8C4, (void *)lbl_8047B8CC, draw_message_window);
}

struct Obj_8036F4DC { u8 pad0[8]; u8 cnt; u8 bits; };

struct Prs_8036F5B0 {
    u8 *f0;
    u8 *f4;
    u8 *fC_pad8;
    s32 fC;
    u8 *f10;
    s32 f14;
    u8 *f18;
    u32 f1C;
    s32 f20, f24;
    s32 f28;
    u32 f2C;
};

extern "C" {
void TAdEp3Exist__sub_8036F574(u8 *arg0);
u8 TAdEp3Exist__sub_8036F590(u8 *arg0);
saddr get_localized_text_entry(s32 arg0, s32 arg1);
u32 calc_text_width(char *s);

void TAdEp3Exist__sub_8036F0AC(TAdEp3Exist *p);
int prs_read_control_bit(Obj_8036F4DC *arg0);
void TAdEp3Exist__sub_8036F5A4(void* p);
s32 prs_decompress(Prs_8036F5B0 *c, u8 *src, s32 arg2, s32 arg3);

void TAdEp3Exist::draw_message_window(void *window, void *frame_context) {
    ((TWindowBase *)window)->draw_window_frame(frame_context);
    f32 x = 320.0f - (f32)(calc_text_width((char *)get_localized_text_entry(0x2C, 0xA)) >> 1U);
    TAdSubPlyItemGC::render_status_line(x, 394.0f, 0.8f, (const char *)get_localized_text_entry(0x2C, 0xA), -1);
}

void TAdEp3Exist::render() {
    if (TMainTask::get_render_pass() == 1) {
        return;
    }
}

void TAdEp3Exist::request_game_mode_transition() { TAdMultiChgGameModeGC::request_transition(); }
void TAdEp3Exist::request_scene_change() { TAdMultiChgGameModeGC::request_scene_change(); }
void TAdEp3Exist__sub_8036F0AC(TAdEp3Exist *p) { TAdMultiChgGameModeGC::reset_and_set_mode(); }
void TAdEp3Exist::close_window() { if (scroll_window != NULL) { scroll_window->close_window(); scroll_window = NULL; } }

void TAdEp3Exist::run_task() {
    prev_state = state;
    switch (state) {
    case 0:
        callback_window = vfunc_6();
        state = 1;
        break;
    case 1:
        if (cursor->confirmation_result() == 1) {
            switch (cursor->selection_index()) {
            case 0:
                state = 2;
                next_state = 3;
                break;
            case 1:
                state = 2;
                next_state = 4;
                break;
            }
        } else if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0 ||
                   test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            state = 2;
            next_state = 5;
        }
        break;
    case 2:
        if (callback_window != NULL) {
            ((TWindowBase *)callback_window)->close();
            callback_window = NULL;
        }
        close_window();
        if ((f32)++frames > 4.5f) {
            state = next_state;
        }
        break;
    case 3:
        TAdEp3Exist__sub_8036F0AC(this);
        break;
    case 4:
        request_scene_change();
        break;
    case 5:
        request_game_mode_transition();
        break;
    }
    if (prev_state != state) {
        frames = 0;
    }
}

}
TAdEp3Exist::~TAdEp3Exist() {
    if (callback_window != NULL) { ((TObject *)callback_window)->queue_destruction(); callback_window = NULL; }
    if (cursor != NULL) { cursor->queue_destruction(); cursor = NULL; }
}

TAdEp3Exist::TAdEp3Exist(TObject *parent) : TObject(parent) {
    s8 flag[16];
    u8 save[16];
    s32 res;
    bool ok;
    bool go;
    m_name = TAdEp3Exist__name;
    scroll_window = NULL;
    cursor = NULL;
    callback_window = NULL;
    frames = 0;
    state = 0;
    next_state = 0;
    flag[0] = 0;
    res = ((TAdSinglePlyChrSelectGC *)flag)->load_and_verify_character_save((char *)save);
    ok = false;
    if (res != 0) {
        if (flag[0] != 0) {
            ok = true;
        }
    }
    go = false;
    if (ok) {
        if ((s8)((u8 *)TAdSinglePlyChrSelectGC::get_instance())[0x1152C] == 0) {
            go = true;
        }
    }
    if (!go) {
        TAdMultiChgGameModeGC::reset_and_set_mode();
        queue_destruction();
        return;
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    scroll_window = new TAdScrollWinGC(this, 3, (s32)get_localized_text_entry(0x2C, 9));
    cursor = new TAdSelectCurGC(tl_clipout, (const NJS_POINT2 *)lbl_8047B8A8, (const NJS_POINT2 *)lbl_8047B8B0);
    cursor->append_entry((void *)lbl_8047B8A8);
    fn_80329BAC(cursor);
    cursor->set_selection_index(0);
}

int prs_read_control_bit(Obj_8036F4DC *arg0) {
    s32 t;
    if (--arg0->cnt == 0) {
        arg0->bits = TAdEp3Exist__sub_8036F590((u8 *)arg0);
        arg0->cnt = 8;
    }
    t = arg0->bits;
    arg0->bits = t >> 1;
    return t & 1;
}

saddr TAdEp3Exist::free_if_valid(saddr arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        ::operator delete((void *)arg0);
    }
    return arg0;
}

void TAdEp3Exist__sub_8036F574(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0xC) = 0;
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 8) = 1;
}

u8 TAdEp3Exist__sub_8036F590(u8 *arg0) {
    u8 *temp_r4;
    temp_r4 = *(u8 **)((s8 *)arg0 + 0xC);
    *(u8 **)((s8 *)arg0 + 0xC) = (u8 *) (temp_r4 + 1);
    return *temp_r4;
}

void TAdEp3Exist__sub_8036F5A4(void* p) { *(s32*)((char*)p + 0x10) = 0; }
#pragma push
#pragma opt_lifetimes off
#define BIT(c) ((u8 (*)(void *))prs_read_control_bit)(c)
#define BYTE(c) TAdEp3Exist__sub_8036F590((u8 *)(c))
s32 prs_decompress(Prs_8036F5B0 *c, u8 *src, s32 arg2, s32 arg3) {
    s32 n;
    s32 off;
    u32 size;
    u8 *p;
    u32 lo;
    u32 hi;
    u8 a;
    n = 0;
    c->fC = c->f14 = arg2;
    c->f18 = src;
    c->f0 = src;
    c->f4 = src;
    c->f28 = arg3;
    c->f10 = (u8 *)0x80001800;
    for (;;) {
        if (c->f2C != 0) break;
        while (BIT(c)) {
            p = (u8 *)prs_next_output_byte(c);
            *p = BYTE(c);
            n++;
        }
        if (BIT(c)) {
            size = BYTE(c);
            hi = BYTE(c);
            if ((hi | size) == 0) break;
            off = (s32)(hi << 5) + (s32)(size >> 3) - 0x2000;
            size &= 7;
            if (size != 0) {
                size += 2;
            } else {
                size = BYTE(c) + 1;
            }
        } else {
            a = BIT(c);
            size = (a << 1) + BIT(c) + 2;
            off = BYTE(c) - 0x100;
        }
        off += n;
        while (size-- != 0) {
            p = (u8 *)prs_next_output_byte(c);
            *p = prs_read_byte_at((u8 *)c, off);
            n++;
            off++;
        }
    }
    if (c->f2C != 0) {
        TAdEp3Exist__sub_8036F5A4((void*)(c));
        return -1;
    }
    size = n;
    if (c->f1C != 0) {
        memmove(c->f18 + (n - c->f1C), c->f10, c->f1C);
        c->f1C = 0;
    }
    TAdEp3Exist__sub_8036F5A4((void*)(c));
    return size;
}
#pragma pop
