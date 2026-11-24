#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TUnk_8049F8E0.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayerActions.h"
#include "pso/object/base/TObjBase.h"

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
                if (slot->target_records.get_record(0)->get_entity_id() != 0xFFFF) {
                    send_6x33_revive_player(this->owner->get_entity_id(), slot->target_records.get_record(0)->get_entity_id());
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
