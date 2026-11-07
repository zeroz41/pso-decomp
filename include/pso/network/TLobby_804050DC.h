#ifndef PSO_NETWORK_TLOBBY_804050DC_H
#define PSO_NETWORK_TLOBBY_804050DC_H

#include "types.h"

/* TLobby_804050DC.c: connection records, the DNS resolver tables and socket start-up. */
#ifdef __cplusplus
extern "C" {
#endif
s16 run_connect_step(void);
void flush_flags_step(void);
s16 init_net_tables(void);
s32 clear_all_used_records(void);
s32 close_connection_by_index(s16 i);
#ifdef __cplusplus
}
#endif

#endif
