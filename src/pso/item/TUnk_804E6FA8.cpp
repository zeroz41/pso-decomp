#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TItemData.h"
#include "pso/enemy/TUnk_804E6FA8.h"

void TUnk_804E6FA8::apply_use_effect() {
    TItem *armor = (TItem *)((TItemData *)(*(s32 *)((s8 *)this + 0xF0)))->get_item_field_2();
    if (armor != NULL) {
        armor->add_slot();
    }
}

TUnk_804E6FA8::~TUnk_804E6FA8() {}

TUnk_804E6FA8::TUnk_804E6FA8(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_add_slot_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_804E6FA8(tl_05, item);
    }
    return NULL;
}
