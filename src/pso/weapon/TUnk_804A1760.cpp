#include "types.h"
#include "pso/weapon/TUnk_804A1760.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

TUnk_804A1760::~TUnk_804A1760() {}

TUnk_804A1760::TUnk_804A1760(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x600);
}

u8 *TObjPlayer::create_twin_chakram(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1760(tl_05, arg0);
    }
    return NULL;
}
