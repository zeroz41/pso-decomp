#include "types.h"
#include "pso/unk/TLobby_80242910.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 TLobby::get_id() { return *(s32 *)&this->m_name; }

extern u16 lbl_805D63FC;

void TLobby__sub_80242918(void) {
    lbl_805D63FC |= 4;
}

void TLobby::clear_flag_bit2() {
    lbl_805D63FC &= 0xFFFFFFFB;
}

}
