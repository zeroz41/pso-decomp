#ifndef PSO_ITEM_TITEMLOCKCOUNTCTRL_H
#define PSO_ITEM_TITEMLOCKCOUNTCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

// The controller's two callbacks (TItemTimerEvent::notify_if_active(int) and check_battle_ctrl(int)).
typedef void (*TItemLockCountCallback)(int);

class TItemLockCountCtrl : public TObject {
public:
    s32 count;                             // slots (clients) the hold counts cover
    s32 *lock_counts;                      // one hold count per slot
    TItemLockCountCallback on_first_lock;  // called with the slot when its count leaves 0
    TItemLockCountCallback on_last_unlock; // called with the slot when its count returns to 0
public:
    TItemLockCountCtrl(TObject *parent, s32 count, TItemLockCountCallback on_first_lock,
                       TItemLockCountCallback on_last_unlock);
    virtual ~TItemLockCountCtrl();
    // Releases one hold on slot index; the last release calls on_last_unlock.
    void unlock(s32 index);
    // Takes a hold on slot index; the first hold calls on_first_lock.
    void lock(s32 index);
public:
    static void init_effect_table();
    static void create_instance();
public:
};

#endif
