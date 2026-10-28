#include "types.h"
#include "pso/misc/TLobby_80160804.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TLobby.h"

void update_and_send_60__6TLobbyFPv(void* p) { TLobby::bswap_60_header(p); send_subcommand((u8 *)p); }
