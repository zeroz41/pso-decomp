#ifndef PSO_OBJECT_LOBBY_TOBJPATHOBJ_H
#define PSO_OBJECT_LOBBY_TOBJPATHOBJ_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_MOTION;

// A row of a path object's profile table (profile picks it): the path motion, the path and motion
// frame steps per frame, how far ahead along the path it looks to steer, and its turn step
// (182 is one degree in 0x10000 units).
struct PathProfile {
    s32 path_motion;
    f32 path_speed;
    f32 motion_speed;
    f32 look_ahead;
    s32 turn_step;
};

// TObjJungleEbi's rows add flags: update_path_follow_rotation only steers while bit 0 is set.
struct EbiPathProfile {
    s32 path_motion;
    f32 path_speed;
    f32 motion_speed;
    f32 look_ahead;
    s32 turn_step;
    s32 flags;
};

// An object flown along a path motion: the path's root node gives its offset from the set position.
struct TObjPathObj : public TObjBase {
    TObjPathObj(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjPathObj();
    // run_task's step, every frame.
    virtual void update();
    // render's draw, when the object is in view.
    virtual void draw();
    virtual void render();
    virtual void run_task();
    // node's position at frame of motion; 0 once frame passes the motion's last frame.
    s32 sample_clamped_path_position(NJS_OBJECT *node, NJS_MOTION *motion, Vec *pos, f32 frame);
    // Debug line along the whole path, one segment per step frames.
    void draw_line_strip(NJS_OBJECT *node, NJS_MOTION *motion, f32 step);
    f32 view_distance; // render's first update_object_view_visibility argument; 500 unless a subclass sets it
    f32 view_radius;   // render's second update_object_view_visibility argument
};

LAYOUT_ASSERT(TObjPathObj_size, sizeof(TObjPathObj) == 0x98);
#endif
