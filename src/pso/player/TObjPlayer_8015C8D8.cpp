#include "types.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/CameraDistanceFade.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOAirconCave01.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 lbl_804B6C24[];

void *TUnk_804B6C24::destroy_container_object(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B6C24;
        ((CameraDistanceFade *)((s8 *)this + 0x340))->CameraDistanceFade::~CameraDistanceFade();
        __dt__9TObjCharaFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void TUnk_804B6C24::vfunc_6(s16 *, s32) {  }

}
