#ifndef PSO_BOSS_BARBARAY_TBOSS7DEROLLEC_H
#define PSO_BOSS_BARBARAY_TBOSS7DEROLLEC_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct TBoss7DeRolLeC : public TObjEneDD_ST {
    virtual ~TBoss7DeRolLeC();
    void update_projectile_spawns();
    virtual void run_task();
    virtual void render();
    void update_or_dispatch();
    void flee_if_disturbed();
    void set_state_and_send(s32);
    u8 sub_802ECB10();
    void sub_802ECAA4();
    void advance_action_sequence();
    void sub_802E8234();
    void set_flag_800();
    virtual void vfunc_88();
    virtual void render_shadows();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void vfunc_28();
    u8 pad_374[0x18];
    u16 unk_38C;
    u8 pad_38E[0x29A];
    s32 unk_628;                  // state flags (0x4, 0x8, 0x40, 0x80, 0x8000 tested)
    u8 pad_62C[0x64];             // 0x630/0x650/0x670: three 0x20 blocks (TBoss2DeRolLe::init_resources / free_if_positive)
    TObject unk_690;              // embedded task group: the ctor builds it with TObject(TObject *), run_task/render walk it
    s32 unk_6AC;
    u8 pad_6B0[0x4];
    s32 action_index;             // step in lbl_804E3C2C[difficulty][], advanced by advance_action_sequence
    s32 unk_6B8;
    u8 pad_6BC[0x8];
    s32 unk_6C4;
    u8 pad_6C8[0xC];
    s32 unk_6D4;                  // mem_alloc'd buffer (freed by the destructor)
    s32 unk_6D8;                  // mem_alloc'd buffer (freed by the destructor)
    u8 pad_6DC[0x10];             // TObject *[4], released by the destructor
    Vec unk_6EC;
    u8 pad_6F8[0x4];
    s32 unk_6FC;
    s32 unk_700;
    u8 pad_704[0xA0];             // 0x708/0x71C/0x720/0x784/0x788[6] TObject *, 0x718 AreaAttackHistory * (destructor)
    TObject *crawfish_parent;     // the group spawned crawfish are children of
    u8 pad_7A8[0x4];
    u32 unk_7AC;
    u8 pad_7B0[0x24];
    void set_field_38(s32 v);
    static void run_exit_callbacks();
    static void *create(void *arg0);
};

typedef char TBoss7DeRolLeC_size[sizeof(TBoss7DeRolLeC) == 0x7D4 ? 1 : -1];
#endif
