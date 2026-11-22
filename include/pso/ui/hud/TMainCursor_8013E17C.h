#ifndef PSO_UI_HUD_TMAINCURSOR_8013E17C_H
#define PSO_UI_HUD_TMAINCURSOR_8013E17C_H

#include "types.h"

// Accessors on the nearest-target scan record (TLockOnCursor +0x510, reset by
// reset_nearest_target_record). The candidate id/dist are the best values the
// try_add_target_candidate scan writes into the record; the published id/dist are
// the copies publish_nearest_target commits for consumers (e.g. TCameraCtrl).
// set_end_task stores the lock-on end task pointer into the cursor's +0x3c task
// triple (TUnk_8013F08C.unk_4), the slot reset_and_spawn_cursors fills with a new
// TLOC_End and ~TLockOnCursor deletes.
extern "C" {
void TMainCursor__set_published_target_dist(void *p, f32 v);
f32 TMainCursor__get_candidate_target_dist(void *p);
void TMainCursor__set_published_target_id(void *p, s16 v);
u16 TMainCursor__get_candidate_target_id(void *p);
void TMainCursor__set_end_task(void *p, s32 v);
}

// --- C functions defined in TMainCursor_8013E17C.cpp ---
extern "C" {
void TMainCursor__set_published_target_dist(void *p, f32 v);
f32 TMainCursor__get_candidate_target_dist(void *p);
void TMainCursor__set_published_target_id(void *p, s16 v);
u16 TMainCursor__get_candidate_target_id(void *p);
void TMainCursor__set_end_task(void *p, s32 v);
}
// --- end of C functions

#endif
