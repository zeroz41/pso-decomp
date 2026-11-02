#ifndef PSO_MISC_TOROCKCAVE_H
#define PSO_MISC_TOROCKCAVE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct BmlResource;

// The cave rocks (TORockCaveS01 .. TORockCaveBL03, one TU).
struct TORockCave : public TObjCollidable {
    TORockCave();
    virtual ~TORockCave();
    virtual void render();
    virtual void vfunc_14();
    virtual void vfunc_15();
    static void free_instances();
    static void load_resources();
    f32 unk_AC;  // with m_b0, what update_object_view_visibility culls by
    f32 m_b0;
};

typedef char TORockCave_size[sizeof(TORockCave) == 0xB4 ? 1 : -1];
#endif
