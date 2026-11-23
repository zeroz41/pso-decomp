#include "pso/unk/text_800FA464.h"
#include "pso/system/Adxf.h"
#include "types.h"
#include <string.h>
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FA848.h"

extern "C" {


s32 TLobby::request_file_read(const char *filename, void *destination, s32 *completion, void **request) {
    AsyncFileReadRequest *entry;
    AdxfHandle *file;

    if (request != NULL) {
        *request = NULL;
    }
    file = ADXF_Open(filename, 0);
    if (file == 0) {
        return -2;
    }
    entry = reinterpret_cast<AsyncFileReadRequest *>(TLobby::alloc_from_heap(sizeof(AsyncFileReadRequest)));
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

}
