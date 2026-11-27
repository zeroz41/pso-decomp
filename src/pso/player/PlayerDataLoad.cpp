#include "types.h"
#include "pso/player/PlayerDataLoad.h"
#include "pso/system/memory.h"
#include "pso/network/TLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/frontend/TAdPlayerLoadGCMemCard.h"

u8 *player_data_load_buffer;
u8 *get_player_data_load_buffer() {  return player_data_load_buffer; }
void load_player_data() { init_memcard(0, 0, player_data_load_buffer, 0); }
void free_player_data_load_buffer(void) {
    if (player_data_load_buffer != NULL) {
        xfree(player_data_load_buffer);
        player_data_load_buffer = NULL;
    }
}


void TKeyBoardControl::alloc_buffer() {
    player_data_load_buffer = (u8 *)xmalloc(0x14000);
}
