#include "types.h"
#include "pso/weapon/TUnk_804A1760.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

TUnk_804A1760::~TUnk_804A1760() {}

TUnk_804A1760::TUnk_804A1760(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x600);
}

TItem *TObjPlayer::create_twin_chakram(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A1760(tl_05, item);
    }
    return NULL;
}
