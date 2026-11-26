#ifndef PSO_NETWORK_PROTOCOL_CHOICE_SEARCH_H
#define PSO_NETWORK_PROTOCOL_CHOICE_SEARCH_H

#include "pso/network/protocol/protocol.h"
#include "pso/network/protocol/packet_classes.h"
#include <stddef.h>
#include "pso/network/TPlyMeetUserExtension.h"
#include "types.h"

// C2 and C3: the player's choice search settings. TProtocol::send_choice_search_parameters sends C2,
// TProtocol::send_choice_search sends C3.
struct ChoiceSearchPacket {
    packet_header header;
    TPlyChoiceSearchConfig parameters;

    void bswap();
};

TPlyChoiceSearchConfig *copy_choice_search_parameters(TPlyChoiceSearchConfig *dst, const TPlyChoiceSearchConfig *src);

// C0: one choice the server offers; a parent_choice_id of 0 marks a category.
struct ChoiceSearchOption {
    TPlyChoiceSearchConfig::Entry choice;
    char text[0x1C];

    void bswap();
};

// C0: the choice search options the server offers, the answer to
// TProtocol::send_choice_search_options_request; header.flags is the entry count.
// TProtocol::handle_cmd_C0 passes them to TLobby::handle_choice_search_options.
struct TRecvChoiceSearchOptions {
    packet_header header;
    ChoiceSearchOption entries[56];

    void bswap();
};

// C4: the command that reconnects to the server a found player is on.
struct ChoiceSearchReconnect {
    packet_header header;
    u32 address;
    u16 port;
    u16 unused;

    void bswap();
};

// C4: one player the choice search found.
struct ChoiceSearchResult {
    ChoiceSearchResult();

    u32 guildcard_number;
    char name[16];
    char info[32];
    char location[48];
    ChoiceSearchReconnect reconnect;
    TPlyMeetUserExtension extension;

    void bswap();
};

// C4: the players the choice search found. TProtocol::handle_cmd_C4 passes them to
// TLobby::handle_choice_search_results.
struct ChoiceSearchResultList {
    ChoiceSearchResultList();

    packet_header header;
    ChoiceSearchResult entries[32];

    void bswap();
};

ChoiceSearchResultList *copy_choice_search_result_list(ChoiceSearchResultList *dst, ChoiceSearchResultList *src);
ChoiceSearchResult *copy_choice_search_result(ChoiceSearchResult *dst, ChoiceSearchResult *src);

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
LAYOUT_ASSERT(ChoiceSearchReconnectOffset, offsetof(ChoiceSearchResult, reconnect) == 0x64);
LAYOUT_ASSERT(ChoiceSearchResultSize, sizeof(ChoiceSearchResult) == 0xD4);
LAYOUT_ASSERT(ChoiceSearchResultListSize, sizeof(ChoiceSearchResultList) == 0x1A84);

struct ChoiceSearchSelection;
struct TPlyChoiceSearchConfig;

extern "C" {
u8 *copy_struct28__17TWindowSubComCardFii(saddr dest, saddr src);
int quest_hack_check_b_stub(void);
int quest_hack_check_a_stub(void);
}

// The option picked in the category `parent_choice_id` of the five selections, or 0.
s32 find_choice_search_value(ChoiceSearchSelection *selections, u16 parent_choice_id);

// Copies the saved choice search selections into the search request.
void copy_choice_search_selections(ChoiceSearchSelection *selections, TPlyChoiceSearchConfig *config);

void clear_choice_search_selections(ChoiceSearchSelection *arr);

#endif
