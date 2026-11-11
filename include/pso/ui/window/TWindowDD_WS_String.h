#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_STRING_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_STRING_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowDD_WS_String : public TWindowBase {
public:
    virtual ~TWindowDD_WS_String();
    virtual void run_task();
    virtual void render();
    void draw(s32, s32, f32);
    void init_and_set_field50(void *arg1);
    void update_position(s32 arg1);
    void set_first_entry_text(u32 str);
    void draw_entry_if_visible(void *);
    u8 pad_1C[0x8];
    u8 pad_24[0xC];  // entry list (update_window_entry_list, draw_visible_window_entries)
    f32 pad_30[2];   // position
    f32 pad_38[2];   // size, from the window descriptor
    u8 pad_40[0x10];
    s32 pad_50;
    u32 m_54;
    u8 pad_58[0x4];
    s32 m_5c;
    s32 pad_60;      // point table index passed to draw (ctor argument; 1 and 3 recolor the text)
    f32 pad_64[2];   // position given to the ctor
    f32 pad_6C[2];   // second ctor vector (update_position: negative x/y anchor right/bottom)
};
typedef char TWindowDD_WS_String_size[sizeof(TWindowDD_WS_String) == 0x74 ? 1 : -1];

#endif
