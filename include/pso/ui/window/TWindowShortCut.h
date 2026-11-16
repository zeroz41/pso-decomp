#ifndef PSO_UI_WINDOW_TWINDOWSHORTCUT_H
#define PSO_UI_WINDOW_TWINDOWSHORTCUT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowChatSymbol;

struct TWindowShortCut : public TWindowBase {
    virtual ~TWindowShortCut();
    virtual void render();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 _pad28[0x38];
    u32 heading;                       // type-1 status heading titled with message 0x35
    TWindowBase *preview_window;       // text preview of a text or word-select shortcut
    TWindowChatSymbol *symbol_preview; // preview of a symbol-chat shortcut
    s32 shortcut_index;
    s32 *shortcut;                     // the shortcut record (s32 kind, then its payload)
    virtual void run_task();
    void show_shortcut(s32 index, s32 *shortcut);
};

typedef char TWindowShortCut_size[sizeof(TWindowShortCut) == 0x74 ? 1 : -1];

extern "C" {
u8 *TWindowShortCut__ct(TWindowShortCut *window_short_cut, s32 arg1, s32 index, s32 *chat_shortcut);
void render__15TWindowShortCutFv(u8 *arg0);
}

#endif
