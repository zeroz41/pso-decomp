#ifndef PSO_UI_FRONTEND_TADENTERPASSWORDGC_H
#define PSO_UI_FRONTEND_TADENTERPASSWORDGC_H

#include "types.h"

// --- C functions defined in TAdEnterPasswordGC.cpp ---
extern "C" {
u8 *TAdEnterPasswordGC__ct(u8 *parent);
void TAdEnterPasswordGC__sub_8032BC94(u8 *arg0, s32 arg1);
void *__dt__18TAdEnterPasswordGCFv(void *arg0, s16 arg1);
void close_window_and_destroy__18TAdEnterPasswordGCFPv(u8 *arg0);
s32 dispatch_input_to_instance__18TAdEnterPasswordGCFi(s32 arg0);
void open_keyboard_window__18TAdEnterPasswordGCFPv(s32 arg0);
void render__18TAdEnterPasswordGCFv(void *self);
int request_transition__18TAdEnterPasswordGCFPv(void *p);
int set_multi_chg_game_mode_0x14__18TAdEnterPasswordGCFPv(void *p);
void set_password__18TAdEnterPasswordGCFi(s32 arg0);
}
// --- end of C functions

#endif
