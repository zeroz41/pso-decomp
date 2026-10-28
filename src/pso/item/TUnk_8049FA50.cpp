#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049FA50.h"
#include "pso/player/TObjPlayer.h"

void TUnk_8049FA50::apply_use_effect() {
    owner->clear_harmful_statuses();
}

TUnk_8049FA50::~TUnk_8049FA50() {}

TUnk_8049FA50::TUnk_8049FA50(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_sol_atomizer_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FA50(tl_05, item);
    }
    return NULL;
}
