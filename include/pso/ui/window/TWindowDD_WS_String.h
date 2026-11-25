#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_STRING_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_STRING_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowDD_WS_String : public TWindowBase {
public:
    TWindowDD_WS_String(f32 *position, f32 *size, u32 text, s32 style);
    virtual ~TWindowDD_WS_String();
    static TWindowDD_WS_String *create(f32 width, f32 *pos, f32 *size, u32 str, s32 style);
    void fit_width_to_text(); // inferred: widens target_size[0] to the first entry's text
    virtual void run_task();
    virtual void render();
    void draw(saddr, s32, f32);
    void move_to_start(s32 ticks);
    void update_position(s32 ticks);
    void set_first_entry_text(u32 str);
    void draw_entry_if_visible(void *);
    s32 text_style;        // inferred: point table index passed to draw (ctor argument; 1 and 3 recolor the text)
    f32 start_position[2]; // inferred: position given to the ctor; move_to_start tweens back to it
    f32 end_position[2];   // inferred: second ctor vector (update_position: negative x/y anchor right/bottom)
};
LAYOUT_ASSERT(TWindowDD_WS_String_size, sizeof(TWindowDD_WS_String) == 0x74);

#endif
