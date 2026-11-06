#ifndef PSO_UI_FRONTEND_TADENTERPPPPASSGC_H
#define PSO_UI_FRONTEND_TADENTERPPPPASSGC_H

#include "types.h"

// --- C functions defined in TAdEnterPPPPassGC.cpp ---
extern "C" {
void *__dt__17TAdEnterPPPPassGCFv(void *arg0, s16 arg1);
void close_windows_and_advance__17TAdEnterPPPPassGCFPv(u8 *arg0);
int forward_chg_game_mode__17TAdEnterPPPPassGCFPv(void *p);
void open_keyboard_window__17TAdEnterPPPPassGCFPv(u8 *ad_enter_serial_access_gc);
void render__17TAdEnterPPPPassGCFv(void *self);
int request_transition__17TAdEnterPPPPassGCFPv(void *p);
void set_password__17TAdEnterPPPPassGCFi(s32 arg0);
void update_password_input__17TAdEnterPPPPassGCFPv(u8 *ad_enter_serial_access_gc);
}
// --- end of C functions

#endif
