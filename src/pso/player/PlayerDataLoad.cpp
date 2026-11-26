#include "types.h"
#include "pso/player/PlayerDataLoad.h"
#include "pso/system/memory.h"
#include "pso/network/TLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"

saddr player_data_load_buffer;
saddr TLobby::get_global_63e0() {  return player_data_load_buffer; }
void TLobby::load_player_data() { init_memcard(0, 0, (u8 *)player_data_load_buffer, 0); }
void free_player_data_load_buffer(void) {
    if ((u32)player_data_load_buffer != 0U) {
        xfree((void *)player_data_load_buffer);
        player_data_load_buffer = 0;
    }
}


void TKeyBoardControl::alloc_buffer() {
    player_data_load_buffer = (saddr)xmalloc(0x14000);
}
