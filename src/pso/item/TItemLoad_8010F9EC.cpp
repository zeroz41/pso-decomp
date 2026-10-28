#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/TItemLoad.h"
#include "pso/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

struct Base_8010FA4C_8010F9EC { char pad[0x14]; };
struct VObj_8010FA4C_8010F9EC : Base_8010FA4C_8010F9EC {
    virtual void m0();
    virtual void m1();
};

s32 test_flags_any(void *, int);
s32 advance_load_state__9TItemLoadFv();
s32 update_ring__9TItemLoadFv();

extern s32 item_load_work_buffer_busy;

void TItemLoad::reset_ring_state() {
    u8 *arg0 = (u8 *)this;
    if (test_flags_any(arg0 + 0x1C, 4) != 0) {
        item_load_work_buffer_busy = 0;
        ((FlagWord *)(arg0 + 0x1C))->clear(4);
    }
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
    ((FlagWord *)(arg0 + 0x1C))->reset();
}

void TItemLoad::update_state() {

    switch (*(s32 *)((s8 *)this + 0x18)) {
    case 1:
        advance_load_state__9TItemLoadFv();
        return;
    case 2:
        update_ring__9TItemLoadFv();
        return;
    case 4:
        ((VObj_8010FA4C_8010F9EC *)this)->m1();
    case 3:
        return;
    }
}

}
