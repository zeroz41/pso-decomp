#ifndef PSO_UI_FRONTEND_TADENTERBASEGC_H
#define PSO_UI_FRONTEND_TADENTERBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSelectCurGC;
class TKeyBoardControl;
class TWindowBase;
struct TWindowCallBack;

struct TAdEnterBaseGC : public TObject {
    static const char *class_name;
    static s32 entry_mode;
    TAdEnterBaseGC(TObject *parent);
    virtual ~TAdEnterBaseGC();
    void reset(int);
    void create_parts();
    struct Position { f32 x, y; };
    void get_title_position(Position *position);
    TWindowCallBack *create_default_callback();
    virtual void render();
    virtual void run_task();
    s32 prev_state;
    int pending_dispatch_state;  // copied to password_entry_dispatch_state once the close delay ends
    u32 close_delay_ticks;
    int m_28;
    TAdSelectCurGC *select_cursor;
    TWindowBase *prompt_window;
    TWindowCallBack *callback_window;
    s32 input_valid;
    s32 prev_input_valid;
};

LAYOUT_ASSERT(TAdEnterBaseGC_size, sizeof(TAdEnterBaseGC) == 0x40);

extern "C" {
void fn_8032AC94(void);
// TAdEnterBaseGC::TAdEnterBaseGC(TObject *), called by the constructors that are still written by hand.
}

extern u32 serial_access_entered_value_table[4];
extern s32 password_entry_dispatch_state;
extern TAdEnterBaseGC::Position password_screen_status_line_position[];
extern TKeyBoardControl *password_entry_keyboard_control;


void clear_state(void);
extern "C" {
u8 *get_serial_text__22TAdEnterSerialAccessGCFii(s32 owner, s32 field);
s32 has_serial_input__22TAdEnterSerialAccessGCFv(s32 parent, s32 field);
int validate_input__22TAdEnterSerialAccessGCFPviPv(void *window, s32 mode, const char *text);
}

extern "C" {
s32 is_pso_pass_save_accepted(void);
}

void draw_masked_password_field(saddr context);
extern "C" {
void draw_entry_field_box(void);
}
void render_entry_window(void *window, void *context);

#endif
