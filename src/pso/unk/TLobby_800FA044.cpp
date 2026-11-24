#include "pso/unk/text_800FA464.h"
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FA848.h"


void TLobby::add_named_entry(BmlResource *resource, const char *filename) {
    AsyncFileReadRequest *entry;

    entry = static_cast<AsyncFileReadRequest *>(TLobby::alloc_from_heap(sizeof(AsyncFileReadRequest)));
    if (entry != NULL) {
        entry = link_into_list(entry);
    }
    strncpy(entry->name, filename, sizeof(entry->name));
    entry->flags = 4;
    entry->mode = resource;
}
