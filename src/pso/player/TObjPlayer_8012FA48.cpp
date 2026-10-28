#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A65E0[];

void *TObjPlayer::initialize_effect_object() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A65E0;
    ((TObjPlayer *)((char *)this + 516))->construct_target_cursor_records();
    ((FlagWord *)((char *)this + 376))->set(32);
    ((TItemWeapon *)this)->set_weapon_flags(34);
    set_effect_state(5);
    return this;
}

}
