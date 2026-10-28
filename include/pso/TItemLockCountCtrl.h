#ifndef PSO_TITEMLOCKCOUNTCTRL_H
#define PSO_TITEMLOCKCOUNTCTRL_H

#include "pso/TObject.h"
#include "types.h"

class TItemLockCountCtrl : public TObject {
public:
 u8 _pad1C[0x20 - 0x1C];
 void* m_20;
public:
    virtual ~TItemLockCountCtrl();
public:
    static void free_all();
    static void init_effect_table();
    static void create_instance();
public:
    static void apply_unit_immunity(int arg0);
    static void set_battle_ctrl_flag30(int arg0);
    static void unlock_effect(u16 client, u32 effect);
    static void lock_effect(u16 client, u32 effect);
};

#endif
