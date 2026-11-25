#ifndef PSO_OBJECT_CAVE_TOROCKCAVE_H
#define PSO_OBJECT_CAVE_TOROCKCAVE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct BmlResource;

// The cave rocks (TORockCaveS01 .. TORockCaveBL03, one TU).
struct TORockCave : public TObjCollidable {
    TORockCave();
    virtual ~TORockCave();
    virtual void render();
    virtual void pre_draw();
    virtual void post_draw();
    static void free_instances();
    static void load_resources();
    f32 view_far_depth;  // with view_radius, what update_object_view_visibility culls by
    f32 view_radius;
};

LAYOUT_ASSERT(TORockCave_size, sizeof(TORockCave) == 0xB4);
#endif
