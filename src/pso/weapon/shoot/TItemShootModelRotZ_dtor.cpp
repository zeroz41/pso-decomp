#include "types.h"
#include "pso/weapon/shoot/TItemShootModelRotZ_dtor.h"
#include "pso/weapon/shoot/TItemShootModel_dtor.h"

extern "C" {
extern void *__vt__19TItemShootModelRotZ[];
void __dl__7TObjectFPv(void *p);

void *__dt__19TItemShootModelRotZFv(void *self, s16 flag) {
    if (self != 0) {
        *(void **)((u8 *)self + 0x18) = __vt__19TItemShootModelRotZ;
        __dt__15TItemShootModelFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}
