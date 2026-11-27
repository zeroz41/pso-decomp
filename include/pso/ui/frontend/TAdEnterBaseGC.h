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

void entry_window_render_stub(void);

extern u32 serial_access_entered_value_table[4];
extern s32 password_entry_dispatch_state;
extern TAdEnterBaseGC::Position password_screen_status_line_position[];
extern TKeyBoardControl *password_entry_keyboard_control;


void clear_state(void);

s32 is_pso_pass_save_accepted(void);

void draw_masked_password_field(saddr context);
void draw_entry_field_box(void);
void render_entry_window(void *window, void *context);

struct LengthLimits { u32 n[4]; };

struct KeyboardModes { u8 b[4]; };

TWindowBase *show_message_window(void *owner, s32 message_index);

#endif
