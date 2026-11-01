#ifndef PSO_MISC_TWINDOWSUBSYMBOLCHATHELP_H
#define PSO_MISC_TWINDOWSUBSYMBOLCHATHELP_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowSubSymbolChatHelp : public TWindowBase {
    virtual ~TWindowSubSymbolChatHelp();
    void draw_help_entry(void *, s32, s32);
    void draw_color_palette(void *);
    u8 _pad1C[0x44];
    u8 m_60;
    u8 _pad61[0x3];
    u32 m_64;
    u32 m_68;
    u32 m_6c;
    u32 m_70;
    void draw_help_entries(void *arg1);
    void handle_toggle_input();
    void handle_page_input();
    virtual void render();
    virtual void run_task();
};

typedef char TWindowSubSymbolChatHelp_size[sizeof(TWindowSubSymbolChatHelp) == 0x74 ? 1 : -1];

extern "C" {
u8 *TWindowSubSymbolChatHelp__ct(TWindowSubSymbolChatHelp *arg0, s32 arg1, s32 arg2);
void *__dt__24TWindowSubSymbolChatHelpFv(void *arg0, s16 arg1);
}

#endif
