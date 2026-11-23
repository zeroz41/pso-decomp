#ifndef PSO_UNK_TEXT_800FA464_H
#define PSO_UNK_TEXT_800FA464_H

#include "types.h"
#include <stddef.h>

struct AdxfHandle;
struct BmlResource;
struct NJS_TEXLIST;

typedef void (*AsyncFileReadCallback)(void *);

struct AsyncFileReadRequest {
    u32 flags;
    s32 id;
    char name[0x20];
    u8 *dst;
    s32 size;
    s32 count;
    s32 *completion;
    AsyncFileReadRequest *next;
    NJS_TEXLIST *tex;
    AsyncFileReadCallback callback;
    // The on-disc loader copies eight words of context for the callback.
    u8 params[0x20];
    BmlResource *mode;
};

LAYOUT_ASSERT(AsyncFileReadRequestSize, sizeof(AsyncFileReadRequest) == 0x68);

LAYOUT_ASSERT(AsyncFileReadRequest_id_offset, offsetof(AsyncFileReadRequest, id) == 4);
LAYOUT_ASSERT(AsyncFileReadRequest_next_offset, offsetof(AsyncFileReadRequest, next) == 0x38);
LAYOUT_ASSERT(AsyncFileReadRequest_callback_offset, offsetof(AsyncFileReadRequest, callback) == 0x40);
LAYOUT_ASSERT(AsyncFileReadRequest_params_offset, offsetof(AsyncFileReadRequest, params) == 0x44);
LAYOUT_ASSERT(AsyncFileReadRequest_mode_offset, offsetof(AsyncFileReadRequest, mode) == 0x64);

extern "C" {
extern AsyncFileReadRequest *async_file_read_current_request;
extern AsyncFileReadRequest *lobby_stack_entry_list_tail;
extern s32 lobby_list_entry_count;
extern s32 async_file_read_state;
extern u8 *async_file_read_sector_buffer;
extern AdxfHandle *lobby_download_state_ptr;
extern s32 lobby_list_next_id;
}

void process_async_file_reads();

#endif
