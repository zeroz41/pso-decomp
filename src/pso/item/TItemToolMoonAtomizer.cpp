#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolMoonAtomizer.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayerActions.h"
#include "pso/object/base/TObjBase.h"

#pragma push
#pragma scheduling off
void TItemToolMoonAtomizer::apply_use_effect() {
    LockOnActionSlot *slot;
    TLockOnCursor *cursor;
    if (((TObjPlayer *)this->owner)->is_local_or_split_screen() != 0) {
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

TItemToolMoonAtomizer::~TItemToolMoonAtomizer() {}

TItemToolMoonAtomizer::TItemToolMoonAtomizer(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolMoonAtomizer::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolMoonAtomizer(tl_05, item);
    }
    return NULL;
}
