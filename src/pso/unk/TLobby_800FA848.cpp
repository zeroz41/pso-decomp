#include "types.h"
#include "pso/unk/TLobby.h"

extern void *async_file_read_current_request;
extern void *lobby_stack_entry_list_tail;
extern s32 lobby_list_entry_count;
extern s32 lobby_list_next_id;

void TLobby::link_into_list() {
    if ((void *) async_file_read_current_request == NULL) {
        async_file_read_current_request = this;
    }
    if ((void *) lobby_stack_entry_list_tail != NULL) {
        *(void **)((s8 *)lobby_stack_entry_list_tail + 0x38) = this;
    }
    lobby_stack_entry_list_tail = this;
    *(s32 *)((s8 *)this + 0x38) = 0;
    *(s32 *)((s8 *)this + 0x34) = 0;
    *(s32 *)((s8 *)this + 0x40) = 0;
    *(s32 *)((s8 *)this + 0x30) = 0;
    *(s32 *)((s8 *)this + 0x2C) = 0;
    lobby_list_entry_count += 1;
    *(s32 *)&this->m_flags = lobby_list_next_id++;
}
