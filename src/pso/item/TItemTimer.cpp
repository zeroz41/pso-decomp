#include "pso/item/TItemTimer.h"
#include "pso/system/task/TObject.h"

#include "pso/object/base/TObjMotion.h"

const char TItemTimer::class_name_string[] = "TItemTimer";
const char *TItemTimer::class_name = TItemTimer::class_name_string;

void TItemTimer::run_task() {
    frames_left--;
    if (on_expire.target->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
    } else if (frames_left == 0) {
        on_expire.invoke();
        queue_destruction();
    }
}

TItemTimer::~TItemTimer() {}

#include "types.h"

TItemTimer::TItemTimer(TObject *parent, ItemTimerCallback expire, s32 frames) : TObject(parent) {
    on_expire.reset();
    m_name = TItemTimer::class_name;
    frames_left = (frames - 1);
    if (frames_left < 1) {
        frames_left = 1;
    }
    on_expire.set(parent, expire);
    disallow_rendering();
}

void TItemTimerCallback::invoke() {
    if (callback != NULL) {
        callback(target);
    }
}

void TItemTimerCallback::set(TObject *new_target, ItemTimerCallback new_callback) {
    target = new_target;
    callback = new_callback;
}

void TItemTimerCallback::reset() { target = NULL; callback = NULL; }
