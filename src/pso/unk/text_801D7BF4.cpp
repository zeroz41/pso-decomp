#include "types.h"
#include "pso/ui/hud/TMainCursor.h"

typedef struct Bank_801D7BF4 { s32 pad; s32 a[4]; s32 b[4]; } Bank_801D7BF4;

extern "C" {
s32 is_pb_palette_bank_empty(Bank_801D7BF4 *arg0, s32 arg1);
s32 is_pb_palette_bank_empty(Bank_801D7BF4 *arg0, s32 arg1) {
    s32 i;
    s32 *p;
    if (arg1 == 0) {
        p = arg0->a;
    } else {
        p = arg0->b;
    }
    for (i = 0; i < 4; i++, p++) {
        if (((TMainCursor *)p)->get_type() != 0) {
            return 0;
        }
    }
    return 1;
}

}
