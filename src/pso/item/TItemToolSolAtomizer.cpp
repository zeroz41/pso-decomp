#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolSolAtomizer.h"
#include "pso/player/TObjPlayer.h"

void TItemToolSolAtomizer::apply_use_effect() {
    owner->clear_harmful_statuses();
}

TItemToolSolAtomizer::~TItemToolSolAtomizer() {}

TItemToolSolAtomizer::TItemToolSolAtomizer(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolSolAtomizer::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolSolAtomizer(tl_05, item);
    }
    return NULL;
}
