#ifndef PSO_PROTOCOL_H
#define PSO_PROTOCOL_H

/* PSO network protocol base types.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 */

#include "pso/forward.h"
#include "types.h"

extern void bswap_16(u16 *val);
extern void bswap_32(u32 *val);

struct packet_header {
    u8 command;
    u8 flags;
    u16 size;
    void bswap();
};

/* Shared wire formats, derived from newserv (MIT; see reference/newserv-LICENSE).
 * - protocol_types.h : shared payload/header structs (vectors, ...)
 * - subcmd_6x.h      : the G_*_6xNN 0x60 game subcommand formats
 * - commands.h       : the main S_/C_/SC_* command formats
 */
#include "pso/protocol/protocol_types.h"
#include "pso/protocol/subcmd_6x.h"
#include "pso/protocol/commands.h"

#endif
