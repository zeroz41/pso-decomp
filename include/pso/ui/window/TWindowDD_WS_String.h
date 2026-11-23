#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_STRING_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_STRING_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowDD_WS_String : public TWindowBase {
public:
    TWindowDD_WS_String(f32 *position, f32 *size, u32 text, s32 style);
    virtual ~TWindowDD_WS_String();
    virtual void run_task();
    virtual void render();
    void draw(saddr, s32, f32);
    void init_and_set_field50(void *arg1);
    void update_position(s32 arg1);
    void set_first_entry_text(u32 str);
    void draw_entry_if_visible(void *);
    s32 pad_60;      // point table index passed to draw (ctor argument; 1 and 3 recolor the text)
    f32 pad_64[2];   // position given to the ctor
    f32 pad_6C[2];   // second ctor vector (update_position: negative x/y anchor right/bottom)
};
LAYOUT_ASSERT(TWindowDD_WS_String_size, sizeof(TWindowDD_WS_String) == 0x74);

#endif
