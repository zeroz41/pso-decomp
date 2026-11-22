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
    static void free_resources();
    static void load_resources();
    void send_gunners_home();
    s32 all_gunners_landed();
    void hide_gunners();
    void start_gunners_attack();
    void move_gunners();
    s32 select_death_gunner();
    void gather_gunners();
    void run_demo_task();
    s32 state;           // run_task's switch
    s32 state_timer;     // counts the current state down
    s32 gunner_count;    // linked gunners, gathered each frame by gather_gunners
    s32 selected_gunner; // the one select_death_gunner picks in turn
    u16 gunner_ids[16];  // their entity ids, sorted by parameters[1]
    s32 despawn_timer;   // runs down once no gunner is left
};

LAYOUT_ASSERT(TObjEneDarkGunCenter_size, sizeof(TObjEneDarkGunCenter) == 0x3A8);

#endif
