#include "types.h"
#include "pso/weapon/TUnk_804E1BB0.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80120908.h"

void TUnk_804E1BB0::reserved_53() {
    NJS_OBJECT *second;
    NJS_OBJECT *model;
    saddr weapon = (saddr)this;

    draw_weapon_at_joint(weapon, 0x30);
    update_trail_slot(0);
    second = second_model;
    model = item_model;
    if (second != NULL) {
        item_model = second;
    }
    draw_weapon_at_joint(weapon, 0x23);
    update_trail_slot(1);
    item_model = model;
}

TUnk_804E1BB0::TUnk_804E1BB0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(513);
}

TItem *TUnk_804E1BB0::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804E1BB0(tl_05, item);
    }
    return NULL;
}

TUnk_804E1BB0::~TUnk_804E1BB0() {}
