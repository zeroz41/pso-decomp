#ifndef PSO_UI_FRONTEND_TADENTERPASSWORDGC_H
#define PSO_UI_FRONTEND_TADENTERPASSWORDGC_H

#include "types.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"

struct TAdEnterPasswordGC : public TAdEnterBaseGC {
    TAdEnterPasswordGC(TObject *parent);
    virtual ~TAdEnterPasswordGC();
    virtual void render();
    virtual void run_task();
    void open_keyboard_window(void *);
    void update_password_input(void *);
    void request_transition(void *);
    void set_multi_chg_game_mode_0x14(void *);
    void close_window_and_destroy(void *);
    u8 pad_38[0x8];
    s32 len; // strlen of the keyboard buffer (update_password_input)
};

typedef char TAdEnterPasswordGC_size[sizeof(TAdEnterPasswordGC) == 0x44 ? 1 : -1];

// --- C functions defined in TAdEnterPasswordGC.cpp ---
extern "C" {
void close_window_and_destroy__18TAdEnterPasswordGCFPv(u8 *arg0);
s32 dispatch_input_to_instance__18TAdEnterPasswordGCFi(s32 arg0);
void open_keyboard_window__18TAdEnterPasswordGCFPv(s32 arg0);
void request_transition__18TAdEnterPasswordGCFPv(void *p);
void set_multi_chg_game_mode_0x14__18TAdEnterPasswordGCFPv(void *p);
void set_password__18TAdEnterPasswordGCFi(s32 arg0);
}
// --- end of C functions

// TAdEnterPasswordGC__input_buffer: layout known from its uses only.
struct TAdEnterPasswordGCInputBuffer { char value; u8 remaining[8]; };
extern TAdEnterPasswordGCInputBuffer TAdEnterPasswordGC__input_buffer;

#endif
