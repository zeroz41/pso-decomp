#ifndef PSO_SYSTEM_ASYNCFILEREAD_H
#define PSO_SYSTEM_ASYNCFILEREAD_H

#include "types.h"
#include <stddef.h>

struct AdxfHandle;
class THeap;
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

extern AsyncFileReadRequest *async_file_read_current_request;
extern AsyncFileReadRequest *lobby_stack_entry_list_tail;
extern s32 lobby_list_entry_count;
extern s32 async_file_read_state;
extern u8 *async_file_read_sector_buffer;
extern AdxfHandle *lobby_download_state_ptr;
extern s32 lobby_list_next_id;
// The heap init_download_state creates for game allocations.
extern THeap *game_heap;

s32 is_async_file_read_busy();
// Marks a queued request so the reader drops it without reading.
s32 cancel_async_file_read(AsyncFileReadRequest *request);
void process_pending_resources();
void process_async_file_reads();
AsyncFileReadRequest *link_into_list(AsyncFileReadRequest *entry);
void free_static_buffer(void *ptr);
void *alloc_from_heap(size_t size);
void pump_frames();
void add_named_entry(BmlResource *resource, const char *filename);
void notify_and_close();
void destroy_instance();
void pop_and_close();
s32 create_file_load_entry(const char *name, NJS_TEXLIST *texture, AsyncFileReadCallback callback, const void *params, void **request);
s32 create_named_entry(const char *name, void *destination, AsyncFileReadCallback callback, const void *params, void **request);
s32 request_file_read(const char *name, void *destination, s32 *completion, void **request);
void destroy_game_heap();
void init_download_state();
AsyncFileReadRequest *pop_stack_entry(AsyncFileReadRequest *entry, s16 release);

#endif
