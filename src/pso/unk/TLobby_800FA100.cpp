#include "pso/system/Adxf.h"
#include "types.h"
#include "pso/unk/TLobby.h"

    extern AdxfHandle *lobby_download_state_ptr;
void TLobby::destroy_instance() { ADXF_Close(lobby_download_state_ptr); lobby_download_state_ptr = 0; }
