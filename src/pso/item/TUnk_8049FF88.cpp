#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049FF88.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {
s32 add_weapon_grind(s32, u8);
}

void TUnk_8049FF88::apply_use_effect() {
    s32 temp_r3;

    temp_r3 = get_item_field_6__10TObjPlayerFPv((void *)this->owner);
    if (temp_r3 != 0) {
        add_weapon_grind(temp_r3, get_pmt_amount());
    }
}

TUnk_8049FF88::~TUnk_8049FF88() {}

TUnk_8049FF88::TUnk_8049FF88(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_item_grinder(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FF88(tl_05, item);
    }
    return NULL;
}
