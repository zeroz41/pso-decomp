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
    static void set_password(const char *password);
    s32 input_valid;
    s32 prev_input_valid;
    s32 len; // strlen of the keyboard buffer (update_password_input)
};

LAYOUT_ASSERT(TAdEnterPasswordGC_size, sizeof(TAdEnterPasswordGC) == 0x44);


// TAdEnterPasswordGC__input_buffer: layout known from its uses only.
struct TAdEnterPasswordGCInputBuffer { char value; u8 remaining[8]; };
extern TAdEnterPasswordGCInputBuffer TAdEnterPasswordGC__input_buffer;

#endif
