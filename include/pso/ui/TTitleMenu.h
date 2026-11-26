#ifndef PSO_UI_TTITLEMENU_H
#define PSO_UI_TTITLEMENU_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

class TTitleMenu : public TObject {
public:
    TTitleMenu(TObject *parent);
    virtual ~TTitleMenu();
    virtual void render();
    virtual void run_task();
    s32 get_cursor();
    // Whether the player confirmed a menu entry (state 2).
    s32 is_title_choice_confirmed();
    void draw_record_with_camera(s32 record, s32 camera);
    void update_title_prompt();
    void handle_cursor_input();
    // Field names are inferred from use: run_task switches on state (0 prompt, 1 cursor, 2 done),
    // handle_cursor_input wraps cursor in 0..3, render passes color to set_constant_material,
    // update_title_prompt pulses color.a with frame.
    TObject *owner;
    s32 cursor;
    s32 state;
    NJS_ARGB color;
    s32 frame;
};
LAYOUT_ASSERT(TTitleMenu_size, sizeof(TTitleMenu) == 0x3C);

// The title menu's release and load hooks in lobby_load_callback_table; both do nothing.
void free_title_menu_resources();
void load_title_menu_resources();

#endif
