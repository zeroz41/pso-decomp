#include "types.h"
#include "pso/player/TUnk_8048E5F4.h"
#include "pso/misc/TLobby.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__13TUnk_8048E5F4[];

void *TUnk_8048E5F4::init_subobject(void *arg1, void *arg2) {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_8048E5F4;
    *(void * *)&this->unk_1C = arg2;
    return this;
}

}
