#include "pso/object/base/TObjChara.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolFluid.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/ui/TLevelSelect.h"

s16 TItemToolFluid::get_max_tp() { return this->owner->get_tpmax(); }

s16 TItemToolFluid::calc_large_tp() {
    return (game_difficulty_selection * 0x32) + get_pmt_amount();
}

s16 TItemToolFluid::calc_small_tp() {
    return (game_difficulty_selection * 0x19) + get_pmt_amount();
}

void TItemToolFluid::apply_use_effect() {
    s16 stat_value;

    stat_value = 0;
    switch ((s32) this->get_item_index()) {
    case 0:
        stat_value = calc_small_tp();
        break;
    case 1:
        stat_value = calc_large_tp();
        break;
    case 2:
        stat_value = get_max_tp();
        break;
    }
    add_actor_tp(this->owner, stat_value);
}

TItemToolFluid::~TItemToolFluid() {}

TItemToolFluid::TItemToolFluid(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolFluid::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolFluid(tl_05, item);
    }
    return NULL;
}
