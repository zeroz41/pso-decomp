#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049F828.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 get_item_index__5TItemFv(void *);
s32 apply_transform_action__8TItemMagFUc(s32, s32);
}

void TUnk_8049F828::apply_use_effect() {
    s32 temp_r3;

    temp_r3 = this->owner->activate_d04_slot();
    if (temp_r3 != 0) {
        apply_transform_action__8TItemMagFUc(temp_r3, get_item_index__5TItemFv(this));
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
