#ifndef PSO_MISC_TOCAPSULELABO_H
#define PSO_MISC_TOCAPSULELABO_H

#include "types.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"

// The Lab's info capsule: its lid spins and its light node (node 3) shows
// only while it is active.
struct TOCapsuleLabo : public TUnk_804B27D8 {
    TOCapsuleLabo(TObject *parent, void *set_data);
    virtual ~TOCapsuleLabo();
    virtual void animate();
    virtual void render();

    static void *create(void *set_data);
    static void unload_resources();
    static void load_resources();

    static const char *class_name;
    static BmlResource *model_resource;
    static NJS_OBJECT *light_node;  // hidden while the capsule is inactive

    s32 spin_angle;  // the lid's y rotation
};

typedef char TOCapsuleLabo_size[sizeof(TOCapsuleLabo) == 0xE8 ? 1 : -1];

#endif
