#ifndef PSO_UI_WINDOW_TWINDOWDD_H
#define PSO_UI_WINDOW_TWINDOWDD_H

#include "types.h"
#include "pso/system/task/TObject.h"

s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
extern "C" {
s32 TWindowDD_is_id_in_range_5AC_5F9(s32 value);
}

class TWindowDD_WS_Word;
struct NJS_TEXLIST;
struct WordSelectMessage;

struct TWindowDDValueList {
    s16 *values;
    s32 count;
};

struct TWindowDD : public TObject
{
    TWindowDD(TObject *parent, void *arg2);
    virtual ~TWindowDD();
    virtual void run_task();
    s16 menu_index;
    u8 _pad1E[0x2];
    s32 m_20;
    u32 m_24[8];
    u32 m_44[8];
    u32 m_64[6];
    uaddr m_7c;
    u32 m_80;
    uaddr m_84;
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
    u8 m_c4[0x1C];
    u8 m_e0[0x1C];
    s16 selected_word;
    u8 _padFE[0x2];
    u32 m_100;
    u32 m_104;
    void draw_transformed_primitive(s32 a1, u32 id, s32 a3);
    void reset_entries(f32 z, s32 color);
    void set_quad_corners_scaled(f32 x, f32 y, f32 farg2);
    static s32 apply_both_choices(s32 arg0, saddr buttons);
    void set_clamped_page(s32 clamped_page);
    void handle_input();
    void set_clamped_selection(s32 clamped_selection);
    static void *create();
    void set_value_f32(s32 arg1);
    void set_scale(s32 arg1, s32 arg2);
    static s32 check_all_ready(s32 floor);
    void update_com_card();
    int initialize_subwindow();
    void set_mode_2();
    void reset_cursor();
    void set_pos_and_data(f32 farg0);
    s32 get_field_0x74();
    s32 get_cursor_index();
    s32 update_if_field28_set();
    s32 get_field_68();
    void enter_state_19();
    void enter_state_18();
    void enter_state_9();
    void update_dispatch();
    void update_layout();
    void update_transition();
    void update();
    static saddr get_element_ptr(s32 arg0);
    virtual void render();
    void reset_selection();
    void update_selected_id();
    static void build_player_word_lists();
    static void free_buffers();
    static void open(void *message, u16 speaker);
    static u8 is_id_in_special_range(s16 id);
    static s32 classify_id(s16 id);
    static s32 get_player_battle_flag_state(u16 client);
    void format_type6_message(saddr window_dd, void *pos);
    static s32 is_state_zero_unless_0x2C8(s32 arg0);
    void destroy_menu_entry(s32 arg1);
    void set_item_pos(s32 i);
    u8 *init_last_child();
    s32 setup_entry(s16 id);
    s32 get_current_child_index();
    static void *get_entry(void *window, int index);
    void init_entry_field_64(s32 arg1);
    static void refresh_sub(void* p, void* a1);
    static void apply_input(void* p, void* a1);
    static void update(void* p, void* child);
    void update(saddr window_dd);
    static void set_default_coords(int a0, TWindowDD_WS_Word *win);
    static void init_layout(void *window, TWindowDD_WS_Word *child);
    static void set_default_positions(void *window, TWindowDD_WS_Word *child);
    static void spawn_window();
    static void play_se();
    static void play_sound();
    int test_input_flag_4();
    s32 get_word_select_context();
    s32 get_mode_code();
    void set_state();
    void close_all_windows();
    static s32 can_append_chars(s32 arg0, s32 *pos);
    static void format_message(WordSelectMessage *message, char *text, u16 player);
    void append_prompt_newline(s32 *pos);
    static s32 clamp_range_5FA_682(s16 id);
    static s32 clamp_range_2C9_552(s16 id);
    static void show_message_by_count(char *buf, s32 *pos);
    void maybe_scroll(void* a1);
    s32 count_chars_since_newline(s32 *len);
    static void append_char(s8 c, char *buf, s32 *pos);
    static void append_string(const char *str, char *buf, s32 *pos);
    void copy_point_table(s32 idx);
    static s32 get_draw_count(const NJS_TEXLIST *textures);
    static saddr get_entry(s32 arg0);
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
    void handle_confirm_input();
    void update_selection_state();
    static void update_draw(void *p);
    static void enter_state_16(void *window_dd);
    static void apply_entry_layout(void *window_dd);
    static void update_state(void *window_dd);
    static s32 update_close_flag(void *window_dd);
};

#include <stddef.h>
LAYOUT_ASSERT(WindowListSize, sizeof(TWindowDDValueList) == 8);
LAYOUT_ASSERT(WindowListCountOffset, offsetof(TWindowDDValueList, count) == 4);

extern "C" {
s32 TWindowDD__sub_80340820(void *p);
void TWindowDD__sub_80340910(void *p);
}
s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
extern "C" {
void *__dt__21TWindowWordSelectModeFv(void *arg0, s16 arg1);
void measure_message_text_width_default(void *entry);
extern TWindowDDValueList *TWindowDD__ws_data_base;
extern TWindowDDValueList *TWindowDD__ws_data_table;
void build_item_list__9TWindowDDFPv(TWindowDD *window);
s32 TWindowDD__sub_8034435C(TWindowDD *window, u32 mode, s32 entry_id, s32 value_index);
s32 TWindowDD__sub_80344568(TWindowDD *window, u32 mode, s32 entry_id, s32 value_index);
s32 TWindowDD__sub_80344774(TWindowDD *window, u32 mode, s32 entry_id, s32 value_index);
s32 TWindowDD__sub_80346434(TWindowDD *window, u32 mode, s32 entry_id, s32 value_index);
s32 TWindowDD__sub_80346640(TWindowDD *window, u32 mode, s32 entry_id, s32 value_index);
s32 dispatch_by_window_mode(TWindowDD *window, u32 window_mode, s32 entry_id, s32 value_index);
void TWindowDD__sub_80344114(void);
}

// Upper bounds of the numeric word-select entries, indexed by TWindowDD::classify_id.
extern const s32 word_select_numeric_limits[6];

#endif
