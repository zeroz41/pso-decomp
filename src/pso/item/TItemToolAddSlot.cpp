#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemToolAddSlot.h"

void TItemToolAddSlot::apply_use_effect() {
    TItem *armor = (TItem *)((TItemData *)(*(saddr *)((s8 *)this + 0xF0)))->get_item_field_2();
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
