#ifndef PSO_MISC_TUNK_804CF0B8_H
#define PSO_MISC_TUNK_804CF0B8_H
#include "types.h"
#include "pso/misc/TWindowAddition.h"

class TUnk_804CF0B8 : public TWindowAddition {
public:
    virtual ~TUnk_804CF0B8();
    void draw_body(void *, u32, f32 *, f32);
    void draw_body_row(void *, void *, f32, f32, f32, f32);
    void draw_tail(void *, u32, f32 *, f32);
    void sub_80251DF0(s16, s32, s16, f32);
    s32 clamp_position(void *, f32);
    void set_color(u16);
    void follow_anchor();
    s32 is_speaker_far_or_offscreen();
    s32 project_anchor(f32 *, f32 *);
    void place_rect_at_head_or_slot();
    void sub_802504A8();
    void calc_text_size(f32 *);
    virtual void render();
    void clear_flag();
    s16 get_field_20();
    int get_flag_bit1();
    s8 alloc_nearest_free_slot();
    int is_balloon_visible();
    int is_active();
    void clear_flag_20();
    int is_flag_set();
    void sub_80252C68();
    void set_flag();
    void clear_visible_flag();
    void clear_flag2c_bit100();
    void set_flag2c_bit200();
    void clear_flag2c_bit200();
    void set_flag2c_bit100();
    u8 unk_1C[0x4];
    u16 m_20;
    u8 unk_22[0xA];
    u32 m_2c;
    u8 unk_30[0x18];
    f32 m_48;
    u8 unk_4C[0xC];
    f32 m_58;
    u8 unk_5C[0x14];
    s8 m_70;
    u8 m_71;
    u8 unk_72[0x1];
    s8 m_73;
    u8 unk_74[0x2];
    s16 m_76;
    u8 unk_78[0x4];
    f32 m_7c;
    u8 unk_80[0x4];
    s32 m_84;
    u8 unk_88[0x10];
};
typedef char TUnk_804CF0B8_size[sizeof(TUnk_804CF0B8) == 0x98 ? 1 : -1];

#endif
