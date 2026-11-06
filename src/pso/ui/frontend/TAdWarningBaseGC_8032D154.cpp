#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"

extern "C" {

void* init_vtable__13TUnk_804EDBD0Fv(void*, s32);
void* __nw__7TObjectFUl(u32);

extern s32 tl_00;

void TAdWarningBaseGC::create() {
    void* obj = __nw__7TObjectFUl(0x20);
    if (obj != 0) {
        init_vtable__13TUnk_804EDBD0Fv(obj, tl_00);
    }
}

}
