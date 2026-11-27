#include "types.h"
#include <stdlib.h>
#include "pso/item/LoadUnloadSet.h"
#include "pso/system/memory.h"

void LoadUnloadSet::shuffle_order() {
    s32 i;
    u32 j;
    u8 t;
    init_order();
    if (order != NULL) {
        for (i = 0; i != count; i++) {
            j = (u32)((f32)count * (3.0517578e-05f * (f32)rand()));
            t = order[i];
            order[i] = order[j];
            order[j] = t;
        }
    }
}

void LoadUnloadSet::init_order() {
    s32 i;
    if (order == 0) {
        return;
    }
    for (i = 0; i != count; i++) {
        order[i] = i;
    }
}

#pragma push
#pragma opt_common_subs off
void LoadUnloadSet::unload() {
    s32 i;
    void (*f)();
    if (flags.test_flags_any(1) != 0) {
        for (i = count - 1; i >= 0; i--) {
            if (order != 0) {
                f = entries[order[i]].unload;
            } else {
                f = entries[i].unload;
            }
            if (f != 0) {
                f();
            }
        }
        flags.clear(1);
    }
}

void LoadUnloadSet::load() {
    s32 i;
    void (*f)();
    if (flags.test_flags_any(1) == 0) {
        shuffle_order();
        for (i = 0; i != count; i++) {
            if (order != 0) {
                f = entries[order[i]].load;
            } else {
                f = entries[i].load;
            }
            if (f != 0) {
                f();
            }
        }
        flags.set(1);
    }
}
#pragma pop

LoadUnloadSet::~LoadUnloadSet() {
    unload();
    delete[] order;
}

LoadUnloadSet::LoadUnloadSet(ItemClassLoadUnloadEntry *entries, s32 count) {
    this->entries = entries;
    this->count = count;
    order = new u8[count];
    load();
}

LoadUnloadSet *create_load_unload_set(ItemClassLoadUnloadEntry *table) {
    s32 found;
    s32 i;
    if (table != 0) {
        found = 0;
        i = 0;
        while (found == 0) {
            void (*load)() = table[i].load;
            void (*unload)() = table[i].unload;
            if (load == 0 && unload == 0) {
                found = i;
            }
            i++;
        }
        if (found != 0) {
            return new LoadUnloadSet(table, found);
        }
    }
    return 0;
}
