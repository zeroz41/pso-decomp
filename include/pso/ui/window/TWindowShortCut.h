#ifndef PSO_UI_WINDOW_TWINDOWSHORTCUT_H
#define PSO_UI_WINDOW_TWINDOWSHORTCUT_H

#include "types.h"
struct NJS_POINT2;

class WindowHeading;
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

struct TWindowChatSymbol;
struct TWindowMessageQuest;

struct TWindowShortCut : public TWindowBase {
    TWindowShortCut(const NJS_POINT2 *position, s32 index, s32 *chat_shortcut);
    virtual ~TWindowShortCut();
    static const char *class_name;
    virtual void render();
    WindowHeading *heading;                       // type-1 status heading titled with message 0x35
    TWindowMessageQuest *preview_window;       // text preview of a text or word-select shortcut
    TWindowChatSymbol *symbol_preview; // preview of a symbol-chat shortcut
    s32 shortcut_index;
    s32 *shortcut;                     // the shortcut record (s32 kind, then its payload)
    virtual void run_task();
    void show_shortcut(s32 index, s32 *shortcut);
};

LAYOUT_ASSERT(TWindowShortCut_size, sizeof(TWindowShortCut) == 0x74);

// The shortcut window's entries: three rows of label, ":" and icons or text, filled by
// show_shortcut (entries 0, 2, 3, 4, 6, 7, 8 and 10).
struct ShortCutWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    SpritePartLayoutRecord rec_2;
    SpritePartLayoutRecord rec_3;
    TextLayoutRecord rec_4;
    TextLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    TextLayoutRecord rec_7;
    TextLayoutRecord rec_8;
    TextLayoutRecord rec_9;
    TextLayoutRecord rec_10;
};



#endif
