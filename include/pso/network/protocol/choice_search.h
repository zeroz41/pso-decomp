#ifndef PSO_NETWORK_PROTOCOL_CHOICE_SEARCH_H
#define PSO_NETWORK_PROTOCOL_CHOICE_SEARCH_H

#include "pso/network/protocol/protocol.h"
#include <stddef.h>

// Layout follows newserv ChoiceSearch.hh (MIT; reference/newserv-LICENSE).
// The client copies six words at 0x801DF774 and swaps them at 0x801DF6F0.
struct ChoiceSearchParameters {
    u32 disabled;
    struct Entry {
        u16 parent_choice_id;
        u16 choice_id;
    } entries[5];
};

struct ChoiceSearchPacket {
    packet_header header;
    ChoiceSearchParameters parameters;
};

LAYOUT_ASSERT(ChoiceSearchParametersSize, sizeof(ChoiceSearchParameters) == 0x18);
LAYOUT_ASSERT(ChoiceSearchEntriesOffset, offsetof(ChoiceSearchParameters, entries) == 4);
LAYOUT_ASSERT(ChoiceSearchPacketSize, sizeof(ChoiceSearchPacket) == 0x1C);
LAYOUT_ASSERT(ChoiceSearchPayloadOffset, offsetof(ChoiceSearchPacket, parameters) == 4);

#endif
