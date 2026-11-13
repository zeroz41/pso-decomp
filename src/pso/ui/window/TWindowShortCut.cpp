#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowShortCut.h"
#include "pso/ui/chat/TWindowChatSymbol.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowDD.h"

#pragma push
#pragma readonly_strings on
const char *TWindowShortCut__name = "TWindowShortCut";
#pragma pop

struct RecoveredGlobal_8026E728_lbl_804D0AE0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8026E728___vt__15TWindowShortCut {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
s32 forward_render__20TWindowSubStatusDispFv(int, int);
s32 construct_type1_heading__20TWindowSubStatusDispFll(s32, s32, s32);
s32 get_message_10__20TWindowSubStatusDispFl(int);
extern RecoveredGlobal_8026E728_lbl_804D0AE0 window_short_cut_layout;
extern s32 __vt__15TWindowShortCut[];
void __dl__7TObjectFPv(void *);

void render__15TWindowShortCutFv(u8 *arg0) {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    forward_render__20TWindowSubStatusDispFv((int) (((TWindowShortCut *)arg0)->m_60), temp_r3);
}

void TWindowShortCut::run_task() { ((TWindowSubStatusDisp *)(this->m_60))->update_subwindow(); ((TWindowDD *)this)->initialize_subwindow(); update_fade(); update_window_entry_list((char*)this + 0x24); }

void *__dt__15TWindowShortCutFv(TWindowShortCut *self, s16 arg1) {
    if (self != NULL) {
        *(s32 **)((s8 *)self + 0x18) = __vt__15TWindowShortCut;
        if (self->symbol_chat_window != NULL) {
            self->symbol_chat_window->close();
            self->symbol_chat_window = NULL;
        }
        if (self->message_window != NULL) {
            self->message_window->close();
            self->message_window = NULL;
        }
        TWindowSubStatusDisp::destroy_status_display((s32)self->m_60, (s16)1);
        ((TWindowDD *)self)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
typedef char RecoveredGlobal_8026E728_lbl_804D0AE0_size[sizeof(RecoveredGlobal_8026E728_lbl_804D0AE0) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_8026E728___vt__15TWindowShortCut_size[sizeof(RecoveredGlobal_8026E728___vt__15TWindowShortCut) == 0x1C ? 1 : -1];
u8 *TWindowShortCut__ct(TWindowShortCut *window_short_cut, s32 arg1, s32 index, s32 chat_shortcut_addr) {
    s32 var_r31;
    ((TWindowDD *)window_short_cut)->construct_base((u8 *)((s32) &window_short_cut_layout.value), (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)window_short_cut + 0x18) = &(*(RecoveredGlobal_8026E728___vt__15TWindowShortCut *)&__vt__15TWindowShortCut).value;
    *(s32 *)((s8 *)window_short_cut + 0) = (s32) TWindowShortCut__name;
    var_r31 = (int)::operator new(0x24);
    if (var_r31 != 0) {
        var_r31 = construct_type1_heading__20TWindowSubStatusDispFll(var_r31, get_message_10__20TWindowSubStatusDispFl(0x35), (s32) window_short_cut->m_20);
    }
    window_short_cut->m_60 = var_r31;
    window_short_cut->message_window = NULL;
    window_short_cut->symbol_chat_window = NULL;
    window_short_cut->index = index;
    window_short_cut->chat_shortcut = (s32 *)chat_shortcut_addr;
    window_short_cut->sub_8026E1D4(index, (s32 *)chat_shortcut_addr);
    return (u8 *)window_short_cut;
}

}
