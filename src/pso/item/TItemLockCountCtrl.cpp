#include "pso/item/TItemLockCountCtrl.h"
#include "pso/system/memory.h"

#include "types.h"
#include <string.h>

#pragma readonly_strings on

void TItemLockCountCtrl::unlock(s32 index) {
    if (index < count) {
        if (lock_counts[index] != 0) {
            lock_counts[index]--;
            if (lock_counts[index] == 0) {
                if (on_last_unlock != NULL) {
                    on_last_unlock(index);
                }
            }
        }
    }
}

void TItemLockCountCtrl::lock(s32 index) {
    if (index < count) {
        if (lock_counts[index] == 0) {
            if (on_first_lock != NULL) {
                on_first_lock(index);
            }
        }
        lock_counts[index]++;
    }
}


TItemLockCountCtrl::~TItemLockCountCtrl() {
    mem_free(lock_counts);
}

const char *item_lock_count_ctrl_name = "TItemLockCountCtrl";

TItemLockCountCtrl::TItemLockCountCtrl(TObject *parent, s32 count, TItemLockCountCallback on_first_lock,
                                       TItemLockCountCallback on_last_unlock) : TObject(parent) {
    s32 size = count * 4;
    m_name = item_lock_count_ctrl_name;
    this->count = count;
    lock_counts = (s32 *)mem_alloc(size);
    this->on_first_lock = on_first_lock;
    this->on_last_unlock = on_last_unlock;
    memset(lock_counts, 0, size);
}
