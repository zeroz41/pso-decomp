#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecFoie.h"

extern "C" {


void TObjPlayer::create_foie_effect() {
    s32 sp8;
    void *owner;

    if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
        if (((TItemWeapon *)this)->get_joint_position(1, &sp8) != 0) {
            owner = *(void * *)&this->unk_F0;
            TTecFoie::create((void *)owner, &sp8, (void *)(*(s32 *)((s8 *)owner + 0x60)), (void *)5);
        }
    } else {
        update_active_game_effect();
    }
}

}
