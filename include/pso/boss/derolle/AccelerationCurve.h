#ifndef PSO_BOSS_DEROLLE_ACCELERATIONCURVE_H
#define PSO_BOSS_DEROLLE_ACCELERATIONCURVE_H

#include "types.h"

// A velocity ramp without a start speed or clock: accelerate to peak, cruise, brake to rest over dist
// (init_acceleration_curve fills it, sample_acceleration_curve reads it). TBoss1Dragon and TBoss8Dragon hold two
// each as members.
struct AccelerationCurve {
    AccelerationCurve();
    ~AccelerationCurve();
    void reset_coords();
    int check_param_threshold(f32 t);

    f32 accel;
    f32 decel;
    f32 peak;
    f32 accelEnd;
    f32 decelStart;
    f32 end;
    f32 accelDist;
    f32 decelPos;
    f32 dist;
};

#endif
