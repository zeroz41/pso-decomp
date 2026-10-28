#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049F998.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 get_item_index__5TItemFv(void *);
}
void TUnk_8049F998::apply_use_effect() {
    switch ((s32) (((u8 (*)())get_item_index__5TItemFv)())) {
    case 0:
        owner->cure_poison_ailment();
        return;
    case 1:
        owner->cure_paralysis();
        return;
    }
}

TUnk_8049F998::~TUnk_8049F998() {}

TUnk_8049F998::TUnk_8049F998(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_status_cure_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049F998(tl_05, item);
    }
    return NULL;
}
