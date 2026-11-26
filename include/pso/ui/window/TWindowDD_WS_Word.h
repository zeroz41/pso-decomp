#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_WORD_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_WORD_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

struct NJS_POINT2;

class TWindowDD_WS_Word : public TWindowBase {
public:
    static const char *class_name;
    TWindowDD_WS_Word(s32 list_id, s32 visible_count);
    virtual ~TWindowDD_WS_Word();
    static TWindowDD_WS_Word *create(s32 element_list, s32 rows);
    void disable_input(); // sets state_flags bit 0
    void enable_input();  // clears state_flags bit 0
    s16 get_element_list_id() const;
    s32 get_scroll_top() const; // first visible token (selected token minus its row)
    int get_selected_id() const;
    virtual void render();
    virtual void run_task();
    void add_scroll_offset(int offset);
    void get_cursor_pos(NJS_POINT2 *position);
    s32 needs_scroll();
    s32 can_scroll(s32 direction);
    s32 sub_80342268();
    s32 sub_80342254();
    void load_element_list();
    void reset_fields();
    void init_layout_entries();
    void init_child(s32 list_id);
    void free_child();
    void init_and_mark_field8C();
    s32 get_selected_token_index();
    s32 get_selected_row();
    s32 get_token_count();
    char *get_selected_row_text();
    void set_pos_and_data(f32 x);
    void use_active_strips();
    void use_dim_strips();
    s32 state_flags;
    s32 strip_point_index; // point table index for the strips; 0 also picks the first v range
    s32 selected_token_index;
    s32 selected_row;
    s32 element_list_id; // read by load_element_list
    s32 token_count;
    s32 visible_row_count;
    s32 visible_entry_count;
    s16 *token_ids;
    f32 pad_84;
    f32 scroll_offset; // scroll offset (fraction of a 20-unit row drawn as partial strips)
    s32 needs_text_refresh;
};
struct WindowDrawContext;

void draw_word_row_strips(TWindowDD_WS_Word *self, WindowDrawContext *rect);

LAYOUT_ASSERT(TWindowDD_WS_Word_size, sizeof(TWindowDD_WS_Word) == 0x90);

LAYOUT_ASSERT(TWindowDD_WS_Word_pad_64, offsetof(TWindowDD_WS_Word, strip_point_index) == 0x64);
LAYOUT_ASSERT(TWindowDD_WS_Word_pad_78, offsetof(TWindowDD_WS_Word, visible_row_count) == 0x78);
LAYOUT_ASSERT(TWindowDD_WS_Word_float84, offsetof(TWindowDD_WS_Word, pad_84) == 0x84);
LAYOUT_ASSERT(TWindowDD_WS_Word_pad_88, offsetof(TWindowDD_WS_Word, scroll_offset) == 0x88);

LAYOUT_ASSERT(TWindowDD_WS_Word_list_id, offsetof(TWindowDD_WS_Word, element_list_id) == 0x70);

// Entry layout table of the window: one column, one text record (type 3); the row count is
// written before each build (init_layout_entries, TWindowDD_WS_Word::create).
struct TWindowDD_WS_WordLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
};


#endif
