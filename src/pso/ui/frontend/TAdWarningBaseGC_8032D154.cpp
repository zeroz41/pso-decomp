#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/system/task/TObject.h"

extern "C" {

void* init_vtable__13TUnk_804EDBD0Fv(void*, s32);

extern s32 tl_00;

void TAdWarningBaseGC::create() {
    void* obj = TObject::operator new(0x20);
    if (obj != 0) {
        init_vtable__13TUnk_804EDBD0Fv(obj, tl_00);
    }
}

}
