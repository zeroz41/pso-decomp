#ifndef PSO_UI_TUNK_804EE458_H
#define PSO_UI_TUNK_804EE458_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

class TUnk_804EE458 : public TObject {
public:
    TUnk_804EE458(TObject *parent);
    virtual ~TUnk_804EE458();
    virtual void render();
    virtual void run_task();
    s32 sub_8033596C();
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
LAYOUT_ASSERT(TUnk_804EE458_size, sizeof(TUnk_804EE458) == 0x3C);

#endif
