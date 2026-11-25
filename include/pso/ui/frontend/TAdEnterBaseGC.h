#ifndef PSO_UI_FRONTEND_TADENTERBASEGC_H
#define PSO_UI_FRONTEND_TADENTERBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSelectCurGC;
class TKeyBoardControl;
class TWindowBase;
struct TWindowCallBack;

struct TAdEnterBaseGC : public TObject {
    static s32 entry_mode;
    TAdEnterBaseGC(TObject *parent);
    virtual ~TAdEnterBaseGC();
    void sub_8032B460(int);
    void create_parts();
    struct Position { f32 x, y; };
    void fn_8032B318(Position *position);
    TWindowCallBack *create_default_callback();
    virtual void render();
    virtual void run_task();
    s32 m_1c;
    int pending_dispatch_state;  // copied to password_entry_dispatch_state once the close delay ends
    u32 close_delay_ticks;
    int m_28;
    TAdSelectCurGC *select_cursor;
    TWindowBase *prompt_window;
    TWindowCallBack *callback_window;
};

LAYOUT_ASSERT(TAdEnterBaseGC_size, sizeof(TAdEnterBaseGC) == 0x38);

extern "C" {
void fn_8032AC94(void);
// TAdEnterBaseGC::TAdEnterBaseGC(TObject *), called by the constructors that are still written by hand.
void *__ct__14TAdEnterBaseGCFP7TObject(void *self, TObject *parent);
}

// --- C functions defined in TAdEnterBaseGC.cpp ---
extern "C" {
void fn_8032AC94(void);
}
// --- end of C functions

extern u32 serial_access_entered_value_table[4];
extern TKeyBoardControl *password_entry_keyboard_control;

#endif
