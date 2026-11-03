#ifndef PSO_MISC_TWINDOWSHORTLISTCTRL_H
#define PSO_MISC_TWINDOWSHORTLISTCTRL_H

#include "types.h"
#include "pso/TObject.h"

struct TWindowShortListCtrl : public TObject {
    TWindowShortListCtrl(TObject *parent, s32 client_id);
    virtual ~TWindowShortListCtrl();
    void refresh_technique_rows(s32, void *);
    void cycle_list_page();
    void sub_8026EA48();
    virtual void run_task();
    // Short list shown (0..3; saved in the card window flags bits 16-17); cycle_list_page steps it.
    s8 page;
    // run_task state; sub_8026EA48 sets the first state of the page (0, 3, 6, 9).
    u8 state;
    // Frames since open (run_task counts it, wraps to 2; the close button is ignored below 3).
    s16 timer;
    // TWindowSubTechnique::get_current_selection / update_selection snapshot (s16, then s32 at 0x28).
    void* m_20;
    u32 client_id;
    void* m_28;
    // Technique list (create_window, page 3).
    void *tech_window;
    // Item / shortcut list (create_equip_kind_window, pages 0-2).
    void *list_window;
    // Help window (TWindowHelpItem) toggled by button 0x400; cycle_list_page is off while it is open.
    void *help_window;
    // Item id the help window shows (set_displayed_item; -1 when opened).
    s32 help_item_id;
    void update_variant_a();
    void update_variant_b();
    void update_variant_c();
    static s32 get_card_window_flags(s32 client_id);
    static s32 get_card_status_bits();
    void set_displayed_item(s32 arg1);
    s32 is_technique_usable();
    void swap_card_entries(s32 arg1, s32 arg2);
    static void assign_item_to_palette(u32 arg0, u32 arg1);
    void destroy_children();
    void *create_window(s32 arg1, s32 arg2);
    virtual void render();
    static void set_card_window_flags(s32 arg0, s32 arg1);
    s16 get_cursor_pos();
    void update_cursor_pos();
    static void assign_shortcut(s32 arg0, s32 arg1, s32 arg2);
};

typedef char TWindowShortListCtrl_size[sizeof(TWindowShortListCtrl) == 0x3C ? 1 : -1];
#endif
