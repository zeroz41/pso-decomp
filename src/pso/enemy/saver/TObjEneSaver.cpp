#include "types.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *fn_800D79A8(void *, void *, s32, s32);

extern void *tl_05;

TUnk_80494968 *TUnk_80494968::create(u32 arg0, u32 arg1) {
    void *o;
    o = TObject::operator new(0x128);
    if (o != NULL) {
        o = fn_800D79A8(o, tl_05, arg0, arg1);
    }
    return (TUnk_80494968 *)o;
}

}
