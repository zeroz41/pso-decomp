#ifndef PSO_OBJECT_CAVE_TOROCKCAVE_H
#define PSO_OBJECT_CAVE_TOROCKCAVE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"

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

// The rocks of each cave floor (bm_o_rock_cave0N) and the debris pieces of its
// breakable ones (bm_fe_obj_rbN_liwa).
template <int ModelSlots>
struct CaveRockArchive {
    const char *model_filenames[ModelSlots];
    BmlResourceDescriptor descriptor;
};

struct CaveRockArchives {
    CaveRockArchive<4> cave_one;
    CaveRockArchive<7> cave_two;
    CaveRockArchive<4> cave_three;
    CaveRockArchive<7> debris_one;
    CaveRockArchive<7> debris_two;
    CaveRockArchive<7> debris_three;
};

LAYOUT_ASSERT(CaveRockArchives_size, sizeof(CaveRockArchives) == 0xF0);
LAYOUT_ASSERT(CaveRockArchive4_descriptor_offset, offsetof(CaveRockArchive<4>, descriptor) == 0x10);
LAYOUT_ASSERT(CaveRockArchive7_descriptor_offset, offsetof(CaveRockArchive<7>, descriptor) == 0x1C);

#endif
