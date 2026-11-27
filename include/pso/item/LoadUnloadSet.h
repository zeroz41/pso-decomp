#ifndef PSO_ITEM_LOADUNLOADSET_H
#define PSO_ITEM_LOADUNLOADSET_H

#include "types.h"
#include "pso/system/data/FlagWord.h"

// One {load, unload} pair of a resource set. A table of them ends with a null
// pair; create_load_unload_set counts up to it and builds the set.
struct ItemClassLoadUnloadEntry {
    void (*load)();
    void (*unload)();
};

// Runs a table's load functions once in shuffled order and its unload
// functions in reverse; flag bit 1 records that the set is loaded.
class LoadUnloadSet {
public:
    LoadUnloadSet(ItemClassLoadUnloadEntry *entries, s32 count);
    ~LoadUnloadSet();
    void shuffle_order();
    void init_order();
    void unload();
    void load();

    s32 count;
    ItemClassLoadUnloadEntry *entries;
    u8 *order;
    FlagWord flags;
};

LoadUnloadSet *create_load_unload_set(ItemClassLoadUnloadEntry *table);

#endif
