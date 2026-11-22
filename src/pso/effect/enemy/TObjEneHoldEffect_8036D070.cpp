#include "types.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TObjEneHoldEffect__ct(void *, void *, void *, void *);

void TObjEneHoldEffect::create(void *parent, void *type, void *arg2) {
    void *o;
    o = TObject::operator new(0xA0);
    if (o != NULL) {
        TObjEneHoldEffect__ct(o, parent, type, arg2);
    }
}

}
