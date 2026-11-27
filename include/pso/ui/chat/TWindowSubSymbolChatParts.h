#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTS_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTS_H

#include "types.h"

class WindowHeading;

struct NJS_POINT2;
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/WindowLayoutRecord.h"

struct TWindowSubStatusDisp;

struct WindowScrollBar;
struct WindowDrawContext;

struct TWindowSubSymbolChatParts : public TWindowAddition {
    TWindowSubSymbolChatParts(const NJS_POINT2 *position, s32 *flip_u_flag, s32 *flip_v_flag);
    virtual ~TWindowSubSymbolChatParts();
    static const char *class_name;
    void scroll_to_cursor_row();
    void draw_selected_cursor(WindowDrawContext *ctx);
    void update_cursor_input();
    s32 calc_symbol_index();
    s32 is_confirmed();
    s32 is_cancelled();
    virtual void render();
    virtual void run_task();
    u8 result_flags;
    u8 view_mode;
    u8 cursor_col;
    u8 cursor_row;
    s8 row_count;
    u8 pad_75;
    s16 item_count;
    s8 *selection;
    s32 *flip_u;
    s32 *flip_v;
    s32 *help;
    WindowHeading *heading;
    WindowScrollBar *scrollbar;
    void select_index_and_scroll(s32 index);
    void update_height();
    void open(s8 *selected_value);
    void handle_cancel();
    void add_part();
    void handle_add();
    void update_row_count();
    void draw_preset_parts(WindowDrawContext *ctx);
    void draw_part_choices(WindowDrawContext *ctx);
    void draw_part_icons(WindowDrawContext *ctx);
    void init_help(s32 *help_value);
};

LAYOUT_ASSERT(TWindowSubSymbolChatParts_size, sizeof(TWindowSubSymbolChatParts) == 0x90);

void select_symbol_chat_slot(TWindowSubSymbolChatParts *parts);

LAYOUT_ASSERT(TWindowSubSymbolChatParts_row_count_offset, offsetof(TWindowSubSymbolChatParts, row_count) == 0x74);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_selection_offset, offsetof(TWindowSubSymbolChatParts, selection) == 0x78);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_flip_u_offset, offsetof(TWindowSubSymbolChatParts, flip_u) == 0x7C);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_flip_v_offset, offsetof(TWindowSubSymbolChatParts, flip_v) == 0x80);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_heading_offset, offsetof(TWindowSubSymbolChatParts, heading) == 0x88);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_scrollbar_offset, offsetof(TWindowSubSymbolChatParts, scrollbar) == 0x8C);

// symbol_chat_parts_layout_entries, the layout table symbol_chat_parts_window_layout
// points at (three sprite parts).
struct SymbolChatPartsWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec[3];
};


#endif
