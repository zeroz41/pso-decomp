#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_WORD_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_WORD_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct NJS_POINT2;

class TWindowDD_WS_Word : public TWindowBase {
public:
    TWindowDD_WS_Word(s32 list_id, s32 visible_count);
    virtual ~TWindowDD_WS_Word();
    virtual void render();
    virtual void run_task();
    void add_scroll_offset(int offset);
    void get_cursor_pos(NJS_POINT2 *position);
    s32 sub_80341AC0();
    s32 can_scroll(s32);
    s32 sub_80342268();
    s32 sub_80342254();
    void load_element_list();
    void reset_fields();
    void init_layout_entries();
    void init_child(s32 list_id);
    void free_child();
    void init_and_mark_field8C();
    s32 m_60;
    s32 pad_64; // point table index for the strips; 0 also picks the first v range
    s32 selected_token_index;
    s32 selected_row;
    s32 pad_70; // element list id, read by load_element_list
    s32 token_count;
    s32 pad_78; // visible row count
    s32 visible_entry_count;
    s16 *token_ids;
    f32 pad_84;
    f32 pad_88; // scroll offset (fraction of a 20-unit row drawn as partial strips)
    s32 m_8c;
};
struct WindowDrawContext;

extern "C" {
void TWindowDD__sub_80341674(TWindowDD_WS_Word *self, WindowDrawContext *rect);
}

LAYOUT_ASSERT(TWindowDD_WS_Word_size, sizeof(TWindowDD_WS_Word) == 0x90);

LAYOUT_ASSERT(TWindowDD_WS_Word_pad_64, offsetof(TWindowDD_WS_Word, pad_64) == 0x64);
LAYOUT_ASSERT(TWindowDD_WS_Word_pad_78, offsetof(TWindowDD_WS_Word, pad_78) == 0x78);
LAYOUT_ASSERT(TWindowDD_WS_Word_float84, offsetof(TWindowDD_WS_Word, pad_84) == 0x84);
LAYOUT_ASSERT(TWindowDD_WS_Word_pad_88, offsetof(TWindowDD_WS_Word, pad_88) == 0x88);

LAYOUT_ASSERT(TWindowDD_WS_Word_list_id, offsetof(TWindowDD_WS_Word, pad_70) == 0x70);

#endif
