#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"

extern u32 lbl_805D60C4;
extern s32 lbl_805D60C8;

void TLobby::append_swapped_u32(s32 *arg0) {
    s32 sp8;

    if ((u32) lbl_805D60C4 != 0U) {
        sp8 = *arg0;
        bswap_32((u32 *)&sp8);
        ((TLobby *)(lbl_805D60C4 + lbl_805D60C8))->move_data(&sp8, 4);
        lbl_805D60C8 += 4;
    }
}

void TLobby::append_entity_entry() {
    s32 arg0 = (s32)this;
    if ((u32) lbl_805D60C4 != 0U) {
        ((TLobby *)(lbl_805D60C4 + lbl_805D60C8))->move_data((s32 *)arg0, 1);
        lbl_805D60C8 += 1;
    }
}
