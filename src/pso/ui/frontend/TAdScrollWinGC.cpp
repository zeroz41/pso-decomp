#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/text_8026A93C.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802C6F88.h"
#include "pso/ui/frontend/TAdScrollWinGC_8026A5F8.h"
#include "pso/ui/frontend/TAdScrollWinGC_80327504.h"
#include "pso/unk/text_8026A14C.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessageLog.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/unk/text_80145A94.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TObject.h"

struct RecoveredGlobal_80327698___vt__14TAdScrollWinGC { s32 value; u8 remaining[0x14]; };

extern "C" {
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_80327698___vt__14TAdScrollWinGC __vt__14TAdScrollWinGC;
extern u8 controller_physical_port_bank[];
void __ct__7TObjectFP7TObject(void *, void *);
}

s32 scroll_win_texture_handle;

// Functions are written last-to-first: with -inline off,deferred CodeWarrior emits them in reverse source order.
extern "C" {

void *TAdScrollWinGC__ct(TAdScrollWinGC *ad_scroll_win_gc, void *arg1, s32 arg2, s32 arg3) {
    static const f32 pos[2] = { 44.0f, 131.0f };
    static const f32 size[2] = { 552.0f, 220.0f };
    s32 base;
    s32 i;
    __ct__7TObjectFP7TObject(ad_scroll_win_gc, arg1);
    *(s32 **)((s8 *)ad_scroll_win_gc + 0x18) = &__vt__14TAdScrollWinGC.value;
    ad_scroll_win_gc->m_name = TAdScrollWinGC__class_name;
    scroll_win_texture_handle = TAdMultiPlyChrSelectGC__sub_802C6FA8();
    ad_scroll_win_gc->m_3c = 0;
    ad_scroll_win_gc->m_40 = 0;
    ad_scroll_win_gc->m_44 = arg2;
    ad_scroll_win_gc->m_48 = 0;
    ad_scroll_win_gc->m_4c = 0;
    ad_scroll_win_gc->m_50 = 0;
    base = ad_scroll_win_gc->get_scroll_delay_for_mode();
    ad_scroll_win_gc->m_40 = (s32)create_message_log_window((s32)pos, (s32)size, 0);
    switch (ad_scroll_win_gc->m_44) {
    case 0:
    case 1:
        for (i = 0; i < 10; i++) {
            ((TWindowMessage *)(ad_scroll_win_gc->m_40))->append_line(get_localized_text_entry(0x1A, base + i), 1);
        }
        break;
    case 2:
    case 3:
        ((TWindowMessage *)(ad_scroll_win_gc->m_40))->append_line(arg3, 1);
        break;
    }
    ((TWindowMessage *)(ad_scroll_win_gc->m_40))->complete_reveal();
    ((TWindowMessageLog *)(ad_scroll_win_gc->m_40))->update_scroll_position();
    TAdScrollWinGC__sub_8026A5F8((void *)ad_scroll_win_gc->m_40);
    *(f32 *)((s8 *)ad_scroll_win_gc + 0x2C) = 0.71875f;
    ad_scroll_win_gc->m_30 = 0.4765625f;
    *(f32 *)((s8 *)ad_scroll_win_gc + 0x34) = 1.0f;
    ad_scroll_win_gc->m_38 = 0.5546875f;
    return ad_scroll_win_gc;
}

}

const char *TAdScrollWinGC__class_name = "TAdScrollWinGC";

extern "C" {

u8 *__dt__14TAdScrollWinGCFv(u8 *arg0, s16 arg1) {
    u8 *object;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__14TAdScrollWinGC.value;
        object = (u8 *)(*(u8 **)((s8 *)arg0 + 0x40));
        if (object != NULL) {
            ((TObject *)object)->queue_destruction();
            *(u8 **)((s8 *)arg0 + 0x40) = NULL;
        }
        fn_8026A14C();
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

void TAdScrollWinGC::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 d;
    u32 a;
    switch (*(s32 *)&this->m_4c) {
    case 0:
        break;
    case 1:
        if (++*(s32 *)&this->m_50 > 4.5f) {
            ((TObject *)arg0)->queue_destruction();
            return;
        }
        break;
    }
    this->m_3c += 0xC;
    this->m_3c = this->m_3c > 0xFF ? 0xFF : this->m_3c;
    *(f32 *)&this->unk_1C = 531.0f;
    this->m_20 = 353.0f;
    *(f32 *)&this->unk_24 = 603.0f;
    this->m_28 = 373.0f;
    d = *(s16 *)((s8 *)controller_physical_port_bank + 0x3A);
    if (d < 0) {
        d += 0x19;
        if (*(void * *)&this->m_40 != 0) {
            fn_8026A61C(*(void * *)&this->m_40, 0.3f * d);
        }
    }
    if (d > 0 && *(void * *)&this->m_40 != 0) {
        ((TAdScrollWinGC *)(*(void * *)&this->m_40))->advance_scroll(0.3f * (d - 0x19));
    }
}

void TAdScrollWinGC::close_window() { if (this->m_40 != 0) { ((TWindowBase *)this->m_40)->close(); this->m_40 = 0; } }

void TAdScrollWinGC::close() {
    close_window();
    this->m_4c = 1;
}

s32 TAdScrollWinGC::get_scroll_delay_for_mode() {
    TAdScrollWinGC *arg0 = this;
    s32 r = 0;
    switch (arg0->m_44) {
    case 0:
        if (TLobby__sub_80145DB4(4) != 0) {
            r = 0x14;
        } else {
            r = 0;
        }
        break;
    case 1:
        r = 0xA;
        break;
    case 2:
        r = -1;
        break;
    }
    return r;
}

void TAdScrollWinGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); render_status_value(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

void TAdScrollWinGC::render_status_value() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(scroll_win_texture_handle);
    set_draw_texture_and_color(0, ((this->m_3c << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x1C), 0.1f);
    TWindowSubStatusDisp::get_player();
}

}
