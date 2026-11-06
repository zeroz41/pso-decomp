#include "types.h"
#include "pso/item/TUnk_804A2868.h"
#include "pso/item/TItemEffFlame.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TMainTask.h"

void TUnk_804A2868::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->pad_78 = 0x1BB;
    desc->pad_74 = (void *)spawn_flame_effect;
    desc->pad_10 = unk_1f8;
}

TUnk_804A2868::TUnk_804A2868(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x8000);
    shot_speed = 5.0f;
    if (get_item_index() == 1) {
        unk_1f8 = 10;
    } else {
        unk_1f8 = 1;
    }
}

u8 *TObjPlayer__sub_80126054(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A2868(tl_05, item);
    }
    return NULL;
}

TUnk_804A2868::~TUnk_804A2868() {}
