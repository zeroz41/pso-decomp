#include "types.h"
#include "pso/weapon/TUnk_804A5550.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A5550::update_weapon() {
    if (get_item_index() == 5) {
        refresh_owner_stats();
    }
}

TUnk_804A5550::~TUnk_804A5550() {}

TUnk_804A5550::TUnk_804A5550(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    if (item[2] >= 5U) {
        set_color_node(-1);
    }
}

TItem *create_saber_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5550(tl_05, item);
    }
    return NULL;
}
