#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/system/THeap.h"
#include "pso/system/AsyncFileRead.h"
#include <string.h>
#include "pso/audio/Adxf.h"
#include "pso/system/memory.h"
#include "pso/render/GvmTextureArchive.h"
#include "pso/system/TGStream.h"
#include "pso/system/MemoryMove.h"
#include "pso/system/BmlResource.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/MallocLoadFilePrc.h"

void free_static_buffer(void *ptr) { game_heap->heap_free(ptr); }

void *alloc_from_heap(size_t size) { return game_heap->heap_alloc(size); }

void pump_frames() {
    for (;;) {
        if (is_async_file_read_busy() == 0) {
            break;
        }
        process_async_file_reads();
        run_frame();
    }
}

s32 is_async_file_read_busy() {
    if (async_file_read_state != 0) {
        return 1;
    }
    return async_file_read_current_request != NULL ? TRUE : FALSE;
}

s32 cancel_async_file_read(AsyncFileReadRequest *request) {
    AsyncFileReadRequest *n;
    if (request == NULL) {
        return 0;
    }
    for (n = async_file_read_current_request; n != NULL; n = n->next) {
        if (n->id == request->id) {
            n->flags |= 0x200;
            return 1;
        }
    }
    return 0;
}

void add_named_entry(BmlResource *resource, const char *filename) {
    AsyncFileReadRequest *entry;

    entry = static_cast<AsyncFileReadRequest *>(alloc_from_heap(sizeof(AsyncFileReadRequest)));
    if (entry != NULL) {
        entry = link_into_list(entry);
    }
    strncpy(entry->name, filename, sizeof(entry->name));
    entry->flags = 4;
    entry->mode = resource;
}

void notify_and_close() {
    s32 *completion = async_file_read_current_request->completion;
    if (completion != NULL) {
        *completion = 1;
    }
    AsyncFileReadCallback callback = async_file_read_current_request->callback;
    if (callback != NULL) {
        callback(async_file_read_current_request->params);
    }
    pop_and_close();
    async_file_read_state = 0;
}

void destroy_instance() { ADXF_Close(lobby_download_state_ptr); lobby_download_state_ptr = 0; }

void pop_and_close() {
    AsyncFileReadRequest *next = async_file_read_current_request->next;
    pop_stack_entry(async_file_read_current_request, 1);
    async_file_read_current_request = next;
}

s32 create_file_load_entry(const char *name, NJS_TEXLIST *texture, AsyncFileReadCallback callback, const void *params, void **request) {
    AsyncFileReadRequest *entry;
    AdxfHandle *file;

    if (request != NULL) {
        *request = NULL;
    }
    file = ADXF_Open(name, 0);
    if (file == 0) {
        return -2;
    }
    if (ADXF_GetFsizeByte(file) > 0x40000) {
        ADXF_Close(file);
        return -3;
    }
    entry = static_cast<AsyncFileReadRequest *>(alloc_from_heap(sizeof(AsyncFileReadRequest)));
    if (entry != NULL) {
        entry = link_into_list(entry);
    }
    strncpy(entry->name, name, sizeof(entry->name));
    entry->flags = 2;
    entry->tex = texture;
    entry->count = ADXF_GetFsizeSct(file);
    ADXF_Close(file);
    entry->completion = NULL;
    entry->callback = callback;
    if (callback != NULL) {
        move_words(entry->params, params, 8);
    }
    if (request != NULL) {
        *request = entry;
    }
    return 0;
}

void process_pending_resources(void) {
    AsyncFileReadRequest *p;
    pump_frames();
    for (p = async_file_read_current_request; p != 0; p = p->next) {
        p->flags |= 0x200;
    }
}

s32 create_named_entry(const char *name, void *buffer, AsyncFileReadCallback callback, const void *params, void **request) {
    AsyncFileReadRequest *entry;
    AdxfHandle *file;

    if (request != NULL) {
        *request = NULL;
    }
    file = ADXF_Open(name, 0);
    if (file == 0) {
        return -2;
    }
    entry = static_cast<AsyncFileReadRequest *>(alloc_from_heap(sizeof(AsyncFileReadRequest)));
    if (entry != NULL) {
        entry = link_into_list(entry);
    }
    strncpy(entry->name, name, sizeof(entry->name));
    entry->flags = 1;
    entry->dst = static_cast<u8 *>(buffer);
    entry->size = ADXF_GetFsizeByte(file);
    entry->count = ADXF_GetFsizeSct(file);
    ADXF_Close(file);
    entry->completion = NULL;
    entry->callback = callback;
    if (callback != NULL) {
        move_words(entry->params, params, 8);
    }
    if (request != NULL) {
        *request = entry;
    }
    return entry->size;
}

s32 request_file_read(const char *filename, void *destination, s32 *completion, void **request) {
    AsyncFileReadRequest *entry;
    AdxfHandle *file;

    if (request != NULL) {
        *request = NULL;
    }
    file = ADXF_Open(filename, 0);
    if (file == 0) {
        return -2;
    }
    entry = reinterpret_cast<AsyncFileReadRequest *>(alloc_from_heap(sizeof(AsyncFileReadRequest)));
    if (entry != NULL) {
        entry = link_into_list(entry);
    }
    strncpy(entry->name, filename, sizeof(entry->name));
    entry->flags = 1;
    entry->dst = static_cast<u8 *>(destination);
    entry->size = ADXF_GetFsizeByte(file);
    entry->count = ADXF_GetFsizeSct(file);
    ADXF_Close(file);
    entry->completion = completion;
    if (completion != NULL) {
        *completion = 0;
    }
    entry->callback = NULL;
    if (request != NULL) {
        *request = entry;
    }
    return entry->size;
}

