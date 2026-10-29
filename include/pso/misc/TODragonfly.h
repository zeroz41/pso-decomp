#ifndef PSO_MISC_TODRAGONFLY_H
#define PSO_MISC_TODRAGONFLY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

// A small flier (the dragonflies, the mechanical fish and the biwa bugs)
// that idles near its set position, wanders to random points around it and
// flees from players who come close, bobbing up and down as it goes.
// m_ac is its state: 0 idle, 1 wandering, 2 resting after a flight, 3 fleeing.
struct TODragonfly : public TObjMapObject {
    TODragonfly();
    virtual ~TODragonfly();
    // run_task's demo-mode step, empty in this build.
    virtual void update_demo();
    virtual void run_task();
    virtual void render();
    void update_idle();
    void update_wander_flight();
    void update_rest();
    void update_flee_flight();
    // Aims at a random point within wander_radius of home at the given
    // height; 0 when that point is where it already is.
    s32 pick_random_destination(f32 height);

    static const char *class_name;

    u8 pad_c8[0x4];
    s32 wait_timer;     // frames spent idle or resting
    f32 wander_radius;  // how far from home pick_random_destination may aim
    Vec destination;    // the point it is flying to
    Vec step;           // per-frame move toward destination, scaled by scale.z
    f32 bob_height;     // how far it bobs up and down
    f32 bob_offset;     // its current height above position
    f32 bob_rate;       // bobs per second
    s32 bob_angle_step; // bob phase advance per frame
    s32 bob_angle;      // bob phase
};

typedef char TODragonfly_size[sizeof(TODragonfly) == 0x100 ? 1 : -1];
#endif
