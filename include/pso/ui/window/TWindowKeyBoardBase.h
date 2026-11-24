#ifndef PSO_UI_WINDOW_TWINDOWKEYBOARDBASE_H
#define PSO_UI_WINDOW_TWINDOWKEYBOARDBASE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/KeyboardTextBuffer.h"
#include "pso/ui/window/WindowDrawContext.h"

struct TWindowKeyBoardBase : public TWindowBase {
    TWindowKeyBoardBase();
    virtual ~TWindowKeyBoardBase();
    void init_keyboard_text_field(u32, u32);
    void draw_input_text(WindowDrawContext *context);
    void draw_wrapped_text(WindowDrawContext *context, NJS_POINT2 *cursor);
    void draw_text_glyphs(WindowDrawContext *context, NJS_POINT2 *cursor);
    int sub_8025EB68();
    s32 sub_8025CB10();
    void clear_flag60_bit1();
    void set_flag62_bit4();
    u8 get_input_mode();
    void set_input_mode(s32 mode);
    u16 m_60;
    u16 m_62;
    u8 m_input_mode;
    s8 m_65;
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
    void append_text_entry(u8 *arg1);
    void write_name_and_text(char *name, char *text);
    void set_kanji_mode();
    void set_kana_mode();
    void process_input();
    void select_next();
    void update();
    void convert_input_text();
    s32 get_state();
    void update_input_state();
    void sub_8025B928();
    void sub_8025B92C();
    void sub_8025BA28();
    void sub_8025BA44();
    void vt0();
    void vt1();
    void vt2();
    void vt3();
    void vt4();
    void vt5();
    void vt6();
    void vt7();
    void vt8();
    void vt9();
    void vt10();
    void vt11();
    void vt12();
    void vt13();
    void vt14();
    void vt15();
    void vt16();
    void vt17();
    void vt18();
    void vt19();
    void vt20();
    void vt21();
    void handle_backspace();
    void update_input_state2();
    void set_text(char *s);
    void init();
    void commit_composition_text();
    s32 measure_text_overflow();
    int is_key_state_2();
    s32 sub_8025CE00(u8 *text);
    void sub_8025CF50(int count);
    void sub_8025CFA8(s32 *name);
    void sub_8025D1C8(void *arg1);
    s32 sub_8025D378(void *window_sub_status_disp);
    s32 sub_8025D544(s32 *name, s8 *text);
    void sub_8025D664();
    void sub_8025D7FC();
    void sub_8025D8C8();
    void sub_8025DBDC(s32 arg1);
    void draw_composition_background(WindowDrawContext *box, NJS_POINT2 *cursor, u16 *text, u32 count);
    void layout_wrapped_glyphs(WindowDrawContext *box, NJS_POINT2 *cursor, u16 *text, u32 count, s32 scaled);
    void sub_8025C51C(s32 arg1);
    void sub_8025CC48();
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

#endif
