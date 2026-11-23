#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/weapon/TItemAttacker.h"
#include "types.h"

#pragma readonly_strings on

void spawn_land_hit_effect(TObject *parent, TItem *item, Vec *start, Vec *end, s32 frames) {
    if (parent != NULL && start != NULL && end != NULL && item != NULL) {
        TItemAttacker::spawn_item_timer(new TItemEffLandHit(parent, item, start, end),
                                        (ItemTimerCallback)TObjPlayer::invoke_menu_callback_if_set, frames);
    }
}

const char *TItemEffLandHit::class_name = "TItemEffLandHit";

void TItemEffLandHit::run_task() {
    if (finished) {
        queue_destruction();
    }
}

TItemEffLandHit::~TItemEffLandHit() {}

TItemEffLandHit::TItemEffLandHit(TObject *parent, TItem *item, Vec *start, Vec *end) : TObject(parent) {
    m_name = class_name;
    VecCopy(&this->end, end);
    VecCopy(&this->start, start);
    item_id = item->get_item_id();
    finished = 0;
    disallow_rendering();
}
