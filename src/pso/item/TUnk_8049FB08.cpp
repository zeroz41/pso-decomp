#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049FB08.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void send_star_atomizer_targets(void *arg0);
}

void TUnk_8049FB08::apply_use_effect() { send_star_atomizer_targets(*(void* *)&this->owner); }

TUnk_8049FB08::~TUnk_8049FB08() {}

TUnk_8049FB08::TUnk_8049FB08(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_star_atomizer_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FB08(tl_05, item);
    }
    return NULL;
}