AsyncFileReadRequest *async_file_read_current_request;
AsyncFileReadRequest *lobby_stack_entry_list_tail;
s32 lobby_list_entry_count;
s32 async_file_read_state;
u8 *async_file_read_sector_buffer;
AdxfHandle *lobby_download_state_ptr;
s32 lobby_list_next_id;
THeap *game_heap;
u8 *async_file_read_texture_buffer;
void process_async_file_reads(void) {
    switch (async_file_read_state) {
    case 0:
        if (async_file_read_current_request != NULL) {
            if (async_file_read_current_request->flags & 0x200) {
                pop_and_close();
            } else {
                async_file_read_current_request->flags |= 0x100;
                if (async_file_read_current_request->flags & 2) {
                    async_file_read_texture_buffer = tmp_buf_use_req("FSVR_READPVM");
                    if (async_file_read_texture_buffer != NULL) {
                        lobby_download_state_ptr = ADXF_Open(async_file_read_current_request->name, 0);
                        ADXF_ReadNw(lobby_download_state_ptr, async_file_read_current_request->count, async_file_read_texture_buffer);
                        async_file_read_state = 3;
                    }
                } else if (async_file_read_current_request->flags & 4) {
                    async_file_read_state = 4;
                } else {
                    AdxfHandle *h = lobby_download_state_ptr = ADXF_Open(async_file_read_current_request->name, 0);
                    if (h != 0) {
                        if (async_file_read_current_request->count > 1) {
                            ADXF_ReadNw(h, async_file_read_current_request->count - 1, async_file_read_current_request->dst);
                            async_file_read_state = 1;
                        } else {
                            ADXF_ReadNw(h, 1, async_file_read_sector_buffer);
                            async_file_read_state = 2;
                        }
                    }
                }
            }
        }
        break;
    case 1:
        if (async_file_read_current_request->flags & 0x200) {
            destroy_instance();
            pop_and_close();
            async_file_read_state = 0;
        } else if (ADXF_GetStat(lobby_download_state_ptr) == 3) {
            ADXF_ReadNw(lobby_download_state_ptr, 1, async_file_read_sector_buffer);
            async_file_read_state = 2;
        }
        break;
    case 2:
        if (async_file_read_current_request->flags & 0x200) {
            destroy_instance();
            pop_and_close();
            async_file_read_state = 0;
        } else if (ADXF_GetStat(lobby_download_state_ptr) == 3) {
            u8 *dst = async_file_read_current_request->dst + ((async_file_read_current_request->count - 1) << 11);
            s32 n = async_file_read_current_request->size % 2048;
            if (n == 0) {
                n = 0x800;
            }
            switch (n & 3) {
            case 0:
                move_words(dst, async_file_read_sector_buffer, n / 4);
                break;
            case 2:
                copy_u16_array((u16 *)dst, (u16 *)async_file_read_sector_buffer, (n / 2));
                break;
            default:
                move_data(dst, async_file_read_sector_buffer, n);
                break;
            }
            destroy_instance();
            notify_and_close();
        }
        break;
    case 3:
        if (async_file_read_current_request->flags & 0x200) {
            destroy_instance();
            pop_and_close();
            async_file_read_state = 0;
        } else if (ADXF_GetStat(lobby_download_state_ptr) == 3) {
            load_gvm_texture_archive(async_file_read_texture_buffer, async_file_read_current_request->tex);
            tmp_buf_release("FSVR_READPVM");
            notify_and_close();
        }
        break;
    case 4:
        if (LoadBmlExec(async_file_read_current_request->mode, async_file_read_current_request->name) != 0) {
            pop_and_close();
            async_file_read_state = 0;
        }
        break;
    }
    async_file_read_stub();
}

void destroy_game_heap() { process_pending_resources(); safe_free(async_file_read_sector_buffer); free_chr_select_data(); delete game_heap; }

void init_download_state() {
    init_download_buffers();
    async_file_read_sector_buffer = static_cast<u8 *>(alloc(0x800));
    lobby_stack_entry_list_tail = NULL;
    async_file_read_current_request = NULL;
    lobby_download_state_ptr = 0;
    async_file_read_state = 0;
    lobby_list_entry_count = 0;
    lobby_list_next_id = 0;
    game_heap = new THeap(0x4000, 0x20);
}

AsyncFileReadRequest *pop_stack_entry(AsyncFileReadRequest *entry, s16 release) {
    if (entry != NULL) {
        if (lobby_stack_entry_list_tail == entry) {
            lobby_stack_entry_list_tail = NULL;
        }
        async_file_read_current_request = entry->next;
        lobby_list_entry_count -= 1;
        if (release > 0) {
            free_static_buffer(entry);
        }
    }
    return entry;
}

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
