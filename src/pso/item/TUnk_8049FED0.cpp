#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049FED0.h"
#include "pso/item/TUnk_8049FEB8.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"

// Written from the last function back (deferred code generation), which puts
// TUnk_8049FEB8's vtable before this class's.

extern "C" {
void *get_player_by_client_id(s32 i);
}

TUnk_8049FED0 *TUnk_8049FED0::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FED0(tl_05, item);
    }
    return NULL;
}

TUnk_8049FED0::TUnk_8049FED0(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TUnk_8049FED0::~TUnk_8049FED0() {}

void TUnk_8049FED0::apply_use_effect() { TUnk_8049FEB8::create(tl_05, owner); }

void TUnk_8049FEB8::create(TObject *parent, TObjPlayer *player) {
    if (parent != NULL && player != NULL) {
        new TUnk_8049FEB8(parent, player);
    }
}

TUnk_8049FEB8::TUnk_8049FEB8(TObject *parent, TObjPlayer *player) : TObject(parent) {
    client_id = get_entity_id(player);
    TItemTimerEvent::start_event_by_index(client_id);
    frames_left = 3;
}

TUnk_8049FEB8::~TUnk_8049FEB8() {
    TItemTimerEvent::clear_timer_slot(client_id);
}

void TUnk_8049FEB8::run_task() {
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
