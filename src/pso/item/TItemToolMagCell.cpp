#include "pso/item/mag/TItemMag.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolMagCell.h"
#include "pso/player/TObjPlayer.h"

void TItemToolMagCell::apply_use_effect() {
    TItemMag *mag;

    mag = (TItemMag *)this->owner->activate_d04_slot();
    if (mag != NULL) {
        mag->evolve_special_form(get_item_index());
    }
}

TItemToolMagCell::~TItemToolMagCell() {}

TItemToolMagCell::TItemToolMagCell(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolMagCell::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolMagCell(tl_05, item);
    }
    return NULL;
}
