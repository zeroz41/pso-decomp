#ifndef PSO_UI_WINDOW_TWINDOWDD_H
#define PSO_UI_WINDOW_TWINDOWDD_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WordSelectMessage.h"

s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
s32 TWindowDD_is_id_in_range_5AC_5F9(s32 value);

class TWindowDD_WS_Word;
class TWindowDD_WS_ScrollBar;
class TWindowWordSelectMode;
struct NJS_TEXLIST;

struct TWindowDDValueList {
    s16 *values;
    s32 count;
};

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
    s16 menu_index;
    u8 _pad1E[0x2];
    s32 depth;  // levels opened so far; each has a word window
    u32 word_windows[8];  // the TWindowDD_WS_Word of each level
    u32 level_states[8];  // the state a level was in when the next level was opened
    u32 labels[6];  // TWindowDD_WS_String windows: SELECT, NEXT, the entry text, the message text and two cursor labels
    TWindowDD_WS_ScrollBar *scroll_bar;  // shows where the visible rows sit in the word list
    TWindowWordSelectMode *mode_window;  // the three-row mode indicator
    uaddr number_window;  // the TWindowInputNumber of a numeric entry
    s32 m_88;
    s32 m_8c;
    s32 m_90;
    u32 result_flags;
    s32 token_pushed;  // 1 once a word of the message has been taken from the list
    s32 last_selected_id;
    u32 enemies_active;
    u32 m_a4;
    s32 dialog_state;  // 0 choosing, 1 the confirm rows (mode_window) are active, 2 idle
    s32 pending_transition;  // 0 none, 1 open the next level, 2 close this one
    s32 state;  // run_state's switch
    s32 next_state;
    s32 dialog_locked;
    s32 extra_window_count;
    WordSelectMessage *output;  // the caller's message, written when the player accepts
    WordSelectMessage message;  // the message being composed
    WordSelectMessage final_message;  // copied to output when the player accepts
    s16 selected_word;
    u8 _padFE[0x2];
    u32 m_100;
    u32 m_104;
    static s32 apply_both_choices(s32 unused, saddr buttons);
    static void *create();
    static s32 check_all_ready(s32 floor);
    void update_com_card();
    void set_pos_and_data(f32 farg0);
    void enter_state_19();
    void enter_state_18();
    void enter_state_9();
    void update_dispatch();
    void update_layout();
    void update_transition();
    void update();
    static saddr get_element_ptr(s32 list_id);
    virtual void render();
    void reset_selection();
    static void build_player_word_lists();
    static void free_buffers();
    static void open(void *message, u16 speaker);
    static u8 is_id_in_special_range(s16 id);
    static s32 classify_id(s16 id);
    static s32 get_player_battle_flag_state(u16 client);
    static s32 is_state_zero_unless_0x2C8(s32 id);
    void destroy_menu_entry(s32 offset);
    void set_item_pos(s32 i);
    u8 *init_last_child();
    s32 setup_entry(s16 id);
    s32 get_current_child_index();
    static void *get_entry(void *window, int index);
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
    static saddr get_entry(s32 index);
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

s32 TWindowDD_check_input_mask(void *input_context, s32 mask);
void measure_message_text_width_default(void *entry);
s32 dispatch_by_window_mode(TWindowDD *window, u32 window_mode, s32 entry_id, s32 value_index);
extern "C" {
void TWindowDD__sub_80344114(void);
}

// Upper bounds of the numeric word-select entries, indexed by TWindowDD::classify_id.
extern const s32 word_select_numeric_limits[6];

#endif
