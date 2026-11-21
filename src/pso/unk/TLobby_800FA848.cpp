#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FA848.h"

extern void *async_file_read_current_request;
extern void *lobby_stack_entry_list_tail;
extern s32 lobby_list_entry_count;
extern s32 lobby_list_next_id;

void *link_into_list(void *entry) {
    if ((void *) async_file_read_current_request == NULL) {
        async_file_read_current_request = entry;
    }
    if ((void *) lobby_stack_entry_list_tail != NULL) {
        *(void **)((s8 *)lobby_stack_entry_list_tail + 0x38) = entry;
    }
    lobby_stack_entry_list_tail = entry;
    *(s32 *)((s8 *)entry + 0x38) = 0;
    *(s32 *)((s8 *)entry + 0x34) = 0;
    *(s32 *)((s8 *)entry + 0x40) = 0;
    *(s32 *)((s8 *)entry + 0x30) = 0;
    *(s32 *)((s8 *)entry + 0x2C) = 0;
    lobby_list_entry_count += 1;
    *(s32 *)&((TLobby *)entry)->m_flags = lobby_list_next_id++;
    return entry;
}
