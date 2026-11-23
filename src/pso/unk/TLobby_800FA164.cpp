#include "pso/unk/text_800FA464.h"
#include "pso/system/Adxf.h"
#include "pso/system/memory.h"
#include "pso/system/Adxf.h"
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FA848.h"

s32 TLobby::create_file_load_entry(const char *name, NJS_TEXLIST *texture, AsyncFileReadCallback callback, const void *params, void **request) {
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
    entry = static_cast<AsyncFileReadRequest *>(TLobby::alloc_from_heap(sizeof(AsyncFileReadRequest)));
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
