#include "types.h"
#include "pso/player/TUnk_804A1C38.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);

}

void TUnk_804A1C38::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot(0); update_trail_slot(1); }

TUnk_804A1C38::TUnk_804A1C38(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
}

u8 *create_claw_weapon(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1C38(tl_05, arg0);
    }
    return NULL;
}

TUnk_804A1C38::~TUnk_804A1C38() {}
