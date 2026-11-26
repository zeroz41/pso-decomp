#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemToolAddSlot.h"

void TItemToolAddSlot::apply_use_effect() {
    TItem *armor = (TItem *)((TObjPlayer *)owner)->get_equipped_armor();
    if (armor != NULL) {
        armor->add_slot();
    }
}

TItemToolAddSlot::~TItemToolAddSlot() {}

TItemToolAddSlot::TItemToolAddSlot(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolAddSlot::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolAddSlot(tl_05, item);
    }
    return NULL;
}
