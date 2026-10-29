#ifndef PSO_MISC_TOCAPSULEANCIENT01_H
#define PSO_MISC_TOCAPSULEANCIENT01_H

#include "types.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/system/BmlResource.h"

// The Ruins' message capsule: its lid spins while it is active.
struct TOCapsuleAncient01 : public TUnk_804B27D8 {
    TOCapsuleAncient01(TObject *parent, void *set_data);
    virtual ~TOCapsuleAncient01();
    virtual void animate();
    virtual void render();

    static void *create(void *set_data);
    static void unload_resources();
    static void load_resources();

    static const char *class_name;
    static BmlResource *model_resource;

    s32 spin_angle;  // the lid's y rotation
};

typedef char TOCapsuleAncient01_size[sizeof(TOCapsuleAncient01) == 0xE8 ? 1 : -1];

#endif
