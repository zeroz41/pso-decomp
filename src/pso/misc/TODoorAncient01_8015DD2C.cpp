#include "types.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TODoorBase.h"
#include "pso/misc/TODoorAncient01.h"

// The destructor is still written out by hand: the vtable comes ahead of the
// switch table in the original, which only the whole door-base unit compiled
// with deferred code generation would give.
extern "C" {
void __dl__7TObjectFPv(void *);

void *__dt__10TODoorBaseFv(void *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__10TODoorBase;
        __dt__13TObjMapObjectFv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}
