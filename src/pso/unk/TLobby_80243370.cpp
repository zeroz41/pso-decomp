#include "types.h"
#include "pso/unk/TLobby_80243370.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"

extern "C" {
int init_memcard(void*, void*, void*, void*);
saddr player_data_load_buffer;
saddr TLobby::get_global_63e0() {  return player_data_load_buffer; }
void TLobby::load_player_data() { init_memcard((void*)0, (void*)0, (void*)player_data_load_buffer, (void*)0); }
void TLobby__sub_802433A8(void) {
    if ((u32)player_data_load_buffer != 0U) {
        xfree((void *)player_data_load_buffer);
        player_data_load_buffer = 0;
    }
}


void TKeyBoardControl::alloc_buffer() {
    player_data_load_buffer = (saddr)xmalloc(0x14000);
}

}
