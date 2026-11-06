#ifndef PSO_BOSS_OLGAFLOW_TBOSS6SWORDWAVE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6SWORDWAVE_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss6SwordWave : public TObject {
public:
    virtual ~TBoss6SwordWave();
    virtual void run_task();
    virtual void render();
public:
    s32 spawn_wave_ring_particles();
    s32 check_player_hits();
    s32 break_rocks_in_wave();
    static void render();
    static u8 *create(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0);
    static void split_bit_index(s32 arg0, u8 v, void *a, void *b);
    void fill_range(void *arg1, void *arg2);
};

#endif
