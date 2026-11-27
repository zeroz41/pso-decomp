#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolMaterial.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/item_create.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/TObjBase.h"
#include "pso/item/TItem.h"

// Written from the last function back (deferred code generation), which also
// puts the vtable before the switch table.


TItem *TItemToolMaterial::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolMaterial(tl_05, item);
    }
    return NULL;
}

TItemToolMaterial::TItemToolMaterial(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItemToolMaterial::~TItemToolMaterial() {}

void TItemToolMaterial::apply_use_effect() {
    switch (((TItem *)this)->get_item_index()) {
    case 0:
        ((TObjPlayer *)(this->owner))->add_power_material(2);
        break;
    case 1:
        if (check_class_equip_permission(this->owner, 0xD7) == 0) {
            ((TObjPlayer *)(this->owner))->add_mind_material(2);
        }
        break;
    case 2:
        ((TObjPlayer *)(this->owner))->add_evp_material(2);
        break;
    case 3:
        if (calc_base_hp_bonus(owner->get_entity_id()) < 0xFA) {
            ((TObjPlayer *)(this->owner))->add_hp_material((u8)(2));
        }
        break;
    case 4:
        if ((calc_base_tp_bonus(owner->get_entity_id()) < 0xFA) && (check_class_equip_permission(this->owner, 0xD7) == 0)) {
            ((TObjPlayer *)(this->owner))->add_tp_material((u8)(2));
        }
        break;
    case 5:
        ((TObjPlayer *)(this->owner))->add_dfp_material(2);
        break;
    case 6:
        ((TObjPlayer *)(this->owner))->add_luck_material(2);
        break;
    }
    owner->recalc_stats();
}
