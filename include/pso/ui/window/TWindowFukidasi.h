#ifndef PSO_UI_WINDOW_TWINDOWFUKIDASI_H
#define PSO_UI_WINDOW_TWINDOWFUKIDASI_H
#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

struct RotatedQuadSpriteRect;

class TWindowFukidasi : public TWindowAddition {
public:
    void init_flags(s32 flags);
    TWindowFukidasi(u16 speaker, const char *text, s32 client, f32 scale);
    virtual ~TWindowFukidasi();
    virtual void run_task();
    void update_reveal_timer();
    void draw_body(WindowDrawContext *context, u32 color, f32 *offset, f32 depth);
    void draw_body_row(RotatedQuadSpriteRect *slice, WindowDrawContext *context, f32 offset_x, f32 row_top, f32 width, f32 height);
    void draw_tail(WindowDrawContext *context, u32 color, f32 *offset, f32 depth);
    void draw_name_plate(WindowDrawContext *context, u32 color);
    void init_balloon(u16 speaker, const char *text, s32 client, f32 scale);
    s32 clamp_position(void *, f32);
    void set_color(u16);
    void follow_anchor();
    s32 is_speaker_far_or_offscreen();
    s32 project_anchor(f32 *, f32 *);
    void place_rect_at_head_or_slot();
    void request_balloon_hide();
    void calc_text_size(f32 *);
    s32 calc_name_plate_angle(f32 *, f32 *, f32 *, f32 *);  // dead-stripped
    void clear_width();  // dead-stripped
    void measure_text_unbounded(int);  // dead-stripped
    virtual void render();
    void clear_flag();
    u16 get_speaker_id();
    s16 get_field_20();
    int get_flag_bit1();
    s8 alloc_nearest_free_slot();
    int is_balloon_visible();
    int is_active();
    void clear_flag_20();
    int is_flag_set();
    void set_balloon_visible();
    void set_flag();
    void clear_visible_flag();
    void clear_flag2c_bit100();
    void set_flag2c_bit200();
    void clear_flag2c_bit200();
    void set_flag2c_bit100();

    TWindowFukidasi *find_overlapping_balloon(const f32 *position, const f32 *size, TWindowFukidasi *first);
    TWindowFukidasi *draw_resolved_window(const f32 *position, const f32 *size, s32 viewport);
    void hide();
    int get_visible_flag();
    int is_bit10_set();
    s32 check_card_match_enabled(const char *text);
    void sync_display_pos();
    s32 approach(f32 farg0);
    void get_boundary_offset(s32 angle, f32 *out);
    TWindowFukidasi *find_balloon_overlap_for(TWindowFukidasi *first);
    void rearm_balloon(saddr flags);
    void refresh_rect_placement();
    s32 shift_rect_with_head(f32 *rect, f32 *out);
    s32 rest_balloon(f32 *rect, f32 *out);
    s32 try_place_bubble(f32 *rect, f32 *out);
    s32 sub_802505C0(f32 *rect, f32 *out);
    void clamp_text_size(f32 *out);
    s32 is_speech_balloon_ready();
    void complete_speech_balloon();
    void set_text(saddr str, saddr flags);
    void open(u32 *symbol_chat, s32 flags);

    u8 state;            // run_task's state machine
    u8 balloon_flags;    // bit 0 shown, 1 reveal, 2 active, 5 balloon visible
    u8 content_kind;     // 0 text entry, 1 symbol chat, 2 none (calc_text_size)
    s8 slot;             // the balloon slot taken from TWindowCtrl (alloc_nearest_free_slot)
    s16 display_ticks;   // counts down while the balloon is shown; set from the text length (inferred)
    u16 speaker_id;  // Speaker entity ID, or 0xFFFF for no entity.
    char *name;  // speaker name, drawn by draw_name_plate (inferred)
    f32 scale;
    f32 tail_scale;
    s32 balloon_color;
    f32 balloon_center[2];
    f32 head_position[2];
};
LAYOUT_ASSERT(TWindowFukidasi_fields_offset, offsetof(TWindowFukidasi, state) == 0x70);
LAYOUT_ASSERT(TWindowFukidasi_name_offset, offsetof(TWindowFukidasi, name) == 0x78);
LAYOUT_ASSERT(TWindowFukidasi_scale_offset, offsetof(TWindowFukidasi, scale) == 0x7C);
LAYOUT_ASSERT(TWindowFukidasi_speaker_offset, offsetof(TWindowFukidasi, speaker_id) == 0x76);
LAYOUT_ASSERT(TWindowFukidasi_tail_scale_offset, offsetof(TWindowFukidasi, tail_scale) == 0x80);
LAYOUT_ASSERT(TWindowFukidasi_balloon_center_offset, offsetof(TWindowFukidasi, balloon_center) == 0x88);
LAYOUT_ASSERT(TWindowFukidasi_head_position_offset, offsetof(TWindowFukidasi, head_position) == 0x90);
LAYOUT_ASSERT(TWindowFukidasi_size, sizeof(TWindowFukidasi) == 0x98);

extern "C" {
void set_color__15TWindowFukidasiFUs(void *arg0, u16 arg1);
}

#endif
