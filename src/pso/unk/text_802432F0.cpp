#include "types.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/unk/text_802432F0.h"

extern s32 lbl_804CDC88[];
s32 fn_802432F0(void *name) {
    s32 *p = lbl_804CDC88;
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
