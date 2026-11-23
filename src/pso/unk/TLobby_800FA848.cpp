#include "pso/unk/TLobby_800FA848.h"
#include "pso/unk/text_800FA464.h"

AsyncFileReadRequest *link_into_list(AsyncFileReadRequest *entry) {
    if (async_file_read_current_request == NULL) {
        async_file_read_current_request = entry;
    }
    if (lobby_stack_entry_list_tail != NULL) {
        lobby_stack_entry_list_tail->next = entry;
    }
    lobby_stack_entry_list_tail = entry;
    entry->next = NULL;
    entry->completion = NULL;
    entry->callback = NULL;
    entry->count = 0;
    entry->size = 0;
    lobby_list_entry_count += 1;
    entry->id = lobby_list_next_id++;
    return entry;
}
