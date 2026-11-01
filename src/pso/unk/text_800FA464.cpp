#include "types.h"
#include "pso/system/TGStream.h"
#include "pso/unk/text_800FA464.h"
#include "pso/misc/TLobby.h"
struct AsyncFileReadRequest {
    u32 flags;
    u8 pad04[4];
    u8 name[0x20];
    u8 *dst;
    s32 size;
    s32 count;
    u8 pad34[8];
    s32 tex;
    u8 pad40[0x24];
    s32 mode;
};

extern "C" {
s32 TLobby__sub_803CC4C0(u32);
u32 adxf_open__6TLobbyFUii(void *, s32);
void load_gvm_texture_archive(u32, s32);
}
extern u8 fsrv_read_pvm_buffer_tag[];
extern AsyncFileReadRequest *async_file_read_current_request;
extern s32 async_file_read_state;
extern u32 async_file_read_sector_buffer;
extern u32 lobby_download_state_ptr;
extern u32 async_file_read_texture_buffer;
void process_async_file_reads(void) {
    switch (async_file_read_state) {
    case 0:
        if (async_file_read_current_request != NULL) {
            if (async_file_read_current_request->flags & 0x200) {
                TLobby::pop_and_close();
            } else {
                async_file_read_current_request->flags |= 0x100;
                if (async_file_read_current_request->flags & 2) {
                    async_file_read_texture_buffer = TLobby::tmp_buf_use_req((const char *)fsrv_read_pvm_buffer_tag);
                    if (async_file_read_texture_buffer != 0) {
                        lobby_download_state_ptr = adxf_open__6TLobbyFUii(async_file_read_current_request->name, 0);
                        TLobby::read_checked_align(lobby_download_state_ptr, async_file_read_current_request->count, async_file_read_texture_buffer);
                        async_file_read_state = 3;
                    }
                } else if (async_file_read_current_request->flags & 4) {
                    async_file_read_state = 4;
                } else {
                    u32 h = lobby_download_state_ptr = adxf_open__6TLobbyFUii(async_file_read_current_request->name, 0);
                    if (h != 0) {
                        if (async_file_read_current_request->count > 1) {
                            TLobby::read_checked_align(h, async_file_read_current_request->count - 1, (u32)async_file_read_current_request->dst);
                            async_file_read_state = 1;
                        } else {
                            TLobby::read_checked_align(h, 1, async_file_read_sector_buffer);
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
        } else if (TLobby__sub_803CC4C0(lobby_download_state_ptr) == 3) {
            TLobby::read_checked_align(lobby_download_state_ptr, 1, async_file_read_sector_buffer);
            async_file_read_state = 2;
        }
        break;
    case 2:
        if (async_file_read_current_request->flags & 0x200) {
            TLobby::destroy_instance();
            TLobby::pop_and_close();
            async_file_read_state = 0;
        } else if (TLobby__sub_803CC4C0(lobby_download_state_ptr) == 3) {
            u8 *dst = async_file_read_current_request->dst + ((async_file_read_current_request->count - 1) << 11);
            s32 n = async_file_read_current_request->size % 2048;
            if (n == 0) {
                n = 0x800;
            }
            switch (n & 3) {
            case 0:
                ((TLobby *)dst)->move_words((u32 *)async_file_read_sector_buffer, (s32)(n / 4));
                break;
            case 2:
                ((TLobby *)dst)->copy_u16_array((u16 *)async_file_read_sector_buffer, (s32)(n / 2));
                break;
            default:
                ((TLobby *)dst)->move_data((const void *)async_file_read_sector_buffer, (u32)n);
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
        } else if (TLobby__sub_803CC4C0(lobby_download_state_ptr) == 3) {
            load_gvm_texture_archive(async_file_read_texture_buffer, async_file_read_current_request->tex);
            TLobby::tmp_buf_release((const char *)fsrv_read_pvm_buffer_tag);
            TLobby::notify_and_close();
        }
        break;
    case 4:
        if (TLobby::load_bml_exec((u8 *)async_file_read_current_request->mode, (u8 *)async_file_read_current_request->name) != 0) {
            TLobby::pop_and_close();
            async_file_read_state = 0;
        }
        break;
    }
    TGStream__sub_800FDD64();
}
