#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049FC90.h"

extern "C" {
s32 get_item_index__5TItemFv(void *);
}

void TUnk_8049FC90::apply_use_effect() {
  u8 temp_r31;
    s32 arg0 = (s32)this;
  temp_r31 = get_item_index__5TItemFv((void *) arg0);
  ((TItem *)arg0)->set_owner_technique_level(((s16) (((TItemObject *)arg0)->get_technique() & 0xFF)), ((s16) (temp_r31 & 0xFFFFFFFFu)));
}

TUnk_8049FC90::~TUnk_8049FC90() {}

TUnk_8049FC90::TUnk_8049FC90(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_technique_disk_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FC90(tl_05, item);
    }
    return NULL;
}
