#include "types.h"
#include "pso/weapon/shoot/TItemShootModel_dtor.h"

extern "C" {
extern void *__vt__15TItemShootModel[];
void __dt__10TItemShootFv(void *self, s32 flag);
void __dl__7TObjectFPv(void *p);

void *__dt__15TItemShootModelFv(void *self, s16 flag) {
    if (self != 0) {
        *(void **)((u8 *)self + 0x18) = __vt__15TItemShootModel;
        __dt__10TItemShootFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}
