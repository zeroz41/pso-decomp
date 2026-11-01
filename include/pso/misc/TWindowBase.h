#ifndef PSO_MISC_TWINDOWBASE_H
#define PSO_MISC_TWINDOWBASE_H
#include "types.h"
#include "pso/TObject.h"

class TWindowBase : public TObject {
public:
    virtual ~TWindowBase();
    void draw_window_frame(void *);
    void draw_window_frame_strips(void *, void *);
    void draw_message_frame_row(void *, void *);
    void resort_window_order();
    void close();
    void set_depth(f32 depth);
    void calc_inner_rect(u8 *);
    void sub_8026CC28();
    void update_window_entry_list(void *);
    void update_fade();
    void draw_quest_message_frame(void *);
    void sub_80244F2C(u8 *, u8 *, s16);
    s32 setup_window_draw_context(s32);
    s32 is_window_reveal_complete();
    s32 sub_80244994();
    void save_position();
    f32 get_scale();
    u8 sub_80246948();
    s32 get_array_entry(int);
    virtual void render();
    virtual void run_task();
};

#endif
