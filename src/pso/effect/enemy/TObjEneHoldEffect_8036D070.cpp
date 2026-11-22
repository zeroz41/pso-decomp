#include "types.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TObjEneHoldEffect__ct(void *, void *, s32, s32);

void TObjEneHoldEffect::create(void *parent, s32 type, s32 arg2) {
    void *o;
    o = TObject::operator new(0xA0);
    if (o != NULL) {
        TObjEneHoldEffect__ct(o, parent, type, arg2);
    }
}

}
