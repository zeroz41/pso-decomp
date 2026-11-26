#ifndef PSO_UI_WINDOW_TWINDOWDD_H
#define PSO_UI_WINDOW_TWINDOWDD_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WordSelectMessage.h"

s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
s32 TWindowDD_is_id_in_range_5AC_5F9(s32 value);

class TWindowDD_WS_Word;
class TWindowDD_WS_String;
class TWindowDD_WS_ScrollBar;
class TWindowWordSelectMode;
struct TWindowInputNumber;
struct NJS_TEXLIST;

struct TWindowDDValueList {
    s16 *values;
    s32 count;
};

// One row of the word select state table, indexed by TWindowDD::state.
struct TWindowDDStateEntry {
    u32 flags;     // 2: leaving the state drops the last word; 4: it adds a string to strings[4..]
    s16 prompt_id; // word shown in strings[2] while the state is open, -1 for none
    u8 pad_6[0x2];
};

extern TWindowDDStateEntry word_select_state_table[21];

struct TWindowDD : public TObject
{
    static void * ws_data_buffer;
    static TWindowDDValueList * ws_data_table;
    static TWindowDDValueList * ws_data_base;
    static uaddr work_buffer;
    static s32 window_mode;
    TWindowDD(TObject *parent, WordSelectMessage *output);
    virtual ~TWindowDD();
    virtual void run_task();
    s16 menu_index;                     // Its address is the input context of the button tests.
    u8 pad_1e[0x2];
    s32 depth;                          // levels opened so far; each has a word window
    TWindowDD_WS_Word *word_windows[8];
    s32 level_states[8];                // the state a level was in when the next level was opened
    TWindowDD_WS_String *labels[6];     // SELECT, NEXT, the entry text, the message text and two cursor labels
    TWindowDD_WS_ScrollBar *scroll_bar; // shows where the visible rows sit in the word list
    TWindowWordSelectMode *mode_window; // the three-row mode indicator
    TWindowInputNumber *number_window;  // the TWindowInputNumber of a numeric entry
    s32 list_ids[3];                    // element lists of pages depth .. depth + 2
    s32 result_flags;
    s32 token_pushed;                   // 1 once a word of the message has been taken from the list
    s32 last_selected_id;
    s32 enemies_active;
    s32 selection_confirmed;
    s32 dialog_state;                   // 0 choosing, 1 the confirm rows (mode_window) are active, 2 idle
    s32 pending_transition;             // 0 none, 1 open the next level, 2 close this one
    s32 state;                          // run_state's switch
    s32 next_state;
    s32 dialog_locked;
    s32 extra_window_count;
    WordSelectMessage *output;          // the caller's message, written when the player accepts
    WordSelectMessage message;          // the message being composed
    WordSelectMessage final_message;    // copied to output when the player accepts
    s16 selected_word;
    u8 pad_fe[0x2];
    s32 pad_100;
    s32 pad_104;
    static s32 apply_both_choices(void *unused, saddr buttons);
    static s32 check_all_ready(s32 floor);
    void update_com_card();
    void enter_state_19();
    void enter_state_18();
    void enter_state_9();
    void update_dispatch();
    void update_layout();
    void update_transition();
    void update();
    static TWindowDDValueList *get_element_ptr(s32 list_id);
    virtual void render();
    void reset_selection();
    static void build_player_word_lists();
    static void free_buffers();
    static void open(void *message, u16 speaker);
    static s32 is_id_in_special_range(s16 id);
    static s32 classify_id(s16 id);
    static s32 get_player_battle_flag_state(u16 client);
    static s32 is_state_zero_unless_0x2C8(s32 id);
    void destroy_menu_entry(s32 offset);
    void set_item_pos(s32 i);
    TWindowDD_WS_Word *init_last_child();
    s32 setup_entry(s16 id);
    s32 get_current_child_index();
    TWindowDDStateEntry *get_state_entry(s32 state);
    void init_entry_field_64(s32 index);
    void refresh_sub(TWindowDD_WS_Word *page);
    void apply_input(TWindowDD_WS_Word *page);
    void dim_next_page(TWindowDD_WS_Word *page);
    void update(TWindowDD_WS_Word *child);
    void set_default_coords(TWindowDD_WS_Word *child);
    void init_layout(TWindowDD_WS_Word *child);
    void set_default_positions(TWindowDD_WS_Word *child);
    static void spawn_window();
    static void play_se();
    static void play_sound();
    int test_input_flag_4();
    s32 get_word_select_context();
    void build_item_list();
    // Word-select entry value lookups per language; dispatch_by_window_mode picks one by current_language.
    s32 get_entry_value_french(u32 mode, s32 entry_id, s32 value_index);
    s32 get_entry_value_german(u32 mode, s32 entry_id, s32 value_index);
    s32 get_entry_value_spanish(u32 mode, s32 entry_id, s32 value_index);
    s32 get_entry_value_english(u32 mode, s32 entry_id, s32 value_index);
    s32 get_entry_value_japanese(u32 mode, s32 entry_id, s32 value_index);
    s32 get_mode_code();
    void set_state();
    void close_all_windows();
    static s32 can_append_chars(s32 need, s32 *pos);
    static void format_message(WordSelectMessage *message, char *text, u16 player);
    void append_prompt_newline(s32 *pos);
    static s32 clamp_range_5FA_682(s16 id);
    static s32 clamp_range_2C9_552(s16 id);
    static void show_message_by_count(char *buf, s32 *pos);
    static void maybe_scroll(char *buf, s32 *pos);
    static s32 count_chars_since_newline(const char *buf, s32 *pos);
    static void append_char(s8 c, char *buf, s32 *pos);
    static void append_string(const char *str, char *buf, s32 *pos);
    static s32 get_draw_count(const NJS_TEXLIST *textures);
    static TWindowDDValueList *get_entry(s32 index);
    static void init_ws_data_tables();
    static s32 lookup_item_category(s32 item);
    void handle_confirm_input();
    void update_selection_state();
    static void update_draw(void *p);
    void enter_state_16();
    void apply_entry_layout();
    void update_state();
    s32 update_close_flag();
    void handle_input();
    void run_state();
    void handle_state_3();
    void handle_state_9();
    void handle_state_12();
    void handle_state_13();
    void handle_final_word_state();
    void store_selected_word();
    void store_selected_word_plain();
    void begin_word_select_state();
    void advance_word_select_level();
    void pop_menu_level();
    void open_numeric_parameter_input(s32 minimum, s32 maximum, s32 initial);
    TWindowDD_WS_Word *commit_word_select_level();
    void take_word_select_word(TWindowDD_WS_Word *word_window);
    TWindowDD_WS_Word *get_or_create_word_select_child(s32 offset, s32 id);
    void refresh_word_select_child_list();
    void refresh_word_select_message(WordSelectMessage *message);
    void create_word_select_cursor_label(s32 slot);
    void move_next_label_after_wide_page();
    void update_word_select_child_position(s32 index);
    s32 is_word_select_cancel_input();
    s32 update_numeric_parameter_input();
    void finish_word_select();
};

