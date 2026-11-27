#ifndef PSO_NETWORK_FLOOREVENTCOMMAND_H
#define PSO_NETWORK_FLOOREVENTCOMMAND_H

#include "pso/network/protocol/protocol_types.h"
#include <stddef.h>

// 6x67: Triggers a set event on a floor. Sent by send_6x67_wave_trigger_event, TObjEvtCollision::run_task,
// the enemy containers' receive_physical_attack and the quest opcodes setevt and start_setevt; received
// by handle_6x67_trigger_set_event, which runs the event on the current floor or flags it on another.
// Size checked: G_FloorEvent_6x67::init sets the header size to 4 words.
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
void handle_6x67_trigger_set_event(game_command_header *command);

#endif
