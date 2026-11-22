#include "types.h"
#include "pso/unk/text_8010F168.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

// inferred: counts the {load, unload} pairs up to the null pair and builds a 0x10-byte set over them.
s32 create_load_unload_set(ItemClassLoadUnloadEntry *arg0) {
    s32 found;
    s32 i;
    saddr r;
    if (arg0 != 0) {
        found = 0;
        i = 0;
        while (found == 0) {
            void (*a)() = arg0[i].load; void (*b)() = arg0[i].unload;
            if (a == 0 && b == 0) {
                found = i;
            }
            i++;
        }
        if (found != 0) {
            r = (saddr)::operator new(0x10);
            if (r != 0) {
                r = (saddr)TItemDrop__sub_8010F1B8((u8 *)r, (saddr)arg0, found);
            }
            return r;
        }
    }
    return 0;
}

