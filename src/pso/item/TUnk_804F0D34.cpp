#pragma readonly_strings on
// Written from the last function back (deferred code generation), which
// also emits TUnk_804F0D1C's vtable before TUnk_804F0D34's.
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include "pso/TObject.h"
#include "pso/TMainTask.h"
#include "pso/item/TItemObject.h"
#include "pso/item/TUnk_804F0D34.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/object/TObjBgmColCtrl_8017E8E4.h"
#include "pso/object/TUnk_804F0D1C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

static char *event_music_adx_table[] = {
    "WEDDING.adx",
    "Event.adx",
    "hearts.adx",
    "open.adx",
    "Live.adx",
    "DreamS_KIDS.adx",
    "ED_PIANO.adx",
};

static TUnk_804F0D1C *pending_destroy_object;

TUnk_804F0D34 *TUnk_804F0D34::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F0D34(tl_05, item);
    }
    return NULL;
}

TUnk_804F0D34::TUnk_804F0D34(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TUnk_804F0D34::~TUnk_804F0D34() {}

void TUnk_804F0D34::apply_use_effect() {
    create_quest_bgm_object(tl_05, get_item_index());
}

void create_quest_bgm_object(TObject *parent, u32 track) {
    if (track >= 7) {
        track = 0;
    }
    if (get_quest_bgm_issued_flag() == 0) {
        new TUnk_804F0D1C(tl_05, track);
    }
}

TUnk_804F0D1C::TUnk_804F0D1C(TObject *parent, u32 track) : TObject(parent) {
    if (pending_destroy_object != NULL) {
        pending_destroy_object->queue_destruction();
    }
    pending_destroy_object = this;
    play_area_music(event_music_adx_table[track]);
}

TUnk_804F0D1C::~TUnk_804F0D1C() {
    if (pending_destroy_object == this) {
        pending_destroy_object = NULL;
    }
}

void TUnk_804F0D1C::run_task() {
    if (get_quest_bgm_issued_flag() != 0) {
        queue_destruction();
    }
}
