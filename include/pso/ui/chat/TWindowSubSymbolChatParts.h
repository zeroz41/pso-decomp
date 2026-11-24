#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTS_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTS_H

#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

struct TWindowSubStatusDisp;

struct WindowScrollBar;

struct TWindowSubSymbolChatParts : public TWindowAddition {
    TWindowSubSymbolChatParts(void *parent, s32 *arg2, s32 *arg3);
    virtual ~TWindowSubSymbolChatParts();
    static const char *class_name;
    void sub_80284FB8();
    void sub_80285274(u8 *);
    void sub_80285054();
    s32 calc_symbol_index();
    s32 sub_80283974();
    virtual void render();
    virtual void run_task();
    u8 m_70;
    u8 m_71;
    u8 cursor_col;
    u8 cursor_row;
    s8 row_count;
    u8 pad_75;
    s16 item_count;
    s8 *selection;
    s32 *m_7c;
    s32 *m_80;
    u8 _pad84[0x4];
    TWindowSubStatusDisp *heading;
    WindowScrollBar *scrollbar;
    void select_index_and_scroll(s32 index);
    void update_height();
    void open(s8 *selected_value);
    void handle_cancel();
    void add_part();
    void handle_add();
};

LAYOUT_ASSERT(TWindowSubSymbolChatParts_size, sizeof(TWindowSubSymbolChatParts) == 0x90);

extern "C" {
void fn_80284C04(TWindowSubSymbolChatParts *parts);
void render__25TWindowSubSymbolChatPartsFv(u8 *window_sub_symbol_chat_parts);
}
void select_symbol_chat_slot(TWindowSubSymbolChatParts *parts);

LAYOUT_ASSERT(TWindowSubSymbolChatParts_row_count_offset, offsetof(TWindowSubSymbolChatParts, row_count) == 0x74);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_selection_offset, offsetof(TWindowSubSymbolChatParts, selection) == 0x78);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_m_7c_offset, offsetof(TWindowSubSymbolChatParts, m_7c) == 0x7C);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_m_80_offset, offsetof(TWindowSubSymbolChatParts, m_80) == 0x80);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_heading_offset, offsetof(TWindowSubSymbolChatParts, heading) == 0x88);
LAYOUT_ASSERT(TWindowSubSymbolChatParts_scrollbar_offset, offsetof(TWindowSubSymbolChatParts, scrollbar) == 0x8C);

#endif
