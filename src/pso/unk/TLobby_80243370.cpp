#include "types.h"
#include "pso/unk/TLobby_80243370.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"

extern "C" {
int TAdPlayerLoadGC__sub_801E263C(void*, void*, void*, void*);
extern int player_data_load_buffer;
int TLobby::get_global_63e0() {  return player_data_load_buffer; }
void TLobby::load_player_data() { TAdPlayerLoadGC__sub_801E263C((void*)0, (void*)0, (void*)player_data_load_buffer, (void*)0); }
void TLobby__sub_802433A8(void) {
    if ((u32) (*(u32 *)&player_data_load_buffer) != 0U) {
        xfree((void *)(*(u32 *)&player_data_load_buffer));
        (*(u32 *)&player_data_load_buffer) = 0U;
    }
}

}

extern "C" {

s32 xmalloc__FUl(s32);


void TKeyBoardControl::alloc_buffer() {
    player_data_load_buffer = xmalloc__FUl(0x14000);
}

}
