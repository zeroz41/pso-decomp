#include "types.h"
#include "pso/effect/TUnk_80494968.h"

extern "C" {

void *__nw__7TObjectFUl(int);
void *fn_800D79A8(void *, void *, void *, void *);

extern void *tl_05;

TUnk_80494968 *TUnk_80494968::create(u32 arg0, u32 arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x128);
    if (o != NULL) {
        o = fn_800D79A8(o, tl_05, (void *)arg0, (void *)arg1);
    }
    return (TUnk_80494968 *)o;
}

}
