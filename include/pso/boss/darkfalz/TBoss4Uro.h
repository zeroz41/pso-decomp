#ifndef PSO_BOSS_DARKFALZ_TBOSS4URO_H
#define PSO_BOSS_DARKFALZ_TBOSS4URO_H

#include "types.h"
#include "pso/boss/darkfalz/TBoss4Zako.h"

// The minion TBoss4Type1::update_spawn_uro spawns; it circles a point near its
// target player (TBoss4Zako.cpp).
struct TBoss4Uro : public TBoss4Zako {
    TBoss4Uro(TObject *parent, TBoss4ZakoSetData *set_data);
    virtual ~TBoss4Uro();
    virtual void run_task();
    virtual void run_death_reaction();
    static TBoss4Uro *create(TBoss4ZakoSetData *set_data);
    void clamp_min_player_distance();
    void update_orbit_velocity();
    void update_target_position();
    void vt4();
    void update_sink_state();
    void vt6();
    static BmlResource *get_instance_count();

    Vec orbit_center;
};
LAYOUT_ASSERT(TBoss4Uro_size, sizeof(TBoss4Uro) == 0x3D0);

#endif
