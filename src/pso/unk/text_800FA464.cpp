#include "pso/system/memory.h"
#include "pso/render/GvmTextureArchive.h"
#include "pso/system/Adxf.h"
#include "types.h"
#include "pso/system/TGStream.h"
#include "pso/unk/text_800FA464.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_803DE778.h"
AsyncFileReadRequest *async_file_read_current_request;
AsyncFileReadRequest *lobby_stack_entry_list_tail;
s32 lobby_list_entry_count;
s32 async_file_read_state;
u8 *async_file_read_sector_buffer;
AdxfHandle *lobby_download_state_ptr;
s32 lobby_list_next_id;
s32 game_heap;
u8 *async_file_read_texture_buffer;
void process_async_file_reads(void) {
    switch (async_file_read_state) {
    case 0:
        if (async_file_read_current_request != NULL) {
            if (async_file_read_current_request->flags & 0x200) {
                TLobby::pop_and_close();
            } else {
                async_file_read_current_request->flags |= 0x100;
                if (async_file_read_current_request->flags & 2) {
                    async_file_read_texture_buffer = TLobby::tmp_buf_use_req("FSVR_READPVM");
                    if (async_file_read_texture_buffer != NULL) {
                        lobby_download_state_ptr = ADXF_Open(async_file_read_current_request->name, 0);
                        ADXF_ReadNw(lobby_download_state_ptr, async_file_read_current_request->count, async_file_read_texture_buffer);
                        async_file_read_state = 3;
                    }
                } else if (async_file_read_current_request->flags & 4) {
                    async_file_read_state = 4;
                } else {
                    AdxfHandle *h = lobby_download_state_ptr = ADXF_Open(async_file_read_current_request->name, 0);
                    if (h != 0) {
                        if (async_file_read_current_request->count > 1) {
                            ADXF_ReadNw(h, async_file_read_current_request->count - 1, async_file_read_current_request->dst);
                            async_file_read_state = 1;
                        } else {
                            ADXF_ReadNw(h, 1, async_file_read_sector_buffer);
                            async_file_read_state = 2;
                        }
                    }
                }
            }
        }
        break;
    case 1:
        if (async_file_read_current_request->flags & 0x200) {
            TLobby::destroy_instance();
            TLobby::pop_and_close();
            async_file_read_state = 0;
        } else if (ADXF_GetStat(lobby_download_state_ptr) == 3) {
            ADXF_ReadNw(lobby_download_state_ptr, 1, async_file_read_sector_buffer);
            async_file_read_state = 2;
        }
        break;
    case 2:
        if (async_file_read_current_request->flags & 0x200) {
            TLobby::destroy_instance();
            TLobby::pop_and_close();
            async_file_read_state = 0;
        } else if (ADXF_GetStat(lobby_download_state_ptr) == 3) {
            u8 *dst = async_file_read_current_request->dst + ((async_file_read_current_request->count - 1) << 11);
            s32 n = async_file_read_current_request->size % 2048;
            if (n == 0) {
                n = 0x800;
            }
            switch (n & 3) {
            case 0:
                move_words(dst, async_file_read_sector_buffer, n / 4);
                break;
            case 2:
                ((TLobby *)dst)->copy_u16_array((u16 *)async_file_read_sector_buffer, (s32)(n / 2));
                break;
            default:
                move_data(dst, async_file_read_sector_buffer, (u32)n);
                break;
            }
            TLobby::destroy_instance();
            TLobby::notify_and_close();
        }
        break;
    case 3:
        if (async_file_read_current_request->flags & 0x200) {
            TLobby::destroy_instance();
            TLobby::pop_and_close();
            async_file_read_state = 0;
        } else if (ADXF_GetStat(lobby_download_state_ptr) == 3) {
            load_gvm_texture_archive(async_file_read_texture_buffer, async_file_read_current_request->tex);
            TLobby::tmp_buf_release("FSVR_READPVM");
            TLobby::notify_and_close();
        }
        break;
    case 4:
        if (TLobby::load_bml_exec(async_file_read_current_request->mode, async_file_read_current_request->name) != 0) {
            TLobby::pop_and_close();
            async_file_read_state = 0;
        }
        break;
    }
    TGStream__sub_800FDD64();
}
