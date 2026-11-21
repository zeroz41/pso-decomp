#include "types.h"
#include "pso/weapon/TUnk_804A2450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8011BEF0.h"
#include "pso/unk/text_80125428.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80125480.h"
#include "pso/item/TItem.h"

TUnk_804A2450::TUnk_804A2450(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = (WeaponShotCallback)spawn_shoot_particle_9f;
    shot_speed = 11.0f;
}


TItem *TObjPlayer__sub_80125428(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2450(tl_05, item);
    }
    return NULL;
}


TUnk_804A2450::~TUnk_804A2450() {}
