#ifndef PSO_UI_WINDOW_TUNK_804D0658_H
#define PSO_UI_WINDOW_TUNK_804D0658_H
#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

class TWindowSubStatusDisp;

class TUnk_804D0658 : public TWindowAddition {
public:
    // inferred: this is TWindowMenuInfomation (its unit's class-name string).
    TUnk_804D0658(void *parent, s32 rows);
    virtual ~TUnk_804D0658();
    virtual void run_task();
    virtual void render();
    void draw();
    void draw_setting(saddr);
    void clamp_scroll();
    void update_scroll_offset();
    void move_cursor_prev();
    void move_next_choice();
    void request_close();
    int is_selected();
    int is_open();
    u16 m_70;
    u8 unk_72[0x2];
    s16 m_74;
    u8 unk_76[0x2];
    TWindowSubStatusDisp *heading;  // type-1 heading made by create_sub_window (inferred)
    u8 unk_7C[0x4];
};
LAYOUT_ASSERT(TUnk_804D0658_size, sizeof(TUnk_804D0658) == 0x80);

#endif
