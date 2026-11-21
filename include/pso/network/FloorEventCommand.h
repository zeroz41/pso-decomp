#ifndef PSO_NETWORK_FLOOREVENTCOMMAND_H
#define PSO_NETWORK_FLOOREVENTCOMMAND_H

#include "pso/network/protocol/protocol_types.h"
#include <stddef.h>

struct G_FloorEvent_6x67 {
    G_ClientIDHeader header;  // client_id is the event source entity or 0/0xFFFF.
    s32 floor;
    s32 event_id;
    s32 sender_client_id;

    void init();
    void bswap();
    void send();
};

LAYOUT_ASSERT(FloorEventCommandSize, sizeof(G_FloorEvent_6x67) == 0x10);
LAYOUT_ASSERT(FloorEventSenderOffset, offsetof(G_FloorEvent_6x67, sender_client_id) == 0xC);

struct game_command_header;
extern "C" void handle_6x67_trigger_set_event(game_command_header *command);

#endif
