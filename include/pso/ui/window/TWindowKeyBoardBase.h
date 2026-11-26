#ifndef PSO_UI_WINDOW_TWINDOWKEYBOARDBASE_H
#define PSO_UI_WINDOW_TWINDOWKEYBOARDBASE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/KeyboardTextBuffer.h"
#include "pso/ui/window/WindowDrawContext.h"

struct WindowDescriptor;

struct TWindowKeyBoardBase : public TWindowBase {
    static WindowDescriptor window_descriptor;
    TWindowKeyBoardBase();
    virtual ~TWindowKeyBoardBase();
    void init_keyboard_text_field(u32, u32);
    void draw_input_text(WindowDrawContext *context);
    void draw_wrapped_text(WindowDrawContext *context, NJS_POINT2 *cursor);
    void draw_text_glyphs(WindowDrawContext *context, NJS_POINT2 *cursor);
    int sub_8025EB68();
    s32 has_text();
    void clear_flag60_bit1();
    void set_flag62_bit4();
    u8 get_input_mode();
    void set_input_mode(s32 mode);
    u16 state_flags;
    u16 request_flags;  // set_flag62_bit2 / bit8 mark confirmed / cancelled
    u8 m_input_mode;
    s8 active_input_mode;  // get_input_mode returns it; the chat shortcut handlers set it
    u8 _pad66[0x2];
    KeyboardTextBuffer *active_text;
    KeyboardTextBuffer m_text;
    KeyboardTextBuffer m_text2;
    u8 *candidate_buffer;
    u8 *current_candidate;
    u8 *last_candidate;
    s32 candidate_index;
    s32 candidate_count;
    s32 candidate_bytes_remaining;
    u32 composition_flags;
    virtual void render();
    virtual void run_task();
    void insert_character(u16 code);
    // The four input modes TKeyBoardControl's constructor selects (numbered by its mode argument).
    void set_mode0();
    void set_mode1();
    void set_mode2();
    void set_mode3();
    int is_confirmed();
    void set_flag62_bit2();
    int is_cancelled();
    void set_flag62_bit8();
    static int is_alnum(u16 code);
    void insert_string(char *src);
    void update_input(void* a1);
    void append_text_entry(u8 *text);
    void write_name_and_text(char *name, char *text);
    void set_kanji_mode();
    void set_kana_mode();
    void process_input();
    void select_next();
    void update();
    void convert_input_text();
    s32 get_state();
    void update_input_state();
    void key_none();
    void convert_composition();
    void key_end();
    void key_home();
    void key_enter();
    void key_backspace();
    void key_clear();
    void key_f1();
    void key_f2();
    void key_f3();
    void key_f4();
    void key_f5();
    void key_f6();
    void key_f7();
    void key_f8();
    void key_f9();
    void key_f10();
    void key_f11();
    void key_f12();
    void key_right();
    void key_left();
    void key_up();
    void key_down();
    void key_space();
    void key_delete();
    void key_escape();
    void handle_backspace();
    void update_input_state2();
    void set_text(char *s);
    void init();
    void commit_composition_text();
    s32 measure_text_overflow();
    int is_key_state_2();
    // Symbols, user-defined and half-width katakana characters the IME is not asked to convert.
    s32 has_unconvertible_char(u8 *text);
    void skip_ime_candidates(int count);
    // Adds the first IME conversion of text (requests 0x25, 0x26, 0x28, then 0x27)
    // that differs from it, unless text holds characters the conversions skip.
    void add_conversion_candidate(char *text);
    void remove_candidate(void *record);
    s32 can_fit_candidate(void *window_sub_status_disp);
    s32 candidate_fits(char *name, char *text);
    void select_next_segment();
    void shrink_segment();
    void extend_segment();
    void convert_trailing_romaji(s32 finalize);
    void draw_composition_background(WindowDrawContext *box, NJS_POINT2 *cursor, u16 *text, u32 count);
    void layout_wrapped_glyphs(WindowDrawContext *box, NJS_POINT2 *cursor, u16 *text, u32 count, s32 scaled);
    void insert_party_member_name(s32 slot);
    // Japanese: composition flags from the player's keyboard options; other languages: fixed.
    void load_input_mode_options();
    void update_close_mode();
    void reset_input();
    void flush_if_flagged();
    int get_flag();
    void export_text(char *out);
    int get_flag62_bit8();
};

LAYOUT_ASSERT(TWindowKeyBoardBase_size, sizeof(TWindowKeyBoardBase) == 0xB8);
LAYOUT_ASSERT(TWindowKeyBoardBase_active_text_offset, offsetof(TWindowKeyBoardBase, active_text) == 0x68);
LAYOUT_ASSERT(TWindowKeyBoardBase_candidate_offset, offsetof(TWindowKeyBoardBase, candidate_buffer) == 0x9C);
LAYOUT_ASSERT(TWindowKeyBoardBase_input_mode_offset, offsetof(TWindowKeyBoardBase, m_input_mode) == 0x64);

// Blinking caret drawn after the input text at cursor.
void draw_text_cursor(WindowDrawContext *context, NJS_POINT2 *cursor);

#endif
