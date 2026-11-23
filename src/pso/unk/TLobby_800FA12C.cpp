#include "pso/unk/TLobby.h"
#include "pso/unk/text_800FA464.h"

void TLobby::pop_and_close() {
    AsyncFileReadRequest *next = async_file_read_current_request->next;
    pop_stack_entry(async_file_read_current_request, 1);
    async_file_read_current_request = next;
}
