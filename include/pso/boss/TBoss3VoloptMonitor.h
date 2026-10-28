#ifndef PSO_BOSS_TBOSS3VOLOPTMONITOR_H
#define PSO_BOSS_TBOSS3VOLOPTMONITOR_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/system/vector.h"

// Vol Opt's wall monitors: six walls of four, slot = wall * 4 + position.
#define VOLOPT_MONITOR_SLOTS 24

struct TBoss3VoloptMonitor : public TObjEnemyCustom {
    TBoss3VoloptMonitor(TObjBase *parent, u16 id, s32 index, s32 slot_index, s32 start_timer);
    TBoss3VoloptMonitor(TObject *parent, void *set_data);
    virtual ~TBoss3VoloptMonitor();
    virtual void run_task();
    virtual void render();

    void set_hit_flags_and_notify();
    void spawn_effects();
    void damage_player_if_aligned();
    void sub_80041C78();
    void sub_80041D0C();
    void sub_80041D3C();
    void sub_80041E88();
    void sub_800420D8();
    void dispatch_state();
    static void release();
    static void load_resources();
    static void *create(void *set_data);
    void init_params();
    void set_model(s32 index);

    s16 slot;
    s16 anim_frame;
    s16 anim_timer;
    u8 pad_392[0x2];
};

typedef char TBoss3VoloptMonitor_size[sizeof(TBoss3VoloptMonitor) == 0x394 ? 1 : -1];

extern s8 volopt_target_slot_used[VOLOPT_MONITOR_SLOTS];
extern Vec volopt_slot_positions[VOLOPT_MONITOR_SLOTS];

#endif
