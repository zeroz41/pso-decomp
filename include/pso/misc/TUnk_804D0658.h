#ifndef PSO_MISC_TUNK_804D0658_H
#define PSO_MISC_TUNK_804D0658_H
#include "types.h"
#include "pso/misc/TWindowAddition.h"

class TUnk_804D0658 : public TWindowAddition {
public:
    virtual ~TUnk_804D0658();
    void draw();
    void draw_setting(s32);
    void clamp_scroll();
    void update_scroll_offset();
    void move_cursor_prev();
    void move_next_choice();
    void request_close();
    void *destroy_children(s16);
    int is_selected();
    int is_open();
    u8 unk_1C[0x10];
    s32 m_2c;
    u8 unk_30[0xC];
    f32 m_3c;
    u8 unk_40[0xC];
    f32 m_4c;
    u8 unk_50[0xC];
    s32 m_5c;
    u8 unk_60[0x10];
    u16 m_70;
    u8 unk_72[0x2];
    s16 m_74;
    u8 unk_76[0x2];
    u32 m_78;
    u8 unk_7C[0x4];
};
typedef char TUnk_804D0658_size[sizeof(TUnk_804D0658) == 0x80 ? 1 : -1];

#endif