#include <stddef.h>
LAYOUT_ASSERT(WindowListSize, sizeof(TWindowDDValueList) == 8);
LAYOUT_ASSERT(WindowListCountOffset, offsetof(TWindowDDValueList, count) == 4);

s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
void measure_message_text_width_default(void *entry);
s32 dispatch_by_window_mode(TWindowDD *window, u32 window_mode, s32 entry_id, s32 value_index);
void load_word_select_data(void);

extern char *window_dd_buffer_a;
extern char *window_dd_buffer_b;
// Twelve name strings of 0x18 bytes in window_dd_buffer_b, one per client id.
extern char **TWindowDD__player_name_buffers;
// Six word lists allocated as one block; their ids live in word_select_word_storage.
extern TWindowDDValueList *TWindowDD__word_select_lists;
extern s16 *word_select_word_storage;
// Word strings of the loaded ws_data archive and the string index of each word id.
extern char **ws_word_strings;
extern s16 *ws_word_string_index;
extern s32 window_dd_element_count;
extern s32 twindowdd_entry_count;
extern TWindowDDValueList *TWindowDD__data_805D6E40;
extern TWindowDDValueList *TWindowDD__data_805D6E44;
extern u8 *TWindowDD__data_805D6E48;
// Spanish prefix categories, loaded from the word-select archive header.
extern u8 *lbl_805D6E4C;
// The loaded ws_data_<lang>.bin archives (French goes to TWindowDD::ws_data_buffer).
extern void *ws_data_jp;
extern void *ws_data_us;
extern void *ws_data_es;
extern void *ws_data_de;
extern char *word_page_select_label;
extern s8 word_page_select_label_set;
extern char *word_page_next_label;
extern s8 word_page_next_label_set;
// Word id the last word-select message used; -1 when none (reset_selection).
extern s16 remembered_word_select_id;
// Upper bounds of the numeric word-select entries, indexed by TWindowDD::classify_id.
extern const s32 word_select_numeric_limits[6];
extern const f32 window_dd_row_height;
extern const s32 window_dd_tween_ticks;
extern const f32 window_dd_visible_rows;
extern const f32 window_dd_frame_margin;
extern const f32 word_page_x;
extern const f32 word_page_y;
extern const f32 word_page_width;
extern const f32 word_page_height;
extern const f32 word_page_depth;
extern const f32 window_dd_texel_scale;
extern const f32 window_dd_cap_width;
extern const f32 scroll_bar_tile_width;
extern const f32 scroll_bar_tile_height;
extern const f32 scroll_arrow_up_u;
extern const f32 scroll_arrow_down_u;
extern const f32 scroll_arrow_v;
extern const f32 scroll_arrow_size;
extern const f32 scroll_arrow_texture_height;
extern const f32 word_row_strip_v;
extern const f32 word_row_strip2_v;
extern const f32 mode_texel_scale;
extern const f32 mode_row_texture_height;
extern const f32 window_dd_frame_margin_y;
extern const f32 word_label_hidden_x;
extern const f32 word_label_hidden_right_x;
extern const f32 word_prompt_hidden_y;
extern const f32 wide_word_page_width;
extern const f32 next_word_page_x;
extern const f32 next_word_page_y;
extern const f32 next_word_page_width;
extern const f32 next_word_page_height;
extern const f32 word_page_exit_x;
extern const f32 last_word_page_x;
extern const f32 last_word_page_y;
extern const f32 last_word_page_width;
extern const f32 last_word_page_height;
extern const f32 word_page_label_x;
extern const f32 word_page_label_y;
extern const f32 word_page_label_width;
extern const f32 next_word_page_label_x;
extern const f32 next_word_page_label_y;
extern const f32 next_word_page_label_width;
extern const f32 scroll_bar_width;
extern const f32 scroll_bar_height;
extern const f32 scroll_bar_x;
extern const f32 scroll_bar_y;
extern const f32 scroll_arrow_margin;
extern const f32 word_prompt_x;
extern const f32 word_prompt_y;
extern const f32 word_prompt_width;
extern const f32 cursor_label_x;
extern const f32 cursor_label_y;
extern const f32 cursor_label_width;
extern const f32 cursor_label2_x;
extern const f32 cursor_label2_y;
extern const f32 message_label_x;
extern const f32 message_label_y;
extern const f32 message_label_width;
extern const f32 mode_window_x;
extern const f32 mode_window_y;
extern const f32 mode_window_placement_x;
extern const f32 mode_window_placement_y;
extern const f32 wide_mode_window_x;
extern const f32 wide_next_word_page_x;
extern const u32 window_dd_color_white;
extern const u32 window_dd_color_black;
extern const f32 word_label_depth;
extern const f32 scroll_bar_depth;
extern const f32 word_cursor_depth;
extern const f32 mode_window_depth;

#endif
