#include "types.h"
#include "pso/network/TPlyOnCountOver.h"

extern "C" {

void *__ct__15TPlyOnCountOverFv(void *, void *, void *, void *);
void *__nw__7TObjectFUl(int);

void *TPlyOnCountOver::create(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = __ct__15TPlyOnCountOverFv(o, arg0, arg1, arg2);
    }
    return o;
}

}
