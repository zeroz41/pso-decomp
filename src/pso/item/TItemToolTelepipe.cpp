#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolTelepipe.h"
#include "pso/technique/TTecCtrl.h"


void TItemToolTelepipe::apply_use_effect() {
    launch_technique(0xE, 0, this->owner);
}

TItemToolTelepipe::~TItemToolTelepipe() {}

TItemToolTelepipe::TItemToolTelepipe(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolTelepipe::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolTelepipe(tl_05, item);
    }
    return NULL;
}
