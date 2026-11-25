#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_H

struct GuildCardRecord;

#include "types.h"
#include <stddef.h>
#include "pso/ui/window/TWindowBase.h"

struct PageIndicator;
class ItemListRow;

struct TWindowSubStatusDisp : public TWindowBase {
    static void * window_layout[5];
    static void * numbered_times_layout[72];
    static void * rank_time_records_layout[114];
    static void * record_summary_layout[114];
    static void * resistance_layout[212];
    static void * stat_page_layout[254];
    static void * summary_page_layout[135];
    TWindowSubStatusDisp(s32 client);
    virtual ~TWindowSubStatusDisp();
    virtual void run_task();
    virtual void render();
    s16 page; // index into the dispatch_page_init/update page tables
    s16 requested_page;  // the page the owner wants shown (set_requested_page); run_task switches to it
    u32 m_64;
    PageIndicator *m_68;
    f32 scale_x;
    f32 scale_y;

    void set_requested_page(s16 value);
    void set_scale(f32 x, f32 y);
    void vt0();
    void vt1();
    void vt2();
    void vt3();
    void vt4();
    void vt5();
    void vt7();
    void vt11();
    void vt12();
    void vt13();
    void vt14();
    void vt15();
    void vt16();
    void vt18();

    void dispatch_page_update();
    void dispatch_page_init();
    void set_count_ratio_text(s32 count, s32 total);
    void clear_visible_flag();
    static s32 destroy_allocation(s32 arg0, s16 arg1);

    static void *get_message_10(s32 index);
    static void draw_number_digits(void *color, s16 value, u16 digits, f32 x, f32 y, f32 scale);
    static void render_forward();
    static void end_render_forward();
    static void begin_render();
    static saddr get_download_server();
    static u32 calc_text_width(char *s);
    static s32 is_alpha_char(u16 arg0);
    void pack_status_flags(u32 arg1);
    static s32 upload_glyph_if_needed(u16 code, u8 *free_slot, void **arg2);
    static void set_gauge_param(s32 gauge_param);
    static void reset_gauge(void* p);
    static f32 get_card_window_scale(s32 client_id);
    static s32 get_card_window_flags(s32 client_id);
    static void append_play_time(u32 time);
    static void append_comma();
    s8 *copy_message_page_text();
    s16 get_item_type();
    s16 get_field_2F8();
    s16 get_stat();
    void set_all_values(s32 meseta);
    void set_animated_target(s32 meseta, f32 farg0);
    static void update_palette_sprite();
    void init_scroll_pos();
    void add_text_entry(s32 arg1, s32 arg2);
    static f32 get_base_y(f32 width);
    void update_entry_color();
    void set_entry_state(s8 entry_state);
    void draw_entry_tab(void *arg1);
    void update(void* a1);
    static s32 deleting_destructor(s32 arg0, s16 arg1);
    void forward_render(void *level);
    int update_subwindow();
    void fill_card_text_entries(GuildCardRecord *record);
    static saddr query_status_field(void *arg0, s8 arg1);
    static saddr get_flag_or_zero(void *arg0, s8 arg1);
    static void draw_split_screen_dividers();
    static void draw_tiled_background();
    static void draw_bottom_bar();
    static void draw_split_screen_hud();
    static void get_player();
    void set_entry_display_value(s32 str);
    s32 get_display_mode();
    static f32 round_away_from_zero(f32 farg0);
    static s32 build_status_text(s32 client_id);
    static void *get_entry_ptr(int a0);
    static s32 destroy_status_display(saddr arg0, s16 arg1);
    u8 *construct_type1_heading(s32 title, s32 client_index);
    void update_entry_visibility();
    static void *find_cached_glyph(u16 code);
    static u8 calc_gauge_scale(u16 glyph, void *arg1, s32 color);
};

LAYOUT_ASSERT(TWindowSubStatusDisp_offset_page, offsetof(TWindowSubStatusDisp, page) == 0x60);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_requested_page, offsetof(TWindowSubStatusDisp, requested_page) == 0x62);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_m_68, offsetof(TWindowSubStatusDisp, m_68) == 0x68);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_scale_x, offsetof(TWindowSubStatusDisp, scale_x) == 0x6C);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_scale_y, offsetof(TWindowSubStatusDisp, scale_y) == 0x70);

LAYOUT_ASSERT(TWindowSubStatusDisp_size, sizeof(TWindowSubStatusDisp) == 0x74);
s32 measure_string_len(const char *str);

#endif
