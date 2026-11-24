#include "types.h"
#include "pso/weapon/TUnk_804A5058.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_803D853C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A5058::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    get_current_matrix(&owner->item_node_matrices[player_list]);
    if (player_list == 9) {
        TItem::begin_effect_render();
    }
}

TUnk_804A5058::~TUnk_804A5058() {}

TUnk_804A5058::TUnk_804A5058(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TObjPlayer::create_variant_ct(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5058(tl_05, item);
    }
    return NULL;
}
