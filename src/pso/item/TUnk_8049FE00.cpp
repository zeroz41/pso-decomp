#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049FE00.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
int obj_getS16_2BA(void*);
s32 add_actor_tp(u8 *arg0, s32 arg1);
u8 get_item_index__5TItemFv();
extern s32 game_difficulty_selection;
}

int TUnk_8049FE00::get_max_tp() { return obj_getS16_2BA(*(void* *)&this->owner); }

int TUnk_8049FE00::calc_large_tp() {
    return (s16) ((game_difficulty_selection * 0x32) + get_pmt_amount());
}

int TUnk_8049FE00::calc_small_tp() {
    return (s16) ((game_difficulty_selection * 0x19) + get_pmt_amount());
}

void TUnk_8049FE00::apply_use_effect() {
    s32 stat_value;

    stat_value = 0;
    switch ((s32) get_item_index__5TItemFv()) {
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
    add_actor_tp((u8 *)this->owner, stat_value);
}

TUnk_8049FE00::~TUnk_8049FE00() {}

TUnk_8049FE00::TUnk_8049FE00(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TUnk_8049FE00 *TUnk_8049FE00::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FE00(tl_05, item);
    }
    return NULL;
}
