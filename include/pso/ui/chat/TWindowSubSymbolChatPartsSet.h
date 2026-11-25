#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTSSET_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTSSET_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/chat/TWindowChatSymbol.h"

struct TWindowSubStatusDisp;
struct SymbolChatPart;

struct TWindowSubSymbolChatPartsSet : public TWindowChatSymbol {
    TWindowSubSymbolChatPartsSet(const NJS_POINT2 *position, s16 index, s32 *first, s32 *second);
    virtual ~TWindowSubSymbolChatPartsSet();
    void sub_8028625C();
    s32 is_active();
    s32 get_cursor_pos();
    s32 get_cursor_x();
    s32 is_cancelled();
    void set_selection_and_refresh(s8 *arg1);
    s32 select_symbol_chat_record(s8 *arg1, s32 *arg2);
    void init_symbol_layout(s32 *arg1);
    virtual void render();
    u8 flags; // 1: decided, 2: cancelled (set by handle_cancel)
    s8 selection_mode;
    s16 cursor_x;
    s16 cursor_y;
    u16 set_index;
    s8 *selection_out;
    s32 first_part_index;
    s32 second_part_index;
    s32 *first_flag_out;
    s32 *second_flag_out;
    s32 *result_out;
    TWindowSubStatusDisp *heading_display;
    void draw_selected_part_cursor(void *ctx);
    void handle_cancel();
    void handle_decide();
    void toggle_selected_part();
    void handle_cursor_input();
    virtual void run_task();
    f32 m_8c;
    f32 m_90;
    f32 m_94;
    // Reads symbol_chat_parts_color_table.
    static int get_parts_color(int index);
    static void set_pos(WindowSpritePart *sprite, s16 x, s16 y);
    static void set_part_sprite(WindowSpritePart *sprite, s16 id, s32 flip_u, s32 flip_v);
    WindowSpritePart *get_entry_offset_d(s32 sel);
    WindowSpritePart *get_parts_entry(saddr index);
    static WindowSpritePart *get_parts_entry(void *window, int index);
    static void apply_part_to_window(WindowLayoutEntries *entries, SymbolChatPart *part, s32 index);
    static void setup_part_sprites(WindowSpritePart *help, WindowSpritePart *alternate, WindowSpritePart *shortcut_icon, u16 code, s32 color, s32 flip_u, s32 flip_v, s32 uv_index);
};

extern "C" WindowSpritePart *TWindowSubSymbolChatPartsSet__sub_802482B8(void *window, s32 index);

LAYOUT_ASSERT(TWindowSubSymbolChatPartsSet_size, sizeof(TWindowSubSymbolChatPartsSet) == 0x98);
#endif
