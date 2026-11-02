#include "types.h"
#include "pso/item/TUnk_804A1098.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecGiBarta.h"

extern "C" {

s32 rand();
int rotate_matrix_x(void*, void*);
int get_player_list__10TObjPlayerFv(void*);

void TObjPlayer::set_atp(s16 v) { *(s16 *)&this->unk_1CC = v; }
void TUnk_804A1098::emit_marker_effects() {
    s32 sp8;
    void *tec_gi_barta;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(0, &sp8) != 0) {
            tec_gi_barta = this->owner;
            ((TTecGiBarta *)tec_gi_barta)->create_ex(&sp8, (void *)(*(s32 *)((s8 *)tec_gi_barta + 0x60)), (void *)(((TObjPlayer *)this)->get_tp()));
            roll_technique();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}
void TUnk_804A1098::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) == 1) { rotate_matrix_x((void*)0, *(void* *)&this->unk_1F8); } }


void TUnk_804A1098::update_idle() {
    if ((s32) this->m_1fc == 3) {
        this->m_1fc = 1;
    }
    if (((s32) this->m_1fc == 0) && ((3.0517578e-05f * (f32) rand()) < 0.1f)) {
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
