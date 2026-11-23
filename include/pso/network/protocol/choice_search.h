#ifndef PSO_NETWORK_PROTOCOL_CHOICE_SEARCH_H
#define PSO_NETWORK_PROTOCOL_CHOICE_SEARCH_H

#include "pso/network/protocol/protocol.h"
#include <stddef.h>
#include "pso/network/TPlyMeetUserExtension.h"

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

// C4: one player the choice search found.
struct ChoiceSearchResult {
    ChoiceSearchResult();

    u32 guildcard_number;
    char name[16];
    char info[32];
    char location[48];
    u8 pad_64[0xC];
    TPlyMeetUserExtension extension;
};

// C4: the choice-search results the server sends.
struct ChoiceSearchResultList {
    ChoiceSearchResultList();

    packet_header header;
    ChoiceSearchResult entries[32];
};

LAYOUT_ASSERT(ChoiceSearchParametersSize, sizeof(ChoiceSearchParameters) == 0x18);
LAYOUT_ASSERT(ChoiceSearchEntriesOffset, offsetof(ChoiceSearchParameters, entries) == 4);
LAYOUT_ASSERT(ChoiceSearchPacketSize, sizeof(ChoiceSearchPacket) == 0x1C);
LAYOUT_ASSERT(ChoiceSearchPayloadOffset, offsetof(ChoiceSearchPacket, parameters) == 4);
LAYOUT_ASSERT(ChoiceSearchResultSize, sizeof(ChoiceSearchResult) == 0xD4);
LAYOUT_ASSERT(ChoiceSearchResultListSize, sizeof(ChoiceSearchResultList) == 0x1A84);

#endif
