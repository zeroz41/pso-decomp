#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTSSET_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTSSET_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/chat/TWindowChatSymbol.h"

struct TWindowSubStatusDisp;

struct TWindowSubSymbolChatPartsSet : public TWindowChatSymbol {
    TWindowSubSymbolChatPartsSet(const NJS_POINT2 *position, s16 index, s32 *first, s32 *second);
    virtual ~TWindowSubSymbolChatPartsSet();
    void sub_8028625C();
    s32 is_active();
    s32 is_cancelled();
    s32 get_cursor_pos();
    s32 get_cursor_x();
    void set_selection_and_refresh(s8 *selection);
    s32 select_symbol_chat_record(s8 *selection, s32 *result);
    void init_symbol_layout(s32 *result);
    static void apply_part_to_window(void *window_set, void *part, int index);
    virtual void render();
    u8 result_flags;
    s8 selection_mode;
    s16 cursor_x;
    s16 cursor_y;
    s16 part_id;
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
    f32 offset_x;
    f32 offset_y;
    f32 scale;
    static int get_parts_entry(int a0);
    void set_pos(s16 prev, s16 next);
    static void set_part_sprite(void *sprite, s16 id, s32 a, s32 b);
    u16 *get_entry_offset_d(s32 sel);
    u16 *get_parts_entry(saddr index);
    static u16 *get_parts_entry(void *window, int index);
};

extern "C" u16 *TWindowSubSymbolChatPartsSet__sub_802482B8(void *window, s32 index);

LAYOUT_ASSERT(TWindowSubSymbolChatPartsSet_size, sizeof(TWindowSubSymbolChatPartsSet) == 0x98);
#endif
