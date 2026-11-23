#ifndef PSO_UI_FRONTEND_TADSELECTCURGC_H
#define PSO_UI_FRONTEND_TADSELECTCURGC_H
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

struct SelectCursorQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

class TAdSelectCurGC : public TObject {
public:
    TAdSelectCurGC(TObject *parent, const NJS_POINT2 *position, const NJS_POINT2 *size);
    virtual ~TAdSelectCurGC();
    virtual void run_task();
public:
    virtual void render();

    s32 selection_index() const;
    s32 confirmation_result() const;
    void set_selection_index(s32 index);
    void reset_entries();
    void append_entry(const void *position);
    void lock_navigation();
    void request_navigation_unlock();
    void draw_quads();
    void update_texture_rectangles(s32 frame);
    void set_draw_depth(f32 depth);
    void set_selection_state(s32 v);  // stores pending_command; callers pass 1

    NJS_POINT2 entry_positions[16];
    NJS_POINT2 cursor_size;
    s32 selected_index;
    u32 entry_count;
    s32 confirmation;
    s32 navigation_locked;
    s32 confirmation_disabled;
    s32 wait_directions_released;
    SelectCursorQuad quads[48];
    s32 entry_alpha[16];
    s32 frame;
    s32 pending_command;
    f32 draw_depth;
};

LAYOUT_ASSERT(TAdSelectCurGC_size, sizeof(TAdSelectCurGC) == 0x708);
LAYOUT_ASSERT(TAdSelectCurGC_pending_command_offset, offsetof(TAdSelectCurGC, pending_command) == 0x700);
LAYOUT_ASSERT(TAdSelectCurGC_position_offset, offsetof(TAdSelectCurGC, entry_positions) == 0x1C);
LAYOUT_ASSERT(TAdSelectCurGC_cursor_size_offset, offsetof(TAdSelectCurGC, cursor_size) == 0x9C);
LAYOUT_ASSERT(TAdSelectCurGC_selection_table_offset, offsetof(TAdSelectCurGC, entry_alpha) == 0x6BC);

LAYOUT_ASSERT(SelectCursorQuadSize, sizeof(SelectCursorQuad) == 0x20);
LAYOUT_ASSERT(SelectCursorQuadsOffset, offsetof(TAdSelectCurGC, quads) == 0xBC);
LAYOUT_ASSERT(SelectCursorIndexOffset, offsetof(TAdSelectCurGC, selected_index) == 0xA4);
LAYOUT_ASSERT(SelectCursorConfirmationOffset, offsetof(TAdSelectCurGC, confirmation) == 0xAC);

struct NJS_TEXLIST;
extern "C" NJS_TEXLIST *menu_selection_cursor_texture_list;

#endif
