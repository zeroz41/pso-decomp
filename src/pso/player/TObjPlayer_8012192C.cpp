#include "types.h"
#include "pso/player/TUnk_804A0AA8.h"
#include "pso/item/TItemShootModel_dtor.h"
#include "pso/player/TObjPlayer_8012192C.h"
#include "pso/item/TUnk_804A0BC0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecFoie.h"

extern "C" {

s32 rand();
int rotate_matrix_x(void*, void*);
int get_player_list__10TObjPlayerFv(void*);


}
TUnk_804A0AA8::~TUnk_804A0AA8() {

}


void TObjPlayer::cast_foie_effect() {
    s32 sp8;
    void *owner;

    if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
        if (((TItemWeapon *)this)->get_joint_position(0, &sp8) != 0) {
            owner = *(void * *)&this->unk_F0;
            TTecFoie::create((void *)owner, &sp8, (void *)(*(s32 *)((s8 *)owner + 0x60)), (void *)(get_tp()));
            ((TItemWeapon *)this)->roll_technique();
        }
    } else {
        update_active_game_effect();
    }
}

void TObjPlayer::release_container_if_active() { if (get_player_list__10TObjPlayerFv(this) == 1) { rotate_matrix_x((void*)0, *(void* *)&this->unk_1F8); } }

extern f32 lbl_805DACC8;
extern f32 lbl_805DACCC;

void TUnk_804A0BC0::update_idle() {
    if ((s32) this->m_1fc == 3) {
        this->m_1fc = 1;
    }
    if (((s32) this->m_1fc == 0) && ((lbl_805DACC8 * (f32) rand()) < lbl_805DACCC)) {
        this->m_1fc = 2;
    }
}

void TUnk_804A0BC0::update_attack() {
    s32 temp_r0;

    temp_r0 = this->m_1fc;
    if ((temp_r0 == 1) || (temp_r0 == 0)) {
        this->m_1fc = 2;
    }
}

