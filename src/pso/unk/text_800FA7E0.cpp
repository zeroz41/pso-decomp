#include "types.h"
#include "pso/unk/TLobby.h"

extern s32 async_file_read_current_request;
extern u32 lobby_stack_entry_list_tail;
extern s32 lobby_list_entry_count;

u8 *TLobby::pop_stack_entry(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    if (arg0 != NULL) {
        if ((u32) lobby_stack_entry_list_tail == (u32)arg0) {
            lobby_stack_entry_list_tail = 0U;
        }
        async_file_read_current_request = *(s32 *)((s8 *)arg0 + 0x38);
        lobby_list_entry_count -= 1;
        if (arg1 > 0) {
            TLobby::free_static_buffer(arg0);
        }
    }
    return arg0;
}
