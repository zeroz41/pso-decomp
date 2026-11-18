#ifndef PSO_UI_FRONTEND_TADENTERPPPPASSGC_H
#define PSO_UI_FRONTEND_TADENTERPPPPASSGC_H

#include "types.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"

struct TAdEnterPPPPassGC : public TAdEnterBaseGC {
    TAdEnterPPPPassGC(TObject *parent);
    virtual ~TAdEnterPPPPassGC();
    virtual void render();
    virtual void run_task();
    void open_keyboard_window(void *);
    void update_password_input(void *);
    void request_transition(void *);
    void forward_chg_game_mode(void *);
    void close_windows_and_advance(void *);
    u8 unk_38[0x8];
    s32 m_40;
};

typedef char TAdEnterPPPPassGC_size[sizeof(TAdEnterPPPPassGC) == 0x44 ? 1 : -1];

// --- C functions defined in TAdEnterPPPPassGC.cpp ---
extern "C" {
void close_windows_and_advance__17TAdEnterPPPPassGCFPv(u8 *arg0);
int forward_chg_game_mode__17TAdEnterPPPPassGCFPv(void *p);
void open_keyboard_window__17TAdEnterPPPPassGCFPv(u8 *ad_enter_serial_access_gc);
int request_transition__17TAdEnterPPPPassGCFPv(void *p);
void set_password__17TAdEnterPPPPassGCFi(s32 arg0);
void update_password_input__17TAdEnterPPPPassGCFPv(u8 *ad_enter_serial_access_gc);
}
// --- end of C functions

#endif
