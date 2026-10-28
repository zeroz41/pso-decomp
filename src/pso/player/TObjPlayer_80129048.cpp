#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/unk/TUnk_804A4020.h"
#include "pso/player/TUnk_804A4138.h"
#include "pso/item/TItemShootModel_dtor.h"
#include "pso/player/TObjPlayer_80129048.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TAdRicoRing.h"
#include "pso/TItemShootModel.h"

extern "C" {

int rotate_matrix_z(void*, void*);
s32 test_flags_any(void *, int);
int get_player_list__10TObjPlayerFv(void*);


}
TUnk_804A4020::~TUnk_804A4020() {

}


void TObjPlayer::clear_rico_ring_flag() {
    u32 arg0 = (u32)this;
    if (arg0 != 0U) {
        ((FlagWord *)(arg0 + 0x1FC))->clear(2);
    }
}

extern "C" {

s32 TObjPlayer__sub_801290D0(u8 *arg0) {
    if (test_flags_any(arg0 + 0x1FC, 4) != 0) {
        return *(s32 *)((s8 *)arg0 + 0x188);
    }
    return *(s32 *)((s8 *)arg0 + 0x184);
}

}

void TItemShootModel::sub_80129118(s32 arg1, s32 arg2) {
    *(s32 *)&this->m_58 = arg1;
    *(s32 *)&this->m_5C = arg2;
}

void TUnk_804A4138::update_idle() { *(s32*)((char*)this + 0x1fc) = 0; }
void TObjPlayer::handle_tunnel_state_0() { if (get_player_list__10TObjPlayerFv(this) == 0) { rotate_matrix_z((void*)0, *(void* *)&this->m_1fc); } }

