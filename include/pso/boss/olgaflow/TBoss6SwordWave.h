#ifndef PSO_BOSS_OLGAFLOW_TBOSS6SWORDWAVE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6SWORDWAVE_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

struct TBoss6Type2;

// One bit per 1/256 turn of the wave ring: a set bit is a live arc of the wave, a rock it hits clears its bits.
struct Boss6WaveArcMask {
    s32 test_bit(s32 bit);
    void split_bit_index(s32 bit, s32 *word, s32 *shift);
    s32 angle_to_bit(s32 angle);
    void clear_bit(s32 bit);
    void fill_range(s32 start_angle, s32 end_angle);
    void set_bit(s32 bit);
    void clear_all();

    s32 words[8];
};

class TBoss6SwordWave : public TObject {
public:
    TBoss6SwordWave(TBoss6Type2 *owner, const Vec *position, s32 start_angle, s32 end_angle, f32 radius);
    virtual ~TBoss6SwordWave();
    virtual void run_task();
    virtual void render();

    void spawn_wave_ring_particles();
    void check_player_hits();
    void break_rocks_in_wave();
    static TBoss6SwordWave *create(TBoss6Type2 *owner, const Vec *position, s32 start_angle, s32 end_angle, f32 radius);

    TBoss6Type2 *owner;  // the parent that created it
    Vec position;
    f32 radius;          // the ring dies once outer_radius passes it
    Boss6WaveArcMask arcs;
    f32 inner_radius;    // the ring band hurts between inner_radius and outer_radius
    f32 outer_radius;
    f32 particle_timer;
    s32 power;           // boss parameter 0x2C
    f32 power_scale;     // boss parameter 0x2F, applied while the owner's rotation timer runs
};

LAYOUT_ASSERT(TBoss6SwordWaveOwnerOffset, offsetof(TBoss6SwordWave, owner) == 0x1C);
LAYOUT_ASSERT(TBoss6SwordWaveArcsOffset, offsetof(TBoss6SwordWave, arcs) == 0x30);
LAYOUT_ASSERT(TBoss6SwordWaveSize, sizeof(TBoss6SwordWave) == 0x64);

#endif
