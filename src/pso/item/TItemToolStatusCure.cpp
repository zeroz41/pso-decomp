#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolStatusCure.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

void TItemToolStatusCure::apply_use_effect() {
    switch ((s32) (this->get_item_index())) {
    case 0:
        owner->cure_poison_ailment();
        return;
    case 1:
        owner->cure_paralysis();
        return;
    }
}

TItemToolStatusCure::~TItemToolStatusCure() {}

TItemToolStatusCure::TItemToolStatusCure(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolStatusCure::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolStatusCure(tl_05, item);
    }
    return NULL;
}
