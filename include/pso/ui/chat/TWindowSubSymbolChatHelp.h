#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATHELP_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATHELP_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubSymbolChatHelp : public TWindowBase {
    TWindowSubSymbolChatHelp(s8 *selection, s32 *mode);
    virtual ~TWindowSubSymbolChatHelp();
    void draw_help_entry(void *, s32, s32);
    void draw_color_palette(void *);
    s8 m_60;
    u8 _pad61[0x3];
    // Borrowed selection, mode and optional toggle targets.
    s8 *m_64;
    s32 *m_68;
    s32 *m_6c;
    s32 *m_70;
    void clear_flag60_bit2();
    void clear_flag60_bit4();
    void set_pos_and_flag(s32 *first, s32 *second);
    void set_flag60_bit1();
    void set_flag60_bit2();
    void draw_help_entries(void *arg1);
    void handle_toggle_input();
    void handle_page_input();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubSymbolChatHelp_size, sizeof(TWindowSubSymbolChatHelp) == 0x74);

LAYOUT_ASSERT(TWindowSubSymbolChatHelp_m64, offsetof(TWindowSubSymbolChatHelp, m_64) == 0x64);
LAYOUT_ASSERT(TWindowSubSymbolChatHelp_m70, offsetof(TWindowSubSymbolChatHelp, m_70) == 0x70);

extern "C" {
void TWindowSubSymbolChat__sub_80283944(TWindowSubSymbolChatHelp *window);
}

#endif
