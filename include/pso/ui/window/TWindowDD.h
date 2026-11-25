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
    TWindowDD(TObject *parent, void *out_message);
    virtual ~TWindowDD();
    virtual void run_task();
    s16 menu_index;                     // Its address is the input context of the button tests.
    u8 pad_1e[0x2];
    s32 depth;                          // Index of the active word page.
    TWindowDD_WS_Word *pages[8];
    s32 state_stack[8];                 // state to return to from each page level
    TWindowDD_WS_String *strings[6];    // [3] shows the message being composed
    TWindowDD_WS_ScrollBar *scroll_bar;
    TWindowWordSelectMode *mode_window;
    TWindowInputNumber *number_window;
    s32 list_ids[3];                    // element lists of pages depth .. depth + 2
    s32 close_flags;
    s32 word_appended;
    s32 last_selected_id;
    s32 enemies_present;
    s32 selection_confirmed;
    s32 status;                         // 1 mode menu, 2 sent, 3 cancelled
    s32 transition;                     // 1 opening the next page, 2 closing this one
    s32 state;
    s32 next_state;
    s32 numeric_input_active;
    s32 extra_string_count;
    WordSelectMessage *result;
    WordSelectMessage message;
    WordSelectMessage saved_message;
    s16 selected_word;
    u8 pad_fe[0x2];
    s32 pad_100;
    s32 pad_104;
    void draw_transformed_primitive(s32 a1, u32 id, s32 a3);
    void reset_entries(f32 z, s32 color);
    void set_quad_corners_scaled(f32 x, f32 y, f32 farg2);
    static s32 apply_both_choices(void *input_context, saddr buttons);
    static s32 check_all_ready(s32 floor);
    void update_com_card();
    void enter_state_19();
    void enter_state_18();
    void enter_state_9();
    void update_dispatch();
    void update_layout();
    void update_transition();
    void update();
    static saddr get_element_ptr(s32 index);
    virtual void render();
    void reset_selection();
    void update_selected_id();
    static void build_player_word_lists();
    static void free_buffers();
    static void open(void *message, u16 speaker);
    static u8 is_id_in_special_range(s16 id);
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
    static void refresh_sub(void* p, void* a1);
    static void apply_input(void* p, void* a1);
    static void update(void* p, void* child);
    void update(TWindowDD_WS_Word *child);
    static void set_default_coords(void *window, TWindowDD_WS_Word *child);
    static void init_layout(void *window, TWindowDD_WS_Word *child);
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
    static s32 can_append_chars(s32 len, s32 *pos);
    static void format_message(WordSelectMessage *message, char *text, u16 player);
    void append_prompt_newline(s32 *pos);
    static s32 clamp_range_5FA_682(s16 id);
    static s32 clamp_range_2C9_552(s16 id);
    static void show_message_by_count(char *buf, s32 *pos);
    static void maybe_scroll(char *buf, s32 *pos);
    static s32 count_chars_since_newline(const char *buf, s32 *pos);
    static void append_char(s8 c, char *buf, s32 *pos);
    static void append_string(const char *str, char *buf, s32 *pos);
    void copy_point_table(s32 idx);
    static s32 get_draw_count(const NJS_TEXLIST *textures);
    static saddr get_entry(s32 index);
    int handle_word_select();
    static void send_chat_packet(void *data);
    void update_and_send_lobby();
    void init_header();
    void bswap_word_select();
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
};

#include <stddef.h>
LAYOUT_ASSERT(WindowListSize, sizeof(TWindowDDValueList) == 8);
LAYOUT_ASSERT(WindowListCountOffset, offsetof(TWindowDDValueList, count) == 4);

s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
void measure_message_text_width_default(void *entry);
s32 dispatch_by_window_mode(TWindowDD *window, u32 window_mode, s32 entry_id, s32 value_index);
extern "C" {
void TWindowDD__sub_80344114(void);
}

// Upper bounds of the numeric word-select entries, indexed by TWindowDD::classify_id.
extern const s32 word_select_numeric_limits[6];

#endif
