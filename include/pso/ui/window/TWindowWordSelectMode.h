#ifndef PSO_UI_WINDOW_TWINDOW_WORD_SELECT_MODE_H
#define PSO_UI_WINDOW_TWINDOW_WORD_SELECT_MODE_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

// The three-row mode indicator owned by the Word Select window.
class TWindowWordSelectMode : public TWindowBase {
public:
    TWindowWordSelectMode();
    virtual ~TWindowWordSelectMode();
    virtual void run_task();
    virtual void render();
    s32 get_selected_row();
    void hide_selection();
    static TWindowWordSelectMode *create();
    void set_clamped_selection(s32 clamped_selection);
    void handle_input();
    void set_clamped_page(s32 clamped_page);
    s32 highlight_hidden; // nonzero hides the selected row's highlight
    s32 grey_row_count;   // rows below this index draw grey, the rest white
    s32 selected_row;
};
LAYOUT_ASSERT(TWindowWordSelectMode_size, sizeof(TWindowWordSelectMode) == 0x6C);

LAYOUT_ASSERT(TWindowWordSelectMode_highlight_hidden, offsetof(TWindowWordSelectMode, highlight_hidden) == 0x60);
LAYOUT_ASSERT(TWindowWordSelectMode_grey_row_count, offsetof(TWindowWordSelectMode, grey_row_count) == 0x64);
LAYOUT_ASSERT(TWindowWordSelectMode_selected_row, offsetof(TWindowWordSelectMode, selected_row) == 0x68);

#endif
