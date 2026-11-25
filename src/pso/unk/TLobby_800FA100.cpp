#include "pso/system/Adxf.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/unk/text_800FA464.h"

void TLobby::destroy_instance() { ADXF_Close(lobby_download_state_ptr); lobby_download_state_ptr = 0; }
