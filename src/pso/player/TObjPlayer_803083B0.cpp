#include "types.h"
#include "pso/weapon/TUnk_804E71F8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

TUnk_804E71F8::TUnk_804E71F8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *TObjPlayer::create_nug2000_bazooka(u8 *item) {
    if (item != NULL) {
        return new TUnk_804E71F8(tl_05, item);
    }
    return NULL;
}

TUnk_804E71F8::~TUnk_804E71F8() {}
