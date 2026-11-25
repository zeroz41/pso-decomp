#pragma readonly_strings on
// Written from the last function back (deferred code generation), which
// also emits TItemQuestBgmTask's vtable before TItemToolQuestBgm's.
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemObject.h"
#include "pso/item/TItemToolQuestBgm.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/object/collision/TObjBgmColCtrl_8017E8E4.h"
#include "pso/object/TItemQuestBgmTask.h"
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

static TItemQuestBgmTask *pending_destroy_object;

TItem *TItemToolQuestBgm::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolQuestBgm(tl_05, item);
    }
    return NULL;
}

TItemToolQuestBgm::TItemToolQuestBgm(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItemToolQuestBgm::~TItemToolQuestBgm() {}

void TItemToolQuestBgm::apply_use_effect() {
    create_quest_bgm_object(tl_05, get_item_index());
}

void create_quest_bgm_object(TObject *parent, u32 track) {
    if (track >= 7) {
        track = 0;
    }
    if (get_quest_bgm_issued_flag() == 0) {
        new TItemQuestBgmTask(tl_05, track);
    }
}

TItemQuestBgmTask::TItemQuestBgmTask(TObject *parent, u32 track) : TObject(parent) {
    if (pending_destroy_object != NULL) {
        pending_destroy_object->queue_destruction();
    }
    pending_destroy_object = this;
    play_area_music(event_music_adx_table[track]);
}

TItemQuestBgmTask::~TItemQuestBgmTask() {
    if (pending_destroy_object == this) {
        pending_destroy_object = NULL;
    }
}

void TItemQuestBgmTask::run_task() {
    if (get_quest_bgm_issued_flag() != 0) {
        queue_destruction();
    }
}
