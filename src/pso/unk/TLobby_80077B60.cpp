#include "types.h"
#include "pso/unk/TLobby_80077B60.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"

extern u32 lbl_805D4E58;
extern u32 lbl_805D4E5C;

void TLobby::free_static_windows() {
    if ((u32) lbl_805D4E5C != 0U) {
        ::operator delete((void *)lbl_805D4E5C);
        lbl_805D4E5C = 0U;
    }
    if ((u32) lbl_805D4E58 != 0U) {
        ::operator delete((void *)lbl_805D4E58);
        lbl_805D4E58 = 0U;
    }
}
void TLobby__sub_80077BAC(void) { (*(int *)&lbl_805D4E58) = 0; (*(int *)&lbl_805D4E5C) = 0; }
