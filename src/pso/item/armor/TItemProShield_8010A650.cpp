#include "types.h"
#include "pso/item/armor/TItemProShield.h"

extern "C" {

s32 __ct__14TItemEffShieldFv(u32, s32, u16, u32);
u32 __nw__7TObjectFUl(s32);

void TItemProShield::create_shield_effect(s32 arg0, u16 arg1, u32 arg2) {
    u32 obj;
    if ((arg0 != 0) && ((u16) arg1 != 0xFFFF) && (arg2 != 0U) && ((obj = __nw__7TObjectFUl(0x48)) != 0U)) {
        __ct__14TItemEffShieldFv(obj, arg0, arg1, arg2);
    }
}

}
