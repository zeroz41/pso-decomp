#include "types.h"
#include "pso/item/TUnk_804A1098.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecGiBarta.h"

extern "C" {

s32 rand();
int rotate_matrix_x(void*, void*);
s32 is_mode_two_and_ready__10TObjPlayerFv();
int get_player_list__10TObjPlayerFv(void*);

void TObjPlayer::set_atp(s16 v) { *(s16 *)&this->unk_1CC = v; }
void TObjPlayer::cast_tech_gibarta() {
    s32 sp8;
    void *tec_gi_barta;

    if (is_mode_two_and_ready__10TObjPlayerFv() != 0) {
        if (draw_icon(0, (s32)&sp8) != 0) {
            tec_gi_barta = *(void * *)&this->unk_F0;
            ((TTecGiBarta *)tec_gi_barta)->create_ex(&sp8, (void *)(*(s32 *)((s8 *)tec_gi_barta + 0x60)), (void *)(get_tp()));
            ((TItemWeapon *)this)->roll_technique();
        }
    } else {
        update_active_game_effect();
    }
}
void TObjPlayer::notify_container_if_mode1() { if (get_player_list__10TObjPlayerFv(this) == 1) { rotate_matrix_x((void*)0, *(void* *)&this->unk_1F8); } }

extern f32 lbl_805DACF0;
extern f32 lbl_805DACF4;

void TUnk_804A1098::update_idle() {
    if ((s32) this->m_1fc == 3) {
        this->m_1fc = 1;
    }
    if (((s32) this->m_1fc == 0) && ((lbl_805DACF0 * (f32) rand()) < lbl_805DACF4)) {
        this->m_1fc = 2;
    }
}

void TUnk_804A1098::update_attack() {
    s32 temp_r0;

    temp_r0 = this->m_1fc;
    if ((temp_r0 == 1) || (temp_r0 == 0)) {
        this->m_1fc = 2;
    }
}

}
