#include "types.h"
#include "pso/unk/TLobby.h"

    extern int lobby_download_state_ptr;
void TLobby::destroy_instance() { ((TLobby *)lobby_download_state_ptr)->close_adxf_handle(); lobby_download_state_ptr = 0; }
