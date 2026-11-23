#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubQuestBoard_8027D1E8.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"

struct Obj_8027D1E8 { u8 pad[0x60]; s8 f60; };

extern "C" {
void fn_8027D1E8(Obj_8027D1E8 *o);


void fn_8027D1E8(Obj_8027D1E8 *o) {
    o->f60 &= ~1;
}

void TWindowCtrl__sub_8027D1F8(void) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->flags &= ~0x10;
    }
}

void TWindowCtrl__sub_8027D214(void) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->flags |= 0x10;
    }
}

}
