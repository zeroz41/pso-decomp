#include "types.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer_80130520.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TUnk_804A69DC.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int rotate_matrix_x(void*, void*);
s32 update_trail_slot__11TItemWeaponFPvi(void *, s32);
int get_player_list__10TObjPlayerFv(void*);

void TObjPlayer::handle_container_state_3() { if (get_player_list__10TObjPlayerFv(this) == 3) { rotate_matrix_x((void*)0, *(void* *)&this->unk_1F8); } }

void TObjPlayer::set_temp_flag10_and_update() {
    s32 *temp_r31;

    if ((u32) *(u32 *)&this->unk_F0 != 0U) {
        temp_r31 = *(s32 **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this->m_f4 + 0x2C)) + 0x30)) + 0x30);
        if ((s32) this->m_204 == 0) {
            *temp_r31 |= 0x10;
        }
        ((TItemWeapon *)this)->draw_weapon_model();
        update_trail_slot__11TItemWeaponFPvi(this, 0);
        if ((s32) this->m_204 == 0) {
            *temp_r31 &= 0xFFFFFFEF;
        }
    }
}

void TUnk_804A69DC::update_idle() {
    s32 temp_r4;

    temp_r4 = this->m_1fc;
    if (temp_r4 > 0xCCC) {
        this->m_1fc = (temp_r4 - 0xB6);
    }
}

void TUnk_804A69DC::update_attack() {
    s32 temp_r4;

    *(s32 *)&this->unk_200 = (s32) (*(s32 *)&this->unk_200 + 1);
    if (!(*(s32 *)&this->unk_200 & 3)) {
        temp_r4 = this->m_1fc;
        if (temp_r4 < 0x3333) {
            this->m_1fc = (temp_r4 + 0xB6);
        }
    }
}

void TUnk_804A69DC::update_weapon() {
    advance_angle_wrap((s32 *)&this->unk_1F8, this->m_1fc);
}

}
