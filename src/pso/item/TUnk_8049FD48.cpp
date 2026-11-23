#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TUnk_8049FD48.h"
#include "pso/technique/TTecCtrl.h"


void TUnk_8049FD48::apply_use_effect() {
    launch_technique(0xE, 0, this->owner);
}

TUnk_8049FD48::~TUnk_8049FD48() {}

TUnk_8049FD48::TUnk_8049FD48(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_telepipe_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FD48(tl_05, item);
    }
    return NULL;
}
