#ifndef PSO_BOSS_OLGAFLOW_TBOSS6SWORDWAVE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6SWORDWAVE_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

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
    static TBoss6SwordWave *create(TObject *owner, const Vec *position, s32 start_angle, s32 end_angle, f32 radius);
    static void split_bit_index(s32 arg0, u8 v, void *a, void *b);
    void fill_range(void *arg1, void *arg2);

    TObject *owner;
};

typedef char TBoss6SwordWaveOwnerOffset[offsetof(TBoss6SwordWave, owner) == 0x1C ? 1 : -1];

#endif
