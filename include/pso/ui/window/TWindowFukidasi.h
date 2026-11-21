#ifndef PSO_UI_WINDOW_TWINDOWFUKIDASI_H
#define PSO_UI_WINDOW_TWINDOWFUKIDASI_H

#include "types.h"

struct TWindowFukidasi
{
    u8 _pad1C[0x4];
    u16 m_20;
    u8 _pad22[0x4E];
    u8 m_70;
    u8 m_71;
    u8 m_72;
    u8 m_73;
    u8 _pad74[0x2];
    u16 m_76;
    u32 m_78;
    static s32 draw_resolved_window(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void hide();
    int get_visible_flag();
    int is_bit10_set();
    s32 check_card_match_enabled(saddr arg1);
    void sync_display_pos();
    s32 approach(f32 farg0);
    void get_boundary_offset(s32 angle, f32 *out);
    void *find_balloon_overlap_for(saddr next);
    void rearm_balloon(saddr flags);
};

extern "C" {
void *sub_80251DF0__13TUnk_804CF0B8Fslsf(void *arg0, s32 arg1, s32 str, s32 arg3, f32 farg0);
s32 clamp_position__13TUnk_804CF0B8FPvf(void *arg0, void *arg1, f32 farg0);
}
void complete_speech_balloon(u8 *arg0);
extern "C" {
void init_flags__15TWindowFukidasiFPvi(void *arg0, s32 arg1);
}
s32 is_speech_balloon_ready(u8 *arg0);
extern "C" {
void open__15TWindowFukidasiFPvPvi(u8 *arg0, u32 *arg1, s32 arg2);
void set_color__13TUnk_804CF0B8FUs(void *arg0, u16 arg1);
void set_text__15TWindowFukidasiFPvii(u8 *arg0, saddr str, saddr arg2);
u8 *TWindowFukidasi__sub_80252B74(u8 *arg0, s32 player, s32 str, s32 client, f32 farg0);
}

#endif
