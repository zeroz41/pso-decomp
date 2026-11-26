#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemTimer.h"
#include "pso/system/task/TObject.h"

#include "pso/object/base/TObjMotion.h"

extern const char TItemTimer__class_name_string[] = "TItemTimer";
const char *TItemTimer__class_name = TItemTimer__class_name_string;

void TItemTimer::run_task() {
    frames_left--;
    if (((TObject *)on_expire.target)->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
    } else if (frames_left == 0) {
        on_expire.invoke();
        queue_destruction();
    }
}

TItemTimer::~TItemTimer() {}

#include "types.h"

TItemTimer::TItemTimer(TObject *parent, s32 expire, s32 frames) : TObject(parent) {
    on_expire.reset();
    m_name = TItemTimer__class_name;
    frames_left = (frames - 1);
    if (frames_left < 1) {
        frames_left = 1;
    }
    on_expire.set((saddr)parent, expire);
    disallow_rendering();
}

void TItemTimerCallback::invoke() {
    if (callback != NULL) {
        callback((s32)target);
    }
}

void TItemTimerCallback::set(s32 new_target, s32 new_callback) {
    target = (void *)new_target;
    callback = (s32 (*)(s32))new_callback;
}

void TItemTimerCallback::reset() { target = NULL; callback = NULL; }
