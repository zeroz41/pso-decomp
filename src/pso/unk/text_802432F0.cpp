#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/unk/text_802432F0.h"

s32 card_file_search_channels[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
s32 find_card_file_channel(void *name) {
    s32 *p = card_file_search_channels;
    s32 i;
    for (i = 0; i < 2; i++, p++) {
        switch (TAdPlayerLoadGC::find_card_file(*p, (const char *)name)) {
        case 0:
            return *p;
        case -1:
            return -2;
        }
    }
    return -1;
}
