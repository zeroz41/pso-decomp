#ifndef PSO_UI_WINDOW_TWINDOWSUBCUSTOMEQUIP_H
#define PSO_UI_WINDOW_TWINDOWSUBCUSTOMEQUIP_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowSubStatusDisp;

struct TWindowSubCustomEquip : public TWindowBase {
    TWindowSubCustomEquip(s32 slot);
    virtual ~TWindowSubCustomEquip();
    void handle_cursor_input();
    void update_palette_slot(s32, s32, s32);
    void sub_80275F08(void *);
    virtual void render();
    u8 m_60;
    u8 m_61;
    u8 m_62;
    u8 m_63;
    u8 m_64;
    u8 m_65;
    s16 m_66;
    u32 m_68;
    TWindowSubStatusDisp *m_6c;
    void set_relative_pos(void *relative_pos);
    void layout_selection_parts(void *arg1);
    void layout_entry_group(void *index);
    void reset_selection();
    void refresh_palette_slots();
    void update_rotate_anim();
    void handle_cancel();
    void handle_decide();
    virtual void run_task();
    int is_selected();
    void clear_flag_and_set_entry_state();
    void draw_cursor(u8 *arg1);
    s32 is_type_valid();
    static s32 get_saved_slot_for_index(s32 arg0, s8 arg1);
    void get_cursor_pos(void *arg1);
    void remove_duplicate_bindings(void *arg1);
    void toggle_action_binding(void *arg1);
    void place_bank_slot_on_ring(s32 angle, s32 index);
};

LAYOUT_ASSERT(TWindowSubCustomEquip_size, sizeof(TWindowSubCustomEquip) == 0x70);

LAYOUT_ASSERT(TWindowSubCustomEquipHeadingOffset, offsetof(TWindowSubCustomEquip, m_6c) == 0x6C);

#endif
