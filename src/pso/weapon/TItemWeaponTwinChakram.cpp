#include "types.h"
#include "pso/weapon/TItemWeaponTwinChakram.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

TItemWeaponTwinChakram::~TItemWeaponTwinChakram() {}

TItemWeaponTwinChakram::TItemWeaponTwinChakram(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x600);
}

TItem *TObjPlayer::create_twin_chakram(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponTwinChakram(tl_05, item);
    }
    return NULL;
}
