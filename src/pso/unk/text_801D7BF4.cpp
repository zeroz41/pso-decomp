#include "types.h"
#include "pso/ui/window/ActionPaletteTag.h"

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
        if (get_action_palette_tag_mode(reinterpret_cast<const ActionPaletteTag *>(p)) != 0) {
            return 0;
        }
    }
    return 1;
}

}
