#ifndef PSO_UI_WINDOW_TWINDOWDD_H
#define PSO_UI_WINDOW_TWINDOWDD_H

#include "types.h"

s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
extern "C" {
s32 TWindowDD_is_id_in_range_5AC_5F9(s16 id);
}

struct TWindowDDValueList {
    s16 *values;
    s32 count;
};

extern "C" {
s16 TWindowDD_read_indexed_value(s32 entry_index, s32 value_index);
s16 TWindowDD_read_resolved_value(s32 entry_id, s32 value_index);
}

struct TWindowDD
{
    void run_task();
    u16 m_1c;
    u8 _pad1E[0x2];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u8 _pad2C[0x18];
    u32 m_44;
    u8 _pad48[0x1C];
    u32 m_64;
    u32 m_68;
    u32 m_6c;
    u32 m_70;
    u8 _pad74[0x8];
    u32 m_7c;
    u32 m_80;
    u32 m_84;
    u32 m_88;
    u32 m_8c;
    u32 m_90;
    u32 m_94;
    u32 m_98;
    u32 m_9c;
    u32 m_a0;
    u32 m_a4;
    u32 m_a8;
    u32 m_ac;
    u32 m_b0;
    u32 m_b4;
    u32 m_b8;
    u32 m_bc;
    u32 m_c0;
    s16 m_c4;
    u8 _padC6[0x1A];
    s16 m_e0;
    u8 _padE2[0x1A];
    u16 m_fc;
    u8 _padFE[0x2];
    u32 m_100;
    u32 m_104;
    void draw_transformed_primitive(void* a1, void* a2, void* a3);
    void reset_entries(f32 z, s32 color);
    void set_quad_corners_scaled(f32 farg0, f32 farg1, f32 farg2);
    static s32 apply_both_choices(s32 arg0, s32 arg1);
    void set_clamped_page(s32 arg1);
    void handle_input();
    void set_clamped_selection(s32 arg1);
    static void *construct_variant_a(void *arg0v);
    static void *create();
    static void init_layout_constants();
    void init();
    void set_value_f32(s32 arg1);
    void set_scale(s32 arg1, s32 arg2);
    static s32 check_all_ready(s32 arg0);
    int update_com_card();
    int initialize_subwindow();
    void *destroy_window_base(s16 arg1);
    static void refresh_status_display();
    void init_window();
    void init_and_set_field50(void *arg1);
    void update_position(s32 arg1);
    void set_first_entry_text(u32 arg1);
    void set_mode_2();
    void reset_cursor();
    void handle_scroll_input();
    void init_and_mark_field8C();
    void free_child();
    void init_child(void* a1);
    void init_layout_entries();
    void reset_fields();
    void load_element_list();
    void set_pos_and_data(f32 farg0);
    s32 get_field_0x74();
    s32 get_cursor_index();
    s32 update_if_field28_set();
    void get_cursor_pos(u8 *arg1);
    s32 get_field_68();
    void add_scroll_offset(int a1);
    void enter_state_19();
    void enter_state_18();
    void enter_state_9();
    void update_dispatch();
    void update_layout();
    void update_transition();
    void update();
    static s32 get_element_ptr(s32 arg0);
    void render();
    void reset_selection();
    void update_selected_id();
    static void build_player_word_lists();
    static void open(s32 arg0, s32 arg1);
    static u8 is_id_in_special_range(s16 id);
    static s32 classify_id(s16 arg0);
    static s32 get_player_battle_flag_state(u16 arg0);
    void format_type6_message(s32 arg1, void *arg2);
    static s32 is_state_zero_unless_0x2C8(s32 arg0);
    void destroy_menu_entry(s32 arg1);
    void set_item_pos(s32 i);
    u8 *init_last_child();
    s32 setup_entry(s32 arg1);
    s32 get_current_child_index();
    static void*get_entry(int a0, int a1);
    void init_entry_field_64(s32 arg1);
    static void refresh_sub(void* p, void* a1);
    static void apply_input(void* p, void* a1);
    static void update(void* p, void* a1);
    void update(s32 arg1);
    static void set_default_coords(int a0, void* a1);
    static void init_layout(int a0, void* a1);
    static void set_default_positions(int a0, void* a1);
    static void spawn_window();
    static void play_se();
    static void play_sound();
    int test_input_flag_4();
    static void dispatch_state();
    s32 get_word_select_context();
    s32 get_mode_code();
    void set_state();
    void close_all_windows();
    static s32 can_append_chars(s32 arg0, s32 *arg1);
    static void update_state();
    void append_prompt_newline(s32 *arg1);
    static s32 clamp_range_5FA_682(s16 arg0);
    static s32 clamp_range_2C9_552(s16 arg0);
    static void show_message_by_count(s32 arg0, s32 arg1);
    void maybe_scroll(void* a1);
    s32 count_chars_since_newline(s32 *len);
    static void append_char(s8 arg0, s32 arg1, s32 *arg2);
    static void append_string(s32 arg0, s32 arg1, s32 *arg2);
    void copy_point_table(s32 idx);
    static s32 get_draw_count(void **arg0);
    static s32 get_entry(s32 arg0);
    int handle_word_select();
    static void send_chat_packet(void *data);
    void update_and_send_lobby();
    void init_header();
    void bswap_word_select();
    void reset_index();
    void set_field14(s32 v);
    void pop_entry();
    void init_item_slots();
    static void init_ws_data_tables();
    static s32 lookup_item_category(s32 arg0);
    static s32 draw_default_entry(s32 arg0);
    u8 *construct_base(u8 *arg1, s16 arg2, u8 *arg3);
    void handle_confirm_input();
    void update_selection_state();
};

#include <stddef.h>
typedef char WindowListSize[sizeof(TWindowDDValueList) == 8 ? 1 : -1];
typedef char WindowListCountOffset[offsetof(TWindowDDValueList, count) == 4 ? 1 : -1];

extern "C" {
s32 TWindowDD__sub_80340820(void *p);
void TWindowDD__sub_80340910(void *p);
}
s32 TWindowDD_check_input_mask(void *input_context, s32 arg1);
extern "C" {
void *__dt__13TUnk_804EFBACFv(void *arg0, s16 arg1);
void update_draw__9TWindowDDFPv(void *p);
}

#endif
