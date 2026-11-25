#ifndef PSO_NETWORK_PROTOCOL_SEND_GUILD_CARD_PACKET_H
#define PSO_NETWORK_PROTOCOL_SEND_GUILD_CARD_PACKET_H

#include <stddef.h>
#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/player/GuildCardEntry.h"

// 6x06: one player's guild card, sent to another client (handle_6x06_send_guild_card stores it).
struct G_SendGuildCard_6x06 {
    G_ClientIDHeader header;
    GuildCardEntry card;

    // Fills in the subcommand and size, in words.
    G_SendGuildCard_6x06();
    void bswap();
    void send_to(u32 client);
};
LAYOUT_ASSERT(SendGuildCardPacketSize, sizeof(G_SendGuildCard_6x06) == 0x94);

void handle_6x06_send_guild_card(G_SendGuildCard_6x06 *cmd);

#endif
