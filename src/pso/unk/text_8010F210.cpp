#include "types.h"
#include "pso/unk/text_8010F168.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
typedef struct Slot_8010F210 { u32 a; u32 b; } Slot_8010F210;

extern "C" {
s32 create_load_unload_set(Slot_8010F210 *arg0);
// inferred: counts the {load, unload} pairs up to the null pair and builds a 0x10-byte set over them.
s32 create_load_unload_set(Slot_8010F210 *arg0) {
    s32 found;
    s32 i;
    s32 r;
    if (arg0 != 0) {
        found = 0;
        i = 0;
        while (found == 0) {
            u32 a = arg0[i].a; u32 b = arg0[i].b;
            if (a == 0 && b == 0) {
                found = i;
            }
            i++;
        }
        if (found != 0) {
            r = (int)::operator new(0x10);
            if (r != 0) {
                r = (s32)TItemDrop__sub_8010F1B8((u8 *)r, (s32)arg0, found);
            }
            return r;
        }
    }
    return 0;
}

}
