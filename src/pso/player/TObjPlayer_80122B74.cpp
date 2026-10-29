#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_80122B74.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecFoie.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

void TObjPlayer::cast_foie() {
    s32 sp8;
    void *owner;

    ((TItemWeapon *)this)->get_joint_position(2, &sp8);
    spawn_particle_effect(&sp8, 0x1BF);
    if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
        owner = *(void * *)&this->blend.frame[1];
        TTecFoie::create((void *)owner, &sp8, (void *)(*(s32 *)((s8 *)owner + 0x60)), (void *)3);
        return;
    }
    update_active_game_effect();
}

extern s32 lbl_804A1380[];

void *TObjPlayer__sub_80122BE4(void *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = lbl_804A1380;
    ((TItemWeapon *)player)->set_weapon_flags(34);
    return player;
}

}
