#ifndef PSO_NETWORK_PROTOCOL_PROTOCOL_H
#define PSO_NETWORK_PROTOCOL_PROTOCOL_H

/* PSO network protocol base types.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 */

#include "pso/forward.h"
#include "types.h"
#include "pso/system/byteswap.h"

// The header of every lobby server command: the command, a flags byte whose meaning depends on the
// command, and the size in bytes with the header.
struct packet_header {
    u8 command;
    u8 flags;
    u16 size;
    void bswap();
};

/* - protocol_types.h : the headers and records the game subcommands share
 * - subcmd_6x.h      : the game subcommands (G_*_6xNN) that 60, 62, 6C and 6D carry
 * - commands.h       : the lobby server commands and the types that carry them
 */
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/commands.h"

#endif
