#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

void *TAdSinglePlyChrSelectGC__sub_802115C0(void *p);

void TAdSinglePlyChrSelectGC::swap_item_data(s32 *arg1) {
    struct { u8 _pad[0x20]; } sp8;

    TAdSinglePlyChrSelectGC__sub_802115C0(&sp8);
    ((TAdSinglePlyChrSelectGC *)(&sp8))->copy_item_data(this);
    this->copy_item_data(arg1);
    ((TAdSinglePlyChrSelectGC *)arg1)->copy_item_data(&sp8);
}

}
