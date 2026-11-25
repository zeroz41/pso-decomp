#include "types.h"
#include "pso/item/TItemObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolStarAtomizer.h"
#include "pso/player/TObjPlayer.h"


void TItemToolStarAtomizer::apply_use_effect() { send_star_atomizer_targets(this->owner); }

TItemToolStarAtomizer::~TItemToolStarAtomizer() {}

TItemToolStarAtomizer::TItemToolStarAtomizer(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolStarAtomizer::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolStarAtomizer(tl_05, item);
    }
    return NULL;
}
