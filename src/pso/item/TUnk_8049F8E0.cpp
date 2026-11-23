#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TUnk_8049F8E0.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
s16 get_type_id__10TObjPlayerFv();
void *TObjPlayer__sub_80116620(void *, s32);
}

#pragma push
#pragma scheduling off
void TUnk_8049F8E0::apply_use_effect() {
    LockOnActionSlot *slot;
    TLockOnCursor *cursor;
    if (((TObjPlayer *)this->owner)->sub_801A1DDC() != 0) {
        cursor = this->owner->lock_on_cursor;
        if (cursor != NULL) {
            slot = cursor->find_by_pos(4, 9);
            if (slot != NULL) {
                TObjPlayer__sub_80116620(&slot->target_records, 0);
                if ((u16) get_type_id__10TObjPlayerFv() != 0xffffU) {
                    TObjPlayer__sub_80116620(&slot->target_records, 0);
                    send_6x33_revive_player(this->owner->get_entity_id(), get_type_id__10TObjPlayerFv());
                }
            }
        }
    }
}
#pragma pop

TUnk_8049F8E0::~TUnk_8049F8E0() {}

TUnk_8049F8E0::TUnk_8049F8E0(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_moon_atomizer_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049F8E0(tl_05, item);
    }
    return NULL;
}
