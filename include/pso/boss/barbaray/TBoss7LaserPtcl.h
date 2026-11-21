#ifndef PSO_BOSS_BARBARAY_TBOSS7LASERPTCL_H
#define PSO_BOSS_BARBARAY_TBOSS7LASERPTCL_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TParticleCtrl;

struct TBoss7LaserPtclVector { f32 x, y, z; };

struct TBoss7LaserPtcl : public TObject {
    TBoss7LaserPtcl(TObject *parent, TBoss7LaserPtclVector *origin, TBoss7LaserPtclVector *target);
    virtual ~TBoss7LaserPtcl();
    s32 state;
    Vec position;
    Vec direction;
    Vec displacement;
    TParticleCtrl *particles[2];
    f32 travel_distance;
    u8 unknown50[4];
    s32 yaw;

    virtual void run_task();
    s32 is_state_2();
    void calc_world_position(void *out);
    void update_position();
    void init_laser();
    void calc_position(u8 *origin, u8 *direction);
    void destroy_particles();
    virtual void render();
};

void calc_laser_ray_hit_point(u8 *laser, u8 *out);

LAYOUT_ASSERT(TBoss7LaserPtcl_size, sizeof(TBoss7LaserPtcl) == 0x58);
#endif
