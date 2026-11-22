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
    void spawn_wave_ring_particles();
    void check_player_hits();
    void break_rocks_in_wave();
    static TBoss6SwordWave *create(TObject *owner, const Vec *position, s32 start_angle, s32 end_angle, f32 radius);
    static void split_bit_index(s32 arg0, u8 v, void *a, void *b);
    void fill_range(void *start_angle, void *end_angle);

    TObject *owner;
};

LAYOUT_ASSERT(TBoss6SwordWaveOwnerOffset, offsetof(TBoss6SwordWave, owner) == 0x1C);

#endif
