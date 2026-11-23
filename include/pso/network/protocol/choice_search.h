#ifndef PSO_NETWORK_PROTOCOL_CHOICE_SEARCH_H
#define PSO_NETWORK_PROTOCOL_CHOICE_SEARCH_H

#include "pso/network/protocol/protocol.h"
#include "pso/network/protocol/packet_classes.h"
#include <stddef.h>
#include "pso/network/TPlyMeetUserExtension.h"

// C2/C3: the player's choice search settings.
struct ChoiceSearchPacket {
    packet_header header;
    TPlyChoiceSearchConfig parameters;

    void bswap();
};

extern "C" TPlyChoiceSearchConfig *copy_choice_search_parameters(TPlyChoiceSearchConfig *dst, const TPlyChoiceSearchConfig *src);

// C0: one choice the server offers; parent_choice_id 0 marks a category.
struct ChoiceSearchOption {
    u16 parent_choice_id;
    u16 choice_id;
    char text[0x1C];
};

// C0: the choice search options the server offers; header.flags is the entry count.
struct TRecvChoiceSearchOptions {
    packet_header header;
    ChoiceSearchOption entries[56];
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

// The last C0 options and C4 results the server sent (allocated on first receipt).
extern TRecvChoiceSearchOptions *choice_search_options;
extern ChoiceSearchResultList *choice_search_results;

void store_choice_search_options(TRecvChoiceSearchOptions *options);
void store_choice_search_results(ChoiceSearchResultList *results);
// Scene setup / teardown of the two buffers.
void reset_choice_search_data();
void free_choice_search_data();

LAYOUT_ASSERT(ChoiceSearchOptionsSize, sizeof(TRecvChoiceSearchOptions) == 0x704);
LAYOUT_ASSERT(ChoiceSearchConfigSize, sizeof(TPlyChoiceSearchConfig) == 0x18);
LAYOUT_ASSERT(ChoiceSearchEntriesOffset, offsetof(TPlyChoiceSearchConfig, entries) == 4);
LAYOUT_ASSERT(ChoiceSearchPacketSize, sizeof(ChoiceSearchPacket) == 0x1C);
LAYOUT_ASSERT(ChoiceSearchPayloadOffset, offsetof(ChoiceSearchPacket, parameters) == 4);
LAYOUT_ASSERT(ChoiceSearchResultSize, sizeof(ChoiceSearchResult) == 0xD4);
LAYOUT_ASSERT(ChoiceSearchResultListSize, sizeof(ChoiceSearchResultList) == 0x1A84);

#endif
