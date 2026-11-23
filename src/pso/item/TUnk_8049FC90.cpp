#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TUnk_8049FC90.h"
#include "pso/item/TItem.h"


void TUnk_8049FC90::apply_use_effect() {
  u8 item_index;
    saddr arg0 = (saddr)this;
  item_index = (s32)((TItem *)arg0)->get_item_index();
  ((TItem *)arg0)->set_owner_technique_level(((s16) (((TItemObject *)arg0)->get_technique() & 0xFF)), ((s16) (item_index & 0xFFFFFFFFu)));
}

TUnk_8049FC90::~TUnk_8049FC90() {}

TUnk_8049FC90::TUnk_8049FC90(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_technique_disk_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FC90(tl_05, item);
    }
    return NULL;
}
