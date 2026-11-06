#include "types.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"

extern "C" {

void *TObjEneHoldEffect__ct(void *, void *, void *, void *);
void *__nw__7TObjectFUl(int);

void TObjEneHoldEffect::create(void *arg0, void *type, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0xA0);
    if (o != NULL) {
        TObjEneHoldEffect__ct(o, arg0, type, arg2);
    }
}

}
