#include "types.h"
#include "pso/unk/TLobby.h"

extern u8 *async_file_read_current_request;
extern s32 async_file_read_state;

void TLobby::notify_and_close() {
    s32 (*temp_r12)(void *);
    s32 *temp_r3;

    temp_r3 = *(s32 **)((s8 *)async_file_read_current_request + 0x34);
    if (temp_r3 != NULL) {
        *temp_r3 = 1;
    }
    temp_r12 = *(s32 (**)(void *))((s8 *)async_file_read_current_request + 0x40);
    if (temp_r12 != NULL) {
        temp_r12(async_file_read_current_request + 0x44);
    }
    TLobby::pop_and_close();
    async_file_read_state = 0;
}
