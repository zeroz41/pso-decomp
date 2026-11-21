#ifndef PSO_OBJECT_AMBIENT_TOBJCGRASS_H
#define PSO_OBJECT_AMBIENT_TOBJCGRASS_H

#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct CsnGroup;

struct CGrassFragment {
    Vec position;
    Vec velocity;
    s32 yaw;
    u32 flags;
};

typedef char CGrassFragmentSize[sizeof(CGrassFragment) == 0x20 ? 1 : -1];

struct TObjCGrass : public TObjMotion {
    TObjCGrass(Vec *origin, s32 count, s32 lifetime);
    virtual ~TObjCGrass();
    CGrassFragment *fragments;
    f32 last_animation_frame;
    s32 fragment_count;
    s32 remaining_frames;
    CsnGroup *ground_candidates[16];
    virtual void render();
    virtual void run_task();
    static void release_global_805D5130();
    static void load_resources();
};

typedef char TObjCGrassFragmentsOffset[offsetof(TObjCGrass, fragments) == 0xFC ? 1 : -1];
typedef char TObjCGrassGroundCandidatesOffset[offsetof(TObjCGrass, ground_candidates) == 0x10C ? 1 : -1];
LAYOUT_ASSERT(TObjCGrass_size, sizeof(TObjCGrass) == 0x14C);

extern "C" {
void *__dt__10TObjCGrassFv(void *arg0, s16 arg1);
void *fn_800B8B00(void *p);
}

#endif
