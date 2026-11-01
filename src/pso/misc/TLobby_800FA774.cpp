#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"

extern "C" {

s32 __ct__5THeapFUli(s32, s32, s32);
s32 __nw__5THeapFUl(s32);

extern s32 async_file_read_current_request;
extern s32 lobby_stack_entry_list_tail;
extern s32 lobby_list_entry_count;
extern s32 async_file_read_state;
extern s32 async_file_read_sector_buffer;
extern s32 lobby_download_state_ptr;
extern s32 lobby_list_next_id;
extern s32 game_heap;

void TLobby::init_download_state() {
    s32 var_r0;

    TLobby::init_download_buffers();
    async_file_read_sector_buffer = (s32)TQuestVmDownLoadServer::alloc(0x800);
    lobby_stack_entry_list_tail = 0;
    async_file_read_current_request = 0;
    lobby_download_state_ptr = 0;
    async_file_read_state = 0;
    lobby_list_entry_count = 0;
    lobby_list_next_id = 0;
    var_r0 = __nw__5THeapFUl(0x14);
    if (var_r0 != 0) {
        var_r0 = __ct__5THeapFUli(var_r0, 0x4000, 0x20);
    }
    game_heap = var_r0;
}

}
