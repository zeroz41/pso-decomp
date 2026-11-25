#include "pso/object/base/TObjChara.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolFluid.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/ui/TLevelSelect.h"

extern "C" {
int obj_getS16_2BA(void*);
}

int TItemToolFluid::get_max_tp() { return obj_getS16_2BA(this->owner); }

int TItemToolFluid::calc_large_tp() {
    return (s16) ((game_difficulty_selection * 0x32) + get_pmt_amount());
}

int TItemToolFluid::calc_small_tp() {
    return (s16) ((game_difficulty_selection * 0x19) + get_pmt_amount());
}

void TItemToolFluid::apply_use_effect() {
    s32 stat_value;

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
    add_actor_tp((TObjChara *)this->owner, stat_value);
}

TItemToolFluid::~TItemToolFluid() {}

TItemToolFluid::TItemToolFluid(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolFluid::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolFluid(tl_05, item);
    }
    return NULL;
}
