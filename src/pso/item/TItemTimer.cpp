#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemTimer.h"
#include "pso/system/task/TObject.h"

#include "pso/object/base/TObjMotion.h"

extern const char TItemTimer__class_name_string[] = "TItemTimer";
const char *TItemTimer__class_name = TItemTimer__class_name_string;

void TItemTimer::run_task() {
    m_1C--;
    if (((TObject *)m_20)->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
    } else if (m_1C == 0) {
        ((TItemTimer *)(&m_20))->invoke_callback();
        queue_destruction();
    }
}

TItemTimer::~TItemTimer() {}

#include "types.h"

extern "C" {
void TItemTimer__sub_8011D598(u8 *arg0, s32 arg1, s32 arg2);


#define item_timer ((u8 *)this)
TItemTimer::TItemTimer(TObject *arg1, s32 expire, s32 frames) : TObject(arg1) {
    ((TItemTimer *)(item_timer + 0x20))->reset_fields();
    ((TObject *)item_timer)->m_name = TItemTimer__class_name;
    ((TItemTimer *)item_timer)->m_1C = (frames - 1);
    if ((s32) ((TItemTimer *)item_timer)->m_1C < 1) {
        ((TItemTimer *)item_timer)->m_1C = 1;
    }
    TItemTimer__sub_8011D598(item_timer + 0x20, (saddr)arg1, expire);
    ((TObject *)(item_timer))->disallow_rendering();
}
#undef item_timer

void TItemTimer::invoke_callback() {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)this + 4);
    if (temp_r12 != NULL) {
        temp_r12(*(s32 *)&this->m_name);
    }
}

void TItemTimer__sub_8011D598(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0) = arg1;
    *(s32 *)((s8 *)arg0 + 4) = arg2;
}

void TItemTimer::reset_fields() { *(s32 *)&this->m_name = 0; *(s32 *)&this->m_flags = 0; }

}
