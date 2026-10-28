#include "types.h"
#include "pso/player/TObjPlayer_8012CE9C.h"
#include "pso/player/TUnk_804A5740.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int rotate_matrix_x(void*, void*);
void __ct__11TItemWeaponFP7TObjectPUc(void *);
int get_player_list__10TObjPlayerFv(void*);

void TUnk_804A5740::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), 1820, 10922); }
void TUnk_804A5740::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), -1820, 0); }
void TObjPlayer::release_container_if_positive() { if (get_player_list__10TObjPlayerFv(this) > 0) { rotate_matrix_x((void*)0, *(void* *)&this->unk_1F8); } }

extern s32 lbl_804A5740[];

void *TUnk_804A5740::init_state_1f8() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A5740;
    *(u32 *)&this->unk_1F8 = 10922;
    set_weapon_flags(1536);
    return this;
}

}
