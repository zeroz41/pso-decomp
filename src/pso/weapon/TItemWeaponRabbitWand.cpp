#include "types.h"
#include "pso/weapon/TItemWeaponRabbitWand.h"
#include "pso/item/TItem.h"
#include "pso/render/DebugFont.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponRabbitWand::transform_model_node() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    get_current_matrix(&owner->item_node_matrices[player_list]);
    if (player_list == 9) {
        TItem::begin_effect_render();
    }
}

TItemWeaponRabbitWand::~TItemWeaponRabbitWand() {}

TItemWeaponRabbitWand::TItemWeaponRabbitWand(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponRabbitWand::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponRabbitWand(tl_05, item);
    }
    return NULL;
}
