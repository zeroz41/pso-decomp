#include "types.h"
#include "pso/weapon/TUnk_804A1C38.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80120908.h"

void TUnk_804A1C38::reserved_53() { draw_weapon_at_joint((saddr)this, (s8)49); update_trail_slot(0); update_trail_slot(1); }

TUnk_804A1C38::TUnk_804A1C38(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
}

TItem *create_claw_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A1C38(tl_05, item);
    }
    return NULL;
}

TUnk_804A1C38::~TUnk_804A1C38() {}
