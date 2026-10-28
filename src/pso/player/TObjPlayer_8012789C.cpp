#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012789C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecJelin.h"
#include "pso/misc/TTecZarua.h"

extern "C" {


void TObjPlayer__sub_8012789C(void* p) { ((TItemWeapon *)p)->roll_technique(); ((TItemWeapon *)p)->roll_technique(); }

extern s32 tl_05;

void TObjPlayer::cast_jellen_zalure() {
    s32 owner;
    s32 temp_r3_2;
    s32 temp_r4;
    s32 temp_r4_2;

    if (((TItemWeapon *)this)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)this, 2, 1);
    }
    if (is_mode_two_and_ready() != 0) {
        if (get_tp() == 0) {
            owner = *(s32 *)&this->unk_F0;
            temp_r4 = owner + 0x38;
            TTecJelin::create(owner, temp_r4, temp_r4, 4);
        } else {
            temp_r3_2 = *(s32 *)&this->unk_F0;
            temp_r4_2 = temp_r3_2 + 0x38;
            TTecZarua::create_instance(temp_r3_2, temp_r4_2, temp_r4_2, 4);
        }
        ((TItemWeapon *)this)->roll_technique();
        return;
    }
    update_active_game_effect();
}

}
