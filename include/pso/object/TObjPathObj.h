#ifndef PSO_OBJECT_TOBJPATHOBJ_H
#define PSO_OBJECT_TOBJPATHOBJ_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct AnimationMotion;

// An object flown along a path motion: the path's root node gives its offset from the set position.
struct TObjPathObj : public TObjBase {
    TObjPathObj(TObject *parent, void *set_data);
    virtual ~TObjPathObj();
    // run_task's step, every frame.
    virtual void update();
    // render's draw, when the object is in view.
    virtual void draw();
    virtual void render();
    virtual void run_task();
    // node's position at frame of motion; 0 once frame passes the motion's last frame.
    s32 sample_clamped_path_position(NJS_OBJECT *node, AnimationMotion *motion, Vec *pos, f32 frame);
    // Debug line along the whole path, one segment per step frames.
    void draw_line_strip(NJS_OBJECT *node, AnimationMotion *motion, f32 step);
    f32 view_distance; // render's first update_object_view_visibility argument; 500 unless a subclass sets it
    f32 m_94;
};

LAYOUT_ASSERT(TObjPathObj_size, sizeof(TObjPathObj) == 0x98);
#endif
