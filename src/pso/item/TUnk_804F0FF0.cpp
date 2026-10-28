#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/TMainTask.h"
#include "pso/item/TItem.h"
#include "pso/unk/TUnk_804F0FF0.h"
#include "pso/player/TObjPlayer.h"

// A kill-counting item whose count reached its target becomes item 03 17 xx,
// xx being the kill count.
void TUnk_804F0FF0::apply_use_effect() {
    TItemData data;
    if (get_item_index() == 0 && (get_item_flags() & ITEM_FLAG_KILL_COUNTER)) {
        data.data1.data_u8[0] = 3;
        data.data1.data_u8[1] = 0x17;
        data.data1.data_u8[2] = get_kill_count();
        replace_item_with_new_code(&data, this);
    }
}

TUnk_804F0FF0::~TUnk_804F0FF0() {}

TUnk_804F0FF0::TUnk_804F0FF0(TObject *parent, u8 *item) : TItemObject(parent, item) {
    clear_item_flags(ITEM_FLAG_CONSUMABLE);
}

TUnk_804F0FF0 *TUnk_804F0FF0::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F0FF0(tl_05, item);
    }
    return NULL;
}
