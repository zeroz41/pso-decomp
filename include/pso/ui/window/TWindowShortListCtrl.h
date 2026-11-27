#ifndef PSO_UI_WINDOW_TWINDOWSHORTLISTCTRL_H
#define PSO_UI_WINDOW_TWINDOWSHORTLISTCTRL_H

#include "types.h"
struct NJS_POINT2;
class TWindowMenuIconLine;
struct TWindowMenu;
struct TWindowHelpItem;
#include "pso/system/task/TObject.h"

struct TWindowShortListCtrl : public TObject {
    TWindowShortListCtrl(TObject *parent, s32 client_id);
    virtual ~TWindowShortListCtrl();
    static const char *class_name;
    void refresh_technique_rows(saddr tech_window, const NJS_POINT2 *position);
    void cycle_list_page();
    void enter_page_first_state();
    virtual void run_task();
    // Short list shown (0..3; saved in the card window flags bits 16-17); cycle_list_page steps it.
    s8 page;
    // run_task state; enter_page_first_state sets the first state of the page (0, 3, 6, 9).
    u8 state;
    // Frames since open (run_task counts it, wraps to 2; the close button is ignored below 3).
    s16 timer;
    // tp and hold status the technique list was built for (TWindowSubTechnique::update_selection).
    s16 shown_tp;
    u8 pad_22[2];
    u32 client_id;
    s32 shown_hold_status;
    // Technique list (create_window, page 3).
    TWindowMenu *tech_window;
    // Item / shortcut list (create_equip_kind_window, pages 0-2).
    TWindowMenuIconLine *list_window;
    // Help window (TWindowHelpItem) toggled by button 0x400; cycle_list_page is off while it is open.
    TWindowHelpItem *help_window;
    // Item id the help window shows (set_displayed_item; -1 when opened).
    s32 help_item_id;
    static s32 get_card_window_flags(s32 client_id);
    void set_displayed_item(s32 item_id);
    s32 is_technique_usable();
    void swap_card_entries(s32 index_a, s32 index_b);
    static void assign_item_to_palette(u32 item_id, u32 client_id);
    void destroy_children();
    TWindowMenu *create_window(const NJS_POINT2 *position, const NJS_POINT2 *list_position);
    virtual void render();
    static void set_card_window_flags(saddr client_id, s32 page);
    static void assign_shortcut(s32 slot, saddr item, s32 client_id);
};

LAYOUT_ASSERT(TWindowShortListCtrl_size, sizeof(TWindowShortListCtrl) == 0x3C);

void init_default_short_list_order(s16 *dst);

#endif
