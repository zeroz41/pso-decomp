#include "pso/unk/text_800FA464.h"
#include "pso/system/Adxf.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/THeap.h"

void TLobby::init_download_state() {
    TLobby::init_download_buffers();
    async_file_read_sector_buffer = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(0x800));
    lobby_stack_entry_list_tail = NULL;
    async_file_read_current_request = NULL;
    lobby_download_state_ptr = 0;
    async_file_read_state = 0;
    lobby_list_entry_count = 0;
    lobby_list_next_id = 0;
    game_heap = new THeap(0x4000, 0x20);
}

