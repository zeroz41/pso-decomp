#ifndef PSO_UI_WINDOW_TWINDOWSUBCUSTOMSELECT_H
#define PSO_UI_WINDOW_TWINDOWSUBCUSTOMSELECT_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

struct TWindowSubCustomSelect : public TWindowAddition {
    TWindowSubCustomSelect(s32 client);
    virtual ~TWindowSubCustomSelect();
    virtual void render();
    u8 m_70;
    u8 m_71;
    u8 m_72;
    u8 m_73;
    u32 m_74;
    uaddr m_78;
    uaddr m_7c;
    u32 m_80;
    void handle_cancel();
    void handle_decide();
    void update_list_scroll();
    void handle_grid_navigation();
    void draw_cursor(u8 *arg1);
    void draw_palette_cells(WindowDrawContext *ctx);
    virtual void run_task();
    int is_active();
    void *get_selected_action();
};

LAYOUT_ASSERT(TWindowSubCustomSelect_size, sizeof(TWindowSubCustomSelect) == 0x84);

LAYOUT_ASSERT(TWindowSubCustomSelectFieldsOffset, offsetof(TWindowSubCustomSelect, m_70) == 0x70);

#endif
