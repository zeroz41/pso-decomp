#include "types.h"
#include "pso/ui/window/TWindowSubQuestBoard_8027D1E8.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"

struct Obj_8027D1E8 { u8 pad[0x60]; s8 f60; };

extern "C" {
void fn_8027D1E8(Obj_8027D1E8 *o);

extern void *TWindowCtrl__active_window;

void fn_8027D1E8(Obj_8027D1E8 *o) {
    o->f60 &= ~1;
}

void TWindowCtrl__sub_8027D1F8(void) {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) & 0xFFFFFFEF);
    }
}

void TWindowCtrl__sub_8027D214(void) {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) | 0x10);
    }
}

}
