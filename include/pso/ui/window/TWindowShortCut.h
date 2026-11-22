#ifndef PSO_UI_WINDOW_TWINDOWSHORTCUT_H
#define PSO_UI_WINDOW_TWINDOWSHORTCUT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowChatSymbol;
struct TWindowMessageQuest;

struct TWindowShortCut : public TWindowBase {
    TWindowShortCut(saddr arg1, s32 index, s32 *chat_shortcut);
    virtual ~TWindowShortCut();
    virtual void render();
    uaddr heading;                       // type-1 status heading titled with message 0x35
    TWindowMessageQuest *preview_window;       // text preview of a text or word-select shortcut
    TWindowChatSymbol *symbol_preview; // preview of a symbol-chat shortcut
    s32 shortcut_index;
    s32 *shortcut;                     // the shortcut record (s32 kind, then its payload)
    virtual void run_task();
    void show_shortcut(s32 index, s32 *shortcut);
};

LAYOUT_ASSERT(TWindowShortCut_size, sizeof(TWindowShortCut) == 0x74);


#endif
