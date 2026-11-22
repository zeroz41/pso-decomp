#ifndef PSO_NETWORK_TPLYMEETUSEREXTENSION_801DAC6C_H
#define PSO_NETWORK_TPLYMEETUSEREXTENSION_801DAC6C_H

#include "types.h"

class TProtocol;

// --- C functions defined in TPlyMeetUserExtension_801DAC6C.cpp ---
extern "C" {
void handle_cmd_9A__9TProtocolFR6packet(u8 *arg0, s32 *arg1);
s32 socket_set_server_info(TProtocol *protocol, const char *serial_v1, const char *access_key_v1, const char *serial,
                           const char *access_key, const char *host, u16 port);
}
// --- end of C functions

#endif
