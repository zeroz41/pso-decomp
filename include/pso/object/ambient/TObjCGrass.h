#ifndef PSO_OBJECT_AMBIENT_TOBJCGRASS_H
#define PSO_OBJECT_AMBIENT_TOBJCGRASS_H

#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/CsnGroundCandidates.h"

struct CsnGroup;

struct CGrassFragment {
    Vec position;
    Vec velocity;
    s32 yaw;
    u32 flags;
};

LAYOUT_ASSERT(CGrassFragmentSize, sizeof(CGrassFragment) == 0x20);

struct TObjCGrass : public TObjMotion {
    TObjCGrass(Vec origin, s32 count, s32 lifetime);
    virtual ~TObjCGrass();
    CGrassFragment *fragments;
    f32 last_animation_frame;
    s32 fragment_count;
    s32 remaining_frames;
    CsnGroundCandidates ground_candidates;
    virtual void render();
    virtual void run_task();
    static void release_global_805D5130();
    static void load_resources();
};

LAYOUT_ASSERT(TObjCGrassFragmentsOffset, offsetof(TObjCGrass, fragments) == 0xFC);
LAYOUT_ASSERT(TObjCGrassGroundCandidatesOffset, offsetof(TObjCGrass, ground_candidates) == 0x10C);
LAYOUT_ASSERT(TObjCGrass_size, sizeof(TObjCGrass) == 0x14C);

extern "C" {
void *__dt__10TObjCGrassFv(void *arg0, s16 arg1);
}

#endif
