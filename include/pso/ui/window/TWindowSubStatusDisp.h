#include "pso/unk/GuildCardRecord.h"
#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/window/TWindowBase.h"

struct PageIndicator;
class ItemListRow;

struct TWindowSubStatusDisp : public TWindowBase {
    // Challenge-mode record set (inferred names): resolve_player_slot maps RECORD_SET_CURRENT to the running
    // game's set by selected_episode and is_split_screen; get_layout_id gives the sets 9/5/9/5 stages.
    enum RecordSet {
        RECORD_SET_CURRENT = -1,
        RECORD_SET_EP1,
        RECORD_SET_EP2,
        RECORD_SET_EP1_SPLIT,
        RECORD_SET_EP2_SPLIT
    };

    TWindowSubStatusDisp(s32 client);
    virtual ~TWindowSubStatusDisp();
    void calc_row_width();
    virtual void run_task();
    virtual void render();
    s16 page; // inferred: index into the dispatch_page_init/update page tables
    u16 m_62;
    u32 m_64;
    PageIndicator *m_68;
    f32 scale_x;
    f32 scale_y;

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
    void set_count_ratio_text(s32 arg1, s32 arg2);
    void clear_visible_flag();
    void increment_counter();
    static s32 destroy_allocation(s32 arg0, s16 arg1);

    static s32 get_status_index(u16 client_index);
    static s32 get_status_index_or_default(u16 *arg0);
    static char *get_status_window(u16 arg0);
    static void *get_message_10(s32 index);
    static void draw_number_digits(void *color, s16 value, u16 digits, f32 x, f32 y, f32 scale);
    static void render_forward();
    static void end_render_forward();
    static void begin_render();
    void clear_fields();
    static saddr get_download_server();
    static u32 calc_text_width(char *s);
    static s32 is_alpha_char(u16 arg0);
    void pack_status_flags(u32 arg1);
    static s32 upload_glyph_if_needed(u16 code, u8 *free_slot, void **arg2);
    static void set_gauge_param(s32 _w0);
    static void reset_gauge(void* p);
    static f32 get_card_window_scale(s32 _w0);
    static s32 get_card_window_flags(s32 client_id);
    static void append_play_time(u32 time);
    static void append_comma();
    s8 *copy_message_page_text();
    void set_selected_index(s16 arg1);
    static void draw_status(saddr window, s32 arg2, s32 arg3);
    static void dispatch_without_flags(saddr window, s32 arg2, s32 arg3);
    s16 get_item_type();
    s16 get_field_2F8();
    s16 get_stat();
    s16 get_value();
    void set_all_values(s32 meseta);
    void set_animated_target(s32 arg1, f32 farg0);
    static void update_palette_sprite();
    void set_string(uaddr arg1);
    void set_text(uaddr arg1, s32 arg2, s32 arg3);
    void set_text(uaddr arg1, s32 arg2);
    void clamp_scroll_offset();
    void add_list_entry(s32 arg1);
    void refresh_selected_entry(s32 arg1);
    void add_status_entry(s8 arg1, s32 src, s32 arg3);
    void add_inventory_item(saddr item, s32 count, s32 sid);
    void add_item_info_entry(saddr arg1, s32 arg2, saddr count);
    void add_ground_item(saddr arg1, s32 arg2);
    void init_scroll_pos();
    int is_flag80_set();
    void add_text_entry(s32 arg1, s32 arg2);
    void set_entry1_field20(s32 arg1);
    void start_hp_text_color_transition();
    void init_gauge_entry();
    void update_status_entry();
    void update_hp_tp_level();
    static f32 get_base_y(f32 farg0);
    void update_entry_color();
    void set_entry_state(s8 arg1);
    void draw_entry_tab(void *arg1);
    void update(void* a1);
    static s32 deleting_destructor(s32 arg0, s16 arg1);
    void forward_render(void *a1);
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
    static s32 build_status_text(s32 arg0);
    static s32 calc_layout_hash(s32 slot);
    static s32 calc_entry_offset(s32 slot);
    static s32 get_layout_id(s32 slot);
    static s32 resolve_player_slot(s32 slot);
    void advance_state();
    void finalize_state();
    void setup_entry_msg_d1(s32 arg1);
    void setup_entry_msg_d0(s32 arg1);
    void init_no_item_entry(s32 arg1);
    void init_entry(s8 arg1, s8 arg2, u8 arg3, u32 src, s32 arg5);
    void setup_stat_line(s32 src, s32 arg2, s32 arg3);
    static void init_status_entry_by_flag(ItemListRow *row, s32 flag, u32 src, s32 item);
    void init_list_entry(u8 arg1, s32 src, s32 arg3);
    void set_inventory_item(void *item, s32 count, s32 sid);
    void update_from_player(void *item, s32 arg2, s32 arg3);
    void init_item_row(void *item, s32 arg2);
    void set_item_info(void* a1, int a2, void* a3);
    void set_ground_item(void *arg1, s32 arg2);
    void init_display(s32 src, s32 arg2);
    static void *get_entry_ptr(int a0);
    void append_entry(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    s32 update_hp_entry();
    static s32 destroy_status_display(saddr arg0, s16 arg1);
    u8 *construct_type1_heading(s32 title, s32 client_index);
    void update_entry_visibility();
    void update_item_colors(saddr item);
    s32 update_hp_gauge();
    static void *find_cached_glyph(u16 code);
    static u8 calc_gauge_scale(u16 glyph, void *arg1, s32 color);
    void update_item_icon_colors(void *item);
    static void init_status_entry(ItemListRow *row, u8 category_icon, u32 src, s32 item);
    static void reset(void *arg0);
    static void *destroy_free_buffers(void *window_sub_status_disp, s16 arg1);
};

LAYOUT_ASSERT(TWindowSubStatusDisp_offset_page, offsetof(TWindowSubStatusDisp, page) == 0x60);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_m_62, offsetof(TWindowSubStatusDisp, m_62) == 0x62);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_m_68, offsetof(TWindowSubStatusDisp, m_68) == 0x68);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_scale_x, offsetof(TWindowSubStatusDisp, scale_x) == 0x6C);
LAYOUT_ASSERT(TWindowSubStatusDisp_offset_scale_y, offsetof(TWindowSubStatusDisp, scale_y) == 0x70);

LAYOUT_ASSERT(TWindowSubStatusDisp_size, sizeof(TWindowSubStatusDisp) == 0x74);
extern "C" s32 measure_string_len(const char *str);

#endif
