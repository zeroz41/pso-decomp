#include "types.h"
#include "pso/weapon/TUnk_804A3D20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

TUnk_804A3D20::TUnk_804A3D20(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

TItem *TObjPlayer::create_shoot_model_callback(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A3D20(tl_05, item);
    }
    return NULL;
}

TUnk_804A3D20::~TUnk_804A3D20() {}
