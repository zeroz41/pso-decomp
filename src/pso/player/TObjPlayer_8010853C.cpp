#include "pso/effect/item/TItemEffCane.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

void TObjPlayer::create_item_eff_cane(TItem* item, s32 attachment, s32 effect_id) {
    if (this != NULL && item != NULL &&
        ((TObject *)item)->all_parents_unqueued_for_destruction() != 0) {
        new TItemEffCane(this, item, attachment, effect_id);
    }
}

void TObjPlayer::spawn_cane_effect(TItem* item, s32 attachment) {
    if (this != NULL && item != NULL &&
        ((TObject *)item)->all_parents_unqueued_for_destruction() != 0) {
        new TItemEffCane(this, item, attachment, 0x1BD);
    }
}

void TObjPlayer::spawn_cane_effects(TItem* item, s32 first_attachment, s32 second_attachment) {
    if (this != NULL && item != NULL &&
        ((TObject *)item)->all_parents_unqueued_for_destruction() != 0) {
        new TItemEffCane(this, item, first_attachment, 0x1BD);
        new TItemEffCane(this, item, second_attachment, 0x1BD);
    }
}
