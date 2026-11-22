#ifndef PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNCENTER_H
#define PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNCENTER_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

class TObject;

// Groups the TObjEneDarkGunner of its room that share its parameters[0] and drives them.
struct TObjEneDarkGunCenter : public TObjEnemy {
    TObjEneDarkGunCenter(TObject *parent, void *set_data);
    virtual ~TObjEneDarkGunCenter();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static void sub_800A0E7C();
    static void sub_800A0E80();
    void sub_800A0654();
    s32 sub_800A06B4();
    void trigger_targets_action();
    void sub_800A0798();
    void hide_linked_enemies();
    s32 sub_800A0884();
    void sub_800A0994();
    void sub_800A0B18();
    s32 state;           // run_task's switch
    s32 state_timer;     // counts the current state down
    s32 gunner_count;    // linked gunners, gathered each frame by sub_800A0994
    s32 selected_gunner; // the one sub_800A0884 picks in turn
    u16 gunner_ids[16];  // their entity ids, sorted by parameters[1]
    s32 despawn_timer;   // runs down once no gunner is left
};

LAYOUT_ASSERT(TObjEneDarkGunCenter_size, sizeof(TObjEneDarkGunCenter) == 0x3A8);

#endif
