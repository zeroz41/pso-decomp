#include "types.h"
#include "pso/unk/TLobby.h"

extern void *async_file_read_current_request;

void TLobby::pop_and_close() {
    void *temp_r31;

    temp_r31 = *(void **)((s8 *)async_file_read_current_request + 0x38);
    ((TLobby *)async_file_read_current_request)->pop_stack_entry(1);
    async_file_read_current_request = temp_r31;
}
