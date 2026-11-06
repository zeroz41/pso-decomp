#ifndef PSO_NETWORK_TPLYMEETUSEREXTENSION_801DAC6C_H
#define PSO_NETWORK_TPLYMEETUSEREXTENSION_801DAC6C_H

#include "types.h"

extern "C" {
void handle_cmd_9A__9TProtocolFR6packet(u8 *arg0, s32 *arg1);
s32 socket_set_server_info(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
}

// --- C functions defined in TPlyMeetUserExtension_801DAC6C.cpp ---
extern "C" {
void handle_cmd_9A__9TProtocolFR6packet(u8 *arg0, s32 *arg1);
s32 socket_set_server_info(u8 *socket, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
}
// --- end of C functions

#endif
