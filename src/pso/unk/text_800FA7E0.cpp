#include "pso/unk/TLobby.h"
#include "pso/unk/text_800FA464.h"

AsyncFileReadRequest *TLobby::pop_stack_entry(AsyncFileReadRequest *entry, s16 release) {
    if (entry != NULL) {
        if (lobby_stack_entry_list_tail == entry) {
            lobby_stack_entry_list_tail = NULL;
        }
        async_file_read_current_request = entry->next;
        lobby_list_entry_count -= 1;
        if (release > 0) {
            TLobby::free_static_buffer(entry);
        }
    }
    return entry;
}
