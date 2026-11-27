#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolTechniqueDisk.h"
#include "pso/item/TItem.h"


void TItemToolTechniqueDisk::apply_use_effect() {
  u8 item_index;
  item_index = (s32)get_item_index();
  set_owner_technique_level(((s16) (get_technique() & 0xFF)), ((s16) (item_index & 0xFFFFFFFFu)));
}

TItemToolTechniqueDisk::~TItemToolTechniqueDisk() {}

TItemToolTechniqueDisk::TItemToolTechniqueDisk(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolTechniqueDisk::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolTechniqueDisk(tl_05, item);
    }
    return NULL;
}
