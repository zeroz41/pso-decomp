#ifndef PSO_UI_WINDOW_TWINDOWSUBCUSTOMEQUIP_H
#define PSO_UI_WINDOW_TWINDOWSUBCUSTOMEQUIP_H

#include <stddef.h>
#include "types.h"

class WindowHeading;
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"

class TWindowSubStatusDisp;
class WindowSpritePart;
struct NJS_POINT2;

void set_relative_pos(NJS_POINT2 *position, WindowSpritePart *entry);

struct TWindowSubCustomEquip : public TWindowBase {
    static u8 bank_ring_init_done;
    static f32 ring_scale;
    TWindowSubCustomEquip(s32 slot);
    virtual ~TWindowSubCustomEquip();
    static const char *class_name;
    void handle_cursor_input();
    void update_palette_slot(s32, u16, u16);
    void get_cursor_origin(NJS_POINT2 *position);
    virtual void render();
    s8 state_flags;
    u8 slot;
    u8 bank;
    u8 bank_swap_timer;
    s8 front_bank;
    s8 back_bank;
    s16 cursor_frame;
    u32 angle;
    WindowHeading *status_disp;
    void layout_selection_parts(void *selection);
    void layout_entry_group(void *index);
    void reset_selection();
    void refresh_palette_slots();
    void update_rotate_anim();
    void handle_cancel();
    void handle_decide();
    virtual void run_task();
    int is_selected();
    void clear_flag_and_set_entry_state();
    void draw_cursor(WindowDrawContext *context);
    static void draw_cursor_sprite(f32 depth_scale, WindowDrawContext *context, NJS_POINT2 *position, s32 frame);
    s32 is_type_valid(u8 type);
    s32 get_saved_slot_for_index(u8 slot);
    void get_cursor_pos(PaletteTag *tag);
    void remove_duplicate_bindings(const PaletteTag *tag);
    void toggle_action_binding(PaletteTag *tag);
    void place_bank_slot_on_ring(s32 angle, s32 index);
};

LAYOUT_ASSERT(TWindowSubCustomEquip_size, sizeof(TWindowSubCustomEquip) == 0x70);

LAYOUT_ASSERT(TWindowSubCustomEquipHeadingOffset, offsetof(TWindowSubCustomEquip, status_disp) == 0x6C);

#endif
