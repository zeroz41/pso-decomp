#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolTrapVision.h"
#include "pso/item/TItemTrapVisionTask.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/PlayerCommands.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

// Written from the last function back (deferred code generation), which puts
// TItemTrapVisionTask's vtable before this class's.

TItem *TItemToolTrapVision::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolTrapVision(tl_05, item);
    }
    return NULL;
}

TItemToolTrapVision::TItemToolTrapVision(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItemToolTrapVision::~TItemToolTrapVision() {}

void TItemToolTrapVision::apply_use_effect() { TItemTrapVisionTask::create(tl_05, owner); }

void TItemTrapVisionTask::create(TObject *parent, TObjPlayer *player) {
    if (parent != NULL && player != NULL) {
        new TItemTrapVisionTask(parent, player);
    }
}

TItemTrapVisionTask::TItemTrapVisionTask(TObject *parent, TObjPlayer *player) : TObject(parent) {
    client_id = player->get_entity_id();
    TItemTimerEvent::start_event_by_index(client_id);
    frames_left = 3;
}

TItemTrapVisionTask::~TItemTrapVisionTask() {
    TItemTimerEvent::clear_timer_slot(client_id);
}

void TItemTrapVisionTask::run_task() {
    s32 frames;

    if (get_player_by_client_id(client_id) == NULL) {
        queue_destruction();
        return;
    }
    frames = frames_left;
    if (frames == 0) {
        queue_destruction();
        return;
    }
    frames_left = frames - 1;
}
