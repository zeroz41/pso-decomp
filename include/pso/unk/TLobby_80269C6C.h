#ifndef PSO_UNK_TLOBBY_80269C6C_H
#define PSO_UNK_TLOBBY_80269C6C_H

#include "types.h"

struct WindowDescriptor;

extern "C" {
void set_message_window_default_flags(void);
void set_message_window_flags(s32 arg0);
WindowDescriptor *get_message_window_settings(void);
}

// --- C functions defined in TLobby_80269C6C.cpp ---
extern "C" {
void set_message_window_default_flags(void);
void set_message_window_flags(s32 arg0);
WindowDescriptor *get_message_window_settings(void);
}
// --- end of C functions

#endif
