#ifndef PSO_UI_WINDOW_TWINDOWDD_H
#define PSO_UI_WINDOW_TWINDOWDD_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/system/NinjaTypes.h"

s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
s32 is_verb_word(s32 value);

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
    static void * ws_data_fr;
    static TWindowDDValueList * ws_data_table;
    static TWindowDDValueList * ws_data_base;
    static char *work_buffer;
    static s32 window_mode;
    // Twelve name strings of 0x18 bytes in window_dd_buffer_b, one per client id.
    static char **player_name_buffers;
    // Six word lists allocated as one block; their ids live in word_select_word_storage.
    static TWindowDDValueList *word_select_lists;
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
    void reset_selection(WordSelectMessage *message);
    static void copy_chat_entry(WordSelectMessage *dst, WordSelectMessage *src);
    static void build_player_word_lists();
    static void free_buffers();
    static void open(WordSelectMessage *message, u16 speaker);
    static s32 is_levelled_technique_word(s16 id);
    static s32 is_rememberable_word(s16 id);
    static s32 is_weapon_word(s16 id);
    static s32 is_topic_word(s16 id);
    s32 get_initial_word_select_list();
    s32 has_menu_selection();
    static s16 read_indexed_value(s32 entry_index, s32 value_index);
    static s16 read_resolved_value(s32 entry_id, s32 value_index);
    static void append_word_select_entry_words(WordSelectMessage *entry, char *buf, s32 *pos);
    static void append_word_select_word(WordSelectMessage *entry, s16 id, char *buf, s32 *pos);
    static void append_word_select_word_with_number(WordSelectMessage *entry, s16 id, char *word, char *buf, s32 *pos);
    static void append_word_select_token(s16 id, char *buf, s32 *pos);
    static void convert_type3_message(WordSelectMessage *src, WordSelectMessage *dst);
    static void append_word_inside_phrase(WordSelectMessage *src, s16 id, char *verb, char *phrase, char *buf, s32 *pos);
    static s32 classify_id(s16 id);
    static s32 get_player_battle_flag_state(u16 client);
    static s32 is_non_topic_word(s32 id);
    void destroy_menu_entry(s32 offset);
    void set_item_pos(s32 i);
    TWindowDD_WS_Word *init_last_child();
    s32 setup_entry(s16 id);
    s32 get_current_child_index();
    TWindowDDStateEntry *get_state_entry(s32 state);
    void move_label_to_start(s32 index);
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
    static s32 format_french_message(WordSelectMessage *words, char *text, u16 player);
    static s32 format_german_message(WordSelectMessage *words, char *text, u16 player);
    static s32 format_spanish_message(WordSelectMessage *words, char *text, u16 player);
    static s32 format_english_message(WordSelectMessage *words, char *text, u16 player);
    static s32 format_entry_text(WordSelectMessage *words, char *text);
    static void append_prompt_newline(char *buf, s32 *pos);
    static s32 clamp_range_5FA_682(s16 id);
    static s32 clamp_range_2C9_552(s16 id);
    static void show_message_by_count(char *buf, s32 *pos);
    static void maybe_scroll(char *buf, s32 *pos);
    static s32 count_chars_since_newline(const char *buf, s32 *pos);
    static void append_char(s8 c, char *buf, s32 *pos);
    static void append_string(const char *str, char *buf, s32 *pos);
    static s32 get_draw_count(const NJS_TEXLIST *textures);
    static TWindowDDValueList *get_entry(s32 index);
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
void ws_data_load(void);

extern char *window_dd_buffer_a;
extern char *window_dd_buffer_b;
// Header of a word select data file (ws_data_<language>.bin, loaded by ws_data_load).
// The Japanese file has only the first four tables; the US file stores the
// form index before the form lists, the European files after them.
struct WordSelectDataUS {
    char **word_strings;
    TWindowDDValueList *base;
    TWindowDDValueList *table;
    s16 *word_string_index;
    TWindowDDValueList *word_variant_lists;
    u8 *word_form_index;
    TWindowDDValueList *word_form_lists;
};

struct WordSelectDataEU {
    char **word_strings;
    TWindowDDValueList *base;
    TWindowDDValueList *table;
    s16 *word_string_index;
    TWindowDDValueList *word_variant_lists;
    TWindowDDValueList *word_form_lists;
    u8 *word_form_index;
    u8 pad_1C[4];
    u8 *spanish_prefix_categories;
};

extern s16 *word_select_word_storage;
// Word strings of the loaded ws_data archive and the string index of each word id.
extern char **ws_word_strings;
extern s16 *ws_word_string_index;
extern s32 window_dd_element_count;
extern s32 twindowdd_entry_count;
// Archive words 4-6 (not in Japanese): two variant lists for word ids 0x5AC-0x5F9, three inflected-form
// lists for word ids 0x5FA-0x682 plus a list of words used without a lead-in, and the form (0-3) each
// word id 0x2C9-0x552 selects. Names inferred from the formatters.
extern TWindowDDValueList *ws_word_variant_lists;
extern TWindowDDValueList *ws_word_form_lists;
extern u8 *ws_word_form_index;
// Spanish prefix categories, loaded from the word-select archive header.
extern u8 *ws_spanish_prefix_categories;
// The loaded ws_data_<lang>.bin archives (French goes to TWindowDD::ws_data_fr).
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

struct WindowDrawContext;
struct WindowVertex;

// Texture coordinates of the word-select quad sets, filled from window_dd_quad_positions.
extern NJS_POINT2 word_select_quad_points[7][8];
extern const NJS_POINT2 window_dd_quad_positions[7];
extern const f32 window_dd_quad_scales[8];
void set_frame_row_vertices_y(WindowDrawContext *context, WindowVertex *vertices, s32 row);
void set_frame_column_vertices_x(WindowDrawContext *context, WindowVertex *vertices);
f32 word_select_inverse_depth(f32 depth, f32 offset);
saddr get_word_select_token_text(s16 id);
void handle_6x74_word_select(u8 *window_dd);

// Recent word-select ids (push_recent_id) and the two ws data tables init_ws_data_tables checked.
struct WsRecentState {
    s16 ids[16];
    TWindowDDValueList *a;
    TWindowDDValueList *b;
    s16 *a0;
    s16 *b0;
    s32 n;
};

extern WsRecentState ws_recent_state;

// Entry counts of lookup_item_category's id lists (.sdata2, after the lists).
extern const s32 category0_id_count;
extern const s32 category2_id_count;
extern const s32 category3_id_count;
extern const s32 category4_id_count;

s32 get_word_select_type_state(s32 state, s32 item);
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

void init_ws_data_tables();

s32 lookup_item_category(s32 item);

#endif
