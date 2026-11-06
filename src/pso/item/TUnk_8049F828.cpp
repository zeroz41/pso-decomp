#include "pso/item/mag/TItemMag.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TUnk_8049F828.h"
#include "pso/player/TObjPlayer.h"

void TUnk_8049F828::apply_use_effect() {
    TItemMag *mag;

    mag = (TItemMag *)this->owner->activate_d04_slot();
    if (mag != NULL) {
        mag->evolve_special_form(get_item_index());
    }
}

TUnk_8049F828::~TUnk_8049F828() {}

TUnk_8049F828::TUnk_8049F828(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TUnk_8049F828 *TUnk_8049F828::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049F828(tl_05, item);
    }
    return NULL;
}
