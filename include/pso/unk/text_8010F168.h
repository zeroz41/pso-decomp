#ifndef PSO_UNK_TEXT_8010F168_H
#define PSO_UNK_TEXT_8010F168_H

#include "types.h"

// One {load, unload} pair of a resource set. A table of them ends with a null
// pair; create_load_unload_set counts up to it and builds the set.
struct ItemClassLoadUnloadEntry {
    void (*load)();
    void (*unload)();
};

s32 create_load_unload_set(ItemClassLoadUnloadEntry *table);

extern "C" {
void *TItemDrop__sub_8010F168(void *drop, s16 flags);
u8 *TItemDrop__sub_8010F1B8(u8 *drop, s32 id, s32 size);
}

#endif
