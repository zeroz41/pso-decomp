#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TUnk_804A5550.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 get_item_index__5TItemFv();

void TUnk_804A5550::update_weapon() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        ((TItemEquipBase *)arg0)->refresh_owner_stats();
    }
}

}
