#ifndef PSO_ITEM_TITEMLOCKCOUNTCTRL_H
#define PSO_ITEM_TITEMLOCKCOUNTCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

// The controller's two callbacks (TItemTimerEvent::notify_if_active(int) and check_battle_ctrl(int)).
typedef void (*TItemLockCountCallback)(int);

class TItemLockCountCtrl : public TObject {
public:
 s32 m_1c;
 void* m_20;
 TItemLockCountCallback m_24;
 TItemLockCountCallback m_28;
public:
    TItemLockCountCtrl(TObject *parent, s32 count, TItemLockCountCallback arg3, TItemLockCountCallback arg4);
    virtual ~TItemLockCountCtrl();
public:
    static void free_all();
    static void init_effect_table();
    static void create_instance();
public:
    static void add_poison_immunity(int client);
    static void add_status_cleanse(int client);
    static void unlock_effect(u16 client, u32 effect);
    static void lock_effect(u16 client, u32 effect);
};

#endif
