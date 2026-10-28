#include "types.h"
#include "pso/unk/text_802E52AC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
extern u8 lbl_804E35E8[];
extern u32 lbl_805D68F4;

void fn_802E52AC() {
    s32 r;
    if (lbl_805D68F4 == 0) {
        r = (int)::operator new(0x440);
        if (r != 0) {
            r = load_resource_from_descriptor(r, 5, lbl_804E35E8, 0, 0, 0);
        }
        lbl_805D68F4 = r;
        if (lbl_805D68F4 == 0) {
            return;
        }
    }
}
}
