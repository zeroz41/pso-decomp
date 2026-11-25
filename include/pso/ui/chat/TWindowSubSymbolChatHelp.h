#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATHELP_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATHELP_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubSymbolChatHelp : public TWindowBase {
    TWindowSubSymbolChatHelp(s8 *selection, s32 *mode);
    virtual ~TWindowSubSymbolChatHelp();
    void draw_help_entry(struct WindowDrawContext *, s32, s32);
    void draw_color_palette(struct WindowDrawContext *);
    void draw_help_icon(struct WindowDrawContext *context, s32 row, s32 color);
    s8 feature_flags;
    u8 _pad61[0x3];
    // Borrowed selection, mode and optional toggle targets.
    s8 *color_selection;
    s32 *mirror_mode;
    s32 *flip_u;
    s32 *flip_v;
    void clear_flag60_bit2();
    void clear_flag60_bit4();
    void set_pos_and_flag(s32 *first, s32 *second);
    void set_flag60_bit1();
    void set_flag60_bit2();
    void draw_help_entries(struct WindowDrawContext *context);
    void handle_toggle_input();
    void handle_page_input();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubSymbolChatHelp_size, sizeof(TWindowSubSymbolChatHelp) == 0x74);

LAYOUT_ASSERT(TWindowSubSymbolChatHelp_m64, offsetof(TWindowSubSymbolChatHelp, color_selection) == 0x64);
LAYOUT_ASSERT(TWindowSubSymbolChatHelp_m70, offsetof(TWindowSubSymbolChatHelp, flip_v) == 0x70);

extern "C" {
void clear_help_feature_flag1(TWindowSubSymbolChatHelp *window);
}

#endif
